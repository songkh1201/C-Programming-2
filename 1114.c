#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>


#if 0
#define SIZE 10
int main() {
	int grade[SIZE];
	int sum = 0;
	int i, average;

	for (i = 0; i < SIZE; i++)
		grade[i] = rand() % 100;

	for (i = 0; i < SIZE; i++)
		printf("%5d   %5d\n", i, grade[i]);
	return 0;
}
#endif

#if 0
int main() {

	char a[] = "rose";
	char b[] = "rose";
	char* p = "grace";

	a[0] = 'n';  // ����
	b[0] = 'n';  // ����
	p[0] = 't';  // �Ұ�

	printf("%s\n%s\n%s\n", a, b, p);
	return 0;

	// �ؽ�Ʈ ���׸�Ʈ
	//		- �ڵ�
	//		- ���
	// ������ ���׸�Ʈ
	//		- ��������
	//		- ��������
	// ����
	//		- �Լ��� ����ϴ� �޸�
	// ��
	//		- �����ͷ� �����ϴ� �޸�
	//
}
#endif

#if 0
int main() {

	char a[] = "rose";
	char* p = "%s\n";

	a[0] = 'n';

	printf(p, a);
	return 0;
}
#endif

#if 0
#include<string.h>
int main() {
	char* c1 = "abcde";
	char c2[] = "abcde";

	printf("%s %s\n", c1, c2);

	// strcpy(c1, "edcba");
	strcpy(c2, "edcba");

	printf("%s %s\n", c1, c2);
	return 0;
}
#endif

// ����Ž��
#if 0
int main() {
	int arr[16], idx, low = 0, high = 15, num;
	for (int i = 0; i < 16; i++) arr[i] = i * 2;
	scanf("%d", &num);
	while (1) {
		idx = (high + low) / 2;
		if (arr[idx] == num) {
			break;
		}
		else if (high <= low) {
			idx = -1;
			break;
		}
		else if (arr[idx] > num) {
			high = idx - 1;
		}
		else if (arr[idx] < num) {
			low = idx + 1;
		}
	}
	printf("%d", idx);
	return 0;
}
#endif

// ����Ž�� ��
#if 0
int binary_search(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high) {			  // ���� ���ڵ��� ����������
		middle = (low + high) / 2;	  // �߰� ��� ����
		if (key == list[middle])	  // ��ġ�ϸ� Ž�� ����
			return middle;
		else if (key > list[middle])  // �߰� ���Һ��� ũ�ٸ�
			low = middle + 1;		  // ���ο� ������ low ����
		else
			high = middle - 1;		  // ���ο� ������ high ����
	}
	return -1;
}
int binary_search_bandae(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high) {			  // ���� ���ڵ��� ����������
		middle = (low + high) / 2;	  // �߰� ��� ����
		if (key == list[middle])	  // ��ġ�ϸ� Ž�� ����
			return middle;
		else if (key < list[middle])  // �߰� ���Һ��� ũ�ٸ�
			low = middle + 1;		  // ���ο� ������ low ����
		else
			high = middle - 1;		  // ���ο� ������ high ����
	}
	return -1;
}
int main() {
	int arr[16], idx, low = 0, high = 15, num, arr2[16];
	for (int i = 0; i < 16; i++) arr[i] = i * 2;
	for (int i = 0; i < 16; i++) arr2[i] = 30 - (i * 2);
	scanf("%d", &num);
	printf("%d %d", binary_search(arr, 16, num), binary_search_bandae(arr2, 16, num));
	return 0;
}
#endif

// ������ ������
#if 0
int main() {
	char* s1 = "Hello";  // ������� ���������� 4����Ʈ

	scanf("%s", s1);  // �Ұ�, �ؽ�Ʈ������ read only
	
	printf("%s\n", s1);
	// ��ĵ�ϱ� ���ؼ��� �ݵ�� ����� ������ �־����
	// �� ������ ���⿡�� ����
	return 0;
}
#endif

// �����Ҵ�
// 
// �޸� �Ҵ�
//	�����Ҵ�(static allocation): ������ Ÿ��, ������� ���� ������ �ð�(compile-time)�� ����
//	�����Ҵ�(dynamic allocation): ������ Ÿ��, ������� ���� ���� �ð�(run-time)�� ����
// 
// �����Ҵ� array
//	int i[100];
//	i[10] = 10;
// �����Ҵ� array
//	int* aptr;
//	aptr = (int*)malloc(100 * sizeof(int));
//	aptr[10] = 10; ...
//	free(i);  // �߿�

// malloc() �̿�
//	int* pn = (int*)malloc(sizeof(int));  // �׳� ���ڷ� ���°ͺ��� ������ ǥ�����ִ°� ����
//	c++������ int* pn = new int;
// 
// ���α׷� ����     Text.exe
// �ʱ�ȭ�� ������ ����   int i = 8;
// �ʱ�ȭ ���� ���� ������ ����   int j[num];
// Heap(���� �������� �������)
//		int* k = new int;
//		�Լ� ȣ��ÿ� ���
// Stack(���� �������� �������)

// malloc�� ����� �����迭�� ����
// 
// ���� �޸��� �ʿ伺
//	Ŀ�ٶ� �����͸� �������� �Ҵ��ϴ� ���� ��ȿ������ �� ����
//	���ε� �ð�
//		��ü�� Ÿ��, ���� ��� ���� Ȯ���Ǵ� �ð�
//		���� �޸𸮴� ���� �ð��� ���ε�
// ���� �迭 ����
//	���� �ð��� �����Ǵ� �迭
// ���� �迭�� ����
//	int* pn;     pn = (int*)malloc(sizeof(int) * 10));
//	������ �ð����� pn(������)�� ���� ������ �Ҵ�
//		����ð��� 10���� ���Ҹ� ���� �迭 ����

// free�� ����� �޸� ����
// 
// ���� �޸��� �Ҵ�� ������ ���α׷����� å��
// ��������� �Ҵ�/���� --> ���� ����� ���� �ݵ�� ����ϰ� �� ������ ���� �˾Ƽ� ������ �������
// ��
// int* ps = (int*)malloc(sizeof(int));
// 
// free(ps);	// O
// free(ps);	// X �̹� �ѹ� ������
// 
// int jugs = 5;	// O
// int* pi = &jugs; // O
// 
// free(pi);	// X pi�� ������ �Ҵ��ϱ� ������ �������� ������ ����� �Ҵ��� ���� �ƴ϶� ������ �ִ� ���������� �Ҵ���

#if 0
#include<stdlib.h>
int main() {
	int* pn, i;

	pn = (int*)malloc(sizeof(int) * 10);

	for (i = 0; i < 10; i++) {
		pn[i] = i * 10;
	}

	printf("%d, %d\n", pn[5], *(pn + 5));

	free(pn);
	return 0;
}
#endif

// 2���� �迭 �Ҵ�
// 
// int** pn = (int**)malloc(sizeof(int)*row*col);
// �������� �ȴ�. ������ ���ϴ� ���� ���� �ʴ´�.
// malloc() �Լ��� ���ڴ� �޸��� ũ���̰�, return ���´� �� �޸𸮸� � �������� ���� �������� �˷��ִ� ��
// ���� row * col �� ������ ��Ÿ�� �� ����. �迭ó�� �ڵ����� �� ���� ����.
// ������ ������ �־�� �Ѵ�.
// 
// m ������
// int iarray[3][5]; �� ���� ���¸� ������� �� ����
// 
// int** m = (int**)malloc(sizeof(int*) * 3);
// m[0] = (int*)malloc(sizeof(int) * 5);
// m[1] = (int*)malloc(sizeof(int) * 5);
// m[2] = (int*)malloc(sizeof(int) * 5);
// �� ���� �����ؼ� �ۼ��� �־�� �Ѵ�.
// 
// free�� �������
// free(m[0]);
// free(m[1]);
// free(m[2]);
// 
// free(m);
//

#if 0
#include<stdlib.h>
int main() {
	int array[3][4];
	int** m;

	m = (int**)malloc(sizeof(int*) * 3);

	m[0] = (int*)malloc(sizeof(int) * 5);
	m[1] = (int*)malloc(sizeof(int) * 5);
	m[2] = (int*)malloc(sizeof(int) * 5);

	// m�� �ּҰ���, m�� ��, m[0],[1],[2] �� ���� Ȯ���غ���
	// � ������ �ؼ��� �� �ִ°�?
	// ���� �ǹ̷� array�� ����, array[0],[1],[2] �� ���� Ȯ���غ���.

	return 0;
}
#endif

// ����
// "abcdefg" ���ڿ� ����� ����Ű�� char* ���� p�� �ִ�.
// count�� ���� int�� ���� i�� �ִ�.
// �� ������ �����߿� �ҹ��� 26���ڸ� ����Ű�� ���α׷� ����.
#if 0
#include<stdlib.h>
int main() {
	char* p = "abcdefg";
	int count = 0;
	
	p = (char*)malloc(sizeof(char) * 27);  // "abcdefg"�� ��ġ�� ���� �н�.

	scanf("%s", p);  // �ҹ��� 26���� �Է�

	printf("%s\n", p);

	free(p);
	return 0;
	// �ҹ��� 26���� ���ڿ��ΰ�? �����ΰ�?  ������, ���ڵ� ���� null�� ������ ���ڿ�
	// �ҹ��� 26���� �����ΰ�? ����ΰ�?  ����
	// ����̸� �� ����̰�, �����̸� ������ �����ΰ�?  ó���� "abcdefg"�� ���ڿ� ����̰� ���� �Է��� ���� ����
	// ���� p�� �� ũ�Ⱑ 1������ 26���� ����� ���ΰ�?
	//	�ƴϸ� 7������ 26���� ����� ���ΰ�?  p�� �þ ���� �ƴϰ�, ���� 27�� ���� ������� ����Ű�� ����
}
#endif

// ���� ������(double pointer): �����͸� ����Ű�� ������
// int i = 100;
// int* p = &i
// int** q = &p;
#if 0
int main() {
	int i = 100;
	int* p = &i;
	int** q = &p;

	*p = 200;
	printf("i=%d  *p=%d  **q=%d\n", i, *p, **q);

	**q = 300;
	printf("i=%d  *p=%d  **q=%d\n", i, *p, **q);
	return 0;
}
#endif

// ����2
#if 0
void set_proverb(char* q);

int main() {
	char* s = NULL;

	set_proverb(s);
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char* q) {
	static char* str1 = "A friend in need is a friend indeed";
	static char* str2 = "A little knowledge is a dangerous thing";

	q = str1;
}
// 1. ������ �Ϸ��� ���ΰ�?
// 2. ��� �ǰڴ°�?
// 3. �ߵǴ� ������? Ȥ�� �ȵǴ� ������?
//
//
#endif
#if 0
void set_proverb(char** q);

int main() {
	char* s = NULL;

	set_proverb(&s);
	printf("selected proverb = %s\n", s);
	return 0;
}

void set_proverb(char** q) {
	static char* str1 = "A friend in need is a friend indeed";
	static char* str2 = "A little knowledge is a dangerous thing";
	// static�� �� ���� �����Ǵ� ��, �Լ��� ������, ��������ó��
	*q = str1;
}
#endif


// ������ �迭
// �����͸� ��Ƽ� �迭�� �����
// 
// int a=10, b=20, c=30, d=40, e=50;
// int* pa[5] = { &a, &b, &c, &d, &e };

// ���ڿ� �迭
//	���� ���� ���Ǵ� ������ �迭
//	���ڿ����� ȿ�������� ������ �� �ִ�.
// 
// char* fruits[] = {
//		"apple",
//		"blueberry",
//		"orange",
//		"melon"
// };
// 
// ������ ���� �����ϰ� �� ��������� ������ �м��� ����.
// - fruits
// - &fruits
// - &fruits[0]
// - fruits[0];
// - fruits[0][0]
// ��밪���� ��(fruits�� ����)
#if 0
int main() {
	char* fruits[] = {
		"apple",
		"blueberry",
		"orange",
		"melon"
	};
	
	printf("%p\n", fruits);
	printf("%p\n", &fruits);
	printf("%p\n", fruits[0]);
	printf("%p\n", fruits[1]);
	printf("%p\n", &fruits[1]);
	printf("%p\n", &fruits[0][0]);
	printf("%s\n", fruits[0]);
	printf("%c\n", fruits[0][0]);
	// fruits == &fruits == &fruits[0]             // 1000
	// fruits + 1 == &fruits[1] == &fruits[0] + 1  // 1004
	// fruits[0] == &fruits[0][0] ("apple")		   // 8000
	// fruits[1] == &fruits[1][0] ("blueberry")	   // 8100
	// fruits[0] + 1 == &fruits[0][1] ("pple")	   // 8001
	// &fruits + 1  // �ʰ�

	return 0;
}
#endif

// fruits[0] = "xyz"; �� �����ϰڴ°�?  ����
// fruits[0][1] = "xyz"; ��  �����ϰڴ°�?  �߸���ǥ��
// 
// fruits[1][2] = 'X' �� �����ϰڴ°�?  �Ұ���
//
#if 0
int main() {

	return 0;
}
#endif
// ���ڿ����� �����ϴ� 2���� �迭
//	������ ���� �߻��� �� �ִ�.
// char fname[][10] = {
//		"apple",
//		"blueberry",
//		"orange",
//		"melon"
// };
// a p p l e \0 - - - -
// b l u e b e r r y \0
// o r a n g e \0 - - -
// m e l o n \0 - - - -

#if 0
int main() {
	char fname[][10] = {
		"apple",
		"blueberry",
		"orange",
		"melon"
	};

	char** p;
	p = fname[0];  // fname[0]�� ù��° ����� "apple"�� a�ּ�, Ʋ��
	printf("%s\n", p);

	p = fname;  // fname�� ù��° ����� "apple"�� �ּ�, Ʋ��
	printf("%s\n", p);
	return 0;
}
#endif
// ��纣�� �� �ȳ����µ�??
#if 0
int a;
int main() {
	char* fruits[10] = {
		"apple",
		"blueberry",
		"orange",
		"melon"
	};
	printf("%d %d %d %d\n%p\n", fruits[0] - fruits[0], fruits[1] - fruits[0], fruits[2] - fruits[0], fruits[3] - fruits[0], &a);

	char** p;
	p = fruits[0];
	printf("%c, %s, %s\n", *p, p,  *(&fruits[0] + 1));
	printf("%c, %c, %d\n", p[0], p[1], sizeof(p));

	p = fruits;
	printf("%s\n", *p);
	printf("%c, %s, %s\n", p[0][1], p[0], *(p + 1));
	return 0;
}
#endif

// char* arr[5] = {
//		"abc",			// 8000
//		"12345",		// 8100
//		"ddfhsdfhsdfh",	// 8200
//		"0934872435",	// 8300
//		"a0sd89uf"		// 8400
// };
// char** p = arr;
// ----------------------------------------------------------------------
// | arr        | arr + 1     | arr + 2 | &arr      | arr[0] | arr[1]   |
// | 1000       | 1004        | 1008    | 1000      | 8000   | 8100     |
// ----------------------------------------------------------------------
// | arr[0] + 1 | arr[1] + 1  | &arr[1] | arr[1][2] | &arr+1 |          |
// | 8001       | 8101        | 1004    | 3         | 1020   |          |
// ----------------------------------------------------------------------
// | p          | &p		  | p[0]    | p[1]      | p + 1  | p[1] + 1 |
// | 1000       | 1500        | 8000    | 8100      | 1004   | 8101     |
// ----------------------------------------------------------------------
// | p[1][1]    | p[0][1] + 1 |         | &p[1]     |                   |
// | 2          | c           |         | 1004      |                   |
// ----------------------------------------------------------------------
#if 0
int main() {
	 char* arr[5] = {
		"abc",			// 8000
		"12345",		// 8100
		"ddfhsdfhsdfh",	// 8200
		"0934872435",	// 8300
		"a0sd89uf"		// 8400
	};
	 char** p = arr;

	 printf("%d\n", arr);
	 printf("%d\n", arr + 1);
	 printf("%d\n", arr + 2);
	 printf("%d\n", &arr);
	 printf("%d\n", arr[0]);
	 printf("%d\n", arr[1]);
	 printf("%d\n", arr[0] + 1);
	 printf("%d\n", arr[1] + 1);
	 printf("%d\n", &arr[1]);
	 printf("%d\n", arr[1][2]);
	 printf("%d\n", &arr + 1);

	 printf("%d\n", p[0]);
	 printf("%d\n", p[1]);
	 printf("%d\n", p + 1);
	 printf("%d\n", p[1] + 1);
	 printf("%d\n", p[1][1]);
	 printf("%d\n", p[0][1] + 1);
	 printf("%d\n", &p[1]);
	 printf("%d\n", *arr);
	 printf("%d\n", *arr + 1);

	 return 0;
}
#endif

// �����Ʈ
#if 0
int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

int main() {

	char* c1 = "abcde";
	char c2[] = "abcde";

	printf("%s %s\n", c1, c2);

	strcpy(c1, "edcba");  // ���� �Ұ�
	strcpy(c2, "edcba");

	printf("%s %s\n", c1, c2);

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

