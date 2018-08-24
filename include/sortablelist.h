#ifndef SORTABLELIST_H
#define SORTABLELIST_H

#include <wx/listctrl.h>
#include "vzlibrary.h"
using namespace std;

class SortableList: public wxListCtrl
{
    public:
        /** Default constructor */
        SortableList(wxWindow* parent, wxWindowID id);

        void SetData(vector<vzLibEntry*>* pData);

        wxString OnGetItemText(long item, long column) const;

        void Sort(long column);

        wxString GetItemFilename(long item);

    protected:

    private:
        long m_lSortColumn;
        vector<vzLibEntry*>* m_pvData; // Pointer to vector of library entries
};

#endif // SORTABLELIST_H
