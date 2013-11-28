#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string a[210];
char buf[10000];
int n,p[210][210],f[110][110][2];
void init()
{
    for (int i=1;i<=2*n;i++)
        for (int j=1;j<=2*n;j++)
            for (int k=0;k<=7;k++)
            {
                if ((i<=n && j<=n || i>n && j>n) && k==0)
                    continue;
                bool flag=true;
                for (int q=0;q<7;q++)
                {
                    if (k+q==7)
                        break;
                    if (a[i][k+q]!=a[j][q])
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag)
                {
                    p[i][j]=k;
                    break;
                }
            }
}
void dp()
{
    memset(f,63,sizeof(f));
    int inf=f[0][0][0];
    for (int i=1;i<=n;i++)
        f[i-1][n-i][0]=f[i-1][n-i][1]=7;
    for (int i=n;i>=0;i--)
        for (int j=n;j>=0;j--)
            for (int k=0;k<=1;k++)
            {
                if (f[i][j][k]==inf)
                    continue;
                if (k==0)
                {
                    if (i>0)
                        f[i-1][j][0]=min(f[i-1][j][0],f[i][j][0]+p[i][i+1]);
                    if (j>0)
                        f[i][j-1][1]=min(f[i][j-1][1],f[i][j][0]+p[n-j+1+n][i+1]);
                }
                else
                {
                    if (i>0)
                        f[i-1][j][0]=min(f[i-1][j][0],f[i][j][1]+p[i][n-j+n]);
                    if (j>0)
                        f[i][j-1][1]=min(f[i][j-1][1],f[i][j][1]+p[n-j+1+n][n-j+n]);
                }
            }
}
string ret[110][110][2];
bool vis[110][110][2];
string get(int i,int j,int op)
{
    if (vis[i][j][op])
        return(ret[i][j][op]);
    vis[i][j][op]=true;
    if (i+j==n-1)
        ret[i][j][op]=op==0?a[i+1]:a[i+1+n];
    else if (op==0)
    {
        string s1,s2;
        s1=s2=char('z'+1);
        if (f[i][j][0]==f[i+1][j][0]+p[i+1][i+2])
            s1=a[i+1].substr(0,p[i+1][i+2])+get(i+1,j,0);
        if (f[i][j][0]==f[i+1][j][1]+p[i+1][n-j+n])
            s2=a[i+1].substr(0,p[i+1][n-j+n])+get(i+1,j,1);
        ret[i][j][op]=min(s1,s2);
    }
    else
    {
        string s1,s2;
        s1=s2=char('z'+1);
        if (f[i][j][1]==f[i][j+1][0]+p[n-j+n][i+1])
            s1=a[n-j+n].substr(0,p[n-j+n][i+1])+get(i,j+1,0);
        if (f[i][j][1]==f[i][j+1][1]+p[n-j+n][n-j-1+n])
            s2=a[n-j+n].substr(0,p[n-j+n][n-j-1+n])+get(i,j+1,1);
        ret[i][j][op]=min(s1,s2);
    }
    return(ret[i][j][op]);
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            a[i]=buf;
        }
        for (int i=1;i<=n;i++)
        {
            a[i+n]=a[i];
            reverse(a[i+n].begin(),a[i+n].end());
        }
        init();
        dp();
        memset(vis,0,sizeof(vis));
        string ans;
        if (f[0][0][0]<f[0][0][1])
            ans=get(0,0,0);
        else if (f[0][0][0]>f[0][0][1])
            ans=get(0,0,1);
        else
            ans=min(get(0,0,0),get(0,0,1));
        string ans1=ans;
        ans.erase(ans.size()-1);
        reverse(ans1.begin(),ans1.end());
        printf("%s%s\n",ans.c_str(),ans1.c_str());
    }
    return(0);
}

