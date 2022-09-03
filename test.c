#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdbool.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800

int main(int argc, char **argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        SDL_Window *window =  SDL_CreateWindow("Test Window",
                                               SDL_WINDOWPOS_UNDEFINED,
                                               SDL_WINDOWPOS_UNDEFINED,
                                               WINDOW_WIDTH,
                                               WINDOW_HEIGHT,
                                               SDL_WINDOW_OPENGL);

        SDL_GLContext context = SDL_GL_CreateContext(window);

        if (GLEW_OK != glewInit()) {
                fprintf(stderr, "GLEW failed to initialise %s!\n", SDL_GetError());
                exit(1);
        }

        SDL_Event event = {0};

        while (true) {
                if (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT)
                                break;
                }

                SDL_GL_SwapWindow(window);
        }

        SDL_DestroyWindow(window);
        SDL_GL_DeleteContext(context);

        SDL_Quit();
        return 0;
}
