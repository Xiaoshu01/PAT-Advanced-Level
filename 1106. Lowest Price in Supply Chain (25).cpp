#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,cnt,mindepth=0x7fffffff;
double p,r; 
vector<vector<int>> v;
void dfs(int r,int depth)
{
	if(v[r].size()==0)
	{
		if(depth==mindepth) cnt++;
		else if(depth<mindepth) cnt=1,mindepth=depth;
	}
	for(auto x:v[r]) dfs(x,depth+1);
}
int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		int k,idx;
		scanf("%d",&k);
		for(int j=0;j<k;++j)
		{
			scanf("%d",&idx);
			v[i].push_back(idx);
		}
	}
	dfs(0,0);
	printf("%.4lf %d",p*pow((1+r*0.01),mindepth),cnt);
	return 0;
}
