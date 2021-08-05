// BookStoreManage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class book 
{
private:
	char* author, * title, * publisher;
	float* price;
	int* stock;

public:
	book() 
	{
		author = new char[100];
		title = new char[100];
		publisher = new char[100];
		price = new float;
		stock = new int;
	}

	void feeddata();
	void editdata();
	void showdata();
	int search(char tbuy[100], char abuy[100]);
	void buybook();
};

void book::feeddata() 
{
	cin.ignore();
	cout << "\nEnter Author Name: "; cin.getline(author, 100);
	cout << "Enter Title Name: "; cin.getline(title, 100);
	cout << "Enter Publisher Name: "; cin.getline(publisher, 100);
	cout << "Enter Price: "; cin >> *price;
	cout << "Enter Stock Position: "; cin >> *stock;
}

void book::editdata() 
{
	cout << "\nEnter Author Name: "; cin.getline(author, 100);
	cout << "Enter Title Name: "; cin.getline(title, 100);
	cout << "Enter Publisher Name: "; cin.getline(publisher, 100);
	cout << "Enter Price: "; cin >> *price;
	cout << "Enter Stock Position: "; cin >> *stock;
}

void book::showdata() 
{
	cout << "\nAuthor Name: " << author;
	cout << "\nTitle Name: " << title;
	cout << "\nPublisher Name: " << publisher;
	cout << "\nPrice: " << *price;
	cout << "\nStock Position: " << *stock;
}

int book::search(char tbuy[100], char abuy[100])
{
	if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
		return 1;
	else return 0;
}

void book::buybook() 
{
	int count;
	cout << "\nEnter Number Of Books to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: $. " << (*price) * count;
	}
	else
		cout << "\nRequired Copies not in Stock";
}
int main()
{
	book* B[100];
	int i = 0, r, t, choice;
	char titlebuy[100], authorbuy[100];
	while (true) {
		cout << "\n\n\t\tMENU"
			<< "\n1. Entry of New Book"
			<< "\n2. Buy Book"
			<< "\n3. Search For Book"
			<< "\n4. Edit Details Of Book"
			<< "\n5. Exit"
			<< "\n\nEnter your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1: B[i] = new book;
				B[i]->feeddata();
				i++;
				break;
		case 2: cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 100);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 100);
				for (t = 0; t < i; t++) {
					if (B[t]->search(titlebuy, authorbuy)) {
						B[t]->buybook();
						break;
					}
				}
				if (t == 1)
					cout << "\nThis Book is Not in Stock";
				break;
		case 3: cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 100);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 100);

				for (t = 0; t < i; t++) {
					if (B[t]->search(titlebuy, authorbuy)) {
						cout << "\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if (t == i)
					cout << "\nThis Book is Not in Stock";
				break;
		case 4: cin.ignore();
				cout << "\nEnter Title Of Book: "; cin.getline(titlebuy, 100);
				cout << "Enter Author Of Book: ";  cin.getline(authorbuy, 100);

				for (t = 0; t < i; t++) {
					if (B[t]->search(titlebuy, authorbuy)) {
						cout << "\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if (t == i)
					cout << "\nThis Book is Not in Stock";
				break;
		case 5: exit(0);
		default: cout << "\nInvalid Choice Entered";
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
