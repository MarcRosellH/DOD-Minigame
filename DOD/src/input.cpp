#pragma once

#include "memleak.h"
#include "utils.h"

#include "app.h"
#include "input.h"
#include "render.h"

void input_state_change(Input* _input)
{

	for (size_t i = 0; i < MOUSE_BUTTON_COUNT; ++i)
	{
		if (_input->mouse_buttons[i] == BUTTON_PRESS)
		{
			_input->mouse_buttons[i] = BUTTON_PRESSED;
		}
		else if (_input->mouse_buttons[i] == BUTTON_RELEASE)
		{
			_input->mouse_buttons[i] = BUTTON_IDLE;
		}
	}

	for (size_t i = 0; i < KEY_COUNT; ++i)
	{
		if (_input->keys[i] == BUTTON_PRESS)
		{
			_input->keys[i] = BUTTON_PRESSED;
		}
		else if (_input->keys[i] == BUTTON_RELEASE)
		{
			_input->keys[i] = BUTTON_IDLE;
		}
	}
}

void input_initialize(App* _app)
{
	glfwSetMouseButtonCallback(_app->renderer->window, on_glfw_mouse_event);
	glfwSetCursorPosCallback(_app->renderer->window, on_glfw_mouse_move_event);
	glfwSetScrollCallback(_app->renderer->window, on_glfw_scroll_event);
	glfwSetKeyCallback(_app->renderer->window, on_glfw_keyboard_event);
	glfwSetCharCallback(_app->renderer->window, on_glfw_char_event);
	glfwSetFramebufferSizeCallback(_app->renderer->window, on_glfw_resize_framebuffer);
	glfwSetWindowCloseCallback(_app->renderer->window, on_glfw_close_window);
}

void on_glfw_mouse_event(GLFWwindow* _window, int _button, int _event, int _modifiers)
{
	App* app = (App*)glfwGetWindowUserPointer(_window);

	switch (_event)
	{
	case GLFW_PRESS:
		switch (_button)
		{
		case GLFW_MOUSE_BUTTON_RIGHT:
			(app->input->mouse_buttons[RIGHT] != BUTTON_PRESSED) ? app->input->mouse_buttons[RIGHT] = BUTTON_PRESS : app->input->mouse_buttons[RIGHT] == BUTTON_PRESSED; break;
		case GLFW_MOUSE_BUTTON_LEFT:
			(app->input->mouse_buttons[LEFT] != BUTTON_PRESSED) ? app->input->mouse_buttons[LEFT] = BUTTON_PRESS : app->input->mouse_buttons[LEFT] == BUTTON_PRESSED; break;
		}
		break;
	case GLFW_RELEASE:
		switch (_button)
		{
		case GLFW_MOUSE_BUTTON_RIGHT: app->input->mouse_buttons[RIGHT] = BUTTON_RELEASE; break;
		case GLFW_MOUSE_BUTTON_LEFT:  app->input->mouse_buttons[LEFT] = BUTTON_RELEASE; break;
		}
		break;
	}
}

void on_glfw_mouse_move_event(GLFWwindow* _window, double _xposition, double _yposition)
{
	App* app = (App*)glfwGetWindowUserPointer(_window);

	app->input->mouse_delta.x = _xposition - app->input->mouse_position.x;
	app->input->mouse_delta.y = _xposition - app->input->mouse_position.y;
	app->input->mouse_position.x = _xposition;
	app->input->mouse_position.y = _yposition;
}

void on_glfw_scroll_event(GLFWwindow* _window, double _xoffset, double _yoffset)
{
	// Not managed...
}

void on_glfw_keyboard_event(GLFWwindow* _window, int _key, int _scancode, int _action, int _modifications)
{
	// Remap key to our enum values
	switch (_key)
	{
	case GLFW_KEY_SPACE:  _key = K_SPACE; break;
	case GLFW_KEY_0: _key = K_0; break; case GLFW_KEY_1: _key = K_1; break; case GLFW_KEY_2: _key = K_2; break;
	case GLFW_KEY_3: _key = K_3; break; case GLFW_KEY_4: _key = K_4; break; case GLFW_KEY_5: _key = K_5; break;
	case GLFW_KEY_6: _key = K_6; break; case GLFW_KEY_7: _key = K_7; break; case GLFW_KEY_8: _key = K_8; break;
	case GLFW_KEY_9: _key = K_9; break;
	case GLFW_KEY_A: _key = K_A; break; case GLFW_KEY_B: _key = K_B; break; case GLFW_KEY_C: _key = K_C; break;
	case GLFW_KEY_D: _key = K_D; break; case GLFW_KEY_E: _key = K_E; break; case GLFW_KEY_F: _key = K_F; break;
	case GLFW_KEY_G: _key = K_G; break; case GLFW_KEY_H: _key = K_H; break; case GLFW_KEY_I: _key = K_I; break;
	case GLFW_KEY_J: _key = K_J; break; case GLFW_KEY_K: _key = K_K; break; case GLFW_KEY_L: _key = K_L; break;
	case GLFW_KEY_M: _key = K_M; break; case GLFW_KEY_N: _key = K_N; break; case GLFW_KEY_O: _key = K_O; break;
	case GLFW_KEY_P: _key = K_P; break; case GLFW_KEY_Q: _key = K_Q; break; case GLFW_KEY_R: _key = K_R; break;
	case GLFW_KEY_S: _key = K_S; break; case GLFW_KEY_T: _key = K_T; break; case GLFW_KEY_U: _key = K_U; break;
	case GLFW_KEY_V: _key = K_V; break; case GLFW_KEY_W: _key = K_W; break; case GLFW_KEY_X: _key = K_X; break;
	case GLFW_KEY_Y: _key = K_Y; break; case GLFW_KEY_Z: _key = K_Z; break;
	case GLFW_KEY_ESCAPE: _key = K_ESCAPE; break;
	case GLFW_KEY_ENTER:  _key = K_ENTER; break;
	}

	App* app = (App*)glfwGetWindowUserPointer(_window);
	switch (_action)
	{
	case GLFW_PRESS:   (app->input->keys[_key] != BUTTON_PRESSED) ? app->input->keys[_key] = BUTTON_PRESS : app->input->keys[_key] == BUTTON_PRESSED; break;
	case GLFW_RELEASE: app->input->keys[_key] = BUTTON_RELEASE; break;
	}
}

void on_glfw_char_event(GLFWwindow* _window, unsigned int _character)
{
	// Not managed...
}

void on_glfw_resize_framebuffer(GLFWwindow* _window, int _width, int _height)
{
	App* app = (App*)glfwGetWindowUserPointer(_window);
	app->renderer->display_size = glm::ivec2(_width, _height);
}

void on_glfw_close_window(GLFWwindow* _window)
{
	App* app = (App*)glfwGetWindowUserPointer(_window);
	app->running = false;
}