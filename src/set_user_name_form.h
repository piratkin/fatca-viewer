//---------------------------------------------------------------------------

#ifndef set_user_name_formH
#define set_user_name_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tuser_name_form : public TForm
{
__published:	// IDE-managed Components
	TComboBox *uf_name;
	TButton *uf_ok;
	TLabel *uf_label;
	void __fastcall uf_okClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall update_name(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tuser_name_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tuser_name_form *user_name_form;
//---------------------------------------------------------------------------
#endif
