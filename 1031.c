#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// call by reference
// �Լ��� �������� ���踦 ����
// �Լ��� ���ڸ� ���� �����ϰ� �ϴ� ���� ���
// C������ call by value�� �⺻���� ���
// call by reference ȿ���� ���� ������ ���� ���

#if 0
void swap(int p, int q) {
	int tmp;
	tmp = p;
	p = q;
	q = tmp;
}

int main() {
	int i = 3, j = 5;
	swap(i, j);
	printf("%d %d", i, j);
}

/*
	main --------------------
	|		i	j			|
	-------------------------

	swap --------------------
	|	p	q		tmp		|
	-------------------------
*/
// swap �Լ��� �Ҵ� ���� ������ �Լ��� ����� �� �ü������ �ڵ����� ��ȯ�Ǿ� ��������� �νĵȴ�.
// ��, ���� �� ��� ������ ���� ������ ���̻� �ŷ�X
// 
// i�� ���� p�� ����ȴ�~ j�� ���� q�� ����ȴ�~
//
#endif

#if 0
void swap(int *p, int *q) {  // p == 100(i�ּ�)   *p == 3(i��)   &p == 500(p�ּ�)
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

int main() {
	int i = 3, j = 5;
	swap(&i, &j);
	printf("%d %d", i, j);
}
#endif

// �ּҸ� ������ ���� �װ��� ������ �� �ֵ��� �ϱ� ���ؼ�
// scanf�� �ּҸ� ���� ����

#if 0
int abc(int a) {
	int b;
	b = a + 1;
	return b;
}

int main() {
	int i = 2;

	i = abc(i);
	printf("%d ", i);

	i = abc(i);
	printf("%d ", i);
}
#endif

#if 0
// Ʋ�� ���α׷��� (���� 3 4 ���ߵ�)  b�� �������̱� ������
int* abc(int a) {
	int b;
	b = a + 1;
	return &b;  // b == 3   retrun *&b			b�� �ּҰ� ��� �ٲ�
}
int main() {
	int o = 2, * i;  // &o == 100   // &i == 110

	i = &o;  // i == 100   *i == 2
	i = abc(*i);  // o�� ���纻�� 2�� ����Ǿ� �Ѿ(���� �Ѿ)
	printf("%d ", *i);

	i = abc(*i);
	printf("%d ", *i);
}
// 1. &�� *�� ȥ�� �Ǿ���. ���� ����?
// 2. main()���� abc()�� �ѱ�°� ���� ? �ּ��� ?
// 3. abc()���� main()���� �ѱ�°� ���� ? �ּ��� ?
// 4. ù��° abc()ȣ�� ���Ŀ� i�� ����Ǵ� ���� ���� ?
// 5. ���� 4������ i���� ���� ���� ?
// 6. 4�� i ���� ����Ű�� ���� ����� ?
// 7. �� ���α׷��� Ʋ�ȳ� �¾ҳ� ?
#endif

#if 0
void swap(int* a, int* b, int* k) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	for (int i = 0; i < 2; i++) {
		int tmp2 = *(k + i);
		*(k + i) = *(k + 4 - i);
		*(k + 4 - i) = tmp2;
	}
}
int main() {
	int i = 3, j = 5, k[5] = { 1,2,3,4,5 };
	swap(&i, &j, k);
	printf("%d %d\n", i, j);
	for (int ii = 0; ii < 5; ii++) printf("%d ", k[ii]);
	return 0;
}
#endif

#if 0
int main() {
	unsigned int n;
	int p, q;
	scanf("%u %d %d", &n, &p, &q);
	int m;
	m = n >> p;
	int l = 1;
	for (int i = p; i <= q; i++) {
		l = 1;
		if (p == 0) {
			l = 1;
		}
		else {
			for (int j = 0; j <= i - 1; j++) {
				l = l * 2;
			}
		}
		if ((m % 2) == 1) {
			n = n - l;
		}
		else {
			n = n + l;
		}
		m = m / 2;
	}
	printf("%d", n);
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

