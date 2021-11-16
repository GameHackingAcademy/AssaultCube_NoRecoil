# Assault Cube No Recoil
Referenced in https://gamehacking.academy/lesson/5/7.

A hack for Assault Cube 1.2.0.2 that removes all recoil when firing a weapon.

This is done by modifying the game's code responsible for setting the player's recoil. By changing the final instruction, which changes the value of the player's yaw, to instead pop a value that is ignored, the player's yaw is never modified.

This must be injected into the Assault Cube process to work. One way to do this is to use a DLL injector. Another way is to enable AppInit_DLLs in the registry.
