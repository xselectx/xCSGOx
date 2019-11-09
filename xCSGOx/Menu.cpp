#include "Menu.h"
#include "InvertKeys.h"

using namespace std;

Menu DrawMenu;

void Menu::DrawMenu() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "xCSGOx\n";
	cout << "by xSeLeCTx\n";
	cout << "Wersja 2.0.1\n";
	cout << "[07.11.2019]\n\n";

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.Glow) <<"] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Glow ESP";
	cout << "\t   x1 - Wszyscy (team) | x2 - Wszyscy (hp) | 3x - Wrogowie (hp) | 4x - Wrogowie (hp spotted)\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.Triggerbot) <<"] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Triggerbot - ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.TriggerKey) << "]";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.Bunnyhop) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Bunnyhop - ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.BunnyKey) << "]";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "   x1 - Perfect  | x2 - Legit\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.NoFlash) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- No Flash";
	cout << "\t   x1 - No Flash | x2 - Little Anti-Flash\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.RadarHack) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Radar Hack";
	cout << "\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.Aimbot) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Aimbot - ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.AimKey) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.CFGKey) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Config\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.RankReveal) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Rank Reveal - Nie dziala(?) \n\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "[" << IK.Invert(Settings.Keys.ExitKey) << "] ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "- Exit\n\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Opcje:\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

}

