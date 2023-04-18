#include<iostream>
using namespace std;

class Linked_stack{
    private:
        struct Node{
            int data;
            struct Node *next;
        };
        struct Node* top = NULL;
    public:
        void push(int val){
            struct Node* newnode = new Node;
            newnode->data = val;
            newnode->next = top;
            top = newnode;
        }
        void pop(){
            if(top==NULL){
                cout<<"Stack Underflow\n";
            }
            else{
                top = top->next;
            }
        }
        void display(){
            struct Node* ptr;
            if(top==NULL)cout<<"Stack is empty";
            else{
                ptr = top;
                while(ptr != NULL){
                    cout<< ptr->data<<" ";
                    ptr = ptr->next;
                }
            }
            cout<<"\n";
        }
};

int main(){
    Linked_stack gtg;
    int ch, val;
    bool exit = true;
    cout<<"Enter choice\n1->Push\n2->pop\n3->disp\n4->exit ";
    while(exit){
        cin>>ch;
        switch(ch) {
            case 1: {
               cout<<"Enter value to be pushed:"<<endl;
               cin>>val;
               gtg.push(val);
               break;
            }
            case 2: {
               gtg.pop();
               break;
            }
            case 3: {
               gtg.display();
               break;
            }
            case 4: {
               cout<<"Exit"<<endl;
               exit = false;
               break;
            }
            default: {
               cout<<"Invalid Choice"<<endl;
            }
        }
    }
    return 0;
}    