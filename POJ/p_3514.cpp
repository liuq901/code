#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int N=100010;
int writer[110],c[N],flag[N],a[N][110];
char buf[1000000];
map <string,int> M;
string s[N];
bool have[110],f[110][110];
int hash(const string &s)
{
    if (!M.count(s))
    {
        int p=M.size()+1;
        M[s]=p;
    }
    return(M[s]);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        gets(buf);
        M.clear();
        memset(a,0,sizeof(a));
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=m;i++)
        {
            gets(buf);
            int len=strlen(buf);
            buf[len]=' ';
            int x=-1;
            string tmp;
            for (int j=0;j<=len;j++)
            {
                if (!isalpha(buf[j]))
                {
                    if (tmp!="")
                    {
                        int p=hash(tmp);
                        tmp="";
                        if (x==-1)
                        {
                            x=p;
                            writer[i]=x;
                            flag[x]=i;
                        }
                        else
                            a[p][i]=1;
                    }
                    continue;
                }
                tmp+=buf[j];
            }
        }
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                f[i][j]=a[writer[i]][j];
        for (int k=1;k<=m;k++)
            for (int i=1;i<=m;i++)
                for (int j=1;j<=m;j++)
                    if (f[i][k] && f[k][j])
                        f[i][j]=true;
        int t=0;
        for (map <string,int>::iterator k=M.begin();k!=M.end();k++)
        {
            s[++t]=k->first;
            c[t]=k->second;
        }
        memset(have,0,sizeof(have));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]!=1)
                    continue;
                for (int k=1;k<=m;k++)
                    if (f[j][k] && a[i][k]==0 && writer[k]!=i)
                    {
                        a[i][k]=-1;
                        have[k]=true;
                    }
            }
        static int id=0;
        printf("--- CASE %d\n",++id);
        for (int i=1;i<=n;i++)
        {
            int x=c[i];
            if (!flag[x])
                continue;
            x=flag[x];
            if (!have[x])
                continue;
            printf("%s",s[i].c_str());
            for (int j=1;j<=n;j++)
            {
                int y=c[j];
                if (a[y][x]==-1)
                    printf(" %s",s[j].c_str());
            }
            printf("\n");
        }
    }
    return(0);
}

