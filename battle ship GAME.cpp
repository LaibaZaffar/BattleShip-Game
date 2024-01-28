#include<iostream>
#include<iomanip>
#include <unistd.h>     //for sleep 
#include<stdlib.h>      // for random number generation
using namespace std;
bool game_over=false;
int player=1;
int mode;
int type;
int score1=0,score2=0;
void swapPlayer();
int arr1[50][50];//arr1 for storing every change in board
int arr2[50][50];// arr2 contain final grid after placing all ships by player1
int arr3[50][50];// arr3 contain final grid after placing all ships by player 2
void saveArray1();
//fuction for allignment of game 
void spaces()
{
	for(int i=0;i<16;i++)
	{
		cout<<endl;
	}
}
//1-function for board allignment
void centre()       
{   
    game_over=false;
    cout<<endl;
	if(type==1){
		int size=8;
	int arr[size][size];
	for(int i=0;i<size;i++)
	{
		cout<<setw(45);
		for(int j=0;j<size;j++)
		{
			cout<<" 0 ";
		}
		cout<<endl;
	}
	}
		if(type==2){
		int size=12;
	int arr[size][size];
	for(int i=0;i<size;i++)
	{
		cout<<setw(45);
		for(int j=0;j<size;j++)
		{
			cout<<" 0 ";
		}
		cout<<endl;
	}
	}
		if(type==3){
		int size=15;
	int arr[size][size];
	for(int i=0;i<size;i++)
	{
		cout<<setw(45);
		for(int j=0;j<size;j++)
		{
			cout<<" 0 ";
		}
		cout<<endl;
	}
	}
	
}
//2-function for popup menu
void menu()
{   

cout<<"\n\n\n\n";
      cout<<setw(98);cout<<"Your carrier ship will have a pointer"<<"1"<<endl;
       cout<<setw(97);cout<<"Your battle ship will have a pointer"<<"2"<<endl;
       cout<<setw(98);cout<<"Your cruiser ship will have a pointer"<<" 3"<<endl;
       cout<<setw(100);cout<<"Your Submarine ship will have a pointer"<<" 4"<<endl;
       cout<<setw(100);cout<<"Your Destroyer ship will have a pointer"<<" 5"<<endl;
}
//function for displaying names
void credit()
{	cout<<setw(80)<<"Designed By:"<<endl;
	cout<<setw(80)<<"Kamla Safdar"<<endl;
	cout<<setw(79)<<"Laiba Zafar"<<endl;
}
//function for displaying rules
void rules()
{   
cout<<"\t\t\t\tRules:"<<endl;
 cout<<"\t\t\t\tEach player places the 5 ships somewhere on their board"<<endl;
 cout<<"\t\t\t\tThe ships can only be placed vertically or horizontally"<<endl;
 cout<<"\t\t\t\tDiagonal placement is not allowed                      "<<endl;
 cout<<"\t\t\t\tNo part of a ship may hang off the edge of the board"<<endl;
 cout<<"\t\t\t\tOnce the guessing begins, the players may not move the ships"<<endl;
 cout<<"\t\t\t\tNo ships may be placed on another ship"<<endl;
 cout<<"\t\t\t\tThe 5 ships are:  Carrier , Battleship , Cruiser , Submarine , and Destroyer"<<endl;
}


//4- function to dispaly the board after placing ships
void boardchange()
{   if(type==1)
    {
		for (int i = 0;i < 8;i++)
  	{
		cout << setw(45);
		for (int j = 0;j < 8;j++)
		{
			cout << arr1[i][j] << " ";
		}
		    cout << endl;
	}
   }
   if(type==2)
   {
   
		for (int i = 0;i < 12;i++)
  	{
		cout << setw(45);
		for (int j = 0;j < 12;j++)
		{
			cout << arr1[i][j] << " ";
		}
		    cout << endl;
	}
   }
   
    if(type==3)
   {
   		for (int i = 0;i < 15;i++)
  	{
		cout << setw(45);
		for (int j = 0;j < 15;j++)
		{
			cout << arr1[i][j] << " ";
		}
		    cout << endl;
	}
   }
   
   }


void saveArray()
{     if(type==1)
     { 
    	for (int i = 0;i < 8;i++)
    	{
		  cout << setw(45);
		for (int j = 0;j < 8;j++)
		{
			arr2[i][j]= arr1[i][j];
		}
    	}
    }
		if(type==2)
     { 
    	for (int i = 0;i < 12;i++)
    	{
		  cout << setw(45);
		for (int j = 0;j < 12;j++)
		{
			arr2[i][j]= arr1[i][j];
		}
    	}
    }
       if(type==3)
     { 
    	for (int i = 0;i < 15;i++)
    	{
		  cout << setw(45);
		for (int j = 0;j < 15;j++)
		{
			arr2[i][j]= arr1[i][j];
		}
    	}
    }
	
}
//function to place submarine
void submarinePlacement()
{    
	int point,x,y,direction;
	cout << "The size of submarine is 3" << endl;
	cout << "Enter the orientation for submarine, For x-axis enter 1 and for y-axis enter 2:  ";
	if((mode==1) && (type==1))
	{
		cin>>direction;
		while((direction!=1)&&(direction!=2))
		{
			cout<<"You entered wrong input"<<endl;
			cout<<"Again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
  	cin >> x >> y;
  	//for x-coordinate
 	if (direction == 1)
 	{
 		 while((y == 6 || y==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
 		 {   
	 		cout<<"This place is already occupied by ship.You can't place ship here or there is no enough place there"<<endl;
  		    cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	}
		if ((x >= 0 && x <= 7) && (y != 6 || y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+3;j++)
				{
				
					arr1[i][j] = 4;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x == 6 || x==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	        	cout<<"This place is already occupied by ship. You can't place ship here or there is no enough place there"<<endl;
  		    cout<<"Please choose another location:"<<endl;
		    cin >> x >> y;	
	     }
		 if ((y >= 0 && y <= 7) && (x != 6 || x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
		   	}
		 }    
		       boardchange();
	}	
  }
  
  	if((mode==1) && (type==2))
	{
		 cin>>direction;
			while((direction!=1)&&(direction!=2))
		{
			cout<<"You entered wrong input!"<<endl;
			cout<<"Again enter direction: "<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
	 if (direction == 1)
	{   
	      while ((x>9 )|| ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    cout<<"Please choose another location:  "<<endl;
		    cin >> x >> y;	
	  }
		if ((x >= 0 && x <= 11) && (y<=9))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+3;j++)
				{
				
					arr1[i][j] = 4;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x>9 ) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	     	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  		    cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;	
	     	
	     }
		 if ((y >= 0 && y <= 11) && (x<=9))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
		   	}
		 }    
		       boardchange();
	}	
  }
  
      	if((mode==1) && (type==3))
	{
		cin>>direction;
			while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
     	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y > 12 ) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  		    cout<<"Please choose another location"<<endl;
		    cin >> x >> y;	
	     	
	    
	 }
		if ((x >= 0 && x <= 14) && (y<=12))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+3;j++)
				{
				
					arr1[i][j] = 4;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x>12 ) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	     	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there"<<endl;
  		    cout<<"Please choose another location"<<endl;
		    cin >> x >> y;	
	     }
		 if ((y >= 0 && y <= 14) && (x<=12))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
		   	}
		 }    
		       boardchange();
	}	
  }
  if((mode==2)&& (type ==1))
  {
  	
    if (player==1)
    {
    	cin>>direction;
    		while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}

	cout << "Enter x and y coordinate:  ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y == 6 || y==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	{
	     	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  		    cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	}
		if ((x >= 0 && x <= 7) && (y != 6 || y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
			     {
					arr1[i][j] = 4;		
				 }
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x == 6 || x==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	     	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  		    cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	     }
		 if ((y >= 0 && y <= 7) && (x != 6 || x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
			}
	   	}
		       boardchange();
	}	
} 

  if(player==3)
  {
	 direction=rand()%2;
 	cout << "Enter x and y coordinate   ";
  	x=rand()%7;
 	y=rand()%7;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y == 6 || y==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  		    cout<<"Please choose another location:  "<<endl;
  		    x=rand()%7;
  		    y=rand()%7;
  	}
		if ((x >= 0 && x <= 7) && (y != 6 || y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
				{
					arr1[i][j] = 4;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x == 6 || x==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
		   cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  		    cout<<"Please choose another location"<<endl;
		   x=rand()%7;
	       y=rand()%7;
	}
		 if ((y >= 0 && y <= 7) && (x != 6 || x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+3;j++)
				{
					arr1[j][i] = 4;		
				}
		 	}
	  	}   
		       boardchange();
	}	
  	
   } 
}

if((mode==2)&& (type ==2))
  {
  	
    if (player==1)
    {
    	cin>>direction;
    		while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}

	cout << "Enter x and y coordinate:  ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1) 
	{   
	   while((y>9)|| ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	{
		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  		    cout<<"Please choose another location"<<endl;
			cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y<=9))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
			     {
					arr1[i][j] = 4;		
				 }
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x >9) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	        cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  		    cout<<"Please choose another location"<<endl;	
		    cin >> x >> y;
	     }
	     if ((y >= 0 && y <= 11) && (x<=9))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
			}
	   	}
		       boardchange();
	}	
} 

  if(player==3)
  {
	direction=rand()%2;
 	 cout << "Enter x and y coordinate   ";
  	x=rand()%11;
 	y=rand()%11;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y>9) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  		cout<<"Please choose another location"<<endl;	
	    x=rand()%11;
	    y=rand()%11;
	 }
		if ((x >= 0 && x <= 11) && (y<=9))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
				{
					arr1[i][j] = 4;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
		while((x>9) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		   x=rand()%11;
	       y=rand()%11;
	    }
		 if ((y >= 0 && y <= 11) && (x<=9))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+3;j++)
				{
					arr1[j][i] = 4;		
				}
		 	}
	  	}   
		       boardchange();
	}	
  	
   } 
}

if((mode==2)&& (type ==3))
  {
  	
    if (player==1)
    {
    	cin>>direction;
    		while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
       cout << "Enter x and y coordinate:  ";
	   cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y>12) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	{
			cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
	        cin >> x >> y;
	 }
		if ((x >= 0 && x <= 14) && (y <=12))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
			     {
					arr1[i][j] = 4;		
				 }
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x>12) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	     {
	     	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	     }
		 if ((y >= 0&& y<=14) && (x<=12))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+3;j++)
				{
				
					arr1[j][i] = 4;
					
				}
			}
	   	}
		       boardchange();
	}	
} 

  if(player==3)
  {
	 direction=rand()%2;
 	cout << "Enter x and y coordinate   ";
  	x=rand()%14;
 	y=rand()%14;
	//for x-coordinate
	if (direction == 1)
	{   
	   while ((y>12) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
	    x=rand()%14;
	    y=rand()%14;
	 }
		if ((x >= 0 && x <= 14) && (y<=12))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+3;j++)
				{
					arr1[i][j] = 3;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while ((x>12) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	    cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		   x=rand()%14;
	       y=rand()%14;
	    }
		 if ((y >= 0 && y <= 14) && (x<=12))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+3;j++)
				{
					arr1[j][i] = 4;		
				}
		 	}
	  	}   
		       boardchange();
	}	
  	
   } 
}
}
//function to place destroyer ship
void destroyerPlacement()
{
	int point,x,y,direction;
	cout << "The size of destroyer is 2" << endl;
	cout << "Enter the orientation for destroyer, For x-axis enter 1 and for y-axis enter 2:  ";
	if((mode==1) && (type ==1))
	{
			cin >> direction;
				while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y==7)  || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	 cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    	cout<<"Please choose another location:  "<<endl;
	 	
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 7) && ( y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+2;j++)
				{
				
					arr1[i][j] = 5;
					
				}
			}
		}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5))) 
	   {
	   	     cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    	cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 7) && ( x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
				
					arr1[j][i] = 5;
					
				}
			}
		}
		   boardchange();
	}	
}
    	if((mode==1) && (type ==2))
	{
			cin >> direction;
				while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
			cout << "Enter x and y coordinate   ";
	       cin >> x >> y;
	//for x-coordinate
    	if (direction == 1)
	{   
	   while (( y>10) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))  
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    	cout<<"Please choose another location:  "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && ( y<=10))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+2;j++)
				{
				
					arr1[i][j] = 5;
					
				}
			}
		}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>10) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))  
	   {
	   	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    	cout<<"Please choose another location:  "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 11) && ( x<=10))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
				
					arr1[j][i] = 5;
					
				}
			}
		}
		   boardchange();
	}	
}
    	if((mode==1) && (type ==3))
	{
			cin >> direction;
				while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
			cout << "Enter x and y coordinate   ";
	        cin >> x >> y;
        	//for x-coordinate
	       if (direction == 1)
	   {   
	   while (( y>13) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))  
	  {
	  		cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there"<<endl;
  	    	cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	  }
		if ((x >= 0 && x <= 14) && ( y<=13))
		{ 
			for (int i = x;i == x;i++)
			{
			
				for (int j = y; j< y+2;j++)
				{
				
					arr1[i][j] = 5;
					
				}
			}
		}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>13) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))  
	   {
	   	    cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    	cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 14 ) && ( x<=13))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
				
					arr1[j][i] = 5;
					
				}
			}
		}
		   boardchange();
	}	
}
if((mode==2)&& (type==1))
	{
	if(player==1)
	{
	cin >> direction;
		while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y==7) || ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))   
	 {
	 	 cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 7) && ( y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
				arr1[i][j] = 5;	
				}
			 }
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x==7) ||  ((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))   
	   {
	   	    cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 7) && ( x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;	
				}
			}
		}
		   boardchange();
	}	
		
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:  ";
     x=rand()%7;
     y=rand()%7;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y==7) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))   
	 {
	 	 cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		 x=rand()%7;
         y=rand()%7;
	 }
		if ((x >= 0 && x <= 7) && ( y!=7))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
					arr1[i][j] = 5;	
				}
		 	}
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x==7) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	      cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		     x=rand()%7;
             y=rand()%7;
	    }
		 if ((y >= 0 && y <= 7) && ( x!=7))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;
				}
			}
		 }
		   boardchange();
	}	
}
	
}
if((mode==2)&& (type==2))
	{
	if(player==1)
	{
	cin >> direction;
		while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y>10) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && ( y<=10))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
				arr1[i][j] = 5;	
				}
			 }
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>10) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	    	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 11) && ( x<=10))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;	
				}
			}
		}
		   boardchange();
	}	
		
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:  ";
     x=rand()%11;
     y=rand()%11;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y>10) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    	cout<<"Please choose another location"<<endl;
		 x=rand()%11;
         y=rand()%11;
	 }
		if ((x >= 0 && x <= 11) && ( y<=10))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
					arr1[i][j] = 5;	
				}
		 	}
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>10) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	     	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         	cout<<"Please choose another location"<<endl;
		     x=rand()%11;
             y=rand()%11;
	    }
		 if ((y >= 0 && y <= 11) && ( x<=10))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;
				}
			}
		 }
		   boardchange();
	}	
}
	
}
if((mode==2)&& (type==3))
	{
	if(player==1)
	{
	cin >> direction;
		while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y>13) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         	cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 14) && ( y<=13))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
				arr1[i][j] = 5;	
				}
			 }
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>13)  ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	 cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 14) && ( x<=13))
		{ 
			for (int i = y;i == y;i++)
			{
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;	
				}
			}
		}
		   boardchange();
	}	
		
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:  ";
     x=rand()%14;
     y=rand()%14;
	//for x-coordinate
	if (direction == 1)
	{   
	   while (( y>13) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	 cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    cout<<"Please choose another location"<<endl;
		 x=rand()%14;
         y=rand()%14;
	 }
		if ((x >= 0 && x <= 14) && ( y<=13))
		{ 
			for (int i = x;i == x;i++)
			{
				for (int j = y; j< y+2;j++)
				{
					arr1[i][j] = 5;	
				}
		 	}
	 	}
	        	boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{   
	   while (( x>13) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	      cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	    cout<<"Please choose another location"<<endl;
		     x=rand()%14;
             y=rand()%14;
	    }
		 if ((y >= 0 && y <= 14) && ( x<=13))
		{ 
			for (int i = y;i == y;i++)
			{
			
				for (int j = x; j< x+2;j++)
				{
					arr1[j][i] = 5;
				}
			}
		 }
		   boardchange();
	}	
}
	
}
}

//function to place cruiser ship
void cruiserPlacement()
{
	int point,x,y,direction;
	cout << "The size of cruiser is 4" << endl;
	cout << "Enter the orientation for cruiser, For x-axis enter 1 and for y-axis enter 2:  ";
	if(mode==1 && type ==1)
	{
		cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	 cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	    cout<<"Please choose another location:  "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 7) && (y<5))
		{ 
			for (int i = x;i == x;i++)
			{
		
				for (int j = y; j< y+4;j++)
				{
				
					arr1[i][j] = 3;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	     cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 7) || (x>=5))
		{ 
			for (int i = y;i == y;i++)
			{  
			
				for (int j = x; j< x+4;j++)
				{
				
					arr1[j][i] = 3;
					
				}
			}
		}
		boardchange();
	}	
	}
	if(mode==1 && type ==2)
	{
		cin >> direction;
				while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while (( y>8 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	 cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y<=8))
		{ 
			for (int i = x;i == x;i++)
			{
		
				for (int j = y; j< y+4;j++)
				{
				
					arr1[i][j] = 3;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>8 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	 cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location:  "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 11) || (x<=8))
		{ 
			for (int i = y;i == y;i++)
			{  
			
				for (int j = x; j< x+4;j++)
				{
				
					arr1[j][i] = 3;
					
				}
			}
		}
		boardchange();
	}	
	}
	if(mode==1 && type ==3)
	{
		cin >> direction;
				while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	   cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>11 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	 cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 14) && (y<=11))
		{ 
			for (int i = x;i == x;i++)
			{
		
				for (int j = y; j< y+4;j++)
				{
				
					arr1[i][j] = 3;
					
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>11) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 14) || (x<=11))
		{ 
			for (int i = y;i == y;i++)
			{  
			
				for (int j = x; j< x+4;j++)
				{
				
					arr1[j][i] = 3;
					
				}
			}
		}
		boardchange();
	}	
	}
	if((mode==2)&& (type==1))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 7) && (y<5))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
			  	{
			 	arr1[i][j] = 3;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 7) || (x>=5))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%7;
    y=rand()%7;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5))) 
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%7;
         y=rand()%7;
	 }
		if ((x >= 0 && x <= 7) && (y<5))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 3;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>=5 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
		     
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%7;
             y=rand()%7;
	    }
		 if ((y >= 0 && y <= 7) || (x>=5))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;
				}
			}
		}
		boardchange();
	}
		
	}
}
if((mode==2)&& (type==2))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>8 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y<=8))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
			  	{
			 	arr1[i][j] = 3;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>8 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 11) || (x<=8))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%11;
    y=rand()%11;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>8 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%11;
         y=rand()%11;
	 }
		if ((x >= 0 && x <= 11) && (y<=8))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 3;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>8 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%11;
             y=rand()%11;
	    }
		 if ((y >= 0 && y <= 11) || (x<=8))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;
				}
			}
		}
		boardchange();
	}
		
	}
}
if((mode==2)&& (type==3))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>11 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 14) && (y<=11))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
			  	{
			 	arr1[i][j] = 3;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>11 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 14) || (x<=11))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%14;
    y=rand()%14;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>11 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%14;
         y=rand()%14;
	 }
		if ((x >= 0 && x <= 7) && (y<=11))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 3;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>11 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   		cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%14;
             y=rand()%14;
	    }
		 if ((y >= 0 && y <= 14) || (x<=11))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 3;
				}
			}
		}
		boardchange();
	}
		
	}
}
}

//function to place carrier ship
void placementcarrier()
{
	int x, y, direction;
	
	cout << "The size of carrier is 8" << endl;
	cout << "Enter the orientation for carrier for x-axis enter 1 and for y-axis enter 2  ";
	if(mode==1 && type==1)
	{
			cin >> direction;
					while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
		cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	if (direction == 1)
	{
	   while ((y != 0)||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	 }
		if ((x>= 0 && x <= 7) && (y == 0))
		{
			for (int i = x;i == x;i++)
			{
				for (int j = y;j < 8;j++)
				{
					arr1[i][j] = 1;
					
				}
			}
		}
		boardchange();
	}
	//for y-direction
	if (direction == 2)
	{
		while ((x != 0)||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
		{
			cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
			cin >> x >> y;
		}
		if ((y>= 0 && y <= 7) && (x == 0))
		{
			for (int i = y;i == y;i++)
			{
				for (int j = x;j < 8;j++)
				{
					arr1[j][i] = 1;

				}
			}
		}
		boardchange();
	}
	}
	if(mode==1 && type ==2)
	{
			cin >> direction;
					while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
			cout << "Enter x and y coordinate   ";
    	cin >> x >> y;
	if (direction == 1)
	{
	   while ((y>4) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y<=4))
		{
			for (int i = x;i == x;i++)
			{
				for (int j = y;j < 8;j++)
				{
					arr1[i][j] = 1;
					
				}
			}
		}
		boardchange();
	}
	if (direction == 2)
	{
		while ((x >4)||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
		{
			cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
			cin >> x >> y;
		}
		if ((y>= 0 && y <= 11) && (x <=4))
		{
			for (int i = y;i == y;i++)
			{
				for (int j = x;j < 8;j++)
				{
					arr1[j][i] = 1;

				}
			}
		}
		boardchange();
	}
     }
     if(( mode==1 )&& (type ==3))
	{
			cin >> direction;
					while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	 cout << "Enter x and y coordinate   ";
	cin >> x >> y;
	if (direction == 1)
	{
	   while ((y >7)||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y <=7))
		{
			for (int i = x;i == x;i++)
			{
				for (int j = y;j < 8;j++)
				{
					arr1[i][j] = 1;
					
				}
			}
		}
		boardchange();
	}
	if (direction == 2)
	{
		while ((x >7 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
		{
			cout<<"This place is already occupied by ship.You can't place ship here or it is no enough place there!"<<endl;
  	         cout<<"Please choose another location: "<<endl;
			cin >> x >> y;
		}
		if ((y>= 0 && y <= 11) && (x <=7))
		{
			for (int i = y;i == y;i++)
			{
				for (int j = x;j < 8;j++)
				{
					arr1[j][i] = 1;

				}
			}
		}
		boardchange();
	}
}
if((mode==2)&& (type==1))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y!=0 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 7) && (y==0))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+8;j++)
			  	{
			 	arr1[i][j] = 1;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x!=0 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 7) || (x==0))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+8;j++)
				{
					arr1[j][i] = 1;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%7;
    y=rand()%7;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y!=0 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%7;
         y=rand()%7;
	 }
		if ((x >= 0 && x <= 7) && (y==0))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 1;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x!=0 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%7;
             y=rand()%7;
	    }
		 if ((y >= 0 && y <= 7) || (x==0))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 1;
				}
			}
		}
		boardchange();
	}
		
	}
}
if((mode==2)&& (type==2))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1)&&(direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>4 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 11) && (y<=4))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+8;j++)
			  	{
			 	arr1[i][j] = 1;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>4 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 11) || (x<=4))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+8;j++)
				{
					arr1[j][i] = 1;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%11;
    y=rand()%11;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>4 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%11;
         y=rand()%11;
	 }
		if ((x >= 0 && x <= 11) && (y<=4))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 1;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>4 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%11;
             y=rand()%11;
	    }
		 if ((y >= 0 && y <= 11) || (x<=4))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 1;
				}
			}
		}
		boardchange();
	}
		
	}
}
if((mode==2)&& (type==3))
	{
	if(player==1)
	{
	cin >> direction;
			while((direction!=1) && (direction!=2))
		{
			cout<<"You enter wrong input"<<endl;
			cout<<"again enter direction"<<endl;
			cin>>direction;
		}
	cout << "Enter x and y coordinate:   ";
	cin >> x >> y;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>7 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		cin >> x >> y;
	 }
		if ((x >= 0 && x <= 14) && (y<=7))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+8;j++)
			  	{
			 	arr1[i][j] = 1;
			 	}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>7 ) ||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		    cin >> x >> y;
	    }
		 if ((y >= 0 && y <= 14) || (x<=7))
		{ 
			for (int i = y;i == y;i++)
			{  
		     	for (int j = x; j< x+8;j++)
				{
					arr1[j][i] = 1;	
				}
			}
		}
		boardchange();
	}	
	//for player 3 (Computer)	
	}
	if(player==3)
	{
	 direction=rand()%2;
	cout << "Enter x and y coordinate:   ";
    x=rand()%14;
    y=rand()%14;
	//for x-coordinate
     if (direction == 1)
	{   
	   while ((y>7 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	 {
	 	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		 x=rand()%14;
         y=rand()%14;
	 }
		if ((x >= 0 && x <= 14) && (y<=7))
		{ 
			for (int i = x;i == x;i++)
			{
		    	for (int j = y; j< y+4;j++)
				{
					arr1[i][j] = 1;	
				}
			}
		}
		boardchange();
	}
	   //for y-coordiante
		if (direction == 2)
	{     
	   while ((x>7 )||((arr1[x][y]==1)|| (arr1[x][y]==2) || (arr1[x][y]==3)||(arr1[x][y]==4) || (arr1[x][y]==5)))
	   {
	   	cout<<"This place is already occupied by ship. So,You can't place ship here.or there is no enough place there"<<endl;
  	         cout<<"Please choose another location"<<endl;
		     x=rand()%14;
             y=rand()%14;
	    }
		 if ((y >= 0 && y <= 14) || (x<=7))
		{ 
			for (int i = y;i == y;i++)
			{  
		    	for (int j = x; j< x+4;j++)
				{
					arr1[j][i] = 1;
				}
			}
		}
		boardchange();
	}
		
	}
}
}

void saveArray1()
{     if((mode==1) && (type ==1))
      {
		for (int i = 0;i < 8;i++)
     	{
		for (int j = 0;j < 8;j++)
		{
			arr3[i][j]= arr1[i][j];
		}
		 }
	}
	if((mode==1) && (type ==2))
      {
		for (int i = 0;i < 12;i++)
     	{
		for (int j = 0;j < 12;j++)
		{
			arr3[i][j]= arr1[i][j];
		} }
	}
		if((mode==1) && (type ==3))
      {
		for (int i = 0;i < 15;i++)
     	{
		for (int j = 0;j < 15;j++)
		{
			arr3[i][j]= arr1[i][j];
		} }
      }
}
void attack()
{
	int hitx,hity,score=0;
	cout<<"Player "<<player<< " enter you attack place "<<endl;
	  if(mode==1)
	{
		if(player==1)
	{
			cout<<"Enter x and y coordinate   ";
			cin>>hitx>>hity;
		for(int i=hitx;i==hitx;i++)
	{
		for(int j=hity;j==hity;j++)
		{
			if((arr3[i][j]==1) || (arr3[i][j]==2) || (arr3[i][j]==3) || (arr3[i][j]==4) || (arr3[i][j]==5))
			{ 
			     cout<<"\a";
				cout<<"You bomb the ship"<<endl;
				arr1[i][j]=9;
			 	score1=score1+5;
			 	cout<<"Player 1 your score is "<<score1<<endl;
			 	if(score1==55)
			 	    {
			 		game_over=true;
			 		 cout<<"GAME OVER!"<<endl;
			 		cout<<"Winner is player 1"<<endl;
			 		 cout<<"\a";
			 		cout<<"Congratulation :)"<<endl;
			 	    break;
			 	    }
			      boardchange();
				  swapPlayer();
			 }
			else
			{   	cout<<"You missed the attack"<<endl;
					arr1[i][j]=7;
					boardchange();
			    	swapPlayer();
			}
		}
	}
}

   else	if(player==2)
	{
			cout<<"Enter x and y coordinate   ";
			cin>>hitx>>hity;
		for(int i=hitx;i==hitx;i++)
   	{
		for(int j=hity;j==hity;j++)
		{
			if((arr2[i][j]==1) || (arr3[i][j]==2) || (arr2[i][j]==3) || (arr2[i][j]==4) || (arr2[i][j]==5))
			{	
			   cout<<"\a";
			   cout<<"You bomb the ship"<<endl;
				arr1[i][j]=9;
				score2=score2+5;
				cout<<"Player 2 your score is "<<score2;
				if(score2==55)
			 	{
			 		game_over=true;
			 		cout<<"GAME OVER!"<<endl;
			 		cout<<"Winner is player 2"<<endl;
			 		cout<<"Congratulation :)"<<endl;
			 		break;
			 	}
			    boardchange();
				swapPlayer();
			}
			else
			{	
			    cout<<"You missed the attack"<<endl;
				arr1[i][j]=7;
				boardchange();
			    swapPlayer();
			}
        }
     }
   }
}
	
   if(mode==2) 
   {
   		if(player==1)
	{
	    cout<<"Enter x and y coordinate   ";
	    cin>>hitx>>hity;
		
	}
	else if(player==3)
	{    
	    if(type==1){
		cout<<"Computer's turn!"<<endl;
		cout<<"Enter x and y coordinate   ";
		hitx=rand()%7;
		hity=rand()%7;
		}
		if(type==2){
		cout<<"Computer's turn"<<endl;
		cout<<"Enter x and y coordinate   ";
		hitx=rand()%11;
		hity=rand()%11;
		}
			if(type==3){
		cout<<"Computer's turn"<<endl;
		cout<<"Enter x and y coordinate   ";
		hitx=rand()%14;
		hity=rand()%14;
		}
		
	}
	//comparig the hits and ships
	if(player==1)
	{
		for(int i=hitx;i==hitx;i++)
	{
		for(int j=hity;j==hity;j++)
		{
			if((arr3[i][j]==1) || (arr3[i][j]==2) || (arr3[i][j]==3) || (arr3[i][j]==4))
			{    
				cout<<"You bomb the ship"<<endl;
				arr1[i][j]=9;
			 	score1=score1+5;
			 	cout<<"Player 1 your score is "<<endl;
			 		if(score1==55)
			 	{
			 		game_over=true;
			 		cout<<"GAME OVER!"<<endl;
			 		cout<<"Winner is player 1"<<endl;
			 		cout<<"Congratulations :)"<<endl;
			 	    break;
			 	}
			      boardchange();
				  swapPlayer();
				}
			else
			{	cout<<"You missed the attack"<<endl;
					arr1[i][j]=7;
					boardchange();
			    	swapPlayer();
				
			}
		}
	}
	}

   else	if(player==3)
	{
		for(int i=hitx;i==hitx;i++)
	{
		for(int j=hity;j==hity;j++)
		{
			if((arr2[i][j]==1) || (arr2[i][j]==2) || (arr2[i][j]==3) || (arr2[i][j]==4))
			{	cout<<"You bomb the ship"<<endl;
				arr1[i][j]=9;
				score2=score2+5;
				cout<<"Score of computer is "<<score2<<endl;
				if(score2==55)
			 	{
			 		game_over=true;
			 		cout<<"GAME OVER!"<<endl;
			 		cout<<"Winner is computer"<<endl;
			 		cout<<"Congratulation :)"<<endl;
			 		break;
			 	}
			    boardchange();
				swapPlayer();
			}
			 else
		 	{	
			     cout<<"You missed the attack"<<endl;
					arr1[i][j]=7;
				    boardchange();
				     swapPlayer();
			}
        }
    }
 }
}

}

	
//function to swap player's turn
void swapPlayer()
{  if(mode==1)
   {
	if(player==1)
	{
		player=2;
	}
	else
	player=1;
   }
	
	 if(mode==2){
	 	if(player==1)
	{
		player=3;
	}
	else
	player=1;
	 }
	
}
//main function
int main()
{   
	 system("color 4F");
     spaces();
     cout<<setw(80);cout<<"BATTLESHIP"<<endl<<endl;
     cout<<setw(85);cout<<"\t  Sink others before they sink you"<<endl;
     sleep(3);
     system("cls");
     spaces();
      cout<<setw(80);credit();
     sleep(3);
     system("cls");
     spaces();
     rules();
     sleep(7);
     system("cls");
     spaces();
     cout<<setw(90);cout<<"THE GAME CONSITS OF TWO MODES: \n";
     cout<<setw(79);cout<<"1.Player VS. Player \n";
     cout<<setw(81);cout<<"2.Player VS. Computer \n";
     cout<<setw(81); cout<<"Enter your Play Mode:  ";
     cout<<setw(80);cin>>mode;
     cout<<endl;
     cout<<setw(87);cout<<"Game consits of Three levels:\n";
     cout<<setw(65);cout<<"1.EASY\n";
     cout<<setw(68);cout<<"2.MEDIUM \n";
     cout<<setw(66);cout<<"3.HARD \n";
     cout<<setw(82);cout<<"Enter your level type:  ";
      cin>>type;
     system("cls");
     
     switch(mode)
     {
     	case 1:
     	{
     	spaces();
		 cout<<setw(100);cout<<"You have choosed Player Vs. Player mode \n";
		 cout<<setw(100);cout<<"It's Player 1 Turn first! \n";
     	 menu();
	     sleep(7);
         system("cls");
         centre();
         if(type==1)
         {
         	
        placementcarrier();
        cout<<"Place another carrier ship"<<endl;
        placementcarrier();
        submarinePlacement();
        cout<<"Place another submarine ship"<<endl;
        submarinePlacement();
         destroyerPlacement();
         cout<<"Place another destroyer ship"<<endl;
     	 destroyerPlacement();
         cruiserPlacement();
          cout<<"Place another cruiser ship"<<endl;
         cruiserPlacement();
         
         sleep(5);
         saveArray();
         sleep(5);
         system("cls");
         }
         if(type==2)
         {
         	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
           }
            if(type==3)
               {
            placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
            placementcarrier();
            cout<<"Place another carrier ship"<<endl;
            placementcarrier();
            cout<<"Place another carrier ship"<<endl;
            placementcarrier();
         	submarinePlacement();
            cout<<"Place another submarine ship"<<endl;
            submarinePlacement();
            cout<<"Place another submarine ship"<<endl;
            submarinePlacement();
            cout<<"Place another submarine ship"<<endl;
            submarinePlacement();
     	    destroyerPlacement();
     	    cout<<"Place another destroyer ship"<<endl;
     	    destroyerPlacement();
     	    cout<<"Place another destroyer ship"<<endl;
     	    destroyerPlacement();
     	    cout<<"Place another destroyer ship"<<endl;
     	    destroyerPlacement();
            cruiserPlacement();
            cout<<"Place another cruiser ship"<<endl;
            cruiserPlacement();
            cout<<"Place another cruiser ship"<<endl;
            cruiserPlacement();
            cout<<"Place another cruiser ship"<<endl;
            cruiserPlacement();
              }
              
         sleep(5);
         saveArray();
         sleep(5);
         system("cls");
         	
              
     //2nd player
     spaces();
     cout<<setw(60);
     cout<<"It's players two turn now"<<endl;
     if(type==1)
     {
     for(int i=0;i<8;i++)
     {
     	for(int j=0;j<8;j++)
     	{
     		arr1[i][j]={0};
	     }
	 }
     }
      if(type==2)
     {
     for(int i=0;i<12;i++)
     {
     	for(int j=0;j<12;j++)
     	{
     		arr1[i][j]={0};
	     }
	 }
     }
     if(type==3)
     {
     for(int i=0;i<15;i++)
     {
     	for(int j=0;j<15;j++)
     	{
     		arr1[i][j]={0};
	     }
	 }
     }

	  sleep(3);
      menu();
	  sleep(7);
      system("cls");
      centre();
     if(type==1)
         {
         	
        placementcarrier();
        cout<<"Place another carrier ship"<<endl;
        placementcarrier();
        submarinePlacement();
        cout<<"Place another submarine ship"<<endl;
        submarinePlacement();
         destroyerPlacement();
         cout<<"Place another destroyer ship"<<endl;
     	 destroyerPlacement();
         cruiserPlacement();
          cout<<"Place another cruiser ship"<<endl;
         cruiserPlacement();
         sleep(5);
         saveArray();
         sleep(5);
         system("cls");
         }
         if(type==2)
         {
         	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
           }
               if(type==3)
               {
               	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
              cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
                cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();   	
			  }
              
         sleep(5);
         saveArray();
         sleep(5);
         system("cls");
         saveArray1();
         sleep(5);
         system("cls");
     if(type==1)
     {
     	for(int i=0;i<8;i++)
     {
     	for(int j=0;j<8;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
     }
      if(type==2)
     {
     	for(int i=0;i<12;i++)
     {
     	for(int j=0;j<12;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
     }
      if(type==3)
     {
     	for(int i=0;i<15;i++)
     {
     	for(int j=0;j<15;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
     }
	 cout<<"If you'll point the attack at right place then it will be shown as '9' \n";
	 cout<<"If you'll point the attack at wrong place then it will be shown as '7' \n";
	  sleep(5);
	 while(game_over==false)
	 {
	 	attack();
	 }
	 break;
}
	 case 2:
	 {
	      system("color 3F");
	 	  spaces();
	 	  player=1;
	 	  cout<<setw(100);cout<<"You have choosed Player Vs.Computer mode \n";
		  cout<<setw(100);cout<<"It's Player 1 Turn first! \n";
		   sleep(3);
          
         menu();
	     sleep(3);
         system("cls");
         centre();     
         player=1;
             if(type==1)
         {
         placementcarrier();
         cout<<"Place another carrier ship"<<endl;
         placementcarrier();
         submarinePlacement();
         cout<<"Place another submarine ship"<<endl;
         submarinePlacement();
         destroyerPlacement();
         cout<<"Place another destroyer ship"<<endl;
     	 destroyerPlacement();
         cruiserPlacement();
          cout<<"Place another cruiser ship"<<endl;
         cruiserPlacement();
         
         sleep(3);
         saveArray();
         system("cls");
         }
         if(type==2)
         {
         	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
           }
               if(type==3)
               {
               	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
              cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
                cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               	
			   }
          saveArray();
          //sleep(3);
         system("cls");
     //2nd player
     player=3;
     spaces();
     cout<<setw(60);cout<<"It's Computer turn now"<<endl;
     sleep(3);
     system("cls");
     if(type==1)
     {
     	 for(int i=0;i<8;i++)
     {
     	for(int j=0;j<8;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
      }
       if(type==2)
     {
     	 for(int i=0;i<12;i++)
     {
     	for(int j=0;j<12;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
      }
       if(type==3)
     {
     	 for(int i=0;i<15;i++)
     {
     	for(int j=0;j<15;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
      }
     spaces();
     menu();
     system("cls");
     centre();
     if(type==1)
     {
	     placementcarrier();
         cout<<"Place another carrier ship"<<endl;
         placementcarrier();
         submarinePlacement();
         cout<<"Place another submarine ship"<<endl;
         submarinePlacement();
         destroyerPlacement();
         cout<<"Place another destroyer ship"<<endl;
     	 destroyerPlacement();
         cruiserPlacement();
          cout<<"Place another cruiser ship"<<endl;
         cruiserPlacement();
     }
     if(type==2)
         {
         	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
           }
            if(type==3)
               {
               	placementcarrier();
         	cout<<"Place another carrier ship"<<endl;
             placementcarrier();
             cout<<"Place another carrier ship"<<endl;
             placementcarrier();
              cout<<"Place another carrier ship"<<endl;
             placementcarrier();
         	 submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
              cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
             cout<<"Place another submarine ship"<<endl;
             submarinePlacement();
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
     	      cout<<"Place another destroyer ship"<<endl;
     	      destroyerPlacement();
              cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
                cout<<"Place another cruiser ship"<<endl;
               cruiserPlacement();
               	}
    
   
     saveArray1();
     swapPlayer();
     system("cls");
      for(int i=0;i<8;i++)
     {
     	for(int j=0;j<8;j++)
     	{
     		arr1[i][j]={0};
		 }
	 }
	 cout<<"If you'll point the attack at right place then it will be shown as '9' \n";
	 cout<<"If you'll point the attack at wrong place then it will be shown as '7' \n";
	 while(game_over==false)
	 {
	 	attack();
	 }
	 	 break;
	 }
  }
}
