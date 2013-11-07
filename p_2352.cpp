#include <cstdio>
const int maxn=32005;
int N,ans[15010],Tree[maxn+10];
inline int lowbit(int x)
{
    return(x&-x);
}
void add(int x,int value)
{
    for (int i=x;i<=N;i+=lowbit(i))
        Tree[i]+=value;
}
int get(int x)
{
    int sum=0;
    for (int i=x;i;i-=lowbit(i))
        sum+=Tree[i];
    return(sum);
}
int main()
{
    N=maxn;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%*d",&x);
        x++;
        add(x,1);
        ans[get(x)]++;
    }
    for (int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return(0);
}

