// C++���K�v���O���� Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <numeric>
//�Q�i���ɕϊ����ĕ\������֐�
void b(unsigned n);
void a(unsigned n)
{
	// �܂���̌���\������
	//     n >> 1 �� n ���E�ɂP�r�b�g�V�t�g���邱�Ƃ� n �̏�̌���������
	//     n / 2 �Ɛ��l�I�ɓ������ʂƂȂ邪�A�������Ă��܂���CPU�ɖ��p�ȕ��ׂ��|���邱�ƂɂȂ�
	//    �istd::cout �ɏo�͂��邱�Ƃɂ�镉�ׂ����|�I�ɑ傫�����߁A���̗�ł͂ǂ���ł��卷�Ȃ����j
	b(n >> 1);
	// ���̌�A���̌���\������
	//     n & 1 �� n �� LSB (�ŉ��ʃr�b�g)�A���Ȃ킿�Q�i���\���ł̉��ꌅ�A��������
	std::cout << (n & 1); //
}
void b(unsigned n)
{
	//��[���̏ꍇ�Ɍ��� a �֐����Ăяo��
	if (n)
		a(n);
}
int main()
{
	std::cout << "2�i���ɕϊ����ĕ\�����܂��B\n";
	for (;;) {
		//���͓��e���P�O�i���ŕ\�����ꂽ�����Ȃ������ł�����̂Ƃ��ēǂݎ��
		std::cout
			<< "�I������ɂ� [Ctrl]+[Z]��[Enter] �����\n"
			<< "10�i��: "
			;
		unsigned n;
		if (std::cin >> n) {
			//�Q�i���ɂ��ĕ\������
			std::cout << " 2�i��: ";
			a(n);
			std::cout << "\n";
			continue;
		}
		else if (std::cin.eof())
			break;//EOF�ɓ��B�����̂Łi[Ctrl][Z]�����͂��ꂽ�̂Łj�I���
		else {
			//�ǂݎ�莸�s
			std::cerr << "���������͂���܂���ł����B\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	return 0;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q12271411197
1150626435����

2022/11/22 22:48

3��

C�����10�i������2�i���ɕϊ�����v���O���~���O�ŁA����l���傫�Ȓl����͂���ƕ\�������2�i���̒l���������Ȃ����̂��\�������݂����Ȃ̂ł����A
���̒l����̉��Ȃ̂��Ɖ��̐������\�����ꖳ���̂��̗��R��������܂���B
����������Ē��������ł�

�⑫
�厊�}�ł��肢���܂�
*/
