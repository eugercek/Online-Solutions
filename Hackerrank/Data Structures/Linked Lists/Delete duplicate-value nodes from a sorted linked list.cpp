#include <bits/stdc++.h>
#include <iostream>

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
  SinglyLinkedListNode *tail;

  SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
    }

    this->tail = node;
  }
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

void print_mine(SinglyLinkedListNode *tmp) {
  while (tmp) {
    cout << tmp->data << ' ';
    tmp = tmp->next;
  }
  cout << endl;
}
// Complete the removeDuplicates function below.
// In this i understood that don't hink memory(heap) in first solution
// First solve problem then start to use delete
SinglyLinkedListNode *removeDuplicates(SinglyLinkedListNode *head) {
  SinglyLinkedListNode *cur = head;
  if (!head)
    return head;
  while (cur->next) {
    if (cur->data == cur->next->data) {
      SinglyLinkedListNode *temp = cur->next;
      cur->next = cur->next->next;
      delete temp;
    } else
      cur = cur->next;
  }
  return head;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    SinglyLinkedList *llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    SinglyLinkedListNode *llist1 = removeDuplicates(llist->head);

    print_singly_linked_list(llist1, " ", fout);
    fout << "\n";

    std::cout << "end" << std::endl;
    free_singly_linked_list(llist1);
  }

  fout.close();

  return 0;
}
