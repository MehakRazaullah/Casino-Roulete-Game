#include <iostream>
#include<windows.h>// used to stores the graphics and music
#include<mmsystem.h>
#include<cstdlib> // needed to use random numbers.
#include<ctime> // needed to use time.
using namespace std;
void rules() // function decelaration
{
	 
		cout << "\n\n\n\n\n";
		cout << "\t\t\t\t\t======GAME RULES!=======\n"<<endl;
		cout << "\t\t\t\t 1.PICK ANY NUMBER BETWEEN 1 to 10\n";
		cout << "\t\t\t\t 2.WINNER WILL GET THE 10 TIMES OF BET MONEY\n";
		cout << "\t\t\t\t 3.IF BET WENT WRONG THEN YOU`LL LOSE THE AMOUNT YOU BET :D\n\n ";
	} 


int main(int argc, char** argv) {
	
	

	system("cls");// clears the screen
	string color;
		string playername; // stores the player`s name
		int totalamount; //stores the total amount of player
		int bettingamount; // stores betting amount of player
		int guess; // stores the guess number 
		int dice; // stores the random number (computer generated number)
		char choice; // stores the choice yes or not 
		srand(time(0)); //"seed" the random number generator (takes the time of computer within nanoseconds and prints against the numbers)
	cout<<"\n===============================================================================================";
 cout<<"\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
 cout<<"\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
 cout<<"\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
 cout<<"\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n===============================================================================================\n";
		
		cout<<"\n\n ENTER YOUR NAME: "; 
		getline(cin,playername); // input the player`s full name
		
		cout<<"ENTER YOUR TOTAL AMOUNT: RS.";
		cin>>totalamount;
		
	do  // do-while loop starts
    {
        system("cls");   // to clear screen
        rules();         // calling/invoking a function
        cout << "\n\nYOUR CURRENT TOTAL AMOUNT IS Rs. " << totalamount<< ".\n";
        
    // Get Player's betting amount
    
     do  // nested do-while loop
        {
            cout << "Hello \t" << playername<<", ENTER YOUR BET : Rs. ";
            cin >>bettingamount;
            
            
            
            if (bettingamount >totalamount)
                cout << "BETTING AMOUNT CAN'T BE MORE THAN THE CURRENT TOTAL AMOUNT!\n"
                       <<"\nRe-ENTER YOUR BET\n ";
	    }
		while (bettingamount > totalamount);  // nested do-while loop ends
		
		// Get player's numbers
		
		do   // 2nd nested do-while loop   
		{
			cout << "GUESS ANY BETTING NUMBER BETWEEN 1 to 10 :";
			cin >> guess;
			if (guess <0 || guess > 10)
			cout << "\nNumber should be between 1 and 10\n"
			<<"Re-enter number:\n ";
		}
			
		
        while (guess <0 || guess > 10); // 2nd nested do-while loop endsPlaySound(TEXT("reward.wav"),NULL,SND_SYNC);
    
        
        
        
        PlaySound(TEXT("game.wav"),NULL,SND_SYNC); //snd_sync if we use mp4 the it will make sound by default
        dice = rand()%10+1;
        
        if (dice == guess)  // if-else condition starts
        {
        	cout << "\n\n HURRAY! YOU HAVE WON Rs. " << bettingamount * 10;
        	
        	
        	
        	totalamount = totalamount+bettingamount * 10;
        	
        	
        	 
   	PlaySound(TEXT("reward.wav"),NULL,SND_SYNC);
    PlaySound(TEXT("cheers.wav"),NULL,SND_SYNC);
    
		}
		
		else
		{
			cout << "OOPS BETTER LUCK NEXT TIME! YOU LOST Rs. "<< bettingamount <<endl;
			
			
			
			totalamount = totalamount - bettingamount;
			
			
			
			PlaySound(TEXT("lose.wav"),NULL,SND_SYNC);
			 
		} // if-else condition ends
		
        cout << "\nTHE WINNING NUMBER WAS : "<< dice << endl;  // shows winning number
        
        
        
        
        cout << playername << ", YOU HAVE CURRENT AMOUNT OF Rs. " << totalamount<<endl; // shows current amount
        
        
        
        if (totalamount == 0)   
        {
        	cout << "YOU HAVE NO MONEY TO PLAY ";
        	
        	
        	
        	break;
		}
        cout << "\n\nDO YOU WANT TO PLAY AGAIN (y/n)? ";
        
        
        
        
        cin >> choice;                     // asks your choice whether you wanna play again or want to exit
    }
    while (choice == 'Y' || choice == 'y');  

    cout << "\n\n\n";
    
    cout<<"\n\nTHANKS FOR PLAYING THE GAME. YOUR CURRENT AMOUNT IS Rs."<<totalamount<<"\n\n";
     
    //0E 0 is for black background and E is for yellow.

system ("color 0E");
	return 0;
} 


/* ONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = 24;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

std::cout << "Font: Consolas, Size: 24\n";*/
