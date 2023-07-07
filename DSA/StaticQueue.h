#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <optional>

template <typename T, std::size_t Size>
class StaticQueue
{
private:
	T								m_array[Size];
	int								m_head;
	int								m_tail;
	const int						m_capacity;

public:
	StaticQueue()
		: m_array{}
		, m_head{ -1 }
		, m_tail{ -1 }
		, m_capacity{ Size }
	{
	}

	void push(T data)
	{
		if (full())
			return;

		if (empty())
		{
			++m_head, ++m_tail;
			m_array[m_head] = data;
			return; // push first element
		}

		++m_tail;
		m_array[m_tail] = data;
	}

	void pop() noexcept
	{
		if (empty())
			return;

		if (m_head == m_tail)
		{
			m_head = -1, m_tail = -1;
			return; // pop last element
		}

		++m_head;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_head == -1 ? true : false;
	}

	[[nodiscard]] bool full() const noexcept
	{
		return m_tail + 1 == m_capacity ? true : false;
	}

	[[nodiscard]] std::optional<T> front() const noexcept
	{
		if (m_head == -1)
			return std::nullopt;

		return m_array[m_head];
	}

	[[nodiscard]] std::optional<T> back() const noexcept
	{
		if (m_tail == -1)
			return std::nullopt;

		return m_array[m_tail];
	}

	void clear()
	{
		while (!empty())
			pop();
	}

	[[nodiscard]] int size() const noexcept
	{
		return m_tail + 1;
	}

	[[nodiscard]] int capacity() const noexcept
	{
		return m_capacity;
	}

	[[nodiscard]] T operator[](std::size_t index) const
	{
		return m_array[m_head + index];
	}
};

#endif // !STATIC_QUEUE_H