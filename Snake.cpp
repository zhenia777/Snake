#include "Snake.h"

void SetUp(bool& gameOver, Board& board, Point* snake, TypeMove& move, Point& fruit, int& score)
{
	//srand(time(NULL));
	gameOver = false;

	score = 0;

	move = TypeMove::STOP;

	board.length = 20;
	board.wight = 50;

	snake->x = board.wight / 2;
	snake->y = board.length / 2;

	fruit.x = rand() % board.wight;
	fruit.y = rand() % board.length;
}
void Drow(const Board& board, const Point& snake, Point& fruit, Point tail[], int& n, int& score)
{
	Sleep(100);
	system("cls");
	for (int i = 0; i < board.wight; i++)
	{
		cout << '#';
	}
	cout << endl;
	for (int i = 0; i < board.length; i++)
	{
		for (int j = 0; j < board.wight; j++) {
			if (j == 0 || j == board.wight - 1)
			{
				cout << '#';
			}
			else if (snake.x == j && snake.y == i)
			{
				cout << '0';
			}
			else if (fruit.x == j && fruit.y == i)
			{
				cout << 'F';
			}
			else
			{
				bool print = true;

				for (int t = 0; t < n; t++)
				{
					if (tail[t].x == j && tail[t].y == i)
					{
						cout << 'o';
						print = false;
					}
				}

				if (print)
					cout << ' ';
			}
		}
		cout << endl;
	}

	for (int i = 0; i < board.wight; i++)
	{
		cout << '#';
	}
	cout << endl;
	cout << "Score: " << score;
}
void Input(TypeMove& move)
{
	if (_kbhit()) {
		// wdsa
		switch (_getch())
		{
		case 'w':
			move = TypeMove::UP;
			break;
		case 's':
			move = TypeMove::DOWN;
			break;
		case 'd':
			move = TypeMove::RIGHT;
			break;
		case 'a':
			move = TypeMove::LEFT;
			break;
		}
	}
}
void Logic(const Board& board, TypeMove& move, Point& snake, Point& fruit, Point tail[], int& n, int& score)
{
	switch (move)
	{
	case UP:
		snake.y--;
		break;
	case DOWN:
		snake.y++;
		break;
	case RIGHT:
		snake.x++;
		break;
	case LEFT:
		snake.x--;
		break;
	case STOP:
		break;
	}


	Point tempPrev = tail[0];
	Point prev2;
	tail[0] = snake;
	for (int i = 1; i < n; i++)
	{
		prev2 = tail[i];
		tail[i] = tempPrev;
		tempPrev = prev2;
	}


	if (fruit.x == snake.x && fruit.y == snake.y)
	{

		fruit.x = rand() % board.wight;
		fruit.y = rand() % board.length;
		score += 10;
		n++;
	}
}

