#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// ���� ������ (�迭�� ������)
// �ּҴ� �������� �� ������
// 
#if 0
int main() {
	char* p1 = NULL, p2[100], * p3, * p4[5];

	scanf_s("%s", p1, 100);  // ǥ�� scanf�� ���ȿ� ����ϴ� �����ϴ� ���, 100�� �ִ����
	printf("%s\n", p1);

	scanf_s("%s", p2, 100);  // p1�� p2�� ���̴�?
	printf("%s\n", p2);		 // ���� ������ ����   p1�� �ȵȴ�. p2�� �ȴ�.
	return 0;
}
#endif


// x�� �ܾ���Ͽ� �迭�� �ֱ�?

#if 0
int main() {
	char p2[101], * p3, * p4[5], i = 0, j = 0;

	scanf_s("%s", p2, 100);  // p2�� �Է¹ޱ�
	printf("%s\n", p2);

	p3 = p2;  // p3�� p2�� �ڵ鸵�� ������
	p4[j++] = p3;  // p4�� �迭�� ������. �ܾ� ��ġ ����
	while (*p3) {
		if (*p3 == 'x') {  // 'x'�� ã�ƾ���
			// 'x'�� ã���� �ؾ��� �� 2����      NULL �����, ��ġ ����ϰ�
			*p3 = NULL;
			p4[j++] = p3 + 1;
		}
		p3++;  // ���� ��ġ�� �ű�
	}		   // �ݺ��ؼ� �ϼ�

	for (i = 0; i < j; i++) {
		// �迭�� �����͸� �̿��ؼ� ���
		printf("%s\n", *(p4 + i));
	}
	return 0;
}
#endif


// �����޸� �Ҵ��� ���� (malloc)
// ���Ӽ�    �迭�� ��� ���� ������
//
// int** m = (int**)malloc(sizeof(int*) * 3);
// m[0] = (int*)malloc(sizeof(int) * 4);
// m[1] = (int*)malloc(sizeof(int) * 4);
// m[2] = (int*)malloc(sizeof(int) * 4);
// ���� 3���� 4�� �������� ������������ ���ΰ� ������������ ���� (�迭ó�� �پ����� ����)
// 
// free() �� ��
// �ݵ�� ���� �ͺ���
// ū�� �����ϸ� ���� �޸� �������� ���ٵ� ���ϰ� ����� �� �� ���� �ƹ��� ������ ������ ��
//
#if 0
void set_proverb(char* q);

int main() {
	char* s = NULL;  // s�� �� == NULL

	set_proverb(s);  // NULL�� �ѱ�, ���纹�� �Ѿ
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char* q) {  // ���纻 NULL�� �Ѿ��, q�� �ʱⰪ == NULL,  s�� q�� �ٸ���
	static char* str1 = "A friend in need is a friend indeed";
	static char* str2 = "A little knowledge is a dangerous thing";

	q = str1;  // q�� str1�� ����Ű����, q�� s�� �ٸ��� ������ �Լ��� ������ s�� ������ ����
	// swap �Լ�ó�� s�� �ּҸ� �Ѱ��־�� s�� ���� ���� ����
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

void set_proverb(char** q) {  // s�� �������̹Ƿ� s�� �ּҸ� ������, �ּ��� �ּ��̱� ������ ������ ������� **
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

void process(char** q) {    // s�� ������ �迭�̶�, �����͵� 2������ �ش��ϴ� ���� �����ͷ� �޾Ҵ�. ������??
							// q�� q[1][0]�� �̾��ִ� ������ ���� �� ������ ����
	char tmp[4];
	q[1][0] = '7';			// 4+4 �� �����̴�, 5��° �����͸� �����Ѿ� �Ѵ�. 1*4 + 0 =4��(5��°) ������,
							// �� 1*4 + 0 ���� �� �����Լ� q�� ������ �˰� ������ �𸣰ڴ°�?
	return;
}							// �׷��� ���� ������ �̾��°�?  q�� s�� ������ �𸣱� ���� ���� ���� ũ�⸦ ���� ([4]�� ����)
#endif
	
// �迭�� ������ ���� ���
// 
// 2���� �迭 �̸��� ��ġ�ϴ� ������ ����
// int arr[2][4];  -->  int (*pArr)[4];
// int --> int �� ������ ����Ų��.    int �� �������̴�.
// (*pArr) --> pArr�� ������    �׳� �������̴�.
// [4] --> 4ĭ�� �ǳʶڴ�    ���� ����
//

// �Ű������� ����� ���� �̷��� �ᵵ ������
// void show_data(int (*ptr)[4], int a);
// ==
// void show_data(int ptr[][4], int a);
// �׷��� ����ÿ��� �׷��� ���� �ȵȴ� (���ڷ� �� ���� ����)

// ������ �迭�� �迭 �������� ���� ����!
// 
// 3���� 4���� �迭�� ����� �� �迭�� �ٸ� �Լ����� �ڵ鸵 �� �� �ִ� �迭�� ������ �����   �ݵ�� �ݵ�� �ݵ��
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

// ���� �غ���
// sizeof �����غ��� �� Ȯ���غ���
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

// 3����?
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
�Է� ���� ����
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
// ============== �ڵ� �ۼ� ���� ==============
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
/*�Է� ���� ����
Do    you   like      my  car
��� ���� ����
car my like you Do*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ======== �ڵ� �ۼ� ���� ========
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
/*������ ���ڿ� ���ϱ�*/
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
/*���� ���̵ȴٰ�?!*/
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
/*���� ���̵Ǵ� ����*/
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
/*4X4 3����Ʈ*/
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
/*���ƿ� �縰���*/
// ============== �ڵ� �ۼ� ���� ==============

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

