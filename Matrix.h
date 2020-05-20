#include<iostream>

using namespace std;

template<class M>
class Matrix
{
public:
  Matrix();
  Matrix(int A, int B); //Свободная матрница  A строк и B столбцов
  Matrix(int C, int D, M** arr);
  Matrix(const Matrix<M>& Znach);
  ~Matrix();
  M** GetMatrix();
  void SetRazm(int num_strings, int num_columns);// указать размерность матрицы 
  int Getm();// узнать кол-во строк 
  int Getn();// узнать кол-во столбцов
  bool operator==(const Matrix<M>& Znach);
  Matrix<M> operator =(const Matrix<M>& Znach);
  Matrix<M> operator +(const Matrix<M>& Znach);
  Matrix<M> operator -(const Matrix<M>& Znach);
  Matrix<M> operator *(const Matrix<M>& Znach);
  M*& operator [](const int i);
  template<class M>
  friend ostream& operator<<(ostream os, const Matrix<M>& matr); // потоковый вывод 
  template<class M>
  friend istream& operator>>(istream&, const Matrix<M>& matr); //потоковый ввод
protected:
  int m;// строки 
  int n;// столбцы
  M** mass;
  void MSize(int num_strings, int num_columns) // выделение памяти под двумерный массив  
  {
    mass = new M * [m];
    for (int i = 0; i < num_strings; i++)
      this->mass[i] = new M[num_columns];
  }
};

 template <class M>
  Matrix<M>::Matrix()
 {
  m = 1;
  n = 1;
  MSize(m, n);
  mass[0][0] = 0;
 }

template<class M>
Matrix<M>::Matrix(int A, int B)// указанная размерность матрицы (сост из 2 масс, разм. кот. указан ранее)
{
  m = A;
  n = B;
  MSize(m, n);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      mass[i][j] = 0;
    }
  }
}
 template<class M>
 Matrix<M>:: Matrix(int C, int D, M** arr)//второй двойн массив идент. mass
 {
   m = C;
   n = D;
   MSize(C, D);
   for (int i = 0; i < m; i++)
   {
     for (int j = 0; j < n; j++)
     {
       mass[i][j] = arr[i][j];
     }
   }
 }
 template <class M>
 Matrix<M>::Matrix(const Matrix<M>& Znach)// переложить mass в Znach
 {
   m = Znach.n;
   n = Znach.m;
   MSize(m, n);
   for (i = 0; i < m; i++)
   {
     for (j = 0; j < n; j++)
     {
       mass[i][j] = Znach.mass[i][j];
     }
   }
 }
  template<class M>
  Matrix<M>::~Matrix()// очищаем двумерный массив(выз. дестр. в обр порядке)
  {
    for (int i = 0; i < m; i++)
    {
      delete[] mass[i];
    }
    delete[] mass;
    n = 0;
    m = 0;
  }
  template<class M>
  int Matrix<M>::Getm()
  {
    return m;
  }
  template<class M>
  int Matrix<M>::Getn()
  {
    return n;
  }
  template<class M>
  M** Matrix<M>::GetMatrix()
  {
    return mass;
  }
  template<class M>
  void Matrix<M>::SetRazm(int num_strings, int num_columns)// новые значения строк и столбцов матрицы
  {
    m = num_strings;
    n = num_columns;
  }
  template<class M>
  bool Matrix<M>::operator ==(const Matrix<M>& Znach)
  {
    if (m == Znach.m && n == Znach.n)
    {
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
          if (mass[i][j] == Znach.mass[i][j])
            return true;
          else
            return false;
      }
    }
    else
      return false;
  }
  template<class M>
  Matrix<M> Matrix<M>::operator =(const Matrix<M>& Znach)
  {
    this->swap(Znach)
      return *this;
  }
  template<class M>
  Matrix<M> Matrix<M>::operator +(const Matrix<M>& Znach)
  {
    if (n == Znach.n && m == Znach.m)
    {
      Matrix<M> res(m,n,Znach.mass);
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
          res.mass[i]][j] += Znach.mass[i][j]
        }
      return res;
    }
    else throw ("incorrect row or column values")
  }
  template<class M>
  Matrix<M> Matrix<M>::operator -(const Matrix<M>& Znach)
  {
    if (n == Znach.n && m == Znach.m)
    {
      Matrix<M> res(n, m, Znach.mass);
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
          res.mass[i]][j] -= Znach.mass[i][j];
        }
      return res;
    }
    else throw ("incorrect row or column values");
  }
  template<class M>
  Matrix<M> Matrix<M>::operator *(const Matrix<M>& Znach)
  {
    if (n == Znach.m)
    {
      Matrix<M>proiz(m, Znach.n);
      for (int i = 0; i < proiz.m; i++)
        for (int j = 0; j < proiz.n; j++)
        {
          proiz.mass[i][j] = 0;
          for (int k; k < n; k++)
          {
            proiz.mass[i][j] = proiz.mass[i][j] + (proiz.mass[i][k] * proiz.mass[k][j]);
          }
        }
      return proiz;
    }
    else
      return throw ("incorrect row or column values");
  }
  template <class M>
  M*& Matrix<M>::operator [](const int i)
  {
    return mass[i];
  }
  template<class M>
  ostream& operator<<(ostream os, const Matrix<M>& matr)
  {
    for (int i = 0; i < matr.m; i++)
    {
      for (int j = 0; j < matr.n; j++)
      {
        out << matr.mass[i][j] << " ";
      }
      out << endl;
    }
    return out;
  }
  template<class M>
  istream& operator>>(istream&, const Matrix<M>& matr)
  {
    if ((matr.Getm() != 0) || (matr.Getn() != 0))
    {
      for (int i = 0; i < matr.m; i++)
        delete[] matr.mass[i];//очистка массива для новых данных
      delete[] matr.mass;
    }
    cout >> "Enter rows and columns for the matrix" << "\n"
      cout << "m = " << "\n";
    in >> matr.m;
    cout << "n = " << "\n"
    in >> matr.n;
    matr.MSize(matr.m, matr.n);
    for (int i = 0; i < matr.m; i++)
    {
      for (int j = 0; j < matr.n; j++)
        in >> matr.massiv[i][j];
    }
    return in;
  }