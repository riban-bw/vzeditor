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
    col1.SetText("Type");
    col1.SetWidth(200);
    InsertColumn(1, col1);
    Connect(wxEVT_KEY_UP, (wxObjectEventFunction)&SortableList::OnKeyUp);
    Connect(id, wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&SortableList::OnColClick);
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
            return pData->type;
        }
    }
    return wxEmptyString;
}

wxString SortableList::GetItemName(long row)
{
    return OnGetItemText(row, 0);
}

wxString SortableList::GetItemType(long row)
{
    return OnGetItemText(row, 3);
}

wxString SortableList::GetItemFilename(long row)
{
    return OnGetItemText(row, -1);
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
    col.SetText("Type");
    SetColumn(1, col);
    GetColumn(column, col);
    switch(column)
    {
    case 0:
        m_pData->Sort("name", bAscending);
        col.SetText(wxString::FromUTF8(bAscending?"▲ Name":"▼ Name"));
        SetColumn(column, col);
        break;
    case 1:
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

void SortableList::OnColClick(wxListEvent& event)
{
    Sort(event.GetColumn());
}
