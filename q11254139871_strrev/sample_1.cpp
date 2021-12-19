#include <stdio.h>
void 逆順に表示(const char 文字列[])
{
	switch (*文字列) {
	case '\n':
	case '\0':
		break;
	default:
		逆順に表示(&文字列[1]);
		putchar(*文字列);
		break;
	}
}
int main()
{
	char 文字列[30+1];
	if (fgets(文字列, sizeof 文字列, stdin)) {
		逆順に表示(文字列);
		putchar('\n');
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11254139871
yuy********さん

2021/12/19 2:09

1回答

大学のC言語で分かりません
30文字までの文字列が入力されたら,入力された文字を逆順に表示するプログラムを書き,ABCを入力したら,CBAが出力されることを確認せよ
*/
