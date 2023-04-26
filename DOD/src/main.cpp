#pragma once

#include "app.h"
#include "memleak.h"
#include "utils.h"

int main()
{
	// Initialize crtdbg to detect memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	App* app = DBG_NEW App;



	return 0;
}