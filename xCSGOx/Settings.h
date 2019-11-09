#pragma once
#include "Includes.h"

class CheatSettings {
public:
	struct {
		struct {
			bool Enabled = false;
			int Type = 0;
		} Glow;

		struct {
			bool Enabled = false;
			int Type = 0;
		} NoFlash;

		struct {
			bool Enabled = false;
		} RadarHack;
	} Visuals;

	struct {
		bool Enabled = false;
		int fov = 20;
		int smooth = 30;
	} Aimbot;

	struct {
		bool Enabled = false;
		int Type = 0;
	} Bunnyhop;

	struct {
		bool Enabled = false;
		int Delay = 0;
	} Triggerbot;

	struct {
		int Glow = VK_F1;
		int Triggerbot = VK_F2;
		int TriggerKey= VK_MENU;
		int Bunnyhop = VK_F3;
		int BunnyKey = VK_SPACE;
		int NoFlash = VK_F4;
		int RadarHack = VK_F6;
		int Aimbot = VK_F7;
		int AimKey = VK_LBUTTON;
		int RankReveal = VK_F9;
		int CFGKey = VK_F8;
		int ExitKey = VK_HOME;
	} Keys;
};

extern CheatSettings Settings;