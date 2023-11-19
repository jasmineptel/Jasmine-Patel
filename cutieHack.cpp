#include <fstream> 
#include <iostream>

using namespace std;

string GetHint ( string word )
{
    if ( word == "yellow"){
        return "This is one of the two colors of a bee";
    }
    
    else if ( word == "halloween" ){
        return "A holiday with candy and costumes";
    }
    
    else if ( word == "lavender" ){
        return "This is a shade of purple, and also a flower";
    }
    
    else if ( word == "pumpkin" ){
        return "This is an object that is carved in October";
    }
    
    else if ( word == "orange"){
        return "This word is a fruit and color";
    }
    
    else if ( word == "flowers"){
        return "Something you can buy on Valentines day";
    }
    
    else if ( word == "monkey" ){
        return "Animal that likes bananas";
    }
    
    else if ( word == "sunset"){
        return "Opposite of sunrise";
    }
    
    else if ( word == "gorilla"){
        return "In the Ape family, and very strong";
    }
    
    else if ( word == "tortilla" ){
        return "A food item that can be made with corn or flour";
    }
    else {
        return "";
    }
}


int main()
{
    // STEP 1 -- directions and start
    cout << "Hi!! Today We are playing Hangman. The purpose of the game is to guess the word we have chosen for you" << endl;
    cout << "The rules are simple, you have unlimited chances to guess the letters of the word. We will give you a hint once you have correctly guessed 4 letters" << endl;
    cout << "Please enter the number 1 to play!" << endl;
    
    int varPlay;
    cin >> varPlay;
    
    if ( varPlay !=1 )
    {
        cout << "Bye!! Have a nice day :)" << endl;
    }
    
    //GAME STARTS
    else if ( varPlay == 1)
    {
        
    ifstream namesHangman;
    namesHangman.open( "namesHangman.txt");
    
    int lineCount = 0;
    string line;
    int randomLine;
    string showGuesses = "";
    
    // chooses 1 out of the 10 lines in the file
    srand ( time(0));
    randomLine = (rand() % 10) +1;
    
    for (int i = 1; i < randomLine; ++i) {
        getline (namesHangman, line);
        }
        
    // tell the user how long the word is 
    int wordSize;
    wordSize = line.size();
    cout << "Your word has " << wordSize << " letters." << endl;
    
    // ask user to guess letter until 4 are guessed right 
    int guessCount = 0;
    char letter;
    
  
    
    while (guessCount <= 4)
    {
        
        cout << "Please guess a letter: a-z (lowecase only)" << endl;
        cin >> letter;
        
        
        for ( int i = 0; i < wordSize; ++i)
        {
    
            if (letter == line.at(i))
            {
             ++guessCount;
             cout << "good job! you guessed a letter correctly!!" << endl;
            }
            
        }
        
    }
     
     string guessWord;
     
     // call the function for hints    
     cout << "Here's a hint that may help you guess your word!:" << endl;
     cout << GetHint(line) << endl;
     cout << endl;
     
     // Last part... guess word
     cout << "Try to Guess the whole word now! :" << endl;
     cin >> guessWord;
     
     if ( guessWord == line )
     {
         cout << "CONGRADULATIONS!! YOU GUESSED THE RIGHT WORD!:)" << endl; 
     }
     while ( guessWord != line)
     {
         cout << "That is the Wrong Word. Try again!" << endl;
         cin >> guessWord;
     }
     
     
        
    namesHangman.close();
    }
    
    return 0;
}