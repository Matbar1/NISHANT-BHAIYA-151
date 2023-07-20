// C++ implementation of above approach
#include<bits/stdc++.h>
using namespace std;

// link list node
struct LNode{
	int data;
	LNode* next;
	LNode* prev;
};

// binary tree node
struct TNode{
	int data;
	TNode* left;
	TNode* right;
	TNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// function to insert a node at
// the beginning of the doubly linked list
void push(LNode** head_ref, int new_data){
	// allocated node
	LNode* new_node = new LNode();
	
	// put in the data
	new_node->data = new_data;
	
	// since we are adding at the beginning
	// prev is always null
	new_node->prev = NULL;
	
	// link the old list of the new node
	new_node->next = (*head_ref);
	
	// changes prev of head node to new node
	if(*head_ref != NULL)
		(*head_ref)->prev = new_node;
	
	// move the head to point to the new node
	*head_ref = new_node;
}

// function to print nodes in a given linked list
void printList(LNode* node){
	while(node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
}

void preOrder(TNode* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
TNode* sortedListToBSTRecur(vector<int>& vec, int start, int end){
	if(start > end) return NULL;
	int mid = start + (end-start)/2;
	if((end - start)%2 != 0) mid = mid+1;
	TNode* root = new TNode(vec[mid]);
	root->left = sortedListToBSTRecur(vec, start, mid-1);
	root->right = sortedListToBSTRecur(vec, mid+1, end);
	return root;
}

TNode* sortedListToBST(LNode* head){
	vector<int> vec;
	LNode* temp = head;
	while(temp != NULL){
		vec.push_back(temp->data);
		temp = temp->next;
	}
	return sortedListToBSTRecur(vec, 0, vec.size()-1);
}

int main(){
	// Let us create a sorted linked list to test the functions
	// Created linked list will be 1->2->3->4->5->6->7
	LNode* head = NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	cout<<"Given Linked List: "<<endl;
	printList(head);
	cout<<endl;
	// convert list to bst
	TNode* root = sortedListToBST(head);
	cout<<"Peorder Traversal of constructed BST: "<<endl;
	preOrder(root);
	return 0;
}
// THIS CODE IS CONTRIBUTED BY YASH AGARWAL(YASHAGARWAL2852002)
