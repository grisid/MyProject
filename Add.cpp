//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add.h"
#include "Main.h"
#include "Lamp.h"
#include "LampType.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddNewForm *AddNewForm;
//---------------------------------------------------------------------------
__fastcall TAddNewForm::TAddNewForm(TComponent* Owner)
	: TForm(Owner)
{
	HideAll();
}
//---------------------------------------------------------------------------
void __fastcall TAddNewForm::SavebtnClick(TObject *Sender)
{
	String name = NewName->Text;
	String power = Moshnost->Text;
	String price = NewCost->Text;
	String selectedType = NewType->Text;
	String parameter;

	if (selectedType == "������� �����") {
		parameter = NewGas->Text;
		MainForm->databaseHandler.add(new GasLamp(name, power, price, parameter));
	}
	else if (selectedType == "����� �����������") {
		parameter = TempNak->Text + " �C";
		MainForm->databaseHandler.add(new NakalLamp(name, power, price, parameter));
	}
	else if (selectedType == "�������������� �����") {
		parameter = NewTemperature->Text;
		MainForm->databaseHandler.add(new LuminLamp(name, power, price, parameter));
	}

	MainForm->updateDevices();
}
//---------------------------------------------------------------------------
void __fastcall TAddNewForm::OtmenaBtnClick(TObject *Sender)
{
	AddNewForm->Close();
}
//---------------------------------------------------------------------------
void TAddNewForm::HideAll() {
	NewGas->Visible = false;
	TempNak->Visible = false;
	NewTemperature->Visible = false;
	ColorTempText->Visible = false;
	GasText->Visible = false;
	TempNakText->Visible = false;
}
void __fastcall TAddNewForm::LampTypeComboBoxChange(TObject *Sender) {
	HideAll();

	String selectedType = NewType->Text;

    if (selectedType == "������� �����") {
		NewGas->Visible = true; // ��� ���� ����
		GasText->Visible = true;
    }
    else if (selectedType == "����� �����������") {
		TempNak->Visible = true; // ��� ����������� �������
		TempNakText->Visible = true;
    }
    else if (selectedType == "�������������� �����") {
		NewTemperature->Visible = true; // ��� �������� �����������
		ColorTempText->Visible = true;
	}
}


