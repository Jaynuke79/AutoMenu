#include <iostream>
#include "testFuncs.h"

using namespace std;

// #define ID "heres"
// int IDs = 10;
// template<typename T>

void menu(int,string[],void(*func[])());
void test();
void test2();
void playMenu();

// class menuss {
//   public:
//     typedef void (menuss::*action)();
//     action actions[4];
// };

int main(int argv, char* argc[]){
  // numbBetweenAB(0,50);
  // cout << ID << " + " << IDs << endl;


  // // This Allows me to save functions into an array
  // typedef void (*func)();
  // // This is how declare the function array
  // func funcs[4];
  // // This is how you define the elements
  // funcs[0] = &test;
  // funcs[1] = &test2;
  // // This is how you call the function
  // // funcs[0]();

  // string strArray[2] = {"",""};
  // menu(2, strArray, funcs);


  // cout << "Here: ";
  // test();


  return 0;
}



void menu(int i0, string array[], void (*funcs[])()){
  try {
    for (int i = 0; i < i0; i++){
      cout << i << " : " << i0 << ": ";
      funcs[i]();
      cout << endl;
    }
  } catch (...) {
    cout << i0 << " is larger than the amount of elements in the passed array" << endl;
  }
  try{
    int state = 0;
    while (state = 0){
      int stateInner = -1;

    }
  } catch (...) {
    cout << "int passed in larger than amount of elements in passed array" << endl;
  }
}

void test(){
  cout << "Herro" << endl;
}
void test2(){
  cout << "Byeee" << endl;
}