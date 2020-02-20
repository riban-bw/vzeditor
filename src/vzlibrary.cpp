/***************************************************************
 * Name:      vzlibrary.cpp
 * Purpose:   Implements VZLibrary class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-24
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzlibrary.h"
#include <wx/file.h>
#include <wx/xml/xml.h>
#include <algorithm>

bool SortByNameAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->name.mb_str());
    string sRhs(rhs->name.mb_str());
    return  sLhs < sRhs;
}

bool SortByNameDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->name.mb_str());
    string sRhs(rhs->name.mb_str());
    return  sLhs > sRhs;
}

bool SortByDescriptionAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->description.mb_str());
    string sRhs(rhs->description.mb_str());
    return  sLhs < sRhs;
}
bool SortByDescriptionDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->description.mb_str());
    string sRhs(rhs->description.mb_str());
    return  sLhs > sRhs;
}

bool SortByGroupAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->group.mb_str());
    string sRhs(rhs->group.mb_str());
    return  sLhs < sRhs;
}

bool SortByGroupDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->group.mb_str());
    string sRhs(rhs->group.mb_str());
    return  sLhs > sRhs;
}

bool SortByTypeAsc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->type.mb_str());
    string sRhs(rhs->type.mb_str());
    return  sLhs < sRhs;
}

bool SortByTypeDesc(const vzLibEntry* lhs, const vzLibEntry* rhs)
{
    string sLhs(lhs->type.mb_str());
    string sRhs(rhs->type.mb_str());
    return  sLhs > sRhs;
}

VZLibrary::VZLibrary(const wxString &sFilename) :
    m_sFilename(sFilename),
    m_bDirty(false),
    m_bValid(false)
{
    m_bValid = Load(sFilename);

}

VZLibrary::~VZLibrary()
{
    Close();
}


void VZLibrary::ClearData()
{
    for(auto it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
        delete(*it);
    m_vEntries.clear();
}

bool VZLibrary::Load(const wxString &sFilename)
{
    wxXmlDocument xmlDoc;
    if(!wxFileExists(sFilename))
        return false;
    if(!xmlDoc.Load(sFilename))
        return false;
    Close();
    wxXmlNode* pNode = xmlDoc.GetRoot()->GetChildren();
    wxString sValue;
    while(pNode)
    {
        sValue = pNode->GetAttribute("index", wxEmptyString);
        if(sValue.IsEmpty())
            continue;
        unsigned int nIndex = wxAtoi(sValue);
        if(nIndex > 63)
            continue;
        if(pNode->GetName() == "vztone")
        {
             sValue = pNode->GetAttribute("name", "UNKNOWN");
             m_asToneName[nIndex] = sValue;
             sValue = pNode->GetAttribute("filename", "UNKNOWN");
             m_asToneFilename[nIndex] = sValue;
        }
        else if(pNode->GetName() == "vzoperation")
        {
             sValue = pNode->GetAttribute("name", "UNKNOWN");
             m_asOperatorName[nIndex] = sValue;
             sValue = pNode->GetAttribute("filename", "UNKNOWN");
             m_asOperatorFilename[nIndex] = sValue;
        }
        pNode = pNode->GetNext();
    }
    m_sFilename = sFilename;
    m_bDirty = false;
    return true;
}

bool VZLibrary::Save(wxString sFilename)
{
    wxXmlDocument xmlDoc;
    wxXmlNode* pNode = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "vzlibrary");
    xmlDoc.SetRoot(pNode);
    //iterate in reverse because we are adding each node to the root so it ends up at start of document
    for(int nIndex = 63; nIndex >= 0; --nIndex)
    {
        pNode = new wxXmlNode(xmlDoc.GetRoot(), wxXML_ELEMENT_NODE, "vztone");
        pNode->AddAttribute("index", wxString::Format(wxT("%i"), nIndex));
        pNode->AddAttribute("name", m_asToneName[nIndex]);
        pNode->AddAttribute("filename", m_asToneFilename[nIndex]);
    }
    for(int nIndex = 63; nIndex >= 0; --nIndex)
    {
        pNode = new wxXmlNode(xmlDoc.GetRoot(), wxXML_ELEMENT_NODE, "vzoperation");
        pNode->AddAttribute("index", wxString::Format(wxT("%i"), nIndex));
        pNode->AddAttribute("name", m_asOperatorName[nIndex]);
        pNode->AddAttribute("filename", m_asOperatorFilename[nIndex]);
    }
    if(!sFilename.IsEmpty())
        m_sFilename = sFilename;
    m_bDirty = xmlDoc.Save(m_sFilename);
    return m_bDirty;
}

void VZLibrary::Close()
{
    if(m_bDirty)
    {
        if(wxMessageBox("Save changes to library?", "Unsaved changes", wxYES_NO|wxCENTRE) == wxYES)
            Save();
    }
    ClearData();
}

bool VZLibrary::AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription, const wxString &sGroup, const wxString &sType)
{
    for(auto it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
    {
        vzLibEntry* pEntry = *it;
        if(sFilename.IsSameAs(pEntry->filename))
            return false;
    }
    vzLibEntry* pEntry = new vzLibEntry;
    pEntry->name = sName;
    pEntry->type = sType;
    pEntry->description = sDescription;
    pEntry->group = sGroup;
    pEntry->filename = sFilename;
    m_vEntries.push_back(pEntry);
    m_bDirty = true;
    return true;
}

bool VZLibrary::RemoveEntry(unsigned long lIndex)
{
    if(lIndex > m_vEntries.size())
        return false;
    delete(m_vEntries[lIndex]);
    m_vEntries.erase(m_vEntries.begin() + lIndex);
    m_bDirty = true;
    return true;
}

wxString VZLibrary::GetEntryName(unsigned long lIndex)
{
    if(lIndex > m_vEntries.size())
        return wxEmptyString;
    return m_vEntries[lIndex]->name;
}

bool VZLibrary::SetEntryName(unsigned long lIndex, wxString sName)
{
    if(lIndex > m_vEntries.size())
        return false;
    m_vEntries[lIndex]->name = sName;
    m_bDirty = true;
    return true;
}

wxString VZLibrary::GetEntryDescription(unsigned long lIndex)
{
    if(lIndex > m_vEntries.size())
        return wxEmptyString;
    return m_vEntries[lIndex]->description;
}

bool VZLibrary::SetEntryDescription(unsigned long lIndex, wxString sDescription)
{
    if(lIndex > m_vEntries.size())
        return false;
    m_vEntries[lIndex]->description = sDescription;
    m_bDirty = true;
    return true;
}

wxString VZLibrary::GetEntryGroup(unsigned long lIndex)
{
    if(lIndex > m_vEntries.size())
        return wxEmptyString;
    return m_vEntries[lIndex]->group;
}

bool VZLibrary::SetEntryGroup(unsigned long lIndex, wxString sGroup)
{
    if(lIndex > m_vEntries.size())
        return false;
    m_vEntries[lIndex]->group = sGroup;
    m_bDirty = true;
    return true;
}

wxString VZLibrary::GetEntryType(unsigned long lIndex)
{
    if(lIndex > m_vEntries.size())
        return wxEmptyString;
    return m_vEntries[lIndex]->type;
}

bool VZLibrary::SetEntryType(unsigned long lIndex, wxString sType)
{
    if(lIndex > m_vEntries.size())
        return false;
    m_vEntries[lIndex]->type = sType;
    m_bDirty = true;
    return true;
}

vzLibEntry* VZLibrary::GetEntry(unsigned long lIndex)
{
    if(lIndex >= m_vEntries.size())
        return NULL;
    return m_vEntries[lIndex];
}

vzLibEntry* VZLibrary::GetEntry(wxString sFilename)
{
    for(auto it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
    {
        vzLibEntry* pEntry = *it;
        if(pEntry->filename.IsSameAs(sFilename))
           return pEntry;
    }
    return NULL;
}

vector<vzLibEntry*>::iterator VZLibrary::GetEntryIt(wxString sFilename)
{
    for(auto it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
    {
        vzLibEntry* pEntry = *it;
        if(pEntry->filename.IsSameAs(sFilename))
           return it;
    }
    return m_vEntries.end();
}

long VZLibrary::GetCount()
{
    return m_vEntries.size();
}

void VZLibrary::Sort(wxString sColumn, bool bAscending)
{
    if(sColumn.IsSameAs("name"))
        sort(m_vEntries.begin(), m_vEntries.end(), bAscending?SortByNameAsc:SortByNameDesc);
    else if(sColumn.IsSameAs("description"))
        sort(m_vEntries.begin(), m_vEntries.end(), bAscending?SortByDescriptionAsc:SortByDescriptionDesc);
    else if(sColumn.IsSameAs("type"))
        sort(m_vEntries.begin(), m_vEntries.end(), bAscending?SortByTypeAsc:SortByTypeDesc);
    else if(sColumn.IsSameAs("group"))
        sort(m_vEntries.begin(), m_vEntries.end(), bAscending?SortByGroupAsc:SortByGroupDesc);

}

wxString VZLibrary::GetFilename()
{
    return m_sFilename;
}

void VZLibrary::SetToneName(unsigned int nIndex, wxString sName)
{
    if(nIndex > 63)
        return;
    m_asToneName[nIndex] = sName;
    m_bDirty = true;
}

wxString VZLibrary::GetToneName(unsigned int nIndex)
{
    if(nIndex > 63)
        return wxEmptyString;
    return m_asToneName[nIndex];
}

void VZLibrary::SetToneFilename(unsigned int nIndex, wxString sFilename)
{
    if(nIndex > 63)
        return;
    m_asToneFilename[nIndex] = sFilename;
    m_bDirty = true;
}

wxString VZLibrary::GetToneFilename(unsigned int nIndex)
{
    if(nIndex > 63)
        return wxEmptyString;
    return m_asToneFilename[nIndex];
}

void VZLibrary::SetOperationName(unsigned int nIndex, wxString sName)
{
    if(nIndex > 63)
        return;
    m_asOperatorName[nIndex] = sName;
    m_bDirty = true;
}

wxString VZLibrary::GetOperationName(unsigned int nIndex)
{
    if(nIndex > 63)
        return wxEmptyString;
    return m_asOperatorName[nIndex];
}

void VZLibrary::SetOperationFilename(unsigned int nIndex, wxString sFilename)
{
    if(nIndex > 63)
        return;
    m_asOperatorFilename[nIndex] = sFilename;
    m_bDirty = true;
}

wxString VZLibrary::GetOperationFilename(unsigned int nIndex)
{
    if(nIndex > 63)
        return wxEmptyString;
    return m_asOperatorFilename[nIndex];
}

