#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput.h"



void keyInput()
{
    bool quit = false;

    SDL_Event e;

    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if(e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                    /*case SDLK_UP:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    break;

                    case SDLK_DOWN:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    break;*/

                    case SDLK_LEFT:
                    SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    break;

                    case SDLK_RIGHT:
                    SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    break;

                    default:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(gWindow);
                    break;
                }
            }
        }
    }
}
