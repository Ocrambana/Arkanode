#pragma once
class Vector2
{
public:
	Vector2() = default;
	Vector2(float x, float y);
	~Vector2() = default;
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator-(const Vector2& rhs) const;
	Vector2 operator*(const float& rhs) const;
	friend Vector2 operator*(const float& lhs, const Vector2 rhs);
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	float GetSquareMagnitude() const;
	float GetMagnitude() const;
	float Distance(const Vector2& v1) const;
	Vector2 GetNormalized() const;
	Vector2& Normalize();
public:
	float x;
	float y;
};

