#ifndef __RENDER_H__
#define __RENDER_H__

#include "Module.h"

#include <queue>
#include <memory>

#include "Point.h"

#include "SDL/include/SDL.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	SDL_Texture* texture = NULL;
	int x = 0, y = 0, layer = 0;
	const SDL_Rect* section = NULL;

};

class CompareSprites
{
public:
	bool operator()(const std::shared_ptr<Sprite> sprite1, const std::shared_ptr<Sprite> sprite2)
	{
		if (sprite1->layer > sprite2->layer)
		{
			return true;
		}
		else if (sprite1->layer == sprite2->layer && sprite1->y + sprite1->section->h < sprite2->y + sprite2->section->h)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};


class Render : public Module
{
public:

	

	Render(bool startEnabled);

	// Destructor
	virtual ~Render();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void SetViewPort(const SDL_Rect& rect);
	void ResetViewPort();

	// Drawing
	bool DrawTexture(SDL_Texture* texture, int x, int y, const SDL_Rect* section = NULL, float speed = 1.0f, double angle = 0, int pivotX = INT_MAX, int pivotY = INT_MAX) const;
	bool DrawRectangle(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool filled = true, bool useCamera = true) const;
	bool DrawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool useCamera = true) const;
	bool DrawCircle(int x1, int y1, int redius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255, bool useCamera = true) const;

	// Set background color
	void SetBackgroundColor(SDL_Color color);

	void AddElementToQueue(SDL_Texture* texture, int x, int y, const SDL_Rect* section = NULL, int layer = 0);
	void DrawQueue(std::priority_queue<std::shared_ptr<Sprite>, std::vector<std::shared_ptr<Sprite>>, CompareSprites>& spriteQueue_);

public:

	std::vector<std::shared_ptr<Sprite>> sprites;
	std::priority_queue< std::shared_ptr<Sprite>, std::vector<std::shared_ptr<Sprite>>, CompareSprites> spriteQueue;

	SDL_Renderer* renderer;
	SDL_Rect camera;
	SDL_Rect viewport;
	SDL_Color background;
};

#endif // __RENDER_H__