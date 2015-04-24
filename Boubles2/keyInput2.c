#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput2.h"

void keyInput2()
{
    bool quit = false;

    SDL_Event e;
    SDL_Surface* gXOut = NULL;
    SDL_Renderer* gRenderer = NULL;

    SDL_Rect dstrect;
    dstrect.x = 640/2;
    dstrect.y = 480/2;
    dstrect.w = 100;
    dstrect.h = 100;

    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];

    //Apply the image
    SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, &dstrect );
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
                        dstrect.y -= 2;
                        break;
                    case SDLK_DOWN:
                        dstrect.y += 2;
                        break;
                    case SDLK_LEFT:
                        dstrect.x -= 2;
                        break;
                    case SDLK_RIGHT:
                        dstrect.x += 2;
                        break;
                }
                SDL_FillRect(gScreenSurface, NULL, 0x000000);
                SDL_Rect fillRect = { 100, 100, 20, 60 };
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect(gRenderer, &fillRect);
                SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, &dstrect);
                SDL_UpdateWindowSurface( gWindow );
            }

        }
    }
}
