#pragma once

#include <fstream>
#include <iostream>

#include "app.h"
#include "memleak.h"
#include "utils.h"
#include "scene.h"

int main()
{
	// Initialize crtdbg to detect memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	App* app = DBG_NEW App;

	std::cout << "DOD simulation of " << MAX_OBJECTS << " objects during " << MAX_TIME << " seconds:" << std::endl;
	std::cout << "Average values above may differ due to calculating them using incremental averaging!" << std::endl;

	app_initialize(app);
	app_start(app);
	app->last_time = Clock::now();
	int i = 0;
	while (app->running)
	{
		app_update(app);
		auto now = Clock::now();
		app->delta_time = std::chrono::duration<float, std::chrono::seconds::period>(now - app->last_time).count();
		app->total_time += app->delta_time;


		app->average_delta_time = app->average_delta_time + ((app->delta_time - app->average_delta_time) / app->times_count);
		app->fps = 1 / app->delta_time;
		app->average_fps = app->average_fps + ((app->fps - app->average_fps) / app->times_count);
		app->times_count++;

		app->delta_time_list.push_back(app->delta_time);
		app->last_time = now;

		app->running = app->total_time < MAX_TIME;
	}
	app_clean_up(app);

#ifdef _WIN64
	std::string platform = "x64";
#elif _WIN32
	std::string platform = "x86";
#endif
	std::string name = std::string(platform + "output_" + std::to_string(MAX_OBJECTS) + "_objects_in_" + std::to_string((int)MAX_TIME) + ".csv");

	std::cout << "\nAverage update time: " << app->average_delta_time << " seconds" << std::endl;
	std::cout << "Average updates per second: " << app->average_fps << std::endl;
	std::cout << std::to_string(app->delta_time_list.size()) << " update times data in total." << std::endl;
	std::cout << "Saving update times in file " << name << "..." << std::endl;

	std::ofstream outfile(name);
	for (unsigned long long i = 0; i < app->delta_time_list.size(); ++i)
	{
		outfile << app->delta_time_list[i] << std::endl;
	}

	outfile.close();
	app->delta_time_list.clear();

	std::cout << "Data saved." << std::endl;
	std::cout << "\nPress any key to close..." << std::endl;
	char a = getchar();

	RELEASE(app);

	return 0;
}