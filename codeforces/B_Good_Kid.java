import java.util.*;

public class B_Good_Kid {
    private static int solve(ArrayList<Integer> arr, int n) {
        Collections.sort(arr);
        arr.set(0, arr.get(0) + 1);

        int ans = 1;
        for (int i = 0; i < n; i++)
            ans *= arr.get(i);

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            ArrayList<Integer> arr = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                int value = sc.nextInt();
                arr.add(value);
            }

            System.out.println(solve(arr, n));
        }
        
        sc.close();
    }
}