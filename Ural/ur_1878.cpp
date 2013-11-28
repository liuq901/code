#include <cstdio>
#include <algorithm>
using namespace std;
const int f[4]={0,1,1,2};
const int belong[4][4]={{0,0,1,1},{0,0,1,1},{2,2,3,3},{2,2,3,3}};
int a[10];
int main()
{
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            int x;
            scanf("%d",&x);
            a[x]+=f[belong[i][j]];
        }
    printf("%d\n",*min_element(a+1,a+5));
    return(0);
}

