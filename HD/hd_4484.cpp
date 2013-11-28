#include <cstdio>
#include <map>
using namespace std;
map <int,int> M;
int calc(int n)
{
    if (M.count(n))
        return(M[n]);
    if (n==1)
        M[n]=1;
    else if (n&1)
        M[n]=max(n,calc(3*n+1));
    else
        M[n]=max(n,calc(n>>1));
    return(M[n]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,n;
        scanf("%d%d",&id,&n);
        printf("%d %d\n",id,calc(n));
    }
    return(0);
}

