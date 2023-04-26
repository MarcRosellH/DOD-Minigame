#pragma once
#ifndef __APP_H__
#define __APP_H__

#include <chrono>

struct App
{
	// Stop updating and exit the application
	int update_state;

	// High performance timer to overview application efficiency
	std::chrono::steady_clock::time_point frame_begin;
};

bool initialize_app(App*);
bool start_app(App*);
int update_app(App*); // TODO: Returning int might not be so statless as it is suppoused to

void on_glfw_error(int _error_code, const char* _error_message);

#endif // !__APP_H__