#include "vzlibrary.h"
#include <wx/file.h>
#include <wx/xml/xml.h>

VZLibrary::VZLibrary(const wxString &sFilename) :
    m_sFilename(sFilename)
{
    Load();
}

VZLibrary::~VZLibrary()
{
    Save();
}

bool VZLibrary::Load()
{
    //!@todo Use filename as parameter
    wxXmlDocument xmlDoc;
    if(!wxFileExists(m_sFilename) || !xmlDoc.Load(m_sFilename))
        return false;
    wxXmlNode* pNode = xmlDoc.GetRoot()->GetChildren();
    while(pNode)
    {
        vzLibEntry* pEntry = new vzLibEntry;
        pEntry->type = pNode->GetName();
        pEntry->name= pNode->GetAttribute(wxT("name"), wxT("New Voice"));
        pEntry->description = pNode->GetAttribute(wxT("description"), wxEmptyString);
        pEntry->group = pNode->GetAttribute(wxT("group"), wxEmptyString);
        pEntry->filename = pNode->GetAttribute(wxT("filename"), wxString::Format(wxT("%s.syx"), pEntry->name.c_str()));
        m_vEntries.push_back(pEntry);
        pNode = pNode->GetNext();
    }
    return true;
}

bool VZLibrary::Save()
{
    //!@todo Use filename as parameter
    wxXmlDocument xmlDoc;
    wxXmlNode* pNode = new wxXmlNode(NULL, wxXML_ELEMENT_NODE, wxT("vzlibrary"));
    xmlDoc.SetRoot(pNode);
    //iterate in reverse because we are adding each node to the root so it ends up at start of document
    for(vector<vzLibEntry*>::reverse_iterator it = m_vEntries.rbegin(); it != m_vEntries.rend(); ++it)
    {
        vzLibEntry* pEntry = *it;
        pNode = new wxXmlNode(xmlDoc.GetRoot(), wxXML_ELEMENT_NODE, pEntry->type);
        pNode->AddAttribute(wxT("name"), pEntry->name);
        pNode->AddAttribute(wxT("group"), pEntry->group);
        pNode->AddAttribute(wxT("description"), pEntry->description);
        pNode->AddAttribute(wxT("filename"), pEntry->filename);
    }
    return xmlDoc.Save(m_sFilename);
}

bool VZLibrary::AddEntry(const wxString &sName, const wxString &sFilename, const wxString &sDescription, const wxString &sGroup, const wxString &sType)
{
    vzLibEntry* pEntry = new vzLibEntry;
    pEntry->type = sType;
    pEntry->filename = sFilename;
    pEntry->description = sDescription;
    pEntry->group = sGroup;
    m_vEntries.push_back(pEntry);
    return true;
}

bool VZLibrary::RemoveEntry(wxString sName)
{
    return true;
}

