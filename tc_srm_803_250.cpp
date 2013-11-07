#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
struct Over9000Rocks
{
    int countPossibilities(vector <int> lowerBound,vector <int> upperBound)
    {
        int n=lowerBound.size();
        vector <pair <int,int> > b,ans;
        for (int i=0;i<1<<n;i++)
        {
            int lower=0,upper=0;
            for (int j=0;j<n;j++)
                if (i>>j&1)
                    lower+=lowerBound[j],upper+=upperBound[j];
            if (upper>9000)
                b.push_back(make_pair(max(9001,lower),upper));
        }
        sort(b.begin(),b.end());
        for (int i=0;i<b.size();i++)
            if (!ans.empty() && b[i].first<=ans.back().second)
                ans.back().second=max(ans.back().second,b[i].second);
            else
                ans.push_back(b[i]);
        int ret=0;
        for (int i=0;i<ans.size();i++)
            ret+=ans[i].second-ans[i].first+1;
        return(ret);
    }
};
int main(){}

