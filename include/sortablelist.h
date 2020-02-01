/***************************************************************
 * Name:      sortablelist.h
 * Purpose:   Defines SortableList class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

#include <wx/listctrl.h>
#include "vzlibrary.h"
using namespace std;

class SortableList: public wxListCtrl
{
public:
    /** Default constructor */
    SortableList(wxWindow* parent, wxWindowID id);

    void SetData(VZLibrary* pData);

    wxString OnGetItemText(long item, long column) const;

    void Sort(long column);

    wxString GetItemFilename(long item);

    wxString GetItemType(long item);

    void OnKeyUp(wxKeyEvent& event);

    bool DeleteItem(long item);

protected:

private:
    long m_lSortColumn;
//        vector<vzLibEntry*>* m_pvData; // Pointer to vector of library entries
    VZLibrary* m_pData; // Pointer to the data source
};
