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
			,height = 100
			,x
			,y
			,speed = 300
			,score = 0;

		//Paddles  Movement Up & Down
		void Up()
		{
			y -= speed * GetFrameTime();
		}
		void Down()
		{
			y += speed * GetFrameTime();
		}
		//stopping paddle from going off the screen
		void Stop()
		{
			if (y < GetScreenHeight() - 100){
				y += 5;
			}else if (y > 0){
				y -= 5;
			}
		}
		//Retuning Rectangle
		Rectangle GetRect()
		{
			return Rectangle{x - width / 2, y - height / 2, width, height};
		} 
		void Draw()
		{
			DrawRectangleRec(GetRect(), BLUE);
		}
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
	Player leftWall; leftWall.x = 0; leftWall.y = 0; leftWall.height = GetScreenHeight(); 
	Player rightWall; rightWall.x = GetScreenWidth() - rightWall.width; rightWall.y = 0; rightWall.height = GetScreenHeight(); 


	// Main Loop
	while (!WindowShouldClose())
	{
		//Initial Ball Movement 
		ball.x += ball.speedX * GetFrameTime();
		ball.y += ball.speedY * GetFrameTime();
	
		//Checking stopping ball from going off screen
		if (ball.x < 0){
			ball.speedX *= (-1);
		}else if (ball.x > GetScreenWidth()){
			ball.speedX *= (-1);
		}
		if (ball.y < 0){
			ball.speedY *= (-1);
		}else if (ball.y > GetScreenHeight()){
			ball.speedY *= (-1);
		}

		//Paddle movement P1 with W&S and P2 with Up&Down Keys
		//Player One
		if (IsKeyDown(KEY_W)){
				P1.Up();
		}else if (IsKeyDown(KEY_S)){
			P1.Down();
		}
		//Player Two
		if (IsKeyDown(KEY_UP)){
			P2.Up();
		}else if (IsKeyDown(KEY_DOWN)){
			P2.Down();
		}

		//Stopping Paddle from going off screen
		//Player One
		if (P1.y > GetScreenHeight() - P1.height){
			P1.Stop();
		}else if (P1.y < 0){
			P1.Stop();
		}
		//Player Two
		if (P2.y > GetScreenHeight() - P2.height){
			P2.Stop();
		}else if (P2.y < 0){
			P2.Stop();
		}
		
		//Checking Collisions 
		//Paddle One
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad,
					P1.GetRect())){
			if (ball.speedX < 0){
				ball.speedX *= (-1);
			}
		}
		//Paddle two
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad, 
					P2.GetRect())){
			if (ball.speedX > 0){
				ball.speedX *= (-1);
			}
		}
		//Left Wall
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad,
					leftWall.GetRect())){
			ball.x = (GetScreenWidth() / 2);
			ball.y = (GetScreenHeight() / 2);
			P2.score++;
		}
		//Right Wall
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad,
					rightWall.GetRect())){
			ball.x = (GetScreenWidth() / 2);
			ball.y = (GetScreenHeight() / 2);
			P1.score++;
		}
		//Drawing Window 
		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(10,10);

			DrawCircle(ball.x, ball.y, ball.rad, RED);
			DrawRectangle(P1.x, P1.y, P1.width, P1.height, BLUE);
			DrawRectangle(P2.x, P2.y, P2.width, P2.height, BLUE);
			DrawRectangle(leftWall.x, leftWall.y, leftWall.width, leftWall.height, WHITE);
			DrawRectangle(rightWall.x, rightWall.y, rightWall.width, rightWall.height, WHITE);
			
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
