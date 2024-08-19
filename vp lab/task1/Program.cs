using System;

class Program {
    public static void Main(string[] args){
        int num = int.Parse(Console.ReadLine());
        if(num < 0) {
            Console.WriteLine("The number is not palindrome");
        }
        else {
            int temp = num;
            int ans = 0;
            while(num!=0) {
                int rem = num%10;
                ans = ans*10+rem;
                num/=10;
            }
            if (ans == temp) {
                Console.WriteLine("The number is Palindrome");
            } else {
                Console.WriteLine("The number is not Palindrome");
            }
    }
}
}