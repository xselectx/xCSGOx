#include "Aimbot.h"



CheatAimbot CheatAim;


struct Vec3 {
	float x, y, z;
};

class BoneMatrix
{
public:
	static Vec3 GetBonePos(int boneBase, int boneID)
	{
		Vec3 bonePos;
		bonePos.x = *(float*)((boneBase + 0x30 * boneID + 0x0C));
		bonePos.y = *(float*)((boneBase + 0x30 * boneID + 0x1C));
		bonePos.z = *(float*)((boneBase + 0x30 * boneID + 0x2C));
		return bonePos;
	}
};



DWORD CheatAimbot::findPlayer() {
	D3DXVECTOR3 EntBone;

	DWORD playerToAim;
	double lowestDist = Settings.Aimbot.fov;
	
	for (int i = 1; i < 32; i++) {

		auto base = Entity::getEntBase(i);
		if (Entity::getEntTeam(base) != LocalPlayer::getLocalTeam() && Entity::isValid(base) && !Entity::getEntImmunity(base)) {
			
			int BoneBase = *(uintptr_t*)((baseAddress + netvars::m_dwBoneMatrix));
			WorldToScreen(Entity::getEntBonePos(base, 8), EntBone, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)); // DO POPRAWY!!! <---

			double dist = sqrt(pow((GetSystemMetrics(SM_CXSCREEN) / 2) - EntBone.x, 2) + pow((GetSystemMetrics(SM_CYSCREEN) / 2) - EntBone.y, 2));
			if (dist < lowestDist) {
				lowestDist = dist;
				playerToAim = base;
			}
		}
	}

	return playerToAim;
}

D3DXVECTOR3 NormalizeAngle(D3DXVECTOR3 angles)
{
	if (angles.x > 89)
	{
		 angles.x = 89;
	}
	else if (-89 > angles.x)
	{
		 angles.x = -89;
	}

	if (angles.y > 180)
	{
		angles.y -= 360;
	}
	else if (-180 > angles.y)
	{
		 angles.y += 360;
	}

	angles.z = 0;

	return angles;
}

//!rpm<bool>(base + signatures::m_bDormant)
void CheatAimbot::Aimbot(DWORD playerToAim) {
	if (playerToAim != NULL) {
		if (Entity::getSpotted(playerToAim) == 1 && GetAsyncKeyState(Settings.Keys.AimKey)) {

			D3DXVECTOR3 aimAngles = CalcAngle(LocalPlayer::getLocalPos(), Entity::getEntPos(playerToAim));

			aimAngles -= LocalPlayer::getLocalPunchAngles() * 2.0;

			auto currentAngles = LocalPlayer::getLocalViewAngles();

			auto delta = NormalizeAngle(aimAngles) - NormalizeAngle(currentAngles);

			LocalPlayer::setLocalViewAngles(NormalizeAngle(currentAngles) + delta / Settings.Aimbot.smooth);
			

		}
	}
}