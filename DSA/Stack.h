#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <optional>

template <typename T, std::size_t Size>
class StaticStack
{
private:
	T								m_array[Size];
	int								m_top;
	const int						m_capacity;

public:
	StaticStack()
		: m_array{}
		, m_top{ -1 }
		, m_capacity{ Size }
	{
	}

	void push(T data)
	{
		++m_top;

		if (m_top < m_capacity)
			m_array[m_top] = data;
		else
			--m_top; // stack is already full
	}

	void pop() noexcept
	{
		if (m_top >= 0)
			--m_top;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_top >= 0 ? false : true;
	}

	[[nodiscard]] std::optional<T> top() const noexcept
	{
		if (m_top <= -1)
			return std::nullopt;

		return m_array[m_top];
	}

	void clear()
	{
		while (m_top >= 0)
			pop();
	}

	[[nodiscard]] int size() const noexcept
	{
		return m_top + 1;
	}

	[[nodiscard]] int capacity() const noexcept
	{
		return m_capacity;
	}
};

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
			return; // stack is empty
		}

		m_top = ptr;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size > 0 ? false : true;
	}

	[[nodiscard]] std::optional<T> top() const noexcept
	{
		if (!m_top)
			return std::nullopt;

		return m_top->data;
	}

	void clear()
	{
		while (m_size > 0)
			pop();
	}

	[[nodiscard]] int size() const noexcept
	{
		return m_size;
	}
};

#endif // !STACK_H