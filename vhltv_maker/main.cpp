#include <Windows.h>
#include "main.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace vhltv_maker;

[STAThread]

INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, INT ) {
	Application::Run( gcnew main );
	return TRUE;
}