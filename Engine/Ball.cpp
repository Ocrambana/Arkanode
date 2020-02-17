#include "Ball.h"

#include "SpriteCodex.h"

Ball::Ball(Vector2 & initialPosition, Vector2 & initialSpeed)
	:
	pos{initialPosition}, vel{initialSpeed}
{}

void Ball::Draw(Graphics &gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float deltaTime)
{
	pos += vel * deltaTime;
}

CollisionResult Ball::DoWallCollision(const RectF & walls)
{
	CollisionResult result = none;
	const RectF rect = GetRect();
	
	if (rect.left < walls.left) 
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		result = normal;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		result = normal;
	}

	if (rect.top < walls.top) 
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		result = normal;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		result = bottom;
		hasCollidedWithFloor = true;
	}

	return  result;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius * 10, radius * 10);
}

Vector2 Ball::GetVelocity() const
{
	return vel;
}

Vector2 Ball::GetPosition() const
{
	return pos;
}