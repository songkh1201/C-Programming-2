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

	a[0] = 'n';  // 가능
	b[0] = 'n';  // 가능
	p[0] = 't';  // 불가

	printf("%s\n%s\n%s\n", a, b, p);
	return 0;

	// 텍스트 세그먼트
	//		- 코드
	//		- 상수
	// 데이터 세그먼트
	//		- 전역변수
	//		- 정적변수
	// 스택
	//		- 함수가 사용하는 메모리
	// 힙
	//		- 포인터로 접근하는 메모리
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

// 이진탐색
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

// 이진탐색 답
#if 0
int binary_search(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high) {			  // 아직 숫자들이 남아있으면
		middle = (low + high) / 2;	  // 중간 요소 결정
		if (key == list[middle])	  // 일치하면 탐색 성공
			return middle;
		else if (key > list[middle])  // 중간 원소보다 크다면
			low = middle + 1;		  // 새로운 값으로 low 설정
		else
			high = middle - 1;		  // 새로운 값으로 high 설정
	}
	return -1;
}
int binary_search_bandae(int list[], int n, int key) {
	int low, high, middle;
	low = 0;
	high = n - 1;
	while (low <= high) {			  // 아직 숫자들이 남아있으면
		middle = (low + high) / 2;	  // 중간 요소 결정
		if (key == list[middle])	  // 일치하면 탐색 성공
			return middle;
		else if (key < list[middle])  // 중간 원소보다 크다면
			low = middle + 1;		  // 새로운 값으로 low 설정
		else
			high = middle - 1;		  // 새로운 갑으로 high 설정
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

// 복잡한 포인터
#if 0
int main() {
	char* s1 = "Hello";  // 만들어진 변수공간은 4바이트

	scanf("%s", s1);  // 불가, 텍스트영역은 read only
	
	printf("%s\n", s1);
	// 스캔하기 위해서는 반드시 저장될 공간이 있어야함
	// 그 공간이 여기에는 없음
	return 0;
}
#endif

// 동적할당
// 
// 메모리 할당
//	정적할당(static allocation): 변수의 타입, 저장장소 등이 컴파일 시간(compile-time)에 결정
//	동적할당(dynamic allocation): 변수의 타입, 저장장소 등이 수행 시간(run-time)에 결정
// 
// 정적할당 array
//	int i[100];
//	i[10] = 10;
// 동적할당 array
//	int* aptr;
//	aptr = (int*)malloc(100 * sizeof(int));
//	aptr[10] = 10; ...
//	free(i);  // 중요

// malloc() 이용
//	int* pn = (int*)malloc(sizeof(int));  // 그냥 숫자로 쓰는것보다 계산식을 표현해주는게 좋다
//	c++에서는 int* pn = new int;
// 
// 프로그램 영역     Text.exe
// 초기화된 데이터 영역   int i = 8;
// 초기화 되지 않은 데이터 영역   int j[num];
// Heap(보통 전역변수 저장공간)
//		int* k = new int;
//		함수 호출시에 사용
// Stack(보통 지역변수 저장공간)

// malloc를 사용한 동적배열의 생성
// 
// 동적 메모리의 필요성
//	커다란 데이터를 정적으로 할당하는 것은 비효울적일 수 있음
//	바인딩 시간
//		객체의 타입, 저장 장소 등이 확정되는 시간
//		동적 메모리는 실행 시간에 바인딩
// 동적 배열 정의
//	실행 시간에 생성되는 배열
// 동적 배열의 생성
//	int* pn;     pn = (int*)malloc(sizeof(int) * 10));
//	컴파일 시간에는 pn(포인터)를 위한 공간만 할당
//		실행시간에 10개의 원소를 갖는 배열 생성

// free를 사용한 메모리 해제
// 
// 동적 메모리의 할당과 해제는 프로그래머의 책임
// 명시적으로 할당/해제 --> 내가 써야할 곳에 반드시 써야하고 다 쓰고나면 내가 알아서 해제를 해줘야함
// 예
// int* ps = (int*)malloc(sizeof(int));
// 
// free(ps);	// O
// free(ps);	// X 이미 한번 해제함
// 
// int jugs = 5;	// O
// int* pi = &jugs; // O
// 
// free(pi);	// X pi에 뭔가를 할당하긴 했지만 동적으로 공간을 만들고 할당한 것이 아니라 이전에 있던 정적공간을 할당함

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

// 2차원 배열 할당
// 
// int** pn = (int**)malloc(sizeof(int)*row*col);
// 컴파일은 된다. 하지만 원하는 뜻을 되지 않는다.
// malloc() 함수의 인자는 메모리의 크기이고, return 형태는 그 메모리를 어떤 조각으로 나눌 것인지를 알려주는 것
// 따라서 row * col 의 구조를 나타낼 수 없다. 배열처럼 자동으로 쓸 수가 없다.
// 나눠서 구성해 주어야 한다.
// 
// m 변수를
// int iarray[3][5]; 와 같은 형태를 만들고자 할 때는
// 
// int** m = (int**)malloc(sizeof(int*) * 3);
// m[0] = (int*)malloc(sizeof(int) * 5);
// m[1] = (int*)malloc(sizeof(int) * 5);
// m[2] = (int*)malloc(sizeof(int) * 5);
// 와 같이 구분해서 작성해 주어야 한다.
// 
// free도 순서대로
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

	// m의 주소값과, m의 값, m[0],[1],[2] 의 값을 확인해보자
	// 어떤 뜻으로 해석할 수 있는가?
	// 같은 의미로 array의 값과, array[0],[1],[2] 의 값을 확인해보자.

	return 0;
}
#endif

// 응용
// "abcdefg" 문자열 상수를 가리키는 char* 변수 p가 있다.
// count를 위한 int형 변수 i도 있다.
// 이 변수가 실행중에 소문자 26글자를 가리키게 프로그램 하자.
#if 0
#include<stdlib.h>
int main() {
	char* p = "abcdefg";
	int count = 0;
	
	p = (char*)malloc(sizeof(char) * 27);  // "abcdefg"의 위치는 이제 분실.

	scanf("%s", p);  // 소문자 26글자 입력

	printf("%s\n", p);

	free(p);
	return 0;
	// 소문자 26개는 문자열인가? 문자인가?  같은것, 문자들 끝에 null이 있으면 문자열
	// 소문자 26개는 변수인가? 상수인가?  변수
	// 상수이면 왜 상수이고, 변수이면 무엇이 변수인가?  처음에 "abcdefg"는 문자열 상수이고 내가 입력한 것은 변수
	// 변수 p는 그 크기가 1개에서 26개로 변경된 것인가?
	//	아니면 7개에서 26개로 변경된 것인가?  p가 늘어난 것이 아니고, 내가 27개 새로 만든것을 가리키는 역할
}
#endif

// 이중 포인터(double pointer): 포인터를 가리키는 포인터
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

// 예제2
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
// 1. 무엇을 하려는 것인가?
// 2. 어떻게 되겠는가?
// 3. 잘되는 이유는? 혹은 안되는 이유는?
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
	// static은 그 값이 유지되는 것, 함수가 지나도, 전역변수처럼
	*q = str1;
}
#endif


// 포인터 배열
// 포인터를 모아서 배열로 만든것
// 
// int a=10, b=20, c=30, d=40, e=50;
// int* pa[5] = { &a, &b, &c, &d, &e };

// 문자열 배열
//	가장 많이 사용되는 포인터 배열
//	문자열들을 효율적으로 저장할 수 있다.
// 
// char* fruits[] = {
//		"apple",
//		"blueberry",
//		"orange",
//		"melon"
// };
// 
// 다음의 값을 조사하고 그 결과값으로 내용을 분석해 보자.
// - fruits
// - &fruits
// - &fruits[0]
// - fruits[0];
// - fruits[0][0]
// 상대값으로 비교(fruits를 빼서)
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
	// &fruits + 1  // 초과

	return 0;
}
#endif

// fruits[0] = "xyz"; 는 가능하겠는가?  가능
// fruits[0][1] = "xyz"; 는  가능하겠는가?  잘못된표현
// 
// fruits[1][2] = 'X' 는 가능하겠는가?  불가능
//
#if 0
int main() {

	return 0;
}
#endif
// 문자열들을 저장하는 2차원 배열
//	공간의 낭비가 발생할 수 있다.
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
	p = fname[0];  // fname[0]은 첫번째 덩어리인 "apple"의 a주소, 틀림
	printf("%s\n", p);

	p = fname;  // fname은 첫번째 덩어리인 "apple"의 주소, 틀림
	printf("%s\n", p);
	return 0;
}
#endif
// 블루베리 왜 안나오는데??
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

// 버블솔트
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

	strcpy(c1, "edcba");  // 복사 불가
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

