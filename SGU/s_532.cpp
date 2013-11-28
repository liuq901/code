#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
struct seg
{
    int x1,y1,x2,y2;
    seg(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
};
bool check(const seg &a,const seg &b)
{
    return(a.x1>=b.x1 && a.x1<=b.x2 && b.y1>=a.y1 && b.y1<=a.y2);
}
vector <seg> a,b;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1>x2)
            swap(x1,x2);
        if (y1>y2)
            swap(y1,y2);
        if (x1==x2)
            a.push_back(seg(x1,y1,x2,y2));
        else
            b.push_back(seg(x1,y1,x2,y2));
    }
    ll ans=0;
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            int sum=0;
            for (int k=0;k<b.size();k++)
                sum+=check(a[i],b[k]) && check(a[j],b[k]);
            ans+=ll(sum)*(sum-1)/2;
        }
    printf("%I64d\n",ans);
    return(0);
}

