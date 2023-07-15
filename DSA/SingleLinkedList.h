#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "Node.h"
#include <optional>

template <typename T>
class SingleLinkedList
{
private:
	Node<T>*						m_head;
	std::size_t						m_size;

public:
	SingleLinkedList()
		: m_head{}
		, m_size{}
	{
	}

	~SingleLinkedList()
	{
		clear();
	}

	void push_front(const T& data)
	{
		Node<T>* tmp = new Node<T>();
		tmp->data = data;

		if (!m_head)
		{
			m_head = tmp;
			++m_size;
			return; // first element created
		}

		tmp->link = m_head;

		m_head = tmp;
		++m_size;
	}

	void push_back(const T& data)
	{
		Node<T>* tmp = new Node<T>();
		tmp->data = data;

		++m_size;

		if (!m_head)
		{
			m_head = tmp;
			return; // first element created
		}

		Node<T>* ptr = m_head;

		while (ptr->link)
		{
			ptr = ptr->link;
		}

		ptr->link = tmp;
	}

	void pop_front()
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

	void pop_back()
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

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size == 0 ? true : false;
	}

	[[nodiscard]] std::optional<T> front() const noexcept
	{
		if (!m_head)
			return std::nullopt;

		return m_head->data;
	}

	void insert(const T& data, std::size_t index)
	{
		if (index > m_size)
			return; // invalid index

		Node<T>* tmp = new Node<T>();
		tmp->data = data;

		if (index == 0)
		{
			if (m_head)
				tmp->link = m_head;

			m_head = tmp;
			return; // first element created
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

	void clear()
	{
		while (!empty())
			pop_front();
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}
};

#endif // !SINGLE_LINKED_LIST_H