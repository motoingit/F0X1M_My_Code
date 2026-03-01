// Plus Pattern
//  Enter Row and Col : 7 7
//       *       
//       *       
//       *       
// * * * * * * * 
//       *
//       *
//       *

#include<iostream> 
using namespace std;

int main(){
    int row, col;
    cout << " Enter Row and Col : ";
    cin >> row >> col;
    
    if( !( (row%2 != 0) && (row >= 3) && (col%2 != 0) && (col >= 3) ) ){ //normal condition
        cout << "Wrrog";
        return 0;
    }
    
    int iMid = row / 2,   jMid = col / 2;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(j == jMid || i == iMid)
                cout << "* ";
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }


return 0;}

