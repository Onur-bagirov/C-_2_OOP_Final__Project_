#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <conio.h> 
#include <cctype>

// ---------------------------------------------------- SHOW TITLE PART -------------------------------------------------------------------

using namespace std;

void main();

class Password
{
public:
	static string password()
	{
		string password;
		char pas;

		while ((pas = _getch()) != 13)
		{
			if (pas == 8 && !password.empty())
			{
				password.pop_back();
				cout << "\b \b";
			}

			else if (pas != 8)
			{
				password.push_back(pas);
				cout << "*";
			}
		}

		cout << endl;
		return password;
	}
};

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
//---------------------------------------------------- THIRT PART -------------------------------------------------------------------

class ShowCorrectAnswer
{
public:
	string corretAnswer;
	string text;

	static string Upper(const string& s)
	{
		string res = s;

		for (char& c : res)
		{
			c = toupper(c);
		}

		return res;
	}

	ShowCorrectAnswer(string t, string c)
	{
		text = t;
		corretAnswer = Upper(c);
	}
};

class Questions
{
public:
	vector<ShowCorrectAnswer> questions()
	{
		return
		{
			ShowCorrectAnswer("\t 1. Which data type is used for decimal number in Python ? (20 coin) \n\n \t\tA) Int\n \t\tB) Float\n \t\tC) Str \n\n", "B"),
			ShowCorrectAnswer("\t 2. Which function is used to take input from the user in Python ?  (20 coin)\n\n \t\tA) Read()\n \t\tB) Input()\n \t\tC) Scan() \n\n", "B"),
			ShowCorrectAnswer("\t 3. Which brackets are used to define a list in Python ?  (20 coin)\n\n \n\tA) {}\n \n\tB) ()\n \n\tC) [] \n\n", "C"),
			ShowCorrectAnswer("\t 4. Which keyword is used to define a function in Python ?  (20 coin)\n\n \t\tA) Func\n \t\tB) Function\n \t\tC) Def \n\n", "C"),
		    ShowCorrectAnswer("\t 5. Which of the following is a valid variable name in Python ?  (20 coin)\n\n \t\tA) 2value\n \t\tB) value_2 \n \t\tC) value-2 \n\n", "B")
		};
	}
};

class Quiz
{
public:
	char choice;
	int score = 0;
	int right = 0;

	void QuizPage(const vector<ShowCorrectAnswer>& questions)
	{
		system("cls");
		cin.ignore();
		cin.clear();

		cout << "\n";

		PrintText text("\t Welcome to Quiz Page !");
		text.Print();

		cout << "\n\n";

		system("cls");

		for (const auto& q : questions)
		{
			bool CheckIncluded = false;

			while (!CheckIncluded)
			{
				cout << "\n";
				cout << "\033[35m \t Welcome to Quiz Page ! \033[0m";
				cout << "\n\n";

				cout << "\n\n";

				cout << q.text << "\t \033[36m Enter answer ( A/B/C) : \033[0m";
				cin >> choice;

				cout << "\n\n";

				if (toupper(choice) == 'A' || toupper(choice) == 'B' || toupper(choice) == 'C')
				{

					CheckIncluded = true;

					if (toupper(choice) == toupper(q.corretAnswer[0]))
					{
						cout << "\n\n";
						cout << "\t\t \033[32m Your answer is correct ! \033[0m";
						cout << "\n\n";

						score += 20;
						right++;

						Sleep(2000);
					}

					else
					{
						cout << "\n\n";
						cout << "\t\t \033[31m Your answer isn't correct ! \033[0m";
						cout << "\n\n";

						cout << "\t\t \033[31m Correct answer is : \033[0m" << q.corretAnswer;
						cout << "\n\n";

						Sleep(2000);
					}
				}

				else
				{
					cout << "\n\n";
					cout << "\t\t \033[31m Error ! Please Try again ! \033[0m";
					cout << "\n\n";

					Sleep(2000);
				}

				system("cls");
			}
		}

		system("cls");

		cout << "\n";

		PrintText text_two("\t Your quiz result !");
		text_two.Print();

		cout << "\n\n";

		cout << "\t \033[36m Right Questions : " << right << " / 5 \033[0m" << endl;
		cout << "\n\n";
		cout << "\t \033[36m Score : " << score << " / 100 \033[0m" << endl;
		cout << "\n\n";

		Sleep(9000);
	}
};

//-----------------------------------------------------	SECOUND PART -------------------------------------------------------------

class SecoundMainPage
{
public:
	char choice;

	void Show()
	{
		int score;
		int right;

		system("cls");
		cin.ignore();
		cin.clear();

		cout << "\n";

		Questions questions;

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
			cout << "\t \033[33m  - Your Quiz       :  2 \033[0m" << endl;
			cout << "\t \033[33m  - Creat New Quzi  :  3 \033[0m" << endl;
			cout << "\t \033[31m  - Exit            :  4 \033[0m" << endl;

			cout << "\n\n";

			cout << "\t \033[36m Enter choice : \033[0m";
			cin >> choice;

			if (choice == '1')
			{
				Quiz q1;
				q1.QuizPage(questions.questions());

				Show();
				break;
			}

			else if (choice == '2')
			{

			}

			else if (choice == '3')
			{

			}

			else if (choice == '4')
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
			password = Password::password();

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
				cout << "\t \033[32m Enterance Successful ! \033[0m" << endl;
				cout << "\n\n";

				Sleep(2000);

				SecoundMainPage smain;
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
			password = Password::password();

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

//-------------------------------------------------------- FIRTS PART ---------------------------------------------------------------------------------------

class Page
{
	virtual void Show() = 0;
};

class MainPage : public Page
{
public:
	void Show() override
	{
		char choice;
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

			if (choice == '1')
			{
				SignUp signUp;
				signUp.UserInfo();

				break;
			}

			else if (choice == '2')
			{
				SignIn signIn;
				signIn.Include();

				break;
			}

			else if (choice == '3')
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


