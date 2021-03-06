
#include <SDL2/SDL.h>
#include <stdlib.h>

#include "engine.h"

/*
 * see ENGINE.md
 * see TODO.md
 */

int main(int argc, char **argv)
{
    Engine_Start(argc, argv);

    // Entering main loop.
    Engine_MainLoop();

    // Main loop interrupted; shutting down.
    Engine_Shutdown(EXIT_SUCCESS);
    return(EXIT_SUCCESS);
}
