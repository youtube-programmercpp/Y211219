#include <stdio.h>
int main()
{
	int i = 1;
	do {
		int j = 2;
		printf("%dの段\n%d×1＝%d", i, i, i);
		do
			printf("、%d×%d＝%d", i, j, i * j);
		while (++j <= 9);
		putchar('\n');
	}
	while (++i <= 9);
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
