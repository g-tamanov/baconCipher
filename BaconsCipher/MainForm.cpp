// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "BaconsCipherProcessor.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFormMain *FormMain;

// ---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------
BaconsCipher Processor;

void __fastcall TFormMain::ButtonDecryptedClick(TObject *Sender) {

	if (!MemoInput->Lines->Text.IsEmpty()) {
		String tmp = Processor.Decrypted(MemoInput->Text,
			BaconsCipherMode->ItemIndex, LanguageMode->ItemIndex);
		if (!tmp.IsEmpty())
			MemoOutput->Lines->Add(tmp);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormMain::ButtonEncryptedClick(TObject *Sender) {

	String yyt = ToLower("јавыва");
	if (!MemoInput->Lines->Text.IsEmpty()) {
		String tmp = Processor.Encrypted(MemoInput->Text,
			BaconsCipherMode->ItemIndex, LanguageMode->ItemIndex);
		if (!tmp.IsEmpty())
			MemoOutput->Lines->Add(tmp);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TFormMain::ClearClick(TObject *Sender) {
	MemoOutput->Clear();
}
// ---------------------------------------------------------------------------
