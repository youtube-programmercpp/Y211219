// C言語練習プログラム：１バイト整数を二進数で表示 Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <limits.h>

static char *int2bin(unsigned char x)
{
	//static の使用は避けたいところだが、入門段階（それとも上級者において特別な事情がある場合）に限り許容されるものと考える。
	//元コードでは i = 7 からのカウントダウンの形となっていた。それも良いと思うが、ここでは i = 0 からカウントアップの形としてみた。
	static char bin[CHAR_BIT + 1];
	for (int i = 0;;) {
		bin[i]= ((x >> (CHAR_BIT - 1 - i)) & 1) + '0';
		if (i == CHAR_BIT) {
			bin[CHAR_BIT] = '\0';
			return bin;
		}
		else
			++i;
	}
}

main()
{
	for (int i = 0;;) {
		//１バイトの入力にしてみた
		//また、scanf の代わりに scanf_s を使用したが、さほど大きな意味はない
		unsigned char x;
		if (scanf_s("%hhu", &x) == 1) {
			printf("入力 No.%d : ", i + 1);
			printf("%s\n", int2bin(x));
			++i;
		}
		else
			break;//入力異常があれば終わるものとした
	}
}
