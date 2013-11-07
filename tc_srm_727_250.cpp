#include <vector>
#include <algorithm>
using namespace std;
struct ToastXToast
{
    int bake(vector <int> a,vector <int> b)
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if (a[0]>=b[0] || a.back()>=b.back())
            return(-1);
        return(2-(a.back()<b[0]));
    }
};
int main(){}

