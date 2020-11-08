#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int initalNum = 0;
  int inNum;
  int outNum;
  int i=0;
  cout << "\nThis program calculates number of passengers in a bus.";
  
  //Get user input for initial number of passengers in the bus
  cout << "\nEnter initial number of passengers in the bus. ";
  cin >> initalNum;
  
  //While loop to run continously for user input of person getting in and out of bus at each station 
  while(true) {
    cout << "Enter number of passengers getting in and off the bus at station " << i + 1 << ": ";
    scanf("%d %d", & inNum, & outNum);
    if (inNum < 0 || outNum < 0) {
      break;
    }
    initalNum = initalNum + (inNum - outNum);
    
    //Display the number of passengers in the bus after every station
    cout << "Number of passengers in the bus after station " << i + 1 << ": " << initalNum;
    cout << "\n";
    i++;
  }

  return 0;
}
