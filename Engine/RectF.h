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
	static RectF FromCenter(const Vector2& center, float halfWidth, float halfHeight);
	RectF GetExpanded(float offset) const;
	Vector2 GetCenter() const;
public:
	float	left,
			right,
			top,
			bottom;
};

