export module Node;

export template <typename T>
struct Node
{
	T			data;
	Node*		link;

	Node() : data{}, link{} {}
};