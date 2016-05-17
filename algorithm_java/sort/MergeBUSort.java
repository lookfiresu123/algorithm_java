package chapter_2_sort;

/**
 * Created by lookfiresu on 16-2-23.
 */
/* 自底向上的归并排序 */
public class MergeBUSort extends BaseSort {
    private static Comparable[] aux;    // 归并所需的辅助数组

    public static void merge(Comparable[] a, int lo, int mid, int hi) {
        // 将a[lo:mid]和a[mid+1:hi]归并
        int i = lo, j = mid+1;
        for (int k = lo ; k <= hi ; k++)    // 将a[lo:hi]复制到aux[lo:hi]
            aux[k] = a[k];
        for (int k = lo ; k <= hi ; k++) {
            if (i > mid)    // 若aux[lo:mid]已归并结束，则将aux[mid+1:hi]的剩余部分逐一归并到a中
                a[k] = aux[j++];
            else if (j > hi)    // 若aux[mid+1:hi]已归并结束，则将aux[lo:mid]的剩余部分逐一归并到a中
                a[k] = aux [i++];
            else if (less(aux[j], aux[i]))  // 若aux[j]小于aux[i]，则将aux[j]拷贝到a[k]中，并将a[j+1]加入下次比较
                a[k] = aux[j++];
            else    // 若aux[i]不大于aux[j]，则将aux[i]拷贝到a[k]中，并将a[i+1]加入下次比较
                a[k] = aux[i++];
        }
    }

    public static void sort(Comparable[] a) {
        // 进行lgN次两两归并
        int N = a.length;
        aux = new Comparable[N];
        for (int sz = 1 ; sz < N ; sz = sz+sz)      // sz:子数组的大小
            for (int lo = 0 ; lo < N-sz ; lo += sz+sz)      // lo:子数组索引
                merge(a, lo, lo+sz-1, Math.min(lo+sz+sz-1, N-1));
    }

}
