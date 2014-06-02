#include <cstdio>
typedef long long ll;
int N,C;
ll f(int T)
{
    return(ll(T)*C-ll(T)*T*N);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&N,&C);
        static int id=0;
        printf("Case %d: ",++id);
        if (N==0)
            printf("0\n");
        else
        {
            int mid=C/(2*N),upper=C/N;
            int best=0;
            if (mid<=upper && f(mid)>f(best))
                best=mid;
            if (mid+1<=upper && f(mid+1)>f(best))
                best=mid+1;
            if (f(upper)>f(best))
                best=upper;
            printf("%d\n",best);
        }
    }
    return(0);
}

