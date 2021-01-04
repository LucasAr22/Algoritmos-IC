#include <iostream>
#include "BSwht.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int nam = 10000;
    int t; vector<int> n = {2,5,10,20};
    //string file;
    for (int k:n){
        cout << k << endl;

        string file = "BSwht-n=" + to_string(k) + ".txt";
        ofstream out(file);

        for(int i = 0;i < nam; i++){
            t = start_dinamic(k);
            out << t << endl;
            if (i%1000 == 0){
                cout << i << endl;
            }
        }
    }
     cout << "\a\a\a" << endl;
}
