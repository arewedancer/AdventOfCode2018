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

using namespace std;
int main()
{
	string line; ifstream inputFile ("input.txt");
	stack<char> data; char input;
	if (inputFile)
	{
		while ( inputFile.get(input) )
		{   
				if (!isalpha(input)) continue; 
				if (data.empty() || abs(data.top() - input ) != 32 )
						data.push(input);
				else
						data.pop();
		};
				
	}
	inputFile.close();
	std::cout << "final size = " << data.size() << std::endl;

}
