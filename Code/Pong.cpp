/*
 * Christopher Bennett
 * Classic Pong Game
*/


#include "raylib.h"


using namespace std;


int main()
{
	//cout << "We Ball\n";
	
	InitWindow(1000, 800, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(10,10);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
