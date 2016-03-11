// Midtern - Battleship.cpp : Defines the entry point for the console application.
//
//NEED TO CHANGE mp3s to wav
#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <MMsystem.h>

using namespace std;

void displayBoard(char userGrid[][4]);
void ping(int board[][4]);
int randomCol();
int randomRow();
int orient();


void cinSafeInt(int &val)
{
	cin >> val;
	
	if (cin.fail())
	{
        cin.clear();
        cin.ignore(100,'\n');
    }
}

void displayBoard(char userGrid[][4])
{
	 cout << endl;
	 cout << "         Columns         " << endl << endl; 
	   
     for (int i = 0; i < 6; i++)
     { 
         cout << "Row " << i+1 << "     ";
         for (int q = 0; q < 4; q++)
         {
             cout << userGrid[i][q];
             if (q == 3)
             {
             	cout << endl;
             }
         }
     }
}

int randomRow() 
{
	int newNum = 0;
	newNum=  rand() % 6 + 1;
	//cout << "Generating Row"<<endl;
	return newNum-1;

}
int randomCol()
{
		int newNum = 0;
	newNum=  rand() % 4 + 1;
	//cout << "Generating Collumn"<<endl;
	return newNum-1;


}
int orient()
{
	int newNum = 0;
	newNum = rand() % 2 + 1;
	return newNum;
}

int _tmain(int argc, _TCHAR* argv[])
{

cout << endl << endl << "        ||||||------Welcome to Battleship, Friend.------||||||" << endl << endl;
    cout << "There are 3 ships. One is 2 spaces, one is 3 spaces, one is 4 spaces. "
    << endl << endl;
    cout << "Think you can handle this?! "<<endl;
    
    
 char pingTest;
     bool finished = 0;    
int row, col, hitA=0, hitB=0, value, hitC=0, tries=0, sunk=0, placeRow=0, placeCol=0, i;
 int j = 0;
 int tempRow, tempCol, direction;

char userGrid[6][4] = {{'O','O','O','O'},
                      {'O','O','O','O'},
                      {'O','O','O','O'},
                      {'O','O','O','O'},
                      {'O','O','O','O'},
                      {'O','O','O','O'}};


/*int board[6][4] = {{1,2,1,1},
                   {1,2,1,4},
                   {1,2,1,4},
                   {1,1,1,4},
                   {3,3,1,4},
                   {1,1,1,1}};*/
//Joshua's Code Starts here for ship placement randomization
int board[6][4] ={{1,1,1,1},
				  {1,1,1,1},
				  {1,1,1,1},
				  {1,1,1,1},
				  {1,1,1,1},
				  {1,1,1,1}};

int bombsDropped[6][4] ={{1,1,1,1},
						 {1,1,1,1},
						 {1,1,1,1},
						 {1,1,1,1},
						 {1,1,1,1},
						{1,1,1,1}};

 //randomize ship placement 
srand(time(NULL)); //Initializes the random number based on current time on PC.
		

do //BOAT NUMBER 1, 2 SPACES
{
	tempRow = randomRow();
	tempCol = randomCol();
	direction = orient();
	
	if(board[tempRow][tempCol] == 1)
	{
		switch(direction)
		{
			case 1: //horizontal{
					{
				if(tempCol !=5 && board[tempRow][tempCol+1]==1)
					{
					board[tempRow][tempCol] = 2;
					board[tempRow][tempCol+1] = 2;

					finished = 1;
					break;
					}
				else if(tempCol !=0 && board[tempRow][tempCol-1]==1)
					{
					board[tempRow][tempCol] = 2;
					board[tempRow][tempCol-1] = 2;
					finished = 1;
					break;	
					}
				else
					break;
					};
			case 2:				//vertical
				{
				if(tempRow !=3 && board[tempRow+1][tempCol]==1)
					{
					board[tempRow][tempCol] = 2;
					board[tempRow+1][tempCol] = 2;

					finished = 1;
					break;
					}
				else if(tempRow !=0 && board[tempRow-1][tempCol]==1)
					{
					board[tempRow][tempCol] = 2;
					board[tempRow-1][tempCol] = 2;
					finished = 1;
					break;
					}
				else 
					break;
				}
			default:
				break;
				
				}//endSwitch
			}//endIf
}while(!finished);
finished = 0;

do //BOAT NUMBER 2, 3 SPACES
{
	tempRow = randomRow();
	tempCol = randomCol();
	direction = orient();
	
	if(board[tempRow][tempCol] == 1)
	{
		switch(direction)
		{
			case 1: //horizontal{
					{
				if(tempCol !=5 && tempCol != 4 && board[tempRow][tempCol+1]==1 && board[tempRow][tempCol+2]==1)
					{
					board[tempRow][tempCol] = 3;
					board[tempRow][tempCol+1] = 3;
					board[tempRow][tempCol+2] = 3;

					finished = 1;
					break;
					}
				else if(tempCol !=0 && tempCol != 1 && board[tempRow][tempCol-1]==1 &&board[tempRow][tempCol-2] == 1)
					{
					board[tempRow][tempCol] = 3;
					board[tempRow][tempCol-1] = 3;
					board[tempRow][tempCol-2] = 3;
					finished = 1;
					break;	
					}
				else
					break;
					}
			case 2:				//vertical
				{
				if(tempRow !=3 && tempRow != 2 && board[tempRow+1][tempCol]==1 && board[tempRow+2][tempCol] ==1)
					{
					board[tempRow][tempCol] = 3;
					board[tempRow+1][tempCol] = 3;
					board[tempRow+2][tempCol] = 3;

					finished = 1;
					break;
					}
				else if(tempRow !=0 && tempRow != 1 && board[tempRow-1][tempCol]==1 && board[tempRow-2][tempCol] == 1)
					{
					board[tempRow][tempCol] = 3;
					board[tempRow-1][tempCol] = 3;
					board[tempRow-2][tempCol] = 3;

					finished = 1;
					break;
					}
				else
					break;
				}
				default:
					break;
				}//endswitch
			
		}//endIf
}while(!finished);
finished = 0;



do //BOAT NUMBER 3, 4 SPACES
{
	tempRow = randomRow();
	tempCol = randomCol();
	direction = orient();
	
	if(board[tempRow][tempCol] == 1)
	{
		switch(direction)
		{
			case 1: //horizontal{
					{
				if(tempCol < 3 && board[tempRow][tempCol+1]==1 && board[tempRow][tempCol+2]==1 && board[tempRow][tempCol+3] == 1)
					{
					board[tempRow][tempCol] = 4;
					board[tempRow][tempCol+1] = 4;
					board[tempRow][tempCol+2] = 4;
					board[tempRow][tempCol+3] = 4;
					finished = 1;

					break;
					}
				else if(tempCol > 3 && board[tempRow][tempCol-1]==1 && board[tempRow][tempCol-2]==1 && board[tempRow][tempCol-3] ==1)
					{
					board[tempRow][tempCol] = 4;
					board[tempRow][tempCol-1] = 4;
					board[tempRow][tempCol-2] = 4;
					board[tempRow][tempCol-3] = 4;
					finished = 1;

					break;	
					}
				else
					break;
					}
			case 2:				//vertical
				{
				if(tempRow == 0 && board[tempRow+1][tempCol]==1 && board[tempRow+2][tempCol]==1 && board[tempRow+3][tempCol] ==1)
					{
					board[tempRow][tempCol] = 4;
					board[tempRow+1][tempCol] = 4;
					board[tempRow+2][tempCol] = 4;
					board[tempRow+3][tempCol] = 4;
					finished = 1;
					break;
					}
				else if(tempRow == 3 && board[tempRow-1][tempCol]==1 && board[tempRow-2][tempCol]==1 && board[tempRow-3][tempCol] ==1)
					{
					board[tempRow][tempCol] = 4;
					board[tempRow-1][tempCol] = 4;
					board[tempRow-2][tempCol] = 4;
					board[tempRow-3][tempCol] = 4;

					finished = 1;
					break;
					}
				else
					break;
				}//endCase
				default:
					break;
				}//EndSwitch
			}//EndIF
}while(!finished);
finished = 0;





 do
{                      
	
    cout << endl << endl << "This is what your board looks like. "; 
	displayBoard(userGrid);  

	cout << endl << endl << "Please type B to bomb or P to ping a location with radar. ";
	cin >> pingTest;
	switch(pingTest){
	case 'p':
	case 'P':
		ping(board);
		break;

	default: break;
	}
    cout << endl << endl << "This is what your board looks like. ";
    cout << endl;
    
    displayBoard(userGrid);
    
  

    cout << endl << endl << "Please choose a row to bomb (1-6): ";
    cinSafeInt(row);
    
    
    cout << "Please choose a column to bomb (1-4): " ;
    cinSafeInt(col);
    
    cout << endl;
    
 if (col > 0 && col < 5)
    {
       if (row > 0 && row < 7)
             {   
                 value = board[row-1][col-1];
               
       if(bombsDropped[row-1][col-1] == 2)
		   cout<< "You already bombed this location. Please stop wasting expensive ammunition.\n The United States thanks you for your cooperation.";
	   else{//big else
		   bombsDropped[row-1][col-1] = 2;
   
	
    
         if (value == 1)
               {
				   PlaySound(TEXT("splash.WAV"), NULL,  SND_FILENAME);
				
               cout << "The coordinate you picked was a miss. Please try again. ";
               tries++;
               }
    
         
         else if (value == 2)
                 {
					 PlaySound(TEXT("explosion.mp3"), NULL,  SND_FILENAME);
                 cout << ">>You have hit ship 1. ";
              
                 tries++;
                 hitA++;
              
              userGrid[row-1][col-1] = 'X';
              board[row-1][col-1] = 5;
              
              if (hitA == 2)
              {
                       cout << ">>You have sunk ship 1!<<";
                       hitA = 0;
                       sunk++;
              }
                
                 else
                 {
                 cout << 2 - hitA << " more hit(s) and you sink it.<< ";
                          
              
                 }
    }
    
         else if (value == 3)
         {
			 PlaySound(TEXT("explosion.mp3"), NULL,  SND_FILENAME);
              cout << ">>You have hit ship 2. ";  
              
              tries++;            
              hitB++;
              
              userGrid[row-1][col-1] = 'X';
              board[row-1][col-1] = 5;
              
              if (hitB == 3)
              {
                       cout << ">>You have sunk ship 2!<<" << endl;
                       hitB = 0;
                       sunk++;
              }
              
                 else
                 {
                 cout << 3 - hitB << " more hit(s) and you sink it.<< ";
              
              
                 }
    }
    
        else if (value == 4)
        { 
			PlaySound(TEXT("explosion02.mp3"), NULL,  SND_FILENAME);
               cout << ">>You have hit ship 3. ";  
              
               tries++;
               hitC++;
              
               userGrid[row-1][col-1] = 'X';
               board[row-1][col-1] = 5;
              
              if (hitC == 4)
              {
                       cout << ">>You have sunk ship 3!<<" << endl;
                       hitC = 0;
                       sunk++;
              }
              
                else
                {
                cout << 4 - hitC << " more hit(s) and you sink it.<< ";
              
                }
        }
        
        else if (value == 5)
             {
             cout << endl << "You already hit that space!!" << endl;
             
             }
             }
             
        }
     
     else 
    {
         cout << endl << "Please enter a valid row and column number." << endl << endl;
    }
    
	}//end big else

   if (sunk == 3)
  {
  cout << endl;
  
              displayBoard(userGrid);
      
  cout << endl << endl << "Congratulations! You have sunk all 3 ships. You win the game! " 
  << endl << endl << "It only took you " << tries << " tries!" << endl << endl;  
  
  }
  }
  
  
  
  while (sunk < 3);
  

  
    system("PAUSE");
    return EXIT_SUCCESS;
}

void ping(int board[][4]){
	bool finished = 0;
	while(!finished){
	int row, col, value;
	cout << endl << endl << "Please choose a row to ping (1-6): ";
    cinSafeInt(row);
    
    
    cout << "Please choose a column to ping (1-4): " ;
    cinSafeInt(col);
    
    cout << endl;

	 if (col > 0 && col < 5)
    {
       if (row > 0 && row < 7)
             {   PlaySound(TEXT("ping.WAV"), NULL,  SND_FILENAME);
				getchar();
                 value = board[row-1][col-1];
				 if(value >1 && value <5)
					 {
					 cout<< "Your radar has located an enemy ship in this location!"<< endl;}
				 else
				 {
				 cout << "Your radar did not return any objects in that location."<<endl;
				 }
					 finished = 1;
	   }
	 }
}
}
