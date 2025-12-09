#include <stdio.h>
#include <SDL2/SDL.h>

#undef main

#define WIDTH 900
#define HEIGHT 600

#define CELL_SIZE 20
#define ROWS HEIGHT/CELL_SIZE
#define COLUMNS WIDTH/ CELL_SIZE
#define LINE_WIDTH 2

#define COLOR_GRID 0x1f1f1f1f
#define COLOR_WHITE 0xffffffff
#define COLOR_APPLE 0xffff0000

#define SNAKE(x,y) fill_cell(surface,x,y,COLOR_WHITE)
#define APPLE(x,y) fill_cell(surface,x,y,COLOR_APPLE)
#define DRAW_GRID draw_grid(surface)

int draw_grid(SDL_Surface* surface)
{
    SDL_Rect row_line = {0,0,900,LINE_WIDTH};
    for(row_line.y = 0; row_line.y < HEIGHT; row_line.y += CELL_SIZE)
    {
        SDL_FillRect(surface,&row_line, COLOR_GRID);
    }

    SDL_Rect col_line = {0,0,LINE_WIDTH,HEIGHT};
    for (col_line.x = 0; col_line.x < WIDTH; col_line.x += CELL_SIZE)
    {
        SDL_FillRect(surface,&col_line, COLOR_GRID);
    }
}

void fill_cell(SDL_Surface* surface, int x, int y, Uint32 color)
{
    SDL_Rect rect = {x*CELL_SIZE,y*CELL_SIZE,CELL_SIZE,CELL_SIZE};
    SDL_FillRect(surface, &rect, color);
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
    
    SDL_Event event;
    int game = 1;
    int snake_x = 5;
    int snake_y = 5;
    int apple_x = 13;
    int apple_y = 17;
    while (game)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                game = 0;
            if(event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RIGHT)
                    snake_x++;
                if (event.key.keysym.sym == SDLK_LEFT)
                    snake_x--;
                if (event.key.keysym.sym == SDLK_UP)
                    snake_y--;
                if (event.key.keysym.sym == SDLK_DOWN)
                    snake_y++;
            }
        }

        SNAKE(snake_x,snake_y);
        APPLE(apple_x,apple_y);
        DRAW_GRID;

        SDL_UpdateWindowSurface(window);
        SDL_Delay(20);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}