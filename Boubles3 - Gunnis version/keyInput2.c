#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput2.h"
#include "collisionHandler.h"
#include "shoot.h"

// If it's allowed to shoot
bool shootFlag;

void keyInput2()
{
    bool quit = false;
    bool lookDirection = RIGHT;
    shootFlag = true;

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
                        soundJump();
                        jump();
                        break;
                    }
                    case SDLK_SPACE:
                    {
                        if (lookDirection == RIGHT && shootFlag == true)
                            bubble_thread = SDL_CreateThread(shootFuncRight, "clientConnection", (void *)NULL);
                        else if (lookDirection == LEFT && shootFlag == true)
                            bubble_thread = SDL_CreateThread(shootFunc, "clientConnection", (void *)NULL);
                        break;
                    }
                    // Länk till var vi fick den här gåanimationen från
                    case SDLK_LEFT:
                    {
                        gameVariables.character_rect.x -= 4;
                        SDL_Delay(30);
                        if(collisions(gameVariables.character_rect))
                        {
                            gameVariables.character_rect.x += 4;
                        }
                        gameVariables.character_flip = SDL_FLIP_NONE;
                        if(gameVariables.frame == 2)
                            gameVariables.frame = 1;
                        else if(gameVariables.frame == 1)
                            gameVariables.frame = 0;
                        else if (gameVariables.frame == 0)
                            gameVariables.frame = 3;
                        else
                            gameVariables.frame = 2;
                        lookDirection = LEFT;

                        break;
                    }
                    // Länk till var vi fick den här gåanimationen från
                    case SDLK_RIGHT:
                    {
                        gameVariables.character_rect.x += 4;
                        SDL_Delay(30);
                        if(collisions(gameVariables.character_rect))
                        {
                            gameVariables.character_rect.x -= 4;
                        }
                        gameVariables.character_flip = SDL_FLIP_HORIZONTAL;
                        if(gameVariables.frame == 2)
                            gameVariables.frame = 1;
                        else if (gameVariables.frame == 1)
                            gameVariables.frame = 0;
                        else if (gameVariables.frame == 0)
                            gameVariables.frame = 3;
                        else
                            gameVariables.frame = 2;
                        //printf("Position: (%d,%d)\n", character_rect.x, character_rect.y);
                        lookDirection = RIGHT;

                        break;
                    }
                }
            }
        }

    }
}
