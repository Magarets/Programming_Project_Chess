//�� ����
//���� ���
//1. ������ ��ĭ�̵� ( ó�� �̵��� �� 2ĭ���� ���� )
//2. �ڷ� �̵��Ұ�
//3. �տ� ���� ������ �̵� �Ұ�
//4. �밢�� �տ� ���� ������ ���� ���� �� ����.
//5. ���� ���� ����� �������� �̵��� ���� ���� �� �ٸ� ���� ���� ����
// ��, ���� �� �̵��ϴ� �������ؾߵ�
#pragma warning(disable:4996)
#include <stdio.h>
//���� ���õɶ� ù��°�� ���õǾ��ִ��� Ȯ���� �ʿ䰡 ����.
void Pone_move_White(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. �� �̵�
	if (cmp != 1) {
		//����� ��
		if (Move_x < Now_x -1) {
			printf("�� �߸��� ���� Not cmp = 1");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("�ű� ���� �����־ ����");
			return;
		}
		else if (Move_x > Now_x - 1) {
			printf("�ڷ� �̵� ����");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
	}

	else if (cmp == 1) {
		if (Move_x < Now_x - 2) {
			printf("�� �߸��� ����");
			return;
		}
		else if (map[Move_x][Move_y] != '*') {
			printf("�ű� ���� �����־ ����");
			return;
		}
		else if (Move_x > Now_x - 1) {
			printf("�ڷ� �̵� ����");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y - 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
	}
	map[Move_x][Move_y] = 'P';
	map[Now_x][Now_y] = '*';
}
void Pone_move_Black(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. �� �̵�
	if (cmp != 1) {
		//����� ��
		if (Move_x > Now_x + 1) {
			printf("�� �߸��� ����");
			printf("Now_x : %d Move_x : %d", Now_x, Move_x);
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("�ű� ���� �����־ ����");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("�ڷ� �̵� ����");
			return;
		}
		
		else if (Move_x > Now_x + 2 || Move_x < Now_x && Move_y != Now_y) {
			printf("�¿�� �̵� ���ؿ�");
			return;
		}
	}

	else if (cmp == 1) {
		if (Move_x > Now_x + 2) {
			printf("�� �߸��� ���� 0\n");
			return;
		}
		else if (map[Move_x][Now_y] != '*') {
			printf("�ű� ���� �����־ ���� 1\n");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("�ڷ� �̵� ����2\n");
			return;
		}
		else if (Move_x == Now_x + 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����3\n");
			return;
		}
		else if (Move_x == Now_x - 1 && Move_y == Now_y + 1 && map[Move_x][Move_y] == '*') {
			printf("�ű�� �̵� ����4\n");
			return;
		}
		else if (Move_x > Now_x + 2 || Move_x < Now_x && Move_y != Now_y) {
			printf("�¿�� �̵� ���ؿ�");
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

	//����� �ҹ���, ����� �빮��
	map[0][0] = 'l';  map[7][0] = 'L';
	map[0][1] = 'n';  map[7][1] = 'N';
	map[0][2] = 'b';  map[7][2] = 'B';
	map[0][3] = 'q';  map[7][3] = 'Q';
	map[0][4] = 'k';  map[7][4] = 'K';
	map[0][5] = 'b';  map[7][5] = 'B';
	map[0][6] = 'n';  map[7][6] = 'N';
	map[0][7] = 'l';  map[7][7] = 'L';

	int cmp = 0; //���Լ��� ������ Ȯ��
	int Now_y = 0, Move_y = 0;
	int Now_x = 0, Move_x = 0;

	//�����
	while (Now_x < 7 && Now_y < 7) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}

		//���� ��ǥ
		scanf("%d %d", &Now_x, &Now_y);

		//�����̴� ��ǥ
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
