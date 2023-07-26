#ifndef BINARY_NODE_HPP
#define BINARY_NODE_HPP

template <typename T>
struct BinaryNode
{
	T					data;
	BinaryNode*			left;
	BinaryNode*			right;

	BinaryNode() : data{}, left{}, right{} {}
};

#endif // !BINARY_NODE_HPP