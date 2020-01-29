#include "Brick.h"

Brick::Brick(const RectF & inRect, Color inColor)
	:
	rect{inRect}, color{inColor}
{}

void Brick::Draw(Graphics & gfx) const
{
	gfx.DrawRect(rect,color);
}
