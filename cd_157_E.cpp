#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int f[110][2700];
char s[110];
void init()
{
    int n=100,tot=2600;
    for (int i=1;i<=min(26,tot);i++)
        f[1][i]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=tot;j++)
            for (int k=1;k<=min(26,j);k++)
                f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int n=strlen(s),tot=0;
        for (int i=0;i<n;i++)
            tot+=s[i]-'a'+1;
        printf("%d\n",(f[n][tot]-1+mod)%mod);
    }
    return(0);
}

