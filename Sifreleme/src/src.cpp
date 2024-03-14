#include "header.h"

HWND inputString, inputKey, outputString;
HWND inputSecondary;
HWND checkCeasar, checkVieg, checkEncode, checkDecode, checkFile;
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
	const int columnInputString = 10;
	//const int columnInputKey = columnInputString;
	const int columnInputSecondary = columnInputString;
	const int columnOutputString = columnInputString + 630;
	const int columnButtonGo = columnInputString + 510;

	const int rowInputString = 10;
	//const int rowInputKey = rowInputString + 220;
	const int rowInputSecondary = rowInputString + 220;
	const int rowOutputString = rowInputString;
	const int rowButtonGo = rowInputString + 220;

	std::string alfabe = "abcdefghijklmnopqrstuvwxyz";
	std::wstring inputText;
	std::wstring inputTextSecondary;

	Ceasar Ceasar;
	Ceasar.kayma = 3;
	PWSTR filePath;

	switch(uMsg) {

	case WM_CREATE: {

		inputString  = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL, columnInputString , rowInputString , 600, 200, hwnd, (HMENU)1, NULL, NULL);
		//inputKey     = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_HSCROLL | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOHSCROLL, columnInputKey    , rowInputKey    , 250, 40 , hwnd, (HMENU)11, NULL, NULL);
		outputString = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_LEFT | ES_AUTOVSCROLL, columnOutputString, rowOutputString, 600, 200, hwnd, (HMENU)2, NULL, NULL);

		inputSecondary   = CreateWindow(L"EDIT"  , L"3"          , WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnInputSecondary      , rowInputSecondary      , 90, 20, hwnd, (HMENU)3, NULL, NULL);
		checkEncode      = CreateWindow(L"BUTTON", L"Encode"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP, columnInputSecondary      , rowInputSecondary + 30 , 90, 20, hwnd, (HMENU)4, NULL, NULL);
		checkDecode      = CreateWindow(L"BUTTON", L"Decode"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON           , columnInputSecondary + 120, rowInputSecondary + 30 , 90, 20, hwnd, (HMENU)5, NULL, NULL);
		checkCeasar      = CreateWindow(L"BUTTON", L"Caesar"     , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP, columnInputSecondary      , rowInputSecondary + 60 , 90, 20, hwnd, (HMENU)6, NULL, NULL);
		checkVieg        = CreateWindow(L"BUTTON", L"Viegerene"  , WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTORADIOBUTTON           , columnInputSecondary + 120, rowInputSecondary + 60 , 90, 20, hwnd, (HMENU)10, NULL, NULL);
		buttonGo         = CreateWindow(L"BUTTON", L"Execute"    , WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnButtonGo            , rowButtonGo            , 90, 20, hwnd, (HMENU)7, NULL, NULL);
		buttonImportFile = CreateWindow(L"BUTTON", L"Import File", WS_VISIBLE | WS_BORDER | WS_CHILD                                , columnButtonGo - 110 , rowButtonGo       , 90, 20, hwnd, (HMENU)9, NULL, NULL);
		PostMessage(checkEncode, BM_SETCHECK, BST_CHECKED, 0);
		PostMessage(checkCeasar, BM_SETCHECK, BST_CHECKED, 0);

		checkFile   = CreateWindow(L"BUTTON", L"Export contents into file",   WS_VISIBLE | WS_BORDER | WS_CHILD | BS_AUTOCHECKBOX, columnInputSecondary, rowInputSecondary + 90, 270, 20, hwnd, (HMENU)8, NULL, NULL);
	}
				  
	case WM_COMMAND: {
		switch (HIWORD(wparam)) {
		case BN_CLICKED:
			switch (LOWORD(wparam)) {
			//If execute button is pressed
			case 7: {
				//Ceasar crypt case
				if (IsDlgButtonChecked(hwnd, 6) == BST_CHECKED) {
					if (IsDlgButtonChecked(hwnd, 4) == BST_CHECKED) {
						inputTextSecondary.clear();
						inputTextSecondary.resize(GetWindowTextLength(inputSecondary) + 1);
						GetWindowText(inputSecondary, (PWSTR)inputTextSecondary.c_str(), GetWindowTextLength(inputSecondary) + 1);

						if (!strtol(narrowenString(inputTextSecondary).c_str(), NULL, 10)) {
							MessageBox(hwnd, L"Please enter an integer in the secondary input.", L"Error", MB_OK);
						}
						
						else {
							inputText.clear();
							Ceasar.metin.clear();
							Ceasar.sifrelimetin.clear();

							inputText.resize(GetWindowTextLength(inputString) + 1);
							Ceasar.metin.resize(GetWindowTextLength(inputString) + 1);
							GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);
							Ceasar.metin = narrowenString(inputText);
							Ceasar.kayma = std::stol(inputTextSecondary);

							Ceasar.sifrele();
							SetWindowText(outputString, (PWSTR)widenString(Ceasar.sifrelimetin).c_str());
							UpdateWindow(outputString);

							if (IsDlgButtonChecked(hwnd, 8) == BST_CHECKED) {
								std::ofstream outputFile;
								outputFile.open("cipher_text.txt", std::ios::out);

								outputFile << Ceasar.sifrelimetin;
								outputFile.close();
								MessageBox(hwnd, L"The input string has been encrypted and exported to the \"cipher_text.txt\" file.", L"Success", MB_OK);
							}
							else{
								MessageBox(hwnd, L"The input string has been encrypted.", L"Success", MB_OK);
							}
						}
					}
					else if (IsDlgButtonChecked(hwnd, 5) == BST_CHECKED) {
						inputTextSecondary.clear();
						inputTextSecondary.resize(GetWindowTextLength(inputSecondary) + 1);
						GetWindowText(inputSecondary, (PWSTR)inputTextSecondary.c_str(), GetWindowTextLength(inputSecondary) + 1);

						if (!strtol(narrowenString(inputTextSecondary).c_str(), NULL, 10)) {
							MessageBox(hwnd, L"Please enter an integer in the secondary input.", L"Error", MB_OK);
						}

						else {
							inputText.clear();
							Ceasar.sifrelimetin.clear();
							Ceasar.desifrelimetin.clear();

							inputText.resize(GetWindowTextLength(inputString) + 1);
							Ceasar.sifrelimetin.resize(GetWindowTextLength(inputString) + 1);
							GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);
							Ceasar.sifrelimetin = narrowenString(inputText);
							Ceasar.kayma = std::stol(inputTextSecondary);

							Ceasar.desifrele();
							SetWindowText(outputString, (PWSTR)widenString(Ceasar.desifrelimetin).c_str());
							UpdateWindow(outputString);

							if (IsDlgButtonChecked(hwnd, 8) == BST_CHECKED) {
								std::ofstream outputFile;
								outputFile.open("restore_text.txt", std::ios::out);

								outputFile << Ceasar.desifrelimetin;
								outputFile.close();
								MessageBox(hwnd, L"The input string has been decrypted and exported to the \"restore_text.txt\" file.", L"Success", MB_OK);
							}
							else {
								MessageBox(hwnd, L"The input string has been decrypted.", L"Success", MB_OK);
							}
						}
					}
					else { MessageBox(hwnd, L"Neither encoding nor decoding option is selected.", L"Error", MB_OK); }
				}

				//Viegener crypt case
				else if(IsDlgButtonChecked(hwnd, 10) == BST_CHECKED) {

					if (IsDlgButtonChecked(hwnd, 4) == BST_CHECKED) {
						inputTextSecondary.clear();
						inputTextSecondary.resize(GetWindowTextLength(inputSecondary) + 1);
						GetWindowText(inputSecondary, (PWSTR)inputTextSecondary.c_str(), GetWindowTextLength(inputSecondary) + 1);
						
						if ((strtol(narrowenString(inputTextSecondary).c_str(), NULL, 10)) != 0) {
							MessageBox(hwnd, L"Please enter a character in the secondary input.", L"Error", MB_OK);
						}

						else {
							inputText.clear();
							inputText.resize(GetWindowTextLength(inputString) + 1);
							GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);

							std::string cipher = vieg::sifrele(narrowenString(inputText), narrowenString(inputTextSecondary), alfabe);

							SetWindowText(outputString, (PWSTR)widenString(cipher).c_str());
							UpdateWindow(outputString);

							if (IsDlgButtonChecked(hwnd, 8) == BST_CHECKED) {
								std::ofstream outputFile;
								outputFile.open("cipher_text.txt", std::ios::out);

								outputFile << cipher;
								outputFile.close();
								MessageBox(hwnd, L"The input string has been encrypted and exported to the \"cipher_text.txt\" file.", L"Success", MB_OK);
							}
							else {
								MessageBox(hwnd, L"The input string has been encrypted.", L"Success", MB_OK);
							}
						}
					}

					else if (IsDlgButtonChecked(hwnd, 5) == BST_CHECKED) {
						inputTextSecondary.clear();
						inputTextSecondary.resize(GetWindowTextLength(inputSecondary) + 1);
						GetWindowText(inputSecondary, (PWSTR)inputTextSecondary.c_str(), GetWindowTextLength(inputSecondary) + 1);

						if ((strtol(narrowenString(inputTextSecondary).c_str(), NULL, 10)) != 0) {
							MessageBox(hwnd, L"Please enter a character in the secondary input.", L"Error", MB_OK);
						}

						else {
							inputText.clear();
							inputText.resize(GetWindowTextLength(inputString) + 1);
							GetWindowText(inputString, (PWSTR)inputText.c_str(), GetWindowTextLength(inputString) + 1);

							std::string restore = vieg::sifreCozumu(narrowenString(inputText), narrowenString(inputTextSecondary), alfabe);

							SetWindowText(outputString, (PWSTR)widenString(restore).c_str());
							UpdateWindow(outputString);

							if (IsDlgButtonChecked(hwnd, 8) == BST_CHECKED) {
								std::ofstream outputFile;
								outputFile.open("cipher_text.txt", std::ios::out);

								outputFile << restore;
								outputFile.close();
								MessageBox(hwnd, L"The input string has been decrypted and exported to the \"restore_text.txt\" file.", L"Success", MB_OK);

							}
							else { 
								MessageBox(hwnd, L"The input string has been decrypted.", L"Success", MB_OK); 
							}
						}
					}

					else {
						MessageBox(hwnd, L"Neither encoding nor decoding option is selected.", L"Error", MB_OK);
					}

				}

				else { MessageBox(hwnd, L"No encoding style is selected.", L"Error", MB_OK); }
				break;;
			}
			//If import file button is pressed
			case 9: {

				CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

				IFileOpenDialog* pFileOpen;

				CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, (void**)&pFileOpen);
				pFileOpen->Show(NULL);

				HRESULT hr;
				IShellItem* pShell;
				hr = pFileOpen->GetResult(&pShell);

				if (SUCCEEDED(hr)){
					pShell->GetDisplayName(SIGDN_FILESYSPATH, &filePath);
					pShell->Release();
					pFileOpen->Release();
				}

				std::ifstream inputFile;
				inputFile.open(filePath);

				std::string inputFileString;
				std::string buffer;

				while (inputFile.good()) {
					std::getline(inputFile, buffer);
					buffer += "\r\n";
					inputFileString += buffer;
				}

				inputFile.close();

				SetWindowText(inputString, (PWSTR)widenString(inputFileString).c_str());
				UpdateWindow(inputString);
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