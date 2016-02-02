package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-2.
 */
public class InsertSort extends BaseSort{
    private static void move(Comparable[] a, int start, int end) {
        for (int i = end ; i > start ; --i)
            a[i] = a[i-1];
    }

    public static void sort(Comparable[] a) {
        int N = a.length;
        Comparable nowVal;
        for (int i = 0 ; i < N ; ++i) {
            // 选择a[i]要插入的位置
            nowVal = a[i];
            for (int j = 0 ; j < i ; ++j) {
                if (less(nowVal, a[j])) {
                    move(a, j, i);
                    a[j] = nowVal;
                    break;
                }
            }
        }
    }
}
