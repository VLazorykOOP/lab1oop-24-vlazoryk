// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>

#include <time.h>

using namespace std;

/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size=0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size=0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    int r1=0, r2=0;
   // tm  *time;//
    //time_t *t;
    //time = localtime_s (t);
    srand(1000);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

void WriteArrayFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close();
}

int ReadArrayFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    bfout.write((const char*)&n, sizeof(int));
   // fout << n << endl;
    //for (int i = 0; i < n; i++)
    //    fout << arr[i] << "   ";
    bfout.write((const char*)arr, n*sizeof(double));
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream bfin(fileName, ios_base::binary);
   // fin >> size;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, size*sizeof(double));
    //for (int i = 0; i < n; i++)
    //    fin >> arr[i];
    bfin.close();
    return size;
}

int main()
{
    std::cout << "Hello World!\n";
    double A[1000], B[1000],C[1000];
    int n,m;
    n = RndInputArray(1000, A);
    WriteArrayFile(n, A, "1.txt");
    m = ReadArrayFile(1000, B, "1.txt");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << B[i] << "   ";
    WriteArrayBinFile(n, A, "1.bin");
    m = ReadArrayBinFile(1000, C, "1.bin");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << C[i] << "   ";


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
