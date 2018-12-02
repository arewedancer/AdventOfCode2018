#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int differByOne(string a, string b)
{
	int diff = 0;
	int pos;
  for(int i =0; i < a.size(); i++ )
	{
		if ( a.at(i) != b.at(i) )  { pos = i; diff++;};
		if ( diff > 1 ) break;
	};
	return diff == 1 ? pos : 0 ;
};

int main()
{
	string token; ifstream inputFile ("input.txt");
	vector<string> data;
	int factor2 = 1; int factor3 = 1;
	if (inputFile.is_open())
	{
		while ( getline (inputFile,token) )
		{   
			data.push_back(token);
		};
		inputFile.close();;
	};   
	for(int i = 0; i < data.size(); i ++ )
	 for(int j = i; j < data.size(); j++ )
	{
		int p = differByOne(data[i], data[j]);
		if ( p != 0 )
		{
			std::cout << "found " << data[i].erase(p, 1)<< std::endl;
		};
	};

}
