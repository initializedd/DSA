#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"
#include <optional>

template <typename T>
class BinarySearchTree
{
private:
	BinaryNode<T>*				m_root;
	int							m_size;

	void clearRecursive(BinaryNode<T>* node)
	{
		if (!node)
			return; // return to previous call when reaching leaf

		clearRecursive(node->left);
		clearRecursive(node->right);

		delete node;
		--m_size;
	}

public:
	BinarySearchTree()
		: m_root{}
		, m_size{}
	{
	}

	~BinarySearchTree()
	{
		clear();
	}

	void insert(T data)
	{
		BinaryNode<T>* tmp = new BinaryNode<T>();
		tmp->data = data;

		++m_size;

		if (!m_root)
		{
			m_root = tmp;
			return; // root created
		}

		BinaryNode<T>* ptr = m_root;

		while (ptr)
		{
			if (data < ptr->data)
			{
				if (!ptr->left)
				{
					ptr->left = tmp;
					return; // data inserted
				}

				ptr = ptr->left;
			}
			else if (data > ptr->data)
			{
				if (!ptr->right)
				{
					ptr->right = tmp;
					return; // data inserted
				}

				ptr = ptr->right;
			}
			else
			{
				delete tmp;
				--m_size;
				return; // data already exists
			}
		}
	}

	void remove(T data)
	{
		if (!m_root)
			return;

		BinaryNode<T>* parent = nullptr;
		BinaryNode<T>* ptr = m_root;

		while (ptr)
		{
			if (data == ptr->data)
			{
				--m_size;
				break; // data found
			}

			parent = ptr;

			if (data < ptr->data)
			{
				if (!ptr->left)
					return; // data does not exist

				ptr = ptr->left;
			}
			else if (data > ptr->data)
			{
				if (!ptr->right)
					return; // data does not exist

				ptr = ptr->right;
			}
		}

		// remove root node
		if (ptr == m_root)
		{
			if (ptr->left && ptr->right)
			{
				parent = ptr->left;
				ptr = ptr->right;

				delete m_root;
				m_root = parent;

				BinaryNode<T>* newPtr = m_root;

				// find the new root's right leaf
				while (newPtr->right)
				{
					newPtr = newPtr->right;
				}

				newPtr->right = ptr;

				return; // left node becomes root, right node becomes new root's right leaf
			}

			if (ptr->left)
			{
				ptr = ptr->left;

				delete m_root;
				m_root = ptr;
				return; // set root to left node
			}

			if (ptr->right)
			{
				ptr = ptr->right;

				delete m_root;
				m_root = ptr;
				return; // set root to right node
			}

			delete m_root;
			m_root = nullptr;
			return; // final node destroyed
		}

		if (ptr->left && ptr->right)
		{
			BinaryNode<T>* newPtr = ptr->left;

			if (ptr == parent->left)
				parent->left = newPtr;
			else
				parent->right = newPtr;

			// find the new node's right leaf
			while (newPtr->right)
			{
				newPtr = newPtr->right;
			}

			newPtr->right = ptr->right;

			delete ptr;
			return; // node with 2 children removed
		}

		if (ptr->left)
		{
			if (ptr == parent->left)
				parent->left = ptr->left;
			else
				parent->right = ptr->left;

			delete ptr;
			return; // left node replaces removed node
		}

		if (ptr->right)
		{
			if (ptr == parent->left)
				parent->left = ptr->right;
			else
				parent->right = ptr->right;

			delete ptr;
			return; // right node replaces removed node
		}

		if (ptr == parent->left)
		{
			delete ptr;
			parent->left = nullptr;
			return; // remove left leaf
		}

		if (ptr == parent->right)
		{
			delete ptr;
			parent->right = nullptr;
			return; // remove right leaf
		}
	}

	[[nodiscard]] bool empty() const noexcept
	{
		return m_size == 0 ? true : false;
	}

	[[nodiscard]] BinaryNode<T>* find(T data) const noexcept
	{
		BinaryNode<T>* ptr = m_root;

		while (ptr)
		{
			if (data == ptr->data)
				return ptr;

			else if (data < ptr->data)
				ptr = ptr->left;

			else
				ptr = ptr->right;
		}

		return nullptr;
	}

	void clear()
	{
		clearRecursive(m_root);
		m_root = nullptr;
	}

	[[nodiscard]] int size() const noexcept
	{
		return m_size;
	}

};

#endif // !BINARY_SEARCH_TREE_H