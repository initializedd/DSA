export module HashTable;
import Node;
import std;

export template <typename T, typename U>
class HashTable
{
private:
	std::vector<Node<std::pair<T, U>>*>		m_buckets;
    std::size_t								m_size;
    std::size_t								m_max_size;

	[[nodiscard]] std::size_t hash(const std::string& key) const noexcept
	{
		unsigned int sum = 0;

		for (const auto& ch : key)
		{
			sum += ch;
		}

		return sum % m_max_size;
	}

	[[nodiscard]] std::size_t hash(const int key) const noexcept
	{
		return key % m_max_size;
	}

	void re_hash()
	{
		std::vector<Node<std::pair<T, U>>*> old_buckets = m_buckets;

		m_buckets.clear();

		m_max_size = m_size * 2;
		m_buckets.resize(m_max_size);

		for (auto* bucket : old_buckets)
		{
			while (bucket)
			{
				Node<std::pair<T, U>>* next = bucket->link;
				bucket->link = nullptr;  // clear the link of the old bucket

                std::size_t index = hash(bucket->data.first);

				if (!m_buckets[index])
				{
					m_buckets[index] = bucket; // insert first bucket at this index
				}
				else
				{
					Node<std::pair<T, U>>* ptr = m_buckets[index];

					while (ptr->link)
					{
						ptr = ptr->link;
					}
					
					ptr->link = bucket;
				}

				bucket = next; // iterate to the next linked node
			}
		}
	}

public:
	HashTable()
		: m_size{}
		, m_max_size{ 13 }
	{
		m_buckets.resize(m_max_size);
	}

	HashTable(const std::initializer_list<std::pair<T, U>>& args)
		: m_size{}
	{
        std::size_t size = args.size();
		m_max_size = size * 2;

		m_buckets.resize(m_max_size);

		for (const auto& pair : args)
		{
			insert(pair);
		}
	}

	~HashTable()
	{
		clear();
	}

	void insert(const std::pair<T, U>& pair)
	{
		if (m_max_size < m_size * 1.3)
			re_hash();

		Node<std::pair<T, U>>* tmp = new Node<std::pair<T, U>>();
		tmp->data.first = pair.first;
		tmp->data.second = pair.second;

        std::size_t index = hash(pair.first);

		Node<std::pair<T, U>>* bucket = m_buckets[index];

		if (!bucket)
		{
			m_buckets[index] = tmp;
			++m_size;

			return; // insert first bucket at this index
		}

		Node<std::pair<T, U>>* previous = nullptr;

		// handle collision
		while (bucket)
		{
			if (bucket->data.first == pair.first)
			{
				bucket->data.second = pair.second;
				return; // overwrite data if same key
			}

			previous = bucket;
			bucket = bucket->link;
		}

		// insert new bucket at end of list
		previous->link = tmp;
		++m_size;
	}

	void remove(const T& key)
	{
        std::size_t index = hash(key);

		Node<std::pair<T, U>>* previous = nullptr;
		Node<std::pair<T, U>>* bucket = m_buckets[index];

		while (bucket && bucket->data.first != key)
		{
			previous = bucket;
			bucket = bucket->link;
		}

		if (!bucket)
			return; // key not found

		if (!previous)
		{
			m_buckets[index] = bucket->link; // remove first bucket at this index
		}
		else
		{
			previous->link = bucket->link; // remove bucket
		}

		delete bucket;
		--m_size;
	}

	[[nodiscard]] std::optional<U> find(const T& key) const
	{
		Node<std::pair<T, U>>* bucket = m_buckets[hash(key)];

		while (bucket)
		{
			if (bucket->data.first == key)
				return bucket->data.second;

			bucket = bucket->link;
		}

		return std::nullopt;
	}

	[[nodiscard]] bool contains(const T& key) const noexcept
	{
		for (const auto* bucket : m_buckets)
		{
			while (bucket)
			{
				if (bucket->data.first == key)
					return true; // bucket found

				bucket = bucket->link;
			}
		}

		return false;
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size == 0 ? true : false;
	}

	void clear()
	{
		if (!empty())
		{
			for (auto& bucket : m_buckets)
			{
				while (bucket)
				{
					Node<std::pair<T, U>>* next = bucket->link;

					delete bucket;
					bucket = next;

					--m_size;
				}

				bucket = nullptr;
			}
		}
	}

	[[nodiscard]] std::size_t size() const noexcept
	{
		return m_size;
	}

	[[nodiscard]] std::size_t max_size() const noexcept
	{
		return m_max_size;
	}
};