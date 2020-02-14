#include "RectF.h"

RectF::RectF(float inLeft, float inRight, float inTop, float inBottom)
	:
	left{inLeft}, right{inRight},top{inTop},bottom{inBottom}
{}

RectF::RectF(const Vector2 & topLeft, const Vector2 & bottomRight)
	:
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{}

RectF::RectF(const Vector2 & topLeft, float width, float height)
	:
	RectF(topLeft, topLeft + Vector2(width,height))
{
}

bool RectF::IsOverlappingWith(const RectF & other) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

RectF RectF::FromCenter(const Vector2 & center, float halfWidth, float halfHeight)
{
	const Vector2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

Vector2 RectF::GetCenter() const
{
	const float xVal{ (left + right) / 2 },
		yVal{ (top + bottom) / 2 };
	return Vector2(xVal, yVal);
}
