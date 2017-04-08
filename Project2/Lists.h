#pragma once;
#include "List.h"


// 1 -> 2 -> 3
// |		 |
//  <--------
template <typename T>
class CyclicList : virtual public List<T>
{
protected:
	Node * _end;
public:
	CyclicList(std::initializer_list<T> inList)
	{
		std::vector<T> temp = inList;
		std::reverse(temp.begin(), temp.end());
		for (const auto elem : temp)
		{
			pushBack(elem);
		}
	};
	virtual ~CyclicList()
	{
	};
	void pushBack(const T& val)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(val);
			_begin->_next = _begin;
			_end = _begin; //will point on last elem all the time
		}
		else
		{
			_begin = new Node(val, _begin);
			_end->_next = _begin;
		}
	};
	void popBack()
	{
		if (_begin == nullptr) throw std::exception();
		auto temp = _begin;
		if (_begin == _begin->_next) //if we have just one element
		{
			_begin = nullptr;
			_end = nullptr;
		}
		else
		{
			_begin = _begin->_next;
			_end->_next = _begin;
		}
		temp->_next = nullptr;
		delete temp;
	}
};

template <typename T>
class DoubleSidedList : virtual public List<T>
{
public:
	DoubleSidedList()
	{

	};
	DoubleSidedList(std::initializer_list<T> inList)
	{
		std::vector<T> temp = inList;
		std::reverse(temp.begin(), temp.end());
		for (const auto elem : temp)
		{
			pushBack(elem);
		}
	};
	virtual ~DoubleSidedList()
	{
	};
	virtual void pushFront(const T& val)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(val, nullptr);
		}
		else
		{
			Node * temp = _begin;
			while (temp->_next) temp = temp->_next;
			temp->_next = new Node(val, nullptr);
		}
	}
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
	virtual void popBack()
	{
		if (_begin == nullptr)   throw std::exception();
		auto temp = _begin;
		_begin = _begin->_next;
		temp->_next = nullptr;
		delete temp;
	};
	virtual void popFront()
	{
		if (_begin == nullptr)   throw std::exception();
		auto temp = _begin;
		while (temp->_next->_next) temp = temp->_next;
		delete temp->_next;
		temp->_next = nullptr;
	}
};

template <typename T>
class CyclicDoubleSidedList : public DoubleSidedList<T>, public CyclicList<T>
{
public:
	CyclicDoubleSidedList(std::initializer_list<T> inList) 
		:CyclicList<T>( inList )
	{
	};
	~CyclicDoubleSidedList()
	{};
	void pushBack(const T& val)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(val);
			_begin->_next = _begin;
			_end = _begin; //will point on last elem all the time
		}
		else
		{
			_begin = new Node(val, _begin);
			_end->_next = _begin;
		}
	}; 
	void pushFront(const T& val)
	{
		if (_begin == nullptr)
		{
			_begin = new Node(val);
			_begin->_next = _begin;
			_end = _begin; //will point on last elem all the time
		}
		else
		{
			Node * temp = _begin;
			while (temp!=_end) temp = temp->_next;
			temp->_next = new Node(val, nullptr);
			_end = temp->_next;
			_end->_next = _begin;
		}
	}
	void popBack()
	{
		if (_begin == nullptr) throw std::exception();
		auto temp = _begin;
		if (_begin == _begin->_next) //if we have just one element
		{
			_begin = nullptr;
			_end = nullptr;
		}
		else
		{
			_begin = _begin->_next;
			_end->_next = _begin;
		}
		temp->_next = nullptr;
		delete temp;
	}

	void popFront()
	{
		if (_begin == nullptr)   throw std::exception();
		if (_begin == _begin->_next) //if we have just one element
		{
			_begin = nullptr;
			_end = nullptr;
		}
		else
		{
			auto temp = _begin;
			while (temp->_next != _end) temp = temp->_next;
			_end = temp;
			temp->_next = nullptr;
			_end->_next = _begin;
		}
	}

};

