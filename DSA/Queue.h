#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <optional>

template <typename T>
class Queue
{
private:
	Node<T>*						m_head;
	Node<T>*						m_tail;
	int								m_size;

public:
	Queue();
	~Queue();

	void push(T data);
	void pop();

	std::optional<T> front();
	std::optional<T> back();

	void clear();

	int size();
};

template <typename T>
Queue<T>::Queue()
	: m_head{}
	, m_tail{}
	, m_size{}
{
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <typename T>
void Queue<T>::push(T data)
{
	Node<T>* tmp = new Node<T>();
	tmp->data = data;

	++m_size;

	if (!m_head)
	{
		m_head = tmp;
		m_tail = tmp;
		return; // first element created
	}

	Node<T>* ptr = m_head;

	while (ptr->link)
	{
		ptr = ptr->link;
	}

	ptr->link = tmp;
	m_tail = tmp;
}

template <typename T>
void Queue<T>::pop()
{
	if (m_size == 0 || !m_head)
		return; // no elements

	--m_size;

	if (m_head == m_tail)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
		return; // final element destroyed
	}

	Node<T>* ptr = new Node<T>();
	ptr = m_head->link;

	delete m_head;
	m_head = ptr;
}

template <typename T>
std::optional<T> Queue<T>::front()
{
	if (!m_head)
		return std::nullopt;

	return m_head->data;
}

template <typename T>
std::optional<T> Queue<T>::back()
{
	if (!m_tail)
		return std::nullopt;

	return m_tail->data;
}

template <typename T>
void Queue<T>::clear()
{
	while (m_size > 0)
		pop();
}

template <typename T>
int Queue<T>::size()
{
	return m_size;
}

#endif // !QUEUE_H