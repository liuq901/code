#include <vector>
using namespace std;
typedef long long ll;
const int mod=1000000009;
struct YetAnotherIncredibleMachine
{
    int countWays(vector <int> a,vector <int> len,vector <int> b)
    {
        ll ans=1;
        for (int i=0;i<a.size();i++)
        {
            int sum=0;
            for (int j=a[i]-len[i];j<=a[i];j++)
            {
                bool flag=true;
                for (int k=0;k<b.size();k++)
                    if (b[k]>=j && b[k]<=j+len[i])
                    {
                        flag=false;
                        break;
                    }
                sum+=flag;
            }
            ans=ans*sum%mod;
        }
        return(ans);
    }
};
int main(){}

