struct �ŏ��̂R���� {
	char t[3];
};
void shift(char s[], int length)
{
	if (length > sizeof (struct �ŏ��̂R����)) {
		char* const end = &s[length];
		const struct �ŏ��̂R���� t = *(*(const struct �ŏ��̂R����**)&s)++;
		do
			s[0 - sizeof (struct �ŏ��̂R����)] = *s;
		while (++s < end);
		((struct �ŏ��̂R����*)s)[-1] = t;
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
