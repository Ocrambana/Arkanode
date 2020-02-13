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
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
private:
	Color color = Colors::White;
	float	halfWidth,
			halfHeight,
			speed{ 300.0f };
	Vector2 pos;
};
