#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
ofstream fout ("codes.txt");
string author="github.com/ChillSheep";
int main() {
srand(time(NULL));
char letters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26
char numbers[]="0123456789"; //10
long long int nr_of_codes;
unsigned int codes_length;
unsigned int x_for_minus;

    start:
cout<<"How many characters should the codes have?"<<endl;
cin>>codes_length;
if(codes_length<=0) {
    cout<<"The length should be greater than 0."<<endl;
    goto start; }

    nrofcodes:
cout<<"How many codes to generate?"<<endl;
cin>>nr_of_codes;
if(nr_of_codes<=0) {
    cout<<"The number of codes should be greater than 0."<<endl;
    goto nrofcodes; }

    xforminus:
cout<<"Do you want to have a '-' after every x characters?"<<endl;
cout<<"Type 0 for no or any number for x="<<endl;
cin>>x_for_minus;
    if (x_for_minus<0) {
        cout<<"X should be at least 0"<<endl;
        goto xforminus; }

unsigned short random_letter = rand() % 26;
unsigned short random_number = rand() %10;
unsigned short letter_or_number = rand() % 1;
unsigned int iterations=0;
for (int j=0; j<nr_of_codes; j++) {
    iterations=0;
    for (int i=0; i<codes_length; i++) {
    iterations++;
    if (x_for_minus)
        if (iterations%x_for_minus==0)
            fout<<'-';
    letter_or_number = rand() % 2;
        if (letter_or_number) {
            fout<<numbers[random_number];
            random_number = rand() %10; }
        else {
            fout<<letters[random_letter];
            random_letter = rand() % 26; }

}
    fout<<endl;
}
cout<<"Done!"<<endl;
cout<<"Press any key to exit the program."<<endl;
getch();
}
