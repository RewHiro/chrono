
//
//�@�N���m(���Ԋ֌W)
//


#include <iostream>
#include <chrono>
#include <ctime>//�@localtime
#include <sstream>
#include <iomanip>

int main(){
	//�@���݂̎���
	std::chrono::system_clock::now();

	std::time_t time = 
		std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	char buff[26];
	ctime_s(buff, sizeof(buff), &time);
	std::cout << buff << std::endl;


	// �b
	std::chrono::seconds sec(60);
	// ��
	std::chrono::minutes min(20);
	// ��
	std::chrono::hours hours(6);

	//�@�i�m�b(10^-9)
	std::chrono::nanoseconds nanosec(5 * static_cast<int>(std::powf(10,9)));
	//�@�}�C�N���b(10^-6)
	std::chrono::microseconds microsec(8 * static_cast<int>(std::powf(10, 6)));
	//�@�~���b(10^-3)
	std::chrono::milliseconds millisec(10 * 10 * 10);

	//time_t�ɕω��ł��鎞�v�N���X
	std::chrono::system_clock;

	{
		// �P�ʂ��傫�����Ōv�Z����ꍇ�͖����I�ɃL���X�g�����Ȃ���΂Ȃ�Ȃ�
		//�@���R�Ƃ��Č덷�������邽��
		//�@��Fsec(10) + min(20) = 20
		//�@��Fsec(60) + min(21) = 21
		std::chrono::minutes add = std::chrono::duration_cast<std::chrono::minutes>(sec)+min;
		std::cout << add.count() << std::endl;
	}
	{
		//�@�P�ʂ����������Ōv�Z����ꍇ�͈ÖٓI�L���X�g���s���Ă����
		std::chrono::seconds add = sec + min;// 30 + 20 * 60 = 30 + 1200 = 1230 
		std::cout << add.count() << std::endl;
	}


	// �v������
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

	// �����Ɍv������������
	//for (int i = 0; i < 10000; i++){
	//	Func();
	//}

	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

	std::chrono::duration < std::chrono::system_clock::rep, std::chrono::system_clock::period > processing_time = 
		end- start;
	
	std::cout << processing_time.count() << std::endl;
}