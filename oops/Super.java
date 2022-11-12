package oops;

class Base {
    int value = 10;

    Base() {
        System.out.println("I am from the constructor of the base class.");
    }

    void print_something() {
        System.out.println("I am from the function fo the base class.");
    }
}

class Child extends Base {
    Child() {
        // can be used to invoke constuctor of immediate parent class.
        super();
    }

    void execute() {
        // can be used to get class variables of immediate parent.
        System.out.println(super.value);
        super.print_something();
    }
}

public class Super {
    public static void main(String[] args) {
        Child child = new Child();
        child.execute();
    }
}
