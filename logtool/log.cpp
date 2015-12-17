
#include"log.h"
#include<time.h>

JLog::JLog(const std::string& fileName):m_hFile(INVALID_HANDLE_VALUE),m_fileName(fileName){
	//char p[MAX_PATH];
	//GetCurrentDirectoryA(MAX_PATH, p);
	//strcat(p, "\\jlog.log");
	//fileName(p)
	////p + = "\\jlog.log";
	::InitializeCriticalSection(&m_hCriticalSection);
}
JLog::~JLog(){
	Close();
}
bool JLog::OpenFile(){
	if (IsOpen()){
		return true;
	}
	//OPEN_ALWAYS->��һ�������ļ�������ļ�����ֱ�Ӵ򿪣������ھʹ���.
	m_hFile = CreateFileA(m_fileName.c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hFile == INVALID_HANDLE_VALUE){
		Close();
		char p[20];
		sprintf(p, "������룺%d", GetLastError());
		std::string str = "������־�ļ�ʧ��,��־���ܲ��ڿ��ã�������Ӧ�û���Ӧ��Ȩ���Ƿ���Դ����ļ���";
		str += p;
		MessageBoxA(NULL,str.c_str(), "log", MB_OK);
		return false;
	}
	//��λ��ĩβ
	SetFilePointer(m_hFile, 0, NULL, FILE_END);
	return true;
}
void JLog::Close(){
	if (m_hFile != INVALID_HANDLE_VALUE){
		CloseHandle(m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
	::DeleteCriticalSection(&m_hCriticalSection);
}
bool JLog::IsOpen(){
	return m_hFile != INVALID_HANDLE_VALUE;
}
std::string JLog::GetStrTime(){
	std::string str;
	time_t now;
	time(&now);
	char p[30];
	strftime(p, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
	str = p;
	return str;
}
std::string JLog::GetLogHeader(ErrLevel errLevel){
	std::string str;
	switch (errLevel)
	{
	case FATAL_ERROR:
		str = GetStrTime() + "->��<FATAL_ERROR>:";
		break;
	case FIRST_ERROR:
		str = GetStrTime() + "->��  <FIRST_ERROR>:";
		break;
	case SECOND_ERROR:
		str = GetStrTime() + "->��    <SECOND_ERROR>:";
		break;
	case THIRD_ERROR:
		str = GetStrTime() + "->��      <THIRD_ERROR>:";
		break;
	case NORMAL_LOG:
		str = GetStrTime() + "->��:";
		break;
	}
	return str;
}
void JLog::LockSection(){
	::EnterCriticalSection(&m_hCriticalSection);
}
void JLog::UnLockSection(){
	::LeaveCriticalSection(&m_hCriticalSection);
}

void JLog::LogIn(const std::string& content, ErrLevel errLevel, const std::string& file, int line){
	__try{
		LockSection();
		WriteLog(content, errLevel,file,line);
	}
	__finally{
		UnLockSection();
	}
}
void JLog::WriteLog(const std::string& content, ErrLevel errLevel, const std::string& file, int line){
	OpenFile();
	std::string str(GetLogHeader(errLevel));
	str += content;
	str += file;
	//���line����Ĭ�ϵ�
	if (line != 0){
		char p[20];
		sprintf(p, "line:%d", line);
		str += p;
	}
	str+="\n";
	DWORD dw1;
	WriteFile(m_hFile, str.c_str(), str.length(), &dw1, NULL);
}