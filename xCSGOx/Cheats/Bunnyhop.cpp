#include "Bunnyhop.h"
CheatBunnyhop CheatBunnyHop;

struct VectorVelocity {
	float x, y, z;
};


void CheatBunnyhop::Bunnyhop()
{
	
	VectorVelocity velocity;
	velocity = rpm<VectorVelocity>(LocalPlayer::getLocalPlayer() + netvars::m_vecVelocity);

	srand(time(NULL));
	if (GetAsyncKeyState(Settings.Keys.BunnyKey) && LocalPlayer::getLocalFlags() & (1 << 0)) {
		if (velocity.x != 0 && velocity.y != 0 && velocity.z >= 0) {
			if (Settings.Bunnyhop.Type == 2) {
				Sleep((rand() % 10));
			}
			LocalPlayer::forceJump();
		}
	}
}