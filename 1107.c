#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// char c1;
// char c2 = 'a';
// char c4 = "abcd";  // Ȯ��
// chsr c3 = "a";	  // c2�� c3�� ��������?

// char c1 = 1, c2 = 'a';
// char c3 = "a", *c4 = "abcd";
// char *c5 = "ABCD", c6 = 1;
// 
// c1 = "a";
// c4[4] = a;    // Ʋ�� ��, [3]������ �ֱ� ������ �ƴ�, c4�� �ּ�, c4[4] ��ü�� ����, 1�� ������ ���� �ȵ�
// c5[1] = 'X';  // Ʋ�� ��, �ֵ���ǥ�� ��ġ�� �ȵ�
// �� ������ ��Ȯ�ϰ� �����ϸ�, �Ǵ� �Ͱ� �ȵǴ� ���� ������ �� �ִ�.
// �д� �Ͱ� ���� �͵� �� ��������
// �� �� �ִ� �Ͱ� �� �� ���� �͵� �� ��������

#if 0
void main() {
	char a[] = "rose";  // "" �ȿ� ������ read only ������ �� ����, �׷��� ������ϸ� �ȵ�
	char b[] = "rose";
	char* p = "grace";

	a[0] = 'n';
	b[0] = 'n';
	p[0] = 't';

	printf("a = %s \n", a);
	printf("b = %s \n", b);
	printf("p = %s \n", p);
	
	// �ؽ�Ʈ ���׸�Ʈ    // "" �ȿ� ������ ���� �� read only (write �Ұ�)
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
	char* cp1;
	char* cp2 = "abcde";  // ��򰡿� �޸� ��� �ű� ����
	char* cp3 = { 'a','b','c','d','e' };
	char* cp4 = "";  // NULL
	char* cp5 = '';  // ����ǥ ���̿� ���� �����, '' ���̿��� ���𰡰� ������ �־����
					// ����ǥ ���ڰ� �ϴ� ����
					// char c = ''; ��� �ߴ���
	char* cp6 = 'a';  // ����  cp5�� ��������?				// 'a' �� ���� cp7
	char* cp7 = 100;  // ����  ��ǻ�ʹ� ������ ó���ϳ�?
	return 0;
}
#endif

// �����ʹ� �ּҸ� ������, ���� �Ȱ�����

#if 0
int main() {
	char a = 'a', b = 'b', c = 'c';
	char* aa = "aaa";
	char ab[] = "bbb";

	test(a, aa, ab);
	return 0;
}
test(char a, char* aa, char* ab) {
// test (char a, char* aa, char ab[]) {  // ���� ����, ab[]�� �Լ����� ���ڷ� ���� ���� ����
	printf("%c, %s, %s", a, aa, ab);
}
#endif


// strlen() ������ ������     5���� ���??
// ���ڿ��� ���̸� ��ȯ�ϴ� �Լ� (������ int �� ����)
// 
// �Լ� �̸� ����
// �Լ� ��ȯ�� ���� ����
// �Լ� ���� ���� ���� ����
// ���� ������ ���� ���� �Լ��� Prototype ����

#if 0
int strlen1(char* str) {
	int length = 0;
	while (1) {
		if (*str++ != NULL) length++;
		else break;  // ���⼭ �ٷ� �����ϴ� �ͺ��� ����, �ڵ带 ���⿡ �� ����
		// str++;
	}
	return length;
}
int main() {
	char* str = "abcde";
	int len = 0;
	len = strlen1(str);

	printf("%d\n", len);
	return 0;
}
#endif

// if ���ֱ�?

#if 0
int strlen1(char* str) {
	int length = 0;
	while (*str++ != NULL) length++;

	return length;
}
int main() {
	char* str = "abcde";
	int len = 0;
	len = strlen1(str);

	printf("%d\n", len);
	return 0;
}
#endif

#if 0
int strlen1(char* str) {
	char* str2 = str;
	while (*str2 != NULL) str2++;  // ���⼭�� ��ġ�� �ٲٰ�

	return (str2 - str);
}
int main() {
	char* str = "abcde";
	int len = 0;
	len = strlen1(str);

	printf("%d\n", len);
	return 0;
}
#endif

// �̿ܿ��� �������� �غ���
#if 0
int main() {

	return 0;
}
#endif



// strcpy() �Լ�
#if 0
char* strcpy1(char* s1, char* s2) {
	char* tmp = s1;
	while (*s2 != NULL) *s1++ = *s2++;  // �ڿ��� ������ ����~
	// �������� NULL�� �־�� ������ �̷��� �ϸ� �� �ڿ� NULL�� ���� ����
	// s1�� �ݵ�� �迭�̾�� �ϰ�, s2�� �迭�� �Ϲ� ������ ��� ����
	*s1 = NULL;
	return tmp;  // ��ġ�� ��ȯ
}
int main() {
	char s1[50] = "abcd", s2[10] = "ggg";
	strcpy1(s1, s2);
	printf("%s", s1);
	return 0;
}
#endif

#if 0
int main() {
	char in1[10] = "abcdefg";
	char out1[10];
	char out2[] = "123456";
	char out3[10] = "123456789";
	char* out4, * out5 = "12345";
	
	strcpy(out1, in1);  // ����
	strcpy(out2, in1);  // ����� ���������� ũ�Ⱑ �߸���
	strcpy(out3, in1);  // ����, a b c d e f g NULL 9    %s �δ� 9 ��� �Ұ�
	strcpy(out4, in1);  // �� ���� �ִ�, ������ �� ���� ���� --> ���� �ȵȴ�
	strcpy(out5, in1);  // ���� �ȵǴ� ��      ������ Ȯ���� ������ �����

	return 0;
}
#endif

// strcat(char*, char*) strstr(char*, char*)    // 20��, 60��
// �ٸ� �Լ��� �����غ��� �����  strcmp

// strcat
#if 0
void strcat1(char* s1, char* s2) {
	char* t = s1;
	while (*s1 != NULL) s1++;
	while (*s2 != NULL) *s1++ = *s2++;
	*s1 = NULL;
}
int main() {
	char s1[50] = "abcd", s2[5] = "ggg";
	strcat1(s1, s2);
	printf("%s", s1);
	return 0;
}
#endif

// strcmp
#if 0
int strcmp1(char* s1, char* s2) {
	while (*s1 == *s2) {
		if (*(s1 + 1) == NULL && *(s2 + 1) == NULL) {
			break;
		}
		s1++;
		s2++;
	}
	int t = *s1 - *s2;
	return t > 0 ? 1 : t < 0 ? -1 : 0;
}
int main() {
	char s1[50] = "ac", s2[50] = "aa";
	printf("%d", strcmp1(s1, s2));
	return 0;
}
#endif

// strstr
#if 0
char* strstr1(char* s1, char* s2) {
	while (*s1 != NULL) {
		if (*s1 == *s2) {
			char* t = s2;
			int idx = 0;
			while (*t != NULL) {
				if (*(s1 + idx) != *t++) {
					break;
				}
				if (*t == NULL) return s1;
				idx++;
			}
		}
		s1++;
	}
	return NULL;
}
int main() {
	char s1[50], s2[10], s3[10];
	char* result;
	gets(s1);
	scanf("%s %s", s2, s3);
	while (strstr1(s1, s2) != NULL) {
		for (int i = 0; i < strlen(s1); i++) {
			if (&*(s1 + i) == strstr1(s1, s2)) {
				for (int j = 0; j < strlen(s2); j++) {
					*(s1 + i + j) = *(s3 + j);
				}
				i += strlen(s2);
			}
		}
	}
	printf("%s\n", s1);
	return 0;
}
#endif

// strchr
#if 0
char* strchr1(char* s1, char s2) {
	while (*s1 != s2) {
		s1++;
		if (*s1 == NULL) break;
	}
	return s1;
}
int main() {
	char s1[50], s2;
	gets(s1);
	scanf(" %c", &s2);
	printf("%s", strchr1(s1, s2));
	return 0;
}
#endif

#if 0
// ��
char* strstr(char* str1, char* str2) {
	char* ptr1 = str1;
	char* ptr2 = str2;
	int len = 0;
	while (*ptr2 != NULL) {
		len++;
		ptr2++;
	}
	ptr2 = str2;
	while (*ptr2 != NULL) {
		if (*ptr1 == NULL) { // ã�����ϰ� ���ڿ��� ������
			return NULL;
		}
		if (*ptr1 == *ptr2) {
			ptr2++;
		}
		else ptr2 = str2;
		ptr1++;
	}
	return ptr1 - len;

}
int main() {

	char str1[100] = "bagdogbag";
	char str2[100] = "dog";
	char* ptr = strstr(str1, str2);
	printf("%s", ptr);
	return 0;
}
#endif

// strstr
#if 0
#include<string.h>
char* strstr2(char* s1, char* s2) {
	char* t1 = s1;
	char* t2 = s2;
	int len = 0;
	while (*s2++ != NULL) len++;
	s2 = t2;
	while (*s2 != NULL) {
		if (*s1 == NULL) {
			return NULL;
		}
		if (*s1 == *s2) {
			s2++;
		}
		else {
			s2 = t2;
		}
		s1++;
	}
	return s1 - len;
}
int main() {
	char s1[50] = "my dog is good. hotdog", s2[50] = "dog", s3[10] = "horse";
	//gets(s1);
	//scanf("%s %s", s2, s3);
	while (strstr2(s1, s2) != NULL) {
		char* t = strstr2(s1, s2);
		int idx = strlen(s1) + strlen(s3) - strlen(s2);

		for (int i = idx;; i--) {
			if (t == &s1[i]) {
				idx = i;
				break;
			}
			s1[i] = s1[i - (strlen(s3) - strlen(s2))];
		}

		for (int i = 0; i < strlen(s3); i++) {
			s1[idx + i] = s3[i];
		}
	}
	printf("%s", s1);
	return 0;
}
#endif

#if 0
int main() {

	return 0;
}
#endif

