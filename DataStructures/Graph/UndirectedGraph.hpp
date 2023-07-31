#ifndef UNDIRECTED_GRAPH_HPP
#define UNDIRECTED_GRAPH_HPP

#include <cstddef>
#include <utility>
#include <vector>
#include <unordered_map>
#include <iterator>

template <typename T>
struct Adjacency;

template <typename T>
struct Vertex
{
	int								m_id;
	T								m_data;
	std::vector<Adjacency<T>>		m_adjacent;

	Vertex(int id, T data) : m_id{ id }, m_data{ data } {}
};

template <typename T>
struct Adjacency
{
	Vertex<T>*		m_dst;
	int				m_weight;

	Adjacency(Vertex<T>* dst, int weight) : m_dst{ dst }, m_weight{ weight } {}
};

template <typename T>
class UndirectedGraph
{
private:
	std::unordered_map<int, Vertex<T>*>		m_adj_list;

public:
	UndirectedGraph() = default;

	~UndirectedGraph()
	{
		clear();
	}

	void insert_vertex(const int key, const T data)
	{
		m_adj_list.insert({ key, new Vertex(key, data) });
	}

	void insert_edge(const int src, const int dst, const int weight = 1)
	{
		m_adj_list.at(src)->m_adjacent.emplace_back(m_adj_list.at(dst), weight);
		m_adj_list.at(dst)->m_adjacent.emplace_back(m_adj_list.at(src), weight);
	}

	void remove_vertex(const int key)
	{
		const auto& vertex = m_adj_list.at(key);

		for (int i = 0; i < vertex->m_adjacent.size(); ++i)
		{
			auto& otherAdjacent = vertex->m_adjacent[i].m_dst->m_adjacent;

			for (int j = 0; j < otherAdjacent.size(); ++j)
			{
				if (otherAdjacent[j].m_dst == vertex)
				{
					otherAdjacent.erase(otherAdjacent.begin() + j);
					break;
				}
			}
		}

		delete vertex;
		m_adj_list.erase(key);
	}

	void remove_edge(const int src, const int dst)
	{
		const auto& srcVertex = m_adj_list.at(src);
		const auto& dstVertex = m_adj_list.at(dst);

		for (auto i = 0; i < srcVertex->m_adjacent.size(); ++i)
		{
			if (srcVertex->m_adjacent[i].m_dst == dstVertex)
			{
				srcVertex->m_adjacent.erase(srcVertex->m_adjacent.begin() + i);
				break;
			}
		}

		for (auto i = 0; i < dstVertex->m_adjacent.size(); ++i)
		{
			if (dstVertex->m_adjacent[i].m_dst == srcVertex)
			{
				dstVertex->m_adjacent.erase(dstVertex->m_adjacent.begin() + i);
				break;
			}
		}
	}

	[[nodiscard]] auto at(const int key) noexcept -> T&
	{
		return m_adj_list.at(key)->m_data;
	}

	[[nodiscard]] auto at(const int key) const noexcept -> const T&
	{
		return m_adj_list.at(key)->m_data;
	}

	[[nodiscard]] auto count(const int key) const noexcept -> const std::size_t
	{
		return m_adj_list.count(key);
	}

	[[nodiscard]] auto find(const int key) const noexcept -> std::unordered_map<int, Vertex<T>*>::const_iterator
	{
		return m_adj_list.find(key);
	}

	[[nodiscard]] auto contains(const int key) const noexcept -> const bool
	{
		return m_adj_list.contains(key);
	}

	[[nodiscard]] auto empty() const noexcept -> const bool
	{
		return m_adj_list.empty();
	}

	void clear()
	{
		for (auto& pair : m_adj_list)
			delete pair.second;

		m_adj_list.clear();
	}

	[[nodiscard]] auto size() const noexcept -> const std::size_t
	{
		return m_adj_list.size();
	}

	[[nodiscard]] auto max_size() const noexcept -> const std::size_t
	{
		return m_adj_list.max_size();
	}
};

#endif // !UNDIRECTED_GRAPH_HPP