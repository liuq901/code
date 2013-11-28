#include <string>
using namespace std;
struct MissingParentheses
{
    int countCorrections(string par)
    {
        int tot=0,ans=0;
        for (int i=0;i<par.size();i++)
        {
            if (par[i]=='(')
                tot++;
            else if (tot==0)
                ans++;
            else
                tot--;
        }
        ans+=tot;
        return(ans);
    }
};
int main(){}

