#include <stdio.h>
#include <SDL2/SDL.h>

#undef main

#define WIDTH 900
#define HEIGHT 600

#define CELL_SIZE 15
#define ROWS HEIGHT/CELL_SIZE
#define COLUMNS WIDTH/ CELL_SIZE
#define LINE_WIDTH 2

#define GRID_COLOR 0x1f1f1f1f

int draw_grid(SDL_Surface* surface)
{
    SDL_Rect row_line = {0,0,900,LINE_WIDTH};
    for(row_line.y = 0; row_line.y < HEIGHT; row_line.y += CELL_SIZE)
    {
        SDL_FillRect(surface,&row_line, GRID_COLOR);
    }

    SDL_Rect col_line = {0,0,LINE_WIDTH,HEIGHT};
    for (col_line.x = 0; col_line.x < WIDTH; col_line.x += CELL_SIZE)
    {
        SDL_FillRect(surface,&col_line, GRID_COLOR);
    }
}

int main(int argc, char* argv[])
{
    printf("Hello Snake with SDL2\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow(
        "Classic Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        0
    );

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {200,200,200,200};
    SDL_FillRect(surface, &rect, 0xffffffff);

    draw_grid(surface);
    SDL_UpdateWindowSurface(window);


    SDL_Delay(5000);


}