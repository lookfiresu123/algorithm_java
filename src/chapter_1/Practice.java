package chapter_1;

/**
 * Created by lookfiresu on 16-1-28.
 */

import java.lang.*;
import java.util.*;

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

    public static void main(String[] args) {
        int practice_index = 2;
        int M = 10, N = 10;     // M和N不为0
        Boolean[][] a = new Boolean[M][N];
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        init_boolean_matrix(a);
        if (practice_index == 1)              // 执行练习1.1.11
            print_boolean_array(a);
        else if (practice_index == 2) {      // 执行练习1.2.13
            print_boolean_array(a);
            System.out.println("<--------------->");
            print_matrix_transpose(a);
        }
    }
}
