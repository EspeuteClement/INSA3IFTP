//HEADER :
#include <limits.h>
#define WATCHER_DEFAULT_VALUE INT_MIN
typedef struct Node Node;
struct Node {
	int value;
	Node * prev;
	Node * next;
} ;

//Create a watcher node
Node* newWatcher();

// Create a new empty doubleChain node
Node* nullNewNode();

// Create a new doubleChain node
// PARAMETERS :
//	int value The value of the node
//	prev The node that precedes this node
//	next The node that folows this node
Node* newNode(int value,Node* prev, Node* next);

// Insert an element with the value of value in the doubleChainedList with the first element watcher
//	PARAMETERS :
//	value The value of the element to insert
//  watcher The first node of the doubleChainedList
void doubleChain_insert(int value, Node* watcher);

// Delete the first value equals to value in the doubleChainedList that has watcher as the first element
//  PARAMETERS :
//	value The value that should be deleted
//	watcher The first node of the doubleChainedList
void doubleChain_delete(int value, Node* watcher);

// Print all the values in the doubleChainedList whith the first element watcher
void doubleChain_print(const Node* watcher);

//METHODS :
#include <stdio.h>
#include <stdlib.h>

Node* newWatcher(){
	Node* watch = nullNewNode();
	watch->value = WATCHER_DEFAULT_VALUE;
	watch->prev = watch;
	watch->next = watch;
	return watch;
}

Node* nullNewNode(){
	return newNode(0,NULL,NULL);
}

Node* newNode(int value,Node* prev, Node* next){
	Node* ret = malloc(sizeof(Node));
	// TODO : Error handling
	ret->prev = prev;
	ret->next = next;
	ret->value = value;

	return ret;
}

void doubleChain_insert(int value, Node* watcher){
	Node* currentNode = watcher;

	do{
		currentNode = currentNode->next;
	}while(currentNode->value < value && currentNode != watcher)

	Node *prevNode = currentNode->prev;
	prevNode->next = newNode(value,prevNode,curentNode);
	currentNode->prev = prevNode->next;
}





int main(void){
	Node* watch = newWatcher();
	return 0;
}