#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 데이터 형에 따라 읽지 말고 덩어리로 보기

// 포인터 변수
// 포인터 변수는 메모리의 번지(주소)를 저장하는 데 쓰이는 "변수"이다.
// 앞의 예제들에서 봤던, 1004, 1008 같은 주소를 저장하고, 이를 처리할 수 있는(읽고, 값을 바꾸는 등) 것이, 포인터 변수이다. 
// 포인터 변수가 저장하고 있던 값을 바꾼다는 것은 가리키는 메모리 위치를 변경한다는 의미
// 컴퓨터에서 모든 데이터는 바이트 단위로 주소를 가지고 있다.
// 따라서 저장되는 주소는 바이트의 주소이다
// 그러나, 그 주소로부터 1바이트, 2바이트, 4바이트 등이 하나의 데이터 일 수 있다. 
// 그것을 구분해 주는 것이 포인터 변수의 형(type, 즉 char, int) 등이다.
// 
// 왜 필요한가
// 필요에 따라 가리키고, 변경시키고 하는등의 처리할 필요성
// 특히 메모리를 직접 가리키고, 처리할 수 있는 C언어는 그런 용도의 요구가 아주 많다
// 
// 예를 들어
// unsigned short int i[3] = {0x1234, 0x5678, 0xABCD};
// 이런 데이터가 있을 떄 메모리값은
// 0x34  0x12  0x78  0x56  0xCD  0xAB
// 이 떄 unsigned char 포인터 p가 0x12의 바이트를 가리킨다고 생각해보자.
// p가 가리키는 위치에 따라 바이트 값을 읽을 수 있다.
// 같은 방법으로 unsigned short int 포인터 pi가 역시 같은 0x12 바이트를 가리키게 할 수도 있다.
// 이 때는 전혀 새로운 값을 pi가 읽게 된다. (0x12와 0x78의 결합 = 0x7812) 짝수 바이트이기 때문에 읽을 때는 거꾸로
// 메모리에 값이 있으면 포인터로 원하는 형태로 값을 읽을 수 있다.
// 0xCD567812의 unsigned int 값도 읽을 수 있다.(저장 & 읽기) 동일하게 거꾸로
// 
// 선언
// 변수 앞에 * 붙임, *은 1개 이상 붙일 수 있다
// int *p;   정수형 변수의 주소에 대한 포인터 변수 p의 선언, 크기는 4바이트 하지만 1000번지 가서 보면 int
// char *p;  문자형 변수의 주소에 대한 포인터 변수 p의 선언, 크기는 4바이트 하지만 1000번지 가서 보면 char
// 변수의 타입(int, char, float, ...)에 따라서 별개의 포인터 변수를 사용해야 한다.
// int *p; 를 만들면 3가지가 생김
// p, &p, *p -- 주소, 변수 p의 주소, 포인터가 가리키는 주소 안의 값
// 
// 포인터 변수는 각 데이터 타입별로 있다.
// - 정수포인터, 문자포인터, …
// - 각데이터 타입의 크기가 다르기 때문에
// * 데이터 타입의 크기에 따라서 메모리에서 차지하는 영역이 다르다.
// * 더 후반부에 배우겠지만, struct와 같이 사용자가 지정한 임의의 크기를 가지는 메모리도 포인터로 가리키며 연산할 수 있다.
// - 포인터 관련해서 코딩 때 주의할 것은 해당 포인터가 정확하게 무엇을(어디에서 어디까지를, 혹은 몇바이트를) 가리키는지를 알아야한다.
// 그래야 + -등 연산을 정확하게 할 수 있다.
// - 메모리를 가리킴으로써 생기는 다양한 효과를 이해해야 한다.
// 
// 포인터 변수의 초기화
// int *p, i;		- 정수포인터변수 p와 정수변수 i의 선언
// p = 0;			- p에 0번지를 넣는다
// p = NULL;		-여기서 NULL은 0번지와 같다.
// p = &i;			-p에 i의 주소(번지)값을 넣는다.
// p = (int*)1776;  -p에 정수상수 1776을 정수포인터로 변환한 값을 넣는다.  // 비주얼스튜디오에서 불가능, 일반프로그램에서 의미X, 임베디드 프로그램에서 사용
// 
// & Operator
// &연산자는 변수의 주소(번지)를 돌려주는 연산자
// - &p: 변수 p의 주소이다.
// scanf("%d", &p);
// -scanf의 인자는 control_string(%d)과 변수주소(&p)이다.
// 
// type casts
// 데이터 타임을 변환해주는 연산자
// (float)i <- 여기서 i는 int 변수라고 생각하자   --> i에 3이라는 값이 들어있으면 (float)i 는 3.0의 값을 가진다
// C프로그램은 여러 개의 연산자가 혼합되어 사용된다. 
// 그러나 모든 연산자는 우선순위에 따라 순서대로 처리된다. 
// 따라서 type cast가 발생하는 시점을 명확히 이해해야 값의 처리가 정확해진다.
#if 0
// (without type casts)
#include <stdio.h>
#define STUDENT_NUM 6
int main() {

	int sn = STUDENT_NUM;
	int total_score = 39;
	float avg_score;

	avg_score = total_score / sn;

	printf("Average score is %.2f\n", avg_score);  // 6.00
	return 0;
}
#endif

#if 0
// (with type casts)
#include <stdio.h>
#define STUDENT_NUM 6
int main() {

	int sn = STUDENT_NUM;
	int total_score = 39;
	float avg_score;

	avg_score = (float)total_score / (float)sn;

	printf("Average score is %.2f\n", avg_score);  // 6.50
	// 하나의 데이터가 있다 해도, 이것을 바라보는 크기에 따라 값의 해석은 완전히 달라짐
	// 포인터는 가리키는 역할이다.
	// 얼마의 크기를 가리키는 포인터인가는 무척 중요한 것이다.
	return 0;
}
#endif

// 배열과 포인터의 관계
// int a[100];
// -위의 선언은 a[0], a[1], …, a[99]의 정수 100개의 배열에 대한 선언이다.
// - 앞에서 공부한 대로, 위의 a는 주소(포인터)이며 배열의 첫 번째 원소 a[0]의 주소를 나타낸다.
// (우리는 a가 첫번째 “큰 덩어리”의 주소라고 기억하자)
// - 위에서 만들어지는 100개는 int 형이다.
// - a는 주소이며, 상수이다.즉, 연속 100개의 int 형이 만들어지는 시작 주소를 할당받은 주소이다.
// - a[0], a[1]…의 형태는 모두 int 형태의 변수이다.
// - a[100]도 값을 읽을 수 있다.C언어에서 못하게 제한하지 않는다.
// 그러나 a는 a[0]~a[99]까지의 100개만 유의미하게 관리하며, 
// a[100]의 위치는 접근할 수는 있게 해 주지만, 그 값에 대해서는 책임지지 않는다. 
// a[100]에 뭐가 있을지 몰라, 값이 보호되지 않아서 값이 언제든지 바뀔 수 있다. 
// 맞는 값인지 틀린 값인지 알 수 없음(확신X) --> 쓸 수가 없음
// 
//

#if 0
int main() {
	int c[10] = { 1000,2000,3000 }, a[10] = { 1,2,3,4,5 }, b[10] = { 100,200,300,400,500 };
	// b, a, c의 상대번지는 0, 48, 96
	// 40바이트만 있으면 되는데 48바이트가 차이남
	// 위에서 말한 문제를 예방하기 위해 조금 떨어뜨려 놓음
	// b[0] b[1] b[2] b[3] ... b[8] b[9] 쓰레기 쓰레기 a[0] a[1] a[2] ...
	// 100  200  300  400      0    0     ???    ???   1    2    3
	//                                  == b[10]
	// b[12] == 1 (a[0])
	// a[-3] == 0 (b[9])
	return 0;
}
#endif

// iptr로 할 수 있는 일
// *iptr는 a[0]이다.
// 정확하게 a[0]은 *(iptr + 0)을 의미한다
// - C언어에서 []은 연산자이다
// - []는 *( + )와 완전히 동일한 의미이다
// 여기서 +는 더하기가 아니라 "다음"의 의미이다
// - 컴퓨터는 "다음"이 없으므로 , 각 크기를 저해서 더할 숫자를 미리 정한다
// 
// -iptr+1의 값은?
// * a[0]의 다음 원소인 a[1]의 주소이다.이 다음을 명확하게 알기 위해 가리키는 곳의 크기가 중요한 것이다.
// * iptr은 int pointer이기 때문에 iptr + 1은 1001이 아니라 정수 크기에 맞춰 계산된다(이 경우는 1004)
// * 따라서 * (iptr + 1)은 a[1]이다.
// 
// a[3]
// *(a + 3)
// *(3 + a)
// 3[a]
// 
// a[-3]
// *(a - 3)
// *(3 - a)
// (-3)[a]
//

#if 0
int main() {
	int a[4] = { 1,2,3,4 };
	printf("%d\n", a[3]);
	printf("%d\n", *(a + 3));
	printf("%d\n", *(3 + a));
	printf("%d\n", 3[a]);
	printf("%d\n", a[-3]);
	printf("%d\n", *(a - 3));
	// printf("%d\n", *(3 - a));
	printf("%d\n", (-3)[a]);
	return 0;
}
#endif

#if 0
#include<stdio.h>
int main() {
	int N, X, arr[1000] = { 0 }, idx = 0;
	scanf("%d %d", &N, &X);
	while (N > 0) {
		arr[idx] = N % X;
		N /= X;
		idx++;
	}
	for (int i = idx - 1; i >= 0; i--) printf("%d", arr[i]);
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

