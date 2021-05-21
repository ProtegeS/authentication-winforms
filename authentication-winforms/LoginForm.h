#pragma once

#include "MsgBox.h"
#include "DB.h"
#include "MainForm.h"

namespace authenticationwinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Web;
	using namespace System::Net::Mail;

	/// <summary>
	/// Summary for loginForm
	/// </summary>
	public ref class loginForm : public System::Windows::Forms::Form
	{
		// dragging the form
	private: Point^ mouseOffset;
	private: bool isMouseDown = false;

	private: System::Windows::Forms::PictureBox^ tomoe;
	private: System::Windows::Forms::PictureBox^ mangekyou;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	public:
		loginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->tomoe = (gcnew System::Windows::Forms::PictureBox());
			this->mangekyou = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tomoe))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mangekyou))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(35, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 44);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login First";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 23);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Username: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(164, 140);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 32);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &loginForm::textBox1_KeyDown);
			this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &loginForm::textBox1_Validating);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Crimson;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(179, 315);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &loginForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(39, 204);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 23);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Password: ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(164, 201);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(249, 32);
			this->textBox2->TabIndex = 1;
			this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &loginForm::textBox2_KeyDown);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(53, 398);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(254, 23);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Don\'t have an Account\?";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Crimson;
			this->label5->Location = System::Drawing::Point(315, 398);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 23);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Sign Up";
			this->label5->Click += gcnew System::EventHandler(this, &loginForm::label5_Click);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(815, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(52, 44);
			this->button2->TabIndex = 4;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &loginForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImageLocation = L"";
			this->pictureBox1->Location = System::Drawing::Point(290, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(577, 448);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::pictureBox1_MouseUp);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkColor = System::Drawing::Color::MediumVioletRed;
			this->linkLabel1->Location = System::Drawing::Point(269, 266);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(185, 23);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot password\?";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &loginForm::linkLabel1_LinkClicked);
			// 
			// tomoe
			// 
			this->tomoe->Cursor = System::Windows::Forms::Cursors::Hand;
			this->tomoe->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tomoe.Image")));
			this->tomoe->Location = System::Drawing::Point(419, 201);
			this->tomoe->Name = L"tomoe";
			this->tomoe->Size = System::Drawing::Size(48, 32);
			this->tomoe->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->tomoe->TabIndex = 21;
			this->tomoe->TabStop = false;
			this->tomoe->Click += gcnew System::EventHandler(this, &loginForm::tomoe_Click);
			// 
			// mangekyou
			// 
			this->mangekyou->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mangekyou->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mangekyou.Image")));
			this->mangekyou->Location = System::Drawing::Point(419, 201);
			this->mangekyou->Name = L"mangekyou";
			this->mangekyou->Size = System::Drawing::Size(48, 32);
			this->mangekyou->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->mangekyou->TabIndex = 20;
			this->mangekyou->TabStop = false;
			this->mangekyou->Click += gcnew System::EventHandler(this, &loginForm::mangekyou_Click);
			// 
			// loginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(867, 448);
			this->Controls->Add(this->tomoe);
			this->Controls->Add(this->mangekyou);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"loginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"loginForm";
			this->Load += gcnew System::EventHandler(this, &loginForm::loginForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::loginForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::loginForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::loginForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tomoe))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mangekyou))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = textBox1;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void loginForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int xOffset;
		int yOffset;

		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			//xOffset = -e->X - System::Windows::Forms::SystemInformation::FrameBorderSize.Width;
			//yOffset = -e->Y - System::Windows::Forms::SystemInformation::SystemInformation::CaptionHeight - System::Windows::Forms::SystemInformation::FrameBorderSize.Height;

			xOffset = -e->X;
			yOffset = -e->Y;
			mouseOffset = gcnew Point(xOffset, yOffset);
			isMouseDown = true;
			this->Opacity = 0.6;
		}
	}

	private: System::Void loginForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown)
		{
			Point mousePos = System::Windows::Forms::Control::MousePosition;
			mousePos.Offset(mouseOffset->X, mouseOffset->Y);
			Location = mousePos;
		}
	}

	private: System::Void loginForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Changes the isMouseDown field so that the form does
				// not move unless the user is pressing the left mouse button.
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
			this->Opacity = 1;
		}

	}

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int xOffset;
		int yOffset;

		// enable dragging and get mouse position
		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			xOffset = -e->X - 273;
			yOffset = -e->Y;
			mouseOffset = gcnew Point(xOffset, yOffset);
			isMouseDown = true;
			this->Opacity = 0.6;
		}
	}

	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//check whether able to move
		if (isMouseDown)
		{
			Point mousePos = System::Windows::Forms::Control::MousePosition;
			mousePos.Offset(mouseOffset->X, mouseOffset->Y);
			Location = mousePos;
		}
	}

	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		/*
			Changes the isMouseDown field so that the form does
			not move unless the user is pressing the left mouse button.
			(disable dragging)
		*/
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
			this->Opacity = 1;
		}
	}

	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			textBox2->Focus(); // put the cursor on to the textbox
	}

	private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			button1->PerformClick();
	}

		   //login button was clicked
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			String^ username = textBox1->Text;
			String^ password = textBox2->Text;

			DB^ db = gcnew DB();

			//MySqlCommand^ cmd = gcnew MySqlCommand("select * from register_table where Username='" + username + "' and Password='" + password + "';", db->getConnection());
			MySqlCommand^ cmd = gcnew MySqlCommand("select * from register_table where Username= @username and Password= @password", db->getConnection());

			cmd->Parameters->Add("@username", MySqlDbType::VarChar)->Value = username;
			cmd->Parameters->Add("@password", MySqlDbType::VarChar)->Value = password;

			MySqlDataReader^ dr;

			db->openConnection();
			try
			{
				dr = cmd->ExecuteReader();
				int count = 0;
				while (dr->Read())
				{
					count += 1;
				}
				if (count == 1)
				{
					//MsgBox::Show("Login successful. Congratulations!");
					MainForm^ mainForm = gcnew MainForm();
					mainForm->Show();
					this->Hide();
				}
				else if (textBox1->Text->Length == 0 && textBox2->Text->Length == 0)
				{
					MsgBox::Show("Required fields are Empty.\n Please, try again..");
				}
				else if (String::IsNullOrWhiteSpace(textBox1->Text))
				{
					textBox1->Focus();
					MsgBox::Show("Please, enter a Username.");
				}
				else if (String::IsNullOrWhiteSpace(textBox2->Text))
				{
					textBox2->Focus();
					MsgBox::Show("Please, enter a valid Password.");
				}
				else
				{
					//MessageBox::Show("Username or password is invalid.\n Please, try again..");
					MsgBox::Show("Username or Password is Invalid.\n Please, try again..");
				}
			}
			catch (Exception^ ex)
			{
				//MessageBox::Show(ex->Message);
				MsgBox::Show(ex->Message);
			}


			db->closeConnection(); // Close the connection after Execute reader. ?


		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);
			MsgBox::Show(ex->Message);
		}

	}

	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);

	private: System::Void tomoe_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->PasswordChar == '*') {
			mangekyou->BringToFront();
			textBox2->PasswordChar = '\0';
		}
	}

	private: System::Void mangekyou_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->PasswordChar == '\0') {
			tomoe->BringToFront();
			textBox2->PasswordChar = '*';
		}
	}

	private: System::Void textBox1_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	};
}
