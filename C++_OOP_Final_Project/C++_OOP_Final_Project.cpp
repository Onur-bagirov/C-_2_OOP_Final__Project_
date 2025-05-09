#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <conio.h> 
#include <cctype>

// ---------------------------------------------------- SHOW TITLE PART -------------------------------------------------------------

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
}; // Passwordu ulduz cevirmek ucun class

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
}; // Texti animasiya vermek ucun class

class ToUpper
{
public:
	static string Upper(const string& s)
	{
		string res = s;

		for (char& c : res)
		{
			c = toupper(c);
		}

		return res;
	}
}; // Stringleri boyutmek ucun fuksiya

//---------------------------------------------------- THIRT PART -------------------------------------------------------------------

class ShowCorrectAnswer
{
public:
	string corretAnswer;
	string text;

	ShowCorrectAnswer(string t, string c)
	{
		text = t;
		corretAnswer = ToUpper::Upper(c);
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
			ShowCorrectAnswer("\t 3. Which brackets are used to define a list in Python ?  (20 coin)\n\n \t\tA) {}\n \t\tB) ()\n \t\tC) [] \n\n", "C"),
			ShowCorrectAnswer("\t 4. Which keyword is used to define a function in Python ?  (20 coin)\n\n \t\tA) Func\n \t\tB) Function\n \t\tC) Def \n\n", "C"),
		    ShowCorrectAnswer("\t 5. Which of the following is a valid variable name in Python ?  (20 coin)\n\n \t\tA) 2value\n \t\tB) value_2 \n \t\tC) value-2 \n\n", "B")
		};
	}
};

class Quiz
{
public:
	string choice;
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

		for (const auto& q : questions)
		{
			bool CheckIncluded = false;

			while (!CheckIncluded)
			{
				system("cls");

				cout << "\n";
				cout << "\033[35m \t Welcome to Quiz Page ! \033[0m";
				cout << "\n\n";

				cout << "\n\n";

				cout << q.text << "\t \033[36m Enter answer ( A/B/C) : \033[0m";
				cin >> choice;

				cin.ignore();

				cout << "\n\n";

				if (choice.length() == 1 && (toupper(choice[0]) == 'A' || toupper(choice[0]) == 'B' || toupper(choice[0]) == 'C'))
				{

					CheckIncluded = true;

					if (toupper(choice[0]) == toupper(q.corretAnswer[0]))
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

		cout << "\n";

		PrintText text_two("\t Your quiz result !");
		text_two.Print();

		cout << "\n\n";

		cout << "\t \033[36m Right Questions : " << right << " / 5 \033[0m" << endl;
		cout << "\n\n";
		cout << "\t \033[36m Score : " << score << " / 100 \033[0m" << endl;
		cout << "\n\n";

		Sleep(5000);
	}
};

struct Question
{
	string Question_c;
	string A;
	string B;
	string C;
	string TrueAnswer;
};

class CreateQuiz 
{
public:
	vector<Question> questions;

	void Create()
	{
		system("cls");
		cin.ignore();
		cin.clear();

		cout << "\n";

		PrintText text("\t Welcome to Create Question Page !");
		text.Print();

		cout << "\n\n";

		for (int i = 0; i < 5; ++i)
		{
			system("cls");

			cout << "\n";
			cout << "\033[35m \t Welcome to Create Question Page ! \033[0m";
			cout << "\n\n";

			Question q;
			cout << "\n\n";

			cout << "\t" << i + 1 << ". ";
			getline(cin, q.Question_c);

			cout << "\n";

			cout << "\t\t A) ";
			getline(cin, q.A);

			cout << "\t\t B) ";
			getline(cin, q.B);

			cout << "\t\t C) ";
			getline(cin, q.C);

			cout << "\n";

			while (true)
			{
				cout << "\t \033[36m Enter true answer (A/B/C) : \033[0m";
				getline(cin, q.TrueAnswer);

				q.TrueAnswer = ToUpper::Upper(q.TrueAnswer);

				if (q.TrueAnswer == "A" || q.TrueAnswer == "B" || q.TrueAnswer == "C")
				{
					break;
				}

				cout << "\n\n";
				cout << "\t\t \033[31m Incorrect answer! Try again ! \033[0m";
				cout << "\n\n";
			}

			questions.push_back(q);

			cout << "\n\n";
			cout << "\t\t \033[32m Question successfully introduced ! \033[0m";
			cout << "\n\n";

			Sleep(2000);
			system("cls");
		}

		cout << "\n\n";
		cout << "\t\t \033[32m All questions have been successfully introduced ! \033[0m";
		cout << "\n\n";

		Sleep(2000);
	}
};

class YourQuiz
{
public:
	string choice;
	int score = 0;
	int right = 0;

	void Answer(const vector<Question>& questions)
	{
		system("cls");
		cin.ignore();
		cin.clear();

		PrintText text("\t Welcome to Quiz Page !");
		text.Print();

		for (int i = 0; i < questions.size(); ++i)
		{
			const Question& q = questions[i];

			while (true)
			{
				system("cls");

				cout << "\n";

				cout << "\033[35m \t Welcome to Quiz Page ! \033[0m";
				cout << "\n\n";

				cout << "\t" << i + 1 << ". " << q.Question_c << "\n\n";
				cout << "\t\t A) " << q.A << "\n";
				cout << "\t\t B) " << q.B << "\n";
				cout << "\t\t C) " << q.C << "\n\n";

				cout << "\n\n";

				cout << "\t \033[36m Enter answer (A/B/C) : \033[0m";
				cin >> choice;

				cout << "\n\n";

				if (choice.length() == 1 && (toupper(choice[0]) == 'A' || toupper(choice[0]) == 'B' || toupper(choice[0]) == 'C'))
				{
					if (toupper(choice[0]) == toupper(q.TrueAnswer[0]))
					{

						cout << "\n\n";
						cout << "\t\t \033[32m Your answer is correct! \033[0m";
						cout << "\n\n";

						Sleep(2000);

						score += 20;
						right++;
					}
					else
					{
						cout << "\n\n";
						cout << "\t\t \033[31m Your answer isn't correct! \033[0m";
						cout << "\n\n";

						cout << "\t\t \033[31m Correct answer is: \033[0m" << q.TrueAnswer;
						cout << "\n\n";

						Sleep(2000);
					}

					system("cls");
					break;

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

		PrintText resultText("\t Your quiz result !");
		resultText.Print();

		cout << "\n\n";
		cout << "\t \033[36m Right Questions : " << right << " / " << questions.size() << " \033[0m\n";
		cout << "\n";
		cout << "\t \033[36m Score : " << score << " / " << questions.size()<< " \033[0m\n\n";

		Sleep(5000);
	}
};

//-------------------------------------------------- SECOUND PART ----------------------------------------------------------------------

class SecundMainPage
{
public:
	int score;
	int right;
	CreateQuiz quiz;
	string choice;
	Questions Questions;;

	void Show()
	{
		system("cls");

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
			cout << "\t \033[33m  - Your Quiz       :  2 \033[0m" << endl;
			cout << "\t \033[33m  - Creat New Quiz  :  3 \033[0m" << endl;
			cout << "\t \033[31m  - Exit            :  4 \033[0m" << endl;

			cout << "\n\n";

			cout << "\t \033[36m Enter choice : \033[0m";
			cin >> choice;

			if (choice == "1")
			{
				Quiz q1;
				q1.QuizPage(Questions.questions());

				Show();
				break;
			}

			else if (choice == "2")
			{
				if (quiz.questions.empty())
				{
					cout << "\n\n";
					cout << "\t\t \033[31m No quiz found ! \033[0m";
					cout << "\n\n";
					Sleep(2000);
					continue;
				}

				YourQuiz yq;
				yq.Answer(quiz.questions);

				Show();
				break;
			}

			else if (choice == "3")
			{
				quiz.Create();
				continue;

				Show();
				break;
			}

			else if (choice == "4")
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
				cout << "\t\t \033[31m Incorrect choice ! Please again ! \033[0m" << endl;
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
	int count = 3;

	void Include()
	{
		cin.ignore();
		cin.clear();
		system("cls");

		cout << "\n";

		PrintText text("\t  Welcome to Sign In page !");
		text.Print();

		cout << "\n\n";

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
				cout << "\t\t \033[31m File isn't open ! \033[0m" << endl;
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
				cout << "\t\t \033[32m Introduction Successful ! \033[0m" << endl;
				cout << "\n\n";

				Sleep(2000);

				SecundMainPage smain;
				smain.Show();

				break;
			}

			else
			{
				cout << "\n\n";
				cout << "\t\t \033[31m Your password or username is incorrect ! Please try again ! \033[0m" << endl;
				cout << "\n\n";

				count--;
				cout << "\t\t \033[31m Your remainin chance : \033[0m" << count << endl;
				cout << "\n\n";

				Sleep(2000);

				if (count == 0)
				{
					system("cls");
					cout << "\n\n";
					cout << "\t\t \033[31m If you don't have a account you can go Sign Up page ! \033[0m" << endl;
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
				cout << "\t\t \033[31m Your name is short ! Please try again ! \033[0m" << endl;
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
				cout << "\t\t \033[31m Your surname is short ! Please try again ! \033[0m" << endl;
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
				cout << "\t\t \033[31m Your user name is short ! Please try again ! \033[0m" << endl;
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
				cout << "\t\t \033[31m Your password is short ! Please try again ! \033[0m" << endl;
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
			cout << "\t\t \033[32m User saved successfully ! \033[0m" << endl;
			cout << "\n\n";

			Sleep(2000);

			SignIn signIn;
			signIn.Include();
		}

		else 
		{
			cout << "\n\n";
			cout << "\t\t \033[31m Error saving user ! \033[0m" << endl;
			cout << "\n\n";
		}
	}
};

//-------------------------------------------------- FIRTS PART --------------------------------------------------------------------------

class Page
{
	virtual void Show() = 0;
};

class MainPage : public Page
{
public:
	string choice;

	void Show() override
	{
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

			if (choice == "1")
			{
				SignUp signUp;
				signUp.UserInfo();

				break;
			}

			else if (choice == "2")
			{
				SignIn signIn;
				signIn.Include();

				break;
			}

			else if (choice == "3")
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
				cout << "\t\t \033[31m Incorrect choice ! Please again ! \033[0m" << endl;
				Sleep(2000);
			}
		}
	}
};

// -----------------------------------------------------------------------------------------------------------------------------------------

void main()
{
	system("cls");

	MainPage page;
	page.Show();
}


