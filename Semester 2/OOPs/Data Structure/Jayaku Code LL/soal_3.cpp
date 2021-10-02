#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node {
	char data[100];
	Node *next;	
};

Node *head = NULL, *tail = NULL;

void insertNode(char data[100]) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	if (head == NULL) {
		cout << "[==Membuat Head Baru==]\n";
		head = newNode;
		tail = newNode;	
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

void insertBefore(char find[100], char data[100]) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	if (strcmp(head->data, find) == 0) {
		newNode->next = head;
		head = newNode;
	} else {
		Node *ptr = head->next;
		Node *preptr = head;
		while (strcmp(ptr->data, find) != 0) {
			ptr = ptr->next;
			preptr = preptr->next;
		}
		
		preptr->next = newNode;
		newNode->next = ptr;
	}
}

void printNode(Node *node) {
	cout << "[" << node->data << "] --> Ptr Address " << node << " --> Next Ptr Address " << node->next << "\n";
}

void printLinkedList() {
	Node *ptr = head;
	
	cout << "\nList Data:\n";
	while (ptr != NULL) {
		printNode(ptr);
		ptr = ptr->next;
	}
	cout << "\n";
}

Node *searchNode(char find[100]) {
  Node *ptr = head;
  
  while (strcmp(ptr->data, find) != 0) {
	ptr = ptr->next;
	if (ptr == NULL) {
		return NULL;
	}
  }

  return ptr;
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
	
	cout << "\nTotal Data: " << (count - 1) << "\n\n";
	
	printLinkedList();
	
	char find[100], newInput[100];
	
	do {
		cout << "Data yang anda cari: "; 
		gets(find);
		
		if (strlen(find) > 0) {
			Node *findNode = searchNode(find);
			if (findNode == NULL) {
				cout << "Data tidak ditemukan!\n";
			} else {
				cout << "Data " << findNode->data << " ada pada alamat " << findNode << "\n";
				
				cout << "Data yang disisipkan: ";
				gets(newInput);
				
				insertBefore(find, newInput);
				
				printLinkedList();
			}
		}
	} while(strlen(find) > 0);
	
	return 0;
}

