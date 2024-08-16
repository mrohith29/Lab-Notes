using System;
using mathlib;

public class mathfile {
    public static void Main(string[] args) {
        if(args.Length != 2) {
            Console.WriteLine("Enter valid number of argumenrts");
            return ;
        }
        int num1 = int.Parse(args[0]);
        int num2 = int.Parse(args[1]);

        int add = library.sum(num1, num2);
        int prod = library.mul(num1, num2);
        Console.WriteLine(add +" "+ prod);
    }
}