#define	_CRT_SECURE_NO_WARNINGS //当方にて追加
#include<stdio.h>
#include<stdlib.h>
#define	POP_SIZE	10          //当方にて追加
char *int2bin(int x)
{
	int i;
	static char bin[40];
	for(i=7; i>=0; i--){
		bin[7-i]= ((x>>i)&1 )+'0';
	}
	bin[8]=0;
	return bin;
}

main()
{
	int i, x; char* g;          //当方にて修正

	for(i=0; i<POP_SIZE; i++)
	{
		scanf("%d",&x);
		printf("個体 No.%d : ",i);
		g=int2bin(x);
		printf("%s\n",g);
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271148501
1150342518さん

2022/11/17 15:41

1回答

C言語についての質問です。
入力したｘを二進数に変換して、ｇに代入し、出力したいのですがどうしたらいいでしょうか？


補足
POP＿SIZEなどは今回省いてしまいましたが、ちゃんと定義してあります。

C言語関連 | プログラミング・26閲覧
*/
/*
* [MEMO]
* このご質問に関しては既に適切な内容の回答が上がっていましたので当方からの更なる回答は差し控えました。
*/
