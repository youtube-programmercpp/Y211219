#include <stdio.h>
int main()
{
	int i = 1;
	do {
		int j = 2;
		printf("%d�̒i\n%d�~1��%d", i, i, i);
		do
			printf("�A%d�~%d��%d", i, j, i * j);
		while (++j <= 9);
		putchar('\n');
	}
	while (++i <= 9);
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q13254109568
1249827098����

2021/12/18 14:24

1��

C++����ł̃v���O���~���O�R�[�h�ɂ��Ď���ł��B
1�̒i
1�~1��1�A1�~2��2�c
2�̒i
2�~1��2�A2�~2��4�c
�Ƃ��������\�����e�ꍇ�A
�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
#include <stdio.h>

void main(void)
{
int i;
int x=1 , y=0;

for (i = 1; i <= 9; i++) {
x *= i

printf("%d�̒i�c
�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
�Ƃ��������܂ł͏����܂����������艺��������܂���̂ł��������������Ȃ��ł��傤���H
*/
