#pragma once
#include<iostream>//���o�̓X�g���[��
#include<stdio.h>//�W�����o��
using namespace std;//std��using�錾
//Gnuplot����p�w�b�_�t�@�C��
class Gnuplot {
	FILE* gnuplot;
public:
	Gnuplot();//gnuplot�N��
	~Gnuplot();//gnuplot�I��
	void SetTerm(const char* team,int n);//�O���t�̐ݒ�
	void SetStyle(const char* style);//�O���t�̃X�^�C���ݒ�
	void SetTitle(const char* tytle);//�^�C�g���ݒ�
	void SetXLabel(const char* xlabel);//x���̃��x��
	void SetYLabel(const char* ylabel);//y���̃��x��
	void SetXtics(int x);//x���̖ڐ��ݒ�
	void SetYtics(int y);//y���̖ڐ��ݒ�
	void SetXRange(int lower, int higher);//x���͈̔�
	void SetYRange(int lower, int higher);//y���͈̔�
	void PlotBegin();//�f�[�^���t�J�n
	void PlotBegin(const char* s);//�O���t�`���ݒ��f�[�^���t�J�n
	void AddPlotData(int x,int y);//�f�[�^�̒ǉ�
	void PlotEnd();//�f�[�^�I��
};
