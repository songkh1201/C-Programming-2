#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#if 0
main() {
	unsigned char a[4] = { 0, }, b;

	printf("Input Data : ");
	scanf("%d", (int*)&a[0]);  // a:12 --> b:12 , a:305419896 --> b:138

	b = a[0];
	printf("%d\n", b);
}
#endif

// 한 주소에는 8bit = 1byte가 들어감
// 375e54697189  1000번지에 37 1001번지에 5e
// char일 때 1byte    int일 때 4byte
// 1000번지: 37       1000번지: 375e5469