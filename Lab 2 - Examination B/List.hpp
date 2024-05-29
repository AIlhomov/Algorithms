#ifndef LIST_HPP
#define LIST_HPP

#include <stdexcept>

template <class T>
class List {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = nullptr) : data(data), next(nullptr) {}
    };
    Node* front;
    int num_elements;
public:
    List();
    ~List();
    List(const List& other) = delete;
    List& operator=(const List& other) = delete;
    
    int size() const;
    bool is_empty() const;
    void insertFirst(const T& element);
    void insertLast(const T& element);
    T removeFirst();
    T removeLast();
    T getFirst() const ;
    T getLast() const;
};

template<class T>
List<T>::List() : 
    front(nullptr), num_elements(0)
{
}

template <class T>
List<T>::~List()
{
    // Free allocated memory
    while (!is_empty()) removeLast();


  /*  Node* walker = front;
    while (walker != nullptr) {
        delete front;
        walker = walker->next;
        delete walker;
    }*/
}

template <class T>
int List<T>::size() const {
    // Returns size of List
    return num_elements;
}

template <class T>
bool List<T>::is_empty() const {
    // Returns if empty or not
    return num_elements == 0;
}

template <class T>
void List<T>::insertFirst(const T& element) {
    // Adds element at the beginning of the List
    Node* newElem = new Node(element);
    if (front == nullptr) {
        front = newElem;
    }
    else {
        /*Node* walker = front;

        while (walker->next != nullptr) walker = walker->next;

        newElem->next = walker->next;
        walker->next = newElem;*/

        /*newElem->next = front->next;
        front->next = newElem;*/
       
        newElem->next = front;
        front = newElem;

        /*front->next = front;
        front = newElem;*/
    }
    num_elements++;
}
template <class T>
void List<T>::insertLast(const T& element) {
    // Adds element at the end of the List

    if (front == nullptr) {
        insertFirst(element);
        return;
    }

    Node* newNode = new Node(element);
    
    Node* walker = this->front;
    while (walker->next != nullptr) walker = walker->next;

    newNode->next = walker->next;
    walker->next = newNode;
    num_elements++;
    /*newNode->next = walker;
    walker = newNode;*/
}
template <class T>
T List<T>::removeFirst() {
    // Removes first element in the List
    if (front == nullptr) throw std::exception("Wrong");

    Node* temp = front;
    T data = temp->data;
    front = temp->next;
    delete temp;
    num_elements--;

    return data;
}

template <class T>
T List<T>::removeLast() {
    // Removes last element in the List
    if (is_empty()) throw std::exception("Wrong");
    if (front->next == nullptr) return removeFirst();
    Node* walker = this->front;
    while (walker->next->next != nullptr) walker = walker->next;

    Node* temp = walker->next;
    T data = temp->data;
    walker->next = nullptr;
    delete temp;
    num_elements--;
    return data;
}

template <class T>
T List<T>::getFirst() const {
    // Returns the first element in the List
    if (front == nullptr) throw std::exception("Wrong");

    return front->data;

    /*Node* walker = this->front;

    while (walker->next != nullptr) walker = walker->next;

    return walker->next->data;*/
}

template <class T>
T List<T>::getLast() const {
    // Returns the last element in the List
    if (is_empty()) throw std::exception("Wrong");

    Node* walker = this->front;
    while (walker->next != nullptr) walker = walker->next;

    return walker->data;
}

#endif