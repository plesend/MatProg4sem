#include <iostream>
#include <iomanip> 
#include "Salesman.h"
#define N 5
int main() {
    setlocale(LC_ALL, "rus");
    clock_t  t1 = 0, t2 = 0;
    int d[N][N] = { //0   1    2    3     4        
                  {  INF,  10, 26,  INF,   5},    //  0
                  { 5,   INF,  20,  63,  79 },    //  1
                  { 7,  15,   INF,  86,   54 },    //  2 
                  { 22,  53,  20,   INF,   15 },    //  3
                  { 88,  71,  52,  18,    INF} };  //  4  
                 
    int r[N];                     // результат 

    t1 = clock();

    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );

    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;

    t2 = clock();

    std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);

    std::cout << std::endl;
    system("pause");
    return 0;
}
