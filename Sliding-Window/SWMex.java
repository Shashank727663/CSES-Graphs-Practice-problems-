import java.util.*;

public class SWMex {

    static List<Integer> nums = new ArrayList<>();

    // pass indices instead of sublist
    private static int getMinMissiong(int l, int r) {

        Set<Integer> set = new HashSet<>();

        for (int i = l; i < r; i++) {
            set.add(nums.get(i));
        }

        int mex = 0;
        while (set.contains(mex)) mex++;

        return mex;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        for (int i = 0; i < n; i++) {
            nums.add(sc.nextInt());
        }

        // first window
        System.out.print(getMinMissiong(0, k) + " ");

        // sliding window
        for (int i = 1; i + k <= n; i++) {
            System.out.print(getMinMissiong(i, i + k) + " ");
        }

        sc.close();
    }
}
