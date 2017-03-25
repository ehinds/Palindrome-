/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  2/6/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 3: program3_string

Description: Has three functions: palindrome, replace_all, and choice. Palindrome checks if a string is a palindrome or not
//replace all replaces a substring with a different substring, and choice allows the user to select several choices for 
//running through the functions.
*************************************************************************************************************************/

#include <iostream> 
#include <string> 
using namespace std; 

bool palindrome(const string &s);
string replace_all(const string & original_string, const string & old_substring, const string & new_substring);
void choice(string &original_string, string &old_substring, string &new_substring, string &copyString);

//*************************************************************************************
//Name: palindrome
//Precondition: String has not been checked if it is a palindrome
//Postcondition: String has been checked to see if it is a palindrome
//Description: Returns true if the string is a palindrome and false if it is not.
//*************************************************************************************
bool palindrome(const string &s)
{
	if (s.empty())
	{
		return false;
	}

	unsigned int begin = 0, end = (s.length() - 1);

	while (begin < end)
	{
		if (!isalnum(s[begin])) //check beginning of array to see if it is not an alpha or numeric. If it isn't, skip.
		{
			begin++;
		}
		else if (!isalnum(s[end])) //check end of array to see if it is not an alpha or numeric. If it isn't, skip
		{
			end--;
		}
		else if (tolower(s[begin]) == tolower(s[end])) //remove capitalization and compare values. If equal, check next.
		{
			begin++;
			end--;
		}
		else //not a palindrome, return false
		{
			return false;
		}
	}

	return true;
}

//*************************************************************************************
//Name: replace_all
//Precondition: The original string has not been copied nor has a substring been replaced
//Postcondition: The original string is copied and the copy has a specified substring replaced
//Description: makes a copy of original_string. Searches the string for all instances of old_substring
//and, if found, will replace all instances with new_substring. Otherwise returns that it could not find the substring.
//*************************************************************************************
string replace_all(const string &original_string, const string &old_substring, const string &new_substring)
{
	string s = original_string;
	size_t	position_location = 0;

	if (old_substring.empty())
	{
		cout << "Error: The substring you wish to replace is empty.\n";
		return s;
	}

	else 
	{
		while ((position_location = s.find(old_substring, position_location)) != string::npos) //find the location of old_substring inside of original_string
																											// and assign this value to position_location.
		{
			s.replace(position_location, old_substring.length(), new_substring); //replace the substring in string s at position location
																				//with the length of old_substring, the new substring.
			position_location += new_substring.length();
		}
	}

	return s;
}


//*************************************************************************************
//Name: choice
//Precondition: A choice has not been made
//Postcondition: A choice has been made
//Description: Gives a list of several different choices and will loop infinitely until the user closes.
//choices include entering a new string, checking if it is a palindrome, entering a new substring for replacement,
//entering the substring to replace the old, and replacing the substring. Also displays the current string.
//*************************************************************************************
void choice(string &original_string, string &old_substring, string &new_substring, string &copyString)
{

	cout << "Your current string is '" << original_string << "'.\n";
	cout << "Your replaced string is '" << copyString << "'.\n";
	cout << "Substring to be replaced is currently '" << old_substring << "'.\n";
	cout << "Substring that will replace the old substring is currently '" << new_substring << "'.\n\n";

	cout << "What would you like to do?\n\n";
	cout << "1) Enter a new string.\n";
	cout << "2) Check if string is a palindrome.\n";
	cout << "3) Enter a new substring to remove from the string.\n";
	cout << "4) Enter a new substring that will replace the substring in case 3.\n";
	cout << "5) Replace substring.\n";
	cout << "6) I just want to talk to someone.\n";
	cout << "7) Exit.\n";

	int selection = 0;
	cin >> selection;


	char affirmation1 = 'l', affirmation2 = 'l', affirmation3 = 'l';

	switch (selection)
	{
	case 1:		cout << "Please enter a new string: \n";
				cin.ignore();
				getline(cin, original_string);
				cout << "Thank you. Your string '" << original_string << "' has been saved.\n\n";
				choice(original_string, old_substring, new_substring, copyString);
				break;

	case 2:		if (palindrome(original_string) == 1)
				{
					cout << "Yes, '" << original_string << "' is a palindrome.\n\n";
				}
				else if (palindrome(original_string) == 0)
				{
					cout << "No, '" << original_string << "' is not a palindrome.\n\n";
				}
				choice(original_string, old_substring, new_substring, copyString);
				break;

	case 3:		cout << "Please enter a substring to remove from the primary string: \n";
				cin >> old_substring;
				cout << "Your substring '" << old_substring << "' has been registered.\n\n";
				choice(original_string, old_substring, new_substring, copyString);
				break;
	
	case 4:		cout << "Please enter a substring you would like to replace the old substring: \n";
				cin >> new_substring;
				cout << "Your substring '" << new_substring << "' has been registered.\n\n";
				choice(original_string, old_substring, new_substring, copyString);
				break;

	case 5:		if (old_substring == "")
				{
					cout << "The substring to be replaced has not been set and\nis currently at the default. Do you wish to continue? (y/n)\n";
					cin >> affirmation1;

					while (affirmation1 != 'y' && affirmation1 != 'Y' && affirmation1 != 'n' && affirmation1 != 'N')
					{
						cout << "Please enter 'y' or 'n': \n";
						cin.clear();
						cin >> affirmation1;
					}

					if (affirmation1 == 'y' || affirmation1 == 'Y')
					{
						if (new_substring == "")
						{
							cout << "The substring that is supposed to replace the old substring has not been set\nand is currently at the default. Do you wish to continue (y/n)\n";
							cin >> affirmation2;

								while (affirmation2 != 'n' && affirmation2 != 'N' && affirmation2 != 'Y' && affirmation2 != 'y')
								{
									cout << "Please enter 'y' or 'n': \n";
									cin.clear();
									cin >> affirmation2;
								}
								if (affirmation2 == 'y' || affirmation2 == 'Y')
								{
									copyString = replace_all(original_string, old_substring, new_substring);
									if (copyString == original_string)
									{
										cout << "The string '" << old_substring << "' was not found within the string '" << copyString << "'" << endl << endl;
									}
									else
									{
										cout << "Replacement successful. The new string is '" << copyString << "' and the original string was '" << original_string << "'\n\n";
									}
									choice(original_string, old_substring, new_substring, copyString);
									cin.clear();
									break;
								}
								else if (affirmation2 == 'n' || affirmation2 == 'N')
								{
									choice(original_string, old_substring, new_substring, copyString);
									cin.clear();
									break;
								}
							}
						}
					else if (affirmation1 == 'n' || affirmation1 == 'N')
					{
						choice(original_string, old_substring, new_substring, copyString);
						cin.clear();
						break;
					}
				}
				else if (new_substring == "" && old_substring != "")
				{
						cout << "The substring that is supposed to replace the old substring has not been set\nand is currently at the default. Do you wish to continue (y/n)\n";
						cin >> affirmation3;

						while (affirmation3 != 'n' && affirmation3 != 'N' && affirmation3 != 'y' && affirmation3 != 'Y')
						{
							cout << "Please enter 'y' or 'n': \n";
							cin.clear();
							cin >> affirmation3;
						}

						if (affirmation3 == 'y' || affirmation3 == 'Y')
						{
							copyString = replace_all(original_string, old_substring, new_substring);
							if (copyString == original_string)
							{
								cout << "The string '" << old_substring << "' was not found within the string '" << copyString << "'" << endl << endl;
							}
							else
							{
								cout << "Replacement successful. The new string is '" << copyString << "' and the original string was '" << original_string << "'\n\n";
							}
							choice(original_string, old_substring, new_substring, copyString);
							cin.clear();
							break;
						}
						else if (affirmation3 == 'n' || affirmation3 == 'N')
						{
							choice(original_string, old_substring, new_substring, copyString);
							cin.clear();
							break;
						}
					}
				else
				{
					copyString = replace_all(original_string, old_substring, new_substring);
					if (copyString == original_string)
					{
						cout << "The string '" << old_substring << "' was not found within the string '" << copyString << "'" << endl << endl;
					}
					else
					{
						cout << "The new string is '" << copyString << "' and the original string was '" << original_string << "'\n\n";
					}
					choice(original_string, old_substring, new_substring, copyString);
					cin.clear();
					break;
				}

	case 6:		cout << "I am sorry but unfortunately I cannot chat. Good luck with that though.\n\n";
				choice(original_string, old_substring, new_substring, copyString);
				cin.clear();
				break;

	default:	cout << "Goodbye!\n\n";
			
	}
}
int main()
{
	string original_string, old_substring, new_substring, copyString;

	cout << "Hello. Before we begin, please enter a default string: \n";
	getline(cin, original_string);
	cout << "Thank you. Your string '" << original_string << "' has been saved.\n\n";
	choice(original_string, old_substring, new_substring, copyString);

	return 0;
}