/*
 * Christopher Bennett
 * Classic Pong Game
*/


#include "raylib.h"


using namespace std;


class Ball
{
	public:
		float 
			y
			,x
			,rad = 5
			,speedX = 300
			,speedY = 300;
};

class Player
{
	public:
		float
			width = 10
			,hieght = 100
			,x
			,y
			,speed = 300
			,score = 0;
};

class ScoreBoard
{
	int 
		left = 0
		,right = 0;
};


int main()
{
	//cout << "We Ball\n";
	
	InitWindow(1000, 800, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	Ball ball; ball.y = GetScreenHeight() / 2; ball.x = GetScreenWidth() / 2;
	Player P1; P1.x = 50; P1.y = (GetScreenHeight() / 2) - P1.width;
	Player P2; P2.x = GetScreenWidth() - 50; P2.y = (GetScreenHeight() / 2) - P2.width;


	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(10,10);

			DrawCircle(ball.x, ball.y, ball.rad, RED);
			DrawRectangle(P1.x, P1.y, P1.width, P1.hieght, BLUE);
			DrawRectangle(P2.x, P2.y, P2.width, P2.hieght, BLUE);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
