import java.util.Scanner;

public class rc4 {
    static Scanner s = new Scanner(System.in);
    private static String encrypt(String data, String key) {
        int[] s = new int[256];
        int[] k = new int[256];
        int temp, i, j = 0, z;
        StringBuilder encryptedData = new StringBuilder();
        char[] dataChars = data.toCharArray();
        char[] keyChars = key.toCharArray();
        int[] dataInt = new int[data.length()];
        int[] keyInt = new int[key.length()];

        for(int m = 0; m<data.length(); m++) {
            dataInt[m] = (int) dataChars[m];
        }

        for (int m = 0; m < key.length(); m++)
        {
            keyInt[m] = (int) keyChars[m];
        }

        for(int m = 0; m<256; m++) {
            s[m] = m;
            k[m] = keyInt[m % key.length()];
        }

        j = 0;
        for(int m=0; m<256; m++) {
            j = (j+s[m]+k[m])%256;
            temp = s[m];
            s[m] = s[j];
            s[j] = temp;
        }
        i =0;
        j = 0;
        for(int l = 0; l<data.length(); l++) {
            i = (i+1) %256;
            j = (j+s[i])%256;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            z = s[(s[i] + s[j])%256];
            encryptedData.append((char)(z^dataInt[l]));
        }
        return encryptedData.toString();
    }

    private static String decrypt(String data, String key) {
        return encrypt(data, key);
    }

    public static void main(String[] args) {
        System.out.println("Enter the plain text: ");
        String data = s.nextLine();
        System.out.println("Enter the key: ");
        String key = s.nextLine();
        String encryptedData = encrypt(data, key);
        System.out.println("Encrypted: " + encryptedData);
        System.out.println("Decrypted: " + decrypt(encryptedData, key));
    }
}
