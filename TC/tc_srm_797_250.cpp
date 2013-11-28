#include <vector>
#include <algorithm>
using namespace std;
struct MergersDivOne
{
    double findMaximum(vector <int> a)
    {
        vector <double> b;
        for (int i=0;i<a.size();i++)
            b.push_back(a[i]);
        while (b.size()>1)
        {
            sort(b.begin(),b.end());
            b[1]=(b[0]+b[1])/2.0;
            b.erase(b.begin());
        }
        return(b[0]);
    }
};
int main(){}

