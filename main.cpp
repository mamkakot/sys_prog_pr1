/*
 * File:   main.cpp
 * Author: dmitry
 *
 * Created on 19 февраля 2019 г., 9:10
 */

/* Вычислить среднее арифметическое элементов каждого столбца.
 * Заменить четные элементы этим значением.
 */
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "pr1_sys.h"
#include <gtest/gtest.h>
int main(int argc, char **argv) {
    int n = 1;
    testing::InitGoogleTest(&argc, argv);
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) matrix[i] = new int[n];

    Fill(n, matrix);
    Calc(n, matrix);
    Print(n, matrix);
    return RUN_ALL_TESTS();
}

bool Fill(int n, int **arr) {
    if (arr == nullptr || n == 0) return false;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = rand()%100;
    return true;
}

bool Calc(int n, int **arr) {
    if (arr == nullptr || n == 0) return false;
    int sered[n];
    for (int i = 0; i < n; i++) sered[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sered[i] += arr[j][i];
        }
        for (int t = 0; t < n; t++)
            if (arr[t][i] % 2 == 0)
                arr[t][i] = sered[i]/n;
    }
    return true;
}

bool Print(int n, int **arr) {
    if (arr == nullptr || n == 0) return false;
    std::cout << "\nМассив изменённый:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << "\n";
    }
    return true;
}

TEST(BasicTests, TestPrint) {
    int n = 0, **arr = nullptr;
    bool res = Print(n, arr);
    ASSERT_FALSE(res);
}


TEST(BasicTests, TestCalc) {
    int n = 0, **arr = nullptr;
    bool res = Calc(n, arr);
    ASSERT_FALSE(res);
}

TEST(BasicTests, TestFill) {
    int n = 0, **arr = nullptr;
    bool res = Fill(n, arr);
    ASSERT_TRUE(res);
}