#define	_CRT_SECURE_NO_WARNINGS //�����ɂĒǉ�
#include<stdio.h>
#include<stdlib.h>
#define	POP_SIZE	10          //�����ɂĒǉ�
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
	int i, x; char* g;          //�����ɂďC��

	for(i=0; i<POP_SIZE; i++)
	{
		scanf("%d",&x);
		printf("�� No.%d : ",i);
		g=int2bin(x);
		printf("%s\n",g);
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11271148501
1150342518����

2022/11/17 15:41

1��

C����ɂ��Ă̎���ł��B
���͂��������i���ɕϊ����āA���ɑ�����A�o�͂������̂ł����ǂ������炢���ł��傤���H


�⑫
POP�QSIZE�Ȃǂ͍���Ȃ��Ă��܂��܂������A�����ƒ�`���Ă���܂��B

C����֘A | �v���O���~���O�E26�{��
*/
/*
* [MEMO]
* ���̂�����Ɋւ��Ă͊��ɓK�؂ȓ��e�̉񓚂��オ���Ă��܂����̂œ�������̍X�Ȃ�񓚂͍����T���܂����B
*/
