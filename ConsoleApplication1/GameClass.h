#pragma once
#include<iostream>//入出力ストリーム
#define A 100000//回数限界

class GameClass {
	int hand = 999;//出した手(999=Error_Number)
	int win = 0;//勝ち数
	int lose = 0;//負け数
	int draw = 0;//引き分け数
	int hcount[3] = {};//出した手それぞれのカウント
	int handData[A] = {};//n回目の手
	int rcount[3] = {};//勝利、敗北、引き分け数の結果の配列(グラフ用)	

public:
	GameClass();//コンストラクタ
	~GameClass();//デストラクタ
	int GetHand();//手の取得
	int GetHCountData(int i);//手の回数データの取得
	int GetHandData(int i);//i回目の手のデータ取得
	void WinCount();//勝ち数カウンタ
	void LoseCount();//負け数カウンタ
	void DrawCount();//引き分け数カウンタ
	void SetRCount();//表示用配列生成
	int GetRCount(int i);//表示用配列返却用関数
	void SetHand(int h);//手のセット
	void SetComHand();//コンピュータの手のセット
	void ShowResult();//勝敗結果表示
	void HandData(int num, int h);//num回目の手のデータ集計
	void HandCount(int h);//それぞれの手の出した数カウンタ
	void HandResultShow();//それぞれの手の出した回数表
};

void ShowHand(int x, int y);//出した手の表示
void JudgeHand(GameClass* p, GameClass* c);//勝敗判断


