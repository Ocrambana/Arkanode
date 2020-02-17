#pragma once

#include "Vector2.h"
#include "Graphics.h"
enum CollisionResult {none, normal, bottom};

class Ball
{
public:
	Ball(Vector2 &initialPosition, Vector2 &initialSpeed);
	~Ball() = default;

	void Draw(Graphics &gfx) const;
	void Update(float deltaTime);
	CollisionResult DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	Vector2 GetVelocity() const;
	Vector2 GetPosition() const;
private:
	static constexpr float radius = 0.7f;
	Vector2 pos,
			vel;
	bool hasCollidedWithFloor = false;
};

