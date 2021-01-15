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

// Complete the reverse function below.
SinglyLinkedListNode *reverseRecursive(SinglyLinkedListNode *head) {
  if (head == NULL || head->next == NULL)
    return head;
  SinglyLinkedListNode *new_head = reverseRecursive(head->next);
  // 0->1->2 Let 1 be reverse
  // Creating 2->1
  head->next->next = head; // 1->next->next is 2 2->1
  head->next = NULL;       // 1->next points next element now it's gone.
  return new_head;
}

SinglyLinkedListNode *reverse(SinglyLinkedListNode *head) {
  SinglyLinkedListNode *cur = head, *prev = NULL, *next;
  while (cur != NULL) {
    next = cur->next; // For not losing next element
    cur->next = prev;
    prev = cur;
    cur = next; // Next element in normal linked list.
  }
  return prev;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int tests;
  cin >> tests;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
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

    SinglyLinkedListNode *llist1 = reverse(llist->head);

    print_singly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist1);
  }

  fout.close();

  return 0;
}
