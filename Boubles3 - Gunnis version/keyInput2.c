#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput2.h"
#include "collisionHandler.h"
#include "shoot.h"

void keyInput2()
{
    bool quit = false;
    bool lookDirection = RIGHT;

    SDL_Event e;

    SDL_Thread *bubble_thread;

    //While application is running
    while(!quit)
    {
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
                    {
                        jump();
                        break;
                    }
                    case SDLK_SPACE:
                    {
                        if (lookDirection == RIGHT)
                            bubble_thread = SDL_CreateThread(shootFuncRight, "clientConnection", (void *)NULL);
                        else if (lookDirection == LEFT)
                            bubble_thread = SDL_CreateThread(shootFunc, "clientConnection", (void *)NULL);
                        break;
                    }
                    case SDLK_LEFT:
                    {
                        character_rect.x -= 4;
                        SDL_Delay(30);
                        if(collisions(character_rect))
                        {
                            character_rect.x += 4;
                        }
                        flip = SDL_FLIP_NONE;
                        if(frame == 2)
                            frame = 1;
                        else if(frame == 1)
                            frame = 0;
                        else if (frame == 0)
                            frame = 3;
                        else
                            frame = 2;
                        //printf("Position: (%d,%d)\n", character_rect.x, character_rect.y);
                        lookDirection = LEFT;

                        break;
                    }
                    case SDLK_RIGHT:
                    {
                        character_rect.x += 4;
                        SDL_Delay(30);
                        if(collisions(character_rect))
                        {
                            character_rect.x -= 4;
                        }
                        flip = SDL_FLIP_HORIZONTAL;
                        if(frame == 2)
                            frame = 1;
                        else if (frame == 1)
                            frame = 0;
                        else if (frame == 0)
                            frame = 3;
                        else
                            frame = 2;
                        //printf("Position: (%d,%d)\n", character_rect.x, character_rect.y);
                        lookDirection = RIGHT;

                        break;
                    }
                }
            }
        }

    }
}
