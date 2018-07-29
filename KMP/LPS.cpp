#include<iostream>
#include<vector>

using namespace std;

int gBuildLPS(string& xPattern) 
{
	vector<int> xLPS(xPattern.size(), 0);
	int i = 0, j =1;
	int lMax = 0;
	while(j < xPattern.size()) 
	{
		if (xPattern[i] == xPattern[j]) 
		{
			i++;
				xLPS[j] = i;
				//cout<<j<<" = "<<i<<endl;	
				//if (i > lMax) 
				//	lMax = i;
			j++;
		}
		else 
		{
			// Mismatch 
			if (i > 0) 
			{
				i = xLPS[i-1];
			}
			else 
			{
				xLPS[j] = 0;
				j++;
			}
		}
	}
	return xLPS.back();
}


int main () 
{	
	std::ios::sync_with_stdio(false);
	int lTestcase;
	cin>> lTestcase;
	vector<int> lResult;	
	for (int i = 0; i < lTestcase; i++) 
	{
		string lPattern;
		cin>>lPattern;
		lResult.push_back(gBuildLPS(lPattern));
	}
	for (auto v:lResult) 
		cout<<v<<"\n";	
}
