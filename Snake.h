#pragma once
#include <iostream>
#include <conio.h>
#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Board {
	int length;
	int wight;
};

enum TypeMove
{
	UP, DOWN, RIGHT, LEFT, STOP
};

void SetUp(bool& gameOver, Board& board, Point* snake, TypeMove& move, Point& fruit, int& score);
void Drow(const Board& board, const Point& snake, Point& fruit, Point tail[], int& n, int& score);
void Input(TypeMove& snake);
void Logic(const Board& board, TypeMove& move, Point& snake, Point& fruit, Point tail[], int& n, int& score);