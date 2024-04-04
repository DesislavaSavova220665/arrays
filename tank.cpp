#include "tank.h"


Tank::tank(const Tmpl8::vec2 pos, float rotation) :
	pos(pos),
	angle(rotation),
	tank(new Tmpl8::Surface("assets/ctankbase.tga"), 16)
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
	// TODO:
}
