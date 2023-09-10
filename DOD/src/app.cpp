#pragma once

#include <glfw3.h>
#include <fstream>
#include <iostream>

#include "memleak.h"
#include "utils.h"

#include "app.h"
#include "resource_manager.h"
#include "scene.h"

//#include "input.h"

void app_initialize(App* _app)
{
	LOG("Initializing app...");

	/*_app->renderer = DBG_NEW Renderer;
	_app->input = DBG_NEW Input;

	glfwSetErrorCallback(on_glfw_error);*/

	//_app->resources = DBG_NEW Resources;
	_app->scene = DBG_NEW Scene;

	//resources_initialize(_app);
	//input_initialize(_app);

	_app->average_delta_time = 0.F;
	_app->average_fps = 0.F;
	_app->delta_time = 0.F;
	_app->total_time = 0.F;
	_app->times_count = 1;
	_app->total_created = 0;
	_app->total_destroyed = 0;

	_app->running = true;
}

void app_start(App* _app)
{
	LOG("Starting app...");
	create_scene(_app->scene);
	LOG("Updating app...");
}

void app_update(App* _app)
{
		// Preupdate
		//glfwPollEvents();

		// Update
		update_scene(_app->scene, _app->delta_time);

		// Postupdate
		//input_state_change(_app->input);
}

void app_clean_up(App* _app)
{
	LOG("Cleaning app...");

	_app->total_destroyed = _app->scene->total_destroyed;
	_app->total_created = _app->scene->total_created;
	
	//resources_clean_up(_app->resources);
	destroy_scene(_app->scene);

	//RELEASE(_app->input);
	//RELEASE(_app->renderer);
}

//void on_glfw_error(int _error_code, const char* _error_message)
//{
//	fprintf(stderr, "Glfw failed with error %d: %s\n", _error_code, _error_message);
//}
