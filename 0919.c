#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// char a = 0;  // a는 변수, char 크기
// int a = 0;  // int 크기의 변수
// unsigned : 크기 같음, 부호 상관없이 데이터로 저장하겠다
// char a = 257;  // 불가, 자신의 데이터 최대를 넘어감

// char a = 0; int b = 257; a = b;  // 처음엔 b가 작아 a에 b가 들어갈 수 있지만 b의 값이 변하면 안들어갈 수도 있다
// 5 = 5;  // 프로그래밍 관점에서 틀림, 5를 받는 것은 변수여야 함, 변수의 데이터 크기를 따지는 것은 그 다음의 문제
//
// char a[3];
// a = 7;  // a는 변수가 아니므로 틀림

// 배열은 각각이 변수다
// char a,b,c,d,e,f,g;  char a[7];
// 두 개의 차이점 
// a,b,c... : 각각이 연결성이 없음
// a[7]: 한 개의 주소를 알면 나머지의 주소도 알 수 있음

#if 0
// 각각의 주소 하나씩 확인해보기
// 이 변수들을 전역변수로 바꾸면 또 달라짐
// 지역변수는 스택으로 관리함        전역변수 - 힙
// --> 먼저 나온 변수를 가장 아래(주소가 가장큰 부분)에 저장함, 그 다음 위에 쌓아감
int main() {
	char a, b, c, d;
	int i, j, k;
	char e, f, g;
	int l;
	char h;
	int m;
	char x[7];

	m = 0;
	/*
	a     0x000000e7c06ffaf4  0   
	b     0x000000e7c06ffb14  32   32
	c     0x000000e7c06ffb34  64   32
	d     0x000000e7c06ffb54  96   32
								   32
	i     0x000000e7c06ffb74  128
	j     0x000000e7c06ffb94  160  32
	k     0x000000e7c06ffbb4  192  32
								   32
	e     0x000000e7c06ffbd4  224
	f     0x000000e7c06ffbf4  256  32
	g     0x000000e7c06ffc14  288  32

	l     0x000000e7c06ffc34  320
								   32
	h     0x000000e7c06ffc54  352
								   32
	m     0x000000e7c06ffc74  384
								   32
	x     0x000000e7c06ffc94  416
	x[0]  0x000000e7c06ffc94  416  1
	x[1]  0x000000e7c06ffc95  417  1
	x[2]  0x000000e7c06ffc96  418  1
	x[3]  0x000000e7c06ffc97  419  1
	x[4]  0x000000e7c06ffc98  420  1
	x[5]  0x000000e7c06ffc99  421  1
	x[6]  0x000000e7c06ffc9a  422  1
	*/
}
#endif

#if 0
int i, j;
char a, b;
char arr1[7];
main() {
	char c, d;
	int x, y;
	char arr2[7];
	int m;

	m = 0;
	/*
	i        0x00007ff6fd33c1e8  116
	j		 0x00007ff6fd33c174  2

	a		 0x00007ff6fd33c172  1
	b		 0x00007ff6fd33c171  0
	
	arr1     0x00007ff6fd33c198  39
	arr1[0]  0x00007ff6fd33c198  39
	arr1[1]  0x00007ff6fd33c199  40
	arr1[2]  0x00007ff6fd33c19a  41
	arr1[3]  0x00007ff6fd33c19b  42
	arr1[4]  0x00007ff6fd33c19c  43
	arr1[5]  0x00007ff6fd33c19d  44
	arr1[6]  0x00007ff6fd33c19e  45

	c		 0x00000068ce39fb74  0
	d		 0x00000068ce39fb94  32   32

	x		 0x00000068ce39fbb4  64   32
	y		 0x00000068ce39fbd4  96   32

	arr2	 0x00000068ce39fbf4  128  32
	arr2[0]  0x00000068ce39fbf4  128
	arr2[1]  0x00000068ce39fbf5  129  1
	arr2[2]  0x00000068ce39fbf6  130  1
	arr2[3]  0x00000068ce39fbf7  131  1
	arr2[4]  0x00000068ce39fbf8  132  1
	arr2[5]  0x00000068ce39fbf9  133  1
	arr2[6]  0x00000068ce39fbfa  134  1

	m		 0x00000068ce39fc14  160  32(26)
	*/
}
#endif


// 1 = 0000_0001
// unsigned 1 = 1000_0001;  // 129
// signed 1 = 1000_0001  // -127
#if 0
int main() {
	unsigned char a1 = 1;
	char a2 = 1;
	for (int i = 7; i >= 0; i--) {
		printf("%d", a1 >> i & 1);
	}
	printf("\n");
	for (int i = 7; i >= 0; i--) {
		printf("%d", a2 >> i & 1);
	}
	return 0;
}
#endif


#if 0
int main() {
	unsigned char a = 29 | 12;
	printf("%c\n", a);  // a = 1
	printf("%c %c", 1, 29);
	return 0;
}
#endif


// int i;
// char a;
// &i + 1;
// &a + 1;
// 주소가 1 증가하는 것이 아님
// "그 다음", "그 이전"의 의미
// char의 주소는 +1;
// int의 주소는 +4;
// 주소끼리 빼기 가능, 더하기 불가능
#if 0
int main() {
	char a;
	int b;
	long long c;
	short d;
	printf("%x\n%x\n", &a, &a + 1);  // +1
	printf("%x\n%x\n", &b, &b + 1);  // +4
	printf("%x\n%x\n", &c, &c + 1);  // +8
	printf("%x\n%x\n", &d, &d + 1);  // +2

	return 0;
}
#endif


#if 0
int main() {
	unsigned char i, count = 0;

	for (i = 32; i <= 127; i++) {
		printf("%c(%d) ", i, i);
		count++;
		if (count == 6) {
			count = 0;
			printf("\n");
		}
	}

	printf("\n");
	return 0;
}
#endif


#if 0
int main() {
	unsigned char i, count = 0;

	for (i = 128; i < 255; i++) {
		printf("%c(%d) ", i, i);
		count++;
		if (count == 6) {
			count = 0;
			printf("\n");
		}
	}

	printf("\n");
	return 0;
}
#endif

#if 0
int main() {
	unsigned char i, count = 0;

	system("chcp 437");
	for (i = 32; i <= 127; i++) {
		printf("%c(%d) ", i, i);
		count++;
		if (count == 6) {
			count = 0;
			printf("\n");
		}
	}

	printf("\n");
	return 0;
}
#endif

#if 0
int main() {
	unsigned char hangul[3] = "가";
	unsigned char code;
	code = hangul[0];
	printf("%x %d\n", code, code);  // b0 176
	code = hangul[1];
	printf("%x %d\n", code, code);  // a1 161
	return 0;
}
#endif


// 0 ~ 127 일반 문자
// 128 ~ 255 특수 기호, 각 나라의 글자
// 첫번째 값이 128 이상이면 뒷글자와 합쳐서 출력
#if 0
int main() {
	unsigned char b1 = 0xb0;
	unsigned char b2 = 0xa1;
	unsigned char b3 = 0xa2;
	printf("%c%c\n", b1, b2);  // 가
	printf("%c %c\n", b1, b2);
	printf("%d%d\n", b1, b2);
	printf("%c%c\n", b1, b3);

	return 0;
}
#endif

#if 0
// 한글인지 판단하는 함수도 만들어보기
int is_hangul(char st[]) {
	unsigned char uc;
	uc = st[0];

	if (uc & 0x80)
		return 1;
	else
		return 0;
}
int main() {
	char string[5] = { 0, };
	printf("한 개의 문자를 입력하고 Enter>");
	scanf("%s", string);
	for (int j = 7; j >= 0; j--) {
		printf("%d", 0x80 >> j & 1);
	}
	printf("\n");
	printf("%s\n", string);
	for (int i = 0; i < 5; i++) {
		for (int j = 7; j >= 0; j--) {
			printf("%d", string[i] >> j & 1);
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		if (string[i] & 0x80)
			printf("한글입니다.\n");
		else
			printf("영문입니다.\n");
	}
	if (is_hangul(string))
		printf("한글입니다.\n");
	else
		printf("영문입니다.\n");
	return 0;
}
#endif

#if 0
int main() {
	int n;
	unsigned char a[3];
	a[2] = '\0';
	while (1) {
		scanf("%d", &n);
		if (n) {
			printf("----- 한글 -> 수 -----\n");
			scanf("%s", &a);
			printf("%x %x\n", a[0], a[1]);
			printf("---------------------\n");
		}
		else {
			printf("----- 수 -> 한글 -----\n");
			scanf("%x %x", &a[0], &a[1]);
			printf("%s\n", a);
			printf("---------------------\n");
		}
	}
}
#endif

#if 0
int main() {
	printf("");
	return 0;
}
#endif