#include <vector>
#include <algorithm>
using namespace std;
struct EllysPairs
{
    int getDifference(vector <int> knowledge)
    {
        int ma,mi;
        ma=-1<<30;
        mi=1<<30;
        vector <int> a=knowledge;
        sort(a.begin(),a.end());
        for (int i=0;i<a.size();i++)
        {
            int p=a.size()-i-1;
            ma=max(ma,a[i]+a[p]);
            mi=min(mi,a[i]+a[p]);
        }
        return(ma-mi);
    }
};
int main(){}

