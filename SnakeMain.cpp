#include"Snake.h"

Point fruit;
Point snake;
Board board;

int n = 1;
Point tail[10];

TypeMove move_;
int score;
bool gameOver;

int main()
{
	SetUp(gameOver, board, &snake, move_, fruit, score);


	while (!gameOver)//!false => true
	{
		Drow(board, snake, fruit, tail, n, score);
		Input(move_);
		Logic(board, move_, snake, fruit, tail, n, score);
	}

	return 0;
}