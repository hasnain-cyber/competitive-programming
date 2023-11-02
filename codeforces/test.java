import java.util.*;

class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int categories[] = new int[n];
        for (int i = 0; i < n; i++)
            categories[i] = sc.nextInt();

        int prices[] = new int[n];
        for (int i = 0; i < n; i++)
        prices[i] = sc.nextInt();

        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            if (mp.containsKey(categories[i])) {
                mp.put(categories[i], mp.get(categories[i]) + prices[i]);
            } else {
                mp.put(categories[i], prices[i]);
            }
        }

        ArrayList<Integer> values = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            values.add(entry.getValue());
        }
        Collections.sort(values);

        int ans = 0;
        for (int i = 0; i < values.size(); i++) {
            ans += values.get(i) * (i + 1);
        }
        
        System.out.println(ans);

        sc.close();
    }
}