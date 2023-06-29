#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <memory>
#include <iostream>

template <typename T>
struct Node
{
	T data;
	std::shared_ptr<Node> link;

	Node() : data{}, link{nullptr} {}
};

template <typename T>
class SingleLinkedList
{
public:
	std::shared_ptr<Node<T>>		m_head;
	int								m_size;

public:
	SingleLinkedList();

	void push_front(T data);
	void push_back(T data);

	void pop_front();
	void pop_back();

	bool empty();

	T front();

	void insert(T data, int index);
	void clear();

	int size();
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList()
	: m_head{}
	, m_size{}
{
}

template <typename T>
void SingleLinkedList<T>::push_front(T data)
{
	std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>>();
	tmp->data = data;

	if (!m_head)
	{
		m_head = tmp;
		++m_size;
		return;
	}

	tmp->link = m_head;

	m_head = tmp;
	++m_size;
}

template <typename T>
void SingleLinkedList<T>::push_back(T data)
{
	std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>>();
	tmp->data = data;

	++m_size;

	if (!m_head)
	{
		m_head = tmp;
		return;
	}

	std::shared_ptr<Node<T>> ptr = m_head;

	while (ptr->link != nullptr)
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
		m_head = nullptr;
		--m_size;
		return;
	}

	std::shared_ptr<Node<T>> ptr = m_head->link;
	m_head = nullptr;
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
		m_head = nullptr;
		return;
	}

	std::shared_ptr<Node<T>> previous = nullptr;
	std::shared_ptr<Node<T>> current = m_head;

	while (current->link != nullptr)
	{
		previous = current;
		current = current->link;
	}

	previous->link = nullptr;
	current = nullptr;
}

template <typename T>
bool SingleLinkedList<T>::empty()
{
	if (m_size > 0 || !m_head)
		return false;

	return true;
}

template <typename T>
T SingleLinkedList<T>::front()
{
	if (m_head)
		return m_head->data;
}

template <typename T>
void SingleLinkedList<T>::insert(T data, int index)
{
	if (index > m_size)
		return;

	if (index == 0)
	{
		std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>>();
		tmp->data = data;

		if (m_head)
			tmp->link = m_head->link;

		m_head = tmp;
		return;
	}

	std::shared_ptr<Node<T>> ptr = m_head;

	while (index > 1)
	{
		ptr = ptr->link;
		--index;
	}

	std::shared_ptr<Node<T>> tmp = std::make_shared<Node<T>>();
	tmp->data = data;
	tmp->link = ptr->link;

	ptr->link = tmp;
	++m_size;
}

template <typename T>
void SingleLinkedList<T>::clear()
{
	while (m_size > 0 || m_head)
	{
		pop_front();
	}
}

template <typename T>
int SingleLinkedList<T>::size()
{
	return m_size;
}

#endif // !SINGLE_LINKED_LIST_H