using System;

public class task1 {
    public static void Main(string[] args) {
        int num = int.Parse(Console.ReadLine());
        if(num < 0) {
            Console.WriteLine("Number is not palinddrome");
        } else {
            int temp = num, sum = 0;
            while (num > 0) {
                int rem = num % 10;
                sum = (10 * sum )+rem;
                num /= 10;
            }
            if(temp == sum) {
                Console.WriteLine("Number is palindrome");
            } else {
                Console.WriteLine("Number is not a palindrome");
            }
        }
    }
}