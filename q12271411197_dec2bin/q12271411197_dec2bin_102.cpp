// C++練習プログラム Copyright(C) 2022 https://www.youtube.com/@ProgrammerCpp
#include <iostream>
#include <numeric>
//２進数に変換して表示する関数
void b(unsigned n);
void a(unsigned n)
{
	// まず上の桁を表示する
	//     n >> 1 で n を右に１ビットシフトすることで n の上の桁が得られる
	//     n / 2 と数値的に同じ結果となるが、そうしてしまうとCPUに無用な負荷を掛けることになる
	//    （std::cout に出力することによる負荷が圧倒的に大きいため、この例ではどちらでも大差ないが）
	b(n >> 1);
	// その後、下の桁を表示する
	//     n & 1 で n の LSB (最下位ビット)、すなわち２進数表現での下一桁、が得られる
	std::cout << (n & 1); //
}
void b(unsigned n)
{
	//非ゼロの場合に限り a 関数を呼び出す
	if (n)
		a(n);
}
int main()
{
	std::cout << "2進数に変換して表示します。\n";
	for (;;) {
		//入力内容を１０進数で表現された符号なし整数であるものとして読み取る
		std::cout
			<< "終了するには [Ctrl]+[Z]と[Enter] を入力\n"
			<< "10進数: "
			;
		unsigned n;
		if (std::cin >> n) {
			//２進数にして表示する
			std::cout << " 2進数: ";
			a(n);
			std::cout << "\n";
			continue;
		}
		else if (std::cin.eof())
			break;//EOFに到達したので（[Ctrl][Z]が入力されたので）終わり
		else {
			//読み取り失敗
			std::cerr << "正しく入力されませんでした。\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	return 0;
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q12271411197
1150626435さん

2022/11/22 22:48

3回答

C言語の10進数から2進数に変換するプログラミングで、ある値より大きな値を入力すると表示される2進数の値が正しくないものが表示されるみたいなのですが、
その値が一体何なのかと何故正しく表示され無いのかの理由が分かりません。
これを教えて頂きたいです

補足
大至急でお願いします
*/
