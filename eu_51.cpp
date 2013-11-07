#include <cstdio>
bool f[1000010];
int ans,len,ten[10];
void init()
{
    ten[0]=1;
    for (int i=1;i<=8;i++)
        ten[i]=ten[i-1]*10;
    for (int i=2;i<=1000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=1000000;j++)
            f[i*j]=true;
    }
}
int get(int n)
{
    int ret=0;
    while (n)
    {
        ret++;
        n/=10;
    }
    return(ret);
}
bool work(int n)
{
    int len=get(n),limit=1<<len;
    for (int i=0;i<limit;i++)
    {
        int m=n,t=0,ret=0;
        for (int j=0;j<len;j++)
            if (i>>j&1)
            {
                m-=m/ten[j]%10*ten[j];
                t+=ten[j];
            }
        for (int i=0;i<10;i++)
        {
            m+=t;
            if (get(m)==len && !f[m])
                ret++;
            if (ret==1 && m!=n)
                break;
        }
        if (ret==8)
            return(true);
    }
    return(false);
}
int main()
{
    init();
    for (int i=2;i;i++)
    {
        if (f[i])
            continue;
        if (work(i))
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

