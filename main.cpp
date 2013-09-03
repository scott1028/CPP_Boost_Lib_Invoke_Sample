/*

// Windows 版本
// c++ -I../../Desktop/boost_1_54_0 .\main.cpp

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main(){
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " "
	);
}

*/

// Windows 版本
// c++ -I ../../Desktop/boost_1_54_0 .\main.cpp
// Those are linker errors. The Boost regex library is not a header-only library like shared_ptr (for example) - you need to link against the .a or .lib or whatever binary library.
// You need to link to libboost_regex. Add -lboost_regex to the compiler switch if you're using gcc.
// 首先要先用：C:\Users\scott\Desktop\boost_1_54_0>b2 toolset=gcc --prefix=c:\boost_lib_install_path install，將 boost 的static Lib 編譯安裝好
// c++ .\main.cpp -I/boost_build/include/boost-1_54 -L/boost_build/lib_gcc -lboost_regex-mgw47-mt-1_54 ; .\a.exe

#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	/*
	// 找到字串就返回

	std::string line;
	boost::regex pat( "b(.*?)ex(.*?)y" );					// 也可以輸入表示整個字串的開頭 "^b"

	while (std::cin){
		std::getline(std::cin, line);						// 可以輸入 "b312321321321e"
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat)){
			std::cout << matches[1] << std::endl;			// [0] 全文, [1] 第一個匹配, [2]第二個匹配( 代表有第二個(.*?) )
			std::cout << matches[2] << std::endl;
			std::cout << matches.size() << std::endl;		// 這個 RegExp 的匹配總長( 等於3 )
		}
	}
	*/

	// 找到一群字串(類似 re.findall )
	std::string text("abc abd abc eeee trtrabewqewq rrabyyyy");

	boost::regex regex("ab.");							// 匹配表示( 找到ab+任意一個字母或數字 )

	boost::sregex_token_iterator iter(text.begin(), text.end(), regex, 0);
	boost::sregex_token_iterator end;

	for( ; iter != end; ++iter ) {
		std::cout<<*iter<<'\n';
	}
	
}
