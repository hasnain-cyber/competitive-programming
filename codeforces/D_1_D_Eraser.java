import java.util.*;

class D_1_D_Eraser {
    private static ArrayList<ArrayList<Integer>> condense(String s, int n) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ans.isEmpty() || ans.get(ans.size() - 1).get(0) != (ch - 'a')) {
                ArrayList<Integer> ele = new ArrayList<>();
                ele.add(ch - 'a');
                ele.add(1);
                ans.add(ele);
            } else {
                ArrayList<Integer> ele = ans.get(ans.size() - 1);
                ele.set(1, ele.get(1) + 1);
                ans.set(ans.size() - 1, ele);
            }
        }

        return ans;
    }

    private static int solve(String s, int n, int k) {
        int ans = 0;
        ArrayList<ArrayList<Integer>> values = condense(s, n);
        for (int i = 0; i < values.size(); i++) {
            ArrayList<Integer> ele = values.get(i);

            if (ele.get(0) == ('W' - 'a'))
                continue;
            
            ans += Math.ceil((double)ele.get(1) / k);
        }

        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();

            System.out.println(solve(s, n, k));
        }

        sc.close();
    }
}