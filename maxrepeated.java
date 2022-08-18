import java.util.*;

public class maxrepeated {

    public static void main(String[] args) {
        int n = 0;
        try (Scanner sc = new Scanner(System.in)) {
            if (sc.hasNext())
                n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                if (sc.hasNext())
                    a[i] = sc.nextInt();
            }

            HashMap<Integer, Integer> map = new HashMap<>();
            int maxa = 0, maxe = 0;
            for (int i = 0; i < n; i++) {

                if (map.containsKey(a[i])) {
                    int c = map.get(a[i]);
                    if (c > maxa) {
                        maxa = c;
                        maxe = a[i];
                    }
                    map.replace(a[i], c + 1);
                } else
                    map.put(a[i], 1);
            }
            System.out.println("[(" + maxe + ", " + maxa + ")]");
        }
    }
}