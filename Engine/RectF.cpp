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
