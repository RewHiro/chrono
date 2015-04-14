
//
//　クロノ(時間関係)
//


#include <iostream>
#include <chrono>
#include <ctime>//　localtime
#include <sstream>
#include <iomanip>

int main(){
	//　現在の時刻
	std::chrono::system_clock::now();

	std::time_t time = 
		std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	char buff[26];
	ctime_s(buff, sizeof(buff), &time);
	std::cout << buff << std::endl;


	// 秒
	std::chrono::seconds sec(60);
	// 分
	std::chrono::minutes min(20);
	// 時
	std::chrono::hours hours(6);

	//　ナノ秒(10^-9)
	std::chrono::nanoseconds nanosec(5 * static_cast<int>(std::powf(10,9)));
	//　マイクロ秒(10^-6)
	std::chrono::microseconds microsec(8 * static_cast<int>(std::powf(10, 6)));
	//　ミリ秒(10^-3)
	std::chrono::milliseconds millisec(10 * 10 * 10);

	//time_tに変化できる時計クラス
	std::chrono::system_clock;

	{
		// 単位が大きい方で計算する場合は明示的にキャストをしなければならない
		//　理由として誤差が生じるため
		//　例：sec(10) + min(20) = 20
		//　例：sec(60) + min(21) = 21
		std::chrono::minutes add = std::chrono::duration_cast<std::chrono::minutes>(sec)+min;
		std::cout << add.count() << std::endl;
	}
	{
		//　単位が小さい方で計算する場合は暗黙的キャストを行ってくれる
		std::chrono::seconds add = sec + min;// 30 + 20 * 60 = 30 + 1200 = 1230 
		std::cout << add.count() << std::endl;
	}


	// 計測処理
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	// ここに計測したい処理
	//for (int i = 0; i < 10000; i++){
	//	Func();
	//}

	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

	std::chrono::duration < std::chrono::system_clock::rep, std::chrono::system_clock::period > processing_time = 
		end- start;
	
	std::cout << processing_time.count() << std::endl;
}