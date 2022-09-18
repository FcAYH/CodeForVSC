#include<iostream>
using namespace std;
class String{
	public:
		String(const char* str=NULL);
		String(const String& other);
//				String( char* str=NULL);
//		String( String& other);

		~String();
		int getstring();
	private:
		char* m_data;
};
//String::String( char* str){

String::String(const char* str){
	*m_data=*str;
	cout << "构造函数调用" << endl;
}
//String::String( String& other){

String::String(const String& other){
	*m_data=*other.m_data;//有问题
	cout << "复制构造函数调用" << endl;
}
String::~String(){
	cout << "析构函数调用" << endl;
}
int String::getstring(){
	cout << "该对象m_data为" << *m_data <<endl;
}
int main()
{
	const char* str="str1";
	String str1(str);
	String str2(str1);
	cout << "str1" << str1.getstring();
	cout << "str2" << str2.getstring();
    system("pause");
	return 0;
}