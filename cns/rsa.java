import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

public class rsa {
    static Scanner s = new Scanner(System.in);
    private static BigInteger p, q, N, phi, e, d;
    private static int bitlenght = 1024;
    private static Random r;
    private static void Setter() {
        r = new Random();
        p = BigInteger.probablePrime(bitlenght, r);
        q = BigInteger.probablePrime(bitlenght, r);
        N = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(bitlenght/2, r);

        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0) {
            e = e.add(BigInteger.ONE);
        }
        d = e.modInverse(phi);
    }    
    private static byte[] encrypt(String data) {
        return (new BigInteger(data.getBytes())).modPow(e, N).toByteArray();
    }

    private static byte[] decrypt(byte[] encryptedData) {
        return (new BigInteger(encryptedData)).modPow(d, N).toByteArray();
    }

    public static void main(String[] args) {
        String data = s.nextLine();
        Setter();

        byte[] encrypted = encrypt(data);
        System.out.println("Encryption: " + new BigInteger(encrypted).toString());

        System.out.println("Decryption: " + new String(decrypt(encrypted)));
    }
}
