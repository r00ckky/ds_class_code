#include<iostream>
using namespace std;

class circular_linked_list{
    private:
        struct Node{
            int val;
            struct Node *next;
        };
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int size = 0;
    public:
        void insert(int val) {
        Node* new_node = new Node;
        new_node->val = val;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
            new_node->next = head;
        }
        else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = new_node;
            new_node->next = head;
        }
    }

        void disp(){
            struct Node *ptr = head;
            cout<<ptr->val<<' ';
            ptr = ptr->next;
            while(ptr != head){
                cout<<ptr->val<<' ';
                ptr = ptr->next;
            }
            cout<<'\n';
        }
        int len(){
            return size;
        }
        void insert_at_place(int val, int place){
            struct Node *ptr = head;
            struct Node *ptr_tail = head;
            while(place-- > 0){
                ptr_tail = ptr;
                ptr = ptr->next;
            }
            struct Node *new_node = new Node;
            new_node->val = val;
            new_node->next = ptr;
            ptr_tail->next = new_node;
            size++;
        }
        void delete_node(int place){
            struct Node *ptr_head = head;
            struct Node *ptr_tail = NULL;
            while(place-- > 0){
                ptr_tail = ptr_head;
                ptr_head = ptr_head->next;
            }
            if (ptr_head == head) {
                head = head->next;
                tail->next = head;
            } else {
                ptr_tail->next = ptr_head->next;
            }
            size--;
            delete ptr_head;
        }
};

int main(){
    circular_linked_list gtg;
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert(9);
    gtg.insert_at_place(6, 2);
    gtg.disp();
    gtg.delete_node(2);
    gtg.disp();
    return 0;
}