#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput2.h"

void keyInput2()
{
    bool quit = false;
    bool lookDirection = RIGHT;

    SDL_Event e;
    SDL_Renderer* gRenderer = NULL;

    SDL_Rect character;
    character.x = 640/2;
    character.y = 480/2;
    character.w = 50;
    character.h = 50;

    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];

    //Apply the image
    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, &character );
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );

    //While application is running
    while( !quit){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                printf( "QUIT!\n" );
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        character.y -= 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        break;
                    case SDLK_DOWN:
                        character.y += 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        break;
                    case SDLK_LEFT:
                        character.x -= 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        lookDirection = LEFT;
                        break;
                    case SDLK_RIGHT:
                        character.x += 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        lookDirection = RIGHT;
                        break;
                }
                SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
                if(lookDirection == LEFT)
                {
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, &character);
                }
                else if((lookDirection == RIGHT))
                {
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, &character);
                }
                SDL_UpdateWindowSurface(gWindow);
            }

        }
    }
}
