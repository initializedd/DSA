#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node
{
	T			data;
	Node*		link;

	Node() : data{}, link{} {}
};

#endif // !NODE_HPP