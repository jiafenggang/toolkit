#include<iostream>
#include<codecvt>
#include<string>

using namespace std;
//vs中将string->wstring
//问题：对中文不支持
wstring utf8_to_wstring(const std::string& str){
	wstring_convert<codecvt_utf8<wchar_t>> mconv;
	return mconv.from_bytes(str);
}
//vs中将wstring->string
//问题：对中文不支持
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