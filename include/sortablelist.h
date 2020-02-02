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

    /** @brief  Set pointer to data displayed by sortable list
    *   @param  pData Pointer to VZLibrary object
    */
    void SetData(VZLibrary* pData);

    /** @brief  Override function to return text to show for given row and column
    *   @param  row Index of list row
    *   @param  column Index of list column
    *   @retval wxString Text to display in list cell
    */
    wxString OnGetItemText(long row, long column) const;

    /** @brief  Sort list
    *   @param  column Index of column to index sort order
    */
    void Sort(long column);

    /** @brief  Removes all selected items
    *   @retval unsigned int Quantity of items removed
    */
    unsigned long RemoveItems();

    /** @brief  Get library entry filename
    *   @param  row Index of row
    *   @retval wxString Filename
    */
    wxString GetItemFilename(long row);

    /** @brief  Get library entry type
    *   @param  row Index of row
    *   @retval wxString Type
    */
    wxString GetItemType(long row);

    /** @brief  Get library entry name
    *   @param  row Index of row
    *   @retval wxString Name
    */
    wxString GetItemName(long row);

    /** @brief  Get library entry description
    *   @param  row Index of row
    *   @retval wxString Description
    */
    wxString GetItemDescription(long row);

    /** @brief  Get library entry group
    *   @param  row Index of row
    *   @retval wxString Group
    */
    wxString GetItemGroup(long row);

    /** @brief  Set the description of all selected entries
    *   @param  sDescription Description
    *   @retval long Quantity of entries changed
    */
    unsigned long SetItemDescription(wxString sDescription);

    /** @brief  Set the group of all selected entries
    *   @param  sGroup Description
    *   @retval long Quantity of entries changed
    */
    unsigned long SetItemGroup(wxString sGroup);

    /** @brief  Handle key up event
    *   @param  event Key event
    */
    void OnKeyUp(wxKeyEvent& event);

    /** @brief  Get the index of selected entry
    *   @retval long Index of selected entry or -1 if none or more than one entry selected
    */
    long GetSelected();

protected:

private:
    long m_lSortColumn;
//        vector<vzLibEntry*>* m_pvData; // Pointer to vector of library entries
    VZLibrary* m_pData; // Pointer to the data source
};
