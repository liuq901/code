#include <cstdio>
char buf[1000];
void dfs(int left,int right,int n)
{
    if (left==n && right==n)
    {
        printf("%s\n",buf);
        return;
    }
    if (left<n)
    {
        buf[left+right]='(';
        dfs(left+1,right,n);
    }
    if (left>right)
    {
        buf[left+right]=')';
        dfs(left,right+1,n);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        buf[2*n]='\0';
        dfs(0,0,n);
        printf("\n");
    }
    return(0);
}

