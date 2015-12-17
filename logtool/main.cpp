#include"log.h"
#include<process.h>
#include<Windows.h>
JLog mlog;

void thread1(void* v){
	while (true){
		mlog.LogIn("线程1输出:FATAL_ERROR 加加加加加加加加", FATAL_ERROR);
		mlog.LogIn("线程1输出:FIRST_ERROR 冯冯冯冯冯冯冯冯", FIRST_ERROR);
		mlog.LogIn("线程1输出:SECOND_ERROR 刚刚刚刚刚刚刚刚", SECOND_ERROR);
		mlog.LogIn("线程1输出:NORMAL_ERROR 王王王王王王王王", NORMAL_LOG);
	}
}
void thread2(void* v){
	while (true){
		mlog.LogIn("线程2输出:FATAL_ERROR 郭郭郭郭郭郭郭郭郭", FATAL_ERROR);
		mlog.LogIn("线程2输出:FIRST_ERROR 赵赵赵赵赵赵赵赵赵", FIRST_ERROR);
		mlog.LogIn("线程2输出:SECOND_ERROR 祝祝祝祝祝祝祝祝祝", SECOND_ERROR);
		mlog.LogIn("线程2输出:NORMAL_ERROR 蒋蒋蒋蒋蒋蒋蒋蒋蒋", NORMAL_LOG);
	}
}
void thread3(void* v){
	while (true){
		mlog.LogIn("线程3输出:FATAL_ERROR", FATAL_ERROR);
		mlog.LogIn("线程3输出:FIRST_ERROR", FIRST_ERROR);
		mlog.LogIn("线程3输出:SECOND_ERROR", SECOND_ERROR);
		mlog.LogIn("线程3输出:NORMAL_ERROR", NORMAL_LOG);
	}
}

int main(){
	JLog mlog2("dkfksdf.txt");
	mlog = mlog2;
	_beginthread(thread1, 0, NULL);
	_beginthread(thread2, 0, NULL);
	_beginthread(thread3, 0, NULL);
	SleepEx(INFINITE, TRUE);
	/*HANDLE hFile=CreateFileA("log.txt", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	std::string str = "加冯刚\n";
	DWORD dw;
	WriteFile(hFile, str.c_str(), str.length(), &dw, NULL);
	WriteFile(hFile, str.c_str(), str.length(), &dw, NULL);
	CloseHandle(hFile);*/

	return 0;
}