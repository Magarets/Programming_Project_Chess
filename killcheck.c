#include<stdio.h>
int check(char map[8][8]);
int main(void) {
	char map[8][8];
	int a = 0;
	
	
	for (int i = 0; i < 8; i++) {
		map[1][i] = 'p';
		map[6][i] = 'p';
		for (int j = 2; j < 6; j++) {
			map[j][i] = '*';
		}
	}
	map[0][0] = 'l', map[0][7] = 'l';
	map[0][1] = 'n', map[0][6] = 'n';
	map[0][2] = 'b', map[0][5] = 'b';
	map[0][3] = 'q', map[0][4] = 'k';
	map[7][0] = 'l', map[7][7] = 'l';
	map[7][1] = 'n', map[7][6] = 'n';
	map[7][2] = 'b', map[7][5] = 'b';
	map[7][3] = 'q', map[7][4] = 'k';
	while (a <= 1) {
		if (check(map) == 1) {
			a += 1;
			printf("check");

		}
	}
}
int check(char map[8][8]) {
	int check = 0;

	for (int m = 0; m < 8; m++) {
		for (int n = 0; n < 8; n++) {
			switch (map[m][n]) {
			case '*':
				break;

			case 'p':
				if (map[m - 1][n - 1] == 'k' || map[m - 1][n + 1] == 'k') {
					check++;
					break;
				}
					
				

			case 'l':
				for (int i = 0; i < 8; i++) {
					if (map[i][n] == 'k' || map[m][i] == 'k') {
						check++;
						break;
					}
				}
				break;

			case 'b':
				for (int i = 0; i < 8; i++) {
					if (map[m + i][n + i] == 'k') {
						if (m + i <= 7 && n + i <= 7) {
							check++;
							break;
						}
					}
					else if (map[m - i][n - i] == 'k') {
						if (m - i >= 0 && n - i >= 0) {
							check++;
							break;
						}
					}
					else if (map[m - i][n + i] == 'k') {
						if (m - i >= 0 && n + i <= 7) {
							check++;
							break;
						}
					}
					else if (map[m + 1][n - 1] == 'k') {
						if (m + 1 <= 7 && n - 1 >= 0) {
							check++;
							break;
						}
					}
				}
				break;
			case 'q':
				for (int i = 0; i <8; i++) {
					if (map[m][i] == 'k' || map[i][n] == 'k') {
						check++;
						break;
					}
				}
				if (check > 0)
					break;
				else {
					for (int i = 0; i < 8; i++) {
						if (map[m + i][n + i] == 'k') {
							if (m + i <= 7 && n + i <= 7) {
								check++;
								break;
							}
						}
						else if (map[m - i][n - i] == 'k') {
							if (m - i >= 0 && n - i >= 0) {
								check++;
								break;
							}
						}
						else if (map[m - i][n + i] == 'k') {
							if (m - i >= 0 && n + i <= 7) {
								check++;
								break;
							}
						}
						else if (map[m + 1][n - 1] == 'k') {
							if (m + 1 <= 7 && n - 1 >= 0) {
								check++;
								break;
							}
						}
					}
				}
				break;
			case'n':
				if (map[m + 2][n - 1] == 'k' || map[m + 2][n + 1] == 'k' || map[m - 1][n + 2] == 'k' || map[m + 1][n + 2] == 'k' ||
					map[m - 2][n - 1] == 'k' || map[m - 2][n + 1] == 'k' || map[m - 1][n - 2] == 'k' || map[m + 1][n - 2] == 'k') {//범위 안넘어가게 어케하누?
					check++;
					break;
				}
			}
			if (check > 0)
				break;
		}
		if (check > 0)
			break;
	}
	if (check > 0)
		return 1;
	else 
		return 0;
}
void kill(char map[8][8]) {

}