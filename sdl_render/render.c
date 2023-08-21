#include <SDL2/SDL.h>

int main(void){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Error starting SDL: %s \n",SDL_GetError());
        return -1;
    }

    SDL_Window * window = SDL_CreateWindow("render",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);
    if(!window){
        printf("Error creating window: %s \n",SDL_GetError());
        return -1;
    }

    SDL_Renderer * renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error rendering the window: %s\n",SDL_GetError());
        return -1;
    }


    int quit = 0;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    return 0;

}