#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int x1,y1,x2,y2;
    scanf("%*d%*d%d%d%d%d",&x1,&y1,&x2,&y2);
    int n=abs(x2-x1),m=abs(y2-y1);
    printf("%s\n",max(n,m)<=4 && n+m<=6?"First":"Second");
    return(0);
}

