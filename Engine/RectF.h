#pragma once

#include "Vector2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float inLeft, float inRight, float inTop, float inBottom);
	RectF(const Vector2& topLeft, const Vector2& bottomRight);
	RectF(const Vector2& topLeft, float width, float height);
	bool IsOverlappingWith(const RectF& other) const;

public:
	float	left,
			right,
			top,
			bottom;
};

