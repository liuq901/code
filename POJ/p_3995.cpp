#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int ans,len,k,s[110];
char buf[110];
inline bool check()
{
    int state=0;
    for (int i=0;i<len;i++)
    {
        if (s[i]==0 && state==0)
            state=1;
        if (s[i]==1 && state==1)
            state=2;
        if (s[i]==0 && state==2)
            return(false);
    }
    return(true);
}
void dfs(int dep)
{
    if (dep>=ans)
        return;
    if (check())
    {
        ans=dep;
        return;
    }
    if (dep==10)
        return;
    if (k>0)
    {
        swap(s[k],s[k-1]);
        k--;
        dfs(dep+1);
        k++;
        swap(s[k],s[k-1]);
    }
    if (k<len-1)
    {
        swap(s[k],s[k+1]);
        k++;
        dfs(dep+1);
        k--;
        swap(s[k],s[k+1]);
    }
    if (k>1)
    {
        s[k-2]^=1;
        swap(s[k],s[k-2]);
        k-=2;
        dfs(dep+1);
        k+=2;
        swap(s[k],s[k-2]);
        s[k-2]^=1;
    }
    if (k<len-2)
    {
        s[k+2]^=1;
        swap(s[k],s[k+2]);
        k+=2;
        dfs(dep+1);
        k-=2;
        swap(s[k],s[k+2]);
        s[k+2]^=1;        
    }
}
int main()
{
    while (1)
    {
        scanf("%s",buf);
        if (buf[0]=='-')
            break;
        len=strlen(buf);
        for (int i=0;i<len;i++)
            if (buf[i]=='B')
                s[i]=0;
            else if (buf[i]=='W')
                s[i]=1;
            else
            {
                s[i]=2;
                k=i;
            }
        ans=20;
        dfs(0);
        if (ans==20)
            ans=-1;
        static int id=0;
        printf("%d. %d\n",++id,ans);
    }
    return(0);
}

