#pragma once

#include "Ball.h"
#include "Vector2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vector2 &pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx);
	void Update(float dt, const Keyboard& kbd);
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	void ResetCooldown();
private:
	static constexpr float wingWidth = 10.0f;
	Color	color = Colors::White,
			wingColor = Colors::Red;
	float	halfWidth,
			halfHeight,
			speed{ 300.0f };
	Vector2 pos;
	bool isCooldown = false;
};

