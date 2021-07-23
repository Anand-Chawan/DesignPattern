/*
Implement stack data structure using linkedlist. The stack should be designed
in such a way that it can be used for any data type.
(The operation that can be performed in stack: push, pop & print the stack content).
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
	public:
		T val;
		node* next;
		node(T val){
			next=NULL;
			this->val = val;
		}
};
template<class T>
class List{
	node<T> *head;
	public:
		List(){
			head = NULL;
		}
		void push(T val){
			node<T> *n = new node<T>(val);
			if(head==NULL){
				head=n;
				return;
			}else{
				n->next=head;
				head=n;
			}
		}
		void pop(){
			if(head==NULL){
				cout<<"No Elements in Stack\n\n";
			}else{
				node<T> *curr;
				cout<<(head->val)<<" is poped from stack\n\n";
				curr = head;
				head=head->next;
				delete curr;
			}
		}
		void print(){
			node<T> *curr=head;
			cout<<"\nTop\n----\n";
			while(curr!=NULL){
				cout<<curr->val<<"\n";
				curr = curr->next;
			}
			cout<<"----\nBottom\n";
		}
};
template<class T>
void call(){
	int ch;
	List<T> l;
	T n;
	while(true){
		cout<<"\n\nChoose your option: \n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter element to push: ";
					cin>>n;
					l.push(n);break;
			case 2: l.pop(); break;
			case 3: l.print();break;
			case 4: exit(0);
			default: cout<<"INVALID INPUT\n\n";
		}
	}
}
int main(){
	cout<<"select datatype:\n1.char\n2.int\n3.float\n4.string\n\n";
	int ch;cin>>ch;switch(ch){
		case 1: call<char>();
		case 2: call<int>();
		case 3: call<float>();
		case 4: call<string>();
	}
}
