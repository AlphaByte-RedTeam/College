#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

struct Node {
	char data[100];
	Node *next;
	Node *prev;
};

Node *head = NULL, *tail = NULL;

void insertNode(char data[100]) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (head == NULL) {
		cout << "[==Membuat Head Baru==]\n";
		head = newNode;
		tail = newNode;
	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void printNode(Node *node) {
	cout << "[" << node->data << "] --> Ptr Address " << node << " --> Next Ptr Address " << node->next << "\n";
}

void printForward() {
	Node *ptr = head;
	
	cout << "Print Forward:\n";
	if (head == NULL) cout << "!--Kosong--!\n";
	else {
		while (ptr != NULL) {
			printNode(ptr);
			ptr = ptr->next;
		}
	}
}

void printBackward() {
	Node *ptr = tail;
	
	cout << "Print Backward:\n";
	if (tail == NULL) {cout << "!--Kosong--!\n";}
	else {
		while (ptr != NULL) {
			printNode(ptr);
			ptr = ptr->prev;
		}
	}
}

void printLinkedList() {
	printForward();
	cout << "\n";
	printBackward();
}

int main() {
	cout << "Entry Serial Data" << "\n";
	
	char input[100];
	int count = 1;
	
	do {
		cout << "Input Data " << count << ": ";
		gets(input);
		
		if (strlen(input) > 0) {
			insertNode(input);
			count++;
		}
	} while(strlen(input) > 0);
	
	cout << "\nTotal Data: " << (count - 1) << "\n";
	
	printLinkedList();
	return 0;
}

