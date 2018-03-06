


#ifndef CSNAKE_TTTREE_H
#define CSNAKE_TTTREE_H

namespace structures {

	template <class Elem>
	class TTNode {
	public:
		const static Elem EMPTY = 0;
		Elem lkey;
		Elem rkey;
		TTNode* left;
		TTNode* center;
		TTNode* right;
		TTNode() {
			center = left = right = nullptr;
			lkey = rkey = EMPTY;
		}
		~TTNode() {}
		bool isLeaf() {
			return left == nullptr;
		}
	};

	template <class Key, class Elem, class KEComp, class EEComp>
	class TTTree {
	private:
		bool findHelp(TTNode<Elem>* subroot, const Key& k, Elem& e) const;
		bool splitNode(TTNode<Elem>* subroot, const Elem& inval,
			TTNode<Elem>* inptr, Elem& retval, TTNode<Elem>*& retptr);
		bool insertHelp(TTNode<Elem>*& subroot, const Elem& e, Elem& retval, TTNode<Elem>*& retptr);

	};


	int test_tttree();
}

#endif	// CSNAKE_TTTREE_H