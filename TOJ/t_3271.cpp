#include <cstdio>
#include <set>
using namespace std;
int a[1010],b[1010],c[1010];
set <int> s;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            s.erase(a[i]);
            bool flag=false;
            for (int j=1;j<=ans;j++)
            {
                if (a[i]<b[j] && (s.lower_bound(a[i])==s.end() || *s.lower_bound(a[i])>b[j]))
                {
                    b[j]=a[i];
                    flag=true;
                    break;
                }
                if (a[i]>c[j])
                {
                    set <int>::iterator k=s.lower_bound(a[i]);
                    if (k==s.begin())
                    {
                        c[j]=a[i];
                        flag=true;
                        break;
                    }
                    k--;
                    if (*k<c[j])
                    {
                        c[j]=a[i];
                        flag=true;
                        break;
                    }
                }
            }
            if (!flag)
            {
                ans++;
                b[ans]=c[ans]=a[i];
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

