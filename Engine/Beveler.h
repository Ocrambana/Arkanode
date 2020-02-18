#pragma once

#include "Graphics.h"
#include "RectF.h"

class Beveler
{
public:
	Beveler() = default;
	Beveler(Color baseColor);
	void DrawOuterBevel(const RectF& rect, int size, Graphics & gfx) const;
	void DrawInnerBevel(const RectF& rect, int size, Graphics & gfx) const;
	void DrawBeveledBrick(const RectF& rect, int bevelSize, Graphics & gfx) const;
	void DrawBevelFrame(const RectF& rect, int bevelSize, Graphics & gfx) const;
	Color GetBaseColor() const;
	void SetBaseColor(Color base);
private:
	static constexpr float	leftFactor = 1.10f,
							topFactor = 0.93f,
							bottomFactor = 0.80f,
							rightFactor = 0.65f;
	Color	baseColor,
			topColor,
			bottomColor,
			leftColor,
			rightColor;
};

