#include <cstdio>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;
complex <int> X,B;
int a[110];
int sqr(int x)
{
    return(x*x);
}
int calc()
{
    int len=sqr(B.real())+sqr(B.imag());
    int limit=int(sqrt(double(len)));
    if (sqr(limit)==len)
        limit--;
    for (int i=0;i<=100;i++)
    {
        bool flag=false;
        for (int j=0;j<=limit;j++)
        {
            complex <int> tmp=X;
            tmp.real()-=j;
            tmp=tmp*conj(B);
            if (tmp.real()%len==0 && tmp.imag()%len==0)
            {
                X=tmp/len;
                a[i]=j;
                flag=true;
                break;
            }
        }
        if (!flag)
            return(-1);
        if (abs(X)==0)
            return(i);
    }
    return(-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&X.real(),&X.imag(),&B.real(),&B.imag());
        int n=calc();
        if (n==-1)
            printf("The code cannot be decrypted.\n");
        else
            for (int i=n;i>=0;i--)
                printf("%d%c",a[i],i==0?'\n':',');
    }
    return(0);
}

