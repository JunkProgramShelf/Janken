#pragma once
#include<iostream>//���o�̓X�g���[��
#define A 100000//�񐔌��E

class GameClass {
	int hand = 999;//�o������(999=Error_Number)
	int win = 0;//������
	int lose = 0;//������
	int draw = 0;//����������
	int hcount[3] = {};//�o�����肻�ꂼ��̃J�E���g
	int handData[A] = {};//n��ڂ̎�
	int rcount[3] = {};//�����A�s�k�A�����������̌��ʂ̔z��(�O���t�p)	

public:
	GameClass();//�R���X�g���N�^
	~GameClass();//�f�X�g���N�^
	int GetHand();//��̎擾
	int GetHCountData(int i);//��̉񐔃f�[�^�̎擾
	int GetHandData(int i);//i��ڂ̎�̃f�[�^�擾
	void WinCount();//�������J�E���^
	void LoseCount();//�������J�E���^
	void DrawCount();//�����������J�E���^
	void SetRCount();//�\���p�z�񐶐�
	int GetRCount(int i);//�\���p�z��ԋp�p�֐�
	void SetHand(int h);//��̃Z�b�g
	void SetComHand();//�R���s���[�^�̎�̃Z�b�g
	void ShowResult();//���s���ʕ\��
	void HandData(int num, int h);//num��ڂ̎�̃f�[�^�W�v
	void HandCount(int h);//���ꂼ��̎�̏o�������J�E���^
	void HandResultShow();//���ꂼ��̎�̏o�����񐔕\
};

void ShowHand(int x, int y);//�o������̕\��
void JudgeHand(GameClass* p, GameClass* c);//���s���f


