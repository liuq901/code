#include <iostream>
#include <bitset>
using namespace std;
bitset <32> a;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>a;
        int ans=a.to_ulong();
        cout<<dec<<ans<<" "<<hex<<uppercase<<ans<<endl;
    }
    return(0);
}

