#pragma once
#include<iostream>//入出力ストリーム
#include<stdio.h>//標準入出力
using namespace std;//stdのusing宣言
//Gnuplot制御用ヘッダファイル
class Gnuplot {
	FILE* gnuplot;
public:
	Gnuplot();//gnuplot起動
	~Gnuplot();//gnuplot終了
	void SetTerm(const char* team,int n);//グラフの設定
	void SetStyle(const char* style);//グラフのスタイル設定
	void SetTitle(const char* tytle);//タイトル設定
	void SetXLabel(const char* xlabel);//x軸のラベル
	void SetYLabel(const char* ylabel);//y軸のラベル
	void SetXtics(int x);//x軸の目盛設定
	void SetYtics(int y);//y軸の目盛設定
	void SetXRange(int lower, int higher);//x軸の範囲
	void SetYRange(int lower, int higher);//y軸の範囲
	void PlotBegin();//データ送付開始
	void PlotBegin(const char* s);//グラフ形式設定後データ送付開始
	void AddPlotData(int x,int y);//データの追加
	void PlotEnd();//データ終了
};
