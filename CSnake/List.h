//
// Created by sunzhijun on 18-2-17.
//

#ifndef CSNAKE_LIST_H
#define CSNAKE_LIST_H

#include <iostream>

namespace structures {

	template<class Elem>
	class List {
	public:
		virtual ~List() {}
	public:

		virtual void clear() = 0;

		virtual bool insert(const Elem &) = 0;/* ---|i----- */
		virtual bool append(const Elem &) = 0;/* ---|-----a */
		virtual bool remove(Elem &) = 0;/* ---|r----- */
		virtual void setStart() = 0;/* |-------- */
		virtual void setEnd() = 0;/* --------| */
		virtual void prev() = 0;/* ---|-----  -> --|------  */
		virtual void next() = 0;/* ---|-----  -> ----|----  */
		virtual int leftLength() const = 0;/* 3 */
		virtual int rightLength() const = 0;/* 5 */
		virtual bool setPos(int pos) = 0;/* ---|-----  pos = 3 */
		virtual bool getValue(Elem &) const = 0;/* ---|v---- */
		virtual void print() const = 0;

		bool find(List<Elem> &L, Elem K);
	};

	template<class Elem>
	class AList : public List<Elem> {
	private:
		int _maxSize;
		int _listSize;
		int _fence;
		Elem* _listArray;

	public:
		AList(int size = 32){
			_maxSize = size;
			_listSize = _fence = 0;
			_listArray = new Elem[_maxSize];
		}
		virtual ~AList(){
			delete[] _listArray;
		}
		void clear() override{
			delete[] _listArray;
			_listSize = _fence = 0;
			_listArray = new Elem[_maxSize];
		}
		bool insert(const Elem&) override;
		bool append(const Elem&) override;
		bool remove(Elem&) override;

		void setStart() override { _fence = 0; }
		void setEnd() override { _fence = _listSize; }
		void prev() override { if (_fence != 0) _fence--; }
		void next() override { if (_fence <= _listSize) _fence++; }
		int leftLength() const override { return _fence; }
		int rightLength() const override { return _listSize - _fence; }
		bool setPos(int pos) override {
			if (pos >= 0 && pos <= _listSize) { _fence = pos; }
			return pos >= 0 && pos <= _listSize;
		}
		bool getValue(Elem& it) const override {
			if (rightLength() == 0) {
				return false;
			}
			else{
				it = _listArray[_fence];
				return true;
			}
		}
		void print() const override;
	};


	// Sorted array-based list
	template <class Elem, class Compare>
	class SAList: protected AList<Elem>{
	public:
		const static int DefaultListSize = 20;
		SAList(int size = DefaultListSize) : AList<Elem>(size){}
		~SAList(){}
		using AList<Elem>::clear;
		bool insert(const Elem& item) override;
		// All remaining methods are exposed from AList
		using AList<Elem>::remove;
		using AList<Elem>::setStart;
		using AList<Elem>::setEnd;
		using AList<Elem>::prev;
		using AList<Elem>::next;
		using AList<Elem>::leftLength;
		using AList<Elem>::rightLength;
		using AList<Elem>::setPos;
		using AList<Elem>::getValue;
		using AList<Elem>::print;
	};


//#define LINK_DEBUG

//    namespace link {

	template<class Elem>// Singly-linked list node
	class Link {

	private:
#ifdef LINK_DEBUG
		static int _freeListSize;
#endif
		const static int NewOnceCount = 20;
		static Link<Elem>* _freeList;//Head of the freelist
	public:
		Elem element;       //Value for this node
		Link *next;         //Pointer to next node in list
		Link(const Elem &element, Link *next = NULL) {
			this->element = element;
			this->next = next;
		}

		Link(Link *next = NULL) { this->next = next; }

		void* operator new(size_t);
		void operator delete(void*);
	};

	template <class Elem>
	Link<Elem>* Link<Elem>::_freeList = NULL;

#ifdef LINK_DEBUG
	template <class Elem>
	int Link<Elem>::_freeListSize = 0;
#endif

	template <class Elem>
	void* Link<Elem>::operator new(size_t){
#ifdef LINK_DEBUG
		std::cout << "\nfreeListSize : "<<_freeListSize << " new --start\n";
#endif
		if (_freeList == NULL){
			Link<Elem> (*tempArray) = ::new Link[NewOnceCount];
			Link<Elem>* temp = &tempArray[0];
			for (int i = 1; i < NewOnceCount; ++i) {
				tempArray[i].next = temp;
				temp = &tempArray[i];
			}
			_freeList = &tempArray[NewOnceCount-1];
//            return ::new Link;
#ifdef LINK_DEBUG
			_freeListSize = NewOnceCount;
			std::cout << "\nfreeListSize : "<<_freeListSize << "\n";
#endif
		}
		Link<Elem>* temp = _freeList;   //Can take from freeList
		_freeList = _freeList->next;
#ifdef LINK_DEBUG
		_freeListSize--;
		std::cout << "\nfreeListSize : "<<_freeListSize << " new --end\n";
#endif
		return temp;
	}

	template <class Elem>
	void Link<Elem>::operator delete(void* ptr){
		((Link<Elem>*)ptr)->next = _freeList;
		_freeList = (Link<Elem>*)ptr;
#ifdef LINK_DEBUG
		_freeListSize++;
		std::cout << "\nfreeListSize : "<<_freeListSize << " delete\n";
#endif
	}



//    }


	template <class Elem>
	class LList:public List<Elem>{
	private:
		Link<Elem>* _head;  //Pointer to list header
		Link<Elem>* _tail;  //Pointer to last Elem in list
		Link<Elem>* _fence; //Last element on left side;
		int _leftcnt;
		int _rightcnt;
		void init(){
			_fence = _tail = _head = new Link<Elem>;
			_leftcnt = _rightcnt = 0;
		}
		void removeall(){
			while (_head != NULL){
				_fence = _head;
				_head = _head->next;
				delete _fence;
			}
		}

		const static int DefaultListSize = 32;
	public:
		LList(int size = DefaultListSize) { init(); }
		virtual ~LList() { removeall(); }
		void clear() { removeall(); init(); }
		bool insert(const Elem&);
		bool append(const Elem&);
		bool remove(Elem&);
		void setStart()
		{ _fence = _head; _rightcnt += _leftcnt; _leftcnt = 0; }
		void setEnd()
		{ _fence = _tail; _leftcnt += _rightcnt; _rightcnt = 0; }
		void prev();
		void next(){
			if (_fence != _tail)
			{ _fence = _fence->next; _rightcnt--; _leftcnt++; }
		}
		int leftLength() const { return _leftcnt; }
		int rightLength() const { return _rightcnt; }
		bool setPos(int pos);
		bool getValue(Elem& it) const {
			if (rightLength() == 0) return false;
			it = _fence->next->element;
			return true;
		}
		void print() const;

	};


	// Sorted array-based list
	template <class Elem, class Compare>
	class SLList: protected LList<Elem>{
	public:
		const static int DefaultListSize = 20;
		SLList(int size = DefaultListSize) : LList<Elem>(size){}
		~SLList(){}
		using AList<Elem>::clear;
		bool insert(const Elem& item){
			Elem curr;
			for (setStart(); getValue(curr); next())
				if (!Compare::lt(curr, item)) break;
			return LList<Elem>::insert(item);
		}
		// All remaining methods are exposed from AList
		using LList<Elem>::remove;
		using LList<Elem>::setStart;
		using LList<Elem>::setEnd;
		using LList<Elem>::prev;
		using LList<Elem>::next;
		using LList<Elem>::leftLength;
		using LList<Elem>::rightLength;
		using LList<Elem>::setPos;
		using LList<Elem>::getValue;
		using LList<Elem>::print;
	};







#define DLINK_DEBUG

	//Doubly-linked list link node with freelist support
	template <class Elem>
	class DLink{
	private:
#ifdef DLINK_DEBUG
		static int _freelistSize;

		static void printSize(std::string name){
			std::cout << "\nfreelistSize : " << _freelistSize << " " << name.c_str() <<"\n";
		}
#endif
		static DLink<Elem>* _freelist;  //Head of the freelist
	public:
		Elem element;   //Value for this node
		DLink* next;    //Pointer to next node in list;
		DLink* prev;    //Pointer to previous node
		DLink(const Elem& e, DLink* prevp = NULL, DLink* nextp = NULL)
		{ element = e; prev = prevp; next = nextp; }
		DLink(DLink* prevp = NULL, DLink* nextp = NULL)
		{ prev = prevp; next = nextp; }

		void* operator new(size_t);
		void operator delete(void*);
	};

#ifdef DLINK_DEBUG
	template <class Elem>
	int DLink<Elem>::_freelistSize = 0;
#endif

	template <class Elem>
	DLink<Elem>* DLink<Elem>::_freelist = NULL;

	template <class Elem>
	void* DLink<Elem>::operator new(size_t){
#ifdef DLINK_DEBUG
		printSize("new start");
#endif
		if(_freelist == NULL){
#ifdef DLINK_DEBUG
			printSize("new if");
#endif
			return ::new DLink;
		}
		DLink<Elem>* temp = _freelist;
		_freelist = _freelist->next;
#ifdef DLINK_DEBUG
		_freelistSize--;
		printSize("new end");
#endif
		return temp;
	}

	template <class Elem>
	void DLink<Elem>::operator delete(void* ptr){
		((DLink<Elem>*)ptr)->next = _freelist;
		_freelist = (DLink<Elem>*)ptr;
#ifdef DLINK_DEBUG
		_freelistSize++;
		printSize("delete");
#endif
	}


	template <class Elem>
	class DList:public List<Elem>{
	private:
		DLink<Elem>* _head; //Pointer to list header
		DLink<Elem>* _tail; //Pointer to last Elem in list
		DLink<Elem>* _fence;//Last Element on left size
		int _leftcnt;       //Size of left partition;
		int _rightcnt;      //Size of right partition;
		void init(){        //Initialization routine
			_fence = _tail = _head = new DLink<Elem>;
			_leftcnt = _rightcnt = 0;
		}
		void removeall(){   //Return link nodes to free store
			while (_head != NULL){
				_fence = _head;
				_head = _head->next;
				delete _fence;
			}
		}

		const static int DefaultListSize = 20;

	public:
		DList(int size = DefaultListSize) { init(); }
		~DList() { removeall(); }
		void clear() { removeall(); init(); }
		bool insert(const Elem&);
		bool append(const Elem&);
		bool remove(Elem&);
		void setStart()
		{ _fence = _head; _rightcnt += _leftcnt; _leftcnt = 0; }
		void setEnd()
		{ _fence = _tail; _leftcnt += _rightcnt; _rightcnt = 0; }
		void prev();
		void next(){
			if (_fence != _tail)// Don't move fence if right empty
			{ _fence = _fence->next; _rightcnt--; _leftcnt++; }
		}
		int leftLength() const { return _leftcnt; }
		int rightLength() const { return _rightcnt; }
		bool setPos(int pos);
		bool getValue(Elem& it) const {
			if (rightLength() == 0) return false;
			it = _fence->next->element;
			return true;
		}
		void print() const;
	};
}

#include"List_impl.h"

#endif //CSNAKE_LIST_H