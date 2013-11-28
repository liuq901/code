#include <cstdio>
typedef long long ll;
inline bool check(int n,int x)
{
    return(ll(n)*x%(x-n)==0);
}
int main()
{
    for (int i=1;;i++)
    {
        int num=0;
        for (int j=i+1;j<=2*i;j++)
            if (check(i,j))
            {
                num++;
                if (num==1000)
                {
                    printf("%d\n",i);
                    goto out;
                }
            }
    }
out:
    return(0);
}

