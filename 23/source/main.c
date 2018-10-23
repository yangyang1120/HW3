#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum Status { CONTINUE, WON, LOST };
int rollDice(void);

int main(void)
{
	int sum;
	int myPoint;
	enum Status gameStatus;
	srand(time(NULL));
	sum = rollDice();

	switch (sum)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;
		myPoint = sum;
		printf("Point i %d\n", myPoint);
		break;
	}
	while (gameStatus == CONTINUE)
	{
		sum = rollDice();
		if (sum == myPoint)
		{
			gameStatus = WON;
		}
		else
		{
			if (sum == 7)
			{
				gameStatus = LOST;
			} 
		}
	}
	if (gameStatus = WON)
	{
		printf("Player wins\n");
	}
	else
	{
		printf("Player loses\n");
	}
	system("pause");
	return 0;
}
int rollDice(void)
{
	int d1;
	int d2;
	int wo;

	d1 = 1 + (rand() % 6);
	d2= 1 + (rand() % 6);
	wo = d1 + d2;
	printf("Player rolled %d+%d=%d\n", d1, d2, wo);
	return wo;
}