#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h> 

using namespace std;

void printPairs(vector<vector<string>>);
vector<vector<string>> assignPairs(vector<vector<string>>);
int main()
{
	std::ifstream infile("secretsanta.csv");
	std::vector<vector<string>> families, orderedFamilies, pairs;
	string holder = "";
	//read in the csv of participants and families.
	while (infile.good())
	{
		vector<string> temp;
		char flag = 'a';
		while (infile.get(flag))
		{
			if (flag == '\n')
			{
				temp.push_back(holder);
				holder = "";
				break;
			}
			if (flag == ',')
			{
				temp.push_back(holder);
				holder = "";
			}
			else
			holder += flag;
		}
		if (holder.compare("") != 0)
			temp.push_back(holder);
		families.push_back(temp);
	}
	//sort the vector based on the size of the families
	for (int i = 0; i < families.size();i=i)
	{
		int y = 0, z = 0;
		for (int x = 0; x < families.size(); x++)
		{
			if (families[x].size() > y)
			{
				y = families[x].size();
				z = x;
			}
		}
		orderedFamilies.push_back(families[z]);
		families.erase(families.begin()+z);
	}
	pairs = assignPairs(orderedFamilies);
	printPairs(pairs);
}

void printPairs(vector<vector<string>> pairs)
{
	for (int i = 0; i < pairs.size(); i++)
	{
		cout << pairs[i][0] << "-->" << pairs[i][1] << endl;
	}
}

vector<vector<string>> assignPairs(vector<vector<string>> orderedFamilies)
{
	vector<vector<string>> copy = orderedFamilies;
	vector<vector<string>> pairs;
	for (int i = 0; i < orderedFamilies.size(); i++)
	{
		vector<string> temp;
		for (int x = 0; x < orderedFamilies[i].size(); x++)
		{
			if (i + 1 > copy.size())
			{
				temp.push_back(orderedFamilies[i][x]);
				temp.push_back(orderedFamilies[0][0]);
			}
			int y = rand() % copy.size(), z = rand() % copy[i + 1].size();
			temp.push_back(orderedFamilies[i][x]);
			temp.push_back(copy[y][z]);
			copy[y].erase(copy[y].begin() + z);
			pairs.push_back(temp);
			temp.clear();
		}
	}



	return pairs;
}
