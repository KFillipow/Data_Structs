#include <iostream>
#include <queue>

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree{
    private:
        Node* root;
    public:
        BinaryTree(){root = NULL;}
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
        void AddNode(int d){
        	Node* tmp = root;
        	
        	Node* new_node = new Node;
        	new_node->data = d;
        	new_node->left = NULL;
            new_node->right = NULL;
            
            bool FoundNew = false;
        	if(root == NULL)
        		root = new_node;
        	else{
        		while(!FoundNew){
        			if(new_node->data < tmp->data){
        				if(tmp->left == NULL){						
        					tmp->left = new_node;
        					FoundNew = true;
						}
        				else
        					tmp = tmp->left;
        			}
					
        			else if(new_node->data > tmp->data){
        				if(tmp->right == NULL){
        					tmp->right = new_node;
        					FoundNew = true;
						}
        					
        				else
        				tmp = tmp->right;	
					}	
        			else{
        				std::cout <<"Error\n";
        				return;
					}
				
				}
			}
		}
        void DisplayTree(){
        	Node* tmp = root;
        	BreadthDisplay(tmp);
        	//print current node
        	//call PreOrder on left node
        	//call PreOrder on right node
		}
		void PreOrder(Node* node){
			if(node == NULL) return;
			std::cout << "Data: " << node->data << std::endl;
			PreOrder(node->left);
			PreOrder(node->right);
		}
        void BreadthDisplay(Node* root){
            if(root == NULL) return;
            std::queue<Node*> nodeQ;
            nodeQ.push(root);
            while(nodeQ.empty() == false){
                Node* tmp = nodeQ.front();
                std::cout << tmp->data << std::endl;
                nodeQ.pop();
                if(tmp->left != NULL)
                    nodeQ.push(tmp->left);
                if(tmp->right != NULL)
                    nodeQ.push(tmp->right);
            }

        }
};

int main(){
    int data;
    BinaryTree tree;
    std::cout << "1st node is 5\n";
    tree.AddNode(5);
    std::cout << "2nd node is 7\n";
    tree.AddNode(7);
    std::cout << "3rd node is 2\n";
    tree.AddNode(2);
    std::cout << "3rd node is 3\n";
    tree.AddNode(3);
    std::cout << "4th node is 4\n";
    tree.AddNode(4);
    std::cout << "5rd node is 9\n";
    tree.AddNode(9);
    std::cout << "6th node is 1\n";
    tree.AddNode(1);
    std::cout << "7th node is 6\n";
    tree.AddNode(6);
    std::cout << "Printing Tree PreOrder\n";
    tree.DisplayTree();
}
