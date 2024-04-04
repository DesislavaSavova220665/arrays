#pragma once
#include "template.h"
#include "surface.h"

class Tank
{
public:
	Tank(const Tmpl8::vec2& pos, const Tmpl8::vec2& dir = Tmpl8::vec2(0)) :
		pos(pos),
		dir(dir),
		tank(new Tmpl8::Surface("assets/ctankbase.tga"), 16)
	{}

	void move(float x, float y)
	{
		pos.x += x;
		pos.y += y;

		dir.x = x;
		dir.y = y;
	}

	void setPos(const Tmpl8::vec2& newPos)
	{
		pos = newPos;
	}

	const Tmpl8::vec2& getPos() const
	{
		return pos;
	}

	void draw(Tmpl8::Surface* surface,  const Tmpl8::vec2& camera )
	{
		tank.Draw(surface, static_cast<int>(pos.x - camera.x), static_cast<int>(pos.y - camera.y));
	}

private: 
	//tank position
	Tmpl8::vec2 pos;
	Tmpl8::vec2 dir;
	Tmpl8::Sprite tank;
};