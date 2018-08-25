#include "sortablelist.h"
#include <algorithm>

bool SortByNameAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->name.mb_str());
    string sRhs(rhs->name.mb_str());
    return  sLhs < sRhs;
}

bool SortByNameDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->name.mb_str());
    string sRhs(rhs->name.mb_str());
    return  sLhs > sRhs;
}

bool SortByDescriptionAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->description.mb_str());
    string sRhs(rhs->description.mb_str());
    return  sLhs < sRhs;
}
bool SortByDescriptionDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->description.mb_str());
    string sRhs(rhs->description.mb_str());
    return  sLhs > sRhs;
}

bool SortByGroupAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->group.mb_str());
    string sRhs(rhs->group.mb_str());
    return  sLhs < sRhs;
}

bool SortByGroupDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->group.mb_str());
    string sRhs(rhs->group.mb_str());
    return  sLhs > sRhs;
}

bool SortByTypeAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->type.mb_str());
    string sRhs(rhs->type.mb_str());
    return  sLhs < sRhs;
}

bool SortByTypeDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->type.mb_str());
    string sRhs(rhs->type.mb_str());
    return  sLhs > sRhs;
}

SortableList::SortableList(wxWindow* parent, wxWindowID id):
    wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VIRTUAL),
    m_pData(NULL)
{
    wxListItem col0;
    col0.SetId(0);
    col0.SetText(wxT("Name"));
    col0.SetWidth(200);
    InsertColumn(0, col0);
    wxListItem col1;
    col1.SetId(1);
    col1.SetText(wxT("Description"));
    col1.SetWidth(400);
    InsertColumn(1, col1);
    wxListItem col2;
    col2.SetId(2);
    col2.SetText(wxT("Group"));
    col2.SetWidth(200);
    InsertColumn(2, col2);
    wxListItem col3;
    col2.SetId(3);
    col2.SetText(wxT("Type"));
    col2.SetWidth(200);
    InsertColumn(3, col3);
    Connect(wxEVT_KEY_UP, (wxObjectEventFunction)&SortableList::OnKeyUp);
}

void SortableList::SetData(VZLibrary* pData)
{
    m_pData = pData;
    SetItemCount(pData->GetData()->size());
    Refresh();
}

//Overload virtual method of wxListCtrl to provide text data for virtual list
wxString SortableList::OnGetItemText(long item, long column) const{
    if(!m_pData)
        return wxEmptyString;
    vzLibEntry* pData = (*m_pData->GetData())[item];
    if(item < (long)m_pData->GetData()->size() && item >= 0)
    {
        switch(column)
        {
            case -1:
                return pData->filename;
            case 0:
                return pData->name;
            case 1:
                return pData->description;
            case 2:
                return pData->group;
            case 3:
                return pData->type;
        }
    }
    return wxT("");
}

wxString SortableList::GetItemFilename(long item)
{
    return OnGetItemText(item, -1);
}

void SortableList::Sort(long column)
{
    static long lSortedColumn = 0; //!@todo use m_lSortedColumn and convert indiviual sort routines to single common function
    if ((lSortedColumn == column + 1) || (lSortedColumn == (-column - 1)))
        lSortedColumn = -lSortedColumn;
    else
        lSortedColumn = column + 1;

    bool bAscending = (lSortedColumn > 0);
    //Reset all columm titles
    wxListItem col;
    GetColumn(0, col);
    col.SetText(wxT("Name"));
    SetColumn(0, col);
    GetColumn(1, col);
    col.SetText(wxT("Description"));
    SetColumn(1, col);
    GetColumn(2, col);
    col.SetText(wxT("Group"));
    SetColumn(2, col);
    GetColumn(3, col);
    col.SetText(wxT("Type"));
    SetColumn(3, col);
    GetColumn(column, col);
    switch(column)
    {
        case 0:
            sort(m_pData->GetData()->begin(), m_pData->GetData()->end(), bAscending?SortByNameAsc:SortByNameDesc);
            col.SetText(bAscending?wxT("▲ Name"):wxT("▼ Name"));
            SetColumn(column, col);
            break;
        case 1:
            sort(m_pData->GetData()->begin(), m_pData->GetData()->end(), bAscending?SortByDescriptionAsc:SortByDescriptionDesc);
            col.SetText(bAscending?wxT("▲ Description"):wxT("▼ Description"));
            SetColumn(column, col);
            break;
        case 2:
            sort(m_pData->GetData()->begin(), m_pData->GetData()->end(), bAscending?SortByGroupAsc:SortByGroupDesc);
            col.SetText(bAscending?wxT("▲ Group"):wxT("▼ Group"));
            SetColumn(column, col);
            break;
        case 3:
            sort(m_pData->GetData()->begin(), m_pData->GetData()->end(), bAscending?SortByTypeAsc:SortByTypeDesc);
            col.SetText(bAscending?wxT("▲ Type"):wxT("▼ Type"));
            SetColumn(column, col);
            break;
        default:
            return;
    }
    Refresh();
}

bool SortableList::DeleteItem(long item)
{
    if(m_pData && m_pData->RemoveEntry(OnGetItemText(item, -1))) //!@todo Can we use index directly?
    {
        return wxListCtrl::DeleteItem(item);
    }
    return false;
}

void SortableList::OnKeyUp(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_DELETE)
    {
        //!@todo Fails for multiple selected items
        long lIndex = -1;
        while((lIndex = GetNextItem(lIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
        {
            if(wxMessageBox(wxT("Delete ") + OnGetItemText(lIndex, 0), wxT("Delete item"), wxYES_NO | wxCENTRE) != wxYES)
                continue;
            DeleteItem(lIndex);
        }
    }
}
