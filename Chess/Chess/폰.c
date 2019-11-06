//폰 구현
//폰의 기능
//1. 앞으로 한칸이동 ( 처음 이동할 땐 2칸까지 가능 )
//2. 뒤로 이동불가
//3. 앞에 말이 있으면 이동 불가
//4. 대각선 앞에 말이 있으면 말을 잡을 수 있음.
//5. 만약 폰이 상대편 진영으로 이동시 죽은 말들 중 다른 말로 변형 가능
// 흑, 백일 때 이동하는 방향고려해야됨
#pragma warning(disable:4996)
#include <stdio.h>
//폰이 선택될때 첫번째로 선택되어있는지 확인할 필요가 있음.
void Pone_move_White(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. 폰 이동
	if (cmp != 1) {
		//백색의 폰
		if (Move_x < Now_x -1) {
			printf("님 잘못감 ㅅㄱ Not cmp = 1");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("거긴 말로 막혀있어서 못감");
			return;
		}
		else if (Move_x > Now_x - 1) {
			printf("뒤로 이동 못함");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
	}

	else if (cmp == 1) {
		if (Move_x < Now_x - 2) {
			printf("님 잘못감 ㅅㄱ");
			return;
		}
		else if (map[Move_x][Move_y] != '*') {
			printf("거긴 말로 막혀있어서 못감");
			return;
		}
		else if (Move_x > Now_x - 1) {
			printf("뒤로 이동 못함");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
	}
	map[Move_x][Move_y] = 'P';
	map[Now_x][Now_y] = '*';
}
void Pone_move_Black(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. 폰 이동
	if (cmp != 1) {
		//흑색의 폰
		if (Move_x > Now_x + 1) {
			printf("님 잘못감 ㅅㄱ");
			printf("Now_x : %d Move_x : %d", Now_x, Move_x);
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("거긴 말로 막혀있어서 못감");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("뒤로 이동 못함");
			return;
		}
		
		else if (Move_x > Now_x + 2 || Move_x < Now_x && Move_y != Now_y) {
			printf("좌우로 이동 못해요");
			return;
		}
	}

	else if (cmp == 1) {
		if (Move_x > Now_x + 2) {
			printf("님 잘못감 ㅅㄱ 0\n");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("거긴 말로 막혀있어서 못감 1\n");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("뒤로 이동 못함2\n");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함3\n");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("거기로 이동 못함4\n");
			return;
		}
		else if (Move_x > Now_x + 2 || Move_x < Now_x && Move_y != Now_y) {
			printf("좌우로 이동 못해요");
			return;
		}
		
	}
	map[Move_x][Move_y] = 'p';
	map[Now_x][Now_y] = '*';
	
}
int main() {

	char map[8][8] = { 0 };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = '*';
		}
	}

	for (int i = 0; i < 8; i++) {
		map[1][i] = 'p';
		map[6][i] = 'P';
	}

	//흑색은 소문자, 백색은 대문자
	map[0][0] = 'l';  map[7][0] = 'L';
	map[0][1] = 'n';  map[7][1] = 'N';
	map[0][2] = 'b';  map[7][2] = 'B';
	map[0][3] = 'q';  map[7][3] = 'Q';
	map[0][4] = 'k';  map[7][4] = 'K';
	map[0][5] = 'b';  map[7][5] = 'B';
	map[0][6] = 'n';  map[7][6] = 'N';
	map[0][7] = 'l';  map[7][7] = 'L';

	int cmp = 0; //폰함수의 움직임 확인
	int Now_y = 0, Move_y = 0;
	int Now_x = 0, Move_x = 0;

	//맵출력
	while (Now_x < 7 && Now_y < 7) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}

		//현재 좌표
		scanf("%d %d", &Now_x, &Now_y);

		//움직이는 좌표
		scanf("%d %d", &Move_x, &Move_y);
		if (map[Now_x][Now_y] == 'P') {
			if (Now_x == 6) {
				cmp = 1;
			}
			else {
				cmp = 2;
			}
			Pone_move_White(cmp, Now_x, Now_y, Move_x, Move_y, map);
		}
		else if (map[Now_x][Now_y] == 'p') {
			if (Now_x == 1) {
				cmp = 1;
			}
			else {
				cmp = 2;
			}
			Pone_move_Black(cmp, Now_x, Now_y, Move_x, Move_y, map);
		}
	}

	return 0;
}
