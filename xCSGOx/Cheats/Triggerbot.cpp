#include "Triggerbot.h"



CheatTriggerbot CheatTrigger;

int triggerDelay = 0;
int playerWeaponID = 0;
int playerTeam = 0;
int localPlayer = 0;

bool isScoped()
{
	return rpm<bool>(localPlayer + netvars::m_bIsScoped);
}


void setTriggerDelay(float distance) {
	float delay;
	switch (playerWeaponID) {
	case 262204: delay = 3; break; // M4A1-S
	case 7: delay = 3.3; break; // AK-47
	case 40: delay = 0.15; break; // SSG-08
	case 9: delay = 0.15; break; // AWP
	default: delay = 0; // OTHER / NOT LISTED
	}
	triggerDelay = delay * distance;
}

void getPlayerWeapon()
{
	playerWeaponID = LocalPlayer::getPlayerWeapon();
}


struct _vector {
	float x, y, z;
};

float getDistance(DWORD entity)
{
	D3DXVECTOR3 playerLocation = LocalPlayer::getLocalPos();
	D3DXVECTOR3 enemyLocation = Entity::getEntPos(entity);

	return sqrt(pow(playerLocation.x - enemyLocation.x, 2) + pow(playerLocation.y - enemyLocation.y, 2) + pow(playerLocation.z - enemyLocation.z, 2)) * 0.0254;
}

void shoot() {
	Sleep(triggerDelay + Settings.Triggerbot.Delay);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

bool checkTrigger() {
	int crosshair = rpm<int>(localPlayer + netvars::m_iCrosshairId);
	if (crosshair != 0 && crosshair < 64) {
		DWORD entity = Entity::getEntBase(crosshair - 1);

		auto eTeam = Entity::getEntTeam(entity);
		auto eHealth = Entity::getEntHp(entity);

		if (eTeam != LocalPlayer::getLocalTeam() && eHealth > 0 && !Entity::getEntImmunity(entity)) {
			float distance = getDistance(entity);
			getPlayerWeapon();
			setTriggerDelay(distance);
			if (playerWeaponID == 40 || playerWeaponID == 9) {
				return isScoped();
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

void handleTrigger() {
	if (checkTrigger()) {
		shoot();
	}
}


void CheatTriggerbot::Triggerbot() {
	bool keyHeld = false , canTrigger = false;
	if (GetAsyncKeyState(Settings.Keys.TriggerKey) == KeyDOWN && !keyHeld) {
		playerTeam = LocalPlayer::getLocalTeam();
		localPlayer = LocalPlayer::getLocalPlayer();
		keyHeld = true;
		canTrigger = true;
	}
	if (GetAsyncKeyState(Settings.Keys.TriggerKey) == KeyUP && keyHeld) {
		keyHeld = false;
		canTrigger = false;
	}
	if (canTrigger) {
		handleTrigger();
	}
}
