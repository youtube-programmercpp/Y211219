#include <stdio.h>
int main()
{
	printf("�����l����͂��Ă��������B\n");
	int n;
	printf("�����l: ");
	if (scanf_s("%d", &n) == 1) {
		printf("���͂��ꂽ�l�� %d �ł����B\n", n);
	}
	else {
		printf("���������͂���܂���ł����B\n");
	}
	return 0;
}
