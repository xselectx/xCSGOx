#pragma  once
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>
#include "Offsets.hpp"

//Vars to use
extern DWORD baseAddress;
extern DWORD engineAddress;
extern DWORD clientState;

//Vars for process snapshot
extern HANDLE hProcSnap;
extern PROCESSENTRY32 procEntry32;

//Vars for module snapshot
extern HANDLE hModuleSnap;
extern MODULEENTRY32 modEntry32;

//Process ID of attached proc
extern DWORD pID;

//Handle to process
extern HANDLE hProc;

//WPM wrapper - Lets us call WriteProcessMemory MUCH more easily (with less args)
template <class dataType>
void wpm(dataType valToWrite, DWORD addressToWrite)
{
	WriteProcessMemory(hProc, (PVOID)addressToWrite, &valToWrite, sizeof(dataType), 0);
}

//RPM wrapper - Lets us call ReadProcessMemory MUCH more easily (with less args)
template <class dataType>
dataType rpm(DWORD addressToRead)
{
	//Stores the value of the address being read
	dataType rpmBuffer;

	//RPM
	ReadProcessMemory(hProc, (PVOID)addressToRead, &rpmBuffer, sizeof(dataType), 0);

	//Return the value that was read
	return rpmBuffer;
}

//Attaches to process and gives ALL_ACCESS so you can rpm/wpm for your hack
extern bool attatchProc(char* procName);

//Gets the base address of a desired module within the process you've attached to, so you can offset from it
extern DWORD getModule(char* moduleName);

extern uintptr_t patternScan(char* base, size_t size, char* pattern);

extern void init();

extern std::uint32_t find(const char* proc);