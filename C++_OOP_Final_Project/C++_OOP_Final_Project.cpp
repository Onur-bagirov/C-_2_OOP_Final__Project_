#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdio>
#include <string>

// ------------------------------------------------------------------ SHOW TITLE PART -------------------------------------------------------------------

using namespace std;

class PrintText
{
public:
	string	Text;

	PrintText(string text)
	{
		Text = text;
	}

	void Print() 
	{
		for (int i = 0; i < Text.length(); i++) 
		{
			cout << "\033[35m" << Text[i] << "\033[0m";
			Sleep(40);
		}
		cout << endl;
	} 
};

//------------------------------------------------------------------- SIGIN IN AND SIGN UP PART -------------------------------------------------------------

void main();

class ScoundMainPage
{
public:
	int choice;

	void Show()
	{
		system("cls");
		cin.ignore();
		cin.clear();

		cout << "\n";

		PrintText text("\t Welcome to Main Page !");
		text.Print();

		cout << "\n\n";

		while (true)
		{
			system("cls");

			cout << "\n";
			cout << "\033[35m \t Welcome to Main Page ! \033[0m";
			cout << "\n\n";

			cout << "\t \033[33m  - Quiz            :  1 \033[0m" << endl;
			cout << "\t \033[33m  - Creat New Quzi  :  2 \033[0m" << endl;
			cout << "\t \033[31m  - Exit            :  3 \033[0m" << endl;

			cout << "\n\n";

			cout << "\t \033[36m Enter choice : \033[0m";
			cin >> choice;

			if (choice == 1)
			{

			}

			else if (choice == 2)
			{

			}

			else if (choice == 3)
			{

			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m False choice ! Please again ! \033[0m" << endl;
				Sleep(3000);
			}
		}
	}
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------

class SignIn
{
public:
	string line;
	string password;
	string username;

	void Include()
	{
		cin.ignore();
		cin.clear();
		system("cls");


		cout << "\n";

		PrintText text("\t  Welcome to Sign In page !");
		text.Print();

		cout << "\n\n";

		int count = 3;

		while(count > 0)
		{
			system("cls");

			cout << "\n";

			cout << "\033[35m \t Welcome to Sign In Page ! \033[0m";
			cout << "\n\n";

			cout << "\n";

			PrintText text("\t  Welcome to  Sign In page !");

			cout << "\n\n";

			cout << "\t \033[36m Enter username : \033[0m";
			cin >> username;

			cout << "\n\n";

			cout << "\t \033[36m Enter password : \033[0m";
			cin >> password;

			ifstream file("C:\\Users\\onurr\\OneDrive\\Desktop\\New Text Document (2).txt");

			if (!file.is_open()) 
			{
				cout << "\n\n";
				cout << "\t \033[31m Error opening file ! \033[0m" << endl;
				cout << "\n\n";

				return;
			}

			string username_;
			string password_;

			bool find = false;

			while (file >> username_ >> password_)
			{
				if (username_ == username && password_ == password)
				{
					find = true;
					break;
				}
			}

			file.close();

			if (find)
			{
				cout << "\n\n";
				cout << "\t \033[32m Entaerance Successful ! \033[0m" << endl;
				cout << "\n\n";

				ScoundMainPage smain;
				smain.Show();

				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m Your password or username is flase ! Please try again ! \033[0m" << endl;
				cout << "\n\n";
				count--;

				Sleep(2000);

				if (count == 0)
				{
					system("cls");
					cout << "\n\n";
					cout << "\t \033[31m If you don't have a account you can go Sign Up page ! \033[0m" << endl;
					cout << "\n\n";

					Sleep(2000);
					main();
				}
			}
	    }
	}
};

//--------------------------------------------------------------------------------------------------------------------------------------------

class SignUp
{
public:
	int choice;
	string password;
	string username;
	string surname;
	string name;

	void UserInfo()
	{
		cin.ignore();
		cin.clear();
		system("cls");

		cout << "\n";

		PrintText text("\t  Welcome to  Sign Up page !");
		text.Print();

		cout << "\n\n";

		while (true)
		{
			cout << "\t \033[36m Enter name (min character 3) : \033[0m";
			cin >> name;

			if (name.length() >= 3)
			{
				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m Your name is long ! Please try again ! \033[0m" << endl;
				cout << "\n\n";
			}
		}

		cout << "\n";

		while (true)
		{
			cout << "\t \033[36m Enter surname (min character 5) : \033[0m";
			cin >> surname;

			if (surname.length() >= 5)
			{
				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m Your surname is long ! Please try again ! \033[0m" << endl;
				cout << "\n\n";
			}
		}

		cout << "\n";

		while (true)
		{
			cout << "\t \033[36m Enter username (min character 6) : \033[0m";
			cin >> username;

			if (username.length() >= 6)
			{
				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m Your user name is long ! Please try again ! \033[0m" << endl;
				cout << "\n\n";
			}
		}

		cout << "\n";

		while (true)
		{
			cout << "\t \033[36m Enter password (min len 7) : \033[0m";
			cin >> password;

			if (password.length() >= 7)
			{
				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t \033[31m Your password is long ! Please try again ! \033[0m" << endl;
				cout << "\n\n";
			}
		}

		SaveFile();
	}

	//---------------------------------------------------------------- USER INFORMATION SAVE PART ---------------------------------------------------------------

	void SaveFile() 
	{
		ofstream file("C:\\Users\\onurr\\OneDrive\\Desktop\\New Text Document (2).txt", ios::app); // ios::app - User melumatlari file elave edir.

		if (file.is_open()) 
		{
			file << "  " << username << "  " << password << "  " << name << "  " << surname << endl;
			file.close();

			cout << "\n\n";
			cout << "\t \033[32m User saved successfully ! \033[0m" << endl;
			cout << "\n\n";

			Sleep(3000);

			SignIn signIn;
			signIn.Include();
		}

		else 
		{
			cout << "\n\n";
			cout << "\t \033[31m Error saving user ! \033[0m" << endl;
			cout << "\n\n";
		}
	}
};

//------------------------------------------------------------------ MAIN PAGE PART ---------------------------------------------------------------------------------------

class Page
{
	virtual void Show() = 0;
};

class MainPage : public Page
{
public:
	void Show() override
	{
		int choice;
		cout << "\n";

		PrintText text("\t Welcome to Main Page !");
		text.Print();

		cout << "\n\n";
		while (true)
		{
			system("cls");

			cout << "\n";
			cout << "\033[35m \t Welcome to Main Page ! \033[0m";
			cout << "\n\n";

			cout << "\t \033[33m  - Sign Up  :  1 \033[0m" << endl;
			cout << "\t \033[32m  - Sign In  :  2 \033[0m" << endl;
			cout << "\t \033[31m  - Exit     :  3 \033[0m" << endl;

			cout << "\n\n";

			cout << "\t \033[36m Enter choice : \033[0m";
			cin >> choice;

			if (choice == 1)
			{
				SignUp signUp;
				signUp.UserInfo();

				break;
			}

			else if (choice == 2)
			{
				SignIn signIn;
				signIn.Include();

				break;
			}

			else if (choice == 3)
			{
				system("cls");

				cout << "\n\n";
				cout << "\t \033[31m Exit Program ! \033[0m" << endl;

				cout << "\n";

				cout << "\t  God Bye !";

				exit(0);
			}

			else
			{    
				cout << "\n\n";
				cout << "\t \033[31m False choice ! Please again ! \033[0m" << endl;
				Sleep(3000);
			}
		}
	}
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------

void main()
{
	system("cls");

	MainPage page;
	page.Show();
}


