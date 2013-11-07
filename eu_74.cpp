#include <cstdio>
#include <set>
#include <map>
using namespace std;
const int f[]={1,1,2,6,24,120,720,5040,40320,362880};
map <int,int> M;
int calc(int x)
{
    int sum=0;
    while (x)
    {
        sum+=f[x%10];
        x/=10;
    }
    return(sum);
}
int get(int n)
{
    set <int> s;
    while (1)
    {
        if (s.count(n))
            break;
        s.insert(n);
        if (!M.count(n))
            M[n]=calc(n);
        n=M[n];
    }
    return(s.size());
}
int main()
{
    int ans=0;
    for (int i=1;i<=1000000;i++)
        ans+=get(i)==60;
    printf("%d\n",ans);
    return(0);
}

