#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Box
{
	int tag;
	int x, y, x_max, y_max;
	Box(int tag_, int x_, int x_max_, int y_, int y_max_):
		tag(tag_), x(x_), x_max(x_max_), y(y_), y_max(y_max_) {};
	Box(const Box& b):
		tag(b.tag), x(b.x), x_max(b.x_max), y(b.y), y_max(b.y_max) {};
};
int main()
{
	string line; ifstream inputFile ("input.txt");
	int fabric[1000][1000];
	// initialize
	for(int i = 0; i < 1000; i++ )
		for( int j = 0; j < 1000; j++ )
			fabric[i][j] = 0;
	vector<Box> data;
	if (inputFile.is_open())
	{
		while ( getline (inputFile,line) )
		{   
			int n1,n2,n3,n4;
			char delimiter=' ';
			string token; int tag;
			istringstream tokenStream(line);
			while (std::getline(tokenStream, token, delimiter))
			{   
				size_t found = token.find(',');
				if ( found != string::npos )
				{
					n1 = stoi(token.substr(0, found));
					n2 = stoi(token.substr(found+1, token.length() - found));	
				};
				found = token.find('x');
				if ( found != string::npos )
				{
					n3 = stoi(token.substr(0, found));
					n4 = stoi(token.substr(found+1, token.length()- found +1));
				};
				found = token.find('#');
				if ( found != string::npos )
					tag = stoi(token.substr(1));;
			};   
			n3 += n1; n4 += n2;
			Box b(tag, n1, n3, n2, n4);
			data.push_back(b);
			for(int i = n1; i < n3; i++)
				for (int j = n2; j < n4; j++ )
					fabric[i][j] ++;
		};
		inputFile.close();;
	};   
	int part1 = 0; 
	for(int i = 0; i < 1000; i++ )
		for( int j = 0; j < 1000; j++ )
		{
			if ( fabric[i][j] > 1 ) part1++;
		};
	std::cout << "part1 = " << part1 << std::endl;
	for (Box b :  data)
	{
		bool part2 = true;
		for(int i = b.x; i < b.x_max; i++)
			for (int j = b.y; j < b.y_max; j++ )
			{
				if ( fabric[i][j] >1 ) part2 = false;
			}
		if ( part2 )
		{
			std::cout << "part2 = " << b.tag << std::endl;
			exit(0);
		};
	};
}
