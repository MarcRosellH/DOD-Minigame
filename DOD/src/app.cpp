#pragma once

#include <glfw3.h>

#include "memleak.h"
#include "utils.h"

#include "app.h"
#include "render.h"
#include "input.h"

void app_initialize(App* _app)
{
	LOG("Initializing app...");

	_app->renderer = DBG_NEW Renderer;
	_app->input = DBG_NEW Input;

	glfwSetErrorCallback(on_glfw_error);

	render_initialize(_app);
	input_initialize(_app);

	_app->running = true;
}

void app_start(App* _app)
{
	LOG("Starting app...");

	LOG("Updating app...");
}

void app_update(App* _app)
{
	while (_app->running)
	{
		// Preupdate
		glfwPollEvents();

		// Update


		// Postupdate
		input_state_change(_app->input);
	}
}

void app_clean_up(App* _app)
{
	LOG("Cleaning app...");
	
	render_clean_up(_app->renderer);

	RELEASE(_app->input);
	RELEASE(_app->renderer);
}

void on_glfw_error(int _error_code, const char* _error_message)
{
	fprintf(stderr, "Glfw failed with error %d: %s\n", _error_code, _error_message);
}
