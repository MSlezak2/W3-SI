#include <string>
#include <iostream>
#include <cmath>

using std::string; using std::cout; using std::endl; using std::min;

string encrypt(string plain_text, string keyword);
char encrypt_letter(char letter, char key);
string decrypt(string encrypted_text, string keyword);
char decrypt_letter(char letter, char key);
string adjust_keyword(string plain_text, string keyword);
int which_place_in_the_alphabet(char letter);

int main() {

	string plain_text = "GEEKSFORGEEKS";
	string keyword = "AYUSH";
	string encrypted_text;
	string decrypted_text;

	encrypted_text = encrypt(plain_text, keyword);

	decrypted_text = decrypt(encrypted_text, keyword);

	cout << "plaint text: " << plain_text << endl;
	cout << "keyword: " << keyword << endl;
	cout << "encrypted text:" << encrypted_text << endl;
	cout << "decrypted text:" << decrypted_text << endl;

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
	
	encrypted_letter = 'A' + ((which_place_in_the_alphabet(letter) + which_place_in_the_alphabet(key)) % 26); // modulo is because we don't want to go beyond Z-letter ;)
	
	return encrypted_letter;

}

string decrypt(string encrypted_text, string keyword) {

	string decrypted_text;
	string adjusted_keyword;

	// prepare keyword (extend / shrink it to be as long as the plain text)
	adjusted_keyword = adjust_keyword(encrypted_text, keyword);

	char temp;
	for (int i = 0; i < encrypted_text.length(); i++)
	{
		temp = decrypt_letter(encrypted_text.at(i), adjusted_keyword.at(i));
		decrypted_text.append(1, temp);
	}

	return decrypted_text;

}

char decrypt_letter(char letter, char key) {

	char decrypted_letter;

	if (which_place_in_the_alphabet(key) <= which_place_in_the_alphabet(letter)) {

		decrypted_letter = 'A' + (abs(which_place_in_the_alphabet(letter) - which_place_in_the_alphabet(key)) % 26); // modulo is because we don't want to go beyond Z-letter ;)

	}
	else {

		decrypted_letter = 'A' + (26 - which_place_in_the_alphabet(key) + which_place_in_the_alphabet(letter));

	}

	return decrypted_letter;

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