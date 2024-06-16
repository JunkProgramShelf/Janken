#include "GameClass.h"//�Q�[���N���X�p�w�b�_�t�@�C��
#include <stdlib.h>//�������g�p���邽�߂̃w�b�_�t�@�C��
#include <time.h>//�����������ɕK�v�ȃw�b�_�t�@�C��
using namespace std;
//�Q�[���Ŏg�p����e��֐��̒�`

GameClass::GameClass() {//�R���X�g���N�^

}

GameClass::~GameClass() {//�f�X�g���N�^

}
int GameClass::GetHand() {//�o�������Ԃ�
	return hand;
}

int GameClass::GetHCountData(int i) {//�o�����肻�ꂼ��̉񐔂��擾
	return hcount[i];
}
int GameClass::GetHandData(int i) {//i��ڂ̎�̃f�[�^��Ԃ�
	return handData[i];
}

void GameClass::SetHand(int h) {//�����̎�̃Z�b�g
	hand = h;
}
void GameClass::SetComHand() {//�R���s���[�^�̎�̃Z�b�g(����)
	srand((unsigned int)time(NULL));//�����̏�����
	hand = rand() % 3;//0,1,2�̂����ꂩ���Z�b�g
}
void GameClass::WinCount() {//�������J�E���^
	win++;//��������1����
}
void GameClass::LoseCount() {//�s�k���J�E���^
	lose++;//��������1����
}
void GameClass::DrawCount() {//�����������J�E���^
	draw++;//�Ђ��킯����1����
}
void GameClass::SetRCount() {//�O���t�p�̌��ʔz��
	rcount[0] = win;//������
	rcount[1] = lose;//������
	rcount[2] = draw;//����������
}
int GameClass::GetRCount(int i) {//���ʂ̔z��̎擾
	return rcount[i];//0:����/1:����/2:��������
}
void GameClass::ShowResult() {//���ʕ\��
	cout << "����:" << win << endl;//������
	cout << "�s�k:" << lose << endl;//�s�k��
	cout << "��������:" << draw << endl;//����������
}
void GameClass::HandData(int num, int h) {//�o������̃f�[�^���L�^
	handData[num] = h;//num��ڂ̎���L�^
}
void GameClass::HandCount(int h) {//���ꂼ��̎�̏o�������J�E���^
	hcount[h] ++;//0:�O�[/1:�`���L/2:�p�[
}
void GameClass::HandResultShow() {
	cout << "�O�[:" << hcount[0] << "��" << endl;//�O�[�̉�
	cout << "�`���L:" << hcount[1] << "��" << endl;//�`���L�̉�
	cout << "�p�[:" << hcount[2] << "��" << endl;//�p�[�̉�

}


void JudgeHand(GameClass* p, GameClass* c) {//���ʂ̔��f
	int x = p->GetHand();//�����̎�
	int y = c->GetHand();//�R���s���[�^�̎�
	cout << "����:";
	if (x == 0) {//�������O�[
		switch (y) {
		case 0://���肪�O�[
			cout << "���q�ł�" << endl;
			p->DrawCount();//�������������J�E���g
			c->DrawCount();//�������������J�E���g
			break;

		case 1://���肪�`���L
			cout << "���Ȃ��̏����ł�" << endl;
			p->WinCount();//���������J�E���g
			c->LoseCount();//�s�k�����J�E���g
			break;

		case 2://���肪�p�[
			cout << "���Ȃ��̕����ł�" << endl;
			p->LoseCount();//�s�k�����J�E���g
			c->WinCount();//���������J�E���g
			break;
		}
	}
	else if (x == 1) {//�������`���L
		switch (y) {
		case 0://���肪�O�[
			cout << "���Ȃ��̕����ł�" << endl;
			p->LoseCount();//�s�k�����J�E���g
			c->WinCount();//���������J�E���g
			break;

		case 1://���肪�`���L
			cout << "���q�ł�" << endl;
			p->DrawCount();//�������������J�E���g
			c->DrawCount();//�������������J�E���g
			break;

		case 2://���肪�p�[
			cout << "���Ȃ��̏����ł�" << endl;
			p->WinCount();//���������J�E���g
			c->LoseCount();//�s�k�����J�E���g
			break;
		}
	}

	else if (x == 2) {//�������p�[
		switch (y) {
		case 0://���肪�O�[
			cout << "���Ȃ��̏����ł�" << endl;
			p->WinCount();//���������J�E���g
			c->LoseCount();//�s�k�����J�E���g
			break;

		case 1://���肪�`���L
			cout << "���Ȃ��̕����ł�" << endl;
			p->LoseCount();//�s�k�����J�E���g
			c->WinCount();//���������J�E���g
			break;

		case 2://���肪�p�[
			cout << "���q�ł�" << endl;
			p->DrawCount();//�������������J�E���g
			c->DrawCount();//�������������J�E���g
			break;
		}

	}
}

void ShowHand(int x, int y) {//�o������̕\��
	cout << "�v���C���[�̎�:";//�v���C���[�̎�
	if (x == 0) { cout << "�O�["; }//�O�[��\��
	else if (x == 1) { cout << "�`���L"; }//�`���L��\��
	else if (x == 2) { cout << "�p�["; }//�p�[��\��

	cout << "\n�R���s���[�^�̎�:";//�R���s���[�^�̎�
	if (y == 0) { cout << "�O�["; }//�O�[��\��
	else if (y == 1) { cout << "�`���L"; }//�`���L��\��
	else if (y == 2) { cout << "�p�["; }//�p�[��\��
	cout << endl;
}