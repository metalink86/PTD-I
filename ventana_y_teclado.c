#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Error al inicializar SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *ventana = SDL_CreateWindow("SDL3 en Dev-C++", 800, 600, 0);
    if (!ventana) {
        SDL_Log("Error al crear la ventana: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, NULL);
    bool corriendo = true;
    SDL_Event evento;

    SDL_StartTextInput(ventana);

    while (corriendo) {
        while (SDL_PollEvent(&evento)) {
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = false;
            } else if (evento.type == SDL_EVENT_TEXT_INPUT) {
                printf("Entrada: %s\n", evento.text.text);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 0, 100, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput(ventana);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}
