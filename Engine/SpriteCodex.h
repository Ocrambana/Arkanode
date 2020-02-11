#pragma once

#include "Graphics.h"
#include "Vector2.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall(const Vector2& center, Graphics& gfx);
	// centered drawing of 200x160 sprite
	static void DrawTitle(const Vector2& center, Graphics& gfx);
	// centered drawing of 84x64 sprite
	static void SpriteCodex::DrawGameOver(const Vector2& center, Graphics& gfx);
	// centered drawing of 104x19 sprite
	static void SpriteCodex::DrawReady(const Vector2& center, Graphics& gfx);
	// centered drawing of 24x24 sprite
	static void SpriteCodex::DrawPoo(const Vector2& center, Graphics& gfx);
};