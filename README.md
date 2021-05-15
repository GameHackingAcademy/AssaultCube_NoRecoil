# AssaultCube No Recoil
A hack for Assault Cube that removes all recoil when firing a weapon.
	
This is done by modifying the game's code responsible for setting the player's recoil and changing the final instruction - which changes the value of the player's yaw - to instead pop a value that is ignored. As such, the player's yaw is never modified.
	
This must be injected into the Wesnoth process to work. One way to do this is to use a DLL injector. Another way is to enable AppInit_DLLs in the registry.
	
The offsets and method to discover them are discussed in the article at: https://gamehacking.academy/lesson/36
