#include <iostream>
 #include <conio.h> 
using namespace std; 
int main() {
 int a=0,e=0;
cout << "Enter a numbers: ";
 cin >> a;
 try {
 if (a%2!=0)
 { 
 	throw 'o'; 
 } 
else throw e; 
} 
catch (int e)
 { cout << "Exception: even number"; } 
catch (char o) 
{ cout << "Exception: odd number"; } 
catch(...) 
{ cout << "Exception: Unknown"; } 
getch();
 return 0;
 } 
