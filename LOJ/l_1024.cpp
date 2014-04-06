/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        new Main().run();
    }
    void run()
    {
        Scanner in=new Scanner(System.in);
        int T=in.nextInt();
        for (int id=1;id<=T;id++)
        {
            int n=in.nextInt();
            BigInteger ans=in.nextBigInteger();
            for (int i=2;i<=n;i++)
            {
                BigInteger x=in.nextBigInteger();
                ans=ans.divide(ans.gcd(x)).multiply(x);
            }
            System.out.println("Case "+id+": "+ans);
            System.gc();
        }
    }
}
*/
int main(){}

