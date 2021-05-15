#include <Windows.h>

// The new opcodes to write into the game's code
unsigned char new_bytes[3] = { 0xDD, 0xD8, 0x90 };

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
