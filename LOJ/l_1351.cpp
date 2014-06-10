#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[2][70][70][70];
char a[70],b[70];
char get(int id,int l,int pos,int i)
{
    int delta=i-l;
    return(id?a[pos-delta]:a[pos+delta]);
}
bool same(int id,int l,int r,int pos)
{
    for (int i=l;i<=r;i++)
        if (get(id,l,pos,i)!=b[i])
            return(false);
    return(true);
}
int dp(int id,int l,int r,int pos)
{
    if (f[id][l][r][pos]!=-1)
        return(f[id][l][r][pos]);
    int &ret=f[id][l][r][pos];
    if (same(id,l,r,pos))
        ret=0;
    else
    {
        ret=1<<30;
        for (int i=l;i<=r;i++)
        {
            for (int j=r;j>=i;j--)
            {
                if (i!=l || j!=r)
                {
                    int delta=j-l;
                    ret=min(ret,dp(id^1,i,j,id?pos-delta:pos+delta)+1);
                }
                if (get(id,l,pos,j)!=b[j])
                    break;
            }
            if (get(id,l,pos,i)!=b[i])
                break;
        }
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1);
        static int id=0;
        printf("Case %d: ",++id);
        if (strcmp(a+1,b+1)==0)
            printf("0\n");
        else
        {
            int ans=1<<30;
            memset(f,-1,sizeof(f));
            for (int i=1;i<=n;i++)
            {
                for (int j=n;j>=i;j--)
                {
                    ans=min(ans,dp(1,i,j,j)+1);
                    if (a[j]!=b[j])
                        break;
                }
                if (a[i]!=b[i])
                    break;
            }
            if (ans==1<<30)
                printf("impossible\n");
            else
                printf("%d\n",ans);
        }
    }
    return(0);
}

