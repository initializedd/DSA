#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "Node.h"
#include <optional>

template <typename T>
class DynamicStack
{
private:
	Node<T>*						m_top;
	int								m_size;

public:
	DynamicStack()
		: m_top{}
		, m_size{}
	{
	}

	~DynamicStack()
	{
		clear();
	}

	void push(T data)
	{
		Node<T>* tmp = new Node<T>();
		tmp->data = data;

		if (m_top)
			tmp->link = m_top;

		m_top = tmp;
		++m_size;
	}

	void pop()
	{
		if (!m_top)
			return; // no elements

		Node<T>* ptr = m_top->link;

		delete m_top;
		--m_size;

		if (!ptr)
		{
			m_top = nullptr;
			return; // final element destroyed
		}

		m_top = ptr;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size == 0 ? true : false;
	}

	[[nodiscard]] std::optional<T> top() const noexcept
	{
		if (!m_top)
			return std::nullopt;

		return m_top->data;
	}

	void clear()
	{
		while (!empty())
			pop();
	}

	[[nodiscard]] int size() const noexcept
	{
		return m_size;
	}
};

#endif // !DYNAMIC_STACK_H