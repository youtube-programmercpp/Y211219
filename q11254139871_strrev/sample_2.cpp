#include <io.h>
int main()
{
	char 文字列[30];
	switch (int n = _read(0, 文字列, sizeof 文字列)) {
	case -1:
	case 0:
		break;
	case 1:
		if (*文字列 == '\n')
			break;
		else {
			_write(1, 文字列, 1);
			_write(1, "\n", 1);
			break;
		}
	default:
		if (文字列[--n] == '\n')
			--n;
		for (;;) {
			_write(1, &文字列[n], 1);
			if (n)
				--n;
			else {
				_write(1, "\n", 1);
				break;
			}
		}
		break;
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
