#pragma once

#include <list>
#include <type_traits>

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class RestrictedList
{
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
};