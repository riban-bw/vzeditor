#pragma once

#include "wx/wx.h"
#include <vector>

class EnvelopeNode
{
    public:
        int m_nLevel;
        int m_nRate;
        bool m_bVelocity; // True if key velocity affects envelope
        bool m_bSustain; // True if this is the sustain stage of the envelolpe
};

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

        /** @brief  Adds a node to the envelope curve
        *   @param  nLevel is the gain of this node
        *   @param  nRate is the slope of the curve
        */
        void AddNode(int nLevel, int nRate);

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

        /** @brief  Sets the position of the X-axis
        *   @param  nAxis Postion of X-axis
        */
        void SetAxis(int nAxis) { m_nAxis = nAxis; }

        /** @brief  Gets the position of the X-axis
        *   @return <i>int</i> Position of X-axis
        */
        int GetAxis() { return m_nAxis; }

    protected:

    private:
        void PlotGraph(wxDC& dc);
        void OnPaint(wxPaintEvent &WXUNUSED(event));
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftUp(wxMouseEvent& event);
        void OnLeftDoubleClick(wxMouseEvent& event);
        void OnMouseMotion(wxMouseEvent& event);
        void OnSize(wxSizeEvent& event);

        int m_nSelectedNode; //Currently selected node (used for mouse click and drag)
        int m_nAxis; //Position of Y axis within control
        int m_nAxisScaler; //Scale of X-axis offset
        unsigned int m_nMaxNodes; //Maximum number of nodes allowed
        std::vector<wxPoint*> m_vNodes; //Vector of nodes

    DECLARE_EVENT_TABLE();
};
