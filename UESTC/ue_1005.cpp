#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int a[2][100];
char buf[100000];
string tmp[100];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        gets(buf);
        memset(a,-1,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            gets(buf);
            stringstream sin(buf);
            string name;
            int n=0;
            while (sin>>name)
                tmp[++n]=name;
            if (n>2 && tmp[n]=="good" && tmp[n-1]=="no")
                a[i&1][i+1>>1]=0;
            else
                a[i&1][i+1>>1]=1;
        }
        int tot=n+1>>1;
        for (int i=1;i<=tot;i++)
            printf("%d ",i);
        printf("Score\n");
        for (int i=1;i>=0;i--)
        {
            for (int j=1;j<=tot;j++)
                if (a[i][j]==1)
                    printf("O ");
                else if (a[i][j]==0)
                    printf("X ");
                else
                    printf("- ");
            printf("%d\n",count(a[i]+1,a[i]+tot+1,1));
        }
    }
    return(0);
}

