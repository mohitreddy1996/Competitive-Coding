#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
/*
long long modular_pow(long long base, long long exponent, int modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}


int solve()
{
      ....
      Base Cases
      ....
      if ( DP[i][j] is calculated) // Already calculated so just reuse
               return DP[i][j];
      else // Calculate DP[i][j] and return it
           put recurrence algo
           DP[i][j] = ans of recurrence algo 
           return DP[i][j]
}

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}



int visited[200000]
vector <int> list[200000]
void bfs(int i)
{
	queue <int> q;
	q.push(i);
	visited[i]=1;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int j=0;j<list[k].size();j++)
		{
			if(visited[list[k][j]]==0)
			{
				q.push(list[k][j]);
				visited[list[k][j]]=1;
			}
		}
	}
}


struct node
{
    int v,dist;
    node(){}
    node(int _v,int _dist)
    {
        v=_v,dist=_dist;
    }
}aux;

#define MAX 10000
bool visited[MAX];
vector <int> L[MAX];
node search(int v)
{
    node ans=node(v,0);
    queue<node> q;
    q.push(node(v,0));
    
    memset(visited,false,sizeof(visited));
    visited[v]=true;
    
    while(!q.empty())
    {
        aux=q.front();
        q.pop();
        
        ans=aux;
        
        for(int i=L[aux.v].size()-1;i>=0;i--)
        {
            if(visited[L[aux.v][i]])   continue;
            visited[L[aux.v][i]]=true;
            q.push(node(L[aux.v][i],aux.dist+1));
        }
    }
    return ans;
    
}
*/
/*
void dfs(int i)
{
    stack<int> s;
    s.push(i);
    while(s.empty()==false)
    {
        int k=s.top();
        s.pop();
        if(visited[k]==false)
            visited[k]=true;
        else
        {
            continue;
        }
            for(int j=0;j<List[k].size();j++)
            {
                if(visited[List[k][j]==false)
                    visited[List[k][j]]=true;
                else
                    continue;
                s.push(List[k][j]);    
            }
    }
}
*/
#define pii pair<int,int>
struct comp
{
    bool operator() (const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.second>b.second;
    }
};


int distance1[102];
bool color[102];
vector<pii> v[102];

void dijkstra(int a,int n)
{
    priority_queue<pii,vector<pii>,comp> q;
    for(int i=0;i<=n+1;i++)
    {
        distance1[i]=100000;
        color[i]=false;
    }
    distance1[a]=0;
    q.push(pii(a,distance1[a]));
    while(q.empty()==false)
    {
        int l=q.top().first;
        q.pop();
        if(color[l])
            continue;
        for(int i=0;i<v[l].size();i++)
        {
            int j=v[l][i].first;
            int d=v[l][i].second;
            if(!color[j] && distance1[j] > distance1[l]+d)
            {
                distance1[j]=distance1[l]+d;
                q.push(pii(j,distance1[j]));
            }
        }
        color[l]=true;
    }
}


int main()
{
    int n,a,b,m;
    scanf("%d %d %d %d",&n,&a,&b,&m);
    
    
    int x,y,z;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        v[x].push_back(pii(y,z));
    }
    
    int count=0;
    for(int i=1;i<=n;i++)
    {
        dijkstra(i,n);
        if(distance1[a]<=b)
            count++;
    }
    printf("%d\n",count);
    
    
    


return(0);    
}