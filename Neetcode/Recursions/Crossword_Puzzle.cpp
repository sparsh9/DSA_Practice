#include<iostream>
#include<string>
#include<vector>
#include<cstring>  
using namespace std;

// void crosswordPuzzle(char grid[10][10])

int main()
{
    char crossword [10][10];
    string words;
    char *word;
    // take the crossword grid input.
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>crossword[i][j];
        }
    }
    cin>>words;
    cout<<endl<<words;
    word = strtok(words,";");
    cout<<endl<<word;


    // crosswordPuzzle(crossword,word);
    
    return 0;
}