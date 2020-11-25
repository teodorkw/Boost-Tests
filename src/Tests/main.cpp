#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "../Boost_Test_example/restricted_list.h"


BOOST_AUTO_TEST_CASE(constructors_test)
{
	BOOST_CHECK_NO_THROW(RestrictedList<char>());
	BOOST_CHECK_NO_THROW(RestrictedList<int>());
	BOOST_CHECK_NO_THROW(RestrictedList<double>());

	BOOST_CHECK_NO_THROW(RestrictedList<int>(4, 4));
	BOOST_CHECK_NO_THROW(RestrictedList<float>(2.f, 4.f));

	BOOST_CHECK_THROW(RestrictedList<int>(123, 4), std::exception);
	BOOST_CHECK_THROW(RestrictedList<float>(4.f, 1.f), std::exception);
}

BOOST_AUTO_TEST_CASE(inserting_test)
{
	RestrictedList<int> list1(10, 50);
	BOOST_CHECK_NO_THROW(list1.push_back(12));
	BOOST_CHECK_THROW(list1.push_back(52), std::exception);

	list1.push_back(28);
	list1.push_back(23);
	list1.push_back(32);

	BOOST_CHECK_NO_THROW(list1.front() = 15);
	BOOST_CHECK(list1.front() == 15);
	BOOST_CHECK_THROW(list1.front() = 51, std::exception);
	BOOST_CHECK(list1.front() == 15);
}
