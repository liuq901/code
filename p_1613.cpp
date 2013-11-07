#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
char s[10000];
bool in[60];
int b[60],d[60],a[1010][3];
vector <int> c[1010];
queue <int> Q;
int main()
{
    int n,m,S,T;
    while (scanf("%d%d%d%d",&n,&m,&S,&T)==4)
    {
        gets(s);
        memset(b,0,sizeof(b));
        memset(d,63,sizeof(d));
        int inf=d[0];
        for (int i=1;i<=m;i++)
        {
            gets(s);
            stringstream sin(s);
            int x,y,z;
            sin>>x>>y>>z;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
            c[i].clear();
            c[i+m].clear();
            c[i].push_back(0);
            c[i+m].push_back(0);
            while (sin>>x)
            {
                c[i].push_back(x);
                c[i+m].push_back(x);
            }
            if (c[i].size()%2==1)
            {
                c[i].push_back(inf);
                c[i+m].push_back(inf);
            }
        }
        in[S]=true;
        d[S]=0;
        Q.push(S);
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            in[x]=false;
            for (int i=b[x];i;i=a[i][2])
            {
                int y=a[i][0];
                for (int j=0;j<c[i].size();j+=2)
                {
                    int l=c[i][j],r=c[i][j+1];
                    if (max(l,d[x])+a[i][1]<d[y] && max(l,d[x])+a[i][1]<=r)
                    {
                        d[y]=max(l,d[x])+a[i][1];
                        if (!in[y])
                        {
                            in[y]=true;
                            Q.push(y);
                        }
                    }
                }
            }
        }
        if (d[T]==inf)
            printf("*\n");
        else
            printf("%d\n",d[T]);
    }
    return(0);
}

