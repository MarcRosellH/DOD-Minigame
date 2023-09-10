#pragma once

//#include <glfw3.h>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <stb_image.h>
#include <stb_image_write.h>

#include "memleak.h"
#include "utils.h"

#include "app.h"
#include "resource_manager.h"

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "DOD Minigame"

void resources_initialize(App* _app)
{
    //glfw_initialize(_app);

    //load_model(_app->resources, "Patrick/Patrick.obj");
    {
    // [Deferred Render] Geometry Pass Program
    //_app->renderer->deferred_geometry_pass_program_index = load_shader_program(_app->renderer, "shaders.glsl", "DEFERRED_GEOMETRY_PASS");

    //ShaderProgram& deferred_geo_pass_program = _app->renderer->shader_programs[_app->renderer->deferred_geometry_pass_program_index];
    //GLint deferred_geo_attribute_count;
    //glGetProgramiv(deferred_geo_pass_program.handle, GL_ACTIVE_ATTRIBUTES, &deferred_geo_attribute_count);

    //for (GLint i = 0; i < deferred_geo_attribute_count; ++i)
    //{
    //    GLchar attr_name[32];
    //    GLsizei attr_len;
    //    GLint attr_size;
    //    GLenum attr_type;

    //    glGetActiveAttrib(deferred_geo_pass_program.handle, i,
    //        ARRAY_COUNT(attr_name),
    //        &attr_len,
    //        &attr_size,
    //        &attr_type,
    //        attr_name);

    //    GLint attr_location = glGetAttribLocation(deferred_geo_pass_program.handle, attr_name);

    //    deferred_geo_pass_program.vertex_input_layout.attributes.push_back({ (unsigned char)attr_location, get_attric_component_count(attr_type) });
    //}

    //_app->renderer->deferred_geometry_program_uTexture = glGetUniformLocation(deferred_geo_pass_program.handle, "uTexture");

    //// [Deferred Render] Lighting Pass Program
    //_app->renderer->deferred_lighting_pass_program_index = load_shader_program(_app->renderer, "shaders.glsl", "DEFERRED_LIGHTING_PASS");

    //ShaderProgram& deferred_lighting_pass_program = _app->renderer->shader_programs[_app->renderer->deferred_lighting_pass_program_index];
    //GLint deferred_light_attribute_count;
    //glGetProgramiv(deferred_lighting_pass_program.handle, GL_ACTIVE_ATTRIBUTES, &deferred_light_attribute_count);

    //for (GLint i = 0; i < deferred_light_attribute_count; ++i)
    //{
    //    GLchar attr_name[32];
    //    GLsizei attr_len;
    //    GLint attr_size;
    //    GLenum attr_type;

    //    glGetActiveAttrib(deferred_lighting_pass_program.handle, i,
    //        ARRAY_COUNT(attr_name),
    //        &attr_len,
    //        &attr_size,
    //        &attr_type,
    //        attr_name);

    //    GLint attr_location = glGetAttribLocation(deferred_lighting_pass_program.handle, attr_name);

    //    deferred_lighting_pass_program.vertex_input_layout.attributes.push_back({ (unsigned char)attr_location, get_attric_component_count(attr_type) });
    //}

    //_app->renderer->deferred_lighting_program_uGPosition = glGetUniformLocation(deferred_lighting_pass_program.handle, "uGPosition");
    //_app->renderer->deferred_lighting_program_uGNormals = glGetUniformLocation(deferred_lighting_pass_program.handle, "uGNormals");
    //_app->renderer->deferred_lighting_program_uGDiffuse = glGetUniformLocation(deferred_lighting_pass_program.handle, "uGDiffuse");

    // [Framebuffers]

    // [Framebuffer] GBuffer
    // [Texture] Positions
    //
}
}

//void glfw_initialize(App* _app)
//{
//	ASSERT(glfwInit(),"glfwInit() method failed\n");
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	_app->renderer->display_size = glm::ivec2(WINDOW_WIDTH, WINDOW_HEIGHT);
//	_app->renderer->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
//
//    ASSERT(_app->renderer->window, "glfwCreateWindow() method failed!\n");
//
//	glfwSetWindowUserPointer(_app->renderer->window, _app);
//
//	glfwMakeContextCurrent(_app->renderer->window);
//
//    ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize OpenGL context\n");
//
//	if (GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 3))
//	{
//		glDebugMessageCallback(on_gl_error, _app);
//	}
//}

void resources_clean_up(Resources* _resources)
{
    /*glfwDestroyWindow(_renderer->window);

    glfwTerminate();*/
}

//void on_gl_error(GLenum _source, GLenum _type, GLuint _id, GLenum _severity, GLsizei _length, const GLchar* _message, const void* _user_param)
//{
//    if (_severity == GL_DEBUG_SEVERITY_NOTIFICATION)
//        return;
//
//    LOG("OpenGL debug message: %s", _message);
//
//    switch (_source)
//    {
//    case GL_DEBUG_SOURCE_API:               LOG(" - source: GL_DEBUG_SOURCE_API"); break;
//    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:     LOG(" - source: GL_DEBUG_SOURCE_WINDOW_SYSTEM"); break;
//    case GL_DEBUG_SOURCE_SHADER_COMPILER:   LOG(" - source: GL_DEBUG_SOURCE_SHADER_COMPILER"); break;
//    case GL_DEBUG_SOURCE_THIRD_PARTY:       LOG(" - source: GL_DEBUG_SOURCE_THIRD_PARTY"); break;
//    case GL_DEBUG_SOURCE_APPLICATION:       LOG(" - source: GL_DEBUG_SOURCE_APPLICATION"); break;
//    case GL_DEBUG_SOURCE_OTHER:             LOG(" - source: GL_DEBUG_SOURCE_OTHER"); break;
//    }
//
//    switch (_type)
//    {
//    case GL_DEBUG_TYPE_ERROR:               LOG(" - type: GL_DEBUG_TYPE_ERROR"); break;
//    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: LOG(" - type: GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR"); break;
//    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  LOG(" - type: GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR"); break;
//    case GL_DEBUG_TYPE_PORTABILITY:         LOG(" - type: GL_DEBUG_TYPE_PORTABILITY"); break;
//    case GL_DEBUG_TYPE_PERFORMANCE:         LOG(" - type: GL_DEBUG_TYPE_PERFORMANCE"); break;
//    case GL_DEBUG_TYPE_MARKER:              LOG(" - type: GL_DEBUG_TYPE_MARKER"); break;
//    case GL_DEBUG_TYPE_PUSH_GROUP:          LOG(" - type: GL_DEBUG_TYPE_PUSH_GROUP"); break;
//    case GL_DEBUG_TYPE_POP_GROUP:           LOG(" - type: GL_DEBUG_TYPE_POP_GROUP"); break;
//    case GL_DEBUG_TYPE_OTHER:               LOG(" - type: GL_DEBUG_TYPE_OTHER"); break;
//    }
//
//    switch (_severity)
//    {
//    case GL_DEBUG_SEVERITY_HIGH:            LOG(" - severity: GL_DEBUG_SEVERITY_HIGH"); break;
//    case GL_DEBUG_SEVERITY_MEDIUM:          LOG(" - severity: GL_DEBUG_SEVERITY_MEDIUM"); break;
//    case GL_DEBUG_SEVERITY_LOW:             LOG(" - severity: GL_DEBUG_SEVERITY_LOW"); break;
//    case GL_DEBUG_SEVERITY_NOTIFICATION:    LOG(" - severity: GL_DEBUG_SEVERITY_NOTIFICATION"); break;
//    }
//}

// Buffer Management

bool is_power_of_2(unsigned int _value)
{
    return _value && !(_value & (_value - 1));
}

unsigned int align(unsigned int _value, unsigned int _alignment)
{
    return (_value + _alignment - 1) & ~(_alignment - 1);
}

Buffer create_buffer(unsigned int _size, GLenum _type, GLenum _usage)
{
    Buffer buffer = {};
    buffer.size = _size;
    buffer.type = _type;

    glGenBuffers(1, &buffer.handle);
    glBindBuffer(_type, buffer.handle);
    glBufferData(_type, buffer.size, NULL, _usage);
    glBindBuffer(_type, 0);

    return buffer;
}

void bind_buffer(const Buffer& _buffer)
{
    glBindBuffer(_buffer.type, _buffer.handle);
}

void map_buffer(Buffer& _buffer, GLenum _access)
{
    glBindBuffer(_buffer.type, _buffer.handle);
    _buffer.data = (unsigned char*)glMapBuffer(_buffer.type, _access);
    _buffer.head = 0;
}

void unmap_buffer(Buffer& _buffer)
{
    glUnmapBuffer(_buffer.type);
    glBindBuffer(_buffer.type, 0);
}

void align_head(Buffer& _buffer, unsigned int _alignment)
{
    ASSERT(is_power_of_2(_alignment), "The alignment must be a power of 2");
    _buffer.head = align(_buffer.head, _alignment);
}

void push_aligned_data(Buffer& _buffer, const void* _data, unsigned int _size, unsigned int _alignment)
{
    ASSERT(_buffer.data != NULL, "The buffer must be mapped first");
    align_head(_buffer, _alignment);
    memcpy((unsigned char*)_buffer.data + _buffer.head, _data, _size);
    _buffer.head += _size;
}

// Shader loader

GLuint create_shader_program_from_source(std::string& _program_src, const char* _shader_name)
{
    GLchar  info_log_buffer[1024] = {};
    GLsizei info_log_buffer_size = sizeof(info_log_buffer);
    GLsizei info_log_size;
    GLint   success;

    char version_string[] = "#version 430\n";
    char shader_name_define[128];
    sprintf(shader_name_define, "#define %s\n", _shader_name);
    char vertex_shader_define[] = "#define VERTEX\n";
    char fragment_shader_define[] = "#define FRAGMENT\n";

    const GLchar* vertex_shader_source[] = {
        version_string,
        shader_name_define,
        vertex_shader_define,
        _program_src.c_str()
    };
    const GLint vertex_shader_lengths[] = {
        (GLint)strlen(version_string),
        (GLint)strlen(shader_name_define),
        (GLint)strlen(vertex_shader_define),
        (GLint)_program_src.length()
    };
    const GLchar* fragment_shader_source[] = {
        version_string,
        shader_name_define,
        fragment_shader_define,
        _program_src.c_str()
    };
    const GLint fragment_shader_lengths[] = {
        (GLint)strlen(version_string),
        (GLint)strlen(shader_name_define),
        (GLint)strlen(fragment_shader_define),
        (GLint)_program_src.length()
    };

    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, ARRAY_COUNT(vertex_shader_source), vertex_shader_source, vertex_shader_lengths);
    glCompileShader(vshader);
    glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vshader, info_log_buffer_size, &info_log_size, info_log_buffer);
        LOG("glCompileShader() function failed with vertex shader %s\nReported message:\n%s\n", _shader_name, info_log_buffer);
    }

    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, ARRAY_COUNT(fragment_shader_source), fragment_shader_source, fragment_shader_lengths);
    glCompileShader(fshader);
    glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fshader, info_log_buffer_size, &info_log_size, info_log_buffer);
        LOG("glCompileShader() function failed with fragment shader %s\nReported message:\n%s\n", _shader_name, info_log_buffer);
    }

    GLuint program_handle = glCreateProgram();
    glAttachShader(program_handle, vshader);
    glAttachShader(program_handle, fshader);
    glLinkProgram(program_handle);
    glGetProgramiv(program_handle, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program_handle, info_log_buffer_size, &info_log_size, info_log_buffer);
        LOG("glLinkProgram() failed with program %s\nReported message:\n%s\n", _shader_name, info_log_buffer);
    }

    glUseProgram(0);

    glDetachShader(program_handle, vshader);
    glDetachShader(program_handle, fshader);
    glDeleteShader(vshader);
    glDeleteShader(fshader);

    return program_handle;
}

unsigned char get_attric_component_count(const GLenum& _type)
{
    switch (_type)
    {
    case GL_FLOAT: return 1; break;
    case GL_FLOAT_VEC2: return 2; break;
    case GL_FLOAT_VEC3: return 3; break;
    case GL_FLOAT_VEC4: return 4; break;
    case GL_FLOAT_MAT2: return 4; break;
    case GL_FLOAT_MAT3: return 9; break;
    case GL_FLOAT_MAT4: return 16; break;
    case GL_FLOAT_MAT2x3: return 6; break;
    case GL_FLOAT_MAT2x4: return 8; break;
    case GL_FLOAT_MAT3x2: return 6; break;
    case GL_FLOAT_MAT3x4: return 12; break;
    case GL_FLOAT_MAT4x2: return 8; break;
    case GL_FLOAT_MAT4x3: return 12; break;
    case GL_INT: return 1; break;
    case GL_INT_VEC2: return 2; break;
    case GL_INT_VEC3: return 3; break;
    case GL_INT_VEC4: return 4; break;
    case GL_UNSIGNED_INT: return 1; break;
    case GL_UNSIGNED_INT_VEC2: return 2; break;
    case GL_UNSIGNED_INT_VEC3: return 3; break;
    case GL_UNSIGNED_INT_VEC4: return 4; break;
    case GL_DOUBLE: return 1; break;
    case GL_DOUBLE_VEC2: return 2; break;
    case GL_DOUBLE_VEC3: return 3; break;
    case GL_DOUBLE_VEC4: return 4; break;
    case GL_DOUBLE_MAT2: return 4; break;
    case GL_DOUBLE_MAT3: return 9; break;
    case GL_DOUBLE_MAT4: return 16;
    case GL_DOUBLE_MAT2x3: return 6; break;
    case GL_DOUBLE_MAT2x4: return 8; break;
    case GL_DOUBLE_MAT3x2: return 6; break;
    case GL_DOUBLE_MAT3x4: return 12; break;
    case GL_DOUBLE_MAT4x2: return 8; break;
    case GL_DOUBLE_MAT4x3: return 12; break;
    default: return 0; break;
    }

    // leave this return 0 as a default return outisde the switch, just in case
    return 0;
}

unsigned int load_shader_program(Resources* renderer, const char* _file_path, const char* _program_name)
{
    std::string program_source = read_text_file(_file_path);

    ShaderProgram program = {};
    program.file_path = _file_path;
    program.name = _program_name;
    program.handle = create_shader_program_from_source(program_source, _program_name);
    renderer->shader_programs.push_back(program);
    return renderer->shader_programs.size() - 1;
}

void process_assimp_mesh(const aiScene* scene, aiMesh* mesh, Mesh* myMesh, unsigned int baseMeshMaterialIndex, std::vector<unsigned int>& submeshMaterialIndices)
{
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    bool hasTexCoords = false;
    bool hasTangentSpace = false;

    // process vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        vertices.push_back(mesh->mVertices[i].x);
        vertices.push_back(mesh->mVertices[i].y);
        vertices.push_back(mesh->mVertices[i].z);
        vertices.push_back(mesh->mNormals[i].x);
        vertices.push_back(mesh->mNormals[i].y);
        vertices.push_back(mesh->mNormals[i].z);

        if (mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            hasTexCoords = true;
            vertices.push_back(mesh->mTextureCoords[0][i].x);
            vertices.push_back(mesh->mTextureCoords[0][i].y);
        }

        if (mesh->mTangents != nullptr && mesh->mBitangents)
        {
            hasTangentSpace = true;
            vertices.push_back(mesh->mTangents[i].x);
            vertices.push_back(mesh->mTangents[i].y);
            vertices.push_back(mesh->mTangents[i].z);

            // For some reason ASSIMP gives me the bitangents flipped.
            // Maybe it's my fault, but when I generate my own geometry
            // in other files (see the generation of standard assets)
            // and all the bitangents have the orientation I expect,
            // everything works ok.
            // I think that (even if the documentation says the opposite)
            // it returns a left-handed tangent space matrix.
            // SOLUTION: I invert the components of the bitangent here.
            vertices.push_back(-mesh->mBitangents[i].x);
            vertices.push_back(-mesh->mBitangents[i].y);
            vertices.push_back(-mesh->mBitangents[i].z);
        }
    }

    // process indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    // store the proper (previously proceessed) material for this mesh
    submeshMaterialIndices.push_back(baseMeshMaterialIndex + mesh->mMaterialIndex);

    // create the vertex format
    VertexBufferLayout vertexBufferLayout = {};
    vertexBufferLayout.attributes.push_back(VertexBufferAttribute{ 0, 3, 0 });
    vertexBufferLayout.attributes.push_back(VertexBufferAttribute{ 1, 3, 3 * sizeof(float) });
    vertexBufferLayout.stride = 6 * sizeof(float);
    if (hasTexCoords)
    {
        vertexBufferLayout.attributes.push_back(VertexBufferAttribute{ 2, 2, vertexBufferLayout.stride });
        vertexBufferLayout.stride += 2 * sizeof(float);
    }
    if (hasTangentSpace)
    {
        vertexBufferLayout.attributes.push_back(VertexBufferAttribute{ 3, 3, vertexBufferLayout.stride });
        vertexBufferLayout.stride += 3 * sizeof(float);

        vertexBufferLayout.attributes.push_back(VertexBufferAttribute{ 4, 3, vertexBufferLayout.stride });
        vertexBufferLayout.stride += 3 * sizeof(float);
    }

    // add the submesh into the mesh
    Submesh submesh = {};
    submesh.vertex_buffer_layout = vertexBufferLayout;
    submesh.vertices.swap(vertices);
    submesh.indices.swap(indices);
    myMesh->submeshes.push_back(submesh);
}

//void process_assimp_material(Resources* _renderer, aiMaterial* material, Material& myMaterial, std::string directory)
//{
//    aiString name;
//    aiColor3D diffuseColor;
//    aiColor3D emissiveColor;
//    aiColor3D specularColor;
//    ai_real shininess;
//    material->Get(AI_MATKEY_NAME, name);
//    material->Get(AI_MATKEY_COLOR_DIFFUSE, diffuseColor);
//    material->Get(AI_MATKEY_COLOR_EMISSIVE, emissiveColor);
//    material->Get(AI_MATKEY_COLOR_SPECULAR, specularColor);
//    material->Get(AI_MATKEY_SHININESS, shininess);
//
//    myMaterial.name = name.C_Str();
//    myMaterial.albedo = glm::vec3(diffuseColor.r, diffuseColor.g, diffuseColor.b);
//    myMaterial.emissive = glm::vec3(emissiveColor.r, emissiveColor.g, emissiveColor.b);
//    myMaterial.smoothness = shininess / 256.0f;
//
//    aiString aiFilename;
//    if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0)
//    {
//        material->GetTexture(aiTextureType_DIFFUSE, 0, &aiFilename);
//        std::string filename = aiFilename.C_Str();
//        std::string filepath = make_path(directory, filename);
//        myMaterial.albedo_texture_index = load_texture_2D(_renderer, filepath.c_str());
//    }
//    if (material->GetTextureCount(aiTextureType_EMISSIVE) > 0)
//    {
//        material->GetTexture(aiTextureType_EMISSIVE, 0, &aiFilename);
//        std::string filename = aiFilename.C_Str();
//        std::string filepath = make_path(directory, filename);
//        myMaterial.emissive_texture_index = load_texture_2D(_renderer, filepath.c_str());
//    }
//    if (material->GetTextureCount(aiTextureType_SPECULAR) > 0)
//    {
//        material->GetTexture(aiTextureType_SPECULAR, 0, &aiFilename);
//        std::string filename = aiFilename.C_Str();
//        std::string filepath = make_path(directory, filename);
//        myMaterial.specular_texture_index = load_texture_2D(_renderer, filepath.c_str());
//    }
//    if (material->GetTextureCount(aiTextureType_NORMALS) > 0)
//    {
//        material->GetTexture(aiTextureType_NORMALS, 0, &aiFilename);
//        std::string filename = aiFilename.C_Str();
//        std::string filepath = make_path(directory, filename);
//        myMaterial.normals_texture_index = load_texture_2D(_renderer, filepath.c_str());
//    }
//    if (material->GetTextureCount(aiTextureType_HEIGHT) > 0)
//    {
//        material->GetTexture(aiTextureType_HEIGHT, 0, &aiFilename);
//        std::string filename = aiFilename.C_Str();
//        std::string filepath = make_path(directory, filename);
//        myMaterial.bump_texture_index = load_texture_2D(_renderer, filepath.c_str());
//    }
//
//    //myMaterial.createNormalFromBump();
//}

void process_assimp_node(const aiScene* scene, aiNode* node, Mesh* myMesh, unsigned int baseMeshMaterialIndex, std::vector<unsigned int>& submeshMaterialIndices)
{
    // process all the node's meshes (if any)
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        process_assimp_mesh(scene, mesh, myMesh, baseMeshMaterialIndex, submeshMaterialIndices);
    }

    // then do the same for each of its children
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        process_assimp_node(scene, node->mChildren[i], myMesh, baseMeshMaterialIndex, submeshMaterialIndices);
    }
}

//unsigned int load_model(Resources* _resources, const char* _file_name)
//{
//    const aiScene* scene = aiImportFile(_file_name,
//        aiProcess_Triangulate |
//        aiProcess_GenSmoothNormals |
//        aiProcess_CalcTangentSpace |
//        aiProcess_JoinIdenticalVertices |
//        aiProcess_PreTransformVertices |
//        aiProcess_ImproveCacheLocality |
//        aiProcess_OptimizeMeshes |
//        aiProcess_SortByPType);
//
//    if (!scene)
//    {
//        LOG("Error loading mesh %s: %s", _file_name, aiGetErrorString());
//        return UINT32_MAX;
//    }
//
//    _resources->meshes.push_back(Mesh{});
//    Mesh& mesh = _resources->meshes.back();
//    unsigned int mesh_index = (unsigned int)_resources->meshes.size() - 1u;
//
//    _resources->models.push_back(Model{});
//    Model& model = _resources->models.back();
//    model.mesh_index = mesh_index;
//    model.name = get_filepath_name(_file_name);
//    unsigned int modelIdx = (unsigned int)_resources->models.size() - 1u;
//
//    std::string directory = get_directory_part(_file_name);
//
//    // Create a list of materials
//    unsigned int baseMeshMaterialIndex = (unsigned int)_resources->materials.size();
//    for (unsigned int i = 0; i < scene->mNumMaterials; ++i)
//    {
//        _resources->materials.push_back(Material{});
//        Material& material = _resources->materials.back();
//        process_assimp_material(_resources, scene->mMaterials[i], material, directory);
//    }
//
//    process_assimp_node(scene, scene->mRootNode, &mesh, baseMeshMaterialIndex, model.material_index);
//
//    aiReleaseImport(scene);
//
//    unsigned int vertexBufferSize = 0;
//    unsigned int indexBufferSize = 0;
//
//    for (unsigned int i = 0; i < mesh.submeshes.size(); ++i)
//    {
//        vertexBufferSize += mesh.submeshes[i].vertices.size() * sizeof(float);
//        indexBufferSize += mesh.submeshes[i].indices.size() * sizeof(unsigned int);
//    }
//
//    /*glGenBuffers(1, &mesh.vertex_buffer_handle);
//    glBindBuffer(GL_ARRAY_BUFFER, mesh.vertex_buffer_handle);
//    glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, NULL, GL_STATIC_DRAW);
//
//    glGenBuffers(1, &mesh.index_buffer_handle);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.index_buffer_handle);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBufferSize, NULL, GL_STATIC_DRAW);*/
//
//    unsigned int indicesOffset = 0;
//    unsigned int verticesOffset = 0;
//
//    for (unsigned int i = 0; i < mesh.submeshes.size(); ++i)
//    {
//        const void* verticesData = mesh.submeshes[i].vertices.data();
//        const unsigned int   verticesSize = mesh.submeshes[i].vertices.size() * sizeof(float);
//        //glBufferSubData(GL_ARRAY_BUFFER, verticesOffset, verticesSize, verticesData);
//        mesh.submeshes[i].vertex_offset = verticesOffset;
//        verticesOffset += verticesSize;
//
//        const void* indicesData = mesh.submeshes[i].indices.data();
//        const unsigned int   indicesSize = mesh.submeshes[i].indices.size() * sizeof(unsigned int);
//        //glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, indicesOffset, indicesSize, indicesData);
//        mesh.submeshes[i].index_offset = indicesOffset;
//        indicesOffset += indicesSize;
//    }
//
//    /*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);*/
//
//
//    return modelIdx;
//}

unsigned int load_texture_2D(Resources* _resources, const char* _file_path)
{
    for (unsigned int texIdx = 0; texIdx < _resources->textures.size(); ++texIdx)
        if (_resources->textures[texIdx].filepath == _file_path)
            return texIdx;

    Image image = load_image(_file_path);

    if (image.pixels)
    {
        Texture tex = {};
        tex.handle = create_texture_2D_from_image(image);
        tex.filepath = _file_path;

        unsigned int texIdx = _resources->textures.size();
        _resources->textures.push_back(tex);

        free_image(image);
        return texIdx;
    }
    else
    {
        return UINT32_MAX;
    }
}

GLuint create_texture_2D_from_image(Image _image)
{
    GLenum internalFormat = GL_RGB8;
    GLenum dataFormat = GL_RGB;
    GLenum dataType = GL_UNSIGNED_BYTE;

    switch (_image.nchannels)
    {
    case 3: dataFormat = GL_RGB; internalFormat = GL_RGB8; break;
    case 4: dataFormat = GL_RGBA; internalFormat = GL_RGBA8; break;
    default: LOG("LoadTexture2D() - Unsupported number of channels");
    }

    /*GLuint texHandle;
    glGenTextures(1, &texHandle);
    glBindTexture(GL_TEXTURE_2D, texHandle);
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, _image.size.x, _image.size.y, 0, dataFormat, dataType, _image.pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);*/

    return 0;
}

Image load_image(const char* _file_name)
{
    Image img = {};
    stbi_set_flip_vertically_on_load(true);
    img.pixels = stbi_load(_file_name, &img.size.x, &img.size.y, &img.nchannels, 0);
    if (img.pixels)
    {
        img.stride = img.size.x * img.nchannels;
    }
    else
    {
        LOG("Could not open file %s", _file_name);
    }
    return img;
}

void free_image(Image image)
{
    stbi_image_free(image.pixels);
}