#include <cstdio>
#include <string>
using namespace std;
const string end="#CODE-END";
int a[1010],b[1010],f[1010][1010],pre[1010][1010];
char buf[300];
pair <int,int> now[1010][1010];
string s[1010],t[1010];
bool same[1010][1010];
void merge(int l1,int r1,int l2,int r2)
{
    if (l1>r1)
    {
        for (int i=l2;i<=r2;i++)
            printf("%s\n",t[i].c_str());
        return;
    }
    if (l2>r2)
    {
        for (int i=l1;i<=r1;i++)
            printf("%s\n",s[i].c_str());
        return;
    }
    printf("//**** CONFLICT STARTS ****//\n");
    printf("//code in A:\n");
    for (int i=l1;i<=r1;i++)
        printf("%s\n",s[i].c_str());
    printf("//code in B:\n");
    for (int i=l2;i<=r2;i++)
        printf("%s\n",t[i].c_str());
    printf("//***** CONFLICT ENDS *****//\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        int n=0,m=0;
        while (1)
        {
            gets(buf);
            s[++n]=buf;
            if (s[n]==end)
                break;
        }
        while (1)
        {
            gets(buf);
            t[++m]=buf;
            if (t[m]==end)
                break;
        }
        n--,m--;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                same[i][j]=s[i]==t[j];
        for (int i=1;i<=n;i++)
            f[i][m+1]=0;
        for (int i=1;i<=m;i++)
            f[n+1][i]=0;
        f[n+1][m+1]=0;
        for (int i=n;i;i--)
            for (int j=m;j;j--)
            {
                if (f[i+1][j]>f[i][j+1] || f[i+1][j]==f[i][j+1] && now[i+1][j]<now[i][j+1])
                {
                    f[i][j]=f[i+1][j];
                    pre[i][j]=0;
                    now[i][j]=now[i+1][j];
                }
                else
                {
                    f[i][j]=f[i][j+1];
                    pre[i][j]=1;
                    now[i][j]=now[i][j+1];
                }
                if (same[i][j] && f[i+1][j+1]+1>=f[i][j])
                {
                    f[i][j]=f[i+1][j+1]+1;
                    pre[i][j]=2;
                    now[i][j]=make_pair(i,j);
                }
            }
        int x=1,y=1,u=0,v=0;
        while (x<=n && y<=m)
        {
            if (pre[x][y]==2)
            {
                a[++u]=now[x][y].first;
                b[++v]=now[x][y].second;
            }
            if (pre[x][y]==0)
                x++;
            else if (pre[x][y]==1)
                y++;
            else
                x++,y++;
        }
        int K=f[1][1];
        a[0]=b[0]=0;
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=K;i++)
        {
            merge(a[i-1]+1,a[i]-1,b[i-1]+1,b[i]-1);
            printf("%s\n",s[a[i]].c_str());
        }
        merge(a[K]+1,n,b[K]+1,m);
        printf("\n");
    }
    return(0);
}

