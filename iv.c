#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("hello\n");

    FILE *in = stdin;
    char *pthroway = calloc(1000, sizeof(char));
    fgets(pthroway, 1000, in);
    fgets(pthroway, 1000, in);
    char *pdim = calloc(1000, sizeof(char));
    fgets(pdim, 1000, in);
    fgets(pthroway, 1000, in);
    free(pthroway);

    int width = -1;
    int height = -1;
    sscanf(pdim, "%d %d\n", &width, &height);
    printf("width=%d height=%d", width, height);
    free(pdim);
    SDL_Window *pwindow =
        SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

    SDL_Rect pixel = (SDL_Rect){
        0,
        0,
        1,
        1,
    };
    Uint8 r, g, b;
    Uint32 color = 0;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            r = (char)getchar();
            g = (char)getchar();
            b = (char)getchar();
            color = SDL_MapRGB(psurface->format, r, g, b);
            pixel.x = x;
            pixel.y = y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }

    SDL_UpdateWindowSurface(pwindow);
    int running = 1;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
        SDL_Delay(1000);
    }
    return 0;
}
