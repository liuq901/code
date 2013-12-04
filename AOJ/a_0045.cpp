#include <cstdio>
int main()
{
    int sum,n,x,y,cnt;
    sum=n=cnt=0;
    while (scanf("%d,%d",&x,&y)==2)
    {
        sum+=x*y;
        n+=y;
        cnt++;
    }
    printf("%d\n%.0f\n",sum,double(n)/cnt+1e-12);
    return(0);
}

