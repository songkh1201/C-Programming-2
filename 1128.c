#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// 구조체 공용체, 함수포인터
// 두 개 이상의 원소들로 구성된 통합 자료형
// 하나의 단위로 취급할 수 있도록 묶어

// 구조체 변수 선언
// struct 구조체명칭 {
//	멤버변수 1;
//  멤버변수 2;
// } 구조체 변수명
// 
// struct address {  // address형의 구조체
//  int num;
//  char name[20];
//  char * addr;
//  int tel;
// } a, b;  // 구조체 변수
// 
// struct address one, two;  // address형의 구조체

// 도트 연산자를 사용하여 구조체 멤버 변수를 참조
// 
// struct card {
//  int x;
//  int y;
// } one;
// struct card two;
// one.x = 50;
// one.y = 100;
// 
// two.x = one.x;
// two.y = one.y;

// 구조체 변수의 치환
// 
// struct s_type {
//  int a;
//  float f;
// } var1, var2;
// 
// var1.a = 10;
// var1.f = 100.23;
// 
// var2 = var1;
// --> 구조체끼리의 치환, 한꺼번에 전달 가능
// 데이터에 배열이 있다 하더라도,
// 할당문으로 한번에 복사가 가능하다.
// 유의해야함. 할당문 가능 비교문 불가능
// 그럼, 구조체 배열의 이름은 무엇일까?

// 너무 많은 함수를 부르는것은 왔다갔다 하는 것이 많아져 오히려 효율이 떨어질수도 있다

// 구조체 배열의 이름은 메모리다
// 배열은 주소, 구조체는 시작의 메모리의 값
//

#if 0
struct Test {
	char a, b, c, d;
	int i;
	char str[100];
} varA;
int main() {
	varA.a = 65, varA.b = 66, varA.c = 67, varA.d = 0;

	printf("%d\n", varA);
	printf("%s\n", varA);
	printf("%s\n", &varA);
	
	printf("%d\n", sizeof(varA));
	// 확인해보기
	return 0;
}
#endif

#if 0
struct address {
	int number;
	char* name;
	char* addr;
	int age;
};
int main() {
	struct address man;
	man.number = 13;
	man.name = "kim";  // 시점 ~
	man.addr = "seoul";
	man.age = 19;

	printf("%d\n", man.number);
	printf("%d\n", man.name);
	printf("%d\n", man.addr);
	printf("%d\n", man.age);

	// name은 초기화 X  "kim"을 할당
	// 배열이 아니라 공간을 못가짐
	// "kim"이라는 내용을 가지지 않음
	// 
	// ""은 프로그램 시작할 때 미리 텍스트 영역에 저장해둠
	// 그 썼던 영역을 name에 할당 ("kim"은 이미 존재)
	// name은 그걸 가리킬뿐
	// name, addr은 자기 공간을 가지는게 아니고 가리키는것
	// 
	// 새로운 공간을 얻어 저장하고 싶으면
	// malloc 사용
	// name에 malloc
	// 
	//
	return 0;
}
#endif
// 구조체 원소의 이름과 다른 변수의  이름이 같더라도 문제 X
// 원소의 이름은 구조체 이름과 연결되기 때문에, 같은 이름의 다른 변수들과 구분된다
//
#if 0
struct s_type {
	int i;
	int j;
} s;
int main() {
	int i;
	i = 100;
	s.i = 10;
	s.j = 101;
	printf("%d %d %d", i, s.i, s.j);
	return 0;
}
#endif

// 구조체 변수의 메모리 할당
// struct birthday {
//	int year; 
//  int month;
//	int day;
//	char calendar;
// };
// 항상 그런것을 아니겠지만 4*3 + 1 = 12 + 1 = 13 이
// 아닐 수 있다
//
// 16으로 나옴
// 4단위로 하는걸 좋아함
// 
// 이렇게 중간에 빈 공간을 넣은데
// 이것을 padding 이라고 하며,
// 메모리를 효율적으로 가져오기 위해 처리한다
// 
// #pragma ~ 
// 이걸로 padding 값 조절 가능
//
#if 01
#pragma pack(push,1)
struct tmp
{
	char a;
	char b;
	char c;
	char d;
	short as;
	double w;
	double x;
	double y;
	double z;
} tmp;
#pragma pack(pop)
struct tmp2
{
	char a;
	double w;
	char b;
	double x;
	char c;
	double y;
	char d;
	double z;
} tmp2;
int main() {
	printf("%d %d", sizeof(tmp), sizeof(tmp2));
	// 1*4 + 8*4 =36이 아니고 40이다
	// tmp와 같은데 배치만 다르다. 36, 40이 아닌 64
	// 메모리 배치의 효율을 위한 padding 공간을 사용함.
	return 0;
}
#endif

// 구조체 배열
// 구조체가 배열의 요소
// 구조체변수는 매개변수로서 함수에 전달될 수 있다
// 함수 또한 구조체를 반환할 수 있다
// 
// struct room[10]
// room[0] room[1]은 연속적
// 하지만 room[0].title[5]  room.year   room.price   구조체 room 안에 요소들은 padding으로 인해 연속적이지 않을수도 있음
//
#if 0
struct Test {
	char a, b, c, d;
	int i;
	char str[100];
} varA[2];
int main() {
	varA[0].a = 65, varA[0].b = 66, varA[0].c = 67, varA[0].d = 0;

	printf("%d\n", varA);  // 주소가 되어서 주소를 출력
	printf("%s\n", varA);  // 틀렸었는데, 이제 이게 정상출력됨
	printf("%s\n", &varA);  // 맞았었는데, 이제 이게 의미없게됨
							// 동작은 함. varA와 같은 값으로
	// 비교를 잘 해보라
	return 0;
}
#endif

// 구조체 포인터
// 구조체에 대한 포인터를 선언한 것 (단지 주소만 만든다. 4바이트)
// 구조체의 포인터 변수를 이용하여 구조체 배열과 동일하게 사용할 수 있다
// // struct 구조체명칭 {
//	멤버변수 1;
//  멤버변수 2;
// } *포인터변수명
// 
// struct 구조체명칭 *포인터변수명;
// 
// struct book *room;  // 주소이다. 그 주소에 가보면 구조체가 존재한다
//
#if 0
struct list {
	int kor;
	int math;
}a = { 90,95 }, * p;
int main() {
	p = &a;

	printf("%d\n", p->kor);   // (*p).kor과 동일
	printf("%d\n", p->math);  // (*p).math와 동일

	// *p.math;
	// *p->math;
	return 0;
}
#endif

// 자기참조 구조체
//
#if 0
struct list
{
	char name[20];
	char address[80];
	int age;
	struct list* next;
	// 4바이트 공간만 있으면됨
};
int main() {
	struct list a = { "abc","qwe",20, };
	struct list a = { "abcqwe","qweasd",20, };
	a.next = &a;
	a.name[0] = 'a';
	printf("%c", a.next->name[0]);
	return 0;
}
#endif

// 비트필드 구조체
#if 0
struct bit_field
{
	unsigned p : 1;
	unsigned none : 1;
	// 내기 원하는 비트 개수 정하는 것
	// 크면 알아서 짤림
};
int main() {

	return 0;
}
#endif

// 구조체와 함수
// 
// 구조체 변수 전달
// 구조체 변수 주소 전달
// 구조체 전달
// 구조체 주소 전달
//

// 공용체
// 두개 이상의 변수들이 같은 메모리를 공유하게 하는 것
// 변수들이 서로 다른 자료형을 가질 수 있다.
// 정의방법과 선언방법은 구조체와 유사
// 
// 단, 구조체는 모든 자료가 별개의 기억장소를 할당받지만
// 공용체의 경우에는 여러 자료형 중에서 가장 크기가 큰 자료형 만큼의 메모리가 확보된다
// 
// 변수에 접근방법은 구조체와 같음 . ->
//
#if 0
union list {
	char s;
	short ss;
	int sss;
};
int main() {
	union list p[4];
	return 0;
}
#endif

#if 0
struct list {
	char s;
	char ss;
	char sss;

};
union list2 {
	unsigned int a;
};
int main() {
	struct list a = { 1,2,3 };
	union list2 b = { 197121 };
	printf("%d\n%hhu", a, b);
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

