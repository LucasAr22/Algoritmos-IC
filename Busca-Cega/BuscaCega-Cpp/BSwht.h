/*
Blind search for Cripto-arithmetic problem:

Puzzle: wow + hot = tea => w,h,t !=0
agents: string type => "hoteaw----" => (h=0,o=1,...,-=9)
mutation: change the order of 2 random and different digits. (restrict for equals and h,t,w in 0).
fit: f = tea - (wow + hot), solution f=0.
return: Number of atualizations of the agent that have a solution for the puzzle.

*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <fstream>
#include <math.h>
using namespace std;

int fit(string g){
    int hot = 0; int wow = 0;int tea = 0;
    for(int i = 0; i < 10; i++){
        if(g[i] == 'h')
            hot += 100*i;
        if(g[i] == 'o'){
            hot += 10*i;
            wow += 10*i;
        }
        if(g[i] == 't'){
            hot += i;
            tea += 100*i;
        }
        if(g[i] == 'e')
            tea += 10*i;
        if(g[i] == 'a')
            tea += i;
        if(g[i] == 'w'){
            wow += 100*i;
            wow += i;
        }
    }
    return abs(tea - (wow+hot));
}
string mutation(string g){
    int i,j; bool key = false; char c1;
    string ng = g;
    while(!key){

        i = rand()%10;j=rand()%10;

        if( (i != j) & (g[i] != g[j]) ){
            c1 = ng[i];
            ng[i] = ng[j];
            ng[j] = c1;
            if( (ng[0] != 'w') & (ng[0] != 'h') & (ng[0] != 't') ){
                g = ng;
                key = true;
            }else{
                ng = g;
            }
        }
    }
    return g;
}
vector<string> random_elements(int n){
    string g = "hoteaw----"; string ng = g;
    int j; char aux;
    vector<string> p;

    for(int k = 0; k < n; k++){
    ng = g;
    for (int i = 0; i< 10; i++){
        j=i;
        while (i == j){
            j = rand()%10;
        }
        aux = ng[i];
        ng[i] = ng[j];
        ng[j] = aux;
    }
    ng = mutation(ng);
    p.push_back(ng);
    }
    return p;
}
void visualize(vector<string> p){
    int f;
    for (string s:p){
        f = fit(s);
        cout << s << "\t" << f << endl;
    }
    cout << endl;
}
bool check(vector<string> p){
    bool issol = false; int f;
    for(string s:p){
        f = fit(s);
        if(f == 0){
            issol = true;
        }
    }
    return issol;
}
int start_dinamic(int n){
    vector<string> p = random_elements(n);bool key = false;
    vector<string> np; string g; int t = 1;
    while(!key){

        t+=1;
        np.clear();
        for(int i=0;i<n;i++){
            g = mutation(p[i]);
            np.push_back(g);
        }
        p = np;
        key = check(p);
    }
    return t;
}

