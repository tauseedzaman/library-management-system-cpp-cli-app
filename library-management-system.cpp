/*
*App Name: library management system
*IDE		 : Dev-c++ 
*Description : This is a simple library management system .
*auther		 : tauseed zaman
*/
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <windows.h>
using namespace std;
void add_book(){
	system("cls");
	string username , password, admin_username = "tauseedzaman" , admin_password = "tauseedzaman";
	cout<<"\n\tPlease dont't try to login if you are not admin here\n";
	cout<<"\n\tEnter admin username : ";
	cin>>username;
	cout<<"\n\tEnter admin password: ";
	cin>>password;
// username and password both are tauseedzaman if you want you can change at to what ever you want
	if(username == admin_username && password == admin_password){	
		cout<<"\n\t\t----------------------Welcome back "<<username<<"-------------------------\n";
		char book_name[100],book_auther[100];
		int book_price;
			cout<<"\n\t\tAdding Book To Library!\n";
			cout<<"\n\tEnter Book Name:";
			cin>>book_name,100;
			
			cout<<"\n\tEnter Book Auther Name:";
			cin>>book_auther;
			
			cout<<"\n\tEnter Book Price:";
			cin>>book_price;
			
			ofstream file("library.txt",ios::app);	//open file with append mode
			file<<"Book Name   : "<<book_name<<"\n"<<"Book Auther : "<<book_auther<<"\n"<<"Book Price  : "<<book_price<<"\n\n";
			
			cout<<"\tBook Added \n\tClosing File.\n";
			file.close();
	}
	else{
		cout<<"\n\tinvalid username or password";
		cout<<"\n\thit any key to continue.";
		while(!kbhit()){
			continue ; 
		}
	}
}
void show_books(){
	system("cls");
		cout<<"\n\n\tShowing Avilable Books!\n\n";
		ifstream readfile("library.txt"); 	//open file with reading mode
		string tp;
		cout<<"\n\t\tAll Books\n";
		cout<<"\t\t----------------------\n\n";
		while(getline(readfile, tp)) {
			cout <<"\t\t"<< tp << "\n";
		}
		cout<<"\n\n";
}
void get_book(){
	system("cls");
	char name[100];
	char op_get_bok;
	cout<<"\n\n\tShowing Avilable Books!\n\n";
		ifstream readfile("library.txt"); 	//open file with reading mode
		string tp;
		cout<<"\n\t\tAll Books\n";
		cout<<"\t\t----------------------\n\n";
		while(getline(readfile, tp)) {
			cout <<"\t\t"<< tp << "\n";
		}
		cout<<"\n";
	cout<<"\n\t\tEnter Name Of Book You Wants to buy.\n\t\t";
	cin>>name;
	cout<<"\n\t\tDO you realy want to buy "<<name<<" book"<<" form our library[y/n]:"; 
	cin>>op_get_bok;
	if(op_get_bok == 'y'){
		cout<<"\n\t\tThank you for choose us\n\n\t\tYou Buy "<<name<<" book from our library .";
		cout<<"\n\t\t press any key to continue.\t\t";
		while(!kbhit()){
			continue;
		}
		cout<<"\n";
	}
	else{
		return ;
	}
}
void settings(){
	char clr;
	cout<<"\n\t\tChoose text color from the following \n\t\ta. blue\t\tb. yellow\n\t\tc. Green \n\t\t";
	cin>>clr;
	if(clr == 'a'){
		system("Color 9");
	}
	else if(clr == 'b'){
		system("Color 6");
	}else if(clr == 'c'){
		system("Color A");
	}
}
int main() { //main function goes here
	char option;
	do {
		cout<<"\n\t\t____________________ Welcome to ZAMAN Library __________________________\n\n";
		system("Color 0"); //change color
		cout<"\n\n";
		cout<<"\t**Choose form the following options**\n\n\ta ==> Show All Books \t\t\t b ==> Add New Book to library \n\tc ==> Settings\t\t\t\t d ==> Buy a book\n\te ==> clear screen\n\tx ==> Exit ";
		cin>>option;
		if(option == 'b'){
			add_book();
		}
		else if(option == 'a'){
		show_books();
		
		}
		else if(option == 'c'){
		settings();
		
		}
		else if(option == 'd'){
		get_book();
		}	
		else if(option == 'e'){
		system("cls");
		}		
	} while(option != 'x');
}


