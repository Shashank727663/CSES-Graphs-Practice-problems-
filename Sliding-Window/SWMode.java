import java.util.*;

public class SWMode {

    static List<Integer> nums = new ArrayList<>();

    public static int getMaxFreqKey(Map<Integer, Integer> mp) {
        int maxFreq = 0;
        int ansKey = Integer.MAX_VALUE;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            int key = entry.getKey();
            int val = entry.getValue();

            if (val > maxFreq || (val == maxFreq && key < ansKey)) {
                maxFreq = val;
                ansKey = key;
            }
        }
        return ansKey;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt());
        }

        Map<Integer, Integer> mp = new HashMap<>();

        //  build first window
        for (int i = 0; i < k; i++) {
            int num = nums.get(i);
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }

        System.out.print(getMaxFreqKey(mp) + " ");

        //  sliding window
        for (int i = 1; i + k - 1 < n; i++) {

            int remove = nums.get(i - 1);
            int add = nums.get(i + k - 1);

            // remove left element
            mp.put(remove, mp.get(remove) - 1);
            if (mp.get(remove) == 0) {
                mp.remove(remove);
            }

            // add right element
            mp.put(add, mp.getOrDefault(add, 0) + 1);

            System.out.print(getMaxFreqKey(mp) + " ");
        }

        sc.close();
    }
}
