#include <stdio.h>
void �t���ɕ\��(const char ������[])
{
	switch (*������) {
	case '\n':
	case '\0':
		break;
	default:
		�t���ɕ\��(&������[1]);
		putchar(*������);
		break;
	}
}
int main()
{
	char ������[30+1];
	if (fgets(������, sizeof ������, stdin)) {
		�t���ɕ\��(������);
		putchar('\n');
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11254139871
yuy********����

2021/12/19 2:09

1��

��w��C����ŕ�����܂���
30�����܂ł̕����񂪓��͂��ꂽ��,���͂��ꂽ�������t���ɕ\������v���O����������,ABC����͂�����,CBA���o�͂���邱�Ƃ��m�F����
*/
