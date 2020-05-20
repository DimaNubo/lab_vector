#include <iostream>
#include <clocale>
#include <iomanip>
#include"Matrix.h"

using namespace std;
template<class V>
class Vector
{
public:
  Vector();
  Vector(int k, V* A);
  Vector(Vector& B);
  ~Vector();
  V* GetVector();
  void SetVector(V* C);
  void SetRazmer(int r);
  int GetSize();
  bool operator==(const Vector<V>& Znach);
  Vector<V> operator =(const Vector<V>& Znach);
  Vector<V> operator +(const Vector<V>& Znach);
  Vector<V> operator -(const Vector<V>& Znach);
  Vector<V> operator *(const Vector<V>& Znach);
  Vector<V> operator /(Vector<V>& Znach);
  V operator [](const int i);
  template<class V>
  friend ostream& operator<< (ostream& os, const Vector<V>& vec);
  template<class V>
  friend istream& operator>>(istream&, const Vector<V>& vec);
  clock_t BubbleSort();
  clock_t InsertionSort();
  clock_t QuickSort(int first, int last);
protected:
  int size;
  V* mass;

};

template<class V>
 Vector<V>::Vector()
 {
   size = 1;
   mass = new V[1];
   Vector a = 0;
   mass[0] = a;
 }

 template <class V>
Vector<V>::Vector(int k, V* A)
{
  mass = nullptr;
  try
  {
    if (k > 0)
    {
      size = k;
      mass = new V[size];
      for (int i = 0; i < size; i++)
      {
        mass[i] = A[i];
      }
    }
    else throw 1;
  }
  catch (int i)
  {
    cout << "data entered incorrectly" << "\n";
  }
}

 template<class V>
 Vector<V>::Vector(Vector& B)
{
  mass = nullptr;
  size = B.GetSize();
  mass = new V[size];
  for (int i = 0; i < razmer; i++)
  {
    mass[i] = B.mass[i];
  }
}
 
 template<class V>
 V* Vector<V>::GetVector()
 {
   return mass;
 }
 template<class V>
 int Vector<V>::GetSize()
 {
   return size;
 }
 template<class V>
 void Vector<V>::SetVector(V* C)
 {
   int i = strlen(C);
   if (mass != 0)
   {
     mass = 0;
     delete[] mass;
   }
   s = i;
   mass = new V[s];
   for (int z = 0; z < i; z++)
   {
     mass[z] = C[z];
   }
 }

 template<class V>
 Vector<V>::~Vector()// удаляем одномерный массив
 {
   if (mass != 0)
   {
     mass = 0;
     delete[] mass;
   }
   size = 0;
 }
 template<class V>
 Vector<V> Vector<V>::operator=(const Vector<V>& Znach)
 {
   this->swap(Znach)
     return *this;
 }
 
 template<class V>
 void Vector<V>::SetRazmer(int r)
 {
   size = r;
 }
 
 template<class V>
 bool Vector<V>::operator==(const Vector<V>& Znach)
 {
   int z = 0;
   if (size == Znach.size)
   {
     for (int i = 0; i < size; i++)
     {
       if (mass[i] == Znach.mass[i])
       {
         z = z + 1;
       }
     }
     if (z == size)
     {
       return true;
     }
     else 
       return false;
   }
   else
     return false;
 }
  template<class V>
 V Vector<V>::operator[](const int i)
 {
   return mass[i];
 }
 
  template<class V>
 Vector<V> Vector<V>::operator + (const Vector& Znach)
 {
   if (size == Znach.size)
   {
     Vector<V> vect(size, Znach.mass);
     for (int i = 0; i < size; i++)
       vect.mass[i] = mass[i] + Znach.mass[i];
     return vect;
   }
   else
     throw ("incorrect size");
 }
  template<class V>
 Vector<V> Vector<V>::operator-(const Vector<V>& Znach)
 {
   if (size == Znach.size)
   {
     Vector<V> vect(size, Znach.mass);
     for (int i = 0; i < size; i++)
       vect.mass[i] = mass[i] - Znach.mass[i];
     return vect;
   }
   else
     throw ("incorrect size");
 }
 
 template<class V>
   Vector<V> Vector<V>::operator *(const Vector<V>& Znach)
 {
   Vector proiz = 0;
   if (size == Znach.size)
   {
     for (int i = 0; i < size; i++)
       proiz = proiz + (mass[i] * Znach.mass[i]);
     return proiz;
   }
   else
     throw ("incorrect size");
 }

 template<class V>
   Vector<V> Vector<V>::operator /(Vector<V>& Znach)
 {

   if (size != Znach.GetRazmer())throw logic_error("incorrect data");
   Vector<V> del;
   del = *this;
   for (int i = 0; i < size; i++)
   {
     if (Znach.mass[i] != 0)
     {
       del.mass[i] = del.mass[i] / Znach.mass[i];
     }

   }
   return del;

 }

   template<class V>
   ostream& operator<<(ostream& os, const Vector<V>& vec)
   {
     for (int i = 0; i < vec.size; i++)
     return  os << vec.size[i];;
   }

   template<class V>
   istream& operator >> (istream& in, Vector<V>& vec)
   {
     in >> vec.size;
     V* newmass;
     newmass = new V[vec.size];
     for (int i = 0; i < vec.size; i++)
     {
       in >> newmass[i];
     }
     Vector<V> ish(vec.size, newmass);
     vec = ish;
     newmass = 0;
     delete[] newmass;
     return in;
   }

   template<class V>
   clock_t Vector<V>::BubbleSort()
   {
     clock_t start, finish;
     start = clock();
     Vector tmp = 0;
     int i, j = 0;
     start = clock();
     for (int i = 0; i < size; i++)
     {
       for (int j = 0; j < i; j++)
       {
         if (mass[j] > mass[j + 1])
         {
           tmp = mass[j];
           mass[j] = mass[j + 1];
           mass[j + 1] = tmp;
         }
       }
     }
     finish = clock();
     return (finish - start);
   }

   template<class V>
   clock_t Vector<V>::InsertionSort()
   {
     int k = 0;
     clock_t start, finish;
     start = clock();
     Vector tmp;

     for (int i = 1; i < size; i++)
     {
       tmp = mass[i];
       k = i - 1;
       while (k >= 0 && mass[k] > tmp)
       {
         mass[k + 1] = mass[k];
         k = k - 1;
       }
       mass[k + 1] = tmp;
     }
     finish = clock();
     return (finish - start);
   }

   template<class V>
   clock_t Vector<V>::QuickSort(int first, int last)
   {
     clock_t t1, t2, t3;
     t1 = clock();
     int i = first, j = last;
     Vector tmp;
     Vector x = mass[(first + last) / 2];

     do {
       while (mass[i] < x)
         i++;
       while (mass[j] > x)
         j--;

       if (i <= j)
       {
         if (i < j)
         {
           tmp = mass[i];
           mass[i] = mass[j];
           mass[j] = tmp;
         }
         i++;
         j--;
       }
     } while (i <= j);

     if (i < last)
       t3 = QuickSort(i, last);
     if (first < j)
       t3 = QuickSort(first, j);
     t2 = clock();
     return t2 - t1;
   }