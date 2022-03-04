#include <iostream>
#include <string>
#include<conio.h>
using namespace std;
bool hasMultipleExclamations(string subj);
string getFirstWord(string text);
string getLastWord(string text);
string extractWord(string& text);
bool isUppercase(string text);
string makeUppercase(string text);
bool isGibberishWord(string text);
bool isConsonant (char thisChar);
int triggerWordChecker(string text);
int getNumWords (string text);
int getNumUpper (string subj);
bool percUpper (string text, int perc);

int main() {


    string bod;
    int spamScore = 0;
    string subj;
    int numSpam = 0;
    int numLeg = 0;
    bool cont = true;
    bool miniWhile = true;
    char yesOrNo;
    int THRESH = 100;
    int a[10],i,b;


    // while loop prompts and takes input from user
    while (cont) {

        spamScore = 0;for(i=0;i<10;i++){a[i]=1;}
        cout << "Enter the subject line of the email: ";
        getline(cin, subj); // getline to give access to paramaters

        //check condition #1
        // if subject has < 1 word, and > 90% have only uppercase letters, add 30 pts to spamScore
        if (percUpper(subj, 90)){spamScore += 30; a[0]=0;} else{a[0]=1;}

        // check condition #2
        // if last word of subject has > 3 consecutive consonants, add 40 pts to spamScore
        string theLast = getLastWord(subj);
        if (isGibberishWord(theLast)){spamScore += 40;a[1]=0;} else{a[1]=1;}

        // check condition #3
        // if subject line >= 3 contiguous exclamation points, add 20 pts to spamScore
        if (hasMultipleExclamations(subj)){spamScore += 20;a[2]=0;} else{a[2]=1;}

        cout << "Enter the body of the email. " << endl;

        getline(cin, bod);

        //check condition #4 problem
        // if the body has > 1 word, and > 50% of them are all uppercase, add 40 pts to spamScore
        if (percUpper(bod, 50)){spamScore +=40;a[3]=0;} else{a[3]=1;}

        //check condition #5
        // each time a trigger word appears in the body, add 10 points to spamScore
        int numTriggers = triggerWordChecker(bod);
        if(numTriggers>0){a[4]=0;} else{a[4]=1;}
        int numToAdd = numTriggers * 10;
        spamScore += numToAdd;


        // output whether spamScore > 100 (it is spam) or < 100 (it is legitimate)
        if(spamScore > THRESH){cout << "This email is classified as spam, because its sp am score is " << spamScore << ".\n\n" << endl; a[5]=0;}
        else{cout << "This email is classified as legitimate, because its spam score is " <<spamScore << ".\n\n" << endl; a[5]=1;}
        //output automata for the input
        cout<<"as \n Q0 --";
        if(a[0]==0){cout<<"(sub_word<1||sub_uppercase>90%)--> Q1 --";} else{cout<<"E--> Q`1 --";}
        if(a[1]==0){cout<<"(sub_consecutive_consonants>3)--> Q2 --";} else{cout<<"E--> Q`2 --";}
        if(a[2]==0){cout<<"(sub_exclamation>3)--> Q3 --";} else{cout<<"E--> Q`3 --";}
        if(a[3]==0){cout<<"(body_uppercase>50%&&words>1)--> Q4 --";} else{cout<<"E--> Q`4 --";}
        if(a[4]==0){cout<<"(body_trigger_words)--> Q5 --";} else{cout<<"E--> Q`5 --";}
        if(a[5]==0){cout<<"E--> Q_spam";} else{cout<<"E--> Q_legitimate";}


        // nested while loop continues prompting user to continue until
        // inputed a 'y' (go back up to while loop) or a 'n' (end while loop)


    cont= false;

    }


}
/*
 returns true if percentage of words in text are uppercase is more than threshold
 */
bool percUpper (string text, int perc) {
    double wordCount = getNumWords(text);
    double upperCount = getNumUpper(text);
    double percUpper = ( upperCount / wordCount ) * 100;
    if (percUpper > perc)
        return true;
    else
        return false;
}

/*
 returns the number of uppercase words
 */
int getNumUpper (string subj) {
    int numWords = getNumWords(subj);
    string thisWord = extractWord(subj);

    int numUp = 0;
    for (int i = 0;i < numWords; i++) {
        if (isUppercase(thisWord))
            numUp++;
        thisWord = extractWord(subj);
    }
    return numUp;
}

/*
 returns the number of words in the text
 */
int getNumWords (string text) {

    int numWords = 0;
    while (extractWord(text) != "")

        numWords++;
    return numWords;

}


/*
 returns first word and modifies text to be all except first word
 */
string extractWord(string& text)
{

    string first = getFirstWord(text);

    if (first == "")
        text = "";

    else {
        int indexFirstWord;
        indexFirstWord = (int) text.find(first);

        int lengthFirstWord = (int) first.size();
        int textLength = (int) text.size();

        int start = indexFirstWord + lengthFirstWord;
        text = text.substr(start, textLength - start);
    }
    return first;
}

/*
 returns true if the text contains more than three consecutive consonants
 */
bool isGibberishWord (string text) {

    int numCons = 0;
    for (int i = 0; i < (int) text.size() - 2; i++) {
        for (int j = i; j <= i + 3; j++) {
            if (isConsonant(text[j]))
                numCons++;
        }
        if (numCons > 3)
            return true;
        numCons = 0;
    }
    return false;
}


/*
 returns true if subject has three or more contiguous exclamation marks
*/
bool hasMultipleExclamations(string subj) {
    if (subj == "")
        return false;
    for (int i = 0; i < (int) subj.size() - 2; i++) {
        if (subj.substr(i, 3) == "!!!")
            return true;
    }
    return false;
}


/*
 returns the first word in the string
*/
string getFirstWord(string text) {
    if (text == "")
        return "";


    int i = 0;
    bool noMoreLetters = true;
    while (text[i] != '\0') {
        if (isalpha(text[i]))
            noMoreLetters = false;
        i++;
    }
    if (noMoreLetters)
        return "";


    i = 0;
    int dontInc = 0;
    while (!isalpha(text[i])) {
        i++;
        dontInc++;
    }
    while (isalpha(text[i]))
        i++;
    return text.substr(0 + dontInc, i - dontInc);
}



/*
 returns the last word in the string
 */
string getLastWord(string text) {
    if (text == "")
        return "";
    int i = 0;
    int dontInc = 0;
    while (text[i]!= '\0')

        i++;
    while (!isalpha(text[i-1])) {
        i--;
        dontInc++;
    }
    while (isalpha(text[i -1]))
        i--;
    int length = (int) text.size() - i;
    return text.substr(i, length - dontInc);
}

/*
 returns true if text is upper case
 */
bool isUppercase(string text)
{
    bool allUp = true;
    for (int i = 0; i < (int) text.size(); i++) {
        if (isalpha(text[i]) && !isupper(text[i])) {
            allUp = false;
            return allUp;
        }
    }
    return allUp;
}

/*
 makes the text upper case
 */
string makeUppercase(string text)
{
    string upString;
    for (int i = 0; i < (int) text.size(); i++)
        upString += toupper(text[i]);

    return upString;
}

/*
 returns number of instances of trigger words
 */
int triggerWordChecker(string text)
{
    if (text == "")
        return 0;

    int numTrigs = 0;
    string newString = makeUppercase(text);
    string thisWord;

    do {
        thisWord = extractWord(newString);
        if (thisWord == "BUY" ||
            thisWord == "CHEAP" ||
            thisWord == "CLICK" ||
            thisWord == "ENLARGE" ||
            thisWord == "FREE" ||
            thisWord == "LONELY" ||
            thisWord == "MONEY" ||
            thisWord == "NOW" ||
            thisWord == "OFFER" ||
            thisWord == "ONLY" ||
            thisWord == "PILLS" ||
            thisWord == "MEDICINE" ||
            thisWord == "SEX")
            numTrigs++;
    } while (thisWord != "");

    return numTrigs;
}

/*
 checks if the character is a consonant
 */
bool isConsonant (char thisChar) {
    if (thisChar =='B' || thisChar =='b' ||
        thisChar =='C' || thisChar =='c' ||
        thisChar =='D' || thisChar =='d' ||
        thisChar =='F' || thisChar =='f' ||
        thisChar =='G' || thisChar =='g' ||
        thisChar =='H' || thisChar =='h' ||
        thisChar =='J' || thisChar =='j' ||
        thisChar =='K' || thisChar =='k' ||
        thisChar =='L' || thisChar =='l' ||
        thisChar =='M' || thisChar =='m' ||
        thisChar =='N' || thisChar =='n' ||
        thisChar =='P' || thisChar =='p' ||
        thisChar =='Q' || thisChar =='q' ||
        thisChar =='R' || thisChar =='r' ||
        thisChar =='S' || thisChar =='s' ||
        thisChar =='T' || thisChar =='t' ||
        thisChar =='V' || thisChar =='v' ||
        thisChar =='W' || thisChar =='w' ||
        thisChar =='X' || thisChar =='x' ||
        thisChar =='Y' || thisChar =='y' ||
        thisChar =='Z' || thisChar =='z')
        return true;
    else
        return false;
}

