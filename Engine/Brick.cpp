#include "Brick.h"
#include <assert.h>

Brick::Brick(const RectF & inRect, Color inColor)
	:
	rect{inRect}, 
	beveler{inColor},
	destroyed(false)
{}

void Brick::Draw(Graphics & gfx) const
{
	if (!destroyed)
	{
		beveler.DrawBeveledBrick(rect.GetExpanded(-padding),bevelSize, gfx);
	}
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !destroyed && rect.GetExpanded(-padding).IsOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallcollision(Ball & ball)
{
	assert(CheckBallCollision(ball));

	const Vector2 ballPos = ball.GetPosition();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x > rect.left && ballPos.x < rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}

	destroyed = true;
}

Vector2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
