#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string token; ifstream inputFile ("input.txt");
	int factor2 = 1; int factor3 = 1;
	if (inputFile.is_open())
	{
		while ( getline (inputFile,token) )
		{   
			bool twice = false; bool thuce = false;
			sort(token.begin(), token.end());
			int count = 0; char pre;;
			for(auto s : token)
			{
				if (s == pre)
				{
					count ++;
				}
				else
				{
					if ( count == 2 ) twice = true;
					if ( count == 3 ) thuce = true;
					pre = s;
					count = 1;
				};
				if ( twice && thuce ) break;
			};
			factor2 += twice; factor3 += thuce;
		};
		inputFile.close();;
	}   
	std::cout << factor2  << " -- " <<  factor3 << std::endl;
	std::cout << "checksum= " << factor2 * factor3 << std::endl;
}
