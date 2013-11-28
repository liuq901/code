#include <cstdio>
#include <algorithm>
using namespace std;
const int to[8]={5,4,7,6,1,0,3,2};
const int center[8]={7,8,9,12,13,16,17,18};
const int op[8][7]={{1,3,7,12,16,21,23},{2,4,9,13,18,22,24},{11,10,9,8,7,6,5},{20,19,18,17,16,15,14},
    {24,22,18,13,9,4,2},{23,21,16,12,7,3,1},{14,15,16,17,18,19,20},{5,6,7,8,9,10,11}};
int limit,a[30];
char ans[1000000];
int calc()
{
    int s[4]={0};
    for (int i=0;i<8;i++)
        s[a[center[i]]]++;
    return(max(max(s[1],s[2]),s[3]));
}
void move(int x)
{
    int t=a[op[x][0]];
    for (int i=1;i<7;i++)
        a[op[x][i-1]]=a[op[x][i]];
    a[op[x][6]]=t;
}
bool dfs(int dep,int prev)
{
    int p=calc();
    if (p==8)
    {
        if (limit==0)
            printf("No moves needed\n");
        else
        {
            ans[limit]='\0';
            printf("%s\n",ans);
        }
        printf("%d\n",a[7]);
        return(true);
    }
    if (dep+8-p>limit)
        return(false);
    for (int i=0;i<8;i++)
    {
        if (to[i]==prev)
            continue;
        ans[dep]=i+'A';
        move(i);
        if (dfs(dep+1,i))
            return(true);
        move(to[i]);
    }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d",&a[1]);
        if (a[1]==0)
            break;
        for (int i=2;i<=24;i++)
            scanf("%d",&a[i]);
        for (limit=0;;limit++)
            if (dfs(0,-1))
                break;
    }
    return(0);
}

