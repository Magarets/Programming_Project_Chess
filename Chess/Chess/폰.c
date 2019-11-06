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
			printf("님 잘못감 ㅅㄱ");
			return;
		}
		else if (Move_x == Now_x - 1 && map[Move_x][Now_y] != '*') {
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
		if (Move_x > Now_x - 2) {
			printf("님 잘못감 ㅅㄱ");
			return;
		}
		else if (Move_x == Now_x - 1 || Move_x == Now_x - 2 && map[Move_x][Move_y] != '*') {
			printf("거긴 말로 막혀있어서 못감");
			return;
		}
		else if (Move_x < Now_x - 1) {
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
}
void Pone_move_Black(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. 폰 이동
	printf("%d %d %d %d", Now_x, Now_y, Move_x, Move_y);
	if (cmp != 1) {
		//흑색의 폰
		if (Move_x > Now_x + 1) {
			printf("님 잘못감 ㅅㄱ");
			printf("Now_x : %d Move_x : %d", Now_x, Move_x);
			return;
		}
		else if (Move_x == Now_x + 1 && map[Move_x][Now_y] != '*') {
			printf("거긴 말로 막혀있어서 못감");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("뒤로 이동 못함");
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
	map[2][0] = 'p';
	map[2][1] = 'N';
	//0행 : white, 1행 : black
	int ponemovecount[2][8] = { 0 };
	int Now_y, Move_y;
	int Now_x, Move_x;

	//맵출력
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
	//폰함수로 이동
	
	ponemovecount[1][0]++;
	
	Pone_move_Black(ponemovecount[1][0], Now_x, Now_y, Move_x, Move_y, map);

	//맵출력
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
