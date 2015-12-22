#include <string>
#include <fstream>
#include <iostream>

#include "outofc.hpp"
#include "OS.hpp"

using namespace std;


int ptexp(){
    int age = 39;
    int* agept = &age;
    
    cout << "Address of age is "<< agept << endl;
    cout << "Value at above address is "<< *agept << endl;
    
    
    int arr[5] = {1, 4, 7, 3 ,5};
    for(int i=0; i<5; i++){
        cout << arr[i] << endl;
    }
    
    int* arrpt = arr;
    
    cout << "ARR_PT= " << arrpt  <<" & value= " << *arrpt <<endl;
    
    cout << "Address \t Value" <<endl;
    for(int i=0; i<5; i++)
    {
        cout << arrpt << "\t   " << *arrpt <<endl;
        arrpt++;
    }
    
    int age2 = 45;
    int& age2ref = age2;
    
    cout << "age2=" <<age2 <<endl;
    cout << "age2ref= "<<age2ref <<endl;
    
    cout << "Enter a value :";
    cin >> age2;
    cout << "You entered "<< age2 <<endl;
    cout << &age2 << endl;
    
    string s="abc";
    string* pt_s= &s;
    
    cout <<"Value at "<<pt_s<<" is "<<*pt_s<<endl;
    return 0;
}

int fileexp(){
    ofstream write("abc.txt");
    if(! write){
        cout << "Error opening file "<<endl;
        return -1;
    }else{
        write << "File example " <<endl;
        write.close();
        
    }
    
    string addata;
    cout <<"Enter a string :";
    cin >> addata;
    ofstream write2("abc.txt", ios::app);
    if(! write2){
        cout <<"Error opening file ";
        return -1;
    }else{
        write2 << "You have entered  "<< addata <<endl;
        write2.close();
        
    }

    
    char letter;
    ifstream read("abc.txt");
    if(! read){
        cout << "Error opening file"<< endl;
        return -1;
    }else{
        for(int i=0; ! read.eof(); i++)
        {
            read.get(letter);
            cout << letter;
        }
        cout << endl;
        read.close();
    }
    
    
    
    return 0;
}



int excexp(){
    
    int number;
    cout << "Enter a number :";
    cin >> number;
    try {
        if(number != 0){
            cout << 1000/number <<endl;
            
        }else throw(number);
    }catch(int num){
        cout << num << " is not valid" <<endl;
    }
    
    return 0;
}




class classexp{
 
private:
    int priv_a=12, priv_b=14;
public:
    //int pub_a, pub_b;
    
    
    int classfunc();
    int pub_a=(priv_a/2);
    int pub_b=(priv_b/2);
};

int classexp::classfunc()
{
    this -> priv_a= 20;
    this -> priv_b= 24;
    return 0;
}
int addnum()
{
    
    int a=12, b=15;
    cout << (a+b) <<endl;
    return 0;
}


int main(){
    
    cout << addnum() << endl;
    //system("clear");
    
    int option;
    string s;
    cout <<"Size of s is "<< s.max_size()<<" capicity is "<<s.capacity()<<endl;
    cout << "Enter your choice :";
    cin >> option;
    
    switch(option){
case 1:
    cout << ptexp() << endl;
    break;
    
case 2:
    cout << getOsName()<< endl;
            break;
case 3:
            cout << fileexp();
            break;
case 4:
            char op;
        syslabel:
            cout << "Open location in Finder [Y/N]:";
            cin >> op;
            if(op=='Y'|| op=='y')
            {
                system("open ./");
            }else if(op=='N'|| op=='n')
            {
                cout <<"Program Ends" <<endl;
            }
            else{
                cout<<"Enter a valid choice"<<endl;
                goto syslabel;
            }
            break;
case 5:
            cout << excexp() <<endl;
            break;
        case 6:
        {
            classexp ob;
            cout << ob.pub_a << endl << ob.pub_b <<endl;
            ob.classfunc();
            cout << ob.pub_a << endl << ob.pub_b <<endl;
            break;
    }
        case 7:
            cout << xyz();
           // cout << head();
default:
            cout<<"Enter a valid choice" <<endl;
            break;
            
    }
    
    
   return 0;
}

