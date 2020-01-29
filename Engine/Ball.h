#pragma once

#include "Vector2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(Vector2 &initialPosition, Vector2 &initialSpeed);
	~Ball() = default;

	void Draw(Graphics &gfx) const;
	void Update(float deltaTime);
private:
	static constexpr float radius = 0.7f;
	Vector2 pos,
			vel;
};

