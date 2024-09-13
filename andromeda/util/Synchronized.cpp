#include "Synchronized.hpp"

using namespace andromeda::util;

void Synchronized::turn(Synchronized *turn) //传入另一个线程的Synchronized对象，阻塞调用该函数的线程，恢复执行传入的线程
{
	std::unique_lock<std::mutex> lock(mutex);
	{
		std::unique_lock<std::mutex> lock(turn->mutex);
		turn->is_running=true;
		turn->condition.notify_one(); //通知所有线程（即另一个线程）
	}
	is_running=false;
	while(!is_running)
		condition.wait(lock); //阻塞该线程，直到其他Synchronized对象调用turn(本对象)才可以恢复执行
}
