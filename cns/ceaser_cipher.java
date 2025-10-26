import java.util.*;

public class ceaser_cipher {
    static Scanner s = new Scanner(System.in);

    private static String encrypt(String data, int key) {
        StringBuilder res = new StringBuilder();
        for (Character ch: data.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                char shiftedChar = (char)(((ch - 'A' + key) % 26) + 'A');
                res.append(shiftedChar);
            } else if (Character.isLowerCase(ch)) {
                char shiftedChar = (char) (((ch - 'a' + key)%26) + 'a');
                res.append(shiftedChar);
            } else {
                res.append(ch);
            }
        }
        return res.toString();
    }

    private static String decrypt(String data, int key) {
        return encrypt(data, 26 - (key % 26));
    }

    public static void main(String[] args) {
        String data = s.nextLine();
        int key = s.nextInt();
        data = encrypt(data, key);
        System.out.println("Encryption: " + data);
        System.out.println("Decryption: " + decrypt(data, key));
    }
}