#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float x, float y)
	:
	x{x},y{y}
{}

Vector2 Vector2::operator+(const Vector2 & rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2 & rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float & rhs) const
{
	return Vector2(x * rhs, y * rhs);
}

Vector2 & Vector2::operator+=(const Vector2 & rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & rhs)
{
	*this = *this - rhs;
	return *this;
}

float Vector2::GetSquareMagnitude() const
{
	return x * x + y * y;
}

float Vector2::GetMagnitude() const
{
	return std::sqrt(GetSquareMagnitude());
}

float Vector2::Distance(const Vector2 & v1) const
{
	return (v1 - *this).GetMagnitude();
}

Vector2 Vector2::GetNormalized() const
{
	const float magnitude = GetMagnitude();
	if (magnitude != 0)
	{
		return *this * (1.0f / magnitude);
	}
	return *this;
}

Vector2 & Vector2::Normalize()
{
	return *this = GetNormalized();
}

Vector2 operator*(const float& lhs, const Vector2 rhs)
{
	return rhs * lhs;
}
