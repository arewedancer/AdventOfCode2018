#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <cmath>
#include <cctype>
#include <queue>

using namespace std;
static int val = 0;
queue<int> data;

void getSubtree()
{
		
		int numNode = data.front();;
		data.pop();
		int numMeta = data.front();
		data.pop();
		for(int j = 0 ; j < numNode ; j++ )
		{
				getSubtree();
		};
		for(int i = 0; i < numMeta; i++)
		{
			val += data.front();	
			data.pop();
		};
		return;
};

int main()
{
	string input; ifstream inputFile ("input.txt");
	if (inputFile)
	{
		while (inputFile >> input)
		{   
			data.push(stoi(input));
		};
	}
	inputFile.close();
	getSubtree();;
	std::cout << "final val = " << val << std::endl;
}
