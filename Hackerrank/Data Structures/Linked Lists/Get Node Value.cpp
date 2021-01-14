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

// Complete the getNode function below.
// Let Array be  1 2 3 4 5 and positionFromTail is 2.
// C as current f as follower.
// 0 1 2 3 4 5
// C
// 0 1 2 3 4 5
//   C
// 0 1 2 3 4 5
//     C
// 0 1 2 3 4 5
// f     C
// 0 1 2 3 4 5
//   f     C
// 0 1 2 3 4 5
//     f     C
// 0 1 2 3 4 5
//       f     C Loop is ended because C is NULL now
int getNode(SinglyLinkedListNode *head, int positionFromTail) {
  SinglyLinkedListNode *cur = head, *ret = head;
  // ret is actually n_previous value
  for (int i{0}; head; i++, head = head->next)
    if (i > positionFromTail)
      ret = ret->next;
  return ret->data;
}
int getNodeNaive(SinglyLinkedListNode *head, int positionFromTail) {
  SinglyLinkedListNode *temp = head;
  int size = 0;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }

  std::cout << size << std::endl;

  temp = head;
  if (positionFromTail == 1)
    return temp->data;
  for (int i = 0; size - positionFromTail - 1; i++) {
    temp = temp->next;
  }
  return temp->data;
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

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = getNode(llist->head, position);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}
