#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string s[20][3];
int a[20],p[20];
char buf[100000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<3;j++)
        {
            scanf("%s",buf);
            s[i][j]=buf;
        }
        sort(s[i],s[i]+3);
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    p[a[1]]=0;
    for (int i=2;i<=n;i++)
    {
        p[0]=-1;
        for (int j=0;j<3;j++)
            if (s[a[i]][j]>s[a[i-1]][p[i-1]])
            {
                p[i]=j;
                p[0]=1;
                break;
            }
        if (p[0]==-1)
            break;
    }
    if (p[0]==-1)
        printf("IMPOSSIBLE\n");
    else
        for (int i=1;i<=n;i++)
            printf("%s\n",s[a[i]][p[i]].c_str());
    return(0);
}

