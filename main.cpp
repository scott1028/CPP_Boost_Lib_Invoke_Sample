#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

// Windows 版本
// c++ -I../../Desktop/boost_1_54_0 .\main.cpp

int main(){
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " "
	);
}

/*
	#include <boost/regex.hpp>
	#include <iostream>
	#include <string>

	// Windows 版本
	// c++ -I ../../Desktop/boost_1_54_0 .\main.cpp

	int main(){
		std::string line;
		boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

		while (std::cin)
		{
			std::getline(std::cin, line);
			boost::smatch matches;
			if (boost::regex_match(line, matches, pat))
				std::cout << matches[2] << std::endl;
		}
	}
*/