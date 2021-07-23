/*
Create your own phonebook software.
a) As part of this exercise you should use OOPS concepts to design the software and use 
'std::map data structure' to store records.
b) Each record should have a 'uniqueid' to identify it.
c) The phonebook software should have following APIs: 
	i) To insert record in 'map data structure'
	ii) To retrieve a record from the map. If the map does not contain the record then print message
		that 'record is not found' and then add the record to the map so that next time if the same record
		is searched then the software can retrieve the record.
	iii) To update a record in the map
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class PB{
	map<int,ll> a;
	public:
		void insert(int id,ll n){
			if(a.find(id)!=a.end()){
				cout<<"The id already exists\n\n";
				return;
			}
			cout<<"ID: "<<id<<" and ph: "<<n<<" is inserted\n\n";
			a[id]=n;
		}
		void getNo(int id){
			if(a.find(id)!=a.end()){
				cout<<"ID: "<<id<<" has ph no.: "<<a[id]<<"\n\n";
			}else{
				cout<<"record not found\n\n";
				cout<<"Please Enter ph: to add the details in record\n";
				ll n;cin>>n;
				a[id]=n;
				cout<<"ID: "<<id<<" and ph: "<<n<<" is inserted\n\n";
			}
		}
		void update(int id,ll n){
			cout<<"for ID: "<<id<<"\nPh: "<<a[id]<<" updated to Ph: "<<n<<"\n\n";
			a[id]=n;
		}
};
int main(){
	PB phone;
	int a;
	ll b;
	while(true){
		cout<<"Choose an option:\n1.INSERT DATA\n2.RETRIEVE DATA\n3.UPDATE DATA\n4.EXIT\n\n";
		int ch;cin>>ch;switch(ch){
			case 1:	cout<<"Enter id and Phone Number:\n";
					cin>>a>>b;
					phone.insert(a,b);break;
			case 2: cout<<"Enter the ID: ";
					cin>>a;
					phone.getNo(a);break;
			case 3: cout<<"Enter id: ";cin>>a;
					cout<<"Enter phone number to update: ";cin>>b;
					phone.update(a,b);break;
			case 4: exit(0);
			default: cout<<"INVALID INPUT\n";
		}
	}
}
