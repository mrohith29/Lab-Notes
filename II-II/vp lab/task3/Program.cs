using System;

class Employee {
    public int id;
    public string name;
    public float salary;
    public void insert(int id, string name, float salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public void display() {
        Console.WriteLine(name + " " + id + " " + salary);
    }

    public static void Main(string[] args) {
        Employee ob = new Employee();
        ob.id = 1234;
        ob.name = "rohith";
        ob.salary = 100000;
         ob.display();
    }
}