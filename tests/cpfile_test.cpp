#include "tpunit++.hpp"

#include <vector>
#include <string>
#include <iterator>
#include "cpfile.h"
#include <iostream>

const char * DATA_FILE = "data.txt";

struct cpfile_test : tpunit::TestFixture
{

	cpfile_test() : tpunit::TestFixture
	(
		TEST(cpfile_test::can_read_lines_into_vector)
	)
	{}

	void can_read_lines_into_vector()
	{
		std::vector<std::string> line_container;
		cp::util::read_lines(
			DATA_FILE, std::back_inserter(line_container));

		typedef std::vector<std::string>::iterator line_iter;

		ASSERT_EQUAL(line_container.size(), 4);

		int line_num = 0;
		char line_value[6];
		for(line_iter it = line_container.begin();
			it != line_container.end(); ++it)
		{
			sprintf(line_value, "line%d", ++line_num);
			ASSERT_EQUAL(*it, line_value);
		}
	}
} __cpfile_test;
