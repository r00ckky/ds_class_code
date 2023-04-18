#include <iostream>
using namespace std;


class BST{
    private:
        struct Node{
            int val;
            Node* left;
            Node* right;
            Node(int val){
                this->val = val;
                left = nullptr;
                right = nullptr;
            }
        };
        Node* root;
        Node* insert(Node* root, int data){
            if (root == nullptr){
                return new Node(data);
            }
            if (data < root->val){
                root->left = insert(root->left, data);
            } else if (data > root->val){
                root->right = insert(root->right, data);
            }
            return root;
        }
        bool search(Node* root, int data){
            if (root == nullptr){
                return false;
            }
            if (root->val == data){
                return true;
            } 
            else if (data < root->val){
                return search(root->left, data);
            } 
            else{
                return search(root->right, data);
            }
        }
        void inorder(Node* root) {
            if (root == nullptr) {
                return;
            }
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
        Node* remove(Node* root, int data){
            if (root == nullptr){
                return root;
            }
            if (data < root->val){
                root->left = remove(root->left, data);
            } else if (data > root->val){
                root->right = remove(root->right, data);
            } else {
                if (root->left == nullptr){
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if (root->right == nullptr){
                    Node* temp = root->left;
                    delete root;
                    return temp;
                } 
                else{
                    Node* temp = find_min(root->right);
                    root->val = temp->val;
                    root->right = remove(root->right, temp->val);
                }
            }
            return root;
        }
         Node* find_min(Node* root){
            while (root->left != nullptr) root = root->left;
            return root;
        }
    public:
        BST(){
            root = nullptr;
        }
        void insert(int val){
            root = insert(root, val);
        }
        bool search(int val){
            return search(root, val);
        }
        void inorder(){
            inorder(root);
        }
};

int main() {
    BST gtg;
    gtg.insert(50);
    gtg.insert(30);
    gtg.insert(20);
    gtg.insert(40);
    gtg.insert(70);
    gtg.insert(60);
    gtg.insert(80);
    cout << "Inorder traversal: ";
    gtg.inorder();
    cout << endl;
    cout << "Searching for 60: ";
    if (gtg.search(60)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found." << endl;
    }
    cout << "Searching for 90: ";
    if (gtg.search(90)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found." << endl;
    }
    return 0;
}