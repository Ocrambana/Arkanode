#include "Paddle.h"

Paddle::Paddle(const Vector2 & pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos{pos_in},
	halfWidth{halfWidth_in},
	halfHeight{halfHeight_in}
{}

void Paddle::Draw(Graphics & gfx)
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect,color);
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

bool Paddle::DoBallCollision(Ball & ball)
{
	if (isCooldown) 
		return false;

	const RectF rect = GetRect();
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		const Vector2 ballPos = ball.GetPosition();
		if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x))
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
		isCooldown = true;
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

void Paddle::ResetCooldown()
{
	isCooldown = false;
}
