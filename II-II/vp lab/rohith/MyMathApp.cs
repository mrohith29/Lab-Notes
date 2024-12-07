using System;
using myMathlib;

class MyMathApp {
    public static void Main(string[] args) {
        int num1 = int.Parse(args[0]);
        int num2 = int.Parse(args[1]);
        int add = shiva.Add(num1, num2);
        int mul = shiva.Mul(num1, num2);
        Console.WriteLine(add);
        Console.WriteLine(mul);
    }
}