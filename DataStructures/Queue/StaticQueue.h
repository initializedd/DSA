#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <optional>

template <typename T, const size_t N>
class StaticQueue
{
private:
	T								m_array[N];
	int								m_head;
	int								m_tail;

public:
	StaticQueue()
		: m_array{}
		, m_head{ -1 }
		, m_tail{ -1 }
	{
	}

	template <typename... Args>
	StaticQueue(const Args&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) <= N)
		: m_array{}
		, m_head{-1}
		, m_tail{-1}
	{
		(push({ args }), ...);
	}

	void push(const T& data)
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
		return m_tail + 1 == N ? true : false;
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

	[[nodiscard]] size_t size() const noexcept
	{
		return m_tail + 1;
	}

	[[nodiscard]] consteval size_t capacity() const noexcept
	{
		return N;
	}

	[[nodiscard]] T& operator[](size_t index) const
	{
		return m_array[m_head + index];
	}
};

#endif // !STATIC_QUEUE_H