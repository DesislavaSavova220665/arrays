#pragma once

#include "template.h"
#include "surface.h"

class Tank
{
public:
	Tank(const Tmpl8::vec2& pos, float rotation = 0.0f);

	void move(float x, float y);

	void setPos(const Tmpl8::vec2& newPos);
	
	const Tmpl8::vec2& getPos() const;

	void draw(Tmpl8::Surface* surface, const Tmpl8::vec2& camera);

	void drawCollider(Tmpl8::Surface* surface, const Tmpl8::vec2& camera);
	
private:
	//tank position
	Tmpl8::vec2 pos;
	float angle;
	//all tanks get this sprite
	static Tmpl8::Sprite tank;
};
 
inline const Tmpl8::vec2& Tank::getPos()const
{

	return pos;

}


inline void Tank::draw(Tmpl8::Surface* surface, const Tmpl8::vec2& camera)
{
	tank.Draw(surface, static_cast<int>(pos.x - camera.x), static_cast<int>(pos.y - camera.y));
	

}