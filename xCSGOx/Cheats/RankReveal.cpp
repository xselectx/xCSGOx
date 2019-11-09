#include "RankReveal.h"

//TODO: Fix / Wyœwietlanie nicku

CheatRankReveal CheatRank;

using namespace std;

const char* CompRanksStr[19] =
{
		"Unranked",
		"Silver I",
		"Silver II",
		"Silver III",
		"Silver IV",
		"Silver Elite",
		"Silver Elite Master",
		"Gold Nova I",
		"Gold Nova II",
		"Gold Nova III",
		"Gold Nova Master",
		"Master Guardian I",
		"Master Guardian II",
		"Master Guardian Elite",
		"Distinguished Master Guardian",
		"Legendary Eagle",
		"Legendary Eagle Master",
		"Supreme Master First Class",
		"The Global Elite"
};

void CheatRankReveal::RankReveal() {
	system("cls");
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "RANK REVEAL - NIE POKAZUJE NAZWY\n";
	for (short int i = 0; i < 64; i++) {
		DWORD PlayerResource = rpm<DWORD>(baseAddress + signatures::dwPlayerResource);
		int CompRanks = rpm<int>(PlayerResource + netvars::m_iCompetitiveRanking + i * 4);
		int CompWins = rpm<int>(PlayerResource + netvars::m_iCompetitiveWins + i * 4);
		if (CompWins > 0) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "------------------\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Name: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "---" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Wins: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << CompWins << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Rank: ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << CompRanksStr[CompRanks] << endl;
		}
		else {
			i = 64;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "Nie znaleziono gracza z jakakolwiek iloscia wygranych meczy!\n";
		}

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		system("pause");
		system("cls");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		DrawMenu.DrawMenu();
		CFG.Print();
	}
}