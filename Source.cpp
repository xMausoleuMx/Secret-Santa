#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	std::ifstream infile("secretsanta.csv");
	std::vector<vector<string>> families;
	string holder = "";
	int x = 0;
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
			if (!infile.good())
			{
				temp.push_back(holder);
				break;
			}
			else
			holder += flag;
		}
		families.push_back(temp);
		cout << families[x][0] << endl;
		x++;
	}
	//sort the vector based on the size of the families
	//for (int i = 0; i < families.size(); i++)
	{


	}


}