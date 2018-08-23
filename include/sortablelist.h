#ifndef SORTABLELIST_H
#define SORTABLELIST_H

#include <wx/listctrl.h>
#include <vector>
using namespace std;

struct ROW_DATA
{
    string name = "";
    string description = "";
    string group = "";
};

class SortableList: public wxListCtrl
{
    public:
        /** Default constructor */
        SortableList(wxWindow* parent, wxWindowID id);

        wxString OnGetItemText(long item, long column) const;

        void Sort(long column);

    protected:

    private:
        long m_lSortColumn;
        vector<ROW_DATA> m_vData;
};

#endif // SORTABLELIST_H
