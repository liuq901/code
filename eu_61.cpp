#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef int (*function)(int);
function f[10];
vector <int> a[10][100];
inline int Triangle(int n)
{
    return(n*(n+1)/2);
}
inline int Square(int n)
{
    return(n*n);
}
inline int Pentagonal(int n)
{
    return(n*(3*n-1)/2);
}
inline int Hexagonal(int n)
{
    return(n*(2*n-1));
}
inline int Heptagonal(int n)
{
    return(n*(5*n-3)/2);
}
inline int Octagonal(int n)
{
    return(n*(3*n-2));
}
int c[10];
bool dfs(int first,int now,int sum,int dep)
{
    if (dep==8)
    {
        for (int i=0;i<a[c[8]][now].size();i++)
            if (a[c[8]][now][i]==first)
            {
                sum+=now*100+first;
                printf("%d\n",sum);
                return(true);
            }
        return(false);
    }
    for (int i=0;i<a[c[dep]][now].size();i++)
    {
        int x=a[c[dep]][now][i];
        if (dfs(first,x,sum+now*100+x,dep+1))
            return(true);
    }
    return(false);
}
int main()
{
    f[3]=Triangle;
    f[4]=Square;
    f[5]=Pentagonal;
    f[6]=Hexagonal;
    f[7]=Heptagonal;
    f[8]=Octagonal;
    for (int i=3;i<=8;i++)
        for (int j=1;;j++)
        {
            int x=f[i](j);
            if (x>=10000)
                break;
            if (x>=1000)
                a[i][x/100].push_back(x%100);
        }
    for (int i=3;i<=8;i++)
        c[i]=i;
    while (1)
    {
        for (int i=10;i<100;i++)
            if (dfs(i,i,0,3))
                goto last;
        next_permutation(c+3,c+9);
    }
last:
    return(0);
}

