// Single Level Inheritance
using System;

class BaseClass {
    public void BaseMethod() {
        Console.WriteLine("Hello from BaseClass");
    }
}

class DerivedClass : BaseClass {
    public void DerivedMethod() {
        Console.WriteLine("Hello from DerivedClass");
    }
}

// Multi-Level Inheritance
class SecondDerivedClass : DerivedClass {
    public void SecondDerivedMethod() {
        Console.WriteLine("Hello from SecondDerivedClass");
    }
}

class Program {
    static void Main(string[] args) {
        // Demonstrating Single Level Inheritance
        Console.WriteLine("Single Level Inheritance:");
        DerivedClass derivedObj = new DerivedClass();
        derivedObj.BaseMethod(); // Method from BaseClass
        derivedObj.DerivedMethod(); // Method from DerivedClass

        Console.WriteLine("\nMulti-Level Inheritance:");
        // Demonstrating Multi-Level Inheritance
        SecondDerivedClass secondDerivedObj = new SecondDerivedClass();
        secondDerivedObj.BaseMethod(); // Method from BaseClass
        secondDerivedObj.DerivedMethod(); // Method from DerivedClass
        secondDerivedObj.SecondDerivedMethod(); // Method from SecondDerivedClass
    }
}