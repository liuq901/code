#include <cstdio>
#include <cstring>
int sg[110][3][3];
int calc(int len,int l,int r)
{
    if (sg[len][l][r]!=-1)
        return(sg[len][l][r]);
    bool vis[110]={0};
    for (int i=1;i<=len;i++)
        for (int j=0;j<2;j++)
        {
            if (i==1 && j==l || i==len && j==r)
                continue;
            vis[calc(i-1,l,j)^calc(len-i,j,r)]=true;
        }
    for (int i=0;;i++)
        if (!vis[i])
            return(sg[len][l][r]=i);
}
char s[110];
int main()
{
    memset(sg,-1,sizeof(sg));
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int n=strlen(s),cnt=0,pos=0,kind=2,ans=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='.')
                continue;
            cnt++;
            ans^=calc(i-pos,kind,s[i]=='O');
            pos=i+1,kind=s[i]=='O';
        }
        ans^=calc(n-pos,kind,2);
        static int id=0;
        printf("Case %d: %s\n",++id,cnt%2==0 && ans || cnt%2==1 && !ans?"Yes":"No");
    }
    return(0);
}

