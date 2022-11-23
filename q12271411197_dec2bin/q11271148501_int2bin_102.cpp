// C++練習プログラム：１バイト整数を二進数で表示 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <limits.h>

static char* int2bin(int x)
{
	static char bin[CHAR_BIT + 1];
	for (int i = 0;;) {
		bin[i] = ((x >> (CHAR_BIT - 1 - i)) & 1) + '0';
		if (i == CHAR_BIT) {
			bin[CHAR_BIT] = '\0';
			return bin;
		}
		else
			++i;
	}
}

int main()
{
	for (int i = 0;;) {
		//unsigned char 型にしたいところだがそうすると文字入力として動作してしまう。
		unsigned short x;
		if (std::cin >> x) {
			if (x > UCHAR_MAX)
				break;//１バイトで表現できない値が入力されたら終わり
			else {
				std::cout << "入力 No." << i + 1 << " : " << int2bin(x) << '\n';
				++i;
			}
		}
		else
			break;//正しく入力されなかったら終わり
	}
	return 0;
}
