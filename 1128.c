#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// ����ü ����ü, �Լ�������
// �� �� �̻��� ���ҵ�� ������ ���� �ڷ���
// �ϳ��� ������ ����� �� �ֵ��� ����

// ����ü ���� ����
// struct ����ü��Ī {
//	������� 1;
//  ������� 2;
// } ����ü ������
// 
// struct address {  // address���� ����ü
//  int num;
//  char name[20];
//  char * addr;
//  int tel;
// } a, b;  // ����ü ����
// 
// struct address one, two;  // address���� ����ü

// ��Ʈ �����ڸ� ����Ͽ� ����ü ��� ������ ����
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

// ����ü ������ ġȯ
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
// --> ����ü������ ġȯ, �Ѳ����� ���� ����
// �����Ϳ� �迭�� �ִ� �ϴ���,
// �Ҵ繮���� �ѹ��� ���簡 �����ϴ�.
// �����ؾ���. �Ҵ繮 ���� �񱳹� �Ұ���
// �׷�, ����ü �迭�� �̸��� �����ϱ�?

// �ʹ� ���� �Լ��� �θ��°��� �Դٰ��� �ϴ� ���� ������ ������ ȿ���� ���������� �ִ�

// ����ü �迭�� �̸��� �޸𸮴�
// �迭�� �ּ�, ����ü�� ������ �޸��� ��
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
	// Ȯ���غ���
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
	man.name = "kim";  // ���� ~
	man.addr = "seoul";
	man.age = 19;

	printf("%d\n", man.number);
	printf("%d\n", man.name);
	printf("%d\n", man.addr);
	printf("%d\n", man.age);

	// name�� �ʱ�ȭ X  "kim"�� �Ҵ�
	// �迭�� �ƴ϶� ������ ������
	// "kim"�̶�� ������ ������ ����
	// 
	// ""�� ���α׷� ������ �� �̸� �ؽ�Ʈ ������ �����ص�
	// �� ��� ������ name�� �Ҵ� ("kim"�� �̹� ����)
	// name�� �װ� ����ų��
	// name, addr�� �ڱ� ������ �����°� �ƴϰ� ����Ű�°�
	// 
	// ���ο� ������ ��� �����ϰ� ������
	// malloc ���
	// name�� malloc
	// 
	//
	return 0;
}
#endif
// ����ü ������ �̸��� �ٸ� ������  �̸��� ������ ���� X
// ������ �̸��� ����ü �̸��� ����Ǳ� ������, ���� �̸��� �ٸ� ������� ���еȴ�
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

// ����ü ������ �޸� �Ҵ�
// struct birthday {
//	int year; 
//  int month;
//	int day;
//	char calendar;
// };
// �׻� �׷����� �ƴϰ����� 4*3 + 1 = 12 + 1 = 13 ��
// �ƴ� �� �ִ�
//
// 16���� ����
// 4������ �ϴ°� ������
// 
// �̷��� �߰��� �� ������ ������
// �̰��� padding �̶�� �ϸ�,
// �޸𸮸� ȿ�������� �������� ���� ó���Ѵ�
// 
// #pragma ~ 
// �̰ɷ� padding �� ���� ����
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
	// 1*4 + 8*4 =36�� �ƴϰ� 40�̴�
	// tmp�� ������ ��ġ�� �ٸ���. 36, 40�� �ƴ� 64
	// �޸� ��ġ�� ȿ���� ���� padding ������ �����.
	return 0;
}
#endif

// ����ü �迭
// ����ü�� �迭�� ���
// ����ü������ �Ű������μ� �Լ��� ���޵� �� �ִ�
// �Լ� ���� ����ü�� ��ȯ�� �� �ִ�
// 
// struct room[10]
// room[0] room[1]�� ������
// ������ room[0].title[5]  room.year   room.price   ����ü room �ȿ� ��ҵ��� padding���� ���� ���������� �������� ����
//
#if 0
struct Test {
	char a, b, c, d;
	int i;
	char str[100];
} varA[2];
int main() {
	varA[0].a = 65, varA[0].b = 66, varA[0].c = 67, varA[0].d = 0;

	printf("%d\n", varA);  // �ּҰ� �Ǿ �ּҸ� ���
	printf("%s\n", varA);  // Ʋ�Ⱦ��µ�, ���� �̰� ������µ�
	printf("%s\n", &varA);  // �¾Ҿ��µ�, ���� �̰� �ǹ̾��Ե�
							// ������ ��. varA�� ���� ������
	// �񱳸� �� �غ���
	return 0;
}
#endif

// ����ü ������
// ����ü�� ���� �����͸� ������ �� (���� �ּҸ� �����. 4����Ʈ)
// ����ü�� ������ ������ �̿��Ͽ� ����ü �迭�� �����ϰ� ����� �� �ִ�
// // struct ����ü��Ī {
//	������� 1;
//  ������� 2;
// } *�����ͺ�����
// 
// struct ����ü��Ī *�����ͺ�����;
// 
// struct book *room;  // �ּ��̴�. �� �ּҿ� ������ ����ü�� �����Ѵ�
//
#if 0
struct list {
	int kor;
	int math;
}a = { 90,95 }, * p;
int main() {
	p = &a;

	printf("%d\n", p->kor);   // (*p).kor�� ����
	printf("%d\n", p->math);  // (*p).math�� ����

	// *p.math;
	// *p->math;
	return 0;
}
#endif

// �ڱ����� ����ü
//
#if 0
struct list
{
	char name[20];
	char address[80];
	int age;
	struct list* next;
	// 4����Ʈ ������ �������
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

// ��Ʈ�ʵ� ����ü
#if 0
struct bit_field
{
	unsigned p : 1;
	unsigned none : 1;
	// ���� ���ϴ� ��Ʈ ���� ���ϴ� ��
	// ũ�� �˾Ƽ� ©��
};
int main() {

	return 0;
}
#endif

// ����ü�� �Լ�
// 
// ����ü ���� ����
// ����ü ���� �ּ� ����
// ����ü ����
// ����ü �ּ� ����
//

// ����ü
// �ΰ� �̻��� �������� ���� �޸𸮸� �����ϰ� �ϴ� ��
// �������� ���� �ٸ� �ڷ����� ���� �� �ִ�.
// ���ǹ���� �������� ����ü�� ����
// 
// ��, ����ü�� ��� �ڷᰡ ������ �����Ҹ� �Ҵ������
// ����ü�� ��쿡�� ���� �ڷ��� �߿��� ���� ũ�Ⱑ ū �ڷ��� ��ŭ�� �޸𸮰� Ȯ���ȴ�
// 
// ������ ���ٹ���� ����ü�� ���� . ->
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

