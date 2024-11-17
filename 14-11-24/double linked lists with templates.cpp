#include <iostream>

// Node structure for doubly linked list
template <typename T>
struct Node {
    T data;           // The data for the node
    Node* next;       // Pointer to the next node
    Node* prev;       // Pointer to the previous node

    // Constructor to initialize a new node
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;    // Pointer to the first node
    Node<T>* tail;    // Pointer to the last node
    int size;         // Number of elements in the list

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Insert element at the end
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        size++;
    }

    // Insert element at the front
    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            head = tail = newNode;
        }
        size++;
    }

    // Remove element from the front
    void pop_front() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Remove element from the end
    void pop_back() {
        if (tail) {
            Node<T>* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // Access front element
    T& front() {
        if (head) {
            return head->data;
        }
        throw std::out_of_range("List is empty");
    }

    // Access back element
    T& back() {
        if (tail) {
            return tail->data;
        }
        throw std::out_of_range("List is empty");
    }

    // Check if the list is empty
    bool empty() const {
        return size == 0;
    }

    // Get the size of the list
    int get_size() const {
        return size;
    }

    // Print the list from front to back
    void print_forward() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Print the list from back to front
    void print_backward() const {
        Node<T>* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Clear the list
    void clear() {
        while (head) {
            pop_front();
        }
    }
};

// Main function to demonstrate the usage of DoublyLinkedList
int main() {
    // Create a doubly linked list of integers
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    std::cout << "List (front to back): ";
    list.print_forward();  // 5 10 20 30

    std::cout << "List (back to front): ";
    list.print_backward(); // 30 20 10 5

    std::cout << "Front element: " << list.front() << std::endl;  // 5
    std::cout << "Back element: " << list.back() << std::endl;    // 30

    list.pop_front();
    list.pop_back();

    std::cout << "List after pop operations (front to back): ";
    list.print_forward();  // 10 20

    std::cout << "Size of the list: " << list.get_size() << std::endl;  // 2

    // Clear the list
    list.clear();
    std::cout << "List after clearing: ";
    list.print_forward();  // (empty list)

    return 0;
}
