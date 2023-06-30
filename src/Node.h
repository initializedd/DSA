#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
struct Node
{
	T data;
	std::shared_ptr<Node> link;

	Node() : data{}, link{} {}
};

#endif // !NODE_H