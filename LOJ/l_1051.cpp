#include <cstdio>
#include <cstring>
const char ans[][10]={"GOOD","BAD","MIXED"};
inline bool vowel(char ch)
{
    return(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
}
char a[60];
int n,f[60][10][10];
int dp(int x,int v,int c)
{
    if (f[x][v][c]!=-1)
        return(f[x][v][c]);
    int &ret=f[x][v][c];
    if (v==3 || c==5)
        ret=1;
    else if (x==n+1)
        ret=0;
    else if (a[x]=='?')
    {
        int u=dp(x+1,v+1,0),v=dp(x+1,0,c+1);
        if (u==2 || v==2 || u!=v)
            ret=2;
        else
            ret=u;
    }
    else if (vowel(a[x]))
        ret=dp(x+1,v+1,0);
    else
        ret=dp(x+1,0,c+1);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        n=strlen(a+1);
        static int id=0;
        memset(f,-1,sizeof(f));
        printf("Case %d: %s\n",++id,ans[dp(1,0,0)]);
    }
    return(0);
}

