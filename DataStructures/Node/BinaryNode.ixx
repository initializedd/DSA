export module BinaryNode;

export template <typename T>
struct BinaryNode
{
	T					data;
	BinaryNode*			left;
	BinaryNode*			right;

	BinaryNode() : data{}, left{}, right{} {}
};