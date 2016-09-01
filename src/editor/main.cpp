#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <GL/glew.h>
#include "version.h"

int main(void)
{
	SDL_Window *window;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Wow Map Editor " VERSION_STR,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	if (window == NULL)
	{
		std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	bool running = true;
	SDL_Event e;

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "Could not initialize glew: " << glewGetErrorString(err) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

	glClearColor(0.15, 0.3, 0.7, 1.0);

	while (running)
	{
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT)
		{
			running = false;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}


	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
