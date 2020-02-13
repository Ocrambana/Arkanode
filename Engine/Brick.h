#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& inRect, Color inColor);
	void Draw(Graphics& gfx) const;
	bool DoBallcollision(Ball &ball);
private:
	RectF rect;
	Color color;
	bool destroyed{ false };
};

