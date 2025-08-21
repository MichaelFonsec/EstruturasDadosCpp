
#include <iostream>
using namespace std;

// main function
int main()
{\
  // Array  to store 5 numbers
  double T[5]; 
  double sum; // to store sum 
  double avg; // to store result
 
  // take input values
  cout << "Enter five numbers: ";
  for (int loop = 0; loop  < 5; ++loop )
  {
    cin >> T[loop ];
  }
  
  // calculate sum value
  sum = 0;
  for (int loop  = 0; loop  < 5; ++loop )
  {
    sum += T[loop ];
  }
 
  // calculate average value
  avg = sum/5;
  
  // display result
  cout << "Sum = " << sum << endl;
  cout << "Average = " << avg << endl;
 
  return 0;
}