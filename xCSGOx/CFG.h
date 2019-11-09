#pragma once

#include "Includes.h"
#include "Settings.h"
#include <fstream>
#include <string>

class CFGSaver {
public:
	void Find();
	void Create();
	void Save();
	void Load();
	void Print();
};

extern CFGSaver CFG;
