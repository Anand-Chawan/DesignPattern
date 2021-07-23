/*
Implement queue data structure using linkedlist.The queue should be designed
in such a way that it can be used for any data type.
(The operation that can be performed in queue: push_back, pop_front & print the queue content)
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
	public:
		T val;
		node* next;
		node(T val){
			next = NULL;
			this->val = val;
		}
};
template<class T>
class List{
	node<T> *head, *curr;
	public:
		List(){
			head = curr = NULL;
		}
		void push_back(T val){
			node<T>* n = new node<T>(val);
			cout<<val<<" is pushed into queue\n";
			if(head==NULL){
				head = n;
			}else{
				curr = head;
				while(curr->next!=NULL) curr=curr->next;
				curr->next = n;
			}
		}
		void pop_front(){
			if(head==NULL){
				cout<<"No element found\n";
			}else{
				cout<<head->val<<" is removed from queue\n";
				curr = head;
				head = head->next;
				delete curr;
			}
		}
		void print(){
			cout<<"Elements in the queue:\n [";
			curr = head;
			while(curr!=NULL){
				cout<<curr->val;
				curr = curr->next;
				if(curr!=NULL) cout<<", ";
			}
			cout<<"]\n\n";
		}
};
template<typename T>
void call(){
	int ch;
	T n;
	List<T> l;
	while(true){
		cout<<"\n\nChoose your option:\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\n";
		cin>>ch;switch(ch){
			case 1: cout<<"Enter the element: ";
					cin>>n;
					l.push_back(n);break;
			case 2: l.pop_front();break;
			case 3: l.print();break;
			case 4: exit(0);
			default: cout<<"INVALID INPUT\n\n";
		}
	}
}
int main(){
	cout<<"Choose the datatype:\n1.char\n2.int\n3.float\n4.string\n";
	int n;cin>>n;switch(n){
		case 1: call<char>();break;
		case 2: call<int>();break;
		case 3: call<float>();break;
		case 4: call<string>();break;
		default: cout<<"INVALID INPUT\n";
	}
}
