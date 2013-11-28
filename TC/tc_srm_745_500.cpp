#include <vector>
#include <string>
using namespace std;
int f[520][50];
struct FiveHundredEleven
{
    vector <int> a;
    string theWinner(vector <int> card)
    {
        a=card;
        return(dp(0,card.size())?"Fox Ciel":"Toastman");
    }
    bool dp(int mem,int tot)
    {
        if (f[mem][tot]!=0)
            return(f[mem][tot]==1);
        int &ret=f[mem][tot];
        if (mem==511)
            ret=1;
        else if (tot==0)
            ret=-1;
        else
        {
            int cnt=0;
            bool flag=false;
            for (int i=0;i<a.size();i++)
                if ((a[i]|mem)!=mem)
                {
                    cnt++;
                    if (!dp(a[i]|mem,tot-1))
                    {
                        flag=true;
                        break;
                    }
                }
            if (!flag && tot>cnt && !dp(mem,tot-1))
                flag=true;
            ret=flag?1:-1;
        }
        return(ret==1);
    }
};
int main(){}

