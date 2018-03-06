#include "TTTree.h"
#include <iostream>
namespace structures {
	int test_tttree() {
		using structures::TTNode;
		TTNode<int> a;
		std::cout << a.EMPTY << "\n";
		std::cout << "--" << a.left << "--\n";



		return 0;
	}
	template <class Key, class Elem, class KEComp, class EEComp>
	bool TTTree<Key, Elem, KEComp, EEComp>::splitNode(
		TTNode<Elem>* subroot, 
		const Elem& inval,TTNode<Elem>* inptr,
		Elem& retval, TTNode<Elem>*& retptr) {
		
		retptr = new TTNode<Elem>(); // Node created by split
		if (EEComp::lt(inval, subroot->lkey)) {
			retval = subroot->lkey; subroot->lkey = inval;
			retptr->lkey = subroot->rkey;
			retptr->left = subroot->center;
			retptr->center = subroot->right;
			subroot->center = inptr;
		}
		else if (EEComp::lt(inval, subroot->rkey)) {
			retval = inval; retptr->lkey = subroot->rkey;
			retptr->left = inptr;
			retptr->center = subroot->right;
		}
		else {
			retval = subroot->rkey; retptr->lkey = inval;
			retptr->left = subroot->right;
			retptr->center = inptr;
		}
		subroot->rkey = TTNode::EMPTY;

	}

	template <class Key, class Elem, class KEComp, class EEComp>
	bool TTTree<Key, Elem, KEComp, EEComp>::insertHelp(
		TTNode<Elem>*& subroot, const Elem& e, 
		Elem& retval, TTNode<Elem>*& retptr) {

		Elem myretv; TTNode<Elem>* myretp = nullptr;

		if (subroot == nullptr) {	// Empty tree: make new node
			subroot = new TTNode<Elem>(); subroot->lkey = e;
		}
		else if (subroot->isLeaf()) {
			if (subroot->rkey == TTNode::EMPTY) // Easy case: not full
				if (EEComp::gt(e, subroot->lkey))
					subroot->rkey = e;
				else {
					subroot->rkey = subroot->lkey; subroot->lkey = e;
				}
			else
				splitNode(subroot, e, nullptr, retval, retptr);

		}
		else if (EEComp::lt(e, subroot->lkey)) // Insert in child
			insertHelp(subroot->left, e, myretv, myretp);
		else if (subroot->rkey == TTNode::EMPTY
			|| EEComp::lt(e, subroot->rkey))
			insertHelp(subroot->center, e, myretv, myretp);
		else
			insertHelp(subroot->right, e, myretv, myretp);

		if (myretp != nullptr) {
			// Child split: receive promoted value
			if (subroot->rkey != TTNode::EMPTY) // Full: split node
				splitNode(subroot, myretv, myretp, retval, retptr);
			else {	// Not full: add to this nnode
				if (EEComp::lt(myretv, subroot->lkey)) {
					subroot->rkey = subroot->lkey;
					subroot->lkey = myretv;
					subroot->right = subroot.center;
					subroot->center = myretp;
				}
				else {
					subroot->rkey = myretv;
					subroot->right = myretp;
				}
			}
		}
		return true;

	}

	template <class Key, class Elem, class KEComp, class EEComp>
	bool TTTree<Key, Elem, KEComp, EEComp>::findHelp(
		TTNode<Elem>* subroot, 
		const Key& k, Elem& e) const {
		if (subroot == nullptr) return false;
		if (KEComp::eq(k, subroot->lkey)) {
			e = subroot->lkey;
			return true;
		}
		if (subroot->rkey != nullptr
			&& KEComp::eq(k, subroot->rkey)) {
			e = subroot->rkey;
			return true;
		}
		if (KEComp::lt(k, subroot->lkey)) {
			return findHelp(subroot->left, k, e);
		}
		else if (subroot->rkey == TTNode::EMPTY) {
			return findHelp(subroot->center, k, e);
		}
		else if (KEComp::lt(k, subroot->rkey)) {
			return findHelp(subroot->center, k, e);
		}
		else {
			return findHelp(subroot->right, k, e);
		}
	}
}

//#define DEBUG_CSNAKE_TTTREE_H
#ifdef DEBUG_CSNAKE_TTTREE_H
int main() {
	structures::test_tttree();

	system("pause");
}

#endif