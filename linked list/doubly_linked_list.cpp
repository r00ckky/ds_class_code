#include<iostream>
using namespace std;

class doubly_linked_list{
    private:
        struct Node{
            int val;
            struct Node *prev;
            struct Node *next;
        };
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int size = 0;
    public:
        void insert(int val){
            size++;
            if(tail == NULL){
                tail = new Node;
                tail->val = val;
                tail->next = NULL;
                head = tail;
                return;
            }
            struct Node *new_node = new Node;
            new_node->val = val;
            new_node->next = head;
            new_node->prev = NULL;
            if(head!=NULL){
                head->prev = new_node;
            }
            head = new_node;
        }
        void disp(){
            struct Node* ptr = head;
            while(ptr!=NULL){
                cout<<ptr->val<<" ";
                ptr = ptr->next;
            }
        }
        void disp_inv(){
            struct Node* ptr = tail;
            while(ptr!= NULL){
                cout<<ptr->val<<" ";
                ptr = ptr->prev;
            }
        }
        int len(){
            return size;
        }
        void insert_at_place(int val, int place){
            if(place>size || head == NULL){
                cout<<"Not possible"<<endl;
                return;
            }
            struct Node *ptr_head = head;
            struct Node *ptr_tail = NULL;
            struct Node *new_node = new Node;
            while(place--){
                ptr_tail = ptr_head;
                ptr_head = ptr_head->next;
            }
            new_node->val = val;
            new_node->next = ptr_tail->next;
            new_node->prev = ptr_tail;
            ptr_tail->next = new_node;
            ptr_head->prev = new_node;
        }
        void delete_node(int place){
            if(place>size || head == NULL){
                cout<<"Not possible"<<endl;
                return;
            }
            struct Node *ptr_head = head;
            struct Node *ptr_tail = NULL;
            struct Node *temp = NULL;
            while(place--){
                ptr_tail = ptr_head;
                ptr_head = ptr_head->next;
            }
            ptr_tail->next = ptr_head->next;
            temp = ptr_head;
            ptr_head = ptr_head->next;
            ptr_head->prev = ptr_tail;
            delete temp;
        }
        void pop_tail(){
            struct Node *temp = tail;
            tail = tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp; 
        }
        void pop_head(){
            struct Node *temp = head;
            head = head->next;
            head->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
};

int main(){
    doubly_linked_list gtg;
    gtg.insert(6);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(6);
    gtg.insert_at_place(6, 5);
    gtg.disp();
    cout<<"\n"<<gtg.len()<<"\n";
    gtg.delete_node(5);
    gtg.pop_tail();
    gtg.pop_head();
    gtg.disp();
}

