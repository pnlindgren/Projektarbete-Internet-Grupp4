#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput.h"
#include "collisionHandler.h"
#include "shoot.h"

// If it's allowed to shoot
bool shootFlag;

void keyInput(int positionStart)
{
    bool quit = false;
    bool lookDirection;

    // baserat på vilken position krokodilen är på
    if(positionStart == 1)
    {
        lookDirection = LEFT;
    }
    else if(positionStart == 0)
    {
        lookDirection = RIGHT;
    }

    shootFlag = true;

    SDL_Event keyInputEvent;

    SDL_Thread *bubble_thread;

    while(!quit)
    {
        // Kollar om ett event kallats
        while( SDL_PollEvent( &keyInputEvent ) != 0 )
        {
            // Stoppar loopen om användaren stängt ner spelet (röda krysset)
            if( keyInputEvent.type == SDL_QUIT )
            {
                quit = true;
                gameVariables.end_game = true;
            }
            // kollar om en knapp har blivit tryckt
            else if( keyInputEvent.type == SDL_KEYDOWN )
            {
                SDL_Delay(5);

                // Kollar vilken knapp som har blivit tryckt
                switch( keyInputEvent.key.keysym.sym )
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
                        {
                            shootFlag = false;
                            bubble_thread = SDL_CreateThread(shootFuncRight, "clientConnection", (void *)NULL);
                        }
                        else if (lookDirection == LEFT && shootFlag == true)
                        {
                            shootFlag = false;
                            bubble_thread = SDL_CreateThread(shootFunc, "clientConnection", (void *)NULL);
                        }
                        break;
                    }
                    // Baserat på Jonas spaceman (F4.c)
                    case SDLK_LEFT:
                    {
                        gameVariables.character_rect.x -= 4;
                        SDL_Delay(30);
                        if(collisions(gameVariables.character_rect))
                        {
                            gameVariables.character_rect.x += 4;
                        }
                        gameVariables.character_flip = SDL_FLIP_NONE;
                        if(gameVariables.character_frame == 2)
                            gameVariables.character_frame = 1;
                        else if(gameVariables.character_frame == 1)
                            gameVariables.character_frame = 0;
                        else if (gameVariables.character_frame == 0)
                            gameVariables.character_frame = 3;
                        else
                            gameVariables.character_frame = 2;
                        lookDirection = LEFT;

                        break;
                    }
                    // Baserat på Jonas spaceman (F4.c)
                    case SDLK_RIGHT:
                    {
                        gameVariables.character_rect.x += 4;
                        SDL_Delay(30);
                        if(collisions(gameVariables.character_rect))
                        {
                            gameVariables.character_rect.x -= 4;
                        }
                        gameVariables.character_flip = SDL_FLIP_HORIZONTAL;
                        if(gameVariables.character_frame == 2)
                            gameVariables.character_frame = 1;
                        else if (gameVariables.character_frame == 1)
                            gameVariables.character_frame = 0;
                        else if (gameVariables.character_frame == 0)
                            gameVariables.character_frame = 3;
                        else
                            gameVariables.character_frame = 2;
                        lookDirection = RIGHT;

                        break;
                    }
                }
            }
        }

    }
}
