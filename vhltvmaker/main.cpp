#include <Windows.h>
#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

#pragma comment( lib, "user32.lib" )

[STAThread]

INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, INT ) {
	Application::Run( gcnew vhltvmaker::main() );
	return TRUE;
}