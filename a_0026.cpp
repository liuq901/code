#include <cstdio>
#include <algorithm>
using namespace std;
int a[10][10];
void fill(int x,int y)
{
    if (x>=0 && x<10 && y>=0 && y<10)
        a[x][y]++;
}
int main()
{
    int x,y,z;
    while (scanf("%d,%d,%d",&x,&y,&z)==3)
    {
        fill(x,y);
        fill(x-1,y);
        fill(x,y-1);
        fill(x+1,y);
        fill(x,y+1);
        if (z>=2)
        {
            fill(x+1,y+1);
            fill(x+1,y-1);
            fill(x-1,y+1);
            fill(x-1,y-1);
        }
        if (z==3)
        {
            fill(x-2,y);
            fill(x+2,y);
            fill(x,y-2);
            fill(x,y+2);
        }
    }
    int ans,sum;
    ans=sum=0;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
        {
            ans=max(ans,a[i][j]);
            sum+=a[i][j]==0;
        }
    printf("%d\n%d\n",sum,ans);
    return(0);
}

