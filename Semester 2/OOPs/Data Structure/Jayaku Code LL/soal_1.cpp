#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

// insert Tail
// print Linked List
// Searching

struct Node {
  char data[100];
  Node *next;
};

Node *head = NULL, *tail = NULL;

void insertTail(char *new_data) {
  // Mengalokasikan memori untuk membentuk node baru
  Node *new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->data, new_data);
  new_node->next = NULL;

  if (head == NULL) { // jika linked-list belum ada
    head = new_node;
    tail = new_node;
    cout << "[== Create Head ==]" << "\n";
  } else { // ternyata ada linked-listnya
    tail->next = new_node;
    tail = new_node;
  }
}

void searchNode(char *find) {
  Node *ptr = head;
  while (strcmp(ptr->data, find) != 0) {
	ptr = ptr->next;
    if (ptr == NULL) {
	  cout << " No Data Found\n";
	}	
  }
  cout << "Data " << ptr->data << " is found at address " << ptr << "\n";
}

void printNodeInformation(Node *node) {
  cout << "[" << node->data << "] --> Ptr Address " << node << " --> Next Ptr Address " << node->next << "\n"; 
}

void printLinkedList() {
  Node *ptr = head;
  
  cout << "Entry Data Result: \n";

  while (ptr != NULL) {
    printNodeInformation(ptr);
    ptr = ptr->next;
  }

  cout << "\n";
}

int main() {
  
  cout << "Entry Your Data!\n";
  
  char input[100];
  int count_input = 1;

  do {
    cout << "Input Data " << count_input << ": ";
    gets(input);
    if (strlen(input) > 0) {
      insertTail(input);
      count_input++;
    }
  } while(strlen(input) > 0);

  cout << "\nTotal Data: " << (count_input - 1) << "\n\n";

  printLinkedList();
  
  char find[100];
  
  do {
    cout << "Input data to find: ";
  	gets(find);
    if (strlen(find) > 0) {
      searchNode(find);
    }
  } while(strlen(find) > 0);

  return 0;  
}
