#include "tank.h"

//once and only once loaded and tka up storage for everything.
Tmpl8::Sprite Tank::tank(new Tmpl8::Surface("assets/ctankbase.tga"), 16);

Tank::tank(const Tmpl8::vec2 pos, float rotation) :
	pos(pos),
	angle(rotation)
{}

void Tank::move(float x, float y)
{
	pos.x += x;
	pos.y += y;

	//math to fixup angle.
	angle = atan2(y, x);
}

void Tank::drawCollider(Tmpl8::Surface* surface, const Tmpl8::vec2& camera)
{

}
