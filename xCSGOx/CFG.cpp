#include "CFG.h"
#include "Includes.h"
#include "Menu.h"

using namespace std;

CFGSaver CFG;
LPSTR currentpath;
fstream fileStream;
string currrpath;

string getexepath()
{
	char result[MAX_PATH];
	return string(result, GetModuleFileName(NULL, result, MAX_PATH));
}

void CFGSaver::Find()
{
	string currpath = getexepath();
	if (currpath.find(".exe")) {
		currpath = currpath.replace(currpath.end() - 4, currpath.end(), ".ini");
		currentpath = const_cast<char*>(currpath.c_str());
	}
	currrpath = currentpath;
	fileStream.open(currentpath);
	if (fileStream.fail()) {
		CFG.Create();
	}
	else {
		CFG.Load();
	}
}

void CFGSaver::Create()
{
	if (WritePrivateProfileString("Aimbot", "Enabled", "0", currentpath)) {
		WritePrivateProfileString("Aimbot", "FOV", "20", currentpath);
		WritePrivateProfileString("Aimbot", "Smooth", "30", currentpath);
		WritePrivateProfileString("Aimbot", "=====", "=====", currentpath);
		WritePrivateProfileString("Triggerbot", "Enabled", "0", currentpath);
		WritePrivateProfileString("Triggerbot", "Delay", "0", currentpath);
		WritePrivateProfileString("Triggerbot", "=====", "=====", currentpath);
		WritePrivateProfileString("GlowESP", "Enabled", "0", currentpath);
		WritePrivateProfileString("GlowESP", "Type", "0", currentpath);
		WritePrivateProfileString("GlowESP", "=====", "=====", currentpath);
		WritePrivateProfileString("Bunnyhop", "Enabled", "0", currentpath);
		WritePrivateProfileString("Bunnyhop", "Type", "0", currentpath);
		WritePrivateProfileString("Bunnyhop", "=====", "=====", currentpath);
		WritePrivateProfileString("NoFlash", "Enabled", "0", currentpath);
		WritePrivateProfileString("NoFlash", "Type", "0", currentpath);
		WritePrivateProfileString("NoFlash", "=====", "=====", currentpath);
		WritePrivateProfileString("Radarhack", "Enabled", "0", currentpath);
		WritePrivateProfileString("Radarhack", "=====", "=====", currentpath);
		WritePrivateProfileString("Keys", "GlowESP", "112", currentpath);
		WritePrivateProfileString("Keys", "Triggerbot", "113", currentpath);
		WritePrivateProfileString("Keys", "TriggerKey", "18", currentpath);
		WritePrivateProfileString("Keys", "Bunnyhop", "114", currentpath);
		WritePrivateProfileString("Keys", "BunnyKey", "32", currentpath);
		WritePrivateProfileString("Keys", "NoFlash", "115", currentpath);
		WritePrivateProfileString("Keys", "RadarHack", "117", currentpath);
		WritePrivateProfileString("Keys", "Aimbot", "118", currentpath);
		WritePrivateProfileString("Keys", "AimKey", "1", currentpath);
		WritePrivateProfileString("Keys", "RankReveal", "120", currentpath);
		WritePrivateProfileString("Keys", "ExitKey", "36", currentpath);
		WritePrivateProfileString("Keys", "CFGKey", "119", currentpath);

		cout << ">> Plik konfiguracyjny stworzony\n";
	}
	else {
		cout << ">> Blad przy wpisywaniu do pliku konfiguracyjnego\n";
	}
	fileStream.close();
}

void CFGSaver::Save()
{
	system("cls");
	int sel = 0;
	while (sel != 1 && sel != 2) {
		cout << "\nZAPIS:\n";
		cout << "Zapisac aktualne ustawienia (wlacz/wylacz)?\n";
		cout << "1 - Tak\n";
		cout << "2 - Nie\n";
		cout << "Wybierz: ";
		cin >> sel;
	}
	string currpath = getexepath();
	if (currpath.find(".exe")) {
		currpath = currpath.replace(currpath.end() - 4, currpath.end(), ".ini");
		currentpath = const_cast<char*>(currpath.c_str());
	}
	cout << "Lokalizacja pliku: " << currentpath << endl;
	fileStream.open(currentpath);
	if (fileStream.fail()) {
		cout << "Brak pliku xCSGOx.ini!\n";
	}
	else {
		LPCSTR Setting;
		char Setting2[255];
		if (sel == 1)
		{
			if (Settings.Aimbot.Enabled == true) Setting = "1";
			else Setting = "0";
			if (WritePrivateProfileString("Aimbot", "Enabled", Setting, currentpath)) {

				if (Settings.Triggerbot.Enabled == true) Setting = "1";
				else Setting = "0";
				WritePrivateProfileString("Triggerbot", "Enabled", Setting, currentpath);

				if (Settings.Visuals.Glow.Enabled == true) Setting = "1";
				else Setting = "0";
				WritePrivateProfileString("GlowESP", "Enabled", Setting, currentpath);
				WritePrivateProfileString("GlowESP", "Type", itoa(Settings.Visuals.Glow.Type, Setting2, 10), currentpath);

				if (Settings.Bunnyhop.Enabled == true) Setting = "1";
				else Setting = "0";
				WritePrivateProfileString("Bunnyhop", "Enabled", Setting, currentpath);
				WritePrivateProfileString("Bunnyhop", "Type", itoa(Settings.Bunnyhop.Type, Setting2, 10), currentpath);

				if (Settings.Visuals.NoFlash.Enabled == true) Setting = "1";
				else Setting = "0";
				WritePrivateProfileString("NoFlash", "Enabled", Setting, currentpath);
				WritePrivateProfileString("NoFlash", "Type", itoa(Settings.Visuals.NoFlash.Type, Setting2, 10), currentpath);

				cout << ">> Zapisano aktualne ustawienia\n";
			}
		}
			else {
				cout << ">> Blad przy wpisywaniu do pliku konfiguracyjnego lub wybrano opcje 'Nie'\n";
			}

			sel = 0;
			while (sel != 1 && sel != 2) {
				cout << "\nZAPIS:\n";
				cout << "Zmiana ustawien aimbota?\n";
				cout << "1 - Tak\n";
				cout << "2 - Nie\n";
				cout << "Wybierz: ";
				cin >> sel;
			}

			if (sel == 1) {
				int FOV;
				int Smooth;
				cout << "\nFOV(1-999): ";
				cin >> FOV;
				cout << "Smooth(1-999): ";
				cin >> Smooth;

				WritePrivateProfileString("Aimbot", "FOV", itoa(FOV,Setting2,10), currentpath);
				WritePrivateProfileString("Aimbot", "Smooth", itoa(Smooth, Setting2, 10), currentpath);
			}

			sel = 0;
			while (sel != 1 && sel != 2) {
				cout << "\nZAPIS:\n";
				cout << "Zmiana ustawien triggerbota?\n";
				cout << "1 - Tak\n";
				cout << "2 - Nie\n";
				cout << "Wybierz: ";
				cin >> sel;
			}

			if (sel == 1) {
				int Delay;
				cout << "\nDelay(0-999): ";
				cin >> Delay;

				WritePrivateProfileString("Triggerbot", "Delay", itoa(Delay, Setting2, 10), currentpath);
			}

			sel = 0;
			while (sel != 1 && sel != 2) {
				cout << "\nZAPIS:\n";
				cout << "Zmiana ustawien klawiszy?\n";
				cout << "1 - Tak\n";
				cout << "2 - Nie\n";
				cout << "Wybierz: ";
				cin >> sel;
			}

			if (sel == 1) {
				int Key;
				cout << "\GlowESP: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "GlowESP", itoa(Key, Setting2, 10), currentpath);

				cout << "\Triggerbot: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "Triggerbot", itoa(Key, Setting2, 10), currentpath);

				cout << "\TriggerKey: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "TriggerKey", itoa(Key, Setting2, 10), currentpath);

				cout << "\Bunnyhop: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "Bunnyhop", itoa(Key, Setting2, 10), currentpath);

				cout << "\BunnyKey: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "BunnyKey", itoa(Key, Setting2, 10), currentpath);

				cout << "\NoFlash: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "NoFlash", itoa(Key, Setting2, 10), currentpath);

				cout << "\RadarHack: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "RadarHack", itoa(Key, Setting2, 10), currentpath);

				cout << "\RankReveal: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "RankReveal", itoa(Key, Setting2, 10), currentpath);

				cout << "\ExitKey: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "ExitKey", itoa(Key, Setting2, 10), currentpath);

				cout << "\CFGKey: ";
				cin >> Key;
				WritePrivateProfileString("Keys", "CFGKey", itoa(Key, Setting2, 10), currentpath);
			}

			cout << "\nZAPISANO!\n\n";
			Sleep(1000);
			system("cls");
			DrawMenu.DrawMenu();
			CFG.Print();
	}
}


void CFGSaver::Load()
{
	cout << ">> Znaleziono plik konfiguracyjny\n";
	cout << ">> Ladowanie ustawien...\n";
	char Setting[255];

	GetPrivateProfileString("Aimbot", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Aimbot.Enabled = stoi(Setting);
	GetPrivateProfileString("Aimbot", "FOV", "20", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Aimbot.fov = stoi(Setting);
	GetPrivateProfileString("Aimbot", "Smooth", "30", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Aimbot.smooth = stoi(Setting);
	cout << "  >> Aimbot zaladowany...\n";
	GetPrivateProfileString("Triggerbot", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Triggerbot.Enabled = stoi(Setting);
	GetPrivateProfileString("Triggerbot", "Delay", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Triggerbot.Delay = stoi(Setting);
	cout << "  >> Triggerbot zaladowany...\n";
	GetPrivateProfileString("GlowESP", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Visuals.Glow.Enabled = stoi(Setting);
	GetPrivateProfileString("GlowESP", "Type", 0, Setting, sizeof(Setting) - 1, currentpath);
	Settings.Visuals.Glow.Type = stoi(Setting);
	cout << "  >> GlowESP zaladowany...\n";
	GetPrivateProfileString("Bunnyhop", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Bunnyhop.Enabled = stoi(Setting);
	GetPrivateProfileString("Bunnyhop", "Type", 0, Setting, sizeof(Setting) - 1, currentpath);
	Settings.Bunnyhop.Type = stoi(Setting);
	cout << "  >> Bunnyhop zaladowany...\n";
	GetPrivateProfileString("NoFlash", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Visuals.NoFlash.Enabled = stoi(Setting);
	GetPrivateProfileString("NoFlash", "Type", 0, Setting, sizeof(Setting) - 1, currentpath);
	Settings.Visuals.NoFlash.Type = stoi(Setting);
	cout << "  >> NoFlash zaladowany...\n";
	GetPrivateProfileString("Radarhack", "Enabled", "0", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Visuals.RadarHack.Enabled = stoi(Setting);
	cout << "  >> RadarHack zaladowany...\n";
	GetPrivateProfileString("Keys", "GlowESP", "112", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.Glow = stoi(Setting);
	GetPrivateProfileString("Keys", "Triggerbot", "113", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.Triggerbot = stoi(Setting);
	GetPrivateProfileString("Keys", "TriggerKey", "18", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.TriggerKey = stoi(Setting);
	GetPrivateProfileString("Keys", "Bunnyhop", "114", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.Bunnyhop = stoi(Setting);
	GetPrivateProfileString("Keys", "BunnyKey", "32", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.BunnyKey = stoi(Setting);
	GetPrivateProfileString("Keys", "NoFlash", "115", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.NoFlash = stoi(Setting);
	GetPrivateProfileString("Keys", "RadarHack", "117", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.RadarHack = stoi(Setting);
	GetPrivateProfileString("Keys", "Aimbot", "118", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.Aimbot = stoi(Setting);
	GetPrivateProfileString("Keys", "AimKey", "1", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.AimKey = stoi(Setting);
	GetPrivateProfileString("Keys", "RankReveal", "120", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.RankReveal = stoi(Setting);
	GetPrivateProfileString("Keys", "CFGKey", "119", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.CFGKey = stoi(Setting);
	GetPrivateProfileString("Keys", "ExitKey", "36", Setting, sizeof(Setting) - 1, currentpath);
	Settings.Keys.ExitKey = stoi(Setting);
	fileStream.close();
}

void CFGSaver::Print()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Aimbot Loaded
	cout << "Aimbot";
	if (Settings.Aimbot.Enabled == true) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << ">> FOV: " << dec << Settings.Aimbot.fov << " SMOOTH: " << Settings.Aimbot.smooth << "\n";
	}
	if (Settings.Aimbot.Enabled == false) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	//GlowESP Loaded
	cout << "Glow ESP";
	if (Settings.Visuals.Glow.Type == 4) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONE | Wrogowie (HP - spotted)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Visuals.Glow.Type == 3) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONE | Wrogowie (HP)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Visuals.Glow.Type == 2) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONE | Wrogowie (HP) - Sojusznicy (niebieski)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Visuals.Glow.Type == 1) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONE | Wrogowie (czerwony) - Sojusznicy (niebieski)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Visuals.Glow.Enabled == false) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONE\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}

	//Triggerbot Loaded
	cout << "Triggerbot";
	if (Settings.Triggerbot.Enabled == 1) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << ">> DELAY: " << dec << Settings.Triggerbot.Delay << endl;
	}
	if (Settings.Triggerbot.Enabled == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}

	//Bunnyhop Loaded
	cout << "Bunnyhop ";
	if (Settings.Bunnyhop.Type == 2) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY (Legit)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Bunnyhop.Type == 1) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY (Perfect)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Bunnyhop.Enabled == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}

	//NoFlash Loaded
	cout << "No Flash";
	if (Settings.Visuals.NoFlash.Type == 2) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY (Little Anti-Flash)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		wpm<float>(100, LocalPlayer::getLocalPlayer() + netvars::m_flFlashMaxAlpha);
	}
	if (Settings.Visuals.NoFlash.Type == 1) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY (No Flash)\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		wpm<float>(255, LocalPlayer::getLocalPlayer() + netvars::m_flFlashMaxAlpha);
	}
	if (Settings.Visuals.NoFlash.Enabled == 0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		wpm<float>(255, LocalPlayer::getLocalPlayer() + netvars::m_flFlashMaxAlpha);
	}


	//Radarhack Loaded
	cout << "Radar Hack";
	if (Settings.Visuals.RadarHack.Enabled == true) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << " WLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	if (Settings.Visuals.RadarHack.Enabled == false) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << " WYLACZONY\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		for (short int i = 0; i < 64; i++) {
			DWORD entity_r = rpm<DWORD>(baseAddress + signatures::dwEntityList + i * 0x10);
			if (entity_r != NULL) {
				wpm<bool>(false, entity_r + netvars::m_bSpotted);
			}
		}
	}

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\nHistoria:\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
