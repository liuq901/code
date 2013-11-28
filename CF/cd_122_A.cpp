#include <cstdio>
int a[1010];
void dfs(int x)
{
    if (x>1000)
        return;
    a[++a[0]]=x;
    dfs(x*10+4);
    dfs(x*10+7);
}
int main()
{
    dfs(4);
    dfs(7);
    int n;
    scanf("%d",&n);
    bool flag=false;
    for (int i=1;i<=a[0];i++)
        if (n%a[i]==0)
        {
            flag=true;
            break;
        }
    printf("%s\n",flag?"YES":"NO");
    return(0);
}

