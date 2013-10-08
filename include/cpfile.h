#ifndef _cp_file_h_
#define _cp_file_h_

#include <fstream>
#include <string>

namespace cp { namespace util {

template<typename back_inserter>
void read_lines(
	const char * filepath, 
	back_inserter iter)
{
	//TODO : ensure back_inserter uses std::string for the value type
	std::ifstream ifs(filepath, std::ifstream::in);

	char buffer[1024];
	std::string line;
	while(ifs.good()) 
	{
		ifs.getline(buffer, sizeof(buffer));
		if(ifs.eof())
			break;
		line = buffer;
		while(ifs.fail() && !ifs.bad() && !ifs.eof())
		{
			ifs.getline(buffer, sizeof(buffer));
			line += buffer;
		}
		
		*iter = line;
		++iter;
	}
}

} }

#endif
