#pragma once

#include "wx/wx.h"
#include <vector>

class EnvelopeNode
{
    public:
        EnvelopeNode(int nPosition, int nValue, bool bVelocity, bool bSustain) :
            m_nPosition(nPosition),
            m_nValue(nValue),
            m_bVelocity(bVelocity),
            m_bSustain(bSustain)
        {}

        /** @brief  Get the node position
        *   @return <i>int</i> Node Position
        */
        int GetPosition() { return m_nPosition; }

        /** @brief  Get the node value (value)
        *   @return <i>int</i> Node value
        */
        int GetValue() { return m_nValue; }

        /** @brief  Set the node position
        *   @param  nPosition
        */
        void SetPosition(int nPosition) { m_nPosition = nPosition; }

        /** @brief  Set the node value
        *   @param  nPosition Value
        */
        void SetValue(int nValue) { m_nValue = nValue; }

        /** @brief  Check whether node uses key velocity
        *   @return <i>bool</i> True if key velocity contributes to this node
        */
        bool IsVelocity() { return m_bVelocity; }

        /** @brief  Check whether node is sustain point
        *   @return <i>bool</i> True if node is sustain point
        */
        bool IsSustain() { return m_bSustain; }

    private:
        int m_nPosition; //node position
        int m_nValue; //node value
        bool m_bVelocity; // True if key velocity affects envelope
        bool m_bSustain; // True if this is the sustain stage of the envelolpe
};

wxDECLARE_EVENT(wxEVT_ENVED, wxCommandEvent);

static const long ENV_STYLE_DCA_ENV = 0;
static const long ENV_STYLE_DCO_ENV = 1;
static const long ENV_STYLE_DCA_KF  = 2;
static const long ENV_STYLE_DCO_KF  = 3;

class EnvelopeEditor : public wxScrolledWindow
{
    public:
        /** @brief  Create an envelope curve editor graphical control
        *   @param  parent Pointer to the parent window
        *   @param  winid Control ID
        *   @param  pos Position of control
        *   @param  size Control size
        *   @param  style Control style
        *   @note   This control allows adjustment of an envelope curve using a mouse to drag node points on the curve.
        *   @note   Double click to add or remove a node
        */
        EnvelopeEditor(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxScrolledWindowStyle, const wxString& name = wxPanelNameStr);

        virtual ~EnvelopeEditor();

        /** @brief  Adds a node to the envelope curve using postion
        *   @param  nPosition Position of node
        *   @param  nValue Value of node
        *   @param  bVelocity True of key velocity affects this
        *   @param  bSustain True of this node is sustain point
        *   @note   Node is inserted at approriate position, based on nPosition
        */
        void AddNode(int nPosition, int nValue, bool bVelocity = false, bool bSustain = false);

        /** @brief  Adds a node to the envelope curve using rate
        *   @param  nRate Slope of the curve
        *   @param  nValue Value of node
        *   @param  bVelocity True of key velocity affects this
        *   @param  bSustain True of this node is sustain point
        *   @note   Node is added to end
        */
        void AddNodeRate(int nRate, int nValue, bool bVelocity = false, bool bSustain = false);

        /** @brief  Removes the last node of the curve
        */
        void RemoveNode();

        /** @brief  Sets the maximum number of nodes
        *   @param  nMax Maximum number of nodes
        */
        void SetMaxNodes(unsigned int nMax) { m_nMaxNodes = nMax; }

        /** @brief  Gets the maximum number of nodes
        *   @return <i>unsigned int</i> Maximum number of nodes
        */
        unsigned int GetMaxNodes() { return m_nMaxNodes; }

        /** @brief  Gets the quantity of nodes
        *   @return <unsigned int> Quantity of nodes
        */
        unsigned int GetNodeCount() { return m_vNodes.size(); }

        /** @brief  Sets the minimum value on the y-axis
        *   @param  nMin Minimum value
        *   @todo   Change y-axis to float?
        */
        void SetMinY(int nMin);

        /** @brief  Sets the maximum value on the y-axis
        *   @param  nMax Maximum value
        *   @todo   Change y-axis to float?
        */
        void SetMaxY(int nMax);

        /** @brief  Get the node rate
        *   @param  nNode Index of node
        *   @return <i>int</i> Rate of change since last node
        */
        int GetRate(unsigned int nNode);

        /** @brief  Get the position from a node
        *   @param  nNode Index of node
        *   @return <i>int</i> Node position
        */
        int GetPosition(unsigned int nNode);

        /** @brief  Get the value from a node
        *   @param  nNode Index of node
        *   @return <i>int</i> Node value
        */
        int GetValue(unsigned int nNode);

        /** @brief  Is a node affected by key velocity
        *   @param  nNode Index of the node
        *   @return <i>bool</i> True if node is affected by key velocity
        */
        bool IsVelocity(unsigned int nNode);

        /** @brief  Is a node the sustain point
        *   @param  nNode Index of the node
        *   @return <i>bool</i> True if node is sustain point
        */
        bool IsSustain(unsigned int nNode);

        /** @brief  Removes all nodes
        */
        void Clear();

    protected:

    private:
        void PlotEnvelope(wxDC& dc);
        void OnPaint(wxPaintEvent &WXUNUSED(event));
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnLeftDoubleClick(wxMouseEvent& event);
        void OnMouseMotion(wxMouseEvent& event);
        void OnSize(wxSizeEvent& event);
        void SendUpdate(int nIndex);

        int m_nSelectedNode; //Currently selected node (used for mouse click and drag)
        int m_nMinY; //Minimum y-axis value
        int m_nMaxY; //Maximum y-axis value
        int m_nRange; //max-min
        int m_nZero; //position of x-axis
        int m_nStyle; //Control style
        unsigned int m_nMaxNodes; //Maximum number of nodes allowed
        float m_fScaleY; //Current y-axis scaling
        std::vector<EnvelopeNode*> m_vNodes; //Vector of nodes

    DECLARE_EVENT_TABLE();
};
