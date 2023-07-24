export module StaticStack;
import std;

export template <typename T, const std::size_t N>
class StaticStack
{
private:
	T								m_array[N];
	int								m_top;

public:
	StaticStack()
		: m_array{}
		, m_top{ -1 }
	{
	}

	template <typename... Args>
	StaticStack(const Args&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) <= N)
		: m_array{}
		, m_top{-1}
	{
		(push({ args }), ...);
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

	[[nodiscard]] T& operator[](std::size_t index) const
	{
		return m_array[index];
	}
};