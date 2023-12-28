#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// char c1;
// char c2 = 'a';
// char c4 = "abcd";  // 확인
// chsr c3 = "a";	  // c2와 c3의 차이점은?

// char c1 = 1, c2 = 'a';
// char c3 = "a", *c4 = "abcd";
// char *c5 = "ABCD", c6 = 1;
// 
// c1 = "a";
// c4[4] = a;    // 틀린 것, [3]까지만 있기 때문이 아님, c4는 주소, c4[4] 자체는 맞음, 1을 쓰려는 것이 안됨
// c5[1] = 'X';  // 틀린 것, 쌍따음표의 위치는 안됨
// 각 과정을 정확하게 이해하면, 되는 것과 안되는 것을 구분할 수 있다.
// 읽는 것과 쓰는 것도 잘 이해하자
// 쓸 수 있는 것과 쓸 수 없는 것도 잘 이해하자

#if 0
void main() {
	char a[] = "rose";  // "" 안에 내용은 read only 영역에 들어가 있음, 그래서 덮어쓰기하면 안됨
	char b[] = "rose";
	char* p = "grace";

	a[0] = 'n';
	b[0] = 'n';
	p[0] = 't';

	printf("a = %s \n", a);
	printf("b = %s \n", b);
	printf("p = %s \n", p);
	
	// 텍스트 세그먼트    // "" 안에 내용이 여기 들어감 read only (write 불가)
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
	char* cp1;
	char* cp2 = "abcde";  // 어딘가에 메모리 잡고 거기 연결
	char* cp3 = { 'a','b','c','d','e' };
	char* cp4 = "";  // NULL
	char* cp5 = '';  // 따옴표 사이에 없는 경우임, '' 사이에는 무언가가 무조건 있어야함
					// 따옴표 문자가 하는 역할
					// char c = ''; 라고 했더라도
	char* cp6 = 'a';  // 주의  cp5와 차이점은?				// 'a' 도 숫자 cp7
	char* cp7 = 100;  // 주의  컴퓨터는 무엇을 처리하나?
	return 0;
}
#endif

// 포인터는 주소만 가져옴, 값은 안가져옴

#if 0
int main() {
	char a = 'a', b = 'b', c = 'c';
	char* aa = "aaa";
	char ab[] = "bbb";

	test(a, aa, ab);
	return 0;
}
test(char a, char* aa, char* ab) {
// test (char a, char* aa, char ab[]) {  // 위와 동일, ab[]는 함수에서 인자로 받을 때만 가능
	printf("%c, %s, %s", a, aa, ab);
}
#endif


// strlen() 힘수를 만들어보자     5가지 방법??
// 문자열의 길이를 반환하는 함수 (리턴은 int 로 설계)
// 
// 함수 이름 결정
// 함수 반환값 형태 결정
// 함수 인자 수와 형태 결정
// 위의 과정을 통해 최종 함수의 Prototype 결정

#if 0
int strlen1(char* str) {
	int length = 0;
	while (1) {
		if (*str++ != NULL) length++;
		else break;  // 여기서 바로 리턴하는 것보다 좋음, 코드를 보기에 더 좋음
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

// if 없애기?

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
	while (*str2 != NULL) str2++;  // 여기서는 위치만 바꾸고

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

// 이외에도 여러가지 해보기
#if 0
int main() {

	return 0;
}
#endif



// strcpy() 함수
#if 0
char* strcpy1(char* s1, char* s2) {
	char* tmp = s1;
	while (*s2 != NULL) *s1++ = *s2++;  // 뒤에서 앞으로 복사~
	// 마지막에 NULL이 있어야 하지만 이렇게 하면 맨 뒤에 NULL이 들어가지 않음
	// s1은 반드시 배열이어야 하고, s2는 배열과 일반 포인터 상수 가능
	*s1 = NULL;
	return tmp;  // 위치를 반환
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
	
	strcpy(out1, in1);  // 가능
	strcpy(out2, in1);  // 복사는 가능하지만 크기가 잘못됨
	strcpy(out3, in1);  // 가능, a b c d e f g NULL 9    %s 로는 9 출력 불가
	strcpy(out4, in1);  // 쓸 수는 있다, 하지만 쓸 곳이 엉뚱 --> 쓰면 안된다
	strcpy(out5, in1);  // 쓰면 안되는 곳      공간을 확보한 다음에 써야함

	return 0;
}
#endif

// strcat(char*, char*) strstr(char*, char*)    // 20분, 60분
// 다른 함수도 생각해보고 만들기  strcmp

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
// 규
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
		if (*ptr1 == NULL) { // 찾지못하고 문자열이 끝나면
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

