#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP

#include <cstdlib>
#include <type_traits>

template <typename T, const std::size_t N>
class FixedArray
{
private:
	T*				m_data;

public:
	FixedArray()
	{
		m_data = static_cast<T*>(std::malloc(sizeof(T) * N));
	}

	template <typename... Args>
	FixedArray(const Args&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) == N)
	{
		m_data = static_cast<T*>(std::malloc(sizeof(T) * N));

        std::size_t index = 0;

		(new(m_data + index++) T{ args }, ...);			
	}

	~FixedArray()
	{
		if (m_data)
			std::free(m_data);
	}

	void insert(const T& data, std::size_t index)
	{
		if (index < N)
			new(m_data + index) T{ data };
	}

	[[nodiscard]] T front() const noexcept
	{
		return *m_data;
	}

	[[nodiscard]] T back() const noexcept
	{
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

#endif // !FIXED_ARRAY_HPP