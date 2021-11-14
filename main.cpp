#include <iostream>
#include <SDL2/SDL.h>
#include "shapes.hpp"
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

using namespace std;

void GameLoop(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_Event e;

    while (true)
    {
        SDL_PollEvent(&e);

        if (e.type == SDL_QUIT)
            return;

        SDL_RenderClear(renderer);

        DrawCircle(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100);

        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    //Ask the WM to not composite the window which fixes visual bugs in some WMs
    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");

     //Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  
        SDL_WINDOWPOS_UNDEFINED,          
        SDL_WINDOWPOS_UNDEFINED,         
        SCREEN_WIDTH,                               
        SCREEN_HEIGHT,                              
        SDL_WINDOW_OPENGL          
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //Check that the window was successfully created
    if (window == NULL) 
    {
        //In the case that the window could not be made...
        cout << "Could not create window: %s\n" << SDL_GetError();
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_UpdateWindowSurface(window);

    GameLoop(window, renderer);

    //Close and destroy the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //Clean up
    SDL_Quit();
    
    return 0;
}
