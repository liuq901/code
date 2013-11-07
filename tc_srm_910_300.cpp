#include <string>
using namespace std;
struct LittleElephantAndBalls
{
    int getNumber(string S)
    {
        int n=S.size();
        bool before[3]={0},after[3]={0};
        int ans=0,x=0,y=0;
        for (int i=0;i<n;i++)
        {
            int value=S[i]=='R'?0:S[i]=='G'?1:2;
            ans+=x+y;
            if (!before[value])
            {
                before[value]=true;
                x++;
            }
            else if (!after[value])
            {
                after[value]=true;
                y++;
            }
        }
        return(ans);
    }
};
int main(){}

