struct 最初の３文字 {
	char t[3];
};
void shift(char s[], int length)
{
	if (length > sizeof (struct 最初の３文字)) {
		char* const end = &s[length];
		const struct 最初の３文字 t = *(*(const struct 最初の３文字**)&s)++;
		do
			s[0 - sizeof (struct 最初の３文字)] = *s;
		while (++s < end);
		((struct 最初の３文字*)s)[-1] = t;
	}
}
#include <stdio.h>
int main()
{
	char s[] = "Programming";
	shift(s, sizeof s - 1);
	puts(s);
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11254141706
vnd********さん

2021/12/19 4:22

2回答

プログラミング初心者です。c言語です。
文字列s[]と文字列の長さlengthから、文字列の最初の３文字を文字列の後ろにつけるvoid型のshift関数を作りたいです。下記の関数の内容を教えていただけると嬉しいです。

例えば、
length=6, s[]=Programming
Programming → grammingPro

void shift(char s[],int length)
{

}

C言語関連 | プログラミング・60閲覧
*/
