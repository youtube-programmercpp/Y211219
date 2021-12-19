#include <stdio.h>
void shift(char s[], int length)
{
	if (length > 3) {
		char t[3];
		t[ 0]/* */ = s[ 0]/*P*/;
		t[ 1]/* */ = s[ 1]/*r*/;
		t[ 2]/* */ = s[ 2]/*o*/;
		for (int i = 0; i < length - 3; ++i) {
			s[i] = s[i + 3];
		}
		s[length - 3]/*i*/ = t[ 0]/*P*/;
		s[length - 2]/*n*/ = t[ 1]/*r*/;
		s[length - 1]/*g*/ = t[ 2]/*o*/;
	}
}
int main(void)
{
	//char s[] = "Programming";
	//shift(s, sizeof s - 1);
	//printf("%s\n", s);
	char s2[] = "abcd";
	shift(s2, sizeof s2 - 1);
	printf("%s\n", s2);
	return 0;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q12254158047
vnd********さん

2021/12/19 14:50

1回答

プログラミング初心者です。c言語です。 文字列s[]と文字列の長さlengthから、文字列の最初の３文字を文字列の後ろにつけるvoid型のshift関数を作ろうとしました。
例えば、Programming → grammingPro length=11

下記のプログラミングを実行したところabcdefgが結果として出てきてしまいます。
結果がdefgabcとなるようにしたいです。どこをどのようにすれば良いのか教えていただきたいです。なお、＃include <stdio.h>しか使うことができないので、<string.h>などは使えません。

#include <stdio.h>

void shift(char s[],int length){
char *p = s;
int i,n[100],k;

n[0]=(*(p+length-1));
n[1]=(*(p+length-2));
n[2]=(*(p+length-3));
for(i=3; s[i] != '\0'; i++){
n[i]=s[i-3];
}
}

int main(void)
{
int len;
char ss[100] = "abcdefg";

len=7;
shift(ss,7);

printf("%s\n",ss);

return 0;
}



.

C言語関連 | プログラミング・19閲覧
*/
