#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "../Boost_Test_example/restricted_list.h"


BOOST_AUTO_TEST_CASE(my_boost_test)
{
	RestrictedList<float> l;

	int a = 2 + 2;
	BOOST_CHECK(a= 4);
}