#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <climits>
#include "ConvexHull.hpp"
using namespace std;

bool exist(Point&p, const vector<Point>& t)
{
	for (Point e: t)
	{
		if ( e == p ) return true;
	};
	return false;
};
int main()
{
	string line; ifstream inputFile ("input.txt");
	vector<Point> points;
	int area[500][500];
	for(int i = 0; i < 500; i++ )
	for(int j = 0; j < 500; j++ )
		area[i][j] = 0;
	int max_x = 0; int max_y = 0;
	if (inputFile.is_open())
	{
		while ( getline (inputFile,line) )
		{   
			int x = stoi(line.substr(0, line.find_first_of(',')));	
			int y = stoi(line.substr(line.find_first_of(',')+2));	
			points.push_back(Point{x,y});
		};
		inputFile.close();;
	};   
	const vector<Point> result = makeConvexHull(points);
	for(int i = 0; i < 500; i++ )
	for(int j = 0; j < 500; j++ )
	{
		int min_d = 20000; int count = -1;
		for (int n =0; n< points.size(); n++ )
		{
			int d = abs(points[n].x - i ) + abs(points[n].y - j );
			if ( d == min_d ) count = -1;
			if ( d < min_d )
			{
				min_d = d;
				count = n;
			};
		};
		area[i][j] = count;
	};
	unordered_map<int, int> map;
	int max = 0;
	for(int i = 0; i < 500; i++ )
	for(int j = 0; j < 500; j++ )
	{
		if ( area[i][j] != -1 )
			map[area[i][j]] ++;
	};
	for( auto p : map )
	{
		if ( !exist(points[p.first], result) )
		max = p.second > max ? p.second : max;
	};
	std::cout << "max = " << max << std::endl;
}

