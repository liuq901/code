#include <cstdio>
#include <cmath>
inline int sqr(int x)
{
    return(x*x);
}
int main()
{
    int ans=0;
    for (int i=1;;i++)
    {
        for (int j=1;j<=i;j++)
            for (int k=1;k<=j;k++)
            {
                int sum=sqr(i)+sqr(j+k),x=int(sqrt(sum+1e-8));
                if (x*x==sum)
                    ans++;
            }
        if (ans>1000000)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

