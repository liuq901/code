#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string a[210],s[210][110];
char buf[1000000];
int f[210][110],b[210][110][110];
bool vis[210][110];
void work(const string &s,const string &t,int i,int j,int k)
{
    for (int p=0;p<s.size() && p<t.size();p++)
    {
        b[i][(j+p)%s.size()][k]=min(b[i][(j+p)%s.size()][k],int(s.size()-p));
        if (s[p]!=t[p])
            return;
    }
    b[i][j][k]=0;
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        gets(buf);
        int len=strlen(buf),n=0;
        string tmp;
        for (int i=0;i<len;i++)
        {
            if (buf[i]==';')
            {
                a[++n]=tmp;
                tmp="";
                continue;
            }
            tmp+=buf[i];
        }
        a[++n]=tmp;
        memset(b,63,sizeof(b));
        for (int i=1;i<=n;i++)
            for (int j=0;j<a[i].size();j++)
            {
                s[i][j]="";
                for (int k=j;k<a[i].size();k++)
                    s[i][j]+=a[i][k];
                for (int k=0;k<j;k++)
                    s[i][j]+=a[i][k];
            }
        for (int i=1;i<n;i++)
            for (int j=0;j<a[i].size();j++)
                for (int k=0;k<a[i+1].size();k++)
                    work(s[i][j],s[i+1][k],i,j,k);
        memset(f,63,sizeof(f));
        memset(vis,0,sizeof(vis));
        for (int i=0;i<a[n].size();i++)
        {
            f[n][i]=a[n].size();
            vis[n][i]=true;
        }
        for (int i=n;i>1;i--)
            for (int j=0;j<a[i].size();j++)
                for (int k=0;k<a[i-1].size();k++)
                    f[i-1][k]=min(f[i-1][k],f[i][j]+b[i-1][k][j]);
        int ans=1<<30;
        for (int i=0;i<a[1].size();i++)
            ans=min(ans,f[1][i]);
        string S;
        int p;
        for (int i=0;i<a[1].size();i++)
            if (ans==f[1][i] && (S=="" || s[1][i]<S))
            {
                S=s[1][i];
                p=i;
            }
        for (int i=2;i<=n;i++)
        {
            S="";
            int t;
            for (int j=0;j<a[i].size();j++)
                if (f[i-1][p]==f[i][j]+b[i-1][p][j] && (S=="" || s[i][j]<S))
                {
                    S=s[i][j];
                    t=j;
                }
            printf("%s",s[i-1][p].substr(0,b[i-1][p][t]).c_str());
            p=t;
        }
        printf("%s\n",s[n][p].c_str());
    }
    return(0);
}

