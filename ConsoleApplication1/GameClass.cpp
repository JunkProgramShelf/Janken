#include "GameClass.h"//ゲームクラス用ヘッダファイル
#include <stdlib.h>//乱数を使用するためのヘッダファイル
#include <time.h>//乱数初期化に必要なヘッダファイル
using namespace std;
//ゲームで使用する各種関数の定義

GameClass::GameClass() {//コンストラクタ

}

GameClass::~GameClass() {//デストラクタ

}
int GameClass::GetHand() {//出した手を返す
	return hand;
}

int GameClass::GetHCountData(int i) {//出した手それぞれの回数を取得
	return hcount[i];
}
int GameClass::GetHandData(int i) {//i回目の手のデータを返す
	return handData[i];
}

void GameClass::SetHand(int h) {//自分の手のセット
	hand = h;
}
void GameClass::SetComHand() {//コンピュータの手のセット(乱数)
	srand((unsigned int)time(NULL));//乱数の初期化
	hand = rand() % 3;//0,1,2のいずれかをセット
}
void GameClass::WinCount() {//勝利数カウンタ
	win++;//勝ち数に1足す
}
void GameClass::LoseCount() {//敗北数カウンタ
	lose++;//負け数に1足す
}
void GameClass::DrawCount() {//引き分け数カウンタ
	draw++;//ひきわけ数に1足す
}
void GameClass::SetRCount() {//グラフ用の結果配列
	rcount[0] = win;//勝ち数
	rcount[1] = lose;//負け数
	rcount[2] = draw;//引き分け数
}
int GameClass::GetRCount(int i) {//結果の配列の取得
	return rcount[i];//0:勝利/1:負け/2:引き分け
}
void GameClass::ShowResult() {//結果表示
	cout << "勝利:" << win << endl;//勝利数
	cout << "敗北:" << lose << endl;//敗北数
	cout << "引き分け:" << draw << endl;//引き分け数
}
void GameClass::HandData(int num, int h) {//出した手のデータを記録
	handData[num] = h;//num回目の手を記録
}
void GameClass::HandCount(int h) {//それぞれの手の出した数カウンタ
	hcount[h] ++;//0:グー/1:チョキ/2:パー
}
void GameClass::HandResultShow() {
	cout << "グー:" << hcount[0] << "回" << endl;//グーの回数
	cout << "チョキ:" << hcount[1] << "回" << endl;//チョキの回数
	cout << "パー:" << hcount[2] << "回" << endl;//パーの回数

}


void JudgeHand(GameClass* p, GameClass* c) {//結果の判断
	int x = p->GetHand();//自分の手
	int y = c->GetHand();//コンピュータの手
	cout << "結果:";
	if (x == 0) {//自分がグー
		switch (y) {
		case 0://相手がグー
			cout << "相子です" << endl;
			p->DrawCount();//引き分け数をカウント
			c->DrawCount();//引き分け数をカウント
			break;

		case 1://相手がチョキ
			cout << "あなたの勝ちです" << endl;
			p->WinCount();//勝利数をカウント
			c->LoseCount();//敗北数をカウント
			break;

		case 2://相手がパー
			cout << "あなたの負けです" << endl;
			p->LoseCount();//敗北数をカウント
			c->WinCount();//勝利数をカウント
			break;
		}
	}
	else if (x == 1) {//自分がチョキ
		switch (y) {
		case 0://相手がグー
			cout << "あなたの負けです" << endl;
			p->LoseCount();//敗北数をカウント
			c->WinCount();//勝利数をカウント
			break;

		case 1://相手がチョキ
			cout << "相子です" << endl;
			p->DrawCount();//引き分け数をカウント
			c->DrawCount();//引き分け数をカウント
			break;

		case 2://相手がパー
			cout << "あなたの勝ちです" << endl;
			p->WinCount();//勝利数をカウント
			c->LoseCount();//敗北数をカウント
			break;
		}
	}

	else if (x == 2) {//自分がパー
		switch (y) {
		case 0://相手がグー
			cout << "あなたの勝ちです" << endl;
			p->WinCount();//勝利数をカウント
			c->LoseCount();//敗北数をカウント
			break;

		case 1://相手がチョキ
			cout << "あなたの負けです" << endl;
			p->LoseCount();//敗北数をカウント
			c->WinCount();//勝利数をカウント
			break;

		case 2://相手がパー
			cout << "相子です" << endl;
			p->DrawCount();//引き分け数をカウント
			c->DrawCount();//引き分け数をカウント
			break;
		}

	}
}

void ShowHand(int x, int y) {//出した手の表示
	cout << "プレイヤーの手:";//プレイヤーの手
	if (x == 0) { cout << "グー"; }//グーを表示
	else if (x == 1) { cout << "チョキ"; }//チョキを表示
	else if (x == 2) { cout << "パー"; }//パーを表示

	cout << "\nコンピュータの手:";//コンピュータの手
	if (y == 0) { cout << "グー"; }//グーを表示
	else if (y == 1) { cout << "チョキ"; }//チョキを表示
	else if (y == 2) { cout << "パー"; }//パーを表示
	cout << endl;
}