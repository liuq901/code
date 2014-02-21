#include <cstdio>
#include <sstream>
using namespace std;
char buf[100000];
int calc()
{
    stringstream sin(buf);
    int sum=0,cnt=0,x;
    while (sin>>x)
    {
        if (x==0)
            return(-1);
        if (x>=10)
            x=10;
        sum+=x;
        cnt+=x==1;
    }
    while (cnt && sum+10<=21)
    {
        cnt--;
        sum+=10;
    }
    if (sum>21)
        sum=0;
    return(sum);
}
int main()
{
    while (1)
    {
        gets(buf);
        int ans=calc();
        if (ans==-1)
            break;
        printf("%d\n",ans);
    }
    return(0);
}

