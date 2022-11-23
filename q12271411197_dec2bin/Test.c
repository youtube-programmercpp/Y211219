#include <stdio.h>
int main()
{
	printf("整数値を入力してください。\n");
	int n;
	printf("整数値: ");
	if (scanf_s("%d", &n) == 1) {
		printf("入力された値は %d でした。\n", n);
	}
	else {
		printf("正しく入力されませんでした。\n");
	}
	return 0;
}
