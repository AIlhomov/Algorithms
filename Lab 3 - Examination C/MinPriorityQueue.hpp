#ifndef MINPRIORITYQUEUEHEAP_HPP
#define MINPRIORITYQUEUEHEAP_HPP
#include <stdexcept>

template <typename T>
class MinPriorityQueue {
private:
    int capacity;
    int nrOfElements;
    T* elements;
    void expand();
    void percolateUp(int index);
    void percolateDown(int index);
public:
    MinPriorityQueue();
    ~MinPriorityQueue() = default;
    MinPriorityQueue(const MinPriorityQueue& other) = delete;
    MinPriorityQueue& operator =(const MinPriorityQueue& other) = delete;

    int size() const;
    void enqueue(const T& element);
    T dequeue();
    T peek() const;
    bool is_empty() const;
};

#endif

template<typename T>
inline void MinPriorityQueue<T>::expand()
{
    this->capacity *= 2;
    T* temp = new T[this->capacity];
    for (int i = 0; i < this->nrOfElements; ++i)
        temp[i] = this->elements[i];
    delete[] this->elements;
    this->elements = temp;
}

template<typename T>
inline void MinPriorityQueue<T>::percolateUp(int index)
{
    if (index > 0) {
        int parent = (index - 1) / 2;
        if (elements[index] < elements[parent]) {
            std::swap(elements[index], elements[parent]);
            percolateUp(parent);
        }
    }
}

template<typename T>
inline void MinPriorityQueue<T>::percolateDown(int index)
{
    int l_child = 2 * index + 1;
    if (l_child >= this->nrOfElements) {
        return;
    }

    int r_child = l_child + 1;
    int best_child = l_child;
    if (r_child < this->nrOfElements && elements[r_child] < elements[l_child]) {
        best_child = r_child;
    }

    if (elements[best_child] < elements[index]) {
        std::swap(elements[best_child], elements[index]);
        percolateDown(best_child);
    }
}


template <class T>
MinPriorityQueue<T>::MinPriorityQueue()
{
    this->capacity = 10;
    this->nrOfElements = 0;
    this->elements = new T[this->capacity];
}

template <class T>
int MinPriorityQueue<T>::size() const {
    return this->nrOfElements;
}

template <class T>
void MinPriorityQueue<T>::enqueue(const T& element) {
    if (this->nrOfElements == this->capacity)
        this->expand();
    int index = this->nrOfElements;
    this->elements[this->nrOfElements++] = element;
    percolateUp(index);
}

template <class T>
T MinPriorityQueue<T>::dequeue() {
    if (this->is_empty()) {
        throw std::out_of_range("calling dequeue() on empty MinPriorityQueue");
    }
    if (this->nrOfElements == 1) {
        return this->elements[--this->nrOfElements];
    }
    T temp = elements[0];
    elements[0] = this->elements[--this->nrOfElements];
    percolateDown(0);
    return temp;
}

template <class T>
T MinPriorityQueue<T>::peek() const {
    if (this->is_empty()) {
        throw std::out_of_range("calling peek() on empty MinPriorityQueue");
    }
    return elements[0];
}

template <class T>
bool MinPriorityQueue<T>::is_empty() const {
    return this->nrOfElements == 0;
}