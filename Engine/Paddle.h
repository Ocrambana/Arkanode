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
	Paddle(const Vector2 &pos_in, float halfWidth_in, float halfHeight_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt, const Keyboard& kbd);
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
	RectF GetRect() const;
	void ResetCooldown();
	void SetPosition(const Vector2 &pos);
private:
	static constexpr float	wingWidth = 5.0f,
							exitFactor = 0.045f,
							speed = 350.0f,
							maximumExitRatio = 2.6f,
							fixedZoneWidthRatio = 0.2f;

	static constexpr Color	color = Colors::White,
							wingColor = Colors::Red;
	float	halfWidth,
			halfHeight,
			exitXFactor,
			fixedZoneHalfWitdth,
			fixedZoneExitX;
	Vector2 pos;
	bool isCooldown = false;
};

