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
			printf("�� �߸��� ����");
			return;
		}
		else if (Move_x == Now_x - 1 && map[Move_x][Now_y] != '*') {
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
		if (Move_x > Now_x - 2) {
			printf("�� �߸��� ����");
			return;
		}
		else if (Move_x == Now_x - 1 || Move_x == Now_x - 2 && map[Move_x][Move_y] != '*') {
			printf("�ű� ���� �����־ ����");
			return;
		}
		else if (Move_x < Now_x - 1) {
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
}
void Pone_move_Black(int cmp, int Now_x, int Now_y, int Move_x, int Move_y, char map[8][8]) {
	//1. �� �̵�
	printf("%d %d %d %d", Now_x, Now_y, Move_x, Move_y);
	if (cmp != 1) {
		//����� ��
		if (Move_x > Now_x + 1) {
			printf("�� �߸��� ����");
			printf("Now_x : %d Move_x : %d", Now_x, Move_x);
			return;
		}
		else if (Move_x == Now_x + 1 && map[Move_x][Now_y] != '*') {
			printf("�ű� ���� �����־ ����");
			return;
		}
		else if (Move_x < Now_x + 1) {
			printf("�ڷ� �̵� ����");
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
	map[2][0] = 'p';
	map[2][1] = 'N';
	//0�� : white, 1�� : black
	int ponemovecount[2][8] = { 0 };
	int Now_y, Move_y;
	int Now_x, Move_x;

	//�����
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
	//���Լ��� �̵�
	
	ponemovecount[1][0]++;
	
	Pone_move_Black(ponemovecount[1][0], Now_x, Now_y, Move_x, Move_y, map);

	//�����
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
