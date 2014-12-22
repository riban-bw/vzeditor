#pragma once

//(*Headers(vzVoiceModule)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include "envelopeeditor.h"
//*)

const static long VZVOICE_STYLE_NOTITLE = 0;
const static long VZVOICE_STYLE_TITLE = 1;

wxDECLARE_EVENT(wxEVT_VZ_MODULE, wxCommandEvent);

class vzVoiceModule: public wxPanel
{
	public:

		vzVoiceModule(wxWindow* parent, unsigned int nId = 8, long lStyle = VZVOICE_STYLE_NOTITLE);
		virtual ~vzVoiceModule();

		/** @brief  Pass pointer to voice data
		*   @param  pData Pointer to voice data
		*/
		void SetVoiceData(wxByte* pData) { m_pVoiceData = pData; }

		/** @brief  Update the display from voice data
		*/
		void UpdateVoice();

		//(*Declarations(vzVoiceModule)
		wxSlider* m_pSliderEnvDepth;
		wxChoice* m_pCmbWaveform;
		wxStaticBitmap* m_pBmpKeyboard;
		wxStaticText* m_pLblVelocity;
		EnvelopeEditor* m_pGraphAmp;
		wxStaticText* m_pLblDetune;
		wxSlider* m_pSliderAmpSens;
		wxStaticText* m_pLblKeyFollow;
		EnvelopeEditor* m_pEnvEditorKeyFollow;
		wxStaticText* m_pLblWaveform;
		wxSlider* m_pSliderDetuneFine;
		wxStaticText* m_pLblAmpEnv;
		wxChoice* m_pCmbCurve;
		wxStaticText* m_pLblDepth;
		wxStaticText* m_pLblAmpSens;
		wxSlider* m_pSliderVelSensitivity;
		wxSlider* m_pSliderDetune;
		wxStaticText* m_pLblTitle;
		wxCheckBox* m_pChkEnable;
		//*)

	protected:

		//(*Identifiers(vzVoiceModule)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT31;
		static const long ID_STATICTEXT16;
		static const long ID_CHOICE3;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		static const long ID_SLIDER8;
		static const long ID_SLIDER25;
		static const long ID_CUSTOM1;
		static const long ID_SLIDER11;
		static const long ID_SLIDER10;
		static const long ID_CHOICE4;
		static const long ID_SLIDER9;
		static const long ID_STATICBITMAP1;
		static const long ID_CUSTOM2;
		//*)

	private:

		//(*Handlers(vzVoiceModule)
		void OnChkEnableM1Click(wxCommandEvent& event);
		void OnCmbWaveformSelect(wxCommandEvent& event);
		void OnSliderDetuneCmdScrollChanged(wxScrollEvent& event);
		void OnSliderDetuneFineCmdScrollChanged(wxScrollEvent& event);
		void OnSliderEnvDepthCmdScrollChanged(wxScrollEvent& event);
		void OnSliderAmpSensCmdScrollChanged(wxScrollEvent& event);
		void OnCmbCurveSelect(wxCommandEvent& event);
		void OnSliderVelSensitivityCmdScrollChanged(wxScrollEvent& event);
		//*)

        unsigned int m_nIndex; //Module index 0 - 7
		wxByte* m_pVoiceData; //Pointer to the voice data
		void SendUpdate(); //Send an event indicating data has been updated

		DECLARE_EVENT_TABLE()
};

