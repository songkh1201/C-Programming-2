#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������ ���� ���� ���� ���� ����� ����

// ������ ����
// ������ ������ �޸��� ����(�ּ�)�� �����ϴ� �� ���̴� "����"�̴�.
// ���� �����鿡�� �ô�, 1004, 1008 ���� �ּҸ� �����ϰ�, �̸� ó���� �� �ִ�(�а�, ���� �ٲٴ� ��) ����, ������ �����̴�. 
// ������ ������ �����ϰ� �ִ� ���� �ٲ۴ٴ� ���� ����Ű�� �޸� ��ġ�� �����Ѵٴ� �ǹ�
// ��ǻ�Ϳ��� ��� �����ʹ� ����Ʈ ������ �ּҸ� ������ �ִ�.
// ���� ����Ǵ� �ּҴ� ����Ʈ�� �ּ��̴�
// �׷���, �� �ּҷκ��� 1����Ʈ, 2����Ʈ, 4����Ʈ ���� �ϳ��� ������ �� �� �ִ�. 
// �װ��� ������ �ִ� ���� ������ ������ ��(type, �� char, int) ���̴�.
// 
// �� �ʿ��Ѱ�
// �ʿ信 ���� ����Ű��, �����Ű�� �ϴµ��� ó���� �ʿ伺
// Ư�� �޸𸮸� ���� ����Ű��, ó���� �� �ִ� C���� �׷� �뵵�� �䱸�� ���� ����
// 
// ���� ���
// unsigned short int i[3] = {0x1234, 0x5678, 0xABCD};
// �̷� �����Ͱ� ���� �� �޸𸮰���
// 0x34  0x12  0x78  0x56  0xCD  0xAB
// �� �� unsigned char ������ p�� 0x12�� ����Ʈ�� ����Ų�ٰ� �����غ���.
// p�� ����Ű�� ��ġ�� ���� ����Ʈ ���� ���� �� �ִ�.
// ���� ������� unsigned short int ������ pi�� ���� ���� 0x12 ����Ʈ�� ����Ű�� �� ���� �ִ�.
// �� ���� ���� ���ο� ���� pi�� �а� �ȴ�. (0x12�� 0x78�� ���� = 0x7812) ¦�� ����Ʈ�̱� ������ ���� ���� �Ųٷ�
// �޸𸮿� ���� ������ �����ͷ� ���ϴ� ���·� ���� ���� �� �ִ�.
// 0xCD567812�� unsigned int ���� ���� �� �ִ�.(���� & �б�) �����ϰ� �Ųٷ�
// 
// ����
// ���� �տ� * ����, *�� 1�� �̻� ���� �� �ִ�
// int *p;   ������ ������ �ּҿ� ���� ������ ���� p�� ����, ũ��� 4����Ʈ ������ 1000���� ���� ���� int
// char *p;  ������ ������ �ּҿ� ���� ������ ���� p�� ����, ũ��� 4����Ʈ ������ 1000���� ���� ���� char
// ������ Ÿ��(int, char, float, ...)�� ���� ������ ������ ������ ����ؾ� �Ѵ�.
// int *p; �� ����� 3������ ����
// p, &p, *p -- �ּ�, ���� p�� �ּ�, �����Ͱ� ����Ű�� �ּ� ���� ��
// 
// ������ ������ �� ������ Ÿ�Ժ��� �ִ�.
// - ����������, ����������, ��
// - �������� Ÿ���� ũ�Ⱑ �ٸ��� ������
// * ������ Ÿ���� ũ�⿡ ���� �޸𸮿��� �����ϴ� ������ �ٸ���.
// * �� �Ĺݺο� ��������, struct�� ���� ����ڰ� ������ ������ ũ�⸦ ������ �޸𸮵� �����ͷ� ����Ű�� ������ �� �ִ�.
// - ������ �����ؼ� �ڵ� �� ������ ���� �ش� �����Ͱ� ��Ȯ�ϰ� ������(��𿡼� ��������, Ȥ�� �����Ʈ��) ����Ű������ �˾ƾ��Ѵ�.
// �׷��� + -�� ������ ��Ȯ�ϰ� �� �� �ִ�.
// - �޸𸮸� ����Ŵ���ν� ����� �پ��� ȿ���� �����ؾ� �Ѵ�.
// 
// ������ ������ �ʱ�ȭ
// int *p, i;		- ���������ͺ��� p�� �������� i�� ����
// p = 0;			- p�� 0������ �ִ´�
// p = NULL;		-���⼭ NULL�� 0������ ����.
// p = &i;			-p�� i�� �ּ�(����)���� �ִ´�.
// p = (int*)1776;  -p�� ������� 1776�� ���������ͷ� ��ȯ�� ���� �ִ´�.  // ���־�Ʃ������� �Ұ���, �Ϲ����α׷����� �ǹ�X, �Ӻ���� ���α׷����� ���
// 
// & Operator
// &�����ڴ� ������ �ּ�(����)�� �����ִ� ������
// - &p: ���� p�� �ּ��̴�.
// scanf("%d", &p);
// -scanf�� ���ڴ� control_string(%d)�� �����ּ�(&p)�̴�.
// 
// type casts
// ������ Ÿ���� ��ȯ���ִ� ������
// (float)i <- ���⼭ i�� int ������� ��������   --> i�� 3�̶�� ���� ��������� (float)i �� 3.0�� ���� ������
// C���α׷��� ���� ���� �����ڰ� ȥ�յǾ� ���ȴ�. 
// �׷��� ��� �����ڴ� �켱������ ���� ������� ó���ȴ�. 
// ���� type cast�� �߻��ϴ� ������ ��Ȯ�� �����ؾ� ���� ó���� ��Ȯ������.
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
	// �ϳ��� �����Ͱ� �ִ� �ص�, �̰��� �ٶ󺸴� ũ�⿡ ���� ���� �ؼ��� ������ �޶���
	// �����ʹ� ����Ű�� �����̴�.
	// ���� ũ�⸦ ����Ű�� �������ΰ��� ��ô �߿��� ���̴�.
	return 0;
}
#endif

// �迭�� �������� ����
// int a[100];
// -���� ������ a[0], a[1], ��, a[99]�� ���� 100���� �迭�� ���� �����̴�.
// - �տ��� ������ ���, ���� a�� �ּ�(������)�̸� �迭�� ù ��° ���� a[0]�� �ּҸ� ��Ÿ����.
// (�츮�� a�� ù��° ��ū ������� �ּҶ�� �������)
// - ������ ��������� 100���� int ���̴�.
// - a�� �ּ��̸�, ����̴�.��, ���� 100���� int ���� ��������� ���� �ּҸ� �Ҵ���� �ּ��̴�.
// - a[0], a[1]���� ���´� ��� int ������ �����̴�.
// - a[100]�� ���� ���� �� �ִ�.C���� ���ϰ� �������� �ʴ´�.
// �׷��� a�� a[0]~a[99]������ 100���� ���ǹ��ϰ� �����ϸ�, 
// a[100]�� ��ġ�� ������ ���� �ְ� �� ������, �� ���� ���ؼ��� å������ �ʴ´�. 
// a[100]�� ���� ������ ����, ���� ��ȣ���� �ʾƼ� ���� �������� �ٲ� �� �ִ�. 
// �´� ������ Ʋ�� ������ �� �� ����(Ȯ��X) --> �� ���� ����
// 
//

#if 0
int main() {
	int c[10] = { 1000,2000,3000 }, a[10] = { 1,2,3,4,5 }, b[10] = { 100,200,300,400,500 };
	// b, a, c�� �������� 0, 48, 96
	// 40����Ʈ�� ������ �Ǵµ� 48����Ʈ�� ���̳�
	// ������ ���� ������ �����ϱ� ���� ���� ����߷� ����
	// b[0] b[1] b[2] b[3] ... b[8] b[9] ������ ������ a[0] a[1] a[2] ...
	// 100  200  300  400      0    0     ???    ???   1    2    3
	//                                  == b[10]
	// b[12] == 1 (a[0])
	// a[-3] == 0 (b[9])
	return 0;
}
#endif

// iptr�� �� �� �ִ� ��
// *iptr�� a[0]�̴�.
// ��Ȯ�ϰ� a[0]�� *(iptr + 0)�� �ǹ��Ѵ�
// - C���� []�� �������̴�
// - []�� *( + )�� ������ ������ �ǹ��̴�
// ���⼭ +�� ���ϱⰡ �ƴ϶� "����"�� �ǹ��̴�
// - ��ǻ�ʹ� "����"�� �����Ƿ� , �� ũ�⸦ ���ؼ� ���� ���ڸ� �̸� ���Ѵ�
// 
// -iptr+1�� ����?
// * a[0]�� ���� ������ a[1]�� �ּ��̴�.�� ������ ��Ȯ�ϰ� �˱� ���� ����Ű�� ���� ũ�Ⱑ �߿��� ���̴�.
// * iptr�� int pointer�̱� ������ iptr + 1�� 1001�� �ƴ϶� ���� ũ�⿡ ���� ���ȴ�(�� ���� 1004)
// * ���� * (iptr + 1)�� a[1]�̴�.
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
