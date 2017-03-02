//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "main_form.h"
#include "set_user_name_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tuser_name_form *user_name_form;
//---------------------------------------------------------------------------
__fastcall Tuser_name_form::Tuser_name_form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tuser_name_form::uf_okClick(TObject *Sender)
{
	fatca->set_user_name(uf_name->Text.Trim());
	Close();
}
//---------------------------------------------------------------------------
void __fastcall Tuser_name_form::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (!uf_name->Text.Trim().Length()) {
		ShowMessage("Не верное имя пользователя!\nОперация не будет продолжена,\nповторите попытку еще раз.");
	}
}
//---------------------------------------------------------------------------
void __fastcall Tuser_name_form::update_name(TObject *Sender)
{
    uf_ok->Enabled = uf_name->Text.Length();
}
//---------------------------------------------------------------------------

