#ifndef STATIC_STACK_HPP
#define STATIC_STACK_HPP

#include <cstddef>
#include <type_traits>
#include <optional>
#include <utility>

template <typename T, const std::size_t N>
class StaticStack
{
private:
	T								m_array[N];
	std::int64_t					m_top;

public:
	StaticStack()
		: m_array{}
		, m_top{ -1 }
	{
	}

	template <typename... Args>
	StaticStack(Args&&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) <= N)
		: m_array{}
		, m_top{-1}
	{
		(push(std::forward<Args>(args)), ...);
	}

	void push(T&& data)
	{
		if (!full())
		{
			++m_top;
			m_array[m_top] = data;
		}
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
		return m_top + 1 == N ? true : false;
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

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_top + 1;
	}

	[[nodiscard]] consteval std::size_t capacity() const noexcept
	{
		return N;
	}

	[[nodiscard]] T operator[](std::size_t index) const
	{
		return m_array[index];
	}
};

#endif // !STATIC_STACK_HPP