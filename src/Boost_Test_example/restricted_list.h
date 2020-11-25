#pragma once

#include <list>
#include <type_traits>

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class RestrictedList
{
	class ProxyRestrictedList
	{
		T *val;
		bool isRestricted;
		T min, max;
	public:
		ProxyRestrictedList(T &val, bool isRestricted, T min, T max) : 
			val(&val), isRestricted(isRestricted), min(min), max(max)
		{}
		T& operator=(T v)
		{
			if (isRestricted && (v < min || v > max))
				throw std::exception("Invalid range");
			*val = v;
			return *val;
		}
		bool operator==(T v)
		{
			return *val == v;
		}
	};

	std::list<T> l;
	T min, max;
	bool isRestricted;
public:
	RestrictedList() : min{ 0 }, max{ 0 }, isRestricted{false}
	{}
	RestrictedList(T min, T max) : min{ min }, max{ max }, isRestricted{ true }
	{
		if (min > max)
			throw std::exception("min value must be greater (or equal) than max");
	}
	void push_back(T elem)
	{
		if(isRestricted && (elem < min || elem > max))
			throw std::exception("inserted element not in specified range");
		l.push_back(elem);
	}
	void pop_back(T elem)
	{
		if (isRestricted && (elem < min || elem > max))
			throw std::exception("inserted element not in specified range");
		l.pop_back(elem);
	}
	ProxyRestrictedList front()
	{
		try 
		{
			return ProxyRestrictedList(l.front(), isRestricted, min, max);
		}
		catch (...)
		{
			throw;
		}
	}
};