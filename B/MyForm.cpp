#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main(array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	B::MyForm form;
	Application::Run(%form); }