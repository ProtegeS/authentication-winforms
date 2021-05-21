#include "loginForm.h"
#include "signUpForm.h"
#include "ForgotPassForm.h"
#include <Windows.h>

using namespace authenticationwinforms;

System::Void loginForm::label5_Click(System::Object^ sender, System::EventArgs^ e) {
	signUpForm^ f2 = gcnew signUpForm(this); // "this" represents the current instance of Form1.
	f2->Show(); // display signUpForm
	this->Hide(); // hide loginform ("this" is the current form) | loginForm::Hide()
}

System::Void loginForm::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	ForgotPassForm^ f3 = gcnew ForgotPassForm(this); // "this" represents the current instance of Form1.
	f3->Show(); // display signUpForm
	this->Hide(); // hide loginform ("this" is the current form) | loginForm::Hide()
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew loginForm);

	return 0;
}
