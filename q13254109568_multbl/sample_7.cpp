#include <iostream>
struct mul {
	int i;
	int j;
	friend std::ostream& operator<<(std::ostream& ostm, const mul& r)
	{
		return ostm << r.i << "×" << r.j << "＝" << r.i * r.j;
	}
};
int main()
{
	for (mul a{ 1, 1 };;) {
		std::cout << a.i << "の段\n" << a;
		do
			std::cout << "、" << a;
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
1249827098さん

2021/12/18 14:24

1回答

C++言語でのプログラミングコードについて質問です。
1の段
1×1＝1、1×2＝2…
2の段
2×1＝2、2×2＝4…
といった九九表を作る各場合、
ーーーーーーーーーーーーーーーーーーー
#include <stdio.h>

void main(void)
{
int i;
int x=1 , y=0;

for (i = 1; i <= 9; i++) {
x *= i

printf("%dの段…
ーーーーーーーーーーーーーーーーーーー
といった所までは書けましたがこれより下が分かりませんのでお教えいただけないでしょうか？
*/
