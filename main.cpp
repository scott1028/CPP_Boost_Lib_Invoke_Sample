// #include <boost/lambda/lambda.hpp>
// #include <iostream>
// #include <iterator>
// #include <algorithm>

// // Windows 版本
// // c++ -I../../Desktop/boost_1_54_0 .\main.cpp

// int main(){
// 	using namespace boost::lambda;
// 	typedef std::istream_iterator<int> in;

// 	std::for_each(
// 		in(std::cin), in(), std::cout << (_1 * 3) << " "
// 	);
// }

#include <boost/regex.hpp>
#include <iostream>
#include <string>

// Windows 版本
// c++ -I ../../Desktop/boost_1_54_0 .\main.cpp
// Those are linker errors. The Boost regex library is not a header-only library like shared_ptr (for example) - you need to link against the .a or .lib or whatever binary library.
// You need to link to libboost_regex. Add -lboost_regex to the compiler switch if you're using gcc.
// 首先要先用：C:\Users\scott\Desktop\boost_1_54_0>b2 toolset=gcc --prefix=c:\boost_lib_install_path install，將 boost 的static Lib 編譯安裝好
// c++ .\main.cpp -I/boost_build/include/boost-1_54 -L/boost_build/lib_gcc -lboost_regex-mgw47-mt-1_54 ; .\a.exe

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
