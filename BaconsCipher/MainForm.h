//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonDecrypted;
	TButton *ButtonEncrypted;
	TRadioGroup *BaconsCipherMode;
	TRadioGroup *LanguageMode;
	TMemo *MemoInput;
	TMemo *MemoOutput;
	TLabel *LabelOutput;
	TLabel *LabelInput;
	TButton *Clear;
	void __fastcall ButtonDecryptedClick(TObject *Sender);
	void __fastcall ButtonEncryptedClick(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
