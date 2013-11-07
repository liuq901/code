#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct ImportantSequence
{   
    int getCount(vector <int> B,string s)
    {
        ll l=1,r=1LL<<60;
        for (int i=0;i<B.size();i++)
        {
            ll x,y;
            if (s[i]=='+')
            {
                x=B[i]-r;
                y=B[i]-l;
            }
            else
            {
                x=l-B[i];
                y=r-B[i];
            }
            x=max(x,1LL);
            l=x,r=y;
            if (x>y)
                break;
        }
        if (l>r)
            return(0);
        if (r>1LL<<50)
            return(-1);
        return(int(r-l+1));
    }
};
int main(){}
