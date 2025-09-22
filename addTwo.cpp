
#include <cmath>
#include <iostream>
namespace add_Two {
struct ListNode {
  int val;        // value at
  ListNode *next; // next value
                  /*
                  |value  |
                  |_______|
                  | next  |
                  */

  ListNode() : val(0), next(nullptr) {} // value at 0 and next is NULL
  ListNode(int x)
      : val(x), next(nullptr) {
  } // Create a node with a specific value x but no next node yet.
  ListNode(int x, ListNode *next)
      : val(x), next(next) {
  } // Create a node with a value x and immediately link it to another node.
};

void addToPointer(int temp[], add_Two::ListNode *list, int size);
std::ostream &operator<<(std::ostream &os, add_Two::ListNode *list);
void combine(add_Two::ListNode *one, add_Two::ListNode *two);

} // namespace add_Two

int main() {
  add_Two::ListNode *practice = new add_Two::ListNode;
  add_Two::ListNode *practiceTwo = new add_Two::ListNode;
  int list[3] = {2, 4, 3};
  int size = 3;

  int listTwo[3] = {5, 6, 4};
  int sizes = 3;

  add_Two::addToPointer(list, practice, size);
  add_Two::addToPointer(listTwo, practiceTwo, sizes);
  // std::cout << practice;
  // std::cout << practiceTwo;

  combine(practice, practiceTwo);
}

// add items to the list
void add_Two::addToPointer(int temp[], add_Two::ListNode *list, int size) {

  list->val = temp[0];
  add_Two::ListNode *current = list;

  for (int i = 1; i < size; i++) {
    add_Two::ListNode *here = new add_Two::ListNode(temp[i]);
    current->next = here;
    current = here;
  }
  current->next = nullptr;
}

/* the function return output of a link list
param 1 is the cout
param 2 is the link list
uses the operator overload <<
I overloaded the << operator for my linked list so that I could output the
entire list in a clean, idiomatic way. I made the first parameter ostream& os
because << always works with output streams like cout or ofstream. By passing it
as a reference using &, I avoid copying the stream — otherwise, operations would
affect a temporary copy, not the actual cout. Returning os allows chaining
multiple << calls, just like standard streams. So basically, os is an alias for
the output stream I’m writing to, and using a reference ensures I’m modifying
the real stream and not a copy
*/
std::ostream &add_Two::operator<<(std::ostream &os, add_Two::ListNode *list) {

  add_Two::ListNode *current = list;
  while (current != nullptr) {

    os << current->val << " ";

    current = current->next;
  }
  os << std::endl;
  return os;
}

// will return a link list form two link list by combiding both reverst so
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
void add_Two::combine(add_Two::ListNode *one, add_Two::ListNode *two) {

  add_Two::ListNode *a = one;
  add_Two::ListNode *b = two;
  add_Two::ListNode *total = new add_Two::ListNode;

  int temps = 0;
  int i = 0;
  bool over = true;

  while (a != nullptr || b != nullptr) {
    // add_Two::ListNode *temp = new add_Two::ListNode;

    int valueOne = 0;
    int valueTwo = 0;

    // save the value of each node or set it to 0 if no number
    if (a != nullptr) {
      valueOne = a->val;
    } else {
      valueOne = 0;
    }
    if (b != nullptr) {
      valueTwo = b->val;
    } else {
      valueTwo = 0;
    }

    over ? temps = (valueOne + valueTwo) : temps = (valueOne + valueTwo + 1);
    if (temps >= 10) {
      over = false;
      temps = temps % 10;
    } else {
      over = true;
    }

    if (i == 0) {
      add_Two::ListNode *totals = new add_Two::ListNode(temps);
      total->next = total; // set list to have that value
      total = total;       // update list to

    } else {
      add_Two::ListNode *current =
          new add_Two::ListNode(temps); // get the total
      total->next = current;            // set list to have that value
      total = current;                  // update list to

      std::cout << total;
    }
    if (a)
      a = a->next;
    if (b)
      b = b->next;
    i++;

    // test
  }
}