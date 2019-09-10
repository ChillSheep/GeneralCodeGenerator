#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <sys/stat.h>
using namespace std;
ofstream fout ("codes.txt");
string author="github.com/ChillSheep";
//Checks if a file exists
inline bool exists (const std::string& filename) {
  struct stat buffer;
  return (stat (filename.c_str(), &buffer) == 0);
}
int main() {
srand(time(NULL));
char letters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //26
char allletters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //52
char smallletters[]="abcdefghijklmnopqrstuvwxyz"; //26
char numbers[]="0123456789"; //10
char all[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"; //62
long long int nr_of_codes;
unsigned int codes_length;
unsigned int x_for_minus;
unsigned short formattype;
char actualformat[1];
short is;
    if(exists("settings")) { //if the settings file exists you can try to load it
        cout<<"Press 1 to load your settings from last time"<<endl;
        cin>>is; }
        if (is==1) {
            ifstream saves("settings");
            saves>>codes_length;
            char actualformat[codes_length];
            saves>>nr_of_codes;
            saves>>x_for_minus;
            saves>>formattype;
            if (formattype==1) {
            saves>>actualformat;
            } }
    else {
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

        format:
    cout<<"Do you want to use the default or a custom format?"<<endl;
    cout<<"The custom format has 8 random characters, either a big letter or a number"<<endl;
    cout<<"Type 0 for default or 1 for custom"<<endl;
    cin>>formattype;
    if (formattype!=0 && formattype!=1) { //we are testing if the format type is correct.
        cout<<"Type either 0 or 1";
        goto format; }
    char actualformat[codes_length];

//for (int test=0; test<codes_length; test++)
//    actualformat[test]='N';

        formattypee:
    if (formattype==1) {
            cout<<"Type L for big letter N for a number, s for small letter, l for any letter, A for any"<<endl;
            gets(actualformat);
            gets(actualformat); //for some reason it won't work with only 1 gets???
            for(int a=0; a<codes_length; a++) //we are testing if the format is correct.
                if (actualformat[a]!='L' & actualformat[a]!='N' & actualformat[a]!='s' & actualformat[a]!='l' & actualformat[a]!='A' ) {
                    cout<<"You entered one or more wrong letters for the format or too little"<<endl;
                    goto formattypee; }
    } }

unsigned short random_letter = rand() % 26;
unsigned short random_number = rand() %10;
unsigned short letter_or_number = rand() % 1;
unsigned short random_all_letter = rand() % 52;
unsigned short random_small_letter = rand() % 26;
unsigned short random_all = rand() % 62;
unsigned int iterations=0;
for (int j=0; j<nr_of_codes; j++) {
    iterations=0;
    for (int character=0; character<codes_length; character++) {

        if (x_for_minus)
            if (iterations%x_for_minus==0 & iterations!=0)
                fout<<'-';
            if (formattype==0) {
                letter_or_number = rand() % 2;
                if (letter_or_number) {
                    fout<<numbers[random_number];
                    random_number = rand() %10; }
                else {
                    fout<<letters[random_letter];
                    random_letter = rand() % 26; } }
            else
            {
                    if (actualformat[character]=='l') {
                        fout<<allletters[random_all_letter];
                        random_all_letter = rand() % 52;
                    }
                    else
                        if (actualformat[character]=='L') {
                            fout<<letters[random_letter];
                            random_letter = rand() % 26;
                        }
                        else
                            if (actualformat[character]=='N'){
                                fout<<numbers[random_number];
                                random_number = rand() %10;
                            }
                            else
                                if (actualformat[character]=='s') {
                                    fout<<smallletters[random_small_letter];
                                    random_small_letter = rand() % 26;
                                }
                                else
                                {
                                    fout<<all[random_all];
                                    random_all = rand() % 62;
                                }
    iterations++;
            }

    }
    fout<<endl;
}
cout<<"Done!"<<endl;
if (is!=1) {
    cout<<"Do you want to save your settings to a file? 1 for yes"<<endl;
    short answer_to_save;
    cin>>answer_to_save;
    if (answer_to_save==1) {
        ofstream save("settings");
        save<<codes_length<<endl;
        save<<nr_of_codes<<endl;
        save<<x_for_minus<<endl;
        save<<formattype<<endl;
        if(formattype)
            save<<actualformat<<endl;
        save.close(); } }
cout<<"Press any key to exit the program."<<endl;
getch();
}
