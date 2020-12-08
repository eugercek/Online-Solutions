#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
  int data;
  SinglyLinkedListNode *next;

  SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
public:
  SinglyLinkedListNode *head;

  SinglyLinkedList() { this->head = nullptr; }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep,
                              ofstream &fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_singly_linked_list(SinglyLinkedListNode *node) {
  while (node) {
    SinglyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data) {
  SinglyLinkedListNode *temp = head;
  SinglyLinkedListNode *new_node = new SinglyLinkedListNode(data);

  if (head == NULL)
    return new_node;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = new_node;
  return head;
}

int main()
