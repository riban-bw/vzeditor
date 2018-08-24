#ifndef VZLIBRARY_H
#define VZLIBRARY_H

#include <vector>
#include <wx/wx.h>

using namespace std;

struct vzLibEntry
{
    wxString name;
    wxString type;
    wxString description;
    wxString group;
    wxString filename;
};

class VZLibrary
{
    public:
        /** Construct VZLibrary obect */
        VZLibrary(const wxString &sFilename = wxT("library/vzlibrary.xml"));
        /** Destruct VZLibrary obect */
        virtual ~VZLibrary();

        /** @brief  Load library from file
        *   @retval bool True on success
        */
        bool Load();

        /** @brief  Save library to file
        *   @retval bool True on success
        */
        bool Save();

        bool AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription = wxEmptyString, const wxString &sGroup = wxEmptyString, const wxString &sType = wxT("vzvoice"));

        bool RemoveEntry(wxString sName);

        wxString GetDescription(wxString sName);

        bool SetDescription(wxString sName, wxString sDescription);

        wxString GetGroup(wxString sName);

        bool SetGroup(wxString sName, wxString sGroup);

        wxString GetFilename(wxString sName);

        bool SetFilename(wxString sName, wxString sFilename);

        vector<vzLibEntry*>* GetData() { return &m_vEntries; };

    protected:

    private:
        wxString m_sFilename; // XML filename
        vector<vzLibEntry*> m_vEntries; // Map of library entries indexed by name
};

#endif // VZLIBRARY_H
