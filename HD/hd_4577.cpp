/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int T=in.nextInt();
        while (T-->0)
        {
            BigInteger n=in.nextBigInteger();
            int K=in.nextInt();
            n=n.shiftRight(K-1);
            BigInteger ans=BigInteger.ZERO;
            while (n.signum()!=0)
            {
                ans=ans.add(n.add(BigInteger.ONE).shiftRight(1));
                n=n.shiftRight(K);
            }
            System.out.println(ans);
        }
    }
}
*/
int main(){}

