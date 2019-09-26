#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;
ofstream fout ("codes.txt");
string author="github.com/ChillSheep";
//Checks if a file exists
int main() {
srand(time(NULL));
//do not use ios_base::sync_with_stdio(false), fout.tie(NULL);
char all[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; //62
long long int nr_of_codes;
unsigned int codes_length;
    codes_length=16;
    char actualformat[codes_length];
    for (int i=0; i<codes_length; i++)
        actualformat[i]='A';
        nrofcodes:
    cout<<"How many codes to generate?\n";
    cin>>nr_of_codes;
    if(nr_of_codes<=0) {
        cout<<"The number of codes should be greater than 0.\n";
        goto nrofcodes; }

unsigned short random_all = rand() % 62;
for (int j=0; j<nr_of_codes; j++) {
//    printf("\rIn progress %d", j/divider);
//    fflush(stdout);
    fout<<"https://discordapp.com/gifts/";
    for (int character=0; character<codes_length; character++) {
                                    fout<<all[random_all];
                                    random_all = rand() % 62;
    }
    fout<<'\n';
}
cout<<"\nDone!\n";

cout<<"Press any key to exit the program."<<endl;
getch();
}
