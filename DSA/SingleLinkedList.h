#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "Node.h"
#include <optional>

template <typename T>
class SingleLinkedList
{
public:
	Node<T>*						m_head;
	int								m_size;

public:
	SingleLinkedList();
	~SingleLinkedList();

	void push_front(T data);
	void push_back(T data);

	void pop_front();
	void pop_back();

	[[nodiscard]] bool empty() const noexcept;

	[[nodiscard]] std::optional<T> front() const noexcept;

	void insert(T data, int index);
	void clear();

	[[nodiscard]] int size() const noexcept;
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
	: m_head{}
	, m_size{}
{
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	clear();
}

template <typename T>
void SingleLinkedList<T>::push_front(T data)
{
	Node<T>* tmp = new Node<T>();
	tmp->data = data;

	if (!m_head)
	{
		m_head = tmp;
		++m_size;
		return; // push first element
	}

	tmp->link = m_head;

	m_head = tmp;
	++m_size;
}

template <typename T>
void SingleLinkedList<T>::push_back(T data)
{
	Node<T>* tmp = new Node<T>();
	tmp->data = data;

	++m_size;

	if (!m_head)
	{
		m_head = tmp;
		return; // push first element
	}

	Node<T>* ptr = m_head;

	while (ptr->link)
	{
		ptr = ptr->link;
	}

	ptr->link = tmp;
}

template <typename T>
void SingleLinkedList<T>::pop_front()
{
	if (m_size == 0 || !m_head)
		return; // no elements

	if (!m_head->link)
	{
		delete m_head;
		m_head = nullptr;
		--m_size;
		return; // final element destroyed
	}

	Node<T>* ptr = m_head->link;
	m_head = ptr;
	--m_size;
}

template <typename T>
void SingleLinkedList<T>::pop_back()
{
	if (m_size == 0 || !m_head)
		return; // no elements

	--m_size;

	if (!m_head->link)
	{
		delete m_head;
		m_head = nullptr;
		return; // final element destroyed
	}

	Node<T>* previous = nullptr;
	Node<T>* current = m_head;

	while (current->link)
	{
		previous = current;
		current = current->link;
	}

	previous->link = nullptr;
	delete current;
}

template <typename T>
[[nodiscard]] bool SingleLinkedList<T>::empty() const noexcept
{
	return m_size > 0 ? false : true;
}

template <typename T>
[[nodiscard]] std::optional<T> SingleLinkedList<T>::front() const noexcept
{
	if (!m_head)
		return std::nullopt;

	return m_head->data;
}

template <typename T>
void SingleLinkedList<T>::insert(T data, int index)
{
	if (index > m_size)
		return;

	Node<T>* tmp = new Node<T>();
	tmp->data = data;

	if (index == 0)
	{
		if (m_head)
			tmp->link = m_head;

		m_head = tmp;
		return; // push element to front
	}

	Node<T>* ptr = m_head;

	while (index > 1)
	{
		ptr = ptr->link;
		--index;
	}

	tmp->link = ptr->link;

	ptr->link = tmp;
	++m_size;
}

template <typename T>
void SingleLinkedList<T>::clear()
{
	while (m_size > 0)
		pop_front();
}

template <typename T>
[[nodiscard]] int SingleLinkedList<T>::size() const noexcept
{
	return m_size;
}

#endif // !SINGLE_LINKED_LIST_H