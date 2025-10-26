import java.util.Scanner;
// Local helper used instead of org.apache.commons.text.StringEscapeUtils to avoid external dependency

public class xss {
    public static void main(String[] args) {
        Scanner scaner = new Scanner(System.in);
        System.out.println("Enter your comment");
        String userInput = scaner.nextLine();
        System.out.println("Without xss protection user inputs is: " + userInput);
        String safeinput = escapeHtml4(userInput);
        System.out.println("With xss protection safe user inputs is: "+safeinput);
        scaner.close();
    }

    // Minimal HTML-escape helper covering common characters. This avoids needing an external library.
    private static String escapeHtml4(String s) {
        if (s == null) return null;
        StringBuilder sb = new StringBuilder(s.length());
        for (char c : s.toCharArray()) {
            switch (c) {
                case '&': sb.append("&amp;"); break;
                case '<': sb.append("&lt;"); break;
                case '>': sb.append("&gt;"); break;
                case '"': sb.append("&quot;"); break;
                case '\'': sb.append("&#x27;"); break;
                case '/': sb.append("&#x2F;"); break;
                default: sb.append(c);
            }
        }
        return sb.toString();
    }
}
