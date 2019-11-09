#pragma once
#include "Includes.h"

class _InvertKeys {
public:
	const char* Invert(int key);
	const char* InvertSave(int key);
};

extern _InvertKeys IK;