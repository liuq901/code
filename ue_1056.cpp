#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
char s[210];
int f[210][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        f[0][0]=0;
        f[0][1]=1<<30;
        for (int i=1;i<=n;i++)
            if (isupper(s[i]))
            {
                f[i][0]=min(f[i-1][0]+1,f[i-1][1]+1);
                f[i][1]=min(f[i-1][1],f[i-1][0]+1);
            }
            else
            {
                f[i][0]=min(f[i-1][0],f[i-1][1]+1);
                f[i][1]=min(f[i-1][0]+1,f[i-1][1]+1);
            }
        printf("%d\n",min(f[n][0],f[n][1])+n);
    }
    return(0);
}

