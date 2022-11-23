// C++���K�v���O�����F�P�o�C�g�������i���ŕ\�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
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
		//unsigned char �^�ɂ������Ƃ��낾����������ƕ������͂Ƃ��ē��삵�Ă��܂��B
		unsigned short x;
		if (std::cin >> x) {
			if (x > UCHAR_MAX)
				break;//�P�o�C�g�ŕ\���ł��Ȃ��l�����͂��ꂽ��I���
			else {
				std::cout << "���� No." << i + 1 << " : " << int2bin(x) << '\n';
				++i;
			}
		}
		else
			break;//���������͂���Ȃ�������I���
	}
	return 0;
}
