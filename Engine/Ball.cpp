#include "Ball.h"

Ball::Ball(Vector2 & initialPosition, Vector2 & initialSpeed)
	:
	pos{initialPosition}, vel{initialSpeed}
{}

void Ball::Draw(Graphics &gfx) const
{
	gfx.DrawCircle(pos, radius, Colors::White);
}

void Ball::Update(float deltaTime)
{
	pos += vel * deltaTime;
}
