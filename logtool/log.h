#pragma once
#include<string>
#include<Windows.h>
enum ErrLevel{
	//��������Ҫ�˳�://2014-02-03 12:02:06->��������
	FATAL_ERROR,
	//һ�����󣬸ô�������ʧ�ܣ������ܼ��������������2014-02-03 12:02:06->������
	FIRST_ERROR,
	//�������󣬸ô�������ϸ�ڴ���ʧ�ܣ������ܴ�������ϸ�ڣ�2014-02-03 12:02:06->����
	SECOND_ERROR,
	//��������ϸ΢���󣬲�Ӱ�����ִ�У�2014-02-03 12:02:06->��
	THIRD_ERROR,
	//����ִ����Ϣ:2014-02-03 12:02:06->��
	NORMAL_LOG
};
class JLog{
public:
	JLog(const std::string& fileName = "jialog.log");
	~JLog();
	void LogIn(const std::string& content, ErrLevel errLevel, const std::string& file = "",int line = 0);
	
private:
	CRITICAL_SECTION m_hCriticalSection;
	HANDLE m_hFile;
	void LockSection();
	void UnLockSection();
	std::string GetStrTime();
	std::string GetLogHeader(ErrLevel);
	bool IsOpen();
	bool OpenFile();
	void Close();
	void WriteLog(const std::string& content, ErrLevel errLevel, const std::string& file, int line);
	std::string m_fileName;
};