#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1. 숫자 1~7을 입력하면, 각각에 대해 A,B,C,D,E,F,G를 출력*/
#if 0
int main() {
	int num;
	scanf("%d", &num);
	printf("%c", num + 'A' - 1);
	return 0;
}
#endif

/*
2. 다음 4줄을 for loop를 이용하여 각각 출력하는 프로그램 (단 아래 기호의 값은 0xA1E1이다)*/
// if를 쓸 때는 else에 아무것도 없어도 일단 써놓기
// 
// 경우의 수가 2개이면 이진수로 생각해보기(배열)
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

