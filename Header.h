#include "Vector.h"
#include "Matrix.h"
template <class T>
Vector<T>  operator * (Matrix<T>& matrx, Vector<T>& vector)
{
  if (matrx.Getm() == vector.GetSize())
  {
    T* arr = new T[matrix.Getm()];
    T** arr_matrix = matrix.GetMatrix();
    T* arr_vector<T> res(matrx.Getn(), arr);
    for (int i = 0; i < matrix.Getm(); i++)
    {
      arr[i] = 0;
      for (int j = 0; j < matrix.Getn(); j++)
      {
        arr[i] = arr[i] + (arr_matrix[i][j] * arr_vector[j]);

      }
    }
    Vector<T> res(matrix.Getn(), arr);
    delete[] arr;
    return res;
  }
  else
    throw - 1;
};

template <class T>
Matrix<T> operator *(Vector<T>& vector, Matrix<T>& matrix)
{
  if (matrix.Getn() == vector.GetSize() && matrix.Getm() == 1)
  {
    T** arr = new T * [matrix.Getn()];
    for (int i = 0; i < vector.Getsize(); i++)
      arr[i] = new T[vector.GetSize()];

    for (int i = 0; i < vector.GetSize(); i++)
      for (int j = 0; j < matrix.Getn(); j++)
      {
        /* result.SetRazmernost(i, j);
           result.s[i]=(matrix[0][j] * vector[i]);*/
        arr[i][j] = (matrix[0][j] * vector[i]);
      }
    Matrix<T> res(matrix.Getn(), vector.GetSize(), arr);


    for (int i = 0; i < vector.GetSize(); i++)
      delete[] arr[i];
    delete[] arr;
    return res;
  }
  else
    throw - 1;
};
