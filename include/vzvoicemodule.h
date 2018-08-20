#pragma once

//(*Headers(vzVoiceModule)
#include "envelopeeditor.h"
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
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
		EnvelopeEditor* m_pEnvEditorAmp;
		EnvelopeEditor* m_pEnvEditorKeyFollow;
		wxCheckBox* CheckBox1;
		wxCheckBox* m_pChkEnable;
		wxCheckBox* m_pChkExtPhase;
		wxCheckBox* m_pChkFixedFreq;
		wxCheckBox* m_pChkX16;
		wxChoice* m_pCmbCurve;
		wxChoice* m_pCmbWaveform;
		wxSlider* m_pSliderAmpSens;
		wxSlider* m_pSliderDetuneFine;
		wxSlider* m_pSliderDetuneOctave;
		wxSlider* m_pSliderEnvDepth;
		wxSlider* m_pSliderVelSensitivity;
		wxStaticBitmap* m_pBmpKeyboard;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* m_pLblDepth;
		wxStaticText* m_pLblTitle;
		wxStaticText* m_pLblWaveform;
		//*)

	protected:

		//(*Identifiers(vzVoiceModule)
		static const long ID_STATICTEXT2;
		static const long ID_CHKENABLE;
		static const long ID_CHKEXTPHASE;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE3;
		static const long ID_STATICTEXT3;
		static const long ID_SLIDER8;
		static const long ID_STATICTEXT5;
		static const long ID_SLIDER1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_ENVAMP;
		static const long ID_STATICTEXT15;
		static const long ID_SLIDER11;
		static const long ID_CHECKBOX4;
		static const long ID_STATICBITMAP1;
		static const long ID_ENVKF;
		static const long ID_CHOICE4;
		static const long ID_SLIDER9;
		static const long ID_SLIDER10;
		//*)

	private:

		//(*Handlers(vzVoiceModule)
		void OnChkEnableClick(wxCommandEvent& event);
		void OnCmbWaveformSelect(wxCommandEvent& event);
		void OnSliderDetuneCmdScrollChanged(wxScrollEvent& event);
		void OnSliderDetuneFineCmdScrollChanged(wxScrollEvent& event);
		void OnSliderEnvDepthCmdScrollChanged(wxScrollEvent& event);
		void OnSliderAmpSensCmdScrollChanged(wxScrollEvent& event);
		void OnCmbCurveSelect(wxCommandEvent& event);
		void OnSliderVelSensitivityCmdScrollChanged(wxScrollEvent& event);
		//*)
		void OnAmpEnv(wxCommandEvent& event);
		void OnKFEnv(wxCommandEvent& event);

        unsigned int m_nIndex; //Module index 0 - 7
		wxByte* m_pVoiceData; //Pointer to the voice data
		void SendUpdate(); //Send an event indicating data has been updated

		DECLARE_EVENT_TABLE()
};

