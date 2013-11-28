#include <cstdio>
#include <algorithm>
using namespace std;
bool check(int *a,int l,int r)
{
    for (int i=l+1;i<=r;i++)
        if (a[i]!=a[i-1]+1)
            return(false);
    return(true);
}
bool straight(int *a)
{
    sort(a+1,a+6);
    return(check(a,1,5) || check(a,2,5) && a[1]==1 && a[2]==10);
}
int main()
{
    int a[10];
    while (scanf("%d",&a[1])==1)
    {
        for (int i=2;i<=5;i++)
            scanf(",%d",&a[i]);
        int b[20]={0};
        for (int i=1;i<=5;i++)
            b[a[i]]++;
        sort(b,b+20);
        reverse(b,b+20);
        if (b[0]==4)
            printf("four card\n");
        else if (b[0]==3)
            printf("%s\n",b[1]==2?"full house":"three card");
        else if (b[0]==2)
            printf("%s\n",b[1]==2?"two pair":"one pair");
        else
            printf("%s\n",straight(a)?"straight":"null");
    }
    return(0);
}

