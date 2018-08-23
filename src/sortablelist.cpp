#include "sortablelist.h"
#include <algorithm>


bool SortByNameAsc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.name < rhs.name; }
bool SortByNameDesc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.name > rhs.name; }
bool SortByDescriptionAsc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.description < rhs.description; }
bool SortByDescriptionDesc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.description> rhs.description; }
bool SortByGroupAsc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.group < rhs.group; }
bool SortByGroupDesc(const ROW_DATA &lhs, const ROW_DATA &rhs) { return  lhs.group > rhs.group; }

SortableList::SortableList(wxWindow* parent, wxWindowID id):
    wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VIRTUAL)
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

    m_vData.push_back(ROW_DATA{"Piano", "Grand piano", "Keyboard"});
    m_vData.push_back(ROW_DATA{"Guitar", "Acoustic guitar", "Plucked"});
    m_vData.push_back(ROW_DATA{"Bass", "Bass guitar", "Plucked"});
    m_vData.push_back(ROW_DATA{"Clarinet", "Alto clarinet", "Woodwind"});
    SetItemCount(m_vData.size());
}

//Overload virtual method of wxListCtrl to provide text data for virtual list
wxString SortableList::OnGetItemText(long item, long column) const{
    if(item < (long)m_vData.size() && item >= 0)
    {
        switch(column)
        {
            case 0:
                return wxString::FromUTF8(m_vData[item].name.c_str());
            case 1:
                return wxString::FromUTF8(m_vData[item].description.c_str());
            case 2:
                return wxString::FromUTF8(m_vData[item].group.c_str());
        }
    }
    return wxT("");
}

void SortableList::Sort(long column)
{
    static long lSortedColumn = 0;
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
    GetColumn(column, col);
    switch(column)
    {
        case 0:
            sort(m_vData.begin(), m_vData.end(), bAscending?SortByNameAsc:SortByNameDesc);
            col.SetText(bAscending?wxT("▲ Name"):wxT("▼ Name"));
            SetColumn(column, col);
            break;
        case 1:
            sort(m_vData.begin(), m_vData.end(), bAscending?SortByDescriptionAsc:SortByDescriptionDesc);
            col.SetText(bAscending?wxT("▲ Name"):wxT("▼ Name"));
            SetColumn(column, col);
            break;
        case 2:
            sort(m_vData.begin(), m_vData.end(), bAscending?SortByGroupAsc:SortByGroupDesc);
            col.SetText(bAscending?wxT("▲ Name"):wxT("▼ Name"));
            SetColumn(column, col);
            break;
        default:
            return;
    }
    Refresh();
}
