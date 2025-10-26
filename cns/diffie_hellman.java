import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class diffie_hellman {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter prime number: ");
        BigInteger p = new BigInteger(br.readLine());
        System.out.println("Enter primitive root of "+p+":");
        BigInteger g = new BigInteger(br.readLine());
        System.out.println("Enter value for x less than " + p + ":");
        BigInteger x = new BigInteger(br.readLine());
        BigInteger R1 = g.modPow(x, p);
        System.out.println("R1 = " + R1);
        System.out.println("Enter value for y less than " + p+":");
        BigInteger y = new BigInteger(br.readLine());
        BigInteger R2 = g.modPow(y, p);
        System.out.println("R2 = "+R2);
        BigInteger k1 = R2.modPow(x, p);
        System.out.println("Key1 calculated:" + k1);
        BigInteger k2 = R1.modPow(y, p);
        System.out.println("Key2 calculated: " + k2);
        System.out.println("Diffie hellman secret key encryption has taken");
    }
}
