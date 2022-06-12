#include <string>
#include <iostream>

using std::string; using std::cout;

string encrypt(string plain_text, string keyword);
char encrypt_letter(char letter, char key);
string adjust_keyword(string plain_text, string keyword);
int which_place_in_the_alphabet(char letter);

int main() {

	string plain_text = "GEEKSFORGEEKS";
	string keyword = "AYUSH";
	string encrypted_text;
	string decrypted_text;

	encrypted_text = encrypt(plain_text, keyword);

	cout << encrypted_text;
	//decrypted_text = decrypt(encrypted_text, keyword);

}

string encrypt(string plain_text, string keyword) {

	string encrypted_text;
	string adjusted_keyword;

	// prepare keyword (extend / shrink it to be as long as the plain text)
	adjusted_keyword = adjust_keyword(plain_text, keyword);
	
	char temp;
	for (int i = 0; i < plain_text.length(); i++)
	{
		temp = encrypt_letter(plain_text.at(i), adjusted_keyword.at(i));
		encrypted_text.append(1, temp);
	}

	return encrypted_text;

}

char encrypt_letter(char letter, char key) {

	char encrypted_letter;
	
	encrypted_letter = 'A' + ((which_place_in_the_alphabet(letter) + which_place_in_the_alphabet(key)) % 26);
	
	return encrypted_letter;

}

string adjust_keyword(string plain_text, string keyword) {

	string adjusted_keyword;
	char temp;

	for (int i = 0; i < plain_text.length(); i++)
	{
		temp = keyword.at(i % keyword.length());
		adjusted_keyword.append(1, temp);
	}

	return adjusted_keyword;

}

int which_place_in_the_alphabet(char letter) {
	// function takes a letter and returns it's place in the alphabet (fo instance A - 0, C - 2)

	return letter - 'A';

}