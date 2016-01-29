package chapter_1;

/**
 * Created by lookfiresu on 16-1-28.
 */

import java.lang.*;
import java.util.*;
import java.math.*;

public class Practice {
    // 打印一个boolean矩阵
    private static void print_boolean_matrix(Boolean[][] a, int row, int column) {
        for (int i = 0 ; i < row ; ++i) {
            for (int j = 0 ; j < column ; ++j) {
                if (a[i][j] == true)
                    System.out.print("* ");
                else
                    System.out.print("  ");
            }
            System.out.println();
        }
    }

    // 打印一个一维int数组
    private static void print_array(int[] a) {
        for (int i = 0 ; i < a.length ; ++i)
            System.out.print(a[i]+" ");
    }

    // 初始化boolean矩阵
    private static void init_boolean_matrix(Boolean[][] a) {
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        for (int i = 0 ; i < a.length ; ++i)
            for (int j = 0; j < a[0].length; ++j) {
                if (random.nextInt(2) == 1)
                    a[i][j] = true;
                else
                    a[i][j] = false;
            }
    }

    // 练习1.1.11：打印一个二维布尔数组的内容，其中*表示真，空格表示假
    public static void print_boolean_array(Boolean[][] a) {
        int row, column;
        if ((row = a.length) != 0 && (column = a[0].length) != 0) {
            print_boolean_matrix(a, row, column);
        }
    }

    // 练习1.1.13：打印出一个M行N列的二维数组的转置
    public static void print_matrix_transpose(Boolean[][] a) {
        int row,column;
        if ((row = a.length) != 0 && (column = a[0].length) != 0) {
            Boolean[][] b = new Boolean[column][row];
            for (int i = 0 ; i < row ; ++i)
                for (int j = 0 ; j < column ; ++j)
                    b[j][i] = a[i][j];
            int new_row = column, new_column = row;
            print_boolean_matrix(b, new_row, new_column);
        }
    }

    // 练习1.1.14：编写一个静态方法lg()，接受一个整型参数N，返回不大于log2(N)的最大整数
    public static int lg(int N) {
        int count = 0, result = 1;
        while ((result *= 2) <= N)
            count++;
        return count;
    }

    // 练习1.1.15：接受一个数组a[]和整数M，返回以M为大小的数组，其中第i个元素表示i在a中出现的次数
    public static int[] histogram(int[] a, int M) {
        int[] b = new int[M];
        for (int i = 0 ; i < M ; ++i) {
            ++b[a[i]];
        }
        return b;
    }

    // 练习1.1.20：递归计算N!
    public static double ln(int N) {
        if (N == 1)
            return 0;
        else
            return Math.log(N) + ln(N - 1);
    }

    // 练习1.1.28：删除排序后的重复元素
    public static int[] delete_same(int[] a) {
        int[] temp = new int[a.length];
        if (a.length > 0) {
            temp[0] = a[0];
            int j = 1;
            for (int i = 1 ; i < a.length ; ++i)
                if (a[i] != a[i-1])
                    temp[j++] = a[i];
            int[] result = new int[j];
            for (int i = 0 ; i < j ; ++i)
                result[i] = temp[i];
            return result;
        } else
            return temp;
    }

    public static void main(String[] args) {
        int practice_index = 6;
        int M = 10, N = 10;     // M和N不为0
        Boolean[][] a = new Boolean[M][N];
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        init_boolean_matrix(a);
        if (practice_index == 1)              // 执行练习1.1.11
            print_boolean_array(a);
        else if (practice_index == 2) {      // 执行练习1.1.13
            print_boolean_array(a);
            System.out.println("<--------------->");
            print_matrix_transpose(a);
        } else if (practice_index == 3) {       // 执行练习1.1.14
            int base = random.nextInt(10000);
            System.out.println(lg(base));
        } else if (practice_index == 4) {       // 执行练习1.1.15
            int n = 10, sum = 0;
            int[] b = new int[n];
            for (int i = 0 ; i < n ; ++i)
                b[i] = random.nextInt(b.length-1);
            int[] c = histogram(b, n);
            for (int i = 0 ; i < c.length ; ++i)
                sum += c[i];
            if (sum == c.length)
                System.out.println("true");
            else
                System.out.println("false");
        } else if (practice_index == 5) {       // 执行练习1.1.20
            int n = 10;
            System.out.println(ln(n));
        } else if (practice_index == 6) {       // 执行练习1.1.28
            int[] b = new int[N];
            for (int i = 0 ; i < N ; ++i)
                b[i] = random.nextInt(N);
            Arrays.sort(b);
            print_array(b);
            int c[] = delete_same(b);
            System.out.println();
            print_array(c);
        }
    }
}
