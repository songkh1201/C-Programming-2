#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1. ���� 1~7�� �Է��ϸ�, ������ ���� A,B,C,D,E,F,G�� ���*/
#if 0
int main() {
	int num;
	scanf("%d", &num);
	printf("%c", num + 'A' - 1);
	return 0;
}
#endif

/*
2. ���� 4���� for loop�� �̿��Ͽ� ���� ����ϴ� ���α׷� (�� �Ʒ� ��ȣ�� ���� 0xA1E1�̴�)*/
// if�� �� ���� else�� �ƹ��͵� ��� �ϴ� �����
// 
// ����� ���� 2���̸� �������� �����غ���(�迭)
//
#if 0
int main() {
	for (int i = 0; i < 20; i++) {
		if ((i % 5) == 4) printf("%c%c \n", 0xA1, 0xE1);
		else if ((i / 5) == 0 || (i / 5) == 3 || (i % 5) == 0) printf("%c%c ", 0xA1, 0xE1);
		else printf("  ");
	}
	return 0;
}
#endif

#if 0
int main() {
	unsigned char a1 = 0xa1, a2 = 0xe1;
	unsigned char pattern[4] = { 0x1F,0x11,0x11,0x1F };

	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			if ((pattern[i] >> j) & 0x01) printf("%c%c", a1, a2);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

