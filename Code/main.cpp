//user defined header files
#include "diceware.h"
#include "wordlist.h"

int diceroll[5];
ofstream outFile,outFile1;

//Function which generate password
void genpass( int passlength, char details[])
{
    string password = "";
    int index;
    //if user want to see details than print, else not.
    if(details[0] == 'y' || details[0] == 'Y')
    {
        cout<<"\t\t YOUR PASSWORD DETAILS IS IN\n";
        cout<<"\t\t\t <details.txt>\n";
    }
    //Run till length of password.
    for(int i = 1; i <=passlength; i++)
    {
        //Calling ROLL function with array diceroll
        ROLL(diceroll);
        //initialzing index by calling wordIndex function
        index = wordIndex(diceroll);
        //call showDeatils function with arguments
        showDetails(details,index, i);
        //concatinate password
        password = password + " " + wordlist[index];
    }
    //open file and print password in that file.
    cout<<"\n\t\t YOUR PASSWORD IS IN\n";
    cout<<"\t\t\t <password.txt>\n";
    outFile1.open ("password.txt", ofstream::out);
    outFile1 <<password<<endl;
    outFile1.close();
}
//Function which will show details of password
void showDetails(char details[], int index, int i)
{
    //if value of detail is true
    if(details[0] == 'Y' || details[0] == 'y')
    {
        outFile.open ("details.txt", ofstream::app);
        outFile << "----------------------------------------------" << endl;
        outFile <<"Dice roll : "<< i<< endl;
        outFile << diceroll[0]<<" "<<diceroll[0]<<" "<<diceroll[0]<<" "<<diceroll[0]<<" "<<diceroll[0]<<endl;
        outFile << "WordList Index Number = "<<index<< endl;
        outFile.close();
    }
}
//function which will return value of index after initializing it.
int wordIndex( int diceroll[])
{
    int index;
    int firstvalue[] = {0, 1, 2, 3, 4, 5};
    int secondvalue[] = {4 , 216, 432, 648, 864, 1080};
    int thirdvalue[] = {3, 37, 73, 109, 145, 181};
    int fourthvalue[] = {2, 7, 13, 19, 25, 31};
    int fifthvalue[] = {1 , 2593, 3889, 1297, 5185, 6481};
    //initializing index
    index = firstvalue[diceroll[0]-1];
    //adding value of index with other values
    index += secondvalue[diceroll[1]-1];
    index += thirdvalue[diceroll[2]-1];
    index += fourthvalue[diceroll[3]-1];
    index += fifthvalue[diceroll[4]-1];
    //return index
    return index;

}
//function which roll the dice
void ROLL (int diceroll[])
{
    //calling random number generator and initializing it to the array
    diceroll[0] = randomNo();
    diceroll[1] = randomNo();
    diceroll[2] = randomNo();
    diceroll[3] = randomNo();
    diceroll[4] = randomNo();
}
//generate randon number
int randomNo()
{
   int minimum = 1, maximum = 6;
   int rand = 0;
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> dis(minimum, maximum);
   rand = dis(gen);
   //return random number betwwen 1 and 6
   return rand;
}
//Driver Code
int main()
{
    int n;
    char details[1];
    cout<<"How many words in your password you want?"<<endl;
    cin>>n;
    cout <<"Do you want to see details? Y/N"<<endl;
    cin>>details[0];
    //Calling Function
    genpass(n,details);
}
