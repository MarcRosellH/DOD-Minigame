#pragma once
#ifndef __APP_H__
#define __APP_H__

#include <chrono>
#include <vector>

#define MAX_TIME 11

typedef std::chrono::steady_clock Clock;

//struct Input;
//struct Resources;
struct Scene;

struct App
{
	// Managers
	/*Renderer*	renderer;
	Input*		input;*/
	//Resources*	resources;
	Scene*		scene;

	// Keep runnning app
	bool running;

	// High performance timer to overview application efficiency
	Clock::time_point last_time;

	float average_delta_time;
	float average_fps;

	unsigned long long total_created;
	unsigned long long total_destroyed;
	float delta_time;

	float total_time;
	float fps;
	unsigned int times_count;
	std::vector<float> delta_time_list;
};

void app_initialize(App* _app);
void app_start(App* _app);
void app_update(App* _app);
void app_clean_up(App* _app);

//void on_glfw_error(int _error_code, const char* _error_message);

#endif // !__APP_H__