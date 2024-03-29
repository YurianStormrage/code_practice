#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
const int N = 102;
using namespace std;

int n,m,numm,numh;
int map[N][N],lx[N],ly[N],vx[N],vy[N],matchy_x[N],slack[N];
char s[N][N];
int abs(int a){return a<0?-a:a;}
int min(int a,int b) {return a<b?a:b;}

bool hungary(int u)
{
	int i;
	vx[u]=1;
	for(i=0;i<numm;i++)
	{
		if(vy[i]) continue;
		if(map[u][i]==lx[u]+ly[i])
		{
		    vy[i]=1;
            if(matchy_x[i]==-1 || hungary(matchy_x[i]))
            {
                matchy_x[i]=u;
                return  1;
            }
		}
		else slack[i]=min(slack[i],lx[u]+ly[i]-map[u][i]);
	}
	return 0;
}

void EK_match()
{
	int i,j;
	for(i=0;i<numm;i++)
	{
		int maxx=0;
		for(j=0;j<numh;j++)
	 		if(map[i][j]>maxx) maxx=map[i][j];
		lx[i]=maxx;
	}
	for(i=0;i<numm;i++)
	{
	    memset(slack,127,sizeof(slack));
		while(1)
		{
			memset(vx,0,sizeof(vx));
			memset(vy,0,sizeof(vy));
			if(hungary(i))
				break;
			else
			{
				int temp=INT_MAX;
				for(j=0;j<numm;j++) if(!vy[j])
					if(temp>slack[j])   temp=slack[j];
				for(j=0;j<numm;j++)
				{
					if(vx[j]) lx[j]-=temp;
					if(vy[j]) ly[j]+=temp;
					else slack[j]-=temp;
				}
			}
		}
	}
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF && (n||m))
	{
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		numm=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='m')
				{
					numh=0;
					for(int k=0;k<n;k++)
					{
						for(int l=0;l<m;l++)
						{
							if(s[k][l]=='H')
							map[numm][numh++]=300-(abs(i-k)+abs(j-l));
						}
					}
					numm++;
				}
			}
		}
		memset(matchy_x,-1,sizeof(matchy_x));
		EK_match();
		int ans=0;
		for(i=0;i<numm;i++)
			ans+=(300-map[matchy_x[i]][i]);
		printf("%d\n",ans);
	}
	return 0;
}