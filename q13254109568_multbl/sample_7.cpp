#include <iostream>
struct mul {
	int i;
	int j;
	friend std::ostream& operator<<(std::ostream& ostm, const mul& r)
	{
		return ostm << r.i << "�~" << r.j << "��" << r.i * r.j;
	}
};
int main()
{
	for (mul a{ 1, 1 };;) {
		std::cout << a.i << "�̒i\n" << a;
		do
			std::cout << "�A" << a;
		while (++a.j <= 9);
		std::cout << '\n';
		if (++a.i <= 9)
			a.j = 1;
		else
			break;
	}
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
