#include <cstdio>
#include <string>
using namespace std;
string s[100];
char buf[1000000];
int m,a[210][3];
bool final[210];
inline int clear(int x)
{
    a[x][0]=a[x][1]=a[x][2]=-1;
    final[x]=true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        n++;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            s[i]=buf;
        }
        clear(m=0);
        for (int i=0;i<s[n].size();i++)
        {
            int x=s[n][i]-'a';
            clear(++m);
            a[i][x]=m;
        }
        final[m]=false;
        clear(++m);
        for (int i=0;i<=m;i++)
            for (int j=0;j<3;j++)
                if (a[i][j]==-1)
                    a[i][j]=m;
        printf("%d\n",m+1);
        for (int i=0;i<=m;i++)
            printf("%d %d %d %d %d\n",i,a[i][0],a[i][1],a[i][2],final[i]);
        printf("\n");
    }
    return(0);
}

