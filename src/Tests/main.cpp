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