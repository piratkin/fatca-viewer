//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Grids.hpp>
#include <msxmldom.hpp>
#include <StdCtrls.hpp>
#include <ValEdit.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
#include "sqlite3\sqlite3.h"
//---------------------------------------------------------------------------
class Tfatca : public TForm
{
__published:	// IDE-managed Components
	TXMLDocument *xml;
	TPageControl *pages;
	TTabSheet *file;
	TTabSheet *Data;
	TTabSheet *journal;
	TMemo *xml_text;
	TValueListEditor *fatca_list;
	TXMLDocument *cnf;
	TMainMenu *menu;
	TMenuItem *menu_file;
	TMenuItem *menu_exit;
	TMenuItem *menu_options;
	TMenuItem *menu_help;
	TMenuItem *menu_about;
	TMenuItem *menu_hint;
	TMenuItem *menu_uploade_xml;
	TSaveTextFileDialog *dlgs;
	TStatusBar *status;
	TMenuItem *menu_uploade_meta;
	TXMLDocument *mdl;
	TXMLDocument *mtf;
	TTabSheet *meta;
	TValueListEditor *meta_list;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *menu_download_xml;
	TMenuItem *menu_download_meta;
	TOpenDialog *dlgo;
	TStringGrid *journal_list;
	TPopupMenu *popup;
	TMenuItem *popup_download_xml;
	TMenuItem *popup_upload_xml;
	TMenuItem *popup_delete_row;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall fatca_listMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall menu_aboutClick(TObject *Sender);
	void __fastcall menu_hintClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall menu_exitClick(TObject *Sender);
	void __fastcall menu_uploade_xmlClick(TObject *Sender);
	void __fastcall update_xml(TObject *Sender);
	void __fastcall menu_uploade_metaClick(TObject *Sender);
	void __fastcall meta_listMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall menu_download_xmlClick(TObject *Sender);
	void __fastcall menu_download_metaClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall fatca_listDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall meta_listDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall popup_download_xmlClick(TObject *Sender);
	void __fastcall popupPopup(TObject *Sender);
	void __fastcall popup_upload_xmlClick(TObject *Sender);
	void __fastcall popup_delete_rowClick(TObject *Sender);

private:	// User declarations
    sqlite3 *db;
	UnicodeString user_name;
	char * fatca_state; //указатели на масив описывающие
	char * meta_state;  //состояние всех полей из модели
public:		// User declarations
	__fastcall Tfatca(TComponent* Owner);
	void __fastcall fatca_xml_load(bool auto_load = 0);
	void __fastcall meta_xml_load(bool auto_load = 0);
	void __fastcall update_all_xml();
	void __fastcall history_load();
	void __fastcall history_create();
	void __fastcall history_xml_save();
	void __fastcall history_meta_save();
	bool __fastcall dlg_user_name();
	void __fastcall set_user_name(UnicodeString name) {user_name = name;}
	char* __fastcall get_xml_blob(AnsiString id);
	UnicodeString PrintVersionStringInfo(const TCHAR *fileName);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfatca *fatca;
//---------------------------------------------------------------------------
#endif
