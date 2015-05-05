#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "position.h"
#include "wallDetector.h"
#include "dropFunction.h"

void nextMove(void * pointer)
{
    int direction = RIGHT;

    bool quit = false;

    SDL_Thread *droppingEnemy;

    srand(time(NULL));

    direction = rand() % 2;

    SDL_Event e;

    // F�r att sp�kena inte ska r�ra p� sig f�r�n spelaren �r redo
    while( !quit){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        quit = true;
                        break;
                    case SDLK_DOWN:
                        quit = true;
                        break;
                    case SDLK_LEFT:
                        quit = true;
                        break;
                    case SDLK_RIGHT:
                        quit = true;
                        break;
                }
            }
        }
    }

    droppingEnemy = SDL_CreateThread(enemyDrop, "EnemyDrop", (void *)NULL); // drop detect

    while(1)
    {
        if(collisions(ghost_rect) == true)
        {
            if(direction == RIGHT)
            {
                direction = LEFT;
                ghost_rect.x = ghost_rect.x + 4;
            }
            else
            {
                direction = RIGHT;
                ghost_rect.x = ghost_rect.x - 4;
            }
        }
        else
        {
            if(direction == RIGHT)
            {
                ghost_rect.x = ghost_rect.x - 4;    // lista ut senare hur mycket
            }
            else if(direction == LEFT)
            {
                ghost_rect.x = ghost_rect.x + 4;    // lista ut senare hur mycket
            }
        }

        SDL_Delay(100);       // f�r att se till s� att funktionen inte k�rs hela tiden (sparar skickningar mellan server och client)
    }
}
