#include <cstdio>
#include <vector>
using namespace std;
const int c[]={6,2,5,5,4,5,6,3,7,6};
vector <int> s[1010];
int calc(int x)
{
    if (x==0)
        return(c[0]);
    if (x<0)
        return(calc(-x)+1);
    int ret=0;
    while (x)
    {
        ret+=c[x%10];
        x/=10;
    }
    return(ret);
}
void print(int ans)
{
    static int id=0;
    printf("Case %d: ",++id);
    if (ans==0)
        printf("No solutions.\n");
    else if (ans==1)
        printf("1 solution.\n");
    else
        printf("%d solutions.\n",ans);
}
int main()
{
    int a,b,c;
    for (int i=-999;i<=999;i++)
        s[calc(i)].push_back(i);
    while (scanf("%d%d%d",&a,&b,&c)==3)
    {
        if (a%5!=0 || b%5!=0 || c%5!=0)
        {
            print(0);
            continue;
        }
        a/=5,b/=5,c/=5;
        int ans=0;
        for (int i=0;i<s[a].size();i++)
            for (int j=0;j<s[b].size();j++)
            {
                int x=s[a][i],y=s[b][j];
                ans+=x+y>=-999 && x+y<=999 && calc(x+y)==c;
                ans+=x-y>=-999 && x-y<=999 && calc(x-y)==c;
                ans+=x*y>=-999 && x*y<=999 && calc(x*y)==c;
                if (y!=0)
                    ans+=x/y>=-999 && x/y<=999 && calc(x/y)==c;
            }
        print(ans);
    }
    return(0);
}

