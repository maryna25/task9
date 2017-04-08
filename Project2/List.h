#pragma once
#include <vector>
#include <algorithm>


template <typename T>
class List
{
public:
	class Iterator;
protected:
	struct Node
	{
		T _elem;
		Node * _next;
		Node(const T& elem, Node* next = nullptr) : _elem{ elem }, _next{next}  {};
		~Node() 
		{
			//delete _next;
		}
	};
protected:
	Node * _begin=nullptr;
public:
	List(){};
	List(std::initializer_list<T> inList)
	{
		std::vector<T> temp = inList;
		std::reverse(temp.begin(), temp.end()); //we need to push elements in list in reversed order
		for (const auto elem : temp)
		{
			pushBack(elem);
		}
	};
	virtual ~List()
	{
		delete _begin; //it will call destructor for each element
	};
	virtual Iterator begin()
	{
		return Iterator(*this, _begin );
	};
	virtual Iterator end() //pointer on element that after last
	{
		return Iterator(*this);
	};
	
	virtual void pushBack(const T& val)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(val, nullptr);
		}
		else
		{
			_begin = new Node(val, _begin);
		}
	}
	virtual void popBack(){
		if (_begin == nullptr)   throw std::exception();
		auto temp = _begin;
		_begin = _begin->_next;
		temp->_next = nullptr;
		delete temp;

	};
	virtual T back()
	{
		return *begin();
	};
};

template <typename T>
class List<T>::Iterator
{
	typedef typename List::Node * nodePtr;
	nodePtr _current;
	List& _associated;
public:
	Iterator(List<T>& associated, nodePtr curr=nullptr) :_associated{ associated }, _current{ curr }  {};
	T& operator*()
	{
		return _current->_elem;
	};
	Iterator& operator++()
	{
		if (_current == nullptr) throw std::exception("Out of range");
		_current = _current->_next;
		return *this;
	};
	bool operator==(const Iterator& iter) const
	{
		if (&_associated != &iter._associated) throw std::exception();
		return _current == iter._current;
	}
	bool operator!=(const Iterator& iter) const
	{
		return !(*this == iter);
	}
};

//1 -> 2 -> 3
//tail	head
//begin	end
//back	front