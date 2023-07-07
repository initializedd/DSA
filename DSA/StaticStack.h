#ifndef STATIC_STACK_H
#define STATIC_STACK_H

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

		if (!full())
			m_array[m_top] = data;
		else
			--m_top; // stack is already full
	}

	void pop() noexcept
	{
		if (!empty())
			--m_top;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_top == -1 ? true : false;
	}

	[[nodiscard]] bool full() const noexcept
	{
		return m_top + 1 == m_capacity ? true : false;
	}

	[[nodiscard]] std::optional<T> top() const noexcept
	{
		if (m_top == -1)
			return std::nullopt;

		return m_array[m_top];
	}

	void clear()
	{
		while (!empty())
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

	[[nodiscard]] T operator[](std::size_t index) const
	{
		return m_array[index];
	}
};

#endif // !STATIC_STACK_H