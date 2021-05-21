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
	/// Summary for ForgotPassForm
	/// </summary>
	public ref class ForgotPassForm : public System::Windows::Forms::Form
	{
		// dragging the form
	private: Point^ mouseOffset;
	private: bool isMouseDown = false;

	public:
		// To generate a random OTP with range 
		Random^ r = gcnew Random();
		int^ OTP = r->Next(1000, 9999);


	private: System::Windows::Forms::Label^ label6;
	public:
		bool passValidation(String^ pass)
		{
			bool passLength = false, hasDigit = false, hasUpper = false, hasLower = false, hasSymbol = false;

			if (pass->Length >= 8)
				passLength = true;

			for each (Char c in pass)
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
				return true;
			}
			else {
				MsgBox::Show("Please, enter a valid Password.");
				return false;
			}
		}

	public: String^ username; // used in send OTP and Reset button clicked

	private: loginForm^ f1; // link to loginForm
	public:
		ForgotPassForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		// Create a constructor that will accept and save a link to the loginForm
		ForgotPassForm(loginForm^ f1)
		{
			InitializeComponent();
			this->f1 = f1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ForgotPassForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ForgotPassForm::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(816, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(52, 40);
			this->button2->TabIndex = 15;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ForgotPassForm::button2_Click);
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
			this->button1->Location = System::Drawing::Point(494, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 37);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ForgotPassForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(606, 224);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(249, 32);
			this->textBox2->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(451, 227);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 23);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Confirm OTP: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(606, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 32);
			this->textBox1->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(471, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 23);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Username: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(502, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(299, 44);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Reset Password";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Left;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(440, 448);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::pictureBox1_MouseUp);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(476, 282);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 23);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Password: ";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(606, 279);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(249, 32);
			this->textBox3->TabIndex = 13;
			this->textBox3->UseSystemPasswordChar = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(395, 340);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(195, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Confirm Password: ";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(606, 337);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(249, 32);
			this->textBox4->TabIndex = 12;
			this->textBox4->UseSystemPasswordChar = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Crimson;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(678, 399);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 37);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ForgotPassForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Crimson;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(574, 124);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(144, 37);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Send OTP";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ForgotPassForm::button4_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Crimson;
			this->label6->Location = System::Drawing::Point(476, 173);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 23);
			this->label6->TabIndex = 17;
			// 
			// ForgotPassForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(867, 448);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ForgotPassForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ForgotPassForm";
			this->Load += gcnew System::EventHandler(this, &ForgotPassForm::ForgotPassForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::ForgotPassForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::ForgotPassForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ForgotPassForm::ForgotPassForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ForgotPassForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = textBox1;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		f1->Show();
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
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

	private: System::Void ForgotPassForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
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
	private: System::Void ForgotPassForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown)
		{
			Point mousePos = System::Windows::Forms::Control::MousePosition;
			mousePos.Offset(mouseOffset->X, mouseOffset->Y);
			Location = mousePos;
		}
	}
	private: System::Void ForgotPassForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Changes the isMouseDown field so that the form does
				// not move unless the user is pressing the left mouse button.
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isMouseDown = false;
			this->Opacity = 1;
		}
	}

		   // Send OTP button clicked 
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			DB^ db = gcnew DB();

			// authorized sender data
			String^ password = "*******";

			// mail details
			String^ to;
			String^ from = "alec.sliusar@gmail.com";
			String^ subject = "OTP to Reset Your Password";

			username = textBox1->Text; // username (login form database)
			String^ msg = "Hi " + username + "," + "\n" + "Your OTP is " + OTP; // message with otp

			// command to search the mail address of that particular user based on username
			MySqlCommand^ cmd = gcnew MySqlCommand("select * from register_table where Username='" + username + "';", db->getConnection());
			MySqlDataReader^ dr;

			db->openConnection();
			dr = cmd->ExecuteReader();
			while (dr->Read())
			{
				to = dr->GetString(1); // store the mail address into the variable
			}
			db->closeConnection();

			try
			{
				// send mail to given mail address through http protocol

				MailMessage^ mail = gcnew MailMessage(from, to, subject, msg); // make a object of mail and give the all parameter
				SmtpClient^ smtp = gcnew SmtpClient("smtp.gmail.com"); // give the host site
				smtp->Port = 587; // MTP with STARTTLS on port 25 or 587
				smtp->Credentials = gcnew System::Net::NetworkCredential(from, password); // provide the gmail credentials
				smtp->EnableSsl = true; // make sure the secure connection (enable SSL)

				smtp->Send(mail); // command to send mail
				//MessageBox::Show("OTP sent.", "Success!", MessageBoxButtons::OK);
				MsgBox::Show("OTP Sent Successfully.");
				label6->Text = "OTP sent to " + to;

			}
			catch (Exception^ ex)
			{
				//MessageBox::Show(ex->Message);
				MsgBox::Show(ex->Message);
			}


		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);
			MsgBox::Show(ex->Message);
		}

	}

		   // Reset button clicked
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			DB^ db = gcnew DB();

			if (textBox2->Text == OTP->ToString()) { // check the input OTP is correct or not

				String^ pass = textBox3->Text;

				if (passValidation(pass))
				{
					if (pass == textBox4->Text) // check the password and confirm password field matches or not
					{
						String^ password = textBox4->Text;

						// mysql command to update the password for a particular user

						//MySqlCommand^ cmd = gcnew MySqlCommand("update register_table set Password='" + password + "' where Username='" + username + "'", db->getConnection());
						MySqlCommand^ cmd = gcnew MySqlCommand("update register_table set Password= @password where Username= @username", db->getConnection());

						cmd->Parameters->Add("@password", MySqlDbType::VarChar)->Value = password;
						cmd->Parameters->Add("@username", MySqlDbType::VarChar)->Value = username;

						db->openConnection();
						MySqlDataReader^ dr = cmd->ExecuteReader(); // execute the mysql command
						db->closeConnection();
						//MessageBox::Show("Password Reset successful. Congrats!");
						MsgBox::Show("Password Reset successful. \nCongrats!");
					}
					else
					{
						//MessageBox::Show("Confirm Password does not match!");
						MsgBox::Show("Confirm Password does not match!");
					}
				}

			}
			else
			{
				//MessageBox::Show("OTP does not match. Please, retry.");
				MsgBox::Show("OTP does not match.\nPlease, retry.");
			}
		}
		catch (Exception^ ex)
		{
			//MessageBox::Show(ex->Message);
			MsgBox::Show(ex->Message);
		}
	}
	};
}
