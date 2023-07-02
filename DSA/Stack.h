#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <optional>

template <typename T>
class Stack
{
private:
	Node<T>*						m_top;
	int								m_size;

public:
	Stack();
	~Stack();

	void push(T data);
	void pop();

	bool empty();

	std::optional<T> top();

	void clear();

	int size();
};

template <typename T>
Stack<T>::Stack()
	: m_top{}
	, m_size{}
{
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}

template <typename T>
void Stack<T>::push(T data)
{
	Node<T>* tmp = new Node<T>();
	tmp->data = data;

	if (m_top)
		tmp->link = m_top;

	m_top = tmp;
	++m_size;
}

template <typename T>
void Stack<T>::pop()
{
	if (!m_top)
		return; // no elements

	Node<T>* ptr = m_top->link;

	delete m_top;
	--m_size;

	if (!ptr)
	{
		m_top = nullptr;
		return; // stack is empty
	}

	m_top = ptr;
}

template <typename T>
bool Stack<T>::empty()
{
	return m_size > 0 ? false : true;
}

template <typename T>
std::optional<T> Stack<T>::top()
{
	if (!m_top)
		return std::nullopt;

	return m_top->data;
}

template <typename T>
void Stack<T>::clear()
{
	while (m_size > 0)
		pop();
}

template <typename T>
int Stack<T>::size()
{
	return m_size;
}

#endif // !STACK_H