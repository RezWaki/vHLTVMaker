#include <msclr\marshal.h>
#include "hltvmaker.h"
#pragma once

char** anim_fnames;
INT num_anims;

namespace vhltvmaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		String^ appdata;
		char* basepath;
		Diagnostics::ProcessStartInfo^ runMdlThing;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public: 
		Diagnostics::Process^ mdlProc;
		main(void)
		{
			this->Icon = Drawing::Icon::FromHandle( (IntPtr)LoadIconA(0, (LPCSTR)IDI_APPLICATION) );
			appdata = Environment::GetEnvironmentVariable( "APPDATA" );
			basepath = (char*)Marshal::StringToHGlobalAnsi(appdata+"\\vhmftmp\\").ToPointer();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBox1;

	private: System::Windows::Forms::Button^  button2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MDL FILE:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(80, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(350, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(436, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &main::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"mdl";
			this->openFileDialog1->Filter = L"HL models|*.mdl";
			this->openFileDialog1->InitialDirectory = L".\\";
			this->openFileDialog1->Title = L"Select the model file";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 14);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PROCESS ANIMATIONS:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(15, 79);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(207, 18);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"PROCESS DRAW ANIMATIONS TOO";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(436, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Process";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &main::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(436, 178);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(66, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Close";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &main::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(436, 31);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Browse...";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &main::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(80, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(350, 20);
			this->textBox2->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 14);
			this->label3->TabIndex = 8;
			this->label3->Text = L"OUTPUT:";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"mdl";
			this->saveFileDialog1->Filter = L"HL models|*.mdl";
			this->saveFileDialog1->InitialDirectory = L".\\";
			this->saveFileDialog1->Title = L"Output model file";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(15, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 94);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &main::pictureBox1_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 206);
			this->ControlBox = false;
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"main";
			this->Text = L"vHLTVMaker";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &main::main_FormClosing);
			this->Load += gcnew System::EventHandler(this, &main::main_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void mdldec_over( Object^ sender, System::EventArgs^ e ) {
			delete runMdlThing; delete mdlProc;

			anim_fnames = GetAnimFNames( (char*)Marshal::StringToHGlobalAnsi(appdata+"\\vhmftmp\\model.qc").ToPointer(), &num_anims );
			if( !ProcessAnimations(basepath, "idle", anim_fnames, num_anims) ) return;
			if( checkBox1->Checked ) CopyAnims( basepath, "idle", "draw", anim_fnames, num_anims );

			runMdlThing = gcnew Diagnostics::ProcessStartInfo( appdata+"\\vhmftmp\\studiomdl.exe", "model.qc" );
			runMdlThing->WorkingDirectory = appdata+"\\vhmftmp";
			runMdlThing->RedirectStandardOutput = FALSE;
			runMdlThing->CreateNoWindow = TRUE;
			runMdlThing->UseShellExecute = FALSE;
			mdlProc = gcnew Diagnostics::Process();
			mdlProc->EnableRaisingEvents = TRUE;
			mdlProc->StartInfo = runMdlThing;
			mdlProc->Start();
			mdlProc->Exited += gcnew System::EventHandler( this, &main::mdlcomp_over );
		}
		void mdlcomp_over( Object^ sender, System::EventArgs^ e ) {
			delete runMdlThing; delete mdlProc;
			IO::File::Move( appdata+"\\vhmftmp\\model.mdl", textBox2->Text );

			MessageBoxA( NULL, "The model file has been created successfully", "Suckcess", MB_ICONINFORMATION );
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->ShowDialog();
				 textBox1->Text = openFileDialog1->FileName;
			 }
	private: System::Void main_Load(System::Object^  sender, System::EventArgs^  e) {
				 Resources::ResourceManager^ resources;
				 Object^ lib_unpaq;
				 array< unsigned char >^ pUnpaqBytes;
				 IO::FileStream^ fUnpaqStream;

				 if( IO::Directory::Exists(appdata+"\\vhmftmp") )
					 IO::Directory::Delete( appdata+"\\vhmftmp", TRUE );
				 IO::Directory::CreateDirectory( appdata+"\\vhmftmp" );

				 resources = gcnew Resources::ResourceManager("vhltvmaker.resources", Reflection::Assembly::GetExecutingAssembly());
				 lib_unpaq = resources->GetObject( "mdldec" );
				 pUnpaqBytes = (array< unsigned char >^)lib_unpaq;
				 fUnpaqStream = gcnew IO::FileStream( appdata+"\\vhmftmp\\mdldec.exe", IO::FileMode::Create );
				 fUnpaqStream->Write( pUnpaqBytes, 0, pUnpaqBytes->Length );
				 fUnpaqStream->Close();
				 delete fUnpaqStream;
				 delete[] pUnpaqBytes;

				 lib_unpaq = resources->GetObject( "studiomdl" );
				 pUnpaqBytes = (array< unsigned char >^)lib_unpaq;
				 fUnpaqStream = gcnew IO::FileStream( appdata+"\\vhmftmp\\studiomdl.exe", IO::FileMode::Create );
				 fUnpaqStream->Write( pUnpaqBytes, 0, pUnpaqBytes->Length );
				 fUnpaqStream->Close();
				 delete fUnpaqStream;
				 delete[] pUnpaqBytes;
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 if( !IO::File::Exists(textBox1->Text) || !IO::File::Exists(textBox2->Text) ) {
					 MessageBoxA( NULL, "The file doesn't exist", "Error", MB_ICONERROR );
					 return;
				 }
				 IO::File::Copy( textBox1->Text, appdata+"\\vhmftmp\\model.mdl" );

				 runMdlThing = gcnew Diagnostics::ProcessStartInfo( appdata+"\\vhmftmp\\mdldec.exe", "model.mdl ." );
				 runMdlThing->WorkingDirectory = appdata+"\\vhmftmp";
				 runMdlThing->RedirectStandardOutput = FALSE;
				 runMdlThing->CreateNoWindow = TRUE;
				 runMdlThing->UseShellExecute = FALSE;
				 mdlProc = gcnew Diagnostics::Process();
				 mdlProc->EnableRaisingEvents = TRUE;
				 mdlProc->StartInfo = runMdlThing;
				 mdlProc->Start();
				 mdlProc->Exited += gcnew System::EventHandler( this, &main::mdldec_over );
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 if( IO::Directory::Exists(appdata+"\\vhmftmp") )
					 IO::Directory::Delete( appdata+"\\vhmftmp", TRUE );
				 Application::Exit();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 saveFileDialog1->ShowDialog();
				 textBox2->Text = saveFileDialog1->FileName;
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBoxA( NULL, "vHLTVMaker\n\tWritten in C++/CLR By RezWaki\n\tgithub.com/RezWaki\n\trezwaki.hldns.ru", "About", MB_ICONQUESTION );
		 }
private: System::Void main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 if( IO::Directory::Exists(appdata+"\\vhmftmp") )
					 IO::Directory::Delete( appdata+"\\vhmftmp", TRUE );
		 }
};
}