/*
Implement your own "command and execute" design pattern.
a) As apart of this exercise create a 'abstract base class' for the command.
This abstract base class should contain all the basic method declaration for the command class.
b) Create at least two 'concrete child classes' from 'abstract class' i.e. you need to implement 
at least two command.
c) Create an executor class which will execute the commands created in step(b).
*/
#include<bits/stdc++.h>
using namespace std;
int vol,briNess;
class TV{
	public:
		void volUp(){
			if(vol==100){
				cout<<"volume is Maximum 100\n\n";
				return;
			}
			vol++; 
			cout<<"Vol increased to "<<vol<<"\n\n";
		}
		void volDown(){
			if(vol==0){
				cout<<"volume is Minimum 0\n\n";
				return;
			}
			vol--;
			cout<<"Vol decreased to "<<vol<<"\n\n";
		}
		void brightnessIncre(){
			if(briNess==100){
				cout<<"Brightness is Maximum 100\n\n";
				return;
			}
			briNess++;
			cout<<"Brightness is "<<briNess<<"\n\n";
		}
		void brightnessDecre(){
			if(briNess==0){
				cout<<"Brightness is Minimum 0\n\n";
				return;
			}
			briNess--;
			cout<<"Brightness is "<<briNess<<"\n\n";
		}
};
class command{
	public:
		virtual void execute() = 0;
};
class volUp:public command{
	private:
		TV& tv;
	public:
		volUp(TV& n): tv(n) {}
		void execute(){
			tv.volUp();
		}
};
class volDown:public command{
	private:
		TV& tv;
	public:
		volDown(TV& n): tv(n) {}
		
		void execute(){
			tv.volDown();
		}
};
class brightnessIncre:public command{
	private:
		TV& tv;
	public:
		brightnessIncre(TV& n): tv(n) {}
		
		void execute(){
			tv.brightnessIncre();
		}
};
class brightnessDecre:public command{
	private:
		TV& tv;
	public:
		brightnessDecre(TV& n): tv(n) {}
		void execute(){
			tv.brightnessDecre();
		}
};
class executor{
	public:
		void submit(command& cmd){
			cmd.execute();
		}
};
int main(){
	TV obj;
	volUp volUp(obj);
	volDown volDown(obj);
	brightnessIncre bIncre(obj);
	brightnessDecre bDecre(obj);
	
	executor remote;
	int ch;
	while(1){
		cout<<"Select your option:\n1.Increase Volume\n2.Decrease Volume\n3.Increase Brightness\n4.Decrease Brightness\n5.Exit\n\n";
		cin>>ch;switch(ch){
			case 1:	remote.submit(volUp); break;
			case 2: remote.submit(volDown); break;
			case 3: remote.submit(bIncre); break;
			case 4: remote.submit(bDecre); break;
			case 5: exit(0);
			default: cout<<"INVALID INPUT\n\n";
		}
	}
	return 0;
}
