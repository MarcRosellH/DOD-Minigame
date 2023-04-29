#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__

#include <string>
#include <vector>

#include <glad/glad.h>
#include <glad/khrplatform.h>

#include <glm/glm.hpp>

struct GLFWwindow;
struct App;

struct Buffer
{
	GLuint			handle;
	GLenum			type;
	unsigned int    size;
	unsigned int    head;
	void*			data;
};

struct VertexBufferAttribute
{
	unsigned char	location;
	unsigned char	component_count;
	unsigned char	offset;
};

struct VertexBufferLayout
{
	std::vector<VertexBufferAttribute>	attributes;
	unsigned char						stride;
};

struct VertexShaderAttribute
{
	unsigned char location;
	unsigned char component_count;
};

struct VertexShaderLayout
{
	std::vector<VertexShaderAttribute> attributes;
};

struct ShaderProgram
{
	GLuint					handle;
	std::string				file_path;
	std::string				name;
	VertexShaderLayout		vertex_input_layout;
};

struct Renderer
{
	GLFWwindow* window;
	glm::ivec2	display_size;

	// Shader programs data
	std::vector<ShaderProgram> shader_programs;
	unsigned int deferred_geometry_pass_program_index;
	unsigned int deferred_lighting_pass_program_index;

	// Deferred rendering ---------------------------

	// Deferred rendering framebuffers
	GLuint framebuffer_geometry;
	GLuint framebuffer_final;

	// Deferred rendering attachment handles
	GLuint position_attachment_handle;
	GLuint normals_attachment_handle;
	GLuint diffuse_attachment_handle;
	GLuint depth_attachment_handle;

	GLuint final_render_attachment_handle;

	// Deferred rendering uniforms
	GLint deferred_geometry_program_uTexture;

	GLint deferred_lighting_program_uGPosition;
	GLint deferred_lighting_program_uGNormals;
	GLint deferred_lighting_program_uGDiffuse;
};

// Renderer main functions
void render_initialize(App* _app);
void glfw_initialize(App* _app);
void render_clean_up(Renderer* _renderer);

unsigned int load_shader_program(Renderer* renderer, const char* _file_path, const char* _program_name);

void on_gl_error(GLenum _source, GLenum _type, GLuint _id, GLenum _severity, GLsizei _length, const GLchar* _message, const void* _user_param);

// Buffer Management

Buffer create_buffer(unsigned int _size, GLenum _type, GLenum _usage);

void push_aligned_data(Buffer& _buffer, const void* _data, unsigned int _size, unsigned int _alignment);

void bind_buffer(const Buffer& _buffer);
void align_head(Buffer& _buffer, unsigned int _alignment);

void map_buffer(Buffer& _buffer, GLenum _access);
void unmap_buffer(Buffer& _buffer);

bool is_power_of_2(unsigned int _value);

unsigned int align(unsigned int _value, unsigned int _alignment);

#define CreateConstantBuffer(_size) create_buffer(_size, GL_UNIFORM_BUFFER, GL_STREAM_DRAW);
#define CreateStaticVertexBuffer(_size) create_buffer(_size, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
#define CreateStaticIndexBuffer(_size) create_buffer(_size, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);

#define PushData(_buffer, _data, _size) push_aligned_data(_buffer, _data, _size, 1);
#define PushUInt(_buffer, _value) {unsigned int v = _value; push_aligned_data(_buffer, &v, sizeof(v), 4);}
#define PushFloat(_buffer, _value) {float v = _value; push_aligned_data(_buffer, &v, sizeof(v), 4);}
#define PushVec3(_buffer, _value) push_aligned_data(_buffer, value_ptr(_value), sizeof(_value), sizeof(glm::vec4))
#define PushVec4(_buffer, _value) push_aligned_data(_buffer, value_ptr(_value), sizeof(_value), sizeof(glm::vec4))
#define PushMat3(_buffer, _value) push_aligned_data(_buffer, value_ptr(_value), sizeof(_value), sizeof(glm::vec4))
#define PushMat4(_buffer, _value) push_aligned_data(_buffer, value_ptr(_value), sizeof(_value), sizeof(glm::vec4))

// Shader loader

GLuint create_shader_program_from_source(std::string& _program_src, const char* _shader_name);

unsigned char get_attric_component_count(const GLenum& _type);



#endif // !__RENDER_H__