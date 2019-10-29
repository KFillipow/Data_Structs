#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
}

class Tree{
    private:
        Node* root;
    public:
        Tree(){root = NULL;}
        void AddLeftNode(int d){
            Node* new_node = new Node;
            new_node->data = d;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root == NULL)
                root = new_node;
            else{
                Node* tmp = root;
                while(tmp->left != NULL)
                    tmp = tmp->left;
                tmp->left = new_node;
            }
        }
        void AddRightNode(int d){
            Node* new_node = new Node;
            new_node->data = d;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root == NULL)
                root = new_node;
            else{
                Node* tmp = root;
                while(tmp->right != NULL)
                    tmp = tmp->right;
                tmp->right = new_node;
            }
        }
};

int main(){
    int data;
    Tree tree;
    std::cout << "First node is 5\n";
    tree.AddLeftNode(5);
    std::cout << "First left node is 3\n";
    tree.AddLeftNode(3);
    std::cout << "First right node is 10\n";
    tree.AddLeftNode(3);
}