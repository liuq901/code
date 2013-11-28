#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    k=k*l/nl,c*=d,p/=np;
    printf("%d\n",min(min(k,c),p)/n);
    return(0);
}

