#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include "../Node/Node.h"
#include <optional>

template <typename T>
class DynamicQueue
{
private:
	Node<T>*						m_head;
	Node<T>*						m_tail;
    std::size_t						m_size;

public:
	DynamicQueue()
		: m_head{}
		, m_tail{}
		, m_size{}
	{
	}

	template <typename... Args>
	DynamicQueue(const Args&... args) requires(std::is_same_v<Args, T> && ...)
		: m_head{}
		, m_tail{}
		, m_size{}
	{
		(push({ args }), ...);
	}

	~DynamicQueue()
	{
		clear();
	}

	void push(const T& data)
	{
		Node<T>* tmp = new Node<T>();
		tmp->data = data;

		++m_size;

		if (!m_head)
		{
			m_head = tmp;
			m_tail = tmp;
			return; // first element created
		}

		Node<T>* ptr = m_head;

		while (ptr->link)
		{
			ptr = ptr->link;
		}

		ptr->link = tmp;
		m_tail = tmp;
	}

	void pop()
	{
		if (m_size == 0 || !m_head)
			return; // no elements

		--m_size;

		if (m_head == m_tail)
		{
			delete m_head;
			m_head = nullptr;
			m_tail = nullptr;
			return; // final element destroyed
		}

		Node<T>* ptr = new Node<T>();
		ptr = m_head->link;

		delete m_head;
		m_head = ptr;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size == 0 ? true : false;
	}

	[[nodiscard]] std::optional<T> front() const noexcept
	{
		if (!m_head)
			return std::nullopt;

		return m_head->data;
	}

	[[nodiscard]] std::optional<T> back() const noexcept
	{
		if (!m_tail)
			return std::nullopt;

		return m_tail->data;
	}

	void clear()
	{
		while (!empty())
			pop();
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}
};

#endif // !DYNAMIC_QUEUE_H
