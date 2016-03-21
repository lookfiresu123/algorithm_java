package chapter_2_sort;

/**
 * Created by lookfiresu on 16-3-7.
 */
public class MaxPQ<Key extends Comparable<Key>> {
    private Key[] pq;       // 基于堆的完全二叉树
    private int N = 0;      // 存储于pq[1:N]中，pq[0]没有使用

    private boolean less(int i, int j) { return pq[i].compareTo(pq[j]) < 0; }

    private void exch(int i, int j) {
        Key t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }

    private void swim(int k) {  // 由下至上的堆有序化（上浮)——当某个结点变得比它的父结点还大时执行（循环执行，直到遇到一个比自己大的父结点或到堆顶）
        while (k > 1 && less(k/2, k)) {
            exch(k/2, k);
            k = k/2;
        }
    }

    private void sink(int k) {  // 由上至下的堆有序化（下沉）——当某个结点变得比它的两个子节点之一更小时执行（循环执行，直到遇见两个子节点都比自己小或到堆底的情况）
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && less(j, j+1)) j++;
            if (! less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    // public MaxPQ(){};

    public MaxPQ(int maxN) { pq = (Key[]) new Comparable[maxN+1]; }

    public boolean isEmpty() { return N == 0; }

    public int size() { return N; }

    public void insert(Key v) {
        pq[++N] = v;
        swim(N);
    }

    public Key delMax() {
        Key max = pq[1];    // 从根节点获取最大值
        exch(1, N--);       // 将根节点和最后一个结点交换
        pq[N+1] = null;     // 删除此时的最后一个结点（最大值结点）
        sink(1);            // 恢复堆的有序性
        return max;         // 返回最大值
    }
}
