#include <cstdio>
#include <cstring>
char c[]="good mornin";
int a[260];
char s[1000000];
int calc()
{
    if (a['g']==0)
        return(0);
    a['g']--;
    int m=strlen(c),ret=0;
    while (1)
    {
        for (int i=0;i<m;i++)
        {
            if (a[c[i]]==0)
                return(ret);
            a[c[i]]--;
        }
        ret++;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        int len=strlen(s);
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++)
            a[s[i]]++;
        static int id=0;
        printf("Case #%d: %d\n",++id,calc());
    }
    return(0);
}

