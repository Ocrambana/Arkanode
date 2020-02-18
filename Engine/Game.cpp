/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Vector2.h"
#include <algorithm>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vector2(300.0f, 300.0f), Vector2(-1.0f, -1.0f)),
	walls(RectF::FromCenter(Graphics::GetScreenRect().GetCenter(), fieldWidth / 2.0f, fieldHeight / 2.0f),
		wallThickness, wallColor),
	paddle(Vector2(400.0f,560.0f),30.0f,5.0f, 3)
{
	const Color colors[4] = {Colors::Red, Colors::Green, Colors::Cyan, Colors::Yellow};
	const Vector2 topLeft(walls.GetInnerBounds().left, walls.GetInnerBounds().top + 40.0f);
	
	for (int j{ 0 }; j < nBricksDown; j++)
	{
		const Color c = colors[j];
		
		for (int i{ 0 }; i < nBricksAcross; i++)
		{
			const RectF rect(topLeft + Vector2(i*brickWidth, j*brickHeight), brickWidth, brickHeight);
			bricks[j * nBricksAcross + i] = Brick(rect, c);			
		} 
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}

	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float deltaTime)
{
	if (isGameOver)
	{

	}
	else
	{
		ball.Update(deltaTime);
		CollisionResult res = ball.DoWallCollision(walls.GetInnerBounds());

		if (res != none)
		{
			paddle.ResetCooldown();
		}
	
		if (res == bottom)
		{
			paddle.LoseLife();
			isGameOver = paddle.IsGameOver();
		}

		DoBricksCollision();

		paddle.Update(deltaTime, wnd.kbd);
		paddle.DoWallCollision(walls.GetInnerBounds());
		paddle.DoBallCollision(ball);
	}
}

void Game::DoBricksCollision()
{
	bool isCollisionHappened{ false };
	float currentCollisionDistanceSquared;
	int currentCollisionIndex;
	for (int i{ 0 }; i < nBricks; i++)
	{
		if (bricks[i].CheckBallCollision(ball))
		{
			const float newCollisionDistance = (bricks[i].GetCenter() - ball.GetPosition()).GetSquareMagnitude();

			if (isCollisionHappened)
			{
				if (currentCollisionDistanceSquared > newCollisionDistance)
				{
					currentCollisionDistanceSquared = newCollisionDistance;
					currentCollisionIndex = i;
				}
			}
			else
			{
				currentCollisionDistanceSquared = newCollisionDistance;
				currentCollisionIndex = i;
				isCollisionHappened = true;
			}
		}
	}

	if (isCollisionHappened)
	{
		paddle.ResetCooldown();
		bricks[currentCollisionIndex].ExecuteBallcollision(ball);
	}
}

void Game::DrawWalls()
{
	const RectF wallsRect = walls.GetInnerBounds(),
			border = wallsRect.GetExpanded(static_cast<float>(wallsBorder));

	for (int j = static_cast<int>(border.top); j <= border.bottom; j++)
		for (int i = static_cast<int>(border.left); i <= border.right; i++)
		{
			const bool condition = (i < wallsRect.left || i > wallsRect.right || j > wallsRect.bottom || j < wallsRect.top);

			if (condition)
			{
				gfx.PutPixel(i, j, Colors::White);
			}
		}
}

void Game::ComposeFrame()
{
	if (isGameOver)
	{

	}
	else
	{
		ball.Draw(gfx);
		paddle.Draw(gfx);
		const Vector2 bottomLeft(5.0f, 15.0f);
		paddle.DrawLifes(bottomLeft, gfx);
	}

	DrawWalls();
	std::for_each(std::begin(bricks), std::end(bricks), [this](Brick &b) {b.Draw(this->gfx); });
}
