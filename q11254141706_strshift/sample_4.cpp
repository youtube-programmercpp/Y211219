void shift(char s[], int length)
{
	if (length > 3) {
		char* const end = &s[length];
		const char t0 = *s++;
		const char t1 = *s++;
		const char t2 = *s++;
		do
			s[-3] = *s;
		while (++s < end);
		end[-3] = t0;
		end[-2] = t1;
		end[-1] = t2;
	}
}
#include <stdio.h>
int main()
{
	char s[] = "Programming";
	shift(s, sizeof s - 1);
	puts(s);
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11254141706
vnd********����

2021/12/19 4:22

2��

�v���O���~���O���S�҂ł��Bc����ł��B
������s[]�ƕ�����̒���length����A������̍ŏ��̂R�����𕶎���̌��ɂ���void�^��shift�֐�����肽���ł��B���L�̊֐��̓��e�������Ă���������Ɗ������ł��B

�Ⴆ�΁A
length=6, s[]=Programming
Programming �� grammingPro

void shift(char s[],int length)
{

}

C����֘A | �v���O���~���O�E60�{��
*/
