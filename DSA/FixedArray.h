#ifndef FIXED_ARRAY_H
#define FIXED_ARRAY_H

#include <optional>

template <typename T, const std::size_t N>
class FixedArray
{
private:
	T*								m_data;

public:
	template <typename... Args>
	FixedArray(const Args&... args) requires(sizeof...(Args) == N)
	{
		m_data = static_cast<T*>(malloc(sizeof(T) * N));

		std::size_t index = 0;

		for (const auto& arg : {args...})
		{
			new(m_data + index) T{ arg };
			
			++index;
		}
	}

	~FixedArray()
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

		return *(m_data + N - 1);
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return N;
	}

	[[nodiscard]] T operator[](std::size_t index) const
	{
		return *(m_data + index);
	}
};

#endif // !FIXED_ARRAY_H