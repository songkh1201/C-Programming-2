#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ� ������
// �Լ��� ����Ű�� ������
//

#if 0
int add(int, int);
int sub(int, int);

int main() {
	int result;
	int (*pf)(int, int);
	
	pf = add;  // 
	result = pf(10, 20);
	printf("%d\n", result);

	pf = sub;
	result = pf(10, 20);
	printf("%d\n", result);
	return 0;
}

int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
#endif

// �Լ� �������� �迭