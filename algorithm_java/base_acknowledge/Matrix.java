package chapter_1;

/**
 * Created by lookfiresu on 16-1-30.
 */

import java.lang.*;
import java.util.Random;

public class Matrix {
    private static double Max = 100.0;

    // 初始化一维矩阵
    public static double[] init_matrix(int length) {
        double[] x = new double[length];
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        for (int i = 0 ; i < x.length ; ++i)
            x[i] = random.nextDouble() % Max;
        return x;
    }

    // 初始化二维矩阵
    public static double[][] init_matrix(int length_row, int length_column) {
        double[][] a = new double[length_row][length_column];
        long seed = System.currentTimeMillis();
        Random random = new Random(seed);
        for (int i = 0 ; i < a.length ; ++i)
            for (int j = 0 ; j < a[i].length ; ++j)
                a[i][j] = random.nextDouble() % Max;
        return a;
    }

    // 向量点乘
    public static double dot(double[] x, double[] y) {
        // 假设x.length = y.length
        double sum = 0;
        for (int i = 0 ; i < x.length ; ++i)
            sum += x[i] * y[i];
        return sum;
    }

    // 矩阵和矩阵之积
    public static double[][] mult(double[][] a, double[][] b) {
        double[][] result = new double[a.length][b[0].length];
        // 假设a[0].length = b.length
        for (int i = 0 ; i < a.length ; ++i) {
            for (int j = 0 ; j < a[i].length ; ++j) {
                double sum = 0;
                for (int k = 0 ; k < a[j].length ; ++k)
                    sum += a[i][k] * b[k][j];
                result[i][j] = sum;
            }
        }
        return result;
    }

    // 转置矩阵
    public static double[][] transpose(double[][] a) {
        double[][] result = new double[a[0].length][a.length];
        // 假设a.length == a[0].length
        for (int i = 0 ; i < a.length ; ++i)
            for (int j = i ; j < a[i].length ; ++j)
                result[j][i] = a[i][j];
        return result;
    }

    // 矩阵和向量之积，此时x为列向量
    public static double[] mult(double[][] a, double[] x) {
        double[] result = new double[a.length];
        // 假设a[0].length == x.length
        for (int i = 0 ; i < a.length ; ++i) {
            double sum = 0;
            for (int j = 0 ; j < a[i].length ; ++j)
                sum += a[i][j] * x[j];
            result[i] = sum;
        }
        return result;
    }

    // 向量和矩阵之积，此时y为行向量
    public static double[] mult(double[] y, double[][] a) {
        double[] result = new double[a[0].length];
        // 假设y.length = a.length
        for (int i = 0 ; i < a[0].length ; ++i) {
            double sum = 0;
            for (int j = 0 ; j < y.length ; ++j)
                sum += y[j] * a[j][i];
            result[i] = sum;
        }
        return result;
    }

    public static void main(String[] args) {
        int m = 10, n = 10;
        double[][] a = init_matrix(m, n);
        double[][] b = init_matrix(n, m);
        double[] x = init_matrix(n);
        double[] y = init_matrix(m);
        dot(x, y);
        mult(a, b);
        transpose(a);
        mult(a, x);
        mult(y, a);
    }
}
