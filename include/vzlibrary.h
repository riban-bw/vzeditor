/***************************************************************
 * Name:      vzlibrary.h
 * Purpose:   Defines VZLibrary class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-24
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

#define VZ_TYPE_LIBRARY 0x03

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
    *   @param  sFilename Full path and filename of XML library file [Default: Current file]
    *   @retval bool True on success
    */
    bool Save(wxString sFilename = wxEmptyString);

    void Close();

    bool IsDirty()
    {
        return m_bDirty;
    };

    bool IsValid()
    {
        return m_bValid;
    };

    /** @brief  Add an entry to library
    *   @param  sName Entry name
    *   @param  sFilename Filename of sysex file
    *   @param  sDescription Entry description
    *   @param  sGroup Entry group
    *   @param  sType Entry type ["vzvoice" | "vzoperation"]
    *   @retval bool True on success
    */
    bool AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription = wxEmptyString, const wxString &sGroup = wxEmptyString, const wxString &sType = "vzvoice");

    /** @brief  Remove an entry from library
    *   @param  lIndex Index of entry to remove
    *   @retval bool True on success
    */
    bool RemoveEntry(unsigned long lIndex);

    /** @brief  Get pointer to library entry by index
    *   @param  lIndex Index of entry
    *   @retval vzLibEntry* Pointer to entry or NULL if not found
    */
    vzLibEntry* GetEntry(unsigned long lIndex);

    /** @brief  Get pointer to library entry by filename
    *   @param  sFilename Filename of entry to find
    *   @retval vzLibEntry* Pointer to entry or NULL if not found
    */
    vzLibEntry* GetEntry(wxString sFilename);

    /** @brief  Get iterator pointing to library entry by filename
    *   @param  sFilename Filename of entry to find
    *   @retval vector<vzLibEntry*>::iterator Iterator pointing to entry or end() if not found
    */
    vector<vzLibEntry*>::iterator GetEntryIt(wxString sFilename);

    /** @brief  Get name of a library entry
    *   @param  lIndex Filename of entry
    *   @retval wxString Name
    */
    wxString GetEntryName(unsigned long lIndex);

    /** @brief  Set the name for a library entry
    *   @param  lIndex Filename of entry
    *   @param  sName Text of name
    *   @retval bool True on success
    */
    bool SetEntryName(unsigned long lIndex, wxString sName);

    /** @brief  Get description of a library entry
    *   @param  lIndex Index of the entry
    *   @retval wxString Description
    */
    wxString GetEntryDescription(unsigned long lIndex);

    /** @brief  Set the description for a library entry
    *   @param  lIndex Index of entry
    *   @param  sDescription Text of description
    *   @retval bool True on success
    */
    bool SetEntryDescription(unsigned long lIndex, wxString sDescription);

    /** @brief  Get group of a library entry
    *   @param  lIndex Index of entry
    *   @retval wxString Group
    */
    wxString GetEntryGroup(unsigned long lIndex);

    /** @brief  Set the group for a library entry
    *   @param  lIndex Index of entry
    *   @param  sGroup Text of group
    *   @retval bool True on success
    */
    bool SetEntryGroup(unsigned long lIndex, wxString sGroup);

    /** @brief  Get type of a library entry
    *   @param  lIndex Index of entry
    *   @retval wxString Type
    */
    wxString GetEntryType(unsigned long sFilename);

    /** @brief  Set the tpe for a library entry
    *   @param  lIndex Index of entry
    *   @param  sType Text of group
    *   @retval bool True on success
    */
    bool SetEntryType(unsigned long, wxString sType);

//    map<wxString,vzLibEntry*>* GetData();

    /** @brief  Get quantity of entries in library
    *   @retval long Qunatity of library entries
    */
    long GetCount();

    /** @brief  Sort the library
    *   @param  wxString sColumn Name of column to index
    *   @param  bool bAscending True to assort ascending
    */
    void Sort(wxString sColumn, bool bAscending);

    /** @brief  Get library filename
    *   @retval wxString Filename
    */
    wxString GetFilename();

    /** @brief  Clear all entries from library
    */
    void ClearData();

    /** @brief  Set the name of a tone
    *   @param  nIndex Index of tone [0..63]
    *   @param  sName Name of tone
    */
    void SetToneName(unsigned int nIndex, wxString sName);

    /** @brief  Get the name of a tone
    *   @param  nIndex Index of tone [0..63]
    *   @retval wxString Name of tone
    */
    wxString GetToneName(unsigned int nIndex);

    /** @brief  Set the filename of a tone
    *   @param  nIndex Index of tone [0..63]
    *   @param  sName Filename of tone
    */
    void SetToneFilename(unsigned int nIndex, wxString sFilename);

    /** @brief  Get the filename of a tone
    *   @param  nIndex Index of tone [0..63]
    *   @retval wxString Filename of tone
    */
    wxString GetToneFilename(unsigned int nIndex);

    /** @brief  Set the name of an operation
    *   @param  nIndex Index of operation [0..63]
    *   @param  sName Name of operation
    */
    void SetOperationName(unsigned int nIndex, wxString sName);

    /** @brief  Get the name of a operation
    *   @param  nIndex Index of operation [0..63]
    *   @retval wxString Name of operation
    */
    wxString GetOperationName(unsigned int nIndex);

    /** @brief  Set the filename of an operation
    *   @param  nIndex Index of operation [0..63]
    *   @param  sName Filename of operation
    */
    void SetOperationFilename(unsigned int nIndex, wxString sFilename);

    /** @brief  Get the filename of a operation
    *   @param  nIndex Index of operation [0..63]
    *   @retval wxString Filename of operation
    */
    wxString GetOperationFilename(unsigned int nIndex);

protected:

private:
    wxString m_sFilename; // XML filename
    vector<vzLibEntry*> m_vEntries; // Vector of library entries
    bool m_bDirty; //True if there are unsaved changes
    bool m_bValid; //True if a valid XML file is open
    wxString m_asToneName[64];
    wxString m_asToneFilename[64];
    wxString m_asOperatorName[64];
    wxString m_asOperatorFilename[64];
};
