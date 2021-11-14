#include <iostream>
#include <SDL2/SDL.h>
#include "shapes.hpp"
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

using namespace std;

void GameLoop(SDL_Window *window, SDL_Renderer *renderer)
{
    float x = SCREEN_WIDTH / 2;
    float y = SCREEN_HEIGHT / 2;
    float speed = 0.1f;

    SDL_Event e;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    while (true)
    {

         LAST = NOW;
         NOW = SDL_GetPerformanceCounter();

        deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency());
        SDL_PollEvent(&e);
        float speedf = speed * deltaTime;

        switch (e.type)
        {
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                    case SDLK_LEFT:  x -= speedf; break;
                    case SDLK_RIGHT: x += speedf; break;
                    case SDLK_UP:    y -= speedf; break;
                    case SDLK_DOWN:  y += speedf; break;
                }
                break;
            case SDL_QUIT:
                return;
                break;
        }

        SDL_RenderClear(renderer);

        DrawCircle(renderer, x, y, 5);

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
