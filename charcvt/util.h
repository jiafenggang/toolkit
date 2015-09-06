#pragma once
#include<Windows.h>
#include<string>

class UTIL
{
public:
	//���ܣ���char���� ת��Ϊwchar_t����
	//*ansi->char����
	//���أ����ɵ�wchar_t����
	//ע�⣺�û������ͷŷ��������ڴ�
	//Լ��������ı��û�����Ĳ��������û����Ըı䷵��ֵ
	static PWSTR ansi2unic(PCSTR ansi);
	//���ܣ���wchar_t���� ת��Ϊchar����
	//*unic->wchar_t����
	//���أ����ɵ�char����
	//ע�⣺�û������ͷŷ��������ڴ�
	//Լ��������ı��û�����Ĳ��������û����Ըı䷵��ֵ
	static PSTR	unic2ansi(PCWSTR unic);
	//���ܣ���wchar_t���� ת��Ϊstring
	//*unic->wchar_t����
	//���أ����ɵ�string
	//Լ��������ı��û�����Ĳ��������û����Ըı䷵��ֵ
	static std::string unic2str(const wchar_t* unic);
	//���ܣ���string ת��Ϊwchar_t����
	//*str->Ҫת����string
	//���أ����ɵ�wchar_t����
	//ע�⣺�û������ͷŷ��������ڴ�
	//Լ��������ı��û�����Ĳ��������û����Ըı䷵��ֵ
	static wchar_t* str2unic(const std::string& str);
private:

};
