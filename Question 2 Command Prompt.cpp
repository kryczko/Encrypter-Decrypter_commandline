#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

char ceaserCipher(char c,int key);
char ceaserDecipher(char c, int key);

void encrypt(string infile, string outfile)
{
  ifstream inputfile;
  ofstream outputfile;
  
  inputfile.open(infile.c_str());
  outputfile.open(outfile.c_str());

  while(!inputfile.eof())
  {
    char letters = inputfile.get();
    outputfile << ceaserCipher(letters, 5);
  }
}
void decrypt(string infile, string outfile)
{
  ifstream inputfile;
  ofstream outputfile;

  inputfile.open(infile.c_str());
  outputfile.open(outfile.c_str());

  while(!inputfile.eof())
  {
    char letters = inputfile.get();
    outputfile << ceaserDecipher(letters, 5);
  }
}

char ceaserCipher(char c,int key)
{
  if (isalpha(c))
  {
   c = (c - 'A' + key) % 26 + 'A';
  } 
  else if (ispunct(c))
  {
	c = c;
  }
  else if(c == 10)
  {
	 c = c;
  }
  else if(c = 32)
  {
	  c = c;
  }
  return c;
}
char ceaserDecipher(char c,int key)
{
  if (c >= 69 && c <= 90)
	{
	c = (c - 'A') % 26 + 'A' - key;
	} 
	else if(c == 'B')
	{
		c = 'W';
	}
	else if(c == 'D')
	{
		c = 'Y';
	}
	else if (ispunct(c))
	{
		c = c;
	}
	else if (c == 32)
	{
		c = c;
	}
	else if (c == 10)
	{
		c = c;
	}
	else if (!(isalnum(c) || ispunct(c)))
	{
		c = ' ';
	}   
  return c;
}


int main(int argc, char* argv[])
{
  if (strcmp(argv[1],"-encrypt") == 0)
  {
	  cout << "\nEncryption Selected.\n\n";
	  encrypt(argv[2], argv[3]);
	  cout << "The encrypted text of " << argv[2] << " is now located in the file " << argv[3] << ".\n";  
  }
  if (strcmp(argv[1],"-decrypt") == 0)
  {
	  cout << "\nDecryption Selected.\n\n";
	  decrypt(argv[2], argv[3]);
	  cout << "The decrypted text of " << argv[2] << " is now located in the file " << argv[3] << ".\n";  
  }
  return 0;
}












