#pragma once

#include "Vector2.h"
#include "Graphics.h"

class LifeCounter
{
public:
	LifeCounter(Vector2 pos, int lives);
	bool ConsumeLife();
	void Draw(Graphics &gfx) const;
	void SetLives(int lives);
private:
	static constexpr float spacing = 5.0f;
	Vector2 position;
	int lives;
};

