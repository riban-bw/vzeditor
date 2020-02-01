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
    for(vector<vzLibEntry*>::iterator it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
        delete(*it);
    m_vEntries.clear();
}

bool VZLibrary::Load(const wxString &sFilename)
{
    wxXmlDocument xmlDoc;
    if(!wxFileExists(sFilename))
    {
        wxXmlNode nodeRoot(NULL, wxXML_ELEMENT_NODE, "vzlibrary");
        xmlDoc.SetRoot(&nodeRoot);
        if(!xmlDoc.Save(sFilename))
            return false;
    }
    else if(!xmlDoc.Load(sFilename))
        return false;
    Close();
    wxXmlNode* pNode = xmlDoc.GetRoot()->GetChildren();
    while(pNode)
    {
        vzLibEntry* pEntry = new vzLibEntry;
        pEntry->type = pNode->GetName();
        pEntry->name = pNode->GetAttribute("name", "New Voice");
        pEntry->description = pNode->GetAttribute("description", wxEmptyString);
        pEntry->group = pNode->GetAttribute("group", wxEmptyString);
        pEntry->filename = pNode->GetAttribute("filename", wxString::Format("%s.syx", pEntry->name.c_str()));
        m_vEntries.push_back(pEntry);
        pNode = pNode->GetNext();
    }
    m_sFilename = sFilename;
    m_bDirty = false;
    return true;
}

bool VZLibrary::Save()
{
    //!@todo Use filename as parameter
    wxXmlDocument xmlDoc;
    wxXmlNode* pNode = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, "vzlibrary");
    xmlDoc.SetRoot(pNode);
    //iterate in reverse because we are adding each node to the root so it ends up at start of document
    for(vector<vzLibEntry*>::reverse_iterator it = m_vEntries.rbegin(); it != m_vEntries.rend(); ++it)
    {
        vzLibEntry* pEntry = *it;
        pNode = new wxXmlNode(xmlDoc.GetRoot(), wxXML_ELEMENT_NODE, pEntry->type);
        pNode->AddAttribute("name", pEntry->name);
        pNode->AddAttribute("group", pEntry->group);
        pNode->AddAttribute("description", pEntry->description);
        pNode->AddAttribute("filename", pEntry->filename);
    }
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
    vzLibEntry* pEntry = new vzLibEntry;
    pEntry->type = sType;
    pEntry->description = sDescription;
    pEntry->group = sGroup;
    m_vEntries.push_back(pEntry);
    m_bDirty = true;
    return true;
}

bool VZLibrary::RemoveEntry(wxString sFilename)
{
    for(vector<vzLibEntry*>::iterator it = m_vEntries.begin(); it != m_vEntries.end(); ++it)
        if(sFilename.IsSameAs((*it)->filename))
        {
            delete(*it);
            m_vEntries.erase(it);
            m_bDirty = true;
            return true;
        }
    return false;
}

