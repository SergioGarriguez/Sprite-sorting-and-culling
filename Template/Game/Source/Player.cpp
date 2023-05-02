#include "Player.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include "Point.h"
#include "Scene.h"



Player::Player() : Entity(EntityType::PLAYER)
{
	name.Create("Player");

	// idle player
	idleanim.PushBack({ 0, 0, 32, 32 });
	//idleanim.loop = false;
	idleanim.speed = 0.0f;

}

Player::~Player() {

}

bool Player::Awake() {
	// Get Player parameters from XML
	position.x = parameters.attribute("x").as_int();
	position.y = parameters.attribute("y").as_int();
	texturePath = parameters.attribute("texturepath").as_string();

	return true;
}

bool Player::Start() {

	// initilize textures
	texture = app->tex->Load(texturePath);

	currentAnim = &idleanim;

	return true;
}

bool Player::Update()
{
	
	if ((app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT))
	{
		position.y --;
	}
	else if ((app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT))
	{
		position.y ++;
	}
	else if ((app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT))
	{
		position.x --;
	}
	else if ((app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT))
	{
		position.x ++;
	}
	
	

	SDL_Rect rect = currentAnim->GetCurrentFrame();
	
	//app->render->DrawTexture(texture, position.x, position.y, &rect);
	app->render->AddElementToQueue(texture, position.x, position.y, &rect, 1);
	currentAnim->Update();

	return true;
}

bool Player::PostUpdate() {

	return true;
}

bool Player::CleanUp()
{
	return true;
}
