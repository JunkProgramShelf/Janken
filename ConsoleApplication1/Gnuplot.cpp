#include"Gnuplot.h"//Gnuplot����N���X�w�b�_�t�@�C��
//Gnuplot�̊e��R�}���h����

Gnuplot::Gnuplot() {//gnuplot�̋N��
	if ((gnuplot = _popen("gnuplot -persist", "w")) == NULL) {//�t�@�C���̑��ݔ��f
		cout << "�t�@�C����������܂���";//������Ȃ��ꍇ
		exit(1);//�I��
	}
}
Gnuplot::~Gnuplot() {//�f�X�g���N�^
	fprintf(gnuplot, "exit\n");//�I��
	_pclose(gnuplot);
}

void Gnuplot::SetTerm(const char* team,int n) {//�O���t�̐ݒ�
	fprintf(gnuplot,"set team %s %d\n",team,n);
}

void Gnuplot::SetStyle(const char* style) {//�O���t�̃X�^�C���ݒ�
	fprintf(gnuplot, "set style %s\n",style);
}

void Gnuplot::SetTitle(const char* title) {//�O���t�̃^�C�g���ݒ�
	fprintf(gnuplot,"set title '%s'\n", title);
}

void Gnuplot::SetXLabel(const char* xlabel) {//x���x���ݒ�
	fprintf(gnuplot, "set xlabel '%s'\n", xlabel);
}

void Gnuplot::SetYLabel(const char* ylabel) {//y���x���ݒ�
	fprintf(gnuplot, "set ylabel '%s'\n", ylabel);
}

void Gnuplot::SetXtics(int x) {//x���̃������ݒ�
	fprintf(gnuplot, "set xtics %d\n",x);
}
void Gnuplot::SetYtics(int y) {//y���̃������ݒ�
	fprintf(gnuplot, "set ytics %d\n", y);
}

void Gnuplot::SetXRange(int lower, int higher) {//x���͈̔͐ݒ�
	fprintf(gnuplot, "set xrange[%d:%d]\n", lower, higher);
}
void Gnuplot::SetYRange(int lower, int higher) {//y���͈̔͐ݒ�
	fprintf(gnuplot, "set yrange[%d:%d]\n", lower, higher);
}
void Gnuplot::PlotBegin() {//�`�ʊJ�n
	fprintf(gnuplot, "plot '-'\n");
}
void Gnuplot::PlotBegin(const char* s) {//�O���t�ݒ��ɕ`�ʊJ�n
	fprintf(gnuplot, "plot '-'%s\n",s);
}

void Gnuplot::AddPlotData(int x, int y) {//�f�[�^�̒ǉ�
	fprintf(gnuplot, "%d\t%d\n", x, y);
}
void Gnuplot::PlotEnd() {//�f�[�^�I��
	fprintf(gnuplot, "e'\n");
}
