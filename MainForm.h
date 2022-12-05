#pragma once
#include "Processor.h"
#include "StringConversion.h"

namespace ProcessorSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Processor* processor;

		void UpdateLabels() {
			AXData->Text = toSystemString(processor->getRegisterData2("AX"));
			BXData->Text = toSystemString(processor->getRegisterData2("BX"));
			CXData->Text = toSystemString(processor->getRegisterData2("CX"));
			DXData->Text = toSystemString(processor->getRegisterData2("DX"));
			SPData->Text = toSystemString(processor->getRegisterData2("SP"));
			BPData->Text = toSystemString(processor->getRegisterData2("BP"));
			SIData->Text = toSystemString(processor->getRegisterData2("SI"));
			DIData->Text = toSystemString(processor->getRegisterData2("DI"));

			CFData->Text = toSystemString(processor->getFlagData("CF"));
			OFData->Text = toSystemString(processor->getFlagData("OF"));

			M0Data->Text = toSystemString(processor->getDataFromMemory("00000"));
			M1Data->Text = toSystemString(processor->getDataFromMemory("00001"));
			M2Data->Text = toSystemString(processor->getDataFromMemory("00002"));
			M3Data->Text = toSystemString(processor->getDataFromMemory("00003"));
			M4Data->Text = toSystemString(processor->getDataFromMemory("00004"));
			M5Data->Text = toSystemString(processor->getDataFromMemory("00005"));
			M6Data->Text = toSystemString(processor->getDataFromMemory("00006"));
			M7Data->Text = toSystemString(processor->getDataFromMemory("00007"));
			M8Data->Text = toSystemString(processor->getDataFromMemory("00008"));
			M9Data->Text = toSystemString(processor->getDataFromMemory("00009"));
			MAData->Text = toSystemString(processor->getDataFromMemory("0000A"));
			MBData->Text = toSystemString(processor->getDataFromMemory("0000B"));
			MCData->Text = toSystemString(processor->getDataFromMemory("0000C"));
			MDData->Text = toSystemString(processor->getDataFromMemory("0000D"));
			MEData->Text = toSystemString(processor->getDataFromMemory("0000E"));
			MFData->Text = toSystemString(processor->getDataFromMemory("0000F"));
		}


	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			processor = new Processor();
			UpdateLabels();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			delete processor;
		}

	private: System::Windows::Forms::RichTextBox^ AssemblyCode;
	private: System::Windows::Forms::RichTextBox^ MachineCode;
	private: System::Windows::Forms::Label^ MachineCodeLabel;
	private: System::Windows::Forms::Label^ AssemblyCodeLabel;


	private: System::Windows::Forms::Button^ AssembleButton;
	private: System::Windows::Forms::Button^ ResetButton;
	private: System::Windows::Forms::Button^ NextButton;


	private: System::Windows::Forms::Label^ AX;
	private: System::Windows::Forms::Label^ BX;
	private: System::Windows::Forms::Label^ CX;
	private: System::Windows::Forms::Label^ DX;
	private: System::Windows::Forms::Label^ SP;
	private: System::Windows::Forms::Label^ BP;
	private: System::Windows::Forms::Label^ SI;
	private: System::Windows::Forms::Label^ DI;


	private: System::Windows::Forms::Label^ AXData;
	private: System::Windows::Forms::Label^ BXData;
	private: System::Windows::Forms::Label^ CXData;
	private: System::Windows::Forms::Label^ DXData;
	private: System::Windows::Forms::Label^ SPData;
	private: System::Windows::Forms::Label^ BPData;
	private: System::Windows::Forms::Label^ SIData;
	private: System::Windows::Forms::Label^ DIData;


	private: System::Windows::Forms::Label^ M0Data;
	private: System::Windows::Forms::Label^ M1Data;
	private: System::Windows::Forms::Label^ M2Data;
	private: System::Windows::Forms::Label^ M3Data;
	private: System::Windows::Forms::Label^ M4Data;
	private: System::Windows::Forms::Label^ M5Data;
	private: System::Windows::Forms::Label^ M6Data;
	private: System::Windows::Forms::Label^ M7Data;
	private: System::Windows::Forms::Label^ M8Data;
	private: System::Windows::Forms::Label^ M9Data;
	private: System::Windows::Forms::Label^ MAData;
	private: System::Windows::Forms::Label^ MBData;
	private: System::Windows::Forms::Label^ MCData;
	private: System::Windows::Forms::Label^ MDData;
	private: System::Windows::Forms::Label^ MEData;
	private: System::Windows::Forms::Label^ MFData;


	private: System::Windows::Forms::Label^ M0;
	private: System::Windows::Forms::Label^ M1;
	private: System::Windows::Forms::Label^ M2;
	private: System::Windows::Forms::Label^ M3;
	private: System::Windows::Forms::Label^ M4;
	private: System::Windows::Forms::Label^ M5;
	private: System::Windows::Forms::Label^ M6;
	private: System::Windows::Forms::Label^ M7;
	private: System::Windows::Forms::Label^ M8;
	private: System::Windows::Forms::Label^ M9;
	private: System::Windows::Forms::Label^ MF;
	private: System::Windows::Forms::Label^ ME;
	private: System::Windows::Forms::Label^ MD;
	private: System::Windows::Forms::Label^ MC;
	private: System::Windows::Forms::Label^ MB;
	private: System::Windows::Forms::Label^ MA;
private: System::Windows::Forms::Label^ CFData;
private: System::Windows::Forms::Label^ OFData;
private: System::Windows::Forms::Label^ CF;
private: System::Windows::Forms::Label^ OF;
private: System::Windows::Forms::Button^ RunButton;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AssemblyCode = (gcnew System::Windows::Forms::RichTextBox());
			this->MachineCode = (gcnew System::Windows::Forms::RichTextBox());
			this->MachineCodeLabel = (gcnew System::Windows::Forms::Label());
			this->AssemblyCodeLabel = (gcnew System::Windows::Forms::Label());
			this->AssembleButton = (gcnew System::Windows::Forms::Button());
			this->BX = (gcnew System::Windows::Forms::Label());
			this->CX = (gcnew System::Windows::Forms::Label());
			this->DX = (gcnew System::Windows::Forms::Label());
			this->SP = (gcnew System::Windows::Forms::Label());
			this->BP = (gcnew System::Windows::Forms::Label());
			this->SI = (gcnew System::Windows::Forms::Label());
			this->DI = (gcnew System::Windows::Forms::Label());
			this->AX = (gcnew System::Windows::Forms::Label());
			this->BXData = (gcnew System::Windows::Forms::Label());
			this->CXData = (gcnew System::Windows::Forms::Label());
			this->DXData = (gcnew System::Windows::Forms::Label());
			this->SPData = (gcnew System::Windows::Forms::Label());
			this->BPData = (gcnew System::Windows::Forms::Label());
			this->SIData = (gcnew System::Windows::Forms::Label());
			this->DIData = (gcnew System::Windows::Forms::Label());
			this->AXData = (gcnew System::Windows::Forms::Label());
			this->M0Data = (gcnew System::Windows::Forms::Label());
			this->M7Data = (gcnew System::Windows::Forms::Label());
			this->M6Data = (gcnew System::Windows::Forms::Label());
			this->M5Data = (gcnew System::Windows::Forms::Label());
			this->M4Data = (gcnew System::Windows::Forms::Label());
			this->M3Data = (gcnew System::Windows::Forms::Label());
			this->M2Data = (gcnew System::Windows::Forms::Label());
			this->M0 = (gcnew System::Windows::Forms::Label());
			this->M1 = (gcnew System::Windows::Forms::Label());
			this->M2 = (gcnew System::Windows::Forms::Label());
			this->M3 = (gcnew System::Windows::Forms::Label());
			this->M4 = (gcnew System::Windows::Forms::Label());
			this->M5 = (gcnew System::Windows::Forms::Label());
			this->M6 = (gcnew System::Windows::Forms::Label());
			this->M7 = (gcnew System::Windows::Forms::Label());
			this->MF = (gcnew System::Windows::Forms::Label());
			this->ME = (gcnew System::Windows::Forms::Label());
			this->MD = (gcnew System::Windows::Forms::Label());
			this->MC = (gcnew System::Windows::Forms::Label());
			this->MB = (gcnew System::Windows::Forms::Label());
			this->MA = (gcnew System::Windows::Forms::Label());
			this->M9 = (gcnew System::Windows::Forms::Label());
			this->M8Data = (gcnew System::Windows::Forms::Label());
			this->MFData = (gcnew System::Windows::Forms::Label());
			this->MEData = (gcnew System::Windows::Forms::Label());
			this->MDData = (gcnew System::Windows::Forms::Label());
			this->MCData = (gcnew System::Windows::Forms::Label());
			this->MBData = (gcnew System::Windows::Forms::Label());
			this->MAData = (gcnew System::Windows::Forms::Label());
			this->M9Data = (gcnew System::Windows::Forms::Label());
			this->M8 = (gcnew System::Windows::Forms::Label());
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			this->NextButton = (gcnew System::Windows::Forms::Button());
			this->M1Data = (gcnew System::Windows::Forms::Label());
			this->CFData = (gcnew System::Windows::Forms::Label());
			this->OFData = (gcnew System::Windows::Forms::Label());
			this->CF = (gcnew System::Windows::Forms::Label());
			this->OF = (gcnew System::Windows::Forms::Label());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// AssemblyCode
			// 
			this->AssemblyCode->AcceptsTab = true;
			this->AssemblyCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AssemblyCode->Location = System::Drawing::Point(48, 74);
			this->AssemblyCode->Margin = System::Windows::Forms::Padding(4);
			this->AssemblyCode->Name = L"AssemblyCode";
			this->AssemblyCode->Size = System::Drawing::Size(279, 283);
			this->AssemblyCode->TabIndex = 0;
			this->AssemblyCode->Text = L"";
			// 
			// MachineCode
			// 
			this->MachineCode->BackColor = System::Drawing::SystemColors::Window;
			this->MachineCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MachineCode->Location = System::Drawing::Point(359, 74);
			this->MachineCode->Margin = System::Windows::Forms::Padding(4);
			this->MachineCode->Name = L"MachineCode";
			this->MachineCode->ReadOnly = true;
			this->MachineCode->Size = System::Drawing::Size(505, 283);
			this->MachineCode->TabIndex = 1;
			this->MachineCode->Text = L"";
			// 
			// MachineCodeLabel
			// 
			this->MachineCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MachineCodeLabel->Location = System::Drawing::Point(362, 27);
			this->MachineCodeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MachineCodeLabel->Name = L"MachineCodeLabel";
			this->MachineCodeLabel->Size = System::Drawing::Size(240, 31);
			this->MachineCodeLabel->TabIndex = 3;
			this->MachineCodeLabel->Text = L"Machine Code";
			// 
			// AssemblyCodeLabel
			// 
			this->AssemblyCodeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AssemblyCodeLabel->Location = System::Drawing::Point(43, 27);
			this->AssemblyCodeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AssemblyCodeLabel->Name = L"AssemblyCodeLabel";
			this->AssemblyCodeLabel->Size = System::Drawing::Size(240, 31);
			this->AssemblyCodeLabel->TabIndex = 4;
			this->AssemblyCodeLabel->Text = L"Assembly Code";
			// 
			// AssembleButton
			// 
			this->AssembleButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AssembleButton->Location = System::Drawing::Point(1079, 67);
			this->AssembleButton->Margin = System::Windows::Forms::Padding(4);
			this->AssembleButton->Name = L"AssembleButton";
			this->AssembleButton->Size = System::Drawing::Size(124, 48);
			this->AssembleButton->TabIndex = 5;
			this->AssembleButton->Text = L"Assemble";
			this->AssembleButton->UseVisualStyleBackColor = true;
			this->AssembleButton->Click += gcnew System::EventHandler(this, &MainForm::ExecuteButton_Click);
			// 
			// BX
			// 
			this->BX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BX->Location = System::Drawing::Point(17, 593);
			this->BX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BX->Name = L"BX";
			this->BX->Size = System::Drawing::Size(40, 25);
			this->BX->TabIndex = 6;
			this->BX->Text = L"BX";
			this->BX->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CX
			// 
			this->CX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CX->Location = System::Drawing::Point(17, 660);
			this->CX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CX->Name = L"CX";
			this->CX->Size = System::Drawing::Size(40, 25);
			this->CX->TabIndex = 7;
			this->CX->Text = L"CX";
			this->CX->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DX
			// 
			this->DX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DX->Location = System::Drawing::Point(17, 727);
			this->DX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DX->Name = L"DX";
			this->DX->Size = System::Drawing::Size(40, 25);
			this->DX->TabIndex = 8;
			this->DX->Text = L"DX";
			this->DX->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SP
			// 
			this->SP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SP->Location = System::Drawing::Point(245, 523);
			this->SP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SP->Name = L"SP";
			this->SP->Size = System::Drawing::Size(40, 25);
			this->SP->TabIndex = 9;
			this->SP->Text = L"SP";
			this->SP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BP
			// 
			this->BP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BP->Location = System::Drawing::Point(245, 593);
			this->BP->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BP->Name = L"BP";
			this->BP->Size = System::Drawing::Size(40, 25);
			this->BP->TabIndex = 10;
			this->BP->Text = L"BP";
			this->BP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SI
			// 
			this->SI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SI->Location = System::Drawing::Point(245, 659);
			this->SI->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SI->Name = L"SI";
			this->SI->Size = System::Drawing::Size(40, 25);
			this->SI->TabIndex = 11;
			this->SI->Text = L"SI";
			this->SI->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DI
			// 
			this->DI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DI->Location = System::Drawing::Point(245, 723);
			this->DI->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DI->Name = L"DI";
			this->DI->Size = System::Drawing::Size(40, 25);
			this->DI->TabIndex = 12;
			this->DI->Text = L"DI";
			this->DI->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// AX
			// 
			this->AX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AX->Location = System::Drawing::Point(17, 523);
			this->AX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AX->Name = L"AX";
			this->AX->Size = System::Drawing::Size(40, 25);
			this->AX->TabIndex = 13;
			this->AX->Text = L"AX";
			this->AX->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BXData
			// 
			this->BXData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BXData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->BXData->Location = System::Drawing::Point(64, 588);
			this->BXData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BXData->Name = L"BXData";
			this->BXData->Size = System::Drawing::Size(133, 36);
			this->BXData->TabIndex = 14;
			this->BXData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CXData
			// 
			this->CXData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->CXData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CXData->Location = System::Drawing::Point(64, 654);
			this->CXData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CXData->Name = L"CXData";
			this->CXData->Size = System::Drawing::Size(133, 36);
			this->CXData->TabIndex = 15;
			this->CXData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DXData
			// 
			this->DXData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->DXData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DXData->Location = System::Drawing::Point(64, 722);
			this->DXData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DXData->Name = L"DXData";
			this->DXData->Size = System::Drawing::Size(133, 36);
			this->DXData->TabIndex = 16;
			this->DXData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SPData
			// 
			this->SPData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->SPData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SPData->Location = System::Drawing::Point(292, 518);
			this->SPData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SPData->Name = L"SPData";
			this->SPData->Size = System::Drawing::Size(133, 36);
			this->SPData->TabIndex = 17;
			this->SPData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// BPData
			// 
			this->BPData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BPData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->BPData->Location = System::Drawing::Point(292, 588);
			this->BPData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BPData->Name = L"BPData";
			this->BPData->Size = System::Drawing::Size(133, 36);
			this->BPData->TabIndex = 18;
			this->BPData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SIData
			// 
			this->SIData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->SIData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SIData->Location = System::Drawing::Point(292, 654);
			this->SIData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SIData->Name = L"SIData";
			this->SIData->Size = System::Drawing::Size(133, 36);
			this->SIData->TabIndex = 19;
			this->SIData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DIData
			// 
			this->DIData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->DIData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DIData->Location = System::Drawing::Point(292, 722);
			this->DIData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DIData->Name = L"DIData";
			this->DIData->Size = System::Drawing::Size(133, 36);
			this->DIData->TabIndex = 20;
			this->DIData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// AXData
			// 
			this->AXData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->AXData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AXData->Location = System::Drawing::Point(64, 518);
			this->AXData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AXData->Name = L"AXData";
			this->AXData->Size = System::Drawing::Size(133, 36);
			this->AXData->TabIndex = 21;
			this->AXData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M0Data
			// 
			this->M0Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M0Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M0Data->Location = System::Drawing::Point(581, 518);
			this->M0Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M0Data->Name = L"M0Data";
			this->M0Data->Size = System::Drawing::Size(133, 36);
			this->M0Data->TabIndex = 37;
			this->M0Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M7Data
			// 
			this->M7Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M7Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M7Data->Location = System::Drawing::Point(841, 718);
			this->M7Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M7Data->Name = L"M7Data";
			this->M7Data->Size = System::Drawing::Size(133, 36);
			this->M7Data->TabIndex = 36;
			this->M7Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M6Data
			// 
			this->M6Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M6Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M6Data->Location = System::Drawing::Point(841, 651);
			this->M6Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M6Data->Name = L"M6Data";
			this->M6Data->Size = System::Drawing::Size(133, 36);
			this->M6Data->TabIndex = 35;
			this->M6Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M5Data
			// 
			this->M5Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M5Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M5Data->Location = System::Drawing::Point(841, 584);
			this->M5Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M5Data->Name = L"M5Data";
			this->M5Data->Size = System::Drawing::Size(133, 36);
			this->M5Data->TabIndex = 34;
			this->M5Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M4Data
			// 
			this->M4Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M4Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M4Data->Location = System::Drawing::Point(841, 514);
			this->M4Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M4Data->Name = L"M4Data";
			this->M4Data->Size = System::Drawing::Size(133, 36);
			this->M4Data->TabIndex = 33;
			this->M4Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M3Data
			// 
			this->M3Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M3Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M3Data->Location = System::Drawing::Point(581, 722);
			this->M3Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M3Data->Name = L"M3Data";
			this->M3Data->Size = System::Drawing::Size(133, 36);
			this->M3Data->TabIndex = 32;
			this->M3Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M2Data
			// 
			this->M2Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M2Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M2Data->Location = System::Drawing::Point(581, 654);
			this->M2Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M2Data->Name = L"M2Data";
			this->M2Data->Size = System::Drawing::Size(133, 36);
			this->M2Data->TabIndex = 31;
			this->M2Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M0
			// 
			this->M0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M0->Location = System::Drawing::Point(501, 525);
			this->M0->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M0->Name = L"M0";
			this->M0->Size = System::Drawing::Size(70, 25);
			this->M0->TabIndex = 29;
			this->M0->Text = L"00000H";
			this->M0->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M1
			// 
			this->M1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M1->Location = System::Drawing::Point(501, 594);
			this->M1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M1->Name = L"M1";
			this->M1->Size = System::Drawing::Size(70, 25);
			this->M1->TabIndex = 38;
			this->M1->Text = L"00001H";
			this->M1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M2
			// 
			this->M2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M2->Location = System::Drawing::Point(501, 659);
			this->M2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M2->Name = L"M2";
			this->M2->Size = System::Drawing::Size(70, 25);
			this->M2->TabIndex = 39;
			this->M2->Text = L"00002H";
			this->M2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M3
			// 
			this->M3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M3->Location = System::Drawing::Point(501, 728);
			this->M3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M3->Name = L"M3";
			this->M3->Size = System::Drawing::Size(70, 25);
			this->M3->TabIndex = 40;
			this->M3->Text = L"00003H";
			this->M3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M4
			// 
			this->M4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M4->Location = System::Drawing::Point(763, 521);
			this->M4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M4->Name = L"M4";
			this->M4->Size = System::Drawing::Size(70, 25);
			this->M4->TabIndex = 41;
			this->M4->Text = L"00004H";
			this->M4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M5
			// 
			this->M5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M5->Location = System::Drawing::Point(763, 590);
			this->M5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M5->Name = L"M5";
			this->M5->Size = System::Drawing::Size(70, 25);
			this->M5->TabIndex = 42;
			this->M5->Text = L"00005H";
			this->M5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M6
			// 
			this->M6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M6->Location = System::Drawing::Point(763, 659);
			this->M6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M6->Name = L"M6";
			this->M6->Size = System::Drawing::Size(70, 25);
			this->M6->TabIndex = 43;
			this->M6->Text = L"00006H";
			this->M6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M7
			// 
			this->M7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M7->Location = System::Drawing::Point(763, 727);
			this->M7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M7->Name = L"M7";
			this->M7->Size = System::Drawing::Size(70, 25);
			this->M7->TabIndex = 44;
			this->M7->Text = L"00007H";
			this->M7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MF
			// 
			this->MF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MF->Location = System::Drawing::Point(1291, 722);
			this->MF->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MF->Name = L"MF";
			this->MF->Size = System::Drawing::Size(70, 25);
			this->MF->TabIndex = 60;
			this->MF->Text = L"0000FH";
			this->MF->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ME
			// 
			this->ME->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ME->Location = System::Drawing::Point(1291, 650);
			this->ME->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ME->Name = L"ME";
			this->ME->Size = System::Drawing::Size(70, 25);
			this->ME->TabIndex = 59;
			this->ME->Text = L"0000EH";
			this->ME->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MD
			// 
			this->MD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MD->Location = System::Drawing::Point(1291, 584);
			this->MD->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MD->Name = L"MD";
			this->MD->Size = System::Drawing::Size(71, 25);
			this->MD->TabIndex = 58;
			this->MD->Text = L"0000DH";
			this->MD->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MC
			// 
			this->MC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MC->Location = System::Drawing::Point(1291, 518);
			this->MC->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MC->Name = L"MC";
			this->MC->Size = System::Drawing::Size(70, 25);
			this->MC->TabIndex = 57;
			this->MC->Text = L"0000CH";
			this->MC->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MB
			// 
			this->MB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MB->Location = System::Drawing::Point(1026, 723);
			this->MB->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MB->Name = L"MB";
			this->MB->Size = System::Drawing::Size(70, 25);
			this->MB->TabIndex = 56;
			this->MB->Text = L"0000BH";
			this->MB->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MA
			// 
			this->MA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MA->Location = System::Drawing::Point(1026, 659);
			this->MA->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MA->Name = L"MA";
			this->MA->Size = System::Drawing::Size(70, 25);
			this->MA->TabIndex = 55;
			this->MA->Text = L"0000AH";
			this->MA->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M9
			// 
			this->M9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M9->Location = System::Drawing::Point(1026, 590);
			this->M9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M9->Name = L"M9";
			this->M9->Size = System::Drawing::Size(70, 25);
			this->M9->TabIndex = 54;
			this->M9->Text = L"00009H";
			this->M9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M8Data
			// 
			this->M8Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M8Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M8Data->Location = System::Drawing::Point(1104, 513);
			this->M8Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M8Data->Name = L"M8Data";
			this->M8Data->Size = System::Drawing::Size(133, 36);
			this->M8Data->TabIndex = 53;
			this->M8Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MFData
			// 
			this->MFData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MFData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MFData->Location = System::Drawing::Point(1369, 713);
			this->MFData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MFData->Name = L"MFData";
			this->MFData->Size = System::Drawing::Size(133, 36);
			this->MFData->TabIndex = 52;
			this->MFData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MEData
			// 
			this->MEData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MEData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MEData->Location = System::Drawing::Point(1369, 646);
			this->MEData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MEData->Name = L"MEData";
			this->MEData->Size = System::Drawing::Size(133, 36);
			this->MEData->TabIndex = 51;
			this->MEData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MDData
			// 
			this->MDData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MDData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MDData->Location = System::Drawing::Point(1369, 579);
			this->MDData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MDData->Name = L"MDData";
			this->MDData->Size = System::Drawing::Size(133, 36);
			this->MDData->TabIndex = 50;
			this->MDData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MCData
			// 
			this->MCData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MCData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MCData->Location = System::Drawing::Point(1369, 510);
			this->MCData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MCData->Name = L"MCData";
			this->MCData->Size = System::Drawing::Size(133, 36);
			this->MCData->TabIndex = 49;
			this->MCData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MBData
			// 
			this->MBData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MBData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MBData->Location = System::Drawing::Point(1104, 717);
			this->MBData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MBData->Name = L"MBData";
			this->MBData->Size = System::Drawing::Size(133, 36);
			this->MBData->TabIndex = 48;
			this->MBData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MAData
			// 
			this->MAData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->MAData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MAData->Location = System::Drawing::Point(1104, 649);
			this->MAData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MAData->Name = L"MAData";
			this->MAData->Size = System::Drawing::Size(133, 36);
			this->MAData->TabIndex = 47;
			this->MAData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M9Data
			// 
			this->M9Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M9Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M9Data->Location = System::Drawing::Point(1104, 583);
			this->M9Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M9Data->Name = L"M9Data";
			this->M9Data->Size = System::Drawing::Size(133, 36);
			this->M9Data->TabIndex = 46;
			this->M9Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// M8
			// 
			this->M8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->M8->Location = System::Drawing::Point(1026, 521);
			this->M8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M8->Name = L"M8";
			this->M8->Size = System::Drawing::Size(70, 25);
			this->M8->TabIndex = 45;
			this->M8->Text = L"00008H";
			this->M8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ResetButton
			// 
			this->ResetButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ResetButton->Location = System::Drawing::Point(1226, 67);
			this->ResetButton->Margin = System::Windows::Forms::Padding(4);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(124, 48);
			this->ResetButton->TabIndex = 61;
			this->ResetButton->Text = L"Reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &MainForm::ResetButton_Click);
			// 
			// NextButton
			// 
			this->NextButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NextButton->Location = System::Drawing::Point(1079, 141);
			this->NextButton->Margin = System::Windows::Forms::Padding(4);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(124, 48);
			this->NextButton->TabIndex = 62;
			this->NextButton->Text = L"Next";
			this->NextButton->UseVisualStyleBackColor = true;
			this->NextButton->Click += gcnew System::EventHandler(this, &MainForm::NextButton_Click);
			// 
			// M1Data
			// 
			this->M1Data->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->M1Data->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->M1Data->Location = System::Drawing::Point(581, 589);
			this->M1Data->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->M1Data->Name = L"M1Data";
			this->M1Data->Size = System::Drawing::Size(133, 36);
			this->M1Data->TabIndex = 63;
			this->M1Data->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CFData
			// 
			this->CFData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->CFData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CFData->Location = System::Drawing::Point(65, 791);
			this->CFData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CFData->Name = L"CFData";
			this->CFData->Size = System::Drawing::Size(36, 36);
			this->CFData->TabIndex = 67;
			this->CFData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// OFData
			// 
			this->OFData->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->OFData->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->OFData->Location = System::Drawing::Point(205, 791);
			this->OFData->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OFData->Name = L"OFData";
			this->OFData->Size = System::Drawing::Size(36, 36);
			this->OFData->TabIndex = 68;
			this->OFData->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// CF
			// 
			this->CF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CF->Location = System::Drawing::Point(17, 796);
			this->CF->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->CF->Name = L"CF";
			this->CF->Size = System::Drawing::Size(40, 25);
			this->CF->TabIndex = 69;
			this->CF->Text = L"CF";
			this->CF->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// OF
			// 
			this->OF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OF->Location = System::Drawing::Point(157, 796);
			this->OF->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OF->Name = L"OF";
			this->OF->Size = System::Drawing::Size(40, 25);
			this->OF->TabIndex = 70;
			this->OF->Text = L"OF";
			this->OF->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// RunButton
			// 
			this->RunButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RunButton->Location = System::Drawing::Point(1226, 141);
			this->RunButton->Margin = System::Windows::Forms::Padding(4);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(124, 48);
			this->RunButton->TabIndex = 71;
			this->RunButton->Text = L"Run";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &MainForm::RunButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1540, 848);
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->OF);
			this->Controls->Add(this->CF);
			this->Controls->Add(this->OFData);
			this->Controls->Add(this->CFData);
			this->Controls->Add(this->M1Data);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->MF);
			this->Controls->Add(this->ME);
			this->Controls->Add(this->MD);
			this->Controls->Add(this->MC);
			this->Controls->Add(this->MB);
			this->Controls->Add(this->MA);
			this->Controls->Add(this->M9);
			this->Controls->Add(this->M8Data);
			this->Controls->Add(this->MFData);
			this->Controls->Add(this->MEData);
			this->Controls->Add(this->MDData);
			this->Controls->Add(this->MCData);
			this->Controls->Add(this->MBData);
			this->Controls->Add(this->MAData);
			this->Controls->Add(this->M9Data);
			this->Controls->Add(this->M8);
			this->Controls->Add(this->M7);
			this->Controls->Add(this->M6);
			this->Controls->Add(this->M5);
			this->Controls->Add(this->M4);
			this->Controls->Add(this->M3);
			this->Controls->Add(this->M2);
			this->Controls->Add(this->M1);
			this->Controls->Add(this->M0Data);
			this->Controls->Add(this->M7Data);
			this->Controls->Add(this->M6Data);
			this->Controls->Add(this->M5Data);
			this->Controls->Add(this->M4Data);
			this->Controls->Add(this->M3Data);
			this->Controls->Add(this->M2Data);
			this->Controls->Add(this->M0);
			this->Controls->Add(this->AXData);
			this->Controls->Add(this->DIData);
			this->Controls->Add(this->SIData);
			this->Controls->Add(this->BPData);
			this->Controls->Add(this->SPData);
			this->Controls->Add(this->DXData);
			this->Controls->Add(this->CXData);
			this->Controls->Add(this->BXData);
			this->Controls->Add(this->AX);
			this->Controls->Add(this->DI);
			this->Controls->Add(this->SI);
			this->Controls->Add(this->BP);
			this->Controls->Add(this->SP);
			this->Controls->Add(this->DX);
			this->Controls->Add(this->CX);
			this->Controls->Add(this->BX);
			this->Controls->Add(this->AssembleButton);
			this->Controls->Add(this->AssemblyCodeLabel);
			this->Controls->Add(this->MachineCodeLabel);
			this->Controls->Add(this->MachineCode);
			this->Controls->Add(this->AssemblyCode);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainForm";
			this->Text = L"8086 Simulator";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void ExecuteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		processor->Assemble(toStdString(AssemblyCode->Text));
	}
	catch (const char* exception) {
		MessageBox::Show(toSystemString(exception));
	}
	catch (const string exception) {
		MessageBox::Show(toSystemString(exception));
	}

	MachineCode->Text = toSystemString(processor->getMachineCode());
}


private: System::Void NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		processor->Execute();
	}
	catch (const char* exception) {
		MessageBox::Show(toSystemString(exception));
	}
	catch (const string exception) {
		MessageBox::Show(toSystemString(exception));
	}
	UpdateLabels();
}


private: System::Void ResetButton_Click(System::Object^ sender, System::EventArgs^ e) {
	processor->Reset();
	UpdateLabels();
}


private: System::Void RunButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		processor->ExecuteAll();
	}
	catch (const char* exception) {
		MessageBox::Show(toSystemString(exception));
	}
	catch (const string exception) {
		MessageBox::Show(toSystemString(exception));
	}
	UpdateLabels();
}
};
}
