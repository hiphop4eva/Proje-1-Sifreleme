#include "header.h"

HWND inputString, outputString;
HWND inputMove;
HWND checkCeasar, checkEncode, checkDecode, checkFile;
HWND buttonGo, buttonImportFile;

HRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);

int WINAPI wWinMain(HINSTANCE hinstance, HINSTANCE hpreviousinstance, PWSTR pCmdLine, int nCmdShow) {
	
	//PWSTR windowName = L"Main Window";

	WNDCLASS windowMain = {};
	windowMain.hInstance = hinstance;
	windowMain.lpszClassName = L"Main Window";
	windowMain.lpfnWndProc = WindowProc;

	RegisterClass(&windowMain);

	HWND hwnd = CreateWindowEx(0, L"Main Window", L"Encryption", WS_OVERLAPPEDWINDOW, 100, 100, 1350, 450, NULL, NULL, hinstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, hwnd, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

HRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
	int columnInputString = 10;
	int columnInputMove = columnInputString;
	int columnOutputString = columnInputString + 630;
	int columnButtonGo = columnInputString + 510;
	int rowInputString = 10;
	int rowInputMove = rowInputString + 220;
	int rowOutputString = rowInputString;
	int rowButtonGo = rowInputString + 220;

	std::wstring inputText;
	Ceasar Ceasar;
	Ceasar.kayma = 3;

	switch(uMsg) {

	case WM_CREATE: {

		inputString  = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL, columnInputString , rowInputString , 600, 200, hwnd, (HMENU)1, NULL, NULL);
		outputString = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL, columnOutputString, rowOutputString, 600, 200, hwnd, (HMENU)2, NULL, NULL);

		inputMove        = CreateWindow(L"EDIT"  , L"3"          , WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnInputMove      , rowInputMove      , 90, 20, hwnd, (HMENU)3, NULL, NULL);
		checkEncode      = CreateWindow(L"BUTTON", L"Encode"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP, columnInputMove      , rowInputMove + 30 , 90, 20, hwnd, (HMENU)4, NULL, NULL);
		checkDecode      = CreateWindow(L"BUTTON", L"Decode"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON           , columnInputMove + 120, rowInputMove + 30 , 90, 20, hwnd, (HMENU)5, NULL, NULL);
		checkCeasar      = CreateWindow(L"BUTTON", L"Caesar"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP, columnInputMove      , rowInputMove + 60 , 90, 20, hwnd, (HMENU)6, NULL, NULL);
		buttonGo         = CreateWindow(L"BUTTON", L"Execute"    , WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnButtonGo       , rowButtonGo       , 90, 20, hwnd, (HMENU)7, NULL, NULL);
		buttonImportFile = CreateWindow(L"BUTTON", L"Import File", WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnButtonGo - 110 , rowButtonGo       , 90, 20, hwnd, (HMENU)9, NULL, NULL);
		PostMessage(checkEncode, BM_SETCHECK, BST_CHECKED, 0);
		PostMessage(checkCeasar, BM_SETCHECK, BST_CHECKED, 0);

		checkFile   = CreateWindow(L"BUTTON", L"Export contents into file",   WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTOCHECKBOX, columnInputMove, rowInputMove + 90, 270, 20, hwnd, (HMENU)8, NULL, NULL);
	}
				  
	case WM_COMMAND: {
		switch (HIWORD(wparam)) {
		case BN_CLICKED:
			switch (LOWORD(wparam)) {
			case 7: {
				if (IsDlgButtonChecked(hwnd, 4) == BST_CHECKED) {
					inputText.clear();
					Ceasar.metin.clear();
					Ceasar.sifrelimetin.clear();

					inputText.resize(GetWindowTextLength(inputString) + 1);
					Ceasar.metin.resize(GetWindowTextLength(inputString) + 1);
					GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);
					Ceasar.metin = narrowenString(inputText);

					Ceasar.sifrele();
					SetWindowText(outputString, (PWSTR)widenString(Ceasar.sifrelimetin).c_str());
					UpdateWindow(outputString);
				}
				else if (IsDlgButtonChecked(hwnd, 5) == BST_CHECKED) {
					inputText.clear();
					Ceasar.sifrelimetin.clear();
					Ceasar.desifrelimetin.clear();

					inputText.resize(GetWindowTextLength(inputString) + 1);
					Ceasar.sifrelimetin.resize(GetWindowTextLength(inputString) + 1);
					GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);
					Ceasar.sifrelimetin = narrowenString(inputText);

					Ceasar.desifrele();
					SetWindowText(outputString, (PWSTR)widenString(Ceasar.desifrelimetin).c_str());
					UpdateWindow(outputString);
				}
				else { MessageBox(hwnd, L"Neither encoding nor decoding option is selected.", L"Error", MB_OK); }
			}

			default:
				break;
			}

		default:
			break;
		}

	default:
		break;
	}

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
		return 0;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}

	return DefWindowProc(hwnd, uMsg, wparam, lparam);
}