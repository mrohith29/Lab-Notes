import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.util.Base64;
import java.util.Scanner;

public class digital_certificates {
    private static Scanner s = new Scanner(System.in);
    public static void main(String[] args) {
        try {
            KeyPairGenerator keygen = KeyPairGenerator.getInstance(("DSA"));
            keygen.initialize(1024);
            KeyPair keypair = keygen.generateKeyPair();
            PrivateKey privatekey = keypair.getPrivate();
            PublicKey publickey = keypair.getPublic();

            String data = s.nextLine();
            byte[] dataBytes = data.getBytes();

            Signature signature = Signature.getInstance("SHA256withDSA");
            signature.initSign(privatekey);
            signature.update(dataBytes);
            byte[] digitalSignature = signature.sign();

            System.out.println("DigitalSignature:"+Base64.getEncoder().encodeToString(digitalSignature));

            signature.initVerify(publickey);
            signature.update(dataBytes);
            boolean isVerified = signature.verify(digitalSignature);

            System.out.println("Signature Verified: " + isVerified);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
