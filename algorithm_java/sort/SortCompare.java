package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-4.
 */
public class SortCompare {
    public static double time(String alg, Comparable[] a) {
        Stopwatch timer = new Stopwatch();
        if (alg.equals("InsertSort"))   InsertSort.sort(a);
        if (alg.equals("InsertSort_Advanced"))  InsertSort.sort_advanced(a);
        if (alg.equals("SelectSort"))   SelectSort.sort(a);
        if (alg.equals("ShellSort"))   ShellSort.sort(a);
        if (alg.equals("QuickSort"))   QuickSort.sort(a);
        return timer.elapsedTime();
    }

    public static double timeRandomInput(String alg, int N, int T) {
        double total = 0.0;
        Double[] a = new Double[N];
        for (int t = 0 ; t < T ; t++) {
            for (int i = 0 ; i < N ; i++)
                a[i] = StdRandom.uniform();
            total += time(alg, a);
        }
        return total;
    }

    public static void main(String[] args) {
        String[] temp = {"SelectSort", "QuickSort"};
        String alg0 = temp[0];
        String alg1 = temp[1];
        int N = 1000;      // 数组长度为N
        int T = 100;       // 重复T次
        double t0 = timeRandomInput(alg0, N, T);
        double t1 = timeRandomInput(alg1, N, T);
        System.out.printf(" %s : %s = %.3f\n", temp[1], temp[0], t1/t0);     // t0 is t1/t0 times faster than t1
    }
}
