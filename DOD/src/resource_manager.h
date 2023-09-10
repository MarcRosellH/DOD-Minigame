#pragma once
#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <string>
#include <vector>

#include <glad/glad.h>
#include <glad/khrplatform.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct GLFWwindow;
struct App;
struct aiMaterial;

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
    unsigned char location;
    unsigned char component_count;
    unsigned char offset;
};

struct VertexBufferLayout
{
    std::vector<VertexBufferAttribute>  attributes;
    unsigned char                       stride;
};

struct Model
{
    std::string                 name;
    unsigned int				mesh_index;
    std::vector<unsigned int>	material_index;
};

struct Vao
{
    GLuint  handle;
    GLuint  program_handle;
};

struct Submesh
{
    VertexBufferLayout              vertex_buffer_layout;
    std::vector<float>              vertices;
    std::vector<unsigned int>       indices;
    unsigned int                    vertex_offset;
    unsigned int                    index_offset;

    std::vector<Vao>                vaos;
};

struct Mesh
{
    std::vector<Submesh>    submeshes;
    GLuint                  vertex_buffer_handle;
    GLuint                  index_buffer_handle;
};

struct Material
{
    std::string          name;
    glm::vec3            albedo;
    glm::vec3            emissive;
    float                smoothness;
    unsigned int         albedo_texture_index;
    unsigned int         emissive_texture_index;
    unsigned int         specular_texture_index;
    unsigned int         normals_texture_index;
    unsigned int         bump_texture_index;
};

struct Image
{
    void* pixels;
    glm::ivec2  size;
    int         nchannels;
    int         stride;
};

struct Texture
{
    GLuint      handle;
    std::string filepath;
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

    

    GLuint textured_program_uTexture;
};

struct Resources
{
    std::vector<ShaderProgram> shader_programs;
    std::vector<Texture>		textures;
    std::vector<Material>		materials;
    std::vector<Mesh>			meshes;
    std::vector<Model>			models;
};

// Renderer main functions
void resources_initialize(App* _app);
//void glfw_initialize(App* _app);
void resources_clean_up(Resources* _resources);

unsigned int load_shader_program(Resources* renderer, const char* _file_path, const char* _program_name);

//void on_gl_error(GLenum _source, GLenum _type, GLuint _id, GLenum _severity, GLsizei _length, const GLchar* _message, const void* _user_param);

// Model loading

unsigned int load_model(Resources* _renderer, const char* _file_name);

void process_assimp_material(Resources* _renderer, aiMaterial* material, Material& myMaterial, std::string directory);

unsigned int load_texture_2D(Resources* _renderer, const char* _file_path);

GLuint create_texture_2D_from_image(Image _image);

Image load_image(const char* _file_name);

void free_image(Image image);

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



#endif // !__RESOURCE_MANAGER_H__