#include<iostream>
using namespace std;

class single_linked_list{
    private:
        struct Node{
            int data;
            struct Node *next;
        };
        struct Node *head = NULL;
        int size = 0;
    public:
        void insert(int val){  //elements are added to the front
            struct Node *new_node = new Node;
            new_node->data = val;
            new_node->next = head;
            head = new_node;
            size++;
        }
        int get_val(int val){
            struct Node *ptr=head;
            while(ptr!=NULL || ptr->data!=val){
                ptr = ptr->next;
            }
            return ptr->data;
        }
        int get_index(int val){
            struct Node *ptr=head;
            int index=0;
            while(ptr!=NULL || ptr->data!=val){
                ptr = ptr->next;
                index++;
            }
            return index;
        }
        void disp(){
            if(head == NULL){
                cout<<"The list is empty"<<endl;
                return;
            }
            struct Node *ptr;
            ptr = head;
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<"\n";
        }
        void insert_at_place(int place, int val){
            if(place>size || head == NULL){
                cout<<"The list is not big enough"<<endl;
                return;
            }
            struct Node* ptr_head = head;
            struct Node* ptr_tail = NULL;
            struct Node* new_node = new Node;
            new_node->data = val;
            while(place--){
                ptr_tail = ptr_head;
                ptr_head = ptr_head->next;
            }
            ptr_tail->next = new_node;
            new_node->next = ptr_head;
            size++;
        }

        void delete_node(int place){
            if(place>size || head == NULL){
                cout<<"The list is not big enough"<<endl;
                return;
            }
            struct Node* ptr_head = head;
            struct Node* ptr_tail = NULL;
            while(place--){
                ptr_tail = ptr_head;
                ptr_head = ptr_head->next;
            }
            if(ptr_head == head){
                head = head->next;
            }
            else{
                ptr_tail->next = ptr_head->next;
            }
            delete ptr_head;
            size--;
        }
        int length(){
            return size;
        }
};

int main(){
    single_linked_list gtg;
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.disp();
    gtg.insert_at_place(5, 6);
    gtg.disp();
    gtg.delete_node(5);
    gtg.insert(6);
    gtg.disp();
    cout<<gtg.length();
    return 0;
}
