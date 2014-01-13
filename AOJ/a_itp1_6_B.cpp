#include <cstdio>
const char ans[]="SHCD";
bool f[4][60];
char a[260];
int main()
{
    for (int i=0;i<4;i++)
        a[ans[i]]=i;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char s[10];
        int x;
        scanf("%s%d",s,&x);
        f[a[s[0]]][x]=true;
    }
    for (int i=0;i<4;i++)
        for (int j=1;j<=13;j++)
            if (!f[i][j])
                printf("%c %d\n",ans[i],j);
    return(0);
}

