#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#define MAX_OBJECTS 1024

struct Scene;

struct ObjectData
{
	float posx[MAX_OBJECTS];				// Objects position
	float posy[MAX_OBJECTS];
	float posz[MAX_OBJECTS];


	float velx[MAX_OBJECTS];				// Objects velocity
	float vely[MAX_OBJECTS];
	float velz[MAX_OBJECTS];

	int	deleting_indexes[MAX_OBJECTS];

	void create_objects();

	void apply_transform(float dt);
	void objects_to_delete();
	void re_create_objects(Scene* _scene);

	Scene* scene_ref;
};

struct Scene
{
	ObjectData* objects;

	unsigned long long total_created;
	unsigned long long total_destroyed;
};

void create_scene(Scene* _scene);
void update_scene(Scene* _scene, float dt);
void destroy_scene(Scene* _scene);


#endif // !__SCENE_H__