#ifndef FIXED_ARRAY_HPP
#define FIXED_ARRAY_HPP

#include <cstddef>
#include <type_traits>
#include <memory>
#include <utility>

template <typename T, const std::size_t N>
class FixedArray
{
private:
	alignas(std::alignment_of<T>) std::byte			m_storage[sizeof(T) * N];

	[[nodiscard]] constexpr auto elem_ptr(const std::size_t index) noexcept -> T* 
	{
		return reinterpret_cast<T*>(&m_storage) + index;
	}

	[[nodiscard]] constexpr auto elem_ptr(const std::size_t index) const noexcept -> const T* 
	{
		return reinterpret_cast<const T*>(&m_storage) + index;
	}

public:
	consteval const FixedArray() noexcept = default;

	template <typename... Args>
	FixedArray(Args&&... args) requires((std::is_same_v<Args, T> && ...) && sizeof...(Args) == N)
	{
		std::size_t index = 0;

		(std::construct_at((elem_ptr(index++)), std::forward<Args>(args)), ...);
	}

	~FixedArray()
	{
		if constexpr (!std::is_trivially_destructible_v<T>)
		{
			for (std::size_t i = 0; i < N; ++i)
				std::destroy_at(elem_ptr(i));
		}
	}

	void insert(T&& data, std::size_t index)
	{
		if (index < N)
			std::construct_at(elem_ptr(index), std::forward<T>(data));
	}

	[[nodiscard]] constexpr auto front() noexcept -> T& 
	{ 
		return *elem_ptr(0); 
	}

	[[nodiscard]] constexpr auto front() const noexcept -> const T& 
	{ 
		return *elem_ptr(0); 
	}

	[[nodiscard]] constexpr auto back() noexcept -> T&
	{
		return *elem_ptr(N - 1);
	}

	[[nodiscard]] constexpr auto back() const noexcept -> const T&
	{
		return *elem_ptr(N - 1);
	}

	[[nodiscard]] consteval auto size() const noexcept -> const std::size_t
	{
		return N;
	}

	[[nodiscard]] constexpr T& operator[](const std::size_t index)
	{
		return *elem_ptr(index);
	}

	[[nodiscard]] constexpr T& operator[](const std::size_t index) const
	{
		return *elem_ptr(index);
	}
};

#endif // !FIXED_ARRAY_HPP