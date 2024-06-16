#include"Gnuplot.h"//Gnuplot制御クラスヘッダファイル
//Gnuplotの各種コマンド制御

Gnuplot::Gnuplot() {//gnuplotの起動
	if ((gnuplot = _popen("gnuplot -persist", "w")) == NULL) {//ファイルの存在判断
		cout << "ファイルが見つかりません";//見つからない場合
		exit(1);//終了
	}
}
Gnuplot::~Gnuplot() {//デストラクタ
	fprintf(gnuplot, "exit\n");//終了
	_pclose(gnuplot);
}

void Gnuplot::SetTerm(const char* team,int n) {//グラフの設定
	fprintf(gnuplot,"set team %s %d\n",team,n);
}

void Gnuplot::SetStyle(const char* style) {//グラフのスタイル設定
	fprintf(gnuplot, "set style %s\n",style);
}

void Gnuplot::SetTitle(const char* title) {//グラフのタイトル設定
	fprintf(gnuplot,"set title '%s'\n", title);
}

void Gnuplot::SetXLabel(const char* xlabel) {//xラベル設定
	fprintf(gnuplot, "set xlabel '%s'\n", xlabel);
}

void Gnuplot::SetYLabel(const char* ylabel) {//yラベル設定
	fprintf(gnuplot, "set ylabel '%s'\n", ylabel);
}

void Gnuplot::SetXtics(int x) {//x軸のメモリ設定
	fprintf(gnuplot, "set xtics %d\n",x);
}
void Gnuplot::SetYtics(int y) {//y軸のメモリ設定
	fprintf(gnuplot, "set ytics %d\n", y);
}

void Gnuplot::SetXRange(int lower, int higher) {//x軸の範囲設定
	fprintf(gnuplot, "set xrange[%d:%d]\n", lower, higher);
}
void Gnuplot::SetYRange(int lower, int higher) {//y軸の範囲設定
	fprintf(gnuplot, "set yrange[%d:%d]\n", lower, higher);
}
void Gnuplot::PlotBegin() {//描写開始
	fprintf(gnuplot, "plot '-'\n");
}
void Gnuplot::PlotBegin(const char* s) {//グラフ設定後に描写開始
	fprintf(gnuplot, "plot '-'%s\n",s);
}

void Gnuplot::AddPlotData(int x, int y) {//データの追加
	fprintf(gnuplot, "%d\t%d\n", x, y);
}
void Gnuplot::PlotEnd() {//データ終了
	fprintf(gnuplot, "e'\n");
}
