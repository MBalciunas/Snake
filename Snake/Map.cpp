#include "Map.h"


Map::Map()
{
	snakeX = 5;
	snakeY = 5;
	foodX = 7;
	foodY = 7;
	score = 0;
	map[foodX][foodY] = 'f';
	printf("Welcome to Snake!\nSelect difficulty:\n1.Easy\n2.Medium\n3.Hard\n");
	cin >> difficulty;
	switch (difficulty) {
	case 1:
		speed = 70;
		break;
	case 2:
		speed = 40;
		break;
	case 3:
		speed = 15;
		break;
	default:
		speed = 70;
		break;
	}
}

void Map::Print() {

	system("cls");

	for (int i = 0; i < 17; i++) {
			printf("%s\n", map[i].c_str());
		}
	printf("Score: %d\n", score);
	
	
}

void Map::SetMap() {
	int i = 0, j = 0;
	map[snakeY][snakeX] = 'O';
	for (int i = 0; i < snakeTailY.size(); i++) {
	map[snakeTailY[i]][snakeTailX[i]] = 'o';
	}
}

void Map::Play() {
	while (true) {
		Sleep(speed);
		SetMap();
		if (!Check()) break;
		CheckFood();
		Print();
		Move();
		if (!Check()) break;	
	}

}

void Map::Move() {

	if (snakeTailX.size() == 0) map[snakeY][snakeX] = ' ';

	oldMove = move;
	oldSnakeX = snakeX;
	oldSnakeY = snakeY;
	if (_kbhit()) {
		move = _getch();
		if ((oldMove == 'w' && move == 's') || (oldMove == 's' && move == 'w') ||
			(oldMove == 'a' && move == 'd') || (oldMove == 'd' && move == 'a') || move == oldMove) move = oldMove;
		else {
			for (int i = 1; i < snakeTailY.size(); i++) {
				tailDistance[i] = i;
			}
			if (move == 'w' || move == 's') speed += 40;
			else speed -= 40;
		}
	}
	switch (move) {
	case 'w':
		snakeY--;
		break;
	case 's':
		snakeY++;
		break;
	case 'a':
		snakeX--;
		break;
	case 'd':
		snakeX++;
		break;
	default:
		snakeX++;
		break;
	}
	TailMove();

	if (map[snakeY][snakeX] == 'f') {
		Eat();
		FoodSpawn();
	}

	}


bool Map::Check() {
	if (map[snakeY][snakeX] == '#' || map[snakeY][snakeX] == 'o') {
		return false;
	}
	return true;
}

void Map::FoodSpawn() {

	while (true) {
		static default_random_engine randomEngine(time(NULL));
		uniform_int_distribution<int> foodX(1, 15);
		uniform_int_distribution<int> foodY(1, 28);

		if (map[foodX(randomEngine)][foodY(randomEngine)] != 'O' && map[foodX(randomEngine)][foodY(randomEngine)] != 'o' &&
			map[foodX(randomEngine)][foodY(randomEngine)] != '#') {
			map[foodX(randomEngine)][foodY(randomEngine)] = 'f';
			break;
		}
	}
}

void Map::Eat() {
	snakeTailX.push_back(oldSnakeX);
	snakeTailY.push_back(oldSnakeY);
	tailDistance.push_back(0);
	score += 20;
}

void Map::TailMove() {
	for (int i = 0; i < snakeTailY.size(); i++) {
		map[snakeTailY[i]][snakeTailX[i]] = ' ';
	}
	for (int i = snakeTailY.size() - 1; i > 0; i--) {
		snakeTailX[i] = snakeTailX[i - 1];
		snakeTailY[i] = snakeTailY[i - 1];
	}

	if (snakeTailX.size() > 0) {
		snakeTailY[0] = oldSnakeY;
		snakeTailX[0] = oldSnakeX;

	}
}

void Map::CheckFood() {
	bool foodIs = false;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 17; j++) {
			if (map[j][i] == 'f') foodIs = true;
		}
	}
	if (!foodIs) FoodSpawn();
}
