#include "Brick.h"

Brick::Brick(const RectF & inRect, Color inColor)
	:
	rect{inRect}, color{inColor}
{}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-padding),color);
	}
}

bool Brick::DoBallcollision(Ball & ball)
{
	if (!destroyed && rect.GetExpanded(-padding).IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}

	return false;
}
