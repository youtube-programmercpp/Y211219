// C������K�v���O�����F�P�o�C�g�������i���ŕ\�� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <stdio.h>
#include <limits.h>

static char *int2bin(unsigned char x)
{
	//static �̎g�p�͔��������Ƃ��낾���A����i�K�i����Ƃ��㋉�҂ɂ����ē��ʂȎ������ꍇ�j�Ɍ��苖�e�������̂ƍl����B
	//���R�[�h�ł� i = 7 ����̃J�E���g�_�E���̌`�ƂȂ��Ă����B������ǂ��Ǝv�����A�����ł� i = 0 ����J�E���g�A�b�v�̌`�Ƃ��Ă݂��B
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
		//�P�o�C�g�̓��͂ɂ��Ă݂�
		//�܂��Ascanf �̑���� scanf_s ���g�p�������A���قǑ傫�ȈӖ��͂Ȃ�
		unsigned char x;
		if (scanf_s("%hhu", &x) == 1) {
			printf("���� No.%d : ", i + 1);
			printf("%s\n", int2bin(x));
			++i;
		}
		else
			break;//���ُ͈킪����ΏI�����̂Ƃ���
	}
}
