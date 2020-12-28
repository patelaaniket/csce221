// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time  

#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

ostream& operator<<(ostream& out, vector<int>& v)
{
  for (int i = 0; i < v.size(); i++) {
    if (i != v.size() - 1) {
      out << v[i] << ",";
    }
    else {
      out << v[i] << endl;
    }
  }
  return out;
}

void sort_heaviest(vector<int>& v){
  comparisons = 0;
  vector<int> out;
  int heaviest;
  int idx;
  for (int i = v.size(); i > 0; i--) {
    heaviest = v[0];
    idx = 0;
    for (int j = 1; j < i; j++) {
      comparisons++;
      if (v[j] > heaviest) {
        heaviest = v[j];
        idx = j;
      }
    }
    out.push_back(heaviest);
    v.erase(v.begin() + idx);
  }
  v = out;
}

int main()
{
 
  cout << "//////Test 1 for vector v ///////////////////////////////"<< endl;
  vector<int> v{10,9,8,7,6,5,4,3,2,1};

  cout << "initial vector v:\n";
  // use overloaded output operator to display vector's elements
  cout << v;
  // use comma to separate the vector's elements
  cout << endl;
  // call the sorting function for vector v 
  sort_heaviest(v);
  cout << "# of comparisons to sort v: " << comparisons << endl << endl;
  cout << "vector v after sorting:\n";
  // use overloaded output operator to display elements of sorted vector
  cout << v;
  // use comma to separate the vector's elements
  cout << endl;
  
  cout << "//////Test 2 for vector v1 ///////////////////////////////"<< endl;

  vector<int> v1{1,2,3,4,5,6,7,8,9,10};
  cout << "initial vector v1:\n";
  // use overloaded output operator to display vector's elements
  cout << v1;
  // use comma to separate the vector's elements
  cout << endl;
   // call the sorting function for vector v2 
  sort_heaviest(v1);
  cout << "# of comparisons to sort v1: " << comparisons << endl << endl;
  cout << "vector v1 after sorting:\n";
  // use overloaded output operator to display elements of sorted vector
  cout << v1;
  // use comma to separate the vector's elements
  cout << endl;

  cout << "//////Test 3 for vector v2 ///////////////////////////////"<< endl;

  vector<int> v2{5,10,3,9,1,6,2,8,4,7,11};
  cout << "initial vector v2:\n";
  // use overloaded output operator to display vector's elements
  cout << v2;
  // use comma to separate the vector's elements
  cout << endl;
   // call the sorting function for vector v2 
  sort_heaviest(v2);
  cout << "# of comparisons to sort v2: " << comparisons << endl << endl;
  cout << "vector v2 after sorting:\n";
  // use overloaded output operator to display elements of sorted vector
  cout << v2;
  // use comma to separate the vector's elements
  cout << endl;
    
}
