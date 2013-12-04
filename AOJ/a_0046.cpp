#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector <double> a;
    double x;
    while (scanf("%lf",&x)==1)
        a.push_back(x);
    printf("%.10f\n",*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end()));
    return(0);
}

