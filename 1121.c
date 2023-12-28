#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// 복합 포인터 (배열의 포인터)
// 주소는 컴파일할 때 정해짐
// 
#if 0
int main() {
	char* p1 = NULL, p2[100], * p3, * p4[5];

	scanf_s("%s", p1, 100);  // 표준 scanf는 보안에 취약하니 제시하는 방법, 100은 최대길이
	printf("%s\n", p1);

	scanf_s("%s", p2, 100);  // p1과 p2의 차이는?
	printf("%s\n", p2);		 // 공간 유무의 차이   p1은 안된다. p2는 된다.
	return 0;
}
#endif


// x로 단어구분하여 배열에 넣기?

#if 0
int main() {
	char p2[101], * p3, * p4[5], i = 0, j = 0;

	scanf_s("%s", p2, 100);  // p2에 입력받기
	printf("%s\n", p2);

	p3 = p2;  // p3는 p2를 핸들링할 포인터
	p4[j++] = p3;  // p4는 배열의 포인터. 단어 위치 저장
	while (*p3) {
		if (*p3 == 'x') {  // 'x'를 찾아야지
			// 'x'를 찾으면 해야할 일 2가지      NULL 만들고, 위치 기억하고
			*p3 = NULL;
			p4[j++] = p3 + 1;
		}
		p3++;  // 다음 위치로 옮김
	}		   // 반복해서 완성

	for (i = 0; i < j; i++) {
		// 배열의 포인터를 이용해서 출력
		printf("%s\n", *(p4 + i));
	}
	return 0;
}
#endif


// 동적메모리 할당의 장점 (malloc)
// 연속성    배열은 모든 것이 연속적
//
// int** m = (int**)malloc(sizeof(int*) * 3);
// m[0] = (int*)malloc(sizeof(int) * 4);
// m[1] = (int*)malloc(sizeof(int) * 4);
// m[2] = (int*)malloc(sizeof(int) * 4);
// 각각 3개와 4개 내에서는 연속적이지만 서로가 연속적이지는 않음 (배열처럼 붙어있지 않음)
// 
// free() 할 때
// 반드시 작은 것부터
// 큰걸 먼저하면 작은 메모리 공간에는 접근도 못하고 어딘지 알 수 없는 아무도 못쓰는 공간이 됨
//
#if 0
void set_proverb(char* q);

int main() {
	char* s = NULL;  // s의 값 == NULL

	set_proverb(s);  // NULL을 넘김, 복사복이 넘어감
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char* q) {  // 복사본 NULL이 넘어옴, q의 초기값 == NULL,  s와 q는 다른놈
	static char* str1 = "A friend in need is a friend indeed";
	static char* str2 = "A little knowledge is a dangerous thing";

	q = str1;  // q는 str1을 가리키지만, q와 s는 다르기 때문에 함수가 끝나도 s는 가만히 있음
	// swap 함수처럼 s의 주소를 넘겨주어야 s의 값을 수정 가능
}
#endif
#if 0
void set_proverb(char** q);

int main() {
	char* s = NULL;

	set_proverb(&s);
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char** q) {  // s가 포인터이므로 s의 주소를 보내면, 주소의 주소이기 때문에 레벨을 맞춰야함 **
	static char* str1 = "A friend in need is a friend indeed";
	static char* str2 = "A little knowledge is a dangerous thing";

	*q = str1;
}
#endif

#if 0

void process(char** q);

int main() {
	char s[2][4] = { "abc","123" };  // s[100][200], s[500][7] ...

	process(s);
	printf("string = %s\n", s[0]);

	return 0;
}

void process(char** q) {    // s가 이차원 배열이라서, 포인터도 2차원에 해당하는 이중 포인터로 받았다. 문제는??
							// q와 q[1][0]을 이어주는 과정에 대해 잘 이해해 보자
	char tmp[4];
	q[1][0] = '7';			// 4+4 의 구조이니, 5번째 데이터를 가리켜야 한다. 1*4 + 0 =4번(5번째) 데이터,
							// 위 1*4 + 0 에서 이 지역함수 q는 무엇을 알고 무엇을 모르겠는가?
	return;
}							// 그래서 뭐가 문제점 이었는가?  q가 s의 구조를 모르기 떄문 가장 안쪽 크기를 몰라서 ([4]를 몰라서)
#endif
	
// 배열의 포인터 선언 방법
// 
// 2차원 배열 이름에 일치하는 포인터 선언
// int arr[2][4];  -->  int (*pArr)[4];
// int --> int 형 변수를 가리킨다.    int 형 포인터이다.
// (*pArr) --> pArr은 포인터    그냥 포인터이다.
// [4] --> 4칸씩 건너뛴다    맞춤 정보
//

// 매개변수로 사용할 때는 이렇게 써도 괜찮다
// void show_data(int (*ptr)[4], int a);
// ==
// void show_data(int ptr[][4], int a);
// 그러나 선언시에는 그렇게 쓰면 안된다 (인자로 쓸 때만 가능)

// 포인터 배열과 배열 포인터의 차이 주의!
// 
// 3차원 4차원 배열을 만들고 그 배열을 다른 함수에서 핸들링 할 수 있는 배열의 포인터 만들기   반드시 반드시 반드시
//
#if 0

void process(char** q);

int main() {
	char s[2][4] = { "abc","123" };  // s[100][200], s[500][7] ...

	process(s);
	printf("string = %s\n", s[0]);

	return 0;
}

void process(char(*q)[4]) {

	char tmp[4];
	q[1][0] = '7';

	return;
}
#endif

// 사진 해보기
// sizeof 예측해보고 답 확인해보기
#if 0
int main() {

	char* fruits[] = {
		"apple",
		"blueberry",
		"orange",
		"melon"
	};

	char** p1 = fruits;

	char fname[][10] = {
		"apple",
		"blueberry",
		"orange",
		"melon"
	};

	char(*p2)[10] = fname;

	printf("%d\n", sizeof(fruits));		// 16		char *[4]
	printf("%d\n", sizeof(fruits[0]));	// 4		char *

	printf("%d\n", sizeof(fname));		// 40		char[4][10]
	printf("%d\n", sizeof(fname[0]));	// 10		char[10]

	printf("%d\n", sizeof(p1));			// 4		char **
	printf("%d\n", sizeof(p1[0]));		// 4		char *

	printf("%d\n", sizeof(p2));			// 4		char[10] *
	printf("%d\n", sizeof(p2[0]));		// 10		char[10]	

	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

// 3차원?
#if 0
void process(char** q);

int main() {
	char s[2][4][10] = {
		{
			"abc",
			"def",
			"ghi",
		},
		{
			"123",
			"456",
			"789"
		}
	};

	process(s);
	printf("string = %s\n", s[1][1]);

	return 0;
}

void process(char (*q)[4][10]) {

	char tmp[4];
	q[1][1][1] = 'L';

	return;
}
#endif

#if 0
/*
입력 예시 복사
hPZOiW8D8Z
QMVOTD3Bq5
yskWEmqbmQ
uw3uaBC7Tx
6zM0wmXtK6
yijexWsT2F
XuRnW56p6u
CvvnKciYHc
fUGEVGiaCS
pQonT0fUpt
*/
// ============== 코드 작성 영역 ==============
void printstring(char **data) {
	for (int i = 0; i < 10; i++) {
		data[i][3] = 'P';
	}
}
// ============================================

int main(int argc, char const* argv[])
{
	char* data[10];
	for (int i = 0; i < 10; i++)
	{
		data[i] = malloc(sizeof(char) * 100);
		scanf("%s", data[i]);
	}

	printstring(data);

	for (int i = 0; i < 10; i++) printf("%s\n", data[i]);

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
/*입력 예시 복사
Do    you   like      my  car
출력 예시 복사
car my like you Do*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ======== 코드 작성 영역 ========
void reverseStringAtSpace_upgrade(char* destination[10], char* source) {
	char* s1 = source, * s2;
	int len = 0, idx = 0, flag = 0;
	while (*s1++ != NULL) len++;
	s2 = source + len - 1;
	while (*s2 != NULL) {
		if (*s2 != ' ') {
			flag = 1;
		}
		if (*s2 == ' ') {
			if (flag) {
				destination[idx++] = s2 + 1;
				flag = 0;
			}
			*s2 = NULL;
		}
		s2--;
	}
	destination[idx] = source;
}
// ===============================

int main(int argc, char const* argv[])
{
	char str[104] = { 0 };
	char* str2[10] = { 0 };
	gets(str);
	reverseStringAtSpace_upgrade(str2, str);
	for (int i = 0; i < 10; i++) {
		if (str2[i] != NULL) {
			printf("%s ", str2[i]);
		}
	}
	return 0;
}
#endif

#if 0
/*이진수 문자열 더하기*/
void leejin_sum(char* str1, char* str2) {
	int arr[101] = { 0 }, len1 = 0, len2 = 0, len = 0, num1, num2;
	char* s1 = str1, * s2 = str2, tmp;
	while (*s1++ != NULL) len1++;
	while (*s2++ != NULL) len2++;
	s1 = str1;
	s2 = str2;
	for (int i = 0; i < len1 / 2; i++) {
		tmp = *(s1 + i);
		*(s1 + i) = *(s1 + len1 - i - 1);
		*(s1 + len1 - i - 1) = tmp;
	}
	for (int i = 0; i < len2 / 2; i++) {
		tmp = *(s2 + i);
		*(s2 + i) = *(s2 + len2 - i - 1);
		*(s2 + len2 - i - 1) = tmp;
	}
	for (len = 0; len < len1 || len < len2; len++) {
		num1 = *(s1 + len) - '0';
		num2 = *(s2 + len) - '0';
		if (num1 < 0) num1 = 0;
		if (num2 < 0) num2 = 0;
		arr[len] += num1 + num2;
		if (arr[len] / 2) {
			arr[len] = 0;
			arr[len + 1] = 1;
		}
	}
	if (arr[len] == NULL) len--;
	for (int i = 0; i <= len; i++) {
		*(s1 + i) = arr[len - i] + '0';
	}
}
int main() {
	char s1[101] = { 0 }, s2[101];
	scanf("%s %s", s1, s2);
	leejin_sum(s1, s2);
	printf("%s", s1);
	return 0;
}
#endif

#if 0
/*개가 말이된다고?!*/
void dog2horse(char* str1, char* str2, char* str3) {
	char* s1 = str1, * s2 = str2, * s3 = str3;
	int len1 = 0, len2 = 0, len3 = 0, sublen, idx, s1idx = 0;
	while (*s1++ != NULL) len1++;
	while (*s2++ != NULL) len2++;
	while (*s3++ != NULL) len3++;
	s1 = str1;
	s2 = str2;
	s3 = str3;
	sublen = len3 - len2;
	while (*s1 != NULL) {
		idx = 0;
		if (*s1 == *s2) {
			while (*(s1 + idx) == *(s2 + idx) && *(s1 + idx) != NULL) idx++;
			if (idx == len2) {
				if (sublen > 0) {
					for (int i = len1 + sublen - 1; i >= s1idx; i--) {
						*(str1 + i) = *(str1 + i - sublen);
					}
					len1 += sublen;
				}
				else {
					for (int i = s1idx; i < len1; i++) {
						*(str1 + i) = *(str1 + i - sublen);
					}
					len1 += sublen;
				}
				for (int i = 0; i < len3; i++) {
					*(s1 + i) = *(s3 + i);
				}
			}
		}
		s1idx++;
		s1++;
	}
}
int main() {
	char s1[101] = { 0 }, s2[101], s3[101];
	gets(s1);
	scanf("%s %s", s2, s3);
	dog2horse(s1, s2, s3);
	puts(s1);
	return 0;
}
#endif

#if 0
/*개가 말이되는 과정*/
char* dog2horse(char* str1, char* str2, char* str3) {
	static char* ss = NULL;
	char* s1, * s2 = str2, * s3 = str3;
	int len1 = 0, len2 = 0, len3 = 0, sublen, idx, s1idx = 0;
	if (str1 != NULL) ss = str1;
	s1 = ss;
	while (*s1++ != NULL) len1++;
	while (*s2++ != NULL) len2++;
	while (*s3++ != NULL) len3++;
	s1 = ss;
	s2 = str2;
	s3 = str3;
	sublen = len3 - len2;
	while (*s1 != NULL) {
		idx = 0;
		if (*s1 == *s2) {
			while (*(s1 + idx) == *(s2 + idx) && *(s1 + idx) != NULL) idx++;
			if (idx == len2) {
				if (sublen > 0) {
					for (int i = len1 + sublen - 1; i >= s1idx; i--) {
						*(ss + i) = *(ss + i - sublen);
					}
					len1 += sublen;
				}
				else {
					for (int i = s1idx; i < len1; i++) {
						*(ss + i) = *(ss + i - sublen);
					}
					len1 += sublen;
				}
				for (int i = 0; i < len3; i++) {
					*(s1 + i) = *(s3 + i);
				}
				return s1;
			}
		}
		s1idx++;
		s1++;
	}
	return NULL;
}
int main() {
	char s1[101] = { 0 }, s2[101], s3[101], * p;
	gets(s1);
	gets(s2);
	gets(s3);
	p = dog2horse(s1, s2, s3);
	printf("\n");
	while (p) {
		puts(s1);
		p = dog2horse(NULL, s2, s3);
	}
	return 0;
}
#endif

#if 0
/*4X4 3바이트*/
int main() {
	unsigned char s[4][4];
	for (int i = 0; i < 3; i++) scanf("%u", s[i]);
	for (int i = 0; i < 4; i++) {
		unsigned int* p;
		p = (unsigned int*)&s[(i * 3) / 4][(i * 3) % 4];
		printf("%u ", *p & 0x00FFFFFF);
	}
	return 0;
	}
#endif

#if 0
/*돌아온 펠린드롬*/
// ============== 코드 작성 영역 ==============

char* returned_palindrome(char* str)
{
	static char* s = NULL;
	char* s2;
	int len = 0, flag = 1;
	if (str != NULL) s = str;
	else s++;
	s2 = s;
	while (*s2++ != NULL) len++;
	while (*s != NULL) {
		flag = 1;
		for (int i = 0; i < len / 2; i++) {
			if (*(s + i) != *(s + len - i - 1)) {
				flag = 0;
				break;
			}
		}
		if (flag) return s;
		else len--;
		if (len == 1) break;
		s++;
	}
	return NULL;
}

// ============================================

int main(int argc, char const* argv[])
{
	char str1[104];
	gets(str1);
	char* p = returned_palindrome(str1);
	if (p == NULL)
	{
		printf("yatppi!");
	}
	while (p)
	{
		printf("%s\n", p);
		p = returned_palindrome(NULL);
	}
	return 0;
}
#endif

#if 0
/*sprintf*/
int main() {
	char s[100];
	sprintf(s, "%d%d%s", 1123, 34325, "asfgasg");
	printf("%s", s);
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

