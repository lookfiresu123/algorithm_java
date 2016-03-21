package chapter_2_sort;

/**
 * Created by lookfiresu on 16-3-21.
 */
public class HeapSort {

    private boolean less(Comparable[] pq, int i, int j) { return pq[i].compareTo(pq[j]) < 0; }

    private void exch(Comparable[] pq, int i, int j) {
        Comparable t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }

    private void sink(Comparable[] a, int k, int n) {  // 由上至下的堆有序化（下沉）——当某个结点变得比它的两个子节点之一更小时执行（循环执行，直到遇见两个子节点都比自己小或到堆底的情况）
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && less(a, j, j+1)) j++;
            if (! less(a, k, j)) break;
            exch(a, k, j);
            k = j;
        }
    }

    // 堆排序
    public void sort(Comparable[] a) {
        int N = a.length-1;
        // 构造堆阶段
        for (int k = N/2 ; k >=1 ; k--)
            sink(a, k, N);
        // 下沉排序阶段
        while(N > 1) {
            exch(a, 1, N--);
            sink(a, 1, N);      // 在1~N的范围内sink a[1]
        }
    }

}
