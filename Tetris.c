#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

//1P 방향키
#define W 87 
#define w 119
#define A 65
#define a 97
#define S 83
#define s 115
#define D 68
#define d 100

//2P 방향키
#define LEFT 75		// Keyboard Input
#define RIGHT 77 
#define UP 72 
#define DOWN 80 

//1P 2P 아이템 M F fm
#define M 77 //P2
#define m 109
#define F 70 //P1
#define f 102

//멈춤, 탈출 키
#define p 112
#define P 80 
#define ESC 27  

#define false 0
#define true 1

#define ACTIVE_BLOCK -2 // Block State
#define CEILLING -1      
#define EMPTY 0         
#define WALL 1
#define INACTIVE_BLOCK 2 

#define MAIN_X 11	// Game borad Size
#define MAIN_Y 23 
#define MAIN_X_ADJ 3 
#define MAIN_Y_ADJ 1  

#define STATUS_X_ADJ MAIN_X_ADJ+MAIN_X+1 // Status info position

FILE *ptr;
int STATUS_Y_GOAL; // Status info position

int STATUS_Y_SCORE;

int blocks[7][4][4][4] = {
	{ { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 } },
	{ { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0 } },
	{ { 0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0 },{ 0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0 },{ 0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0 } }
}; // Shape of block

int b_type; // block type
int b_rotation; // block rotation
int b_type_next; //new block

int main_org[MAIN_Y][MAIN_X];
int main_cpy[MAIN_Y][MAIN_X];

int bx, by; // x,y position of moving block

int key; // keyboard input 

int speed; // Game Speed 

int score_P1; // Game Score
int score_P2;
int item_P1;
int item_P2;
int item_P1_A;
int item_P2_A;
int turn = 1;
int turn_who = 1;
int item_flag = 0;

int new_block_on = 0;
int crush_on = 0;
int sit = 0;


void title(void);
void reset(void);
void reset_main(void); // 
void reset_main_cpy(void);
void draw_map(void);
void draw_main(void);
void new_block(void);
void check_key(void);

int check_crush(int bx, int by, int rotation);
void drop_block(void);
void move_block(int dir);
void check_line(void);

void check_game_over(void);
void pause(void);
void use_item(void);

void setcolor(unsigned short text, unsigned short back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void blockcolor(int check) {
	if (check == 1) {
		setcolor(2, 0);
	}
	if (check == 2) {
		setcolor(9, 0);
	}
}

//아이템 함수 어케 만드냐 ㅠㅠ

void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; // hide cursor
void setcursortype(CURSOR_TYPE c) { // hide cursor
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int main() {
	int i;
	
	srand((unsigned)time(NULL));
	setcursortype(NOCURSOR);
	title();
	reset();

	while (1) {
		for (i = 0; i<5; i++) {
			check_key();
			draw_main();

			Sleep(speed);
			if (crush_on&&check_crush(bx, by + 1, b_rotation) == false) Sleep(100);
		}
		drop_block();

		check_game_over();
		if (new_block_on == 1) {
			new_block();
			item_flag = 0;
		}
		if (turn == 61)		check_game_over();
	}
}

void title(void) {
	int x = 5;
	int y = 4;


	gotoxy(x, y + 0); printf("┌─────────────┐");
	gotoxy(x, y + 1); printf("│                          │");
	gotoxy(x, y + 2); printf("│                          │");
	gotoxy(x, y + 3); printf("│                          │");
	gotoxy(x, y + 4); printf("└─────────────┘");

	gotoxy(x + 5, y + 2); printf("T E T R I S");
	gotoxy(x, y + 7); printf("Please Enter Any Key to Start..");
	//Key for P1 표기
	gotoxy(x, y + 9); printf("<P1>");
	gotoxy(x, y + 11); printf("  W   : Shift");
	gotoxy(x, y + 12); printf("A   D : Left / Right");
	gotoxy(x, y + 13); printf("  S   : Drop");
	gotoxy(x, y + 15); printf("F : Item");
	setcolor(2, 0);
	gotoxy(x, y + 16); printf("color : ■ ");
	setcolor(7, 0);
	//Key for P2 표기
	gotoxy(x + 15, y + 9); printf("<P2>");
	gotoxy(x + 15, y + 11); printf("  △   : Shift");
	gotoxy(x + 15, y + 12); printf("◁  ▷ : Left / Right");
	gotoxy(x + 15, y + 13); printf("  ▽   : Drop");
	gotoxy(x + 15, y + 15); printf("M : Item");
	setcolor(9, 0);
	gotoxy(x + 15, y + 16); printf("color : ■ ");
	setcolor(7, 0);
	//다른 키 표시
	gotoxy(x + 7, y + 18); printf("   P   : Pause");
	gotoxy(x + 7, y + 19); printf("  ESC  : Quit");

	while (true) {
		if (kbhit()) break;
	}

	while (kbhit()) getch();

}

void reset(void) {
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);

	if ((ptr = fopen("log.txt", "a")) == NULL) {
		printf("File could not be opened\n");
		return -1;
	}
	else
	{
		fprintf(ptr, "\nStart at %d-%d-%d %d:%d:%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	}
	fclose(ptr);

	score_P1 = 0;
	score_P2 = 0;
	item_P1 = 0;
	item_P2 = 0;
	item_P1_A = 0;
	item_P2_A = 0;
	key = 0;
	crush_on = 0;
	sit = 0;

	speed = 100;

	system("cls");
	reset_main();
	draw_map();
	draw_main();

	b_type_next = rand() % 7;
	new_block();

}

void reset_main(void) {
	int i, j;

	for (i = 0; i<MAIN_Y; i++) { // Game board initialize
		for (j = 0; j<MAIN_X; j++) {
			main_org[i][j] = 0;
			main_cpy[i][j] = 100;
		}
	}
	for (j = 1; j<MAIN_X; j++) {
		main_org[3][j] = CEILLING;
	}
	for (i = 1; i<MAIN_Y - 1; i++) {
		main_org[i][0] = WALL;
		main_org[i][MAIN_X - 1] = WALL;
	}
	for (j = 0; j<MAIN_X; j++) {
		main_org[MAIN_Y - 1][j] = WALL;
	}
}

void reset_main_cpy(void) {
	int i, j;

	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			main_cpy[i][j] = 100;
		}
	}
}

void draw_map(void) { // Game Status 
	int y = 3;

	gotoxy(STATUS_X_ADJ, y); printf("P%d's Turn (%d/60)", turn_who, turn);
	gotoxy(STATUS_X_ADJ, y + 2); printf("+-  N E X T  -+ ");
	gotoxy(STATUS_X_ADJ, y + 3); printf("|             | ");
	gotoxy(STATUS_X_ADJ, y + 4); printf("|             | ");
	gotoxy(STATUS_X_ADJ, y + 5); printf("|             | ");
	gotoxy(STATUS_X_ADJ, y + 6); printf("|             | ");
	gotoxy(STATUS_X_ADJ, y + 7); printf("+-- -  -  - --+ ");

	gotoxy(STATUS_X_ADJ, y + 15); printf("  △   : Shift        ");
	gotoxy(STATUS_X_ADJ, y + 16); printf("◁  ▷ : Left / Right   P   : Pause");
	gotoxy(STATUS_X_ADJ, y + 17); printf("  ▽   : Soft Drop     ESC  : Quit");

	gotoxy(STATUS_X_ADJ + 12, y + 2); printf("SCORE \t ITEM");
	gotoxy(STATUS_X_ADJ + 12, y + 4);  printf("P1 : %d \t %d", score_P1, item_P1);
	gotoxy(STATUS_X_ADJ + 12, y + 6); printf("P2 : %d \t %d", score_P2, item_P2);

}

void draw_main(void) {
	int i, j;

	for (j = 1; j<MAIN_X - 1; j++) {
		if (main_org[3][j] == EMPTY) main_org[3][j] = CEILLING;
	}
	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			if (main_cpy[i][j] != main_org[i][j]) {

				gotoxy(MAIN_X_ADJ + j, MAIN_Y_ADJ + i);
				switch (main_org[i][j]) {
				case EMPTY:
					printf("  ");
					break;
				case CEILLING:
					printf(". ");
					break;
				case WALL:
					printf("▩");
					break;
				case INACTIVE_BLOCK:
					printf("□");
					break;
				case ACTIVE_BLOCK:
					blockcolor(turn_who);
					printf("■");
					setcolor(7, 0);
					break;
				}
			}
		}
	}
	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			main_cpy[i][j] = main_org[i][j];
		}
	}
}

void new_block(void) {
	int i, j;
	if (sit)		use_item();
	sit = 0;

	bx = (MAIN_X / 2) - 1;
	by = 0;
	b_type = b_type_next;
	b_type_next = rand() % 7;
	b_rotation = 0;

	new_block_on = 0;

	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
		}
	}
	for (i = 1; i<3; i++) {
		for (j = 0; j<4; j++) {
			if (blocks[b_type_next][0][i][j] == 1) {
				gotoxy(STATUS_X_ADJ + 2 + j, i + 6);
				int check;
				if (turn_who == 1)
					check = 2;
				if (turn_who == 2)
					check = 1;
				blockcolor(check);
				printf("■");
				setcolor(7, 0);
			}
			else {
				gotoxy(STATUS_X_ADJ + 2 + j, i + 6);
				printf("  ");
			}
		}
	}
}

void check_key(void) {
	key = 0;
	int x = 5, y = 5;
	if (kbhit()) {
		key = getch();
		if (key == 224) { // direction key
			do { key = getch(); } while (key == 224);
			switch (key) {
			case LEFT:
				if (turn_who == 1)
					break;
				if (check_crush(bx - 1, by, b_rotation) == true) move_block(LEFT);
				break;
			case RIGHT:
				if (turn_who == 1)
					break;
				if (check_crush(bx + 1, by, b_rotation) == true) move_block(RIGHT);
				break;
			case DOWN:
				if (turn_who == 1)
					break;
				if (check_crush(bx, by + 1, b_rotation) == true) move_block(DOWN);
				break;
			case UP:
				if (turn_who == 1)
					break;
				if (check_crush(bx, by, (b_rotation + 1) % 4) == true) move_block(UP);

				else if (crush_on == 1 && check_crush(bx, by - 1, (b_rotation + 1) % 4) == true) move_block(100);
			}
		}
		else { // Not direction eky
			switch (key) {

			case A:
			case a:
				if (turn_who == 2)
					break;
				else if (check_crush(bx - 1, by, b_rotation) == true) move_block(LEFT);
				break;
			case D:
			case d:
				if (turn_who == 2)
					break;
				else if (check_crush(bx + 1, by, b_rotation) == true) move_block(RIGHT);
				break;
			case S:
			case s:
				if (turn_who == 2)
					break;
				else if (check_crush(bx, by + 1, b_rotation) == true) move_block(DOWN);
				break;
			case W:
			case w:
				if (turn_who == 2)
					break;
				else if (check_crush(bx, by, (b_rotation + 1) % 4) == true) move_block(UP);

				else if (crush_on == 1 && check_crush(bx, by - 1, (b_rotation + 1) % 4) == true) move_block(100);
				break;
				// 아이템
			case F: //P1 아이템
			case f:
				//P1이 P2의 차례에서 아이템 사용시 **
				if (turn_who == 2 && item_P1>0 && item_flag == 0) {
					item_P1--;
					sit = 3;
					item_flag = 1;
				}
				//P1이 자기 차례에서 아이템 사용시**
				if (turn_who == 1 && item_P1>0 && item_flag == 0) {
					item_P1--;
					sit = 1;
					item_flag = 1;
				}
				break;

			case M: //P2 아이템
			case m:
				//P2이 P1의 차례에서 아이템 사용시 **
				if (turn_who == 1 && item_P2>0 && item_flag == 0) {
					item_P2--;
					sit = 2;
					item_flag = 1;
				}
				//P2이 자기 차례에서 아이템 사용시**
				if (turn_who == 2 && item_P2>0 && item_flag == 0) {
					item_P2--;
					sit = 4;
					item_flag = 1;
				}
				break;

			case P:
			case p:
				pause();
				break;

			case ESC :
				setcolor(7, 0);
				system("cls");
				if ((ptr = fopen("log.txt", "a")) == NULL) {
					printf("File could not be opened\n");
					return -1;
				}
				else
				{
					fprintf(ptr, "ESC는 기록이 없습니다.\n");
				}
				fclose(ptr);
				exit(0);
			}
		}
	}
	while (kbhit()) getch();
}

int check_crush(int bx, int by, int b_rotation) {
	int i, j;

	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) {
			if (blocks[b_type][b_rotation][i][j] == 1 && main_org[by + i][bx + j]>0) return false;
		}
	}
	return true;

};

void drop_block(void) {
	int i, j;

	if (crush_on&&check_crush(bx, by + 1, b_rotation) == true) crush_on = 0;
	if (crush_on&&check_crush(bx, by + 1, b_rotation) == false) {
		for (i = 0; i<MAIN_Y; i++) {
			for (j = 0; j<MAIN_X; j++) {
				if (main_org[i][j] == ACTIVE_BLOCK) main_org[i][j] = INACTIVE_BLOCK;
			}
		}
		crush_on = 0;
		check_line();
		new_block_on = 1;
		return;
	}
	if (check_crush(bx, by + 1, b_rotation) == true) move_block(DOWN);
	if (check_crush(bx, by + 1, b_rotation) == false) crush_on++;
}

void move_block(int dir) {
	int i, j;

	switch (dir) {
	case LEFT:
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j - 1] = ACTIVE_BLOCK;
			}
		}
		bx--;
		break;

	case RIGHT:
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j + 1] = ACTIVE_BLOCK;
			}
		}
		bx++;
		break;

	case DOWN:
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i + 1][bx + j] = ACTIVE_BLOCK;
			}
		}
		by++;
		break;

	case UP:
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
			}
		}
		b_rotation = (b_rotation + 1) % 4;
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
			}
		}
		break;

	case 10:

		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
			}
		}
		b_rotation = (b_rotation + 1) % 4;
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i - 1][bx + j] = ACTIVE_BLOCK;
			}
		}
		by--;
		break;
	}
}

void check_line(void) {
	int i, j, k, l;
	int combo = 0; //New***
	int block_amount; // block num of one line


	for (i = MAIN_Y - 2; i>3;) {

		block_amount = 0;
		for (j = 1; j<MAIN_X - 1; j++) {
			if (main_org[i][j]>0) block_amount++;
		}
		if (block_amount == MAIN_X - 2) {

			if (turn_who == 1)
				score_P1 += 1;
			if (turn_who == 2)
				score_P2 += 1;

			for (k = i; k>1; k--) {  // Block Down
				for (l = 1; l<MAIN_X - 1; l++) {
					if (main_org[k - 1][l] != CEILLING) main_org[k][l] = main_org[k - 1][l];
					if (main_org[k - 1][l] == CEILLING) main_org[k][l] = EMPTY;

				}
			}
			combo++;
		}
		else i--; //한줄도 안사라질 떄
	} //어디다 점수 초기화 해야지??****
	  //New *-item giving
	if (combo >= 2) {
		if (turn_who == 1) {
			item_P1++;
			item_P1_A++;
		}
		if (turn_who == 2) {
			item_P2++;
			item_P2_A++;
		}
	}
	turn++;
	switch (turn_who) {
	case 1:
		turn_who = 2;
		break;
	case 2:
		turn_who = 1;
		break;
	}

	int y = 3;
	gotoxy(STATUS_X_ADJ + 12, y + 2); printf("SCORE \t ITEM");
	gotoxy(STATUS_X_ADJ + 12, y + 4);  printf("P1 : %d \t %d", score_P1, item_P1);
	gotoxy(STATUS_X_ADJ + 12, y + 6); printf("P2 : %d \t %d", score_P2, item_P2);
	gotoxy(STATUS_X_ADJ, y); printf("P%d's Turn (%d/60)", turn_who, turn);

}

void check_game_over(void) {
	int i;

	int x = 5;
	int y = 5;
	int winner;

	for (i = 1; i<MAIN_X - 2; i++) {
		if (main_org[3][i]>0 || turn == 3) {  // end condition 

			if (score_P1 > score_P2)
				winner = 1;
			else if (score_P1 < score_P2)
				winner = 2;
			else if (score_P1 == score_P2)
				winner = 0;

			gotoxy(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
			gotoxy(x, y + 1); printf("▤                              ▤");
			gotoxy(x, y + 2); printf("▤  +-----------------------+   ▤");
			gotoxy(x, y + 3); printf("▤  |  G A M E  O V E R..   |   ▤");
			gotoxy(x, y + 4); printf("▤  +-----------------------+   ▤");
			gotoxy(x, y + 5); printf("▤   P1 & P2 SCORE: %d %d         ▤", score_P1, score_P2);
			gotoxy(x, y + 6); printf("▤         Winner : %d           ▤", winner);
			gotoxy(x, y + 7); printf("▤  Press any key to restart..  ▤");
			gotoxy(x, y + 8); printf("▤                              ▤");
			gotoxy(x, y + 9); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

			if ((ptr = fopen("log.txt", "a")) == NULL) {
				gotoxy(x, y + 10);  printf("▤ The file could not be opened. ▤");
			}
			else {
				fprintf(ptr, "P1's Removed lines : %d\n", score_P1);
				fprintf(ptr, "P1's Obtained items : %d\n", item_P1_A);
				fprintf(ptr, "P1's Used items : %d\n\n", item_P1_A - item_P1);

				fprintf(ptr, "P2's Removed lines : %d\n", score_P2);
				fprintf(ptr, "P2's Obtained items : %d\n", item_P2_A);
				fprintf(ptr, "P2's Used items : %d\n\n", item_P2_A - item_P2);

				fclose(ptr);
			}

			Sleep(1000);
			while (kbhit()) getch();
			key = getch();
			turn = 0;
			reset();
		}
	}
}

void pause(void) {
	int i, j;

	int x = 5;
	int y = 5;

	for (i = 1; i<MAIN_X - 2; i++) {
		gotoxy(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		gotoxy(x, y + 1); printf("▤                              ▤");
		gotoxy(x, y + 2); printf("▤  +-----------------------+   ▤");
		gotoxy(x, y + 3); printf("▤  |       P A U S E       |   ▤");
		gotoxy(x, y + 4); printf("▤  +-----------------------+   ▤");
		gotoxy(x, y + 5); printf("▤  Press any key to resume..   ▤");
		gotoxy(x, y + 6); printf("▤                              ▤");
		gotoxy(x, y + 7); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	}
	getch();

	system("cls");
	reset_main_cpy();
	draw_main();
	draw_map();

	for (i = 1; i<3; i++) {
		for (j = 0; j<4; j++) {
			if (blocks[b_type_next][0][i][j] == 1) {
				gotoxy(MAIN_X + MAIN_X_ADJ + 3 + j, i + 6);
				printf("■");
			}
			else {
				gotoxy(MAIN_X + MAIN_X_ADJ + 3 + j, i + 6);
				printf("  ");
			}
		}
	}
}

void use_item() {
	int i, j;

	int x = 5;
	int y = 5;

	int item_user;
	int block_user;

	char choice = 0;

	switch (sit) {
	case 1:  //1이 2쓸거 선택
		item_user = 1;
		block_user = 2;
		break;
	case 2:  //1이 1쓸거 선택
		item_user = 1;
		block_user = 1;
		break;
	case 3:  //2가 2쓸거 선택
		item_user = 2;
		block_user = 2;
		break;
	case 4:  //2가 1쓸거 선택
		item_user = 1;
		block_user = 1;
		break;
	}

	for (i = 1; i < MAIN_X - 2; i++) {
		gotoxy(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		gotoxy(x, y + 1); printf("▤                                      ▤");
		gotoxy(x, y + 2); printf("▤  +-----------------------+           ▤");
		gotoxy(x, y + 3); printf("▤  |   Player%d uses item   |           ▤", item_user);
		gotoxy(x, y + 4); printf("▤  +-----------------------+           ▤");
		gotoxy(x, y + 5); printf("▤  Please choose block                 ▤");
		gotoxy(x, y + 6); printf("▤      Player%d will use                ▤", block_user);
		gotoxy(x, y + 7); printf("▤                                      ▤");
		gotoxy(x, y + 8); printf("▤  1   ■   2         3      4         ▤");
		gotoxy(x, y + 9); printf("▤      ■    ■■       ■       ■    ▤");
		gotoxy(x, y + 10); printf("▤      ■    ■■     ■■■   ■■    ▤");
		gotoxy(x, y + 11); printf("▤      ■                      ■      ▤");
		gotoxy(x, y + 12); printf("▤                                      ▤");
		gotoxy(x, y + 13); printf("▤    You have 5 seconds to enter.      ▤");
		gotoxy(x, y + 14); printf("▤                                      ▤");
		gotoxy(x, y + 15); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	}
	for (i = 5; i > 0; i--) {
		Sleep(1000);
		gotoxy(x, y + 13); printf("▤      Left Time : %d                   ▤", i);
		if (kbhit())			choice = getch();
	}

	switch (choice) {
	case '1':
		b_type_next = 1;
		break;
	case '2':
		b_type_next = 0;
		break;
	case '3':
		b_type_next = 6;
		break;
	case '4':
		b_type_next = 2;
		break;
	default:
		break;
	}

	system("cls");
	reset_main_cpy();
	draw_main();
	draw_map();

}
