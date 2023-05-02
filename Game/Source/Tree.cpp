#include "Tree.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include "Point.h"

Tree::Tree() : Entity(EntityType::ITEM)
{
	name.Create("Tree");
}

Tree::~Tree() {}

bool Tree::Awake() {

	position.x = parameters.attribute("x").as_int();
	position.y = parameters.attribute("y").as_int();
	texturePath = parameters.attribute("texturepath").as_string();
	

	return true;
}

bool Tree::Start() {

	// initilize textures
	texture = app->tex->Load(texturePath);

	return true;
}

bool Tree::Update()
{

	
	SDL_Rect rect = NPCAnim.GetCurrentFrame();
	//app->render->DrawTexture(texture, position.x, position.y, &rect);
	app->render->AddElementToQueue(texture, position.x, position.y, &rect, 1);
	

	return true;
}

bool Tree::CleanUp()
{
	return true;
}