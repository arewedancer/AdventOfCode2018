#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	long re = 0; string token;
	ifstream inputFile ("input.txt");
	unordered_set<long> map; vector<long> inputs; map.insert(re);
  bool found = false;
	if (inputFile.is_open())
	{
		while ( getline (inputFile,token) )
		{   
			long e = stol(token.substr(1));
			if (token.at(0) == '-')
				e = 0 - e;
			re += e;
		  inputs.push_back(e);
			if ( map.find(re) != map.end() )
			{
				std::cout << "found " << re << std::endl;
				found = true;
			} else 
				map.insert(re);
		};
		inputFile.close();;
	}   
	std::cout << "result = " << re << std::endl;
  while (!found)
  {
		for( auto e : inputs)
		{
			re += e;
			if ( map.find(re) != map.end() )
			{
				std::cout << "found " << re << std::endl;
				exit(0);
			} else 
				map.insert(re);
		};
	}
}
