#pragma once

#include <xmmintrin.h>  // Streaming SIMD Extension

#include "memleak.h"
#include "utils.h"

#include "scene.h"

void create_scene(Scene* _scene)
{
	_scene->objects = DBG_NEW ObjectData;
	_scene->objects->scene_ref = _scene;
	_scene->total_created = _scene->total_destroyed = 0;
	_scene->objects->create_objects();
}

void update_scene(Scene* _scene, float dt)
{
	_scene->objects->apply_transform(dt);
	_scene->objects->objects_to_delete();
	_scene->objects->re_create_objects(_scene);
}

void destroy_scene(Scene* _scene)
{

	RELEASE(_scene->objects);
}

void ObjectData::create_objects()
{
	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		posx[i] = 0.F;
		posy[i] = 0.F;
		posz[i] = 0.F;

		velx[i] = (((rand() - (RAND_MAX / 2)) % 10));
		vely[i] = (((rand() - (RAND_MAX / 2)) % 10));
		velz[i] = (((rand() - (RAND_MAX / 2)) % 10));
	}

	scene_ref->total_created = MAX_OBJECTS;
}

void ObjectData::apply_transform(float dt)
{
	__m128 delta = _mm_setr_ps(dt, dt, dt, dt);		// Save delta time for all 4 simultaneous operations

	__m128* px = (__m128*) posx;					// Set polsition pointers
	__m128* py = (__m128*) posy;
	__m128* pz = (__m128*) posz;
	__m128* vx = (__m128*) velx;					// Set velocity pointers
	__m128* vy = (__m128*) vely;
	__m128* vz = (__m128*) velz;

	int total_iterations = MAX_OBJECTS / 4;
	for (int i = 0; i < total_iterations; ++i)
	{
		__m128 dx = _mm_mul_ps(vx[i], delta);		// Calculate distance traveled
		__m128 dy = _mm_mul_ps(vy[i], delta);
		__m128 dz = _mm_mul_ps(vz[i], delta);

		__m128 nx = _mm_add_ps(px[i], dx);			// Calculate new position
		__m128 ny = _mm_add_ps(py[i], dy);
		__m128 nz = _mm_add_ps(pz[i], dz);

		_mm_store_ps((float*)(px + i), nx);			// Save new position
		_mm_store_ps((float*)(py + i), ny);
		_mm_store_ps((float*)(pz + i), nz);
	}
}

void ObjectData::objects_to_delete()
{
	int index = 0;
	bool aux;
	memset(deleting_indexes, 0, sizeof(int) * MAX_OBJECTS);
	for (int i = 0; i < MAX_OBJECTS; ++i)
	{
		aux = (velx[i] == 0 && vely[i] == 0 && velz[i] == 0);
		if (abs(posx[i]) > 10 || abs(posy[i]) > 10 || abs(posy[i]) > 10 || aux)
		{
			deleting_indexes[index++] = i;
		}
	}
	deleting_indexes[index] = -1;
}

void ObjectData::re_create_objects(Scene* _scene)
{
	int i = 0, index, created = 0, destroyed = 0;
	while (deleting_indexes[i] != -1)
	{
		index = deleting_indexes[i];
		posx[index] = 0.F;
		posy[index] = 0.F;
		posz[index] = 0.F;

		velx[index] = (((rand() - (RAND_MAX / 2)) % 10));
		vely[index] = (((rand() - (RAND_MAX / 2)) % 10));
		velz[index] = (((rand() - (RAND_MAX / 2)) % 10));

		destroyed++;
		created++;

		i++;
	}

	_scene->total_created += created;
	_scene->total_destroyed += destroyed;
}