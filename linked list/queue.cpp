#include <iostream>
using namespace std;

class Linked_queue{
   private:
         struct node {
            int data;
            struct node *next;
         };
         struct node* front = NULL;
         struct node* rear = NULL;
         struct node* temp;
         int size = 0;
   public:
         void push(int val) {
            size++;
            if (rear == NULL) {
               rear = new node;
               rear->next = NULL;
               rear->data = val;
               front = rear;
            } else {
               temp = new node;
               rear->next = temp;
               temp->data = val;
               temp->next = NULL;
               rear = temp;
            }
         }
         void pop() {
            temp = front;
            size--;
            if (front == NULL) {
               cout<<"Underflow"<<endl;
               return;
            }
            else
            if (temp->next != NULL) {
               temp = temp->next;
               free(front);
               front = temp;
            } else {
               free(front);
               front = NULL;
               rear = NULL;
            }
         }
         void disp() {
            temp = front;
            if ((front == NULL) && (rear == NULL)) {
               cout<<"Empty"<<endl;
               return;
            }
            while (temp != NULL) {
               cout<<temp->data<<" ";
               temp = temp->next;
            }
            cout<<'\n';
         }
         int len(){
            return size;
         }
};

int main(){
    Linked_queue gtg;
    gtg.push(9);
    gtg.push(9);
    gtg.push(6);
    gtg.push(0);
    gtg.push(8);
    gtg.push(7);
    gtg.push(5);
    gtg.push(4);
    gtg.disp();
    gtg.pop();
    gtg.pop();
    gtg.disp();
    cout<<gtg.len();
}  