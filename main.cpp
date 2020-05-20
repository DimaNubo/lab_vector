#include"Matrix.h"
#include <cstdlib>
#include"Vector.h"
#include <time.h>
#include <clocale>
#include <malloc.h>
#include <vector>
#include<iostream>
#include <iomanip>
#include"Header.h"
using namespace std;
int main()
{
  cout << "Vector 1" << "\n";
  Vector<int> A;
  cin >> A;
  cout << "vector 1" << "\n";
  cout << A << "\n";
  int K = 0;
  int arr[] = { 9,2,1,4,5,6,7 };
  int arrr[] = { 2,3,4,5,6,7,8 };
  Vector<int> Z(7, arr);//создадим два вектора одинаковой размерности для операций над ними
  Vector<int> C(7, arrr);
  Vector<int> D;
  cout << "+" << "\n";
  D = Z + C;
  cout << D << "\n";
  cout << "*" << "\n";
  K = Z * C;
  cout << K << "\n";
  cout << "-" << "\n";
  D = Z - C;
  cout << D << "\n";
  cout << "/" << "\n";
  D = C / Z;
  cout << D << "\n";
  cout << "Sort" << "\n" << "\n";
  cout << "BubbleSort" << "\n";
  int t = clock();
  int arrrre[] = { 9,2,3,4,5,6,7 };
  Vector<int> AH(7, arrrre);
  t = AH.BubbleSort();
  cout << "time sort=" << t << "\n";
  cout << "otsortirovannue vector" << "\n";
  cout << AH << "\n" << "\n";
  int arrrr[] = { 9,2,1,4,5,6,3 };
  Vector<int> U(7, arrrr);
  cout << "QuickSort" << "\n";
  int o = clock();
  o = U.QuickSort(0, Z.GetSize() - 1);
  cout << "time sortirovki=" << o << "\n";
  cout << "otsortirovannue vector" << "\n";
  cout << U << "\n" << "\n";

  int arrrra[] = { 9,2,3,2,5,6,4 };
  Vector<int> E(7, arrrra);
  cout << "InsertionSort" << "\n";
  int w = clock();
  w = E.InsertionSort();
  cout << "vreme sortirovki=" << w << "\n";
  cout << "otsortirovannue vector" << "\n";
  cout << E << "\n" << "\n";

  cout << "--------------------" << "\n";
  cout << "Matrica 1" << "\n";
  Matrix<int> AB;
  cin >> AB;
  cout << "vvedite TOY ZHE RAZMERNOSTI Matricu!!!!";
  cout << "Matrica 2" << "\n";
  Matrix<int> AC;
  cin >> AC;
  Matrix<int> ABC;

  cout << "slozhenie" << "\n";
  ABC = AB + AC;
  cout << "umnozhenie" << "\n";
  ABC = AB * AC;
  cout << "vuchitanie" << "\n";
  ABC = AB - AC;
  cout << "kolichestvo vxozhdeniy ukazannogo znacheniya" << "\n";
  cout << "Vector*Matrica" << "\n";
  int arrar[] = { 1,2,3 };
  Vector<int> V1(3, arrar);
  Matrix<int> V2;
  Matrix<int> V3;
  cout << "vvedite razmernosti 1*3" << "\n";
  cin >> V2;
  V3 = V1 * V2;
  cout << "Matrix*Vector" << "\n";
  Matrix<int> VV;
  cout << "vvedite razmernost' 3*3" << "\n";
  cin >> VV;
  int arrereq[] = { 9,2,1 };
  Vector<int> IO(3, arrereq);
  Vector<int> I;
  I = VV * IO;
  cout << I << "\n";
  return 0;
}