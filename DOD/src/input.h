#pragma once
#ifndef __INPUT_H__
#define __INPUT_H__

#include <glm/glm.hpp>
#include <glfw3.h>

struct App;

enum Mouse_Button
{
    LEFT,
    RIGHT,
    MOUSE_BUTTON_COUNT
};

enum Key
{
    K_SPACE,
    K_0, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9,
    K_A, K_B, K_C, K_D, K_E, K_F, K_G, K_H, K_I, K_J, K_K, K_L, K_M,
    K_N, K_O, K_P, K_Q, K_R, K_S, K_T, K_U, K_V, K_W, K_X, K_Y, K_Z,
    K_ENTER, K_ESCAPE,
    KEY_COUNT
};

enum Button_State
{
    BUTTON_IDLE,
    BUTTON_PRESS,
    BUTTON_PRESSED,
    BUTTON_RELEASE
};

struct Input
{
    glm::vec2	    mouse_position;
    glm::vec2	    mouse_delta;
    Button_State    mouse_buttons[MOUSE_BUTTON_COUNT];
    Button_State    keys[KEY_COUNT];
};

//void input_initialize(App* _app);
void input_state_change(Input* _input);

// OpenGL input callbacks

void on_glfw_mouse_event(GLFWwindow* _window, int _button, int _event, int _modifiers);

void on_glfw_mouse_move_event(GLFWwindow* _window, double _xposition, double _yposition);

void on_glfw_scroll_event(GLFWwindow* _window, double _xoffset, double _yoffset);

void on_glfw_keyboard_event(GLFWwindow* _window, int _key, int _scancode, int _action, int _modifications);

void on_glfw_char_event(GLFWwindow* _window, unsigned int _character);

void on_glfw_resize_framebuffer(GLFWwindow* _window, int _width, int _height);

void on_glfw_close_window(GLFWwindow* _window);

#endif // !__INPUT_H__