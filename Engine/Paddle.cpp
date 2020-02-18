#include "Paddle.h"

Paddle::Paddle(const Vector2 & pos_in, float halfWidth_in, float halfHeight_in)
	:
	pos{pos_in},
	halfWidth{halfWidth_in},
	halfHeight{halfHeight_in},
	exitXFactor(maximumExitRatio / halfWidth),
	fixedZoneHalfWitdth(halfWidth * fixedZoneWidthRatio),
	fixedZoneExitX(fixedZoneHalfWitdth * exitXFactor)
{}

void Paddle::Draw(Graphics & gfx) const
{
	RectF rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);
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
		const bool hasToReboundY =	std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x) ||
								(ballPos.x >= rect.left && ballPos.x <= rect.right);
		if (hasToReboundY)
		{
			Vector2 direction;
			const float xDifference = ballPos.x - pos.x;
			if (std::abs(xDifference) < fixedZoneHalfWitdth)
			{
				if (xDifference < 0.0f)
				{
					direction = Vector2(-fixedZoneExitX,-1.0f);
				}
				else
				{
					direction = Vector2(fixedZoneExitX, -1.0f);
				}
			}
			else
			{
				direction = Vector2(xDifference * exitFactor, -1.0f);
			}
			ball.SetDirection(direction);
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

void Paddle::SetPosition(const Vector2 & pos)
{
	this->pos = pos;
}
