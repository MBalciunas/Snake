#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <random>
#include <ctime>
#include <windows.h>

using namespace std;

class Map
{
public:
	Map();
	void Print();
	void SetMap();
	void Play();
	void Move();
	void FoodSpawn();
	void Eat();
	void TailMove();
	void CheckFood();
	bool Check();
	int GetScore() { return score; }

private:
	string map[17] =        { { "##############################" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "#                            #" },
							{ "##############################" } };

	int snakeX;
	int snakeY;
	vector<int> snakeTailX;
	vector<int> snakeTailY;
	vector<int> tailDistance;
	char move = 'd';
	int foodX;
	int foodY;
	int score;
	int speed;
	int level;
	int oldSnakeX;
	int oldSnakeY;
	char oldMove;
	int difficulty;
};