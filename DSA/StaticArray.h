#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <optional>

template <typename T, std::size_t N>
class StaticArray
{
private:
	T*								m_data;
	std::size_t						m_size;

public:
	template <typename... Args>
	StaticArray(Args&&... args) requires(N > 0 && sizeof...(Args) == N)
		: m_size{}
	{
		m_data = static_cast<T*>(malloc(sizeof(T) * N));

		std::size_t index = 0;

		for (const auto& arg : {args...})
		{
			new(m_data + index) T{ arg };
			
			++index;
			++m_size;
		}
	}

	~StaticArray()
	{
		if (m_data)
			free(m_data);
	}

	[[nodiscard]] std::optional<T> front() const noexcept
	{
		if (!m_data)
			return std::nullopt;

		return *m_data;
	}

	[[nodiscard]] std::optional<T> back() const noexcept
	{
		if (!m_data)
			return std::nullopt;

		return *(m_data + m_size - 1);
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}

	[[nodiscard]] T operator[](std::size_t index) const
	{
		return *(m_data + index);
	}
};

#endif // !STATIC_ARRAY_H