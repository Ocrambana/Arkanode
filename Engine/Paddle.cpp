#include "Paddle.h"

Paddle::Paddle(const Vector2 & pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos{pos_in},
	halfWidth{halfWidth_in},
	halfHeight{halfHeight_in}
{}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetRect(), color);
}

void Paddle::Update(float dt, const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	if (GetRect().IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF & walls)
{
	const float	leftBorder{ pos.x - halfWidth },
				rightBorder{ pos.x + halfWidth };


	if (leftBorder < walls.left)
	{
		pos.x += walls.left - leftBorder;
	}
	else if (rightBorder > walls.right)
	{
		pos.x -= rightBorder - walls.right;
	}

}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeight);
}
