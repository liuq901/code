#include <string>
using namespace std;
struct LargestSubsequence
{
    string getLargest(string s)
    {
        if (s.size()<=1)
            return(s);
        int k=0;
        for (int i=0;i<s.size();i++)
            if (s[i]>s[k])
                k=i;
        return(s[k]+getLargest(s.substr(k+1)));
    }
};
int main(){}
