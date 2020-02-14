#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include "Vector2.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& inRect, Color inColor);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const  Ball& ball) const;
	void ExecuteBallcollision(Ball &ball);
	Vector2 GetCenter() const;
private:
	static constexpr float padding = 1.0f;
	RectF rect;
	Color color;
	bool destroyed{ false };
};

