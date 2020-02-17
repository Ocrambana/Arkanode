#pragma once

#include "Ball.h"
#include "Vector2.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle(const Vector2 &pos_in, float halfWidth_in, float halfHeight_in, int lives);
	void Draw(Graphics& gfx) const;
	void Update(float dt, const Keyboard& kbd);
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	void ResetCooldown();
	void LoseLife();
	bool IsGameOver() const;
	void DrawLifes(Vector2 bottomLeft ,Graphics &gfx) const;
private:
	void DrawPaddle(RectF rect, float scale, Graphics& gfx) const;
private:
	static constexpr float wingWidth = 10.0f;
	Color	color = Colors::White,
			wingColor = Colors::Red;
	float	halfWidth,
			halfHeight,
			speed{ 300.0f };
	Vector2 pos;
	bool isCooldown = false;
	int lifes;
};

