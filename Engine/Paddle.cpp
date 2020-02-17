#include "Paddle.h"

Paddle::Paddle(const Vector2 & pos_in, float halfWidth_in, float halfHeight_in, int lives)
	:
	pos{pos_in},
	halfWidth{halfWidth_in},
	halfHeight{halfHeight_in},
	lifes{lives}
{}

void Paddle::Draw(Graphics & gfx) const
{
	DrawPaddle(GetRect(), 1.0f, gfx);
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

void Paddle::LoseLife()
{
	lifes--;
}

bool Paddle::IsGameOver() const
{
	return lifes == 0;
}

void Paddle::DrawLifes(Vector2 bottomLeft, Graphics & gfx) const
{
	const float lifeScale = 3;
	const int padding = 2;
	const RectF rect = GetRect();
	const float width = (rect.right - rect.left) / lifeScale,
				height = (rect.bottom - rect.top) / lifeScale;
	bottomLeft.x += padding * 2;
	RectF lifeRect(bottomLeft, width, height);

	for (int i{ 0 }; i < lifes; i++)
	{
		DrawPaddle(lifeRect, lifeScale, gfx);
		lifeRect.left = lifeRect.right + padding;
		lifeRect.right += padding + width;
	}
}

void Paddle::DrawPaddle(RectF rect, float scale, Graphics & gfx) const
{
	if (scale < 0.0001f)
		scale = 0.0001f;

	rect.left += wingWidth / scale;
	rect.right -= wingWidth / scale;

	const float yCenter = rect.GetCenter().y;
	const Vector2 leftWingCenter(rect.left, yCenter);
	gfx.DrawCircle(leftWingCenter, wingWidth / scale, wingColor);
	const Vector2 rightWingCenter(rect.right, yCenter);
	gfx.DrawCircle(rightWingCenter, wingWidth / scale, wingColor);

	gfx.DrawRect(rect, color);
}
