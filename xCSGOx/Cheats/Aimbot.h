#pragma once

#include "..\Includes.h"
#include "..\Defines.h"
#include "..\Settings.h"
#include <vector>
#include <Math.h>

class CheatAimbot {
public:
	DWORD findPlayer();
	void Aimbot(DWORD playerToAim);
};

extern CheatAimbot CheatAim;