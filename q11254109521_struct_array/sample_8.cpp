#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1.ファイルを開く。
FILE* ファイルを開く()
{
	FILE * const fp = fopen("10_point.txt", "r");
	return  fp ? fp : fopen("10_print.txt", "r");
}
struct ファイルの数字 {
	int 生徒番号       ;
	int 五教科の点数[5];
};
int ファイルの数字を読む(FILE* fp, struct ファイルの数字* p)
{
	return fscanf
	( fp
	, "%d,%d,%d,%d,%d,%d"
	, &p->生徒番号
	, &p->五教科の点数[0]
	, &p->五教科の点数[1]
	, &p->五教科の点数[2]
	, &p->五教科の点数[3]
	, &p->五教科の点数[4]
	) == 6;
}
const struct ファイルの数字* 生徒番号で検索(const struct ファイルの数字 配列[], int 件数, int 生徒番号)
{
	const struct ファイルの数字*const 終わり = &配列[件数];
	while (配列 < 終わり) {
		if (配列->生徒番号 == 生徒番号)
			return 配列;
		else
			++配列;
	}
	return NULL;
}
int 合計(const struct ファイルの数字* p)
{
	return p->五教科の点数[0]
	+      p->五教科の点数[1]
	+      p->五教科の点数[2]
	+      p->五教科の点数[3]
	+      p->五教科の点数[4]
	;
}
int 評価(int 平均)
{
	/**/ if (80 <= 平均) return 'A';
	else if (70 <= 平均) return 'B';
	else if (60 <= 平均) return 'C';
	else /*-----------*/ return 'D';
}
int main()
{
	FILE * const fp = ファイルを開く();
	if (fp) {
		//2.ファイルの数字を配列に入れる。
		struct ファイルの数字 配列[100];
		int 件数 = 0;
		while (ファイルの数字を読む(fp, &配列[件数])) {
			if (++件数 == sizeof 配列 / sizeof *配列)
				break;
		}
		//3.キーボードから入力した数字を読み込み、生徒番号を入力してください。という文の下に入力した番号を表示する。
		//7.複数の生徒番号も入力可能
		for (;;) {
			int 生徒番号;
			printf("生徒番号を入力してください。\n");
			if (scanf("%d", &生徒番号) == 1) {
				//8.マイナスの値入力時に終了。
				if (生徒番号 < 0)
					break;
				else {
					//4.生徒番号があるかどうか判断し、存在しない場合は「生徒番号(入力した数字)は存在しません。」と出力される。
					const struct ファイルの数字* const p = 生徒番号で検索(配列, 件数, 生徒番号);
					if (p) {
						//5. 「生徒番号 国語 数学 社会 理科 英語 合計 平均 評価」と表示する。
						printf("生徒番号 国語 数学 社会 理科 英語 合計 平均 評価\n");
						//6.上記の文字の順に数字を表示する。
						const int sum = 合計(p);
						const int ave = (int)(sum / 5. + .5);
						printf("%8d %4d %4d %4d %4d %4d %4d %4d %c\n"
						, p->生徒番号
						, p->五教科の点数[0]
						, p->五教科の点数[1]
						, p->五教科の点数[2]
						, p->五教科の点数[3]
						, p->五教科の点数[4]
						, sum
						, ave
						, 評価(ave)
						);
					}
					else
						printf("生徒番号(%d)は存在しません。\n", 生徒番号);
				}
			}
			else {
				printf("入力エラーが発生しました。\n");
				break;
			}
		}
		//9.ファイルを閉じる。
		fclose(fp);
	}
}
	/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11254109521
ID非公開さん

2021/12/18 14:22

1回答

c言語の課題ですが、うっすらどのように書けば良いかはわかっているのですが具体的にどう書けば良いかわかりません。教えてください。
ファイル10_point.txt内容。
1001,24,48,65,44,30
1002,48,36,73,80,29
...
1100,44,83,63,30,24
一番左の番号は生徒番号でそれ以外は五教科の点数。
1.ファイルを開く。
2.ファイルの数字を配列に入れる。
3.キーボードから入力した数字を読み込み、生徒番号を入力してください。という文の下に入力した番号を表示する。
4.生徒番号があるかどうか判断し、存在しない場合は「生徒番号(入力した数字)は存在しません。」と出力される。
5. 「生徒番号 国語 数学 社会 理科 英語 合計 平均 評価」と表示する。
6.上記の文字の順に数字を表示する。

平均点に対する評価基準（4段階）平均点評価
80点以上A
70点以上80点未満B
60点以上70点未満C
60点未満D
7.複数の生徒番号も入力可能
8.マイナスの値入力時に終了。
9.ファイルを閉じる。
現在はここまで書けています。

#include <stdio.h>
int main(void){
int 件数;
int n;
int a[1000];
FILE *rfile;
rfile = fopen("10_print.txt", "r");
scanf("%d",&件数);
printf("生徒番号を入力してください。 \n%d\n",件数);
while()
fclose(rfile);
｝

C言語関連 | プログラミング・30閲覧・50
*/
