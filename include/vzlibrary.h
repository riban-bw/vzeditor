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
        VZLibrary(const wxString &sFilename = "library/vzlibrary.xml");
        /** Destruct VZLibrary obect */
        virtual ~VZLibrary();

        /** @brief  Load library from file
        *   @param  sFilename Full path and filename of XML library file
        *   @retval bool True on success
        *   @note   Creates new library if file does not exist
        */
        bool Load(const wxString &sFilename);

        /** @brief  Save library to file
        *   @retval bool True on success
        */
        bool Save();

        void Close();

        bool IsDirty() { return m_bDirty; };

        bool IsValid() { return m_bValid; };

        bool AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription = wxEmptyString, const wxString &sGroup = wxEmptyString, const wxString &sType = "vzvoice");

        bool RemoveEntry(wxString sFilename);

        wxString GetDescription(wxString sName);

        bool SetDescription(wxString sName, wxString sDescription);

        wxString GetGroup(wxString sName);

        bool SetGroup(wxString sName, wxString sGroup);

        wxString GetFilename(wxString sName);

        bool SetFilename(wxString sName, wxString sFilename);

        vector<vzLibEntry*>* GetData() { return &m_vEntries; };

        void ClearData();

    protected:

    private:
        wxString m_sFilename; // XML filename
        vector<vzLibEntry*> m_vEntries; // Map of library entries indexed by name
        bool m_bDirty; //True if there are unsaved changes
        bool m_bValid; //True if a valid XML file is open
};

#endif // VZLIBRARY_H
