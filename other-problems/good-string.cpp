// good string - adobe mock hackathon

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "you#k ##orare ###olomy frnd";
	int len = s.length();
	int c = 0;
	for (int i = 0; i < len; i++)
	{
		if (c == 0 && s[i] != '#' && s[i] != '*' && s[i] != '$')
		{
			cout << s[i];
			continue;
		}
		if (s[i] == '#' || s[i] == '$' || s[i] == '*')
		{
			c++;
			continue;
		}
		c--;
	}
}
