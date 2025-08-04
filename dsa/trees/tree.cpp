#include <iostream>
#include <string.h>
using namespace std;

template <typename T> class Node {
  public:
	T val;
	Node<T> *left;
	Node<T> *right;

	Node(T x) : val(x), left(nullptr), right(nullptr) {};
};

class Tree {
  private:
	Node<char> *root;

  public:
	Node<char> *build_tree(const char *preorder, const char *inorder)
	{
		const char *pre_ptr = preorder;
		const char *in_end = inorder;
		while (*in_end)
		{
			++in_end;
		}

		auto build_rec = [&](const char *in_start, const char *in_finish,
		                     auto &&build_rec) -> Node<char> * {
			if (in_start >= in_finish)
				return nullptr;

			char rval = *pre_ptr++;
			Node<char> *root = new Node<char>(rval);

			const char *root_in = in_start;
			while (root_in != in_finish && *root_in != rval)
			{
				++root_in;
			}

			root->left = build_rec(in_start, root_in, build_rec);
			root->right = build_rec(root_in + 1, in_finish, build_rec);
			return root;
		};

		return build_rec(inorder, in_end, build_rec);
	}
};
