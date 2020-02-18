#pragma once

#include "Vector2.h"
#include "Graphics.h"
enum CollisionResult {none, normal, bottom};

class Ball
{
public:
	Ball(const Vector2 &initialPosition, Vector2 &dir_in);
	~Ball() = default;

	void Draw(Graphics &gfx) const;
	void Update(float deltaTime);
	CollisionResult DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vector2 GetVelocity() const;
	Vector2 GetPosition() const;
	void SetDirection(const Vector2 &dir);
private:
	static constexpr float radius = 0.7f;
	float speed = 400.0f;
	Vector2 pos,
			vel;
	bool hasCollidedWithFloor = false;
};

