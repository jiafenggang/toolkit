#include<iostream>
#include<codecvt>
#include<string>

using namespace std;
//vs�н�string->wstring
//���⣺�����Ĳ�֧��
wstring utf8_to_wstring(const std::string& str){
	wstring_convert<codecvt_utf8<wchar_t>> mconv;
	return mconv.from_bytes(str);
}
//vs�н�wstring->string
//���⣺�����Ĳ�֧��
string wstring_to_utf8(const wstring& wstr){
	wstring_convert<codecvt_utf8<wchar_t>> mconv;
	return mconv.to_bytes(wstr);
}
int main(){
	wstring wstr= utf8_to_wstring(string("jiafenggang"));
	wcout << wstr << endl;
	wcout << __FUNCTIONW__ << endl;
	wstring wstr1 = L"jiafenggang";
	string str = wstring_to_utf8(wstr1);
	cout << str << endl;
	return 0;
}