#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <typename T>
struct BinaryNode
{
	T					data;
	BinaryNode*			left;
	BinaryNode*			right;

	BinaryNode() : data{}, left{}, right{} {}
};

#endif // !BINARY_NODE_H