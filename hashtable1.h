#include<string>
#include<iostream>
using namespace std;

struct node {
string data;
node* next;
};

class CHash {
private:
int numberElem;
int numberCol;
int hash(string element){
int key;
int sum = 0; // represents the sum of ASCII values of the characters in the string
for (int i = 0; i < element.length(); i++) {
sum += int(element[i]);
}
key = sum % 10;
return key;
}
node* Ctable[10];
public:
CHash(){
numberCol=0;numberElem=0;
for (int i = 0; i < 10; i++)
Ctable[i]=NULL;
}
void insertItem(string d) {
node* n = new node;
n->data = d;
n->next = NULL;

int key = this->hash(d); // index represents where in the tableay the element will be stored
if (Ctable[key] == NULL) // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
{Ctable[key] = n;numberElem++;}
else {
node* p = this->Ctable[key];
while (p->next != NULL && p->data != n->data)
p = p->next;

if (p->data == n->data) {
cout << "Student exists in table" << endl;
return;
}

p->next = n;numberElem++;numberCol++;

}
}
void removeItem(string d) {

int key = this->hash(d);
if (Ctable[key]->data == d)
{Ctable[key]=NULL;numberElem--;}
else if (Ctable[key] == NULL)
cout << "Student not found" << endl;
else {
node* p = Ctable[key];
node* q = Ctable[key];
while (p != NULL && p->data != d) {
q = p;
p = p->next;
}

if (p == NULL)
cout << "Student not found" << endl;
else {
q->next = p->next;
delete p;numberElem--;
}

}
}
void Cprint(){
for (int i = 0; i < 10; i++) {
node* n = this->Ctable[i];
cout << "Elements in position " << i << " in the table: ";
while (n != NULL) {
cout << n->data << ", ";
n = n->next;
}
cout << endl;
}
}
float collisionsRate(){
    return static_cast<float>(numberCol)/static_cast<float>(numberElem);
}
};

/*#include "ChainingHash.h"
#include "DynamicHash.h"
#include <iostream>
#include <string>

using namespace std;






CHash::CHash() {
for (int i = 0; i < 10; i++)
Cstable[i]->data = NULL;
}

CHash::hash(string element) {

int key;
int sum = 0; // represents the sum of ASCII values of the characters in the string
for (int i = 0; i < element.length(); i++) {
sum += int(element[i]);
}
key = sum % 10;

return key;
}
CHash::insertItem(string element) {
node* n = new node;
n->data = element;
n->next = NULL;

int key = this->hash(element); // index represents where in the tableay the element will be stored
if (Ctable[key] == NULL) // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
Ctable[key] = n;
else {
node* p = this->Ctable[key];
while (p->next != NULL && p->data != n->data)
p = p->next;

if (p->data == n->data) {
cout << "Student exists in table" << endl;
return;
}

p->next = n;

}
}

CHash::removeItem(string element) {

int key = this->hash(element);
if (Ctable[key]->data == element)
Ctable[key]->data = NULL;
if (Ctable[key]->data == NULL)
cout << "Student not found" << endl;
else {
node* p = Ctable[key];
node* q = Ctable[key];
while (p != NULL && p->data != element) {
q = p;
p = p->next;
}

if (p == NULL)
cout << "Student not found" << endl;
else {
q->next = p->next;
delete p;
}

}
}

CHash::Cprint() {
for (int i = 0; i < 10; i++) {
node* n = this->Ctable[i];
cout << "Elements in position " << i << " in the table: ";
while (n != NULL) {
cout << n->data << ", ";
n = n->next;
}
cout << endl;
}
}*/