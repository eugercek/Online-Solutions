#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
public:
  int data;
  DoublyLinkedListNode *next;
  DoublyLinkedListNode *prev;

  DoublyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
public:
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    DoublyLinkedListNode *node = new DoublyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
      node->prev = this->tail;
    }

    this->tail = node;
  }
};

void print_doubly_linked_list(DoublyLinkedListNode *node, string sep,
                              ofstream &fout) {
  while (node) {
    fout << node->data;

    node = node->next;

    if (node) {
      fout << sep;
    }
  }
}

void free_doubly_linked_list(DoublyLinkedListNode *node) {
  while (node) {
    DoublyLinkedListNode *temp = node;
    node = node->next;

    free(temp);
  }
}

// Complete the reverse function below.
DoublyLinkedListNode *reverse(DoublyLinkedListNode *head) {
  while (head) {
    // List is 1 2 3 head is on 2
    DoublyLinkedListNode *after = head->next;
    head->next = head->prev; // 1<-2 3 arrow is for next. Constructed 2->1
    if (!after)              // If there is no next element
      return head;           // Then the list has reversed, return the list
    head->prev = after;      // 1 2->3 arrow is for prev. Constructed 3<-2->1
    head = after;            // head = head->next
  }
  return head;
}

DoublyLinkedListNode *reverseRecursive(DoublyLinkedListNode *head) {
  if (!head)
    return NULL;
  DoublyLinkedListNode *after = head->next;
  head->next = head->prev;
  head->prev = after;
  // If lastly reversed node was the last node, finish reversing.
  if (!head->prev)
    return head;
  // It has constant space there is no waiting recursive
  return reverseRecursive(after);
}
int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    DoublyLinkedList *llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    DoublyLinkedListNode *llist1 = reverse(llist->head);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);
  }

  fout.close();

  return 0;
}
