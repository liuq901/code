#include <cstdio>
#include <cstring>
int n,a[100010],c[100010];
int get(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
void add(int x)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]++;
}
int work()
{
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(c,0,sizeof(c));
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        ret=ret+get(a[i])&1;
        add(a[i]);
    }
    return(ret);
}
int main()
{
    scanf("%d",&n);
    int x=work(),y=work();
    printf("%s\n",x==y?"Possible":"Impossible");
    return(0);
}

