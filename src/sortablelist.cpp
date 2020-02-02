/***************************************************************
 * Name:      sortablelist.cpp
 * Purpose:   Impleents SortableList class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "sortablelist.h"

SortableList::SortableList(wxWindow* parent, wxWindowID id):
    wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VIRTUAL),
    m_pData(NULL)
{
    wxListItem col0;
    col0.SetId(0);
    col0.SetText("Name");
    col0.SetWidth(200);
    InsertColumn(0, col0);
    wxListItem col1;
    col1.SetId(1);
    col1.SetText("Description");
    col1.SetWidth(400);
    InsertColumn(1, col1);
    wxListItem col2;
    col2.SetId(2);
    col2.SetText("Group");
    col2.SetWidth(200);
    InsertColumn(2, col2);
    wxListItem col3;
    col3.SetId(3);
    col3.SetText("Type");
    col3.SetWidth(200);
    InsertColumn(3, col3);
    Connect(wxEVT_KEY_UP, (wxObjectEventFunction)&SortableList::OnKeyUp);
}

void SortableList::SetData(VZLibrary* pData)
{
    m_pData = pData;
    SetItemCount(pData->GetCount());
    Refresh();
}

//Overload virtual method of wxListCtrl to provide text data for virtual list
wxString SortableList::OnGetItemText(long row, long column) const
{
    if(!m_pData)
        return wxEmptyString;
    vzLibEntry* pData = m_pData->GetEntry(row);
    if(!pData)
        return wxEmptyString;
    if(row < m_pData->GetCount() && row >= 0)
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
    return wxEmptyString;
}

wxString SortableList::GetItemName(long row)
{
    return OnGetItemText(row, 0);
}

wxString SortableList::GetItemDescription(long row)
{
    return OnGetItemText(row, 1);
}

wxString SortableList::GetItemGroup(long row)
{
    return OnGetItemText(row, 2);
}

wxString SortableList::GetItemType(long row)
{
    return OnGetItemText(row, 3);
}

wxString SortableList::GetItemFilename(long row)
{
    return OnGetItemText(row, -1);
}

unsigned long SortableList::SetItemDescription(wxString sDescription)
{
    long lIndex = -1;
    long lCount = 0;
    while ((lIndex = GetNextItem(lIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
    {
        m_pData->SetEntryDescription(lIndex, sDescription);
        ++lCount;
    }
    Refresh();
    return lCount;
}

unsigned long SortableList::SetItemGroup(wxString sGroup)
{
    long lIndex = -1;
    long lCount = 0;
    while ((lIndex = GetNextItem(lIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
    {
        m_pData->SetEntryGroup(lIndex, sGroup);
        ++lCount;
    }
    Refresh();
    return lCount;
}

unsigned long SortableList::RemoveItems()
{
    long lIndex = -1;
    vector<unsigned long> vSelected;
    while ((lIndex = GetNextItem(lIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
        vSelected.push_back(lIndex);
    for(vector<unsigned long>::reverse_iterator it = vSelected.rbegin(); it != vSelected.rend(); ++it)
        m_pData->RemoveEntry(*it);
    SetItemCount(m_pData->GetCount());
    Refresh();
    return vSelected.size();
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
    col.SetText("Name");
    SetColumn(0, col);
    GetColumn(1, col);
    col.SetText("Description");
    SetColumn(1, col);
    GetColumn(2, col);
    col.SetText("Group");
    SetColumn(2, col);
    GetColumn(3, col);
    col.SetText("Type");
    SetColumn(3, col);
    GetColumn(column, col);
    switch(column)
    {
    case 0:
        m_pData->Sort("name", bAscending);
        col.SetText(wxString::FromUTF8(bAscending?"▲ Name":"▼ Name"));
        SetColumn(column, col);
        break;
    case 1:
        m_pData->Sort("description", bAscending);
        col.SetText(wxString::FromUTF8(bAscending?"▲ Description":"▼ Description"));
        SetColumn(column, col);
        break;
    case 2:
        m_pData->Sort("group", bAscending);
        col.SetText(wxString::FromUTF8(bAscending?"▲ Group":"▼ Group"));
        SetColumn(column, col);
        break;
    case 3:
        m_pData->Sort("type", bAscending);
        col.SetText(wxString::FromUTF8(bAscending?"▲ Type":"▼ Type"));
        SetColumn(column, col);
        break;
    default:
        return;
    }
    Refresh();
}

void SortableList::OnKeyUp(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_DELETE)
        RemoveItems();
}

long SortableList::GetSelected()
{
    long lIndex = -1;
    long lCount = 0;
    while ((lIndex = GetNextItem(lIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND)
    {
        ++lCount;
    }
    if(lCount > 1)
        lIndex = -1;
    return lIndex;
}
