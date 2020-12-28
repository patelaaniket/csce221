// resize an array

#include <iostream>

using namespace std;

int comp  = 0;

struct Array {
  int *array;
  int size;
  Array(int* a, int n) : array(a), size(n) {}
};



ostream& operator<<(ostream& out, Array& A)
{
  for (int i=0; i < A.size; ++i)
    out << A.array[i] << " ";
  out << endl;
  return out; 
}

void guess_sort(Array& A) 
{
  for (int k=1; k < A.size; ++k) {  
    for (int i=0; i < A.size-1; ++i) 
      if ( comp++, A.array[i+1] < A.array[i]) {
	int tmp = A.array[i]; // swap
	A.array[i] = A.array[i+1]; 
	A.array[i+1] = tmp;
      }
  }
}

int main()
{ // declare and initialize a dynamic array of integers of sizes 4 and 7
  // arranged in increasing order
  Array A1(new int[4], 4);
  for (int i = 0; i < 4; i++) {
      A1.array[i] = i * 2;
  }
  Array A2(new int[7], 7);
  A2.array[0] = 7;
  A2.array[1] = 6;
  A2.array[2] = 5;
  A2.array[3] = 4;
  A2.array[4] = 3;
  A2.array[5] = 2;
  A2.array[6] = 1;
  Array A3(new int[4], 4);
  Array A4(new int[7], 7);
   
  cout << "Array A1 before sorting:" << endl;
  //Use the constructor of type Array to instantiate an object A1 of that type

  cout << A1 << endl;
  //call guess_sort for A1
  guess_sort(A1);
  cout << " A1 after sorting:" << endl;
  cout << A1;
  cout << "# of comparisons = " << comp << endl;
  cout <<endl<< "///////////////////////////////////////////////////"<< endl;

  comp = 0;
  // declare and initialize a dynamic array of integers of sizes 4 and 7
  // arranged in decreasing order
  
  //Use the constructor of type Array to instantiate an object A2 of that type
  
  cout << "Array A2 before sorting:" << endl;
  cout << A2 << endl;
  //call guess_sort for A2
  guess_sort(A2);
  cout << "A2 after sorting:" << endl;
  cout << A2;
  cout << "# of comparisons = " << comp << endl;
  
  cout <<endl<< "///////////////////////////////////////////////////"<< endl;  
}