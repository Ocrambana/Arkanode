#include "LifeCounter.h"
#include <algorithm>

LifeCounter::LifeCounter(Vector2 pos, int lives)
	:
	position{pos},
	lives{lives}
{}

bool LifeCounter::ConsumeLife()
{
	const bool hasLife = lives > 0;
	lives = std::max(lives - 1, 0);
	return hasLife;
}

void LifeCounter::Draw(Graphics & gfx) const
{
	const float width = 22.0f,
				height = 12.0f;
	RectF rect (position, width, height);

	for (int i{ 0 }; i < lives; i++)
	{
		gfx.DrawRect(rect.GetExpanded(-2), Colors::White);
		rect.left += width + spacing;
		rect.right += width + spacing;
	}
}

void LifeCounter::SetLives(int lives)
{
	this->lives = lives;
}

