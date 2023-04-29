#pragma once
#ifndef __APP_H__
#define __APP_H__

#include <chrono>

struct Renderer;
struct Input;

struct App
{
	// Managers
	Renderer*	renderer;
	Input*		input;

	// Keep runnning app
	bool running;

	// High performance timer to overview application efficiency
	std::chrono::steady_clock::time_point frame_begin;
};

void app_initialize(App* _app);
void app_start(App* _app);
void app_update(App* _app);
void app_clean_up(App* _app);

void on_glfw_error(int _error_code, const char* _error_message);

#endif // !__APP_H__