#define _CRT_SECURE_NO_WARNINGS
#define UNICODE
#include<stdio.h>
#include<windows.h>

char board[8][8];

void input() {

}

void output() {

}


/*
배열 [][0] : Pawn
배열 [][1] : Look
배열 [][2] : Bishop
배열 [][3] : Queen
배열 [][4] : King
*/

int dirnum[9];
int dir[8][2] = {
   {-1,-1},{-1,0},{-1,1},
   {0,-1},        {0,1},
   {1,-1},{1,0},{1,1}
};
int dir2[8][2] = {
   {-1,-2},{-1,2},{-2,-1},{-2,1},{1,2},{1,-2},{2,1},{2,-1}
};
/*
dirnum

012
3 4
567

위 8방향으로 이동 가능한 칸수 각각 적기.

8은 나이트 이동
0 = 이동못함
1 = 이동가능

ex) look

0 = 0
1 = 8
2 = 0
3 = 8
4 = 8
5 = 0
6 = 8
7 = 0
8 = 0

함수 호출

*/



int iswhite(int x, int y)
{
	if ('a' <= board[x][y] && board[x][y] <= 'z') {
		return 1;
	}
	return 0;
}

// 시작점 끝점
// RETURN에 대한 정보. 0 : 못가는 지점 / 1 : 갈 수 있는 지점 & 말을 못 잡음 / 2 : 갈수있는 지점 & 말을 잡음

int check(int sx, int sy, int ex, int ey) {
	int i, j;
	int xx, yy;
	for (i = 0; i < 8; i++)
	{
		xx = sx, yy = sy;
		for (j = 0; j < dirnum[i]; j++) {
			xx += dir[i][0];
			yy += dir[i][1];
			if (0 <= xx && xx < 8 && 0 <= yy && yy < 8) {
				if (xx == ex && yy == ex) {
					if (board[xx][yy] == '.') {
						return 1;
					}
					else if (iswhite(xx, yy) != iswhite(sx, sy)) {
						return 2;
					}
					else return 0;
				}
				if (board[xx][yy] != '.') break;
			}
		}
	}
	if (dirnum[8] == 1) {
		for (i = 0; i < 8; i++)
		{
			xx = sx + dir2[i][0];
			yy = sy + dir2[i][1];
			if (0 <= xx && xx < 8 && 0 <= yy && yy < 8) {
				if (xx == ex && yy == ex) {
					if (board[xx][yy] == '.') {
						return 1;
					}
					else if (iswhite(xx, yy) != iswhite(sx, sy)) {
						return 2;
					}
					else return 0;
				}
			}
		}
	}
	return 0;
}
//return 0 --> stalemate성립X return 1 --> 성립 O
int Checking_mates(int x, int y) {
	int re = 0, i, j;
	int king_x, king_y;
	if (iswhite(x, y) == 0) {
		//킹의 위치 확인
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (board[i][j] == 'K') {
					king_x = i;
					king_y = j;
				}
			}
		}
		//현재 킹이 체크인지 아닌지 확인
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (re == 2) {
					re = mate(king_x, king_y);
					if (re == 0) {
						return 0;
					}
					else if (re == 1) {
						printf("\nYou Lose! CheckMate!\n");
						return 1;
					}
				}
				if (board[i][j] == 'P') {
					re = pawn(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'B') {
					re = Bishop(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'N') {
					re = knight(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'L') {
					re = look(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'Q') {
					re = Queen(i, j, king_x, king_y);
				}
				else if (board[i][j] == "K") {
					re = King(i, j, king_x, king_y);
				}
			}
		}
		if (re != 2) {
			re = mate(king_x, king_y);
			if (re == 0) {
				return 0;
			}
			else if (re == 1) {
				printf("\nDraw! StaleMate!\n");
				return 1;
			}
		}
	}
	else if (iswhite(x, y) == 1) {
		//킹의 위치 확인
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (board[i][j] == 'k') {
					king_x = i;
					king_y = j;
				}
			}
		}
		//현재 킹이 체크인지 아닌지 확인
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (re == 2) {
					re = mate(king_x, king_y);
					if (re == 0) {
						return 0;
					}
					else if (re == 1) {
						printf("\nYou Lose! CheckMate!\n");
						return 1;
					}
				}
				if (board[i][j] == 'p') {
					re = pawn(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'b') {
					re = Bishop(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'n') {
					re = knight(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'l') {
					re = look(i, j, king_x, king_y);
				}
				else if (board[i][j] == 'q') {
					re = Queen(i, j, king_x, king_y);
				}
				else if (board[i][j] == "k") {
					re = King(i, j, king_x, king_y);
				}
			}
		}
		if (re != 2) {
			re = mate(king_x, king_y);
			if (re == 0) {
				return 0;
			}
			else if (re == 1) {
				printf("\nDraw! StaleMate!\n");
				return 1;
			}
		}
	}
}

//스테일메이트와 체크메이트 공통적으로 들어있는 것
//return 0 --> 둘다 성립X return 1 -->성립O
int mate(int kx, int ky) {
	int i, j,k,h;
	int xx, yy, res = 0;
	for (i = 0; i < 8; i++)
	{
		xx = kx, yy = ky;
		xx += dir[i][0];
		yy += dir[i][1];
		if (0 <= xx && xx < 8 && 0 <= yy && yy < 8) {
			for (k = 0; k < 8; k++) {
				for (h = 0; h < 8; h++) {
					if (res == 2) {
						return 1;
					}
					if (board[i][j] == 'p' || board[i][j] == 'P') {
						res = pawn(xx, yy, kx, ky);
					}
					else if (board[i][j] == 'b'|| board[i][j] == 'B') {
						res = Bishop(xx, yy, kx, ky);
					}
					else if (board[i][j] == 'n'|| board[i][j] == 'N') {
						res = knight(xx, yy, kx, ky);
					}
					else if (board[i][j] == 'l'|| board[i][j] == 'L') {
						res = look(xx, yy, kx, ky);
					}
					else if (board[i][j] == 'q'|| board[i][j] == 'Q') {
						res = Queen(xx, yy, kx, ky);
					}
					else if (board[i][j] == "k"|| board[i][j] == 'K') {
						res = King(xx, yy, kx, ky);
					}
				}
			}
			return 0;
		}
	}
}
int pawn(int sx, int sy, int ex, int ey) {
	dirnum[0] = 0;
	dirnum[1] = 1;
	dirnum[2] = 0;
	dirnum[3] = 0;
	dirnum[4] = 0;
	dirnum[5] = 0;
	dirnum[6] = 0;
	dirnum[7] = 0;
	dirnum[8] = 0;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}

int Queen(int sx, int sy, int ex, int ey) {
	dirnum[0] = 8;
	dirnum[1] = 8;
	dirnum[2] = 8;
	dirnum[3] = 8;
	dirnum[4] = 8;
	dirnum[5] = 8;
	dirnum[6] = 8;
	dirnum[7] = 8;
	dirnum[8] = 0;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}

int King(int sx, int sy, int ex, int ey) {
	dirnum[0] = 1;
	dirnum[1] = 1;
	dirnum[2] = 1;
	dirnum[3] = 1;
	dirnum[4] = 1;
	dirnum[5] = 1;
	dirnum[6] = 1;
	dirnum[7] = 1;
	dirnum[8] = 0;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}

int Bishop(int sx, int sy, int ex, int ey) {
	dirnum[0] = 8;
	dirnum[1] = 0;
	dirnum[2] = 8;
	dirnum[3] = 0;
	dirnum[4] = 0;
	dirnum[5] = 8;
	dirnum[6] = 0;
	dirnum[7] = 8;
	dirnum[8] = 0;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}

int look(int sx, int sy, int ex, int ey) {
	dirnum[0] = 0;
	dirnum[1] = 8;
	dirnum[2] = 0;
	dirnum[3] = 8;
	dirnum[4] = 8;
	dirnum[5] = 0;
	dirnum[6] = 8;
	dirnum[7] = 0;
	dirnum[8] = 0;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}

int knight(int sx, int sy, int ex, int ey) {
	dirnum[0] = 0;
	dirnum[1] = 0;
	dirnum[2] = 0;
	dirnum[3] = 0;
	dirnum[4] = 0;
	dirnum[5] = 0;
	dirnum[6] = 0;
	dirnum[7] = 0;
	dirnum[8] = 1;
	if (check(sx, sy, ex, ey) == 0) {
		printf("못가요");
		return 0;
	}
	else if (check(sx, sy, ex, ey) == 1) {
		printf("갈수있어요");
		return 1;
	}
	else if (check(sx, sy, ex, ey) == 2) {
		printf("갈수있고 상대편 말도 잡았어요");
		return 2;
	}
}


int main() {

	for (int i = 0; i < 6; i++) {
		printf("number %d is.... [", i + 1);
		for (int j = 0; j < 6; j++) {
			printf("%d ", horse[i][j]);
		}
		printf("]\n");
	}

	return 0;
}