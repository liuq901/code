#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[110],b[110];
int na[110][26],nb[110][26],f[110][110];
void calc(int n,char a[],int next[][26])
{
    for (int i=n;i;i--)
    {
        for (int j=0;j<26;j++)
            next[i][j]=next[i+1][j];
        next[i][a[i]-'a']=i;
    }
}
void print(int n,int m)
{
    if (f[n][m]==0)
        return;
    for (int i=0;i<26;i++)
    {
        int x=na[n][i],y=nb[m][i];
        if (x==-1 || y==-1)
            continue;
        if (f[n][m]==f[x+1][y+1]+1)
        {
            printf("%c",i+'a');
            print(x+1,y+1);
            return;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        memset(na,-1,sizeof(na));
        memset(nb,-1,sizeof(nb));
        calc(n,a,na);
        calc(m,b,nb);
        memset(f,0,sizeof(f));
        for (int i=n;i;i--)
            for (int j=m;j;j--)
            {
                f[i][j]=max(f[i+1][j],f[i][j+1]);
                if (a[i]==b[j])
                    f[i][j]=max(f[i][j],f[i+1][j+1]+1);
            }
        static int id=0;
        printf("Case %d: ",++id);
        if (f[1][1]==0)
            printf(":(");
        else
            print(1,1);
        printf("\n");
    }
    return(0);
}

