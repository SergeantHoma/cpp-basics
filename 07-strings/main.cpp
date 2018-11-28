#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string file_name;
	cout << "Write file name -> ";
	cin >> file_name;
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "can't open file: " << file_name << endl;
		return 1;
	}

	int count = 0;
	string word;
	while (fin >> word)
	{
		size_t word_len = word.length();

		// Checks if the last character in the word is a punctuation character.
		if (ispunct(word[word_len - 1]))
		{
			word = word.substr(0, word_len - 1);
			word_len--;
		}

		// Checks if every character in the word is an alphabetic letter.
		bool is_word = true;
		for (unsigned int i = 0; i < word_len; i++)
			if (!isalpha(word[i]))
				is_word = false;

		if (is_word)
			if (word_len <= 4)
				count++;
	}
	cout << "The number of words consisting of no more than four characters: ";
	cout << count;

	fin.close();
	return 0;
}