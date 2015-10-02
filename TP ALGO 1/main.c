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
void doubleChain_remove(int value, Node* watcher);

// Print all the values in the doubleChainedList whith the first element watcher
void doubleChain_print(Node* watcher);

// Destroys an element
//  PARAMETERS :
//	theNode The node that has to be cleansed by the fire
void doubleChain_purgeNode(Node* theNode);

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
	}while(currentNode->value < value && currentNode != watcher);

	Node *prevNode = currentNode->prev;
	prevNode->next = newNode(value,prevNode,currentNode);
	currentNode->prev = prevNode->next;
}

void doubleChain_print(Node* watcher){
	Node* currentNode = watcher;

	do{
		currentNode = currentNode->next;
		if(currentNode == watcher){ //Avoid printing the watcher
			break;
		}
		printf("%i\n", currentNode->value);
	}while(currentNode != watcher);

	printf("\n");
}

void doubleChain_remove(int value, Node* watcher){
	Node *currentNode = watcher;

	do{ //Go throught the list until value is found
		currentNode = currentNode->next;
		if (currentNode->value == value){
			doubleChain_purgeNode(currentNode);
			break;	
		}
	}while(currentNode->value < value && currentNode != watcher);
}

void doubleChain_purgeNode(Node* theNode){
	//if(theNode->prev->next != NULL) 
		theNode->prev->next = theNode->next;
	//if(theNode->next->prev != NULL)
		theNode->next->prev = theNode->prev;
	free(theNode);
}

int main(void){
	Node* watch = newWatcher();
	doubleChain_insert(5,watch);
	doubleChain_insert(10,watch);
	doubleChain_insert(55,watch);
	doubleChain_insert(55,watch);
	doubleChain_insert(20,watch);

	doubleChain_print(watch);

	doubleChain_remove(55,watch);
	doubleChain_insert(66,watch);

	doubleChain_print(watch);
	return 0;
}