//Make class for linked List
//Append to list
//Add to front
//Display list
//Delete end
//Delete front

#include <iostream>

struct Node{
	int data;
	struct Node* next;
};

class LinkedList{
	private:
		Node* head;
		Node* tail;
	public:
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		void CreateNode(int d){
			Node* tmp = new Node;
			tmp->data = d;
			tmp->next = NULL;
			//if head is NULL, append to end
			if(head == NULL){
				head = tmp;
				tail = tmp;
			}
			else{
				//Append to the back
				tail->next = tmp;
				tail = tail->next;
			}
		}
		void DisplayList(){
			Node* tmp = head;
			while(tmp != NULL){
				std::cout << "Data: " << tmp->data << std::endl;
				tmp=tmp->next;
			}
		}
		void AddToFront(int d){
			//make new node
			Node* tmp = new Node;
			tmp->data = d;
			tmp->next = head;
			head = tmp;
		}
		void DeleteTail(){			
			Node* tmp = head;
			while(tmp->next->next != NULL){
				tmp=tmp->next;
			}
			delete tmp->next;
			tmp->next = NULL;
		}
		void DeleteHead(){
			Node* tmp = head->next;
			delete head; 
			head = tmp;
		}
		void DeleteNode(int n){
			//Go to node before desired deleted node
			//store pointer to node after delete node
			//delete node
			Node* tmp = head;
			//run up to the node before the specified node
			for(int i=0;i<n;i++){
				tmp = tmp->next;
			}
			//set next of the node before delete node to next of the node to be deleted
			Node* temp_next = tmp->next->next;
			delete tmp->next;
			tmp->next = temp_next;
		}
		void InsertAfterNode(int n, int d){
			//run to specified node
			Node* tmp = head;
			//run up to the node before the specified node
			for(int i=0;i<n;i++){
				tmp = tmp->next;
			}
			//make the new node
			Node* new_node = new Node;
			new_node->data = d;
			new_node->next = tmp->next;//point to 
			tmp->next = new_node;
		}
		void InsertBeforeNode(int n, int d){
			//run to node before the specified node
			//run to specified node
			Node* tmp = head;
			//run up to the node before the specified node
			for(int i=0;i<n-1;i++){
				tmp = tmp->next;
			}
			//make the new node
			Node* new_node = new Node;
			new_node->data = d;
			new_node->next = tmp->next;//point to 
			tmp->next = new_node;
		}
	
};


int main(){
	unsigned int size = 0;
	std::cout << "Enter size of linked list\n";
	std::cin >> size;
	LinkedList LL;
	for(int i=0;i<size;i++){
		int data;
		std::cout << "Enter node data\n";
		std::cin >> data;
		LL.CreateNode(data);
	}
	LL.DisplayList();
	LL.DeleteTail();
	std::cout <<" Deleting tail\n";
	LL.DisplayList();
	LL.DeleteHead();
	std::cout << "Deleting head\n";
	LL.DisplayList();
	std::cout << "Deleting position 2\n";
	LL.DeleteNode(1);
	LL.DisplayList();
	std::cout << "Inserting after node 2\n";
	LL.InsertAfterNode(2,99);
	LL.DisplayList();
	std::cout <<"Inserting before node 2\n";
	LL.InsertBeforeNode(2,69);
	LL.DisplayList();
}
