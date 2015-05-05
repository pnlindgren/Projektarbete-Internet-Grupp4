#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "keyInput2.h"
#include "wallDetector.h"

void keyInput2()
{
    bool quit = false;
    bool lookDirection = RIGHT;

    SDL_Event e;

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
                    /*case SDLK_UP:
                        character_rect.y -= 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        break;
                    case SDLK_DOWN:
                        character_rect.y += 2;
                        printf("Position: (%d,%d)\n", character.x, character.y);
                        break;*/
                    case SDLK_LEFT:
                        character_rect.x -= 4;
                        if(collisions(character_rect))
                        {
                            character_rect.x += 4;
                        }
                        flip = SDL_FLIP_NONE;
                        frame = 2;
                        printf("Position: (%d,%d)\n", character_rect.x, character_rect.y);
                        lookDirection = LEFT;
                        break;
                    case SDLK_RIGHT:
                        character_rect.x += 4;
                        if(collisions(character_rect))
                        {
                            character_rect.x -= 4;
                        }
                        flip = SDL_FLIP_NONE;
                        frame = 3;
                        printf("Position: (%d,%d)\n", character_rect.x, character_rect.y);
                        lookDirection = RIGHT;
                        break;
                }
            }
        }
    }
}
