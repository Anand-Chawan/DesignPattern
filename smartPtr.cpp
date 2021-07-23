/*
Implement your own smart pointer class.
This smart pointer class can take pointer of any data type.
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
class smartPtr{
	T *ptr;
	public:
		explicit smartPtr(T *p=NULL){
			cout<<"\ncreated\n";
			ptr = p;
		}
		~smartPtr(){
			cout<<"\ndestroyed "<<(*ptr)<<"\n";
			delete (ptr);
		}
		T &operator*(){
			return *ptr;
		}
		T *operator->(){
			return ptr;
		}
};
int main(){
	
	{
		smartPtr<int> a(new int());
		*a = 10;
		cout<< (*a)<<"\n";
	}
	
	{
		smartPtr<char> b(new char());
		*b = 'a';
		cout<< (*b)<<"\n";
	}
	
	{
		smartPtr<bool> c(new bool());
		*c = false;
		cout<< (*c)<<"\n";
	}
	{
		smartPtr<float> d(new float());
		*d = 1.234;
		cout<< (*d)<<"\n";
	}
}
