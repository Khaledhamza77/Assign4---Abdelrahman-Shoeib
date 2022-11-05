#include"hashtable1.h"
#include"hashtable2.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    CHash hashLL;
    hashLL.insertItem("Mina");
    hashLL.insertItem("Fawzy");
    hashLL.insertItem("Yara");
    hashLL.insertItem("Mariam");
    hashLL.insertItem("Ayman");
    hashLL.insertItem("Roshdy");
    hashLL.insertItem("Aya");
    hashLL.insertItem("Abdallah");
    hashLL.insertItem("Fatma");
    hashLL.Cprint();
    cout<<"Collision Rate: "<<hashLL.collisionsRate()<<endl;
    return 0;
}