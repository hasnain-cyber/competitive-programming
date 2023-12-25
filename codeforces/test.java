public class test {
    static int a = 10;
    int i = 1;

    static public void main(float[] ar) {
        System.out.println("1st");
        int b[] = { 12 };
        main(b);
    }

    public static void main(int arr[]) {
        System.out.println("2nd");
        System.exit(0);
    }

    static {
        System.out.println("abc");
    }

    {
        System.out.println("def");
    }

    public static void main(String ar[]) {
        System.out.println("X");
        float a[] = { 1.2F };
        System.exit(0);
        test.main(a);
    }
}