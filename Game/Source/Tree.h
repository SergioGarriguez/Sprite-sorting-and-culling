#ifndef __TREE_H__
#define __TREE_H__

#include "Entity.h"
#include "Point.h"
#include "Animation.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Tree : public Entity
{
public:

	Tree();
	virtual ~Tree();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();

	SDL_Rect boundaries;

	int npcid;

private:

	SDL_Texture* texture;
	const char* texturePath;

	Animation NPCAnim;
};

#endif // __TREE_H__