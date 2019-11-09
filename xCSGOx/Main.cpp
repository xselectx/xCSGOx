#include "Includes.h"
#include "Cheats.h"
#include "Settings.h"
#include "CFG.h"
using namespace std;


struct VectorVelocity {
	float x, y, z;
};


int main()
{

	init();
	if (baseAddress == NULL) {
		system("pause");
		return 1;
	}
	LocalPlayer::setLocalPlayer();
	if (LocalPlayer::getLocalPlayer() == NULL) {
		while (LocalPlayer::getLocalPlayer() == NULL) {
			LocalPlayer::setLocalPlayer();
		}
	}

	if (LocalPlayer::getLocalPlayer() != NULL) {
		cout << ">> Znaleziono gracza" << endl;
	}

	fstream fileStream;
	
	CFG.Find();


	Sleep(1500);
	system("cls");
	DrawMenu.DrawMenu();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CFG.Print();

	while (!GetAsyncKeyState(Settings.Keys.ExitKey))
	{
		//Settings ON/OFF
		
		//Glow ESP
		if (GetAsyncKeyState(Settings.Keys.Glow) & 1) {
			if (Settings.Visuals.Glow.Enabled == false) {
				Settings.Visuals.Glow.Enabled = true;
			}

			Settings.Visuals.Glow.Type++;

			if (Settings.Visuals.Glow.Type > 4) {
				Settings.Visuals.Glow.Type = 0;
				Settings.Visuals.Glow.Enabled = false;
			}
			LocalPlayer::setLocalPlayer();
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
		}

		//Triggerbot
		if (GetAsyncKeyState(Settings.Keys.Triggerbot) & 1) {
			Settings.Triggerbot.Enabled = !Settings.Triggerbot.Enabled;
			LocalPlayer::setLocalPlayer();
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
		}

		//Bunnyhop
		if (GetAsyncKeyState(Settings.Keys.Bunnyhop) & 1) {
			if (Settings.Bunnyhop.Enabled == false) {
				Settings.Bunnyhop.Enabled = true;
			}

			Settings.Bunnyhop.Type++;

			if (Settings.Bunnyhop.Type > 2) {
				Settings.Bunnyhop.Type = 0;
				Settings.Bunnyhop.Enabled = false;
			}
			LocalPlayer::setLocalPlayer();
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
		}

		//Radarhack
		if (GetAsyncKeyState(Settings.Keys.RadarHack) & 1) {
			Settings.Visuals.RadarHack.Enabled = !Settings.Visuals.RadarHack.Enabled;
			LocalPlayer::setLocalPlayer();
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
		}

		//Aimbot
		if (GetAsyncKeyState(Settings.Keys.Aimbot) & 1) {
			Settings.Aimbot.Enabled = !Settings.Aimbot.Enabled;
			LocalPlayer::setLocalPlayer();
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
		}




		//NoFlash
		if (GetAsyncKeyState(Settings.Keys.NoFlash) & 1) {
			if (Settings.Visuals.NoFlash.Enabled == false) {
				Settings.Visuals.NoFlash.Enabled = true;
			}

			Settings.Visuals.NoFlash.Type++;

			if (Settings.Visuals.NoFlash.Type > 2) {
				Settings.Visuals.NoFlash.Type = 0;
				Settings.Visuals.NoFlash.Enabled = false;
			}
			LocalPlayer::setLocalPlayer();
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
		}

		if (GetAsyncKeyState(Settings.Keys.CFGKey) & 1) {
			int sel = 0;
			while (sel != 1 && sel != 2) {
				cout << "\nCONFIG:\n";
				cout << "1 - Zapisz\n";
				cout << "2 - Odswiez\n";
				cout << "Wybierz: ";
				cin >> sel;
				if (sel == 1) {
					cout << ">> Zapisywanie...\n";
					CFG.Save();
					cout << ">> Zapisano\n";
				}
				else if (sel == 2) {
					cout << ">> Odswiezanie...\n";
					Sleep(100);
					CFG.Find();
					system("cls");
					DrawMenu.DrawMenu();
					CFG.Print();
				}
			}

		}

		//Cheats
		if (Settings.Visuals.Glow.Enabled == true) {
			CheatGlow.GlowESP();
		}
		if (Settings.Bunnyhop.Enabled == true) {
			CheatBunnyHop.Bunnyhop();
		}
		if (Settings.Triggerbot.Enabled == true) {
			CheatTrigger.Triggerbot();
		}
		if (Settings.Visuals.RadarHack.Enabled == true) {
			CheatRadar.RadarHack();
		}
		if (Settings.Visuals.NoFlash.Enabled == true) {
			CheatNoFlash.NoFlash();
		}
		if (Settings.Aimbot.Enabled == true) {
			CheatAim.Aimbot(CheatAim.findPlayer());
		}
		if (GetAsyncKeyState(Settings.Keys.RankReveal) & 1) {
			CheatRank.RankReveal();
		}
		Sleep(1);
	}

	CloseHandle(hProc);
}