#include <io.h>
int main()
{
	char ������[30];
	switch (int n = _read(0, ������, sizeof ������)) {
	case -1:
	case 0:
		break;
	case 1:
		if (*������ == '\n')
			break;
		else {
			_write(1, ������, 1);
			_write(1, "\n", 1);
			break;
		}
	default:
		if (������[--n] == '\n')
			--n;
		for (;;) {
			_write(1, &������[n], 1);
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
yuy********����

2021/12/19 2:09

1��

��w��C����ŕ�����܂���
30�����܂ł̕����񂪓��͂��ꂽ��,���͂��ꂽ�������t���ɕ\������v���O����������,ABC����͂�����,CBA���o�͂���邱�Ƃ��m�F����
*/
