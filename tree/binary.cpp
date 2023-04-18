#include<iostream>
using namespace std;


class binary_tree {
    private:
        struct Node{
            int val;
            Node* left;
            Node* right;
            Node(int val){
                this->val = val;
                left = right = nullptr;
            }
        };
    public:
        Node* root;
        binary_tree(){
            root = nullptr;
        }
        Node* insert(Node* node, int val){
            if (node == nullptr){
                return new Node(val);
            }
            if (val < node->val){
                node->left = insert(node->left, val);
            } else {
                node->right = insert(node->right, val);
            }
            return node;
        }
        void inorderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
        void preorderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            cout << node->val << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
        void postorderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->val << " ";
        }
};

int main(){
    binary_tree gtg;
    gtg.root = gtg.insert(gtg.root, 5);
    gtg.root = gtg.insert(gtg.root, 3);
    gtg.root = gtg.insert(gtg.root, 7);
    gtg.root = gtg.insert(gtg.root, 1);
    gtg.root = gtg.insert(gtg.root, 4);
    gtg.root = gtg.insert(gtg.root, 6);
    gtg.root = gtg.insert(gtg.root, 8);

    cout << "Inorder traversal: ";
    gtg.inorderTraversal(gtg.root);
    cout << endl;

    cout << "Preorder traversal: ";
    gtg.preorderTraversal(gtg.root);
    cout << endl;

    cout << "Postorder traversal: ";
    gtg.postorderTraversal(gtg.root);
    cout << endl;

    return 0;
}