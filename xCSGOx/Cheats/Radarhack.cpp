#include "Radarhack.h"


CheatRadarHack CheatRadar;

void CheatRadarHack::RadarHack()
{
	if (Settings.Visuals.RadarHack.Enabled == true) {
		for (short int i = 0; i < 64; i++) {
			DWORD entity_r = rpm<DWORD>(baseAddress + signatures::dwEntityList + i * 0x10);
			if (entity_r != NULL) {
				wpm<bool>(true, entity_r + netvars::m_bSpotted);
			}
		}
	}
}