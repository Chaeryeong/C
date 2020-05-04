#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void drawDice(int _i, int _number)
{
	switch (_i)
	{
	case 1:
		printf("┌───┐");
		break;
	case 2:
		switch (_number)
		{
		case 0:
			printf("│      │");
			break;
		case 1:
		case 2:
			printf("│      │");
			break;
		case 3:
			printf("│    ●│");
			break;
		case 4:
		case 5:
		case 6:
			printf("│●  ●│");
			break;
		}
		break;
	case 3:
		switch (_number)
		{
		case 0:
			printf("│      │");
			break;
		case 1:
		case 3:
		case 5:
			printf("│  ●  │");
			break;
		case 2:
		case 6:
			printf("│●  ●│");
			break;
		case 4:
			printf("│      │");
			break;
		}
		break;
	case 4:
		switch (_number)
		{
		case 0:
			printf("│      │");
			break;
		case 1:
		case 2:
			printf("│      │");
			break;
		case 3:
			printf("│●    │");
			break;
		case 4:
		case 5:
		case 6:
			printf("│●  ●│");
			break;
		}
		break;
	case 5:
		printf("└───┘");
		break;
	}
}

void dice_1(int num1)
{
	int i;
	for (i = 1; i <= 5; i++)
	{
		drawDice(i, num1);
		printf("\n");
	}
}

void dice_2(int num1, int num2)
{
	int i;
	for (i = 1; i <= 5; i++)
	{
		drawDice(i, num1);
		drawDice(i, num2);
		printf("\n");
	}
}

void dice_3(int num1, int num2, int num3)
{
	int i;
	for (i = 1; i <= 5; i++)
	{
		drawDice(i, num1);
		drawDice(i, num2);
		drawDice(i, num3);
		printf("\n");
	}
}

int main(void)
{
	int current = 100000;
	int point = 0;
	int num, computersum = 0, sumofmine = 0, bettingmoney;
	int computer[3] = { 0, };
	int mine[3] = { 0, };
	int wincnt = 0, losecnt = 0;
	char type;
	int whattodochoice;

	srand(time(NULL));

main_menu:; 

	system("cls");
	printf("1. My State \n");
	printf("2. Dice Rolling Game \n");
	printf("3. End \n\n");

	printf("Enter your choice: ");
	scanf_s("%d", &num);
	getchar();
	printf("\n");

	while ((num < 1) || (num > 3))
	{
		printf("Enter your choice: ");
		scanf_s("%d", &num);
		getchar();
	}
	
	if (current <= 0 && num != 3)
	{
		system("cls");
		printf("You have no left cash. \n");
		printf("Game Over \nType any key to go mainmenu\n");
		getch();
		goto main_menu;//어떤 키 누르더라도 메인메뉴, 끝 안내면 게임 진행 안되게
	}
	
	while (1)  
	{
		if (num == 1)
		{
			system("cls");
			printf("Current cash: %d \n", current);
			printf("Wins: %d \n", wincnt);
			printf("Loses: %d \n", losecnt);

			printf("\n");
			printf("Type any key to go to main menu ...");
			printf("\n");
			getch();
			system("cls");
			goto main_menu;
		}
		else if (num == 2)
		{
			computersum = 0;
			for (int i = 1; i <= 3; i++)
			{
				computer[i] = (rand() % 6) + 1;
				computersum += computer[i];
			}

		Playing:; 
			system("cls");
			printf("Current cash: %d \n", current);
			printf("\n");
			printf("Sum of computer's dices: %d \n", computersum);
			printf("\n");
			printf("Input your betting: ");
			scanf_s("%d", &bettingmoney);

			while (bettingmoney > current)
			{
				printf("Your betting is larger than your current cash. \n");
				printf("Input your betting: ");
				scanf_s("%d", &bettingmoney);
			}
			system("cls");

			printf("Computer's dice total is %d. \n", computersum);
			printf("┌───┐┌───┐┌───┐\n");
			printf("│      ││      ││      │\n");
			printf("│      ││      ││      │\n");
			printf("│      ││      ││      │\n");
			printf("└───┘└───┘└───┘\n");

			while (1) 
			{
				sumofmine = 0;
				for (int j = 1; j <= 3; j++)
				{
					mine[j] = (rand() % 6) + 1;
					sumofmine += mine[j];
				}
				if (computersum == sumofmine)
					break;

			}


			dice_3(mine[1], mine[2], mine[3]);

			printf("Type ESC to Start Game \n");
			printf("Type s to Surrender \n");
			printf("Any key. Rolling dice again \n");


			type = getch();
			switch (type)
			{
			case 's': //surrender 실행창 다시 보기
				current -= 5000;
				losecnt++;
				goto Playing;

				break;

			/*	printf("You surrender. \n");
				printf("You lose 5000 cash. \n");
				current -= 5000;
				losecnt++; 

				system("cls");

				printf("1. Retry \n");
				printf("2. Back to main menu \n");

				printf("Your choice: ");
				scanf("%d", &whattodochoice);
				while ((num < 1) || (num > 2))
				{
					printf("Your choice: ");
					scanf_s("%d", &num);
				}

				if (whattodochoice == 1)
				{
					system("cls");
					goto Playing;
				}
				else if (whattodochoice == 2)
				{
					system("cls");
					goto main_menu;
				}

				break;
				*/

			case 27: //27은 ESC
				system("cls");
				printf("Stage 1 \n");
				dice_1(computer[1]);
				dice_1(mine[1]);
				Sleep(1000);
				if (computer[1] >= mine[1])
				{
					printf("Computer Win \n");
				}
				else
				{
					printf("User Win \n");
					point++;
				}
				Sleep(1000);

				system("cls");

				printf("Stage 2 \n");
				dice_2(computer[1], computer[2]);
				dice_2(mine[1], mine[2]);
				Sleep(1000);
				if (computer[2] >= mine[2])
				{
					printf("Computer Win \n");
				}
				else
				{
					printf("User Win \n");
					point++;
				}
				Sleep(1000);

				system("cls");
				printf("Stage 3 \n");
				dice_3(computer[1], computer[2], computer[3]);
				dice_3(mine[1], mine[2], mine[3]);
				Sleep(1000);
				if (computer[3] >= mine[3])
				{
					printf("Computer Win \n");
				}
				else
				{
					printf("User Win \n");
					point++;
				}
				Sleep(1000);

				if (point >= 2)
				{
					printf("Final Winner: User!! \n");
					wincnt++;
					current += (bettingmoney) * 2;
				}
				else
				{
					printf("Final Winner: Computer!! \n");
					losecnt++;
					current -= bettingmoney;
				}
				printf("1. Retry \n");
				printf("2. Back to main menu \n");

				printf("Your choice: ");
				scanf("%d", &whattodochoice);
				while ((num < 1) || (num > 2))
				{
					printf("Your choice: ");
					scanf_s("%d", &num);
				}

				if (current <= 0)
				{
					system("cls");
					printf("You have no left cash. \n");
					printf("Game Over \nType any key to go mainmenu\n");
					getch();
					goto main_menu;//어떤 키 누르더라도 메인메뉴, 끝 안내면 게임 진행 안되게
				}

				if (whattodochoice == 1)
				{
					system("cls");
					goto Playing;
				}
				else if (whattodochoice == 2)
				{
					system("cls");
					goto main_menu;
				}

				break;

			default:
				system("cls");

				printf("Computer's dice total is %d. \n", computersum);
				printf("┌───┐┌───┐┌───┐\n");
				printf("│      ││      ││      │\n");
				printf("│      ││      ││      │\n");
				printf("│      ││      ││      │\n");
				printf("└───┘└───┘└───┘\n");

				while (1)
				{
					sumofmine = 0;
					for (int j = 1; j <= 3; j++)
					{
						mine[j] = (rand() % 6) + 1;
						sumofmine += mine[j];
					}
					if (computersum == sumofmine)
						break;

				}

				dice_3(mine[1], mine[2], mine[3]);

				printf("Type ESC to Start Game \n");
				printf("Type s to Surrender \n");
				printf("Any key. Rolling dice again \n");
				while (1)
				{
					type = getch();
					switch (type)
					{
					case 's': //surrender again
						current -= 5000;
						goto Playing;

						break;

						/*
						printf("You surrender. \n");
						printf("You lose 5000 cash. \n");
						current = current - 5000;
						losecnt++;

						system("cls");

						printf("1. Retry \n");
						printf("2. Back to main menu \n");

						printf("Your choice: ");
						scanf("%d", &whattodochoice);
						while ((num < 1) || (num > 2))
						{
							printf("Your choice: ");
							scanf_s("%d", &num);
						}

						if (whattodochoice == 1)
						{
							system("cls");
							goto Playing;
						}
						else if (whattodochoice == 2)
						{
							system("cls");
							goto main_menu;
						}

						break;
						*/

					case 27:
						system("cls");
						point = 0;
						printf("Stage 1 \n");
						dice_1(computer[1]);
						dice_1(mine[1]);
						Sleep(1000);
						if (computer[1] >= mine[1])
						{
							printf("Computer Win \n");
						}
						else
						{
							printf("User Win \n");
							point++;
						}
						Sleep(1000);

						system("cls");

						printf("Stage 2 \n");
						dice_2(computer[1], computer[2]);
						dice_2(mine[1], mine[2]);
						Sleep(1000);
						if (computer[2] >= mine[2])
						{
							printf("Computer Win \n");
						}
						else
						{
							printf("User Win \n");
							point++;
						}
						Sleep(1000);

						system("cls");
						printf("Stage 3 \n");
						dice_3(computer[1], computer[2], computer[3]);
						dice_3(mine[1], mine[2], mine[3]);
						Sleep(1000);
						if (computer[3] >= mine[3])
						{
							printf("Computer Win \n");
						}
						else
						{
							printf("User Win \n");
							point++;
						}
						Sleep(1000);

						if (point >= 2)
						{
							printf("Final Winner: User!! \n");
							wincnt++;
							current += (bettingmoney) * 2;
						}
						else
						{
							printf("Final Winner: Computer!! \n");
							losecnt++;
							current -= bettingmoney;
						}
						printf("1. Retry \n");
						printf("2. Back to main menu \n");

						printf("Your choice: ");
						scanf("%d", &whattodochoice);
						while ((num < 1) || (num > 2))
						{
							printf("Your choice: ");
							scanf_s("%d", &num);
						}

						if (whattodochoice == 1)
						{
							system("cls");
							goto Playing;
						}
						else if (whattodochoice == 2)
						{
							system("cls");
							goto main_menu;
						}

						break;

					default:
						system("cls");

						printf("Computer's dice total is %d. \n", computersum);
						printf("┌───┐┌───┐┌───┐\n");
						printf("│      ││      ││      │\n");
						printf("│      ││      ││      │\n");
						printf("│      ││      ││      │\n");
						printf("└───┘└───┘└───┘\n");

						while (1)
						{
							sumofmine = 0;
							for (int j = 1; j <= 3; j++)
							{
								mine[j] = (rand() % 6) + 1;
								sumofmine += mine[j];
							}
							if (computersum == sumofmine)
								break;

						}

						dice_3(mine[1], mine[2], mine[3]);

						printf("Type ESC to Start Game \n");
						printf("Type s to Surrender \n");
						printf("Any key. Rolling dice again \n");
						break;

					}

				}
				break;

			}

			printf("");

		}
		else if (num == 3)
			exit(0);
	}

	/*if (current <= 0)
	{
		printf("You have no left cash. \n");
		printf("Game Over \n");
		getch();
		goto main_menu;//어떤 키 누르더라도 메인메뉴, 끝 안내면 게임 진행 안되게
	}*/
	return 0;
}