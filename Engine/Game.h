/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Walls.h"
#include "LifeCounter.h"

enum GameState 
{
	Starting,
	Running,
	GameOver,
	Reset
};

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float deltaTime);
	void DoBricksCollision();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTimer ft;
	/********************************/
	/*  User Variables              */
	static constexpr int	nBricksAcross = 13,
							nBricksDown = 4,
							nBricks = nBricksAcross * nBricksDown,
							wallsBorder = 5;
	
	static constexpr float	brickWidth = 40.0f,
							brickHeight = 22.0f,
							wallThickness = 12.0f,
							fieldWidth = float(nBricksAcross) * brickWidth,
							fieldHeight = float(Graphics::ScreenHeight) - wallThickness * 2.0f,
							cooldownTime = 1.6f;
	
	static constexpr Color wallColor = { 20,60,200 };

	Ball ball;
	Walls walls;
	Brick bricks[nBricks];
	Paddle paddle;
	GameState gameState = Starting;
	LifeCounter lives;
	float resetTime = 0.0f;
	/********************************/
};