using System;

class Methodoverloading {
    public int sum(int a, int b) {
        return a+b;
    }

    public int sum(int a, int b, int c) {
        return a+b+c;
    }

    public double sum(double a, double b) {
        return a+b;
    }
    public static void Main(string[] args) {
        Methodoverloading ob = new Methodoverloading();
        Console.WriteLine(ob.sum(12,13));
        Console.WriteLine(ob.sum(12,13,14));
        Console.WriteLine(ob.sum(12.9d,13d));
        
    }
}