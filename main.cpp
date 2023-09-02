#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
using namespace std;

//If the game ends, the input will determine if they game will continue or not
bool yesno(char a) {
  if(a == 'Y'|| a == 'y') {
    return true;
  }
  else if(a == 'N'|| a == 'n') {
    return false;
  }
}

//Display the main menu whenever the program starts
void menu() {
  cout << "----Welcome to guessing game---\n";
  cout << "Based on a small number and large number, your goal is to find the target that is between those numbers \n";
}

//Print a sub-menu for player to choose their mode
void submenu(){
  cout << "Choose a mode:\n";
  cout << "\n[1] Computer Generated low and high \n";
  cout << "[2] Manually input low and high \n\n";
  cout << "Enter a choice: ";
}

//Print the range
void print(int low, int high) {
  cout << low << " to " << high << endl << endl;;
}

//Process the input number and return the new range
string process(int low, int target, int high) {
  int ans;
  cout << "Enter a number between " << low << " and " << high <<": ";
  while(cin >> ans) {
    if(ans == target) {
      return "\nYou found it, the target is " + to_string(target) + ", do you want to play again? (Y/N)\t";
    }
    else if(ans < high && ans > target){
      high = ans;
      print(low,high);
      cout << "Enter a number between " << low << " and " << high <<": ";
    }
    else if(ans > low && ans < target){
      low = ans;
      print(low,high);
      cout << "Enter a number between " << low << " and " << high <<": ";
    }
    else {
      cout << "Either low or high is out of range\n Retype a suitable number: ";
    }
  }
}




int main() {
  srand(time(0));
  menu();
  int choice, low, target, high;
  char yn;
  bool replay = true;
  while(replay) {
  submenu();
  cin>>choice;
  
  switch (choice) {
    case 1:
      
      low = rand()% 10000;
      high = rand()%10000 + low + 1;
      target = (rand() % (high - low - 1) + low + 1);
      print(low,high);
      cout << process(low, target, high);
      cin >> yn;
      replay = yesno(yn);
      submenu();
      
    break;
    
    case 2: 
      
    cout<<"Enter low: ";
    cin >> low;
    cout <<"Enter high: ";
    cin >> high;
      
    if(low >= high) {
      while(high <= low) {
      cout << "Please enter a number larger than low \n";
      cin>>high;
      }
    }
    if(high == low+1) {
      while(high == low+1) {
      cout << "Please choose another higher number \n";
      cin >> high;
      }
  }
      
  print(low,high);
  target = (rand() % (high - low - 1) + low + 1);
  cout << process(low,target,high);
    cin >> yn;
    replay = yesno(yn);
    break;

    default:
    cout << "\nPlease enter 1 or 2\n";
    break;
    } 
    }
  }