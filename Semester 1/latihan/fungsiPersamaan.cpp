//
//  fungsiPersamaan.cpp
//  Pert1
//
//  Created by Maya Cendana on 28/09/20.
//  Copyright © 2020 Maya Cendana. All rights reserved.
//

#include<iostream>
using namespace std;

float F(float x){
    return ((2*x) + 4);
}

int main(){
    float x;

    cout << "Nilai x = ";
    cin  >> x;

    cout << F(x) << endl;
}
