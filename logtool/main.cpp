#include"log.h"
#include<process.h>
#include<Windows.h>
JLog mlog;

void thread1(void* v){
	while (true){
		mlog.LogIn("�߳�1���:FATAL_ERROR �ӼӼӼӼӼӼӼ�", FATAL_ERROR);
		mlog.LogIn("�߳�1���:FIRST_ERROR ���������", FIRST_ERROR);
		mlog.LogIn("�߳�1���:SECOND_ERROR �ոոոոոոո�", SECOND_ERROR);
		mlog.LogIn("�߳�1���:NORMAL_ERROR ����������������", NORMAL_LOG);
	}
}
void thread2(void* v){
	while (true){
		mlog.LogIn("�߳�2���:FATAL_ERROR ������������������", FATAL_ERROR);
		mlog.LogIn("�߳�2���:FIRST_ERROR ������������������", FIRST_ERROR);
		mlog.LogIn("�߳�2���:SECOND_ERROR ףףףףףףףףף", SECOND_ERROR);
		mlog.LogIn("�߳�2���:NORMAL_ERROR ������������������", NORMAL_LOG);
	}
}
void thread3(void* v){
	while (true){
		mlog.LogIn("�߳�3���:FATAL_ERROR", FATAL_ERROR);
		mlog.LogIn("�߳�3���:FIRST_ERROR", FIRST_ERROR);
		mlog.LogIn("�߳�3���:SECOND_ERROR", SECOND_ERROR);
		mlog.LogIn("�߳�3���:NORMAL_ERROR", NORMAL_LOG);
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
	std::string str = "�ӷ��\n";
	DWORD dw;
	WriteFile(hFile, str.c_str(), str.length(), &dw, NULL);
	WriteFile(hFile, str.c_str(), str.length(), &dw, NULL);
	CloseHandle(hFile);*/

	return 0;
}