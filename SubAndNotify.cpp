/*
Implement your own subscription and notification software.
a) As a part of this exercise create a 'subscription class' which will contain details about the 
various subscription a user can subscribe to.
b) Create a 'user class' so that the software can create n users which can subscribe to various subscription offered by
'subscription class'
c) If there is any change in any subscription then all the user who have registered to the particular subscription should get notified.
*/
#include<bits/stdc++.h>
using namespace std;
class IObserver{
	public:
		virtual void update(string s) = 0;
};
class user:public IObserver{
	string name;
	public:
		user(string name){
			this->name = name;
		}
		void update(string s){
			cout<<"[INFO] "<<name<<" : "<<s<<"\n\n";
		}
};
class SubAndUnSub{
	vector<user*> NF,UD;
	public:
		void SubscribeNetflix(user *usr){
			NF.push_back(usr);
		}
		void SubscribeUdemy(user *usr){
			UD.push_back(usr);
		}
		void unSubscribeNetflix(user *usr){
			NF.erase(remove(NF.begin(),NF.end(),usr),NF.end());
		}
		void unSubscribeUdemy(user *usr){
			UD.erase(remove(UD.begin(),UD.end(),usr),UD.end());
		}
		void notifyInfoNetflix(string s){
			for(auto i:NF){
				i->update(s);
			}
		}
		void notifyInfoUdemy(string s){
			for(auto i:UD){
				i->update(s);
			}
		}
};
class UpdateProductInfo: public SubAndUnSub{
	public:
		void UpdateNetflix(string s){
			notifyInfoNetflix(s);
		}
		void UpdateUdemy(string s){
			notifyInfoUdemy(s);
		}
};

int main(){
	UpdateProductInfo p;
	user usr1("user 1");
	user usr2("user 2");
	p.SubscribeNetflix(&usr1);				//user 1 and 2 subscribes to netflix
	p.SubscribeNetflix(&usr2);
	p.SubscribeUdemy(&usr1);				//user 1 and 2 subscribes to udemy
	p.SubscribeUdemy(&usr2);
	
	p.UpdateNetflix("New EP coming soon...");
	p.UpdateUdemy("C/C++ training started");
	p.unSubscribeNetflix(&usr2);						//user 2 unsubscribes to netflix
	p.UpdateNetflix("EP releases on 20th sept, 2030");
		
}
