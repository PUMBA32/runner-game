#include <stdio.h>		
#include <stdbool.h>	
#include <conio.h>		
#include <stdlib.h>		
#include <windows.h>		


#define SPACE	'w'
#define EXIT	'q'

int main(void)
{
	const int width = 50, height = 6;			
	int enemyPosX = width + 1, enemyPosY = 5;	
	int x = 15, y = 5;							
	int score = 0, life = 3;
	bool GameOver = false;

	while (!GameOver)
	{
		system("cls");
		for (int i = 0; i < width + 1; printf("#"), i++) {}	
		printf("\n");
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (j == 0 || j == width - 1)				
					printf("#");
				if (j == x && i == y)						
					printf("0");
				else if (j == enemyPosX && i == enemyPosY)	
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
		for (int i = 0; i < width + 1; printf("#"), i++) {}	
		printf("\n");
		printf("\tScore - %d\t\tLife - %d\n", score, life);
		printf("\t\tPRESS 'Q' TO EXIT\n");

		if (!(y == height - 1))
			y++;

		enemyPosX--;

		if (enemyPosX < 0)
			enemyPosX = width + 1;

		if (enemyPosX == 0)
			score++;

		if (life <= 0)
			GameOver = true;

		if (enemyPosX == x && enemyPosY == y)
			life--;

		if (_kbhit()) {
			switch (_getch())
			{
			case SPACE:
				if (y == 5)
					y -= 5;
				break;
			case EXIT:
				GameOver = true;
				break;
			}
		}
	}
	printf("\n\n\t\t   <GAME OVER>\n\n");
	return 0;
}