#include <string>
#include<iostream>
using namespace std;

class dynamicHash {
private:
int numberElem, numberCol;
int hash(string element);
string* table;
public:
dynamicHash() {
numberCol=0;numberElem=0;
table = new string[10];
for (int i = 0; i < 10; i++)
this->table[i] = "";
}
void insertItem(string element) {
int key = hash(element); // index represents where in the tableay the element will be stored
if (this->table[key] == "") // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
{this->table[key] = element;numberElem++;}
else {
int start = key; // to store the starting point, if the loop passes on this starting point again, then the tableay is full
while (this->table[key] != "") {
key=(key+1)%10; // to stay within the 10 of the table
if (key == start) {
cout << "Table is full" << endl;
return;
}
}
this->table[key] = element;numberElem++;numberCol++;
}
}
void removeItem(string element){

int key = hash(element);
if (table[key] == element)
{table[key] = "";numberElem--;}
else {
int start = key; // to store the starting point, if the loop passes on this starting point again, then the element is not in the table
while (this->table[key] != element) {
key=(key+1)%10;
if (key == start) {
cout << "Element not found " << endl;
return;
}
}
table[key] = "";numberElem--;
}
}
void print() {
for (int i = 0; i < 10; i++) {
cout << "Element " << i << " in the table is: " << table[i] << endl;
}
}
float collisionsRate(){
    return static_cast<float>(numberCol)/static_cast<float>(numberElem);
}
};

/*dynamicHash::dynamicHash() {
for (int i = 0; i < 10; i++)
this->table[i] = NULL;
}

dynamicHash::hash(string element) {

int key;
int sum = 0; // represents the sum of ASCII values of the characters in the string
for (int i = 0; i < element.length(); i++) {
sum += int(element[i]);
}
key = sum % 10;

return key;
}
dynamicHash::insertItem(string element) {
int key = hash(element); // index represents where in the tableay the element will be stored
if (this->table[key] == NULL) // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
this->table[key] = element;
else {
int start = key; // to store the starting point, if the loop passes on this starting point again, then the tableay is full
while (this->table[key] != NULL) {
key++;
if (key == 10)
key = 0; // to stay within the 10 of the table
if (key == start) {
cout << "Table is full" << endl;
return;
}
}
this->table[key] = element;
}

}

dynamicHash::removeItem(string element) {

int key = hash(element);
if (table[key] == element)
table[key] = NULL;
else {
int start = key; // to store the starting point, if the loop passes on this starting point again, then the element is not in the table
while (this->table[key] != element) {
key++;
if (key == 10)
key = 0;
if (key == start) {
cout << "Element not found " << endl;
return;
}
}
table[key] = NULL;
}
}

dynamicHash::print() {
for (int i = 0; i < 10; i++) {
cout << "Element " << i << " in the table is: " << table[i] << endl;
}
}*/