#ifndef STACK_H
#define STACK_H

#include "List.hpp"
#include <stdexcept>

template <class T>
class Stack
{
private:
	// To be filled by student (ad)
	List<T> l;
public:
	Stack();
	virtual ~Stack() = default;
	Stack(const Stack& other) = delete;
	Stack& operator=(const Stack& other) = delete;
	
	void push(const T& element);
	T pop();
	T peek() const;
	bool is_empty() const;
	int size() const;
};

template <class T>
Stack<T>::Stack()
	: l()
{

}

template <class T>
void Stack<T>::push(const T& element)
{
	l.insertFirst(element);
}

template <class T>
T Stack<T>::pop()
{
	if (l.is_empty()) throw std::exception("Wrong");

	return l.removeFirst();
}

template <class T>
T Stack<T>::peek() const
{
	if (l.is_empty()) throw std::exception("Wrong");

	return l.getFirst();
}

template <class T>
bool Stack<T>::is_empty() const
{
	return l.is_empty();
}

template <class T>
int Stack<T>::size() const
{
	return l.size();
}

#endif