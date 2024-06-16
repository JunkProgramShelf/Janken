#include <iostream>//入出力ストリーム
#include "GameClass.h"//ゲーム用の関数定義
#include"Gnuplot.h"//グラフ描写用
using namespace std;//stdのusing宣言
/*ゲーム本体のソースコード*/

//main関数
int main() {
	int flg = 1;//判断フラグ
	int count = 0;//ゲーム回数
	int h = 0;//プレイヤーの手
	GameClass plr, com;//プレーヤー(plr)とコンピュータ(com)のインスタンス
	Gnuplot gp1, gp2, gp3, gp4;//グラフ用インスタンス
	cout << "じゃんけんゲーム" << endl;//タイトル
	cout << "0はグー、1はチョキ、2はパーになります" << endl;//ルール説明
	cout << "*------------------------------------------*" << endl;//区分け線出力

	//ゲーム本体
	while (true) {//ゲーム開始
		cout << "*------------------------------------------*" << endl;//区分け線出力
		count++;//ゲーム回数
		if (count - 1 == A) {//回数限界の判断
			cout << "やりすぎです\n";
			cout << "休憩をとりましょう\n";
			break;//ゲーム強制終了
		}

		cout << count << "回目";//回数出力
		cout << " \n手を入力してください\n";
		cout << "グー:0 / チョキ : 1 / パー : 2\n";//説明
		cout << "入力:";
		cin >> h;//手の入力

		if (cin.fail()) {//入力が不正化の判断
			cout << "Input Erorr Of Type";//入力エラー(文字列または不正な入力)
			return 1;//ゲーム強制終了
		}

		plr.SetHand(h);//プレイヤー手のセット
		com.SetComHand();//コンピュータの手のセット

		if (!(plr.GetHand() == 0 || plr.GetHand() == 1 || plr.GetHand() == 2)) {
			//0,1,2のいずれにも当たらない場合
			cout << "Input Error about Out Of Range";//入力エラー(範囲外の値)
			return 1;//ゲーム強制終了
		}

		ShowHand(plr.GetHand(), com.GetHand());//出した手の表示
		JudgeHand(&plr, &com);//勝敗判断
		plr.HandCount(h);//手の回数カウント
		com.HandCount(com.GetHand());//手の回数カウント
		plr.HandData(count - 1, h);//プレイヤーの手の記録
		com.HandData(count - 1, com.GetHand());//コンピュータの手の記録
		cout << "続けますか?(はい(Yes)...1/いいえ(No)...2):";//継続の判断
		cin >> flg;//ゲームの継続の判断入力

		if (cin.fail()) {//入力内容の判断
			cout << "Input Erorr Of Type";//入力エラー(文字列または不正な入力)
			return 1;//ゲーム強制終了
		}
		if (flg == 2 || flg != 1) {//ゲーム終了判断
			break;
		}
	}//ゲーム終了
	//ここまでゲーム本体

	cout << "ゲーム終了" << endl;//終わりの出力
	cout << "*--------------------------------------------*" << endl;//区分け線出力
	cout << "結果\n";
	cout << "勝負数:" << count << endl;//勝負数出力
	plr.ShowResult();//勝負結果の表示
	cout << "\n統計結果\n";
	plr.HandResultShow();//出した手の数の表示

	//プレイヤーの手の推移のグラフ表示
	gp1.SetTitle("プレイヤーの手の推移");//グラフタイトル設定
	gp1.SetXRange(0, count);//X軸範囲指定[回]
	gp1.SetXLabel("回");//X軸ラベルの設定
	gp1.SetYLabel("グー:0/チョキ:1/パー:2");//Y軸ラベルの設定
	gp1.SetYRange(0, 3);//Y軸範囲の設定
	gp1.SetXtics(1);//X軸目盛の設定
	gp1.SetYtics(1);//Y軸目盛の設定
	gp1.PlotBegin("with linespoints");//線と点で描写する命令
	for (int i = 0; i < count; i++) {//ループ開始
		gp1.AddPlotData(i + 1, plr.GetHandData(i));//データのプロット
	}//ループ終了
	gp1.PlotEnd();//gnuplot終了

	//コンピュータの手の推移のグラフ化
	gp2.SetTitle("コンピュータの手の推移");//グラフタイトル
	gp2.SetXRange(0, count);//X軸の範囲設定
	gp2.SetXLabel("回");//X軸のラベル設定
	gp2.SetYLabel("グー:0/チョキ:1/パー:2");//Y軸のラベル設定
	gp2.SetYRange(0, 3);//Y軸の範囲設定
	gp2.SetXtics(1);//X軸の目盛設定
	gp2.SetYtics(1);//Y軸の目盛設定
	gp2.PlotBegin("with linespoints");//線と点で描写
	for (int i = 0; i < count; i++) {//ループ開始
		gp2.AddPlotData(i + 1, com.GetHandData(i));//データのプロット
	}//ループ終了
	gp2.PlotEnd();//gnuplot終了

	//出した手の数のヒストグラム表示
	gp3.SetTitle("出した手の数結果");//グラフタイトル
	gp3.SetStyle("fill solid border lc rgb 'black'");//グラフのスタイル設定
	gp3.SetXRange(-1, 3);//X軸の範囲設定
	gp3.SetXLabel("0:グー/1:チョキ/2:パー");//X軸のラベル設定
	gp3.SetYLabel("回");//Y軸のラベル設定
	gp3.SetXtics(1);//X軸の目盛設定
	gp3.SetYtics(1);//Y軸の目盛設定
	gp3.PlotBegin("with boxes");//ヒストグラムで出力する命令
	for (int i = 0; i < 3; i++) {//ループ開始
		gp3.AddPlotData(i, plr.GetHCountData(i));//データのプロット
	}//ループ終了
	gp3.PlotEnd();//gnuplot終了

	//勝敗数ヒストグラム表示
	plr.SetRCount();//出力用配列準備
	gp4.SetTitle("勝敗数");//グラフタイトル
	gp4.SetStyle("fill solid border lc rgb 'black'");//グラフのスタイル設定
	gp4.SetXLabel("0:勝利/1:敗北/2:引き分け");//X軸のラベル設定
	gp4.SetYLabel("回");//Y軸のラベル設定
	gp4.SetXRange(-1, 3);//X軸の範囲設定
	gp4.SetXtics(1);//X軸の目盛設定
	gp4.SetYtics(1);//Y軸の目盛設定
	gp4.PlotBegin("with boxes");//ヒストグラムで出力する命令
	for (int i = 0; i < 3; i++) {//ループ開始
		gp4.AddPlotData(i, plr.GetRCount(i));//データのプロット
	}//ループ終了
	gp4.PlotEnd();//gnuplot終了

	return 0;//全処理終了
}//ここまでmain関数