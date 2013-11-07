#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct state
{
    int i,j,ch;
    state(int i,int j,int ch):i(i),j(j),ch(ch){}
};
char S[110],T[110],c[110][110];
int g[110][110],f[110][110][30];
bool in[110][110][30];
queue <state> q;
int main()
{
    while (scanf("%s%s",S+1,T+1)==2)
    {
        int n=strlen(S+1);
        for (int i=1;i<=n;i++)
        {
            c[i][i]=S[i];
            for (int j=i+1;j<=n;j++)
            {
                if (S[j]!=S[i] || c[i][j-1]==' ')
                {
                    c[i][j]=' ';
                    continue;
                }
                c[i][j]=S[i];
            }
        }
        memset(f,63,sizeof(f));
        for (int i=1;i<=n;i++)
            for (int j=0;j<26;j++)
            {
                f[i][i][j]=T[i]!=j+'a';
                q.push(state(i,i,j));
                in[i][i][j]=true;
            }
        while (!q.empty())
        {
            state now=q.front();
            q.pop();
            int i=now.i,j=now.j,ch=now.ch;
            in[i][j][ch]=false;
            for (int k=0;k<26;k++)
                if (f[i][j][ch]+1<f[i][j][k])
                {
                    f[i][j][k]=f[i][j][ch]+1;
                    if (!in[i][j][k])
                    {
                        in[i][j][k]=true;
                        q.push(state(i,j,k));
                    }
                }
            if (i>1 && T[i-1]==ch+'a')
            {
                for (int k=1;k<i;k++)
                    if (f[k][i-1][ch]+f[i][j][ch]<f[k][j][ch])
                    {
                        f[k][j][ch]=f[k][i-1][ch]+f[i][j][ch];
                        if (!in[k][j][ch])
                        {
                            in[k][j][ch]=true;
                            q.push(state(k,j,ch));
                        }
                    }
            }
            if (j<n && T[j+1]==ch+'a')
                for (int k=j+1;k<=n;k++)
                    if (f[i][j][ch]+f[j+1][k][ch]<f[i][k][ch])
                    {
                        f[i][k][ch]=f[i][j][ch]+f[j+1][k][ch];
                        if (!in[i][k][ch])
                        {
                            in[i][k][ch]=true;
                            q.push(state(i,k,ch));
                        }
                    }
        }
        memset(g,63,sizeof(g));
        for (int i=n;i;i--)
            for (int j=i;j<=n;j++)
            {
                if (i==j)
                {
                    g[i][j]=S[i]!=T[i];
                    continue;
                }
                for (int k=0;k<26;k++)
                    g[i][j]=min(g[i][j],f[i][j][k]+(c[i][j]!=k+'a'));
                for (int k=i;k<j;k++)
                    g[i][j]=min(g[i][j],g[i][k]+g[k+1][j]);
            }
        printf("%d\n",g[1][n]);
    }
    return(0);
}

