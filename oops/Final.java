package oops;

public class Final {
    public static void main(String[] args) {
        // final to prevent user from reassigning the value
        final int value = 10;
        System.out.println(value);

        // however, the value at the addresss can be changed, like in the case of an array.
        final int[] arr = { 1 };
        System.out.println(arr[0]);
        arr[0] = 2;
        System.out.println(arr[0]);
    }
}
