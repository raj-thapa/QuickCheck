// program that checks multiple choice answers of the student and returns the result

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// function that takes two parameters keysarr array and count1 variable which are passed with reference.
//This function gets name of filename from the user and opens the input file. It also reads the characters
//present in the key file and assigns it to the array and returns true if every thing
// worked properly returns false.

bool keysAssign(char keysArr[], int &count1)
{
    string keyFileName;
    
    cout << "Enter the name of the file containing the key." << endl;
    cin >> keyFileName;
    
    ifstream inputFile1(keyFileName);
    
    if (inputFile1.fail())
    {
        cout << "\"" << keyFileName << "\" could not be opened." << endl;
        return false;
    }
    else 
    {
        int count = 0;
        while (count < 50 && inputFile1 >> keysArr[count])
        {
            count++;
        }
        
        if (count == 0)
        {
            cout << "The file containing the key was empty." << endl;
            inputFile1.close();
            return false;
        }
        
        count1 = count;
        inputFile1.close();
        return true;
    }
}

// ansAssign function that takes two parameters anssarr array and count2 variable which are passed with reference.
//This function gets name of filename from the user and opens the input file. It also reads the characters
//present in the answer file and assigns it to the array and returns true if every thing
// worked properly returns false.

bool ansAssign(char ansArr[], int &count2)
{
    string ansFileName;
    
    cout << "Enter the name of the file containing the student's responses." << endl;
    cin >> ansFileName;
    
    ifstream inputFile(ansFileName);
    
    if (inputFile.fail())
    {
        cout << "\"" << ansFileName << "\" could not be opened." << endl;
        return false;
    }
    else 
    {
        int count = 0;
        
        while (count < 50 && inputFile >> ansArr[count])
        {
            count++;
        }
        
        count2 = count;
        inputFile.close();
        return true;
    }
}

// displayResults function that takes three parameters, two of which are const char arrays and one is
// integer variable count. This function calculates and checks if two arrays contains valid information
// and display results in the screen.

void displayResults(const char keysArr[], const char ansArr[], int count)
{
    double mistakeCount = 0;
    
    for (int i = 0; i < count; i++) // loops until i is smaller than count
    {
        if (keysArr[i] != ansArr[i]) //checks if elements of arrays are not equal
        {
            cout << "Question " << i + 1 << " has incorrect answer \'" << ansArr[i] << "\', the correct answer is \'" << keysArr[i] << "\'." << endl;
            mistakeCount += 1;
        }
    }
    
    double percentage = ((count - mistakeCount) * 100) / count;
    
    cout << mistakeCount << " questions were missed out of " << count << "." << endl;
    cout << fixed << showpoint;
    cout << "The student grade is " << setprecision(2) << percentage << "%" << endl;
    
    if (percentage >= 72.5)
    {
        cout << "The student has passed the quiz." << endl;
    }
    else 
    {
        cout << "The student has failed the quiz." << endl;
    }
}

// starting of the main function

int main()
{
    
    // two parallel arrays
    char keysArr[50] = {};
    char ansArr[50] = {};
    
    int count1, count2;

    
    if (keysAssign(keysArr, count1) == true) // calls keysAssign function and checks the result 
    {
        if (ansAssign(ansArr, count2) == true) // calls ansAssign function and checks the result
        {
            if (count2 < count1)
            {
                cout << "File error! There is a mismatch between the number of questions and answers." << endl;
            }
            else
            {
                displayResults(keysArr, ansArr, count1); // calls displayResults function
            }
        }
    }
    
    return 0;
}