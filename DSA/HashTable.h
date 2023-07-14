#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <utility>
#include <optional>

template <typename T, typename U>
struct PairNode
{
	std::pair<T, U>			data;
	PairNode*				link;

	PairNode() : data{}, link{} {}
};

template <typename T, typename U>
class HashTable
{
private:
	std::vector<PairNode<T, U>*>			m_bucket;
	std::size_t								m_size;
	std::size_t								m_max_size;

	[[nodiscard]] int hash(const std::string& key) const noexcept
	{
		int sum = 0;

		for (int i = 0; i < key.length(); ++i)
		{
			sum += key[i];
		}

		return sum % m_max_size;
	}

	[[nodiscard]] int hash(const int key) const noexcept
	{
		return key % m_max_size;
	}

public:
	HashTable(const std::initializer_list<std::pair<T, U>>& args)
		: m_size{}
		, m_max_size{}
	{
		std::size_t size = args.size();
		m_size = size;
		m_max_size = size * 2;

		m_bucket.resize(m_max_size);

		for (auto pair : args) 
		{
			insert(pair);
		}
	}

	void insert(std::pair<T, U>& pair)
	{
		PairNode<T, U>* tmp = new PairNode<T, U>();
		tmp->data.first = pair.first;
		tmp->data.second = pair.second;

		std::size_t index = hash(pair.first);
		
		PairNode<T, U>* ptr = m_bucket[index];

		if (!ptr)
		{
			m_bucket[index] = tmp;
			return; // insert first element
		}

		// Collision
		while (ptr->link)
		{
			ptr = ptr->link;
		}
			
		ptr->link = tmp;
	}

	[[nodiscard]] std::optional<U> find(const T& key)
	{
		PairNode<T, U>* result = m_bucket[hash(key)];

		while (result && result->data.first != key)
		{
			result = result->link;
		}

		if (!result)
			return std::nullopt;

		return result->data.second;
	}

	/*bool contains(const T& key)
	{
		
	}*/

	/*void clear()
	{

	}*/

	[[nodiscard]] int size() const noexcept
	{
		return m_size;
	}

	[[nodiscard]] int max_size() const noexcept
	{
		return m_max_size;
	}
};

#endif // !HASH_TABLE_H