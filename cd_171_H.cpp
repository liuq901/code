#include <cstdio>
#include <algorithm>
using namespace std;
void dfs(int a,int b,int &x,int &y)
{
    if (a==1)
    {
        if (b==0)
            x=0,y=0;
        else if (b==1)
            x=1,y=0;
        else if (b==2)
            x=1,y=1;
        else
            x=0,y=1;
        return;
    }
    int len=1<<a-1,num=1<<2*(a-1),x0,y0;
    dfs(a-1,b%num,x0,y0);
    if (a&1)
    {
        if (b/num==0)
            x=x0,y=y0;
        else if (b/num==1)
            x=len+y0,y=x0;
        else if (b/num==2)
            x=len+y0,y=len+x0;
        else
            x=len-x0-1,y=2*len-y0-1;
        return;
    }
    if (b/num==0)
        x=x0,y=y0;
    else if (b/num==1)
        x=y0,y=len+x0;
    else if (b/num==2)
        x=len+y0,y=len+x0;
    else
        x=2*len-x0-1,y=len-y0-1;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int x,y;
    dfs(a,b,x,y);
    if (a&1)
        swap(x,y);
    printf("%d %d\n",x,y);
    return(0);
}

