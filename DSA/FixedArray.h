#ifndef FIXED_ARRAY_H
#define FIXED_ARRAY_H

#include <optional>

template <typename T, const std::size_t N>
class FixedArray
{
private:
	T*								m_data;

public:
	FixedArray()
	{
		m_data = static_cast<T*>(malloc(sizeof(T) * N));
	}

	template <typename... Args>
	FixedArray(const Args&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) == N)
	{
		m_data = static_cast<T*>(malloc(sizeof(T) * N));

		std::size_t index = 0;

		(new(m_data + index++) T{ args }, ...);			
	}

	~FixedArray()
	{
		if (m_data)
			free(m_data);
	}

	void insert(const T& data, std::size_t index)
	{
		if (index < N)
			new(m_data + index) T{ data };
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

		return *(m_data + N - 1);
	}

	[[nodiscard]] consteval std::size_t size() const noexcept
	{
		return N;
	}

	[[nodiscard]] T& operator[](std::size_t index) const
	{
		return *(m_data + index);
	}
};

#endif // !FIXED_ARRAY_H