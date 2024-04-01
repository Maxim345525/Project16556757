#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node() : next(nullptr) {}
    Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}
    void append(T value) {
        if (head == nullptr) {
            head = new Node<T>(value);
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(value);
    }
    LinkedList clone() {
        LinkedList clonedList;
        Node<T>* current = head;
        while (current != nullptr) {
            clonedList.append(current->data);
            current = current->next;
        }
        return clonedList;
    }
    LinkedList operator+(const LinkedList& other) {
        LinkedList result = *this;
        Node<T>* current = other.head;
        while (current != nullptr) {
            result.append(current->data);
            current = current->next;
        }
        return result;
    }
    LinkedList operator*(const LinkedList& other) {
        LinkedList result;
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                if (current->data == otherCurrent->data) {
                    result.append(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return result;
    }
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    LinkedList<int> list2;
    list2.append(2);
    list2.append(3);
    list2.append(4);
    LinkedList<int> clonedList = list1.clone();
    LinkedList<int> concatenatedList = list1 + list2;
    LinkedList<int> commonElementsList = list1 * list2;
    cout << "Original List 1: ";
    list1.display();
    cout << "Cloned List: ";
    clonedList.display();
    cout << "Concatenated List: ";
    concatenatedList.display();
    cout << "Common Elements List: ";
    commonElementsList.display();
    return 0;
}
