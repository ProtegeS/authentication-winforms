#pragma once

#include "loginForm.h"
#include "MsgBox.h"
#include "DB.h"

namespace authenticationwinforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for signUpForm
	/// </summary>
	public ref class signUpForm : public System::Windows::Forms::Form
	{
		// dragging the form
	private: Point^ mouseOffset;
	private: bool isMouseDown = false;

	private: String^ username;
		   String^ email;
		   String^ password;
	public:
		bool usernameCheck()
		{
			username = textBox1->Text;

			DB^ db = gcnew DB();

			//MySqlCommand^ cmd = gcnew MySqlCommand("Select count(*) from register_table where Username='" + username + "';", db->getConnection());
			MySqlCommand^ cmd = gcnew MySqlCommand("Select count(*) from register_table where Username= @username", db->getConnection());

			cmd->Parameters->AddWithValue("@username", username);

			db->openConnection();
			int TotalRows = 0;

			try
			{
				TotalRows = Convert::ToInt32(cmd->ExecuteScalar());
				db->closeConnection();
				if (TotalRows > 0)
				{
					MsgBox::Show("Username " + username + " that username is taken. Try another.");
					return true;
				}
				else
				{
					return false;
				}
			}
			catch (Exception^ ex)
			{
				MsgBox::Show(ex->Message);
			}

		}

		bool validUsername() {
			if (String::IsNullOrWhiteSpace(textBox1->Text)) {
				//textBox1->Focus();
				MsgBox::Show("Please, enter a Username.");
				return true;
			}
			else {
				username = textBox1->Text;
				return false;
			}
		}


		bool emailValidation() {
			if ((textBox2->Text != String::Empty) && (textBox2->Text->Contains("@")) && (textBox2->Text->Contains("."))) {
				email = textBox2->Text;
				return false;
			}
			else {
				//textBox2->Focus();
				MsgBox::Show("Please, enter a valid Email.");
				return true;
			}
		}

		bool passValidation() {
			bool passLength = false, hasDigit = false, hasUpper = false, hasLower = false, hasSymbol = false;

			if (textBox3->Text->Length >= 8)
				passLength = true;

			for each (Char c in this->textBox3->Text)
			{
				if (Char::IsDigit(c))
					hasDigit = true;

				else if (Char::IsUpper(c))
					hasUpper = true;

				else if (Char::IsLower(c))
					hasLower = true;

				else if (Char::IsSymbol(c))
					hasSymbol = true;

			}

			if (passLength && hasDigit && hasUpper && hasLower && hasSymbol) {
				password = textBox3->Text;
				return true;
			}
			else {
				//textBox3->Focus();
				MsgBox::Show("Please, enter a valid Password.");
				return false;
			}


		}



	private: loginForm^ f1; // link to loginForm
	public:
		signUpForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		// Create a constructor that will accept and save a link to the loginForm
		signUpForm(loginForm^ f1)
		{
			InitializeComponent();
			this->f1 = f1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~signUpForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button3;
	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(signUpForm::typeid));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Crimson;
			this->label5->Location = System::Drawing::Point(350, 448);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 23);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Sign Up";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(88, 448);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(254, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Don\'t have an Account\?";
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(816, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 44);
			this->button2->TabIndex = 16;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &signUpForm::button2_Click);
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
			this->button1->Location = System::Drawing::Point(589, 373);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 37);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &signUpForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(538, 182);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(249, 32);
			this->textBox2->TabIndex = 13;
			this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &signUpForm::textBox2_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(878, 398);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 23);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Sign Up";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(460, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 23);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Email:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(538, 121);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 32);
			this->textBox1->TabIndex = 14;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &signUpForm::textBox1_KeyDown);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(408, 124);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 23);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Username: ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(530, 32);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(157, 44);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Sign Up";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(416, 448);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::pictureBox1_MouseUp);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(332, 312);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(201, 23);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Re-Enter Password: ";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(538, 241);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(249, 32);
			this->textBox3->TabIndex = 14;
			this->textBox3->UseSystemPasswordChar = true;
			this->textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &signUpForm::textBox3_KeyDown);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(413, 250);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 23);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Password: ";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(538, 303);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(249, 32);
			this->textBox4->TabIndex = 13;
			this->textBox4->UseSystemPasswordChar = true;
			this->textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &signUpForm::textBox4_KeyDown);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(47, 44);
			this->button3->TabIndex = 16;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &signUpForm::button3_Click);
			// 
			// signUpForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(867, 448);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"signUpForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"signUpForm";
			this->Load += gcnew System::EventHandler(this, &signUpForm::signUpForm_Load_1);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::signUpForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::signUpForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &signUpForm::signUpForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void signUpForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = textBox1;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		f1->Show();
		this->Close();
	}

	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int xOffset;
		int yOffset;

		// enable dragging and get mouse position
		if (e->Button == Windows::Forms::MouseButtons::Left)
		{
			xOffset = -e->X;
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


	private: System::Void signUpForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
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
	private: System::Void signUpForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown)
		{
			Point mousePos = System::Windows::Forms::Control::MousePosition;
			mousePos.Offset(mouseOffset->X, mouseOffset->Y);
			Location = mousePos;
		}
	}
	private: System::Void signUpForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Changes the isMouseDown field so that the form does
				// not move unless the user is pressing the left mouse button.
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
			this->Opacity = 1;
		}
	}
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			textBox2->Focus(); // put the cursor on to the textbox
	}
	private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			textBox3->Focus(); // put the cursor on to the textbox
	}
	private: System::Void textBox3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			textBox4->Focus(); // put the cursor on to the textbox
	}
	private: System::Void textBox4_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			button1->PerformClick();
	}

		   //Register button was clicked
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(textBox1->Text) && String::IsNullOrWhiteSpace(textBox2->Text) && String::IsNullOrWhiteSpace(textBox3->Text) && String::IsNullOrWhiteSpace(textBox4->Text))
		{
			MsgBox::Show("Required fields are Empty.\n Please, try again..");
			return;
		}
		if (!validUsername() && !usernameCheck() && !emailValidation() && passValidation())
		{
			try
			{
				//username = textBox1->Text;
				//email = textBox2->Text;
				//String^ password = textBox3->Text;

				if (textBox3->Text == textBox4->Text) // check for password match
				{
					DB^ db = gcnew DB();

					//MySqlCommand^ cmd = gcnew MySqlCommand("insert into register_table values('" + username + "','" + email + "','" + password + "')", db->getConnection());
					MySqlCommand^ cmd = gcnew MySqlCommand("insert into register_table values(@username, @email, @password)", db->getConnection());

					cmd->Parameters->Add("@username", MySqlDbType::VarChar)->Value = username;
					cmd->Parameters->Add("@email", MySqlDbType::VarChar)->Value = email;
					cmd->Parameters->Add("@password", MySqlDbType::VarChar)->Value = password;

					MySqlDataReader^ dr;

					db->openConnection();
					try
					{
						dr = cmd->ExecuteReader();
						textBox1->Text = "";
						textBox2->Text = "";
						textBox3->Text = "";
						textBox4->Text = "";

						//MessageBox::Show("Sign Up success\n Go to back for login");
						MsgBox::Show("Sign Up success\n Go to back for Login");
					}
					catch (Exception^ ex)
					{
						//MessageBox::Show(ex->Message);
						MsgBox::Show(ex->Message);
					}
					db->closeConnection();
				}
				else
				{
					//MessageBox::Show("Confirm Password does not match!");
					MsgBox::Show("Confirm Password does not match!");
				}

			}
			catch (Exception^ ex)
			{
				MsgBox::Show(ex->Message);
				//MessageBox::Show(ex->Message);
			}
		}
	}

	};
}
