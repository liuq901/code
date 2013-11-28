#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int e[210][2][210][2];
ll f[2][210][210];
struct GameOfLifeDivOne
{
    string s;
    ll theCount(string init,int T,int K)
    {
        s=init+init;
        memset(e,-1,sizeof(e));
        for (int i=0;i<=s.size();i++)
            for (int j=i+1;j<=s.size();j++)
                for (int x=0;x<=1;x++)
                    for (int y=0;y<=1;y++)
                    {
                        if ((j-i)%2==(x+y)%2)
                            continue;
                        bool flag=true;
                        for (int k=i;k<j;k++)
                        {
                            if ((k-i)%2==0 && s[k]==(x^1)+'0')
                            {
                                flag=false;
                                break;
                            }
                            if ((k-i)%2==1 && s[k]==x+'0')
                            {
                                flag=false;
                                break;
                            }
                        }
                        if (!flag)
                            continue;
                        if (x==0 && y==0)
                            e[i][x][j][y]=max((j-i)/2-T,0);
                        else if (x==1 && y==1)
                            e[i][x][j][y]=min(j-i,(j-i+1)/2+T);
                        else
                            e[i][x][j][y]=(j-i)/2;
                    }
        ll ans=0;
        int n=s.size()/2;
        if (K<=n/2)
        {
            ans+=e[0][0][n][1]!=-1;
            ans+=e[0][1][n][0]!=-1;
        }
        for (int i=0;i<n;i++)
            for (int t=0;t<=1;t++)
            {
                memset(f,0,sizeof(f));
                f[t][i][0]=1;
                for (int j=i;j<i+n;j++)
                    for (int x=0;x<=1;x++)
                        for (int k=0;k<=n;k++)
                        {
                            if (f[x][j][k]==0)
                                continue;
                            for (int p=j+1;p<=i+n;p++)
                                for (int y=0;y<=1;y++)
                                    if (e[j][x][p][y]!=-1 && (p<n || p==i+n && j<n))
                                        f[y][p][k+e[j][x][p][y]]+=f[x][j][k];
                        }
                for (int j=K;j<=n;j++)
                    ans+=f[t][i+n][j];
            }
        return(ans);
    }
};
int main(){}

