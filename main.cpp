#include <iostream>
#include <SDL2/SDL.h>
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

using namespace std;

int main(int argc, char* argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Surface* screenSurface = NULL;      

     // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  
        SDL_WINDOWPOS_UNDEFINED,          
        SDL_WINDOWPOS_UNDEFINED,         
        SCREEN_WIDTH,                               
        SCREEN_HEIGHT,                              
        SDL_WINDOW_OPENGL          
    );
    // Check that the window was successfully created
    if (window == NULL) 
    {
        // In the case that the window could not be made...
        cout << "Could not create window: %s\n" << SDL_GetError();
        return -1;
    }
    else
    {
 	   //Get window surface
  	   screenSurface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);

	   //Fill the surface white
	   SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));

	   //Update the surface
	   SDL_UpdateWindowSurface(window); 
    }


    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
	{
            if (e.type == SDL_QUIT)
	    {
                quit = true;
            }
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    
    return 0;
}
