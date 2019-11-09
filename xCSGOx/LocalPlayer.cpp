#include "includes.h"

DWORD LocalPlayer::LocalBaseaddress = 0;

DWORD LocalPlayer::getLocalPlayer()
{
	return LocalPlayer::LocalBaseaddress;
}

void LocalPlayer::setLocalPlayer()
{
	LocalPlayer::LocalBaseaddress = rpm<DWORD>(baseAddress + signatures::dwLocalPlayer);
}

int LocalPlayer::getLocalFlags()
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_fFlags);
}

int LocalPlayer::getLocalHealth()
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_iHealth);
}

int LocalPlayer::getLocalTeam()
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_iTeamNum);
}

int LocalPlayer::getLocalWeapon()
{
	return rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_hActiveWeapon);
}

int LocalPlayer::getLocalWeaponEntity() {
	return rpm<int>(baseAddress + signatures::dwEntityList + ((LocalPlayer::getLocalWeapon() & 0xFFF) - 1) * 0x10);
}

int LocalPlayer::getPlayerWeapon() {
	int weapon = LocalPlayer::getLocalWeapon();
	int weaponEntity = LocalPlayer::getLocalWeaponEntity();
	if (weaponEntity != NULL) {
		return rpm<int>(getLocalWeaponEntity() + netvars::m_iItemDefinitionIndex);
	}
}

void LocalPlayer::forceJump(int waitTime)
{
	wpm<int>(1, baseAddress + signatures::dwForceJump);
	Sleep(waitTime);
	wpm<int>(0, baseAddress + signatures::dwForceJump);
}

int LocalPlayer::getLocalCrossID()
{
	auto temp = rpm<int>(LocalPlayer::getLocalPlayer() + netvars::m_iCrosshairId);
	if (temp <= 0 || temp > 32)
		return -1;
	return temp;
}

D3DXVECTOR3 LocalPlayer::getLocalPos()
{
	return rpm<D3DXVECTOR3>(LocalPlayer::getLocalPlayer() + netvars::m_vecOrigin);
}

D3DXMATRIX	LocalPlayer::getLocalViewMatrix()
{
	return rpm<D3DXMATRIX>(baseAddress + signatures::dwViewMatrix);
}

D3DXVECTOR3 LocalPlayer::getLocalViewAngles()
{
	return rpm<D3DXVECTOR3>(clientState + signatures::dwClientState_ViewAngles);
}

void LocalPlayer::setLocalViewAngles(D3DXVECTOR3 angles)
{
	wpm<D3DXVECTOR3>(angles, clientState + signatures::dwClientState_ViewAngles);
}

D3DXVECTOR3 LocalPlayer::getLocalPunchAngles()
{
	return rpm<D3DXVECTOR3>(LocalPlayer::getLocalPlayer() + netvars::m_aimPunchAngle);
}