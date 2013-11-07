#include <vector>
#include <string>
using namespace std;
struct MysteriousRestaurant
{
    int maxDays(vector <string> a,int K)
    {
        int n=a.size(),m=a[0].size();
        for (int i=n-1;i>=0;i--)
        {
            int ans=0;
            for (int j=0;j<7;j++)
            {
                int now=1<<30;
                for (int k=0;k<m;k++)
                {
                    int sum=0;
                    for (int p=j;p<=i;p+=7)
                        sum+=calc(a[p][k]);
                    now=min(now,sum);
                }
                ans+=now;
            }
            if (ans<=K)
                return(i+1);
        }
        return(0);
    }
    int calc(char ch)
    {
        if (isdigit(ch))
            return(ch-'0');
        if (isupper(ch))
            return(ch-'A'+10);
        return(ch-'a'+36);
    }
};
int main(){}

