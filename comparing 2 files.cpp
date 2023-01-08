/*Amina habib
 programming fundamentals
 submitted to Maam ayesha hakim
 */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  // Prompt the user to enter the names of the two files

  cout<< "Please Keep both files in the same folder of program"<<endl;
  cout << "Enter the name of the first file: ";
  string file1;
  getline(cin,file1);

  cout << "Enter the name of the second file: ";
  string file2;
  getline(cin,file2);

  // Open the two files
  ifstream comp1("file1.txt");
  ifstream comp2("file2.txt");


  // This will Count  number of words 
  string word1, word2;
  int wordCount1 = 0, wordCount2 = 0;
  while (comp1 >> word1) {
    ++wordCount1;
  }
  while (comp2 >> word2) {
    ++wordCount2;
  }

  // Close the files
  comp1.close();
  comp2.close();

  // Reopen the files
  comp1.open("file1.txt");
  comp2.open("file2.txt");

  // Compare the words in the two files, ignoring case
  int commonWordCount = 0;
  while (comp1 >> word1 && comp2 >> word2) {
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    if (word1 == word2) {
      ++commonWordCount;
    }
  }

  // Close the files
  comp1.close();
  comp2.close();

  // Calculate the percentage similarity
  double similarity = static_cast<double>(commonWordCount) / wordCount1 * 100;

  // Results
  cout << "Number of words in first file: " << wordCount1 << endl;
  cout << "Number of words in second file: " << wordCount2 << endl;
  cout << "Percentage similarity: " << similarity << "%" << endl;

  return 0;
}
