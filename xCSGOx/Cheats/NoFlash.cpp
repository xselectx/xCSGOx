#include "NoFlash.h"

CheatNoFlashBang CheatNoFlash;


void CheatNoFlashBang::NoFlash()
{
	if (Settings.Visuals.NoFlash.Type == 1) {
		int flashDuration = rpm<float>(LocalPlayer::getLocalPlayer() + netvars::m_flFlashDuration);
		if (flashDuration > 0) {
			wpm<int>(0, LocalPlayer::getLocalPlayer() + netvars::m_flFlashDuration);
		}
	}
}