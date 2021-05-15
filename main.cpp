/*
	A hack for Assault Cube that removes all recoil when firing a weapon.
	
	This is done by modifying the game's code responsible for setting the player's recoil and changing the final instruction
	- which changes the value of the player's yaw - to instead pop a value that is ignored. As such, the player's yaw is
	never modified.

	This must be injected into the Wesnoth process to work. One way to do this is to use a DLL injector. 
	Another way is to enable AppInit_DLLs in the registry.
	
	The offsets and method to discover them are discussed in the article at: https://gamehacking.academy/lesson/36
*/
#include <Windows.h>

// The new opcodes to write into the game's code
unsigned char new_bytes[3] = { 0xDD, 0xD8, 0x90 };

// When our DLL is attached, first unprotect the memory responsible for adding recoil in the game
// Then, write our new opcodes into that memory location
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	DWORD old_protect;
	unsigned char* hook_location = (unsigned char*)0x45BAAD;

	if (fdwReason == DLL_PROCESS_ATTACH) {
		VirtualProtect((void*)hook_location, 3, PAGE_EXECUTE_READWRITE, &old_protect);
		for (int i = 0; i < sizeof(new_bytes); i++) {
			*(hook_location + i) = new_bytes[i];
		}
	}

	return true;
}
