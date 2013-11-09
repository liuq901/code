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
        while (in.hasNextInt())
        {
            int n=in.nextInt();
            System.out.println(calc(n));
        }
    }
    BigInteger calc(int n)
    {
        BigInteger ans=BigInteger.ONE;
        for (int i=1;i<=n*n;i++)
            ans=ans.multiply(BigInteger.valueOf(i));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                ans=ans.divide(BigInteger.valueOf(i+j-1));
        return(ans);
    }
}
*/
int main(){}

