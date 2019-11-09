#include "Glow.h"

CheatGlowESP CheatGlow;

DWORD glowObject;

struct GlowStruct
{
	BYTE base[4];
	float red;
	float green;
	float blue;
	float alpha;
	BYTE buffer[16];
	bool renderWhenOccluded;
	bool renderWhenUnOccluded;
	bool fullBloom;
	BYTE buffer2[5];
	int glowStyle;
} Glow;

GlowStruct SetGlowColor(GlowStruct Glow, DWORD entity_g) {

	bool defusing = rpm<bool>(entity_g + netvars::m_bIsDefusing);
	if (defusing == true)
	{
		Glow.red = 1.0f;
		Glow.green = 1.0f;
		Glow.blue = 1.0f;
		Glow.alpha = 1.0f;
	}
	else if (Settings.Visuals.Glow.Type == 1) {
		Glow.red = 1.0f;
		Glow.green = 0.0f;
		Glow.blue = 0.0f;
		Glow.alpha = 0.7f;
	}
	else
	{
		int health = rpm<int>(entity_g + netvars::m_iHealth);
		Glow.red = health * -0.01 + 1;
		Glow.green = health * 0.01;
		Glow.alpha = 0.7f;
	}
	Glow.renderWhenOccluded = true;
	Glow.renderWhenUnOccluded = false;
	return Glow;
}

void setTeamGlow(DWORD entity_g, int glowIndex)
{
	if (Settings.Visuals.Glow.Type == 1 || Settings.Visuals.Glow.Type == 2) {
		GlowStruct TGlow;
		TGlow = rpm<GlowStruct>(glowObject + (glowIndex * 0x38));

		TGlow.blue = 1.0f;
		TGlow.alpha = 0.7f;
		TGlow.renderWhenOccluded = true;
		TGlow.renderWhenUnOccluded = false;
		wpm<GlowStruct>(TGlow, (glowObject + (glowIndex * 0x38)));
	}
	
}

void setEnemyGlow(DWORD entity_g, int glowIndex)
{
	GlowStruct EGlow;
	EGlow = rpm<GlowStruct>(glowObject + (glowIndex * 0x38));
	//int health = MemClass.readMem<int>(entity_g + offsets.m_iHealth);
	EGlow = SetGlowColor(EGlow, entity_g);
	wpm<GlowStruct>(EGlow, (glowObject + (glowIndex * 0x38)));
}

void handleGlow()
{
	glowObject = rpm<DWORD>(baseAddress + signatures::dwGlowObjectManager);

	int playerTeam_g = rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_iTeamNum);
	for (short int i = 0; i < 64; i++) {

		DWORD entity_g = rpm<DWORD>(baseAddress + signatures::dwEntityList + i * 0x10);
		if (entity_g != NULL) {

			int glowIndex = rpm<int>(entity_g + netvars::m_iGlowIndex);
			int entityTeam_g = rpm<int>(entity_g + netvars::m_iTeamNum);

			if (playerTeam_g != entityTeam_g) {
				setEnemyGlow(entity_g, glowIndex);
			}
			else {
				setTeamGlow(entity_g, glowIndex);
			}
			wpm<bool>(true, (glowObject + ((glowIndex * 0x38) + 0x24)));
			wpm<bool>(false, (glowObject + ((glowIndex * 0x38) + 0x25)));
		}

	}

}

void handleGlowSpotted()
{
	DWORD glowObject = rpm<DWORD>(baseAddress + signatures::dwGlowObjectManager);
	int playerTeam_g = rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_iTeamNum);
	for (short int i = 0; i < 64; i++) {

		DWORD entity_g = rpm<DWORD>(baseAddress + signatures::dwEntityList + i * 0x10);
		bool spotted_g = rpm<bool>(entity_g + netvars::m_bSpotted);
		if (entity_g != NULL) {

			int glowIndex = rpm<int>(entity_g + netvars::m_iGlowIndex);
			int entityTeam_g = rpm<int>(entity_g + netvars::m_iTeamNum);

			if (playerTeam_g != entityTeam_g) {
				if (spotted_g == true) {
					setEnemyGlow(entity_g, glowIndex);
				}
			}
			else {
				setTeamGlow(entity_g, glowIndex);
			}
			wpm<bool>(true, (glowObject + ((glowIndex * 0x38) + 0x24)));
			wpm<bool>(false, (glowObject + ((glowIndex * 0x38) + 0x25)));
		}
	}

}

void CheatGlowESP::GlowESP()
{
	if (Settings.Visuals.Glow.Type > 0 && Settings.Visuals.Glow.Type < 4) {
		handleGlow();
	}
	if (Settings.Visuals.Glow.Type == 4) {
		handleGlowSpotted();
	}
}
