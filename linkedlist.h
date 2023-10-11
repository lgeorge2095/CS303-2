#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename item_Type>

//structure of nodes and types
struct Node {
    item_Type data; 
    Node* next;    
};

//class for linked list
template <typename item_Type>
class singleLinkedList {

//point to nodes and num of items
private:
    Node<item_Type>* head = nullptr; 
    Node<item_Type>* tail = nullptr; 
    int numItems = 0;               

public:
    //contents of the linked list
    void print() {
      if (numItems == 0) {
        cout << "Empty List" << endl;
        }
        else {
          Node<item_Type>* tempNode = head;
          while (tempNode != nullptr) {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
            }
          cout << endl << endl;
        }
    }

    //get input from user and return
    item_Type ask() {
      item_Type input;
      cout << "Enter an input: ";
      cin >> input;
      cout << endl;
      return input;
    }

    //constructor to int the linked list
    singleLinkedList() {
      head = nullptr;
      tail = nullptr;
      numItems = 0;
    }

    //destructor for linked list
    ~singleLinkedList() {
        while (head != nullptr) {
          Node<item_Type>* tempNode = head;
          head = head->next;
          delete tempNode;
        }
    }

    //add item to front of list
    void push_front() {
      item_Type item = ask();
      Node<item_Type>* tempNode = new Node<item_Type>;
      tempNode->data = item;
      tempNode->next = head;
      head = tempNode;
      if (tail == nullptr) {
        tail = head;
        }
      numItems++;
    }

    //add item to back of list
    void push_back() {
        item_Type item = ask();
        Node<item_Type>* tempNode = new Node<item_Type>;
        tempNode->data = item;
        tempNode->next = nullptr;
        if (numItems == 0) {
          cout << "Empty List" << endl;
        }
        else {
          tail->next = tempNode;
        }
      tail = tempNode;
      numItems++;
    }

    //remove item from front of list
    void pop_front() {
        if (numItems == 0) {
          cout << "Empty List" << endl;
        }
        else {
          Node<item_Type>* tempNode = head;
          head = head->next;
          delete tempNode;
          if (head == nullptr) {
            tail = nullptr;
            }
          numItems--;
        }
    }

    //remove item from back of list
    void pop_back() {
        if (numItems == 0) {
          cout << "Empty List" << endl;
        }
        else {
          if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
            numItems--;
            }
            else {
              Node<item_Type>* temp = head;
              while (temp->next != tail) {
                temp = temp->next;
                }
              temp->next = nullptr;
              delete tail;
              tail = temp;
              numItems--;
            }
        }
    }

    //get data from first item in list
    item_Type front() {
        if (numItems == 0) {
          cout << "Empty List" << endl;
        }
        else {
          return head->data;
        }
    }

    //get data from back item in list
    item_Type back() {
        if (numItems == 0) {
          cout << "Empty List" << endl;
        }
        else {
          return tail->data;
        }
    }

    //check if list is empty
    bool empty() {
      return numItems == 0;
    }

    //insert item at an index
    void insert(const item_Type& item, size_t indexNum) {
        if (indexNum == 0) {
          push_front();
        }
        else if (indexNum > numItems) {
          push_back();
        }
        else if (indexNum < numItems && indexNum > 0) {
          item_Type item = ask();
          Node<item_Type>* temp = head;
          for (int i = 0; i < indexNum - 1; i++) {
            temp = temp->next;
            }
          Node<item_Type>* insertNode = new Node<item_Type>;
          insertNode->data = item;
          insertNode->next = temp->next;
          temp->next = insertNode;
          numItems++;
        }
    }

    //remove item at an index
    bool remove(size_t indexNum) {
        if (indexNum >= numItems) {
          cout << "Index Out of Range" << endl;
          return false;
        }
        else {
            if (indexNum == 0) {
              pop_front();
              cout << "Index " << indexNum << " Removed" << endl;
              return true;
            }
            else {
              Node<item_Type>* temp = head;
              for (int i = 0; i < indexNum - 1; i++) {
                temp = temp->next;
                }
                Node<item_Type>* temp2 = temp->next;
                temp->next = temp2->next;
                if (temp2 == tail) {
                  tail = temp;
                }
                delete temp2;
                numItems--;
                cout << "Index: " << indexNum << " Removed" << endl;
                return true;
            }
        }
    }

    //find index of item in list
    int find(const item_Type& item) {
        Node<item_Type>* temp = head;
        int numIndex = 0;
        while (temp != nullptr) {
          if (temp->data == item) {
            cout << "Index: ";
            return numIndex;
            }
            numIndex++;
            temp = temp->next;
        }
        cout << "Input not found, List Size is ";
        return numItems;
    }
};