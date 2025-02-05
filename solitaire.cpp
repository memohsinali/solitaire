#include<iostream>
using namespace std;

#include "ConsoleFunctions.h"
#include<fcntl.h>
#include <io.h>
//#include "Deck.h"
//#include "PileofCards.h"


class PlayingCard
{
	int rank;  //integer 1 – 13
	int suit; //integer 0 – 3
	char color; // red or black - ‘b’ for black , ‘r’ for red
	bool faceUp; //tells if a card is face up or not
	bool top; //tells if a card is on top of a pile

public:


	const static int DIAMOND;
	const static int HEART;
	const static int SPADE;
	const static int CLUB;

	PlayingCard(int rank = 0, int suit = 0)
	{
		this->faceUp = false;    //initializing to avoid the warning
		this->top = false;
		if (rank == 0 && suit == 0)   //this if condition will prevent assigning 0 to suit and r to colour in case of default constructor
		{
			this->rank = rank;
			this->suit = suit;
			this->color = ' ';
			
		}
		else
		{

			if ((rank >= 1 && rank <= 13) && (suit >= 0 && suit <= 3))
			{
				this->rank = rank;
				this->suit = suit;
			}
			else
			{
				while (rank < 1 || rank > 13)
				{
					cout << "\nInvalid value for rank. Enter the values between 1 to 13 : ";
					cin >> rank;
				}
				this->rank = rank;

				while (suit < 0 || suit > 3)
				{
					cout << "\nInvalid value for suit.\nEnter 0 for DIAMOND.\nEnter 1 for HEART.\nEnter 2 for SPADE.\nEnter 3 for CLUB.\n";
					cin >> suit;
				}
				this->suit = suit;
			}
			if (suit == 0 || suit == 1)
			{
				this->color = 'r';
			}
			else
			{
				this->color = 'b';
			}
		}
	}


	void display(int x, int y)
	{

		if(rank>=1&&rank<=13)   
		{
			ConsoleFunctions temp_obj;   //temporary object made to access functions for the printing of cards
			temp_obj.SetCursorAt(x, y);
			if (faceUp == true && top == true)
			{
				if (this->color == 'b')
					temp_obj.SetColor(0, 15);   //set text colour black and background white
				else
					temp_obj.SetColor(4, 15);   //set text colour red and background white

				int count = 0;  //count will be used for printing. It will store the number of indexes used for the printing in first line.

				if (this->rank == 1)
				{
					temp_obj.writeCharOnConsole('A');
					count++;
				}
				else if (this->rank == 10)
				{
					cout << rank;
					count += 2;
				}
				else if (this->rank == 11)
				{
					temp_obj.writeCharOnConsole('J');
					count++;
				}
				else if (this->rank == 12)
				{
					temp_obj.writeCharOnConsole('Q');
					count++;
				}
				else if (this->rank == 13)
				{
					temp_obj.writeCharOnConsole('K');
					count++;
				}
				else
				{
					cout << rank;
					count++;
				}

				//we have to catch the return type to remove the warning
				int z = _setmode(_fileno(stdout), _O_U16TEXT); // mode for suits set, now use wcout.


				if (suit == 0)
				{
					wcout << L'\u2666';    //unicode for DIAMOND
				}
				else if (suit == 1)
				{
					wcout << L'\u2665';    //unicode for HEART
				}
				else if (suit == 2)
				{
					wcout << L'\u2660';     //unicode for SPADE
				}
				else if (suit == 3)
				{
					wcout << L'\u2663';     //unicode for CLUB
				}

				count++;   //symbol is printed

				int temp_count = count;

				int k = _setmode(_fileno(stdout), _O_TEXT);    // resetting the mode to cout
				for (int j = 0; j < 8; j++)
				{
					if (j == 7)
					{
						for (int i = 0; i < (6 - temp_count); i++)
						{
							temp_obj.writeCharOnConsole(' ');               
						}
					}
					else
					{
						for (int i = count; i < 6; i++)
						{
							temp_obj.writeCharOnConsole(' ');
						}
						count = 0;
						temp_obj.SetCursorAt(x, ++y);
					}

				}


				if (this->rank == 1)
				{
					temp_obj.writeCharOnConsole('A');
				}
				else if (this->rank == 10)
				{
					cout << rank;
				}
				else if (this->rank == 11)
				{
					temp_obj.writeCharOnConsole('J');
				}
				else if (this->rank == 12)
				{
					temp_obj.writeCharOnConsole('Q');
				}
				else if (this->rank == 13)
				{
					temp_obj.writeCharOnConsole('K');
				}
				else
				{
					cout << rank;
				}


				int l = _setmode(_fileno(stdout), _O_U16TEXT); // mode for suits set, now use wcout.

				if (suit == 0)
				{
					wcout << L'\u2666';    //unicode for DIAMOND
				}
				else if (suit == 1)
				{
					wcout << L'\u2665';    //unicode for HEART
				}
				else if (suit == 2)
				{
					wcout << L'\u2660';     //unicode for SPADE
				}
				else if (suit == 3)
				{
					wcout << L'\u2663';     //unicode for CLUB
				}


				int m = _setmode(_fileno(stdout), _O_TEXT);   //resetting mode to cout


				temp_obj.SetColor(15, 0); //set text colour white and background colour black 
			}
			else if (faceUp == true && top == false)
			{
			if (this->color == 'b')
				temp_obj.SetColor(0, 15);   //set text colour black and background white
			else
				temp_obj.SetColor(4, 15);   //set text colour red and background white

			int count = 0;  //count will be used for printing. It will store the number of indexes used for the printing in first line.

			if (this->rank == 1)
			{
				temp_obj.writeCharOnConsole('A');
				count++;
			}
			else if (this->rank == 10)
			{
				cout << rank;
				count += 2;
			}
			else if (this->rank == 11)
			{
				temp_obj.writeCharOnConsole('J');
				count++;
			}
			else if (this->rank == 12)
			{
				temp_obj.writeCharOnConsole('Q');
				count++;
			}
			else if (this->rank == 13)
			{
				temp_obj.writeCharOnConsole('K');
				count++;
			}
			else
			{
				cout << rank;
				count++;
			}

			//we have to catch the return typr to remove the warning
			int z = _setmode(_fileno(stdout), _O_U16TEXT); // mode for suits set, now use wcout.


			if (suit == 0)
			{
				wcout << L'\u2666';    //unicode for DIAMOND
			}
			else if (suit == 1)
			{
				wcout << L'\u2665';    //unicode for HEART
			}
			else if (suit == 2)
			{
				wcout << L'\u2660';     //unicode for SPADE
			}
			else if (suit == 3)
			{
				wcout << L'\u2663';     //unicode for CLUB
			}

			count++;   //symbol is printed

			

			int k = _setmode(_fileno(stdout), _O_TEXT);    // resetting the mode to cout
			for (int j = 0; j < 2; j++)
			{
			
				if(j==0)
				{
					for (int i = count; i < 6; i++)
					{
						temp_obj.writeCharOnConsole(' ');
					}
					temp_obj.SetCursorAt(x, ++y);
				}
				else //when (j==1)
				{
					temp_obj.SetColor(6, 15);  //setting text colour brown and background white
					for (int i = 0; i < 6; i++)
					{
						temp_obj.writeCharOnConsole('_');               
					}
				}

			}
			temp_obj.SetColor(15, 0); //set text colour white and background colour black 
			}
			else if (faceUp == false && top == false)
			{
			temp_obj.SetColor(6, 4);  //setting text color brown and background red   //ask because no code for brown is written
			char ch;   //variable to be printed
			for (int j = 0; j < 2; j++)
			{

				if (j == 0)
					ch = ' ';
				else
					ch = '_';
				for (int i = 0; i < 6; i++)
				{
					temp_obj.writeCharOnConsole(ch);
				}
				temp_obj.SetCursorAt(x, ++y);

			}
			temp_obj.SetColor(15, 0); //set text colour white and background colour black 
            }
			else //when faceup==false and top==true
			{
			temp_obj.SetColor(4, 4);//setting text colour and background colour both red so that even the text is written it is not displayed
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					temp_obj.writeCharOnConsole(' ');
				}
				temp_obj.SetCursorAt(x, ++y);
			}
			temp_obj.SetColor(15, 0); //set text colour white and background colour black 
            }
        }
	}

	


	bool isFaceUp() //returns value of faceUp
	{
		return this->faceUp;
	}
	void setFaceUp(bool value) //sets value of faceUp
	{
		this->faceUp = value;
	}
	bool isTop() //returns value of top
	{
		return this->top;
	}
	void setTop(bool value) //sets value of top
	{
		this->top = value;
	}
	int getSuit() //getter for suit value
	{
		return this->suit;
	}
	int getRank() //getter for rank value
	{
		return this->rank;
	}
	char getColor() //getter for color value
	{
		return this->color;
	}

};

const int PlayingCard::DIAMOND = 0;
const int PlayingCard::HEART = 1;
const int PlayingCard::SPADE = 2;
const int PlayingCard::CLUB = 3;


class PileofCards {
private:
	PlayingCard* pile;
	int top;
	int size;
	point startPt;
	point endPt;
public:
	PileofCards(int size)
	{
		this->size = size;
		this->pile = new PlayingCard[this->size];
		this->top = -1;   //the pile is always empty in the start
		this->startPt.x = 0;    //initializing to avoid warning
		this->startPt.y = 0;
		this->endPt.x = 0;
		this->endPt.y = 0;
	}
	~PileofCards()
	{
		delete[]pile;
		pile = nullptr;
	}

	PlayingCard Peek()
	{
		if (top != -1)
		{
			return pile[top];
		}
	}

	PlayingCard Remove()
	{
		if (IsEmpty() == false)
		{
			top--;
			if (top != -1)
			{
				pile[top].setTop(true);
			}
			return pile[top + 1];   //the value of top is already decremented
		}
		else    //returned a temporary object(with default values) because if nothing is returned it will throw an exception handling error as the return type is an object of Playing Cards
		{
			PlayingCard temp;
			return temp;
		}
	}
	void Add(const PlayingCard& obj)
	{
		if (IsFull() == false)
		{
			if (top != -1)    //checking if the card being added is the first card
			{
				pile[top].setTop(false);   //setting value of top of previously added object as false
			
			}
			pile[top + 1] = obj;   //top points to the last elemet added. So we will add the element in the next index
			top++;
			pile[top].setTop(true); //setting the value of top of latest added object as true
		
		}
	}
	bool IsEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{

			return false;
		}
	}
	bool IsFull()
	{
		if (top == (this->size - 1))
		{
			return true;
		}
		else
		{

			return false;
		}
	}


	int getTop() //returns value of top
	{
		return this->top;
	}
	void setStartPt(int x, int y) //sets startPt
	{
		startPt.x = x;
		startPt.y = y;
	}
	point getStartPt() //returs startPt
	{
		return this->startPt;
	}
	void setEndPt(int x, int y) //sets endPt
	{
		endPt.x = x;
		endPt.y = y;
	}
	point getEndPt() //returs endPt
	{
		return this->endPt;
	}
	PileofCards& operator=(const PileofCards& poc) //overload assignment operator
	{

		if (this != &poc)   //checking if address stored in this pointer and the address of passing object is same
		{
			if (this != nullptr)
			{
				delete[]pile;
				pile = nullptr;
			}
			this->top = poc.top;
			this->size = poc.size;
			this->startPt = poc.startPt;
			this->endPt = poc.endPt;
			this->pile = new PlayingCard[this->size];
			for (int i = 0; i < this->size; i++)
			{
				this->pile[i] = poc.pile[i];
			}
		}
		return *this;
	}
	PlayingCard viewCard(int i) //It is just like peek function but  returns a card at index i rather than top card and no card is removed from pile  
	{                           
		return this->pile[i];   
	}                                                   

	void SimpleDisplay() //only displays top card of a pile,and starting point of display is startPt, if pile is empty a 6x8 dark_green rectangle will be printed.
	{
		if (pile[top].getRank() >= 0 && pile[top].getRank() <= 13)  //condition changed from rank>=1 to rank>=0 because in case of empty pile the card will have rank 0(default)
		{
			ConsoleFunctions temp_obj;   //temporary object made to access functions for the printing of cards
			temp_obj.SetCursorAt(this->startPt.x, this->startPt.y);
			int yCoordinate = this->startPt.y;    //we cannot directly use the value of y as used before because it will update the value of data member
			if (this->pile[top].isFaceUp() == true&&this->top!=-1)
			{
				if (this->pile[top].getColor() == 'b')
					temp_obj.SetColor(0, 15);   //set text colour black and backfround white
				else
					temp_obj.SetColor(4, 15);   //set text colour red and background white

				int count = 0;  //count will be used for printing. It will store the number of indexes used for the printing in first line.

				if (this->pile[top].getRank() == 1)
				{
					temp_obj.writeCharOnConsole('A');
					count++;
				}
				else if (this->pile[top].getRank() == 10)
				{
					cout << this->pile[top].getRank();
					count += 2;
				}
				else if (this->pile[top].getRank() == 11)
				{
					temp_obj.writeCharOnConsole('J');
					count++;
				}
				else if (this->pile[top].getRank() == 12)
				{
					temp_obj.writeCharOnConsole('Q');
					count++;
				}
				else if (this->pile[top].getRank() == 13)
				{
					temp_obj.writeCharOnConsole('K');
					count++;
				}
				else
				{
					cout << this->pile[top].getRank();
					count++;
				}

				//we have to catch the return typr to remove the warning
				int z = _setmode(_fileno(stdout), _O_U16TEXT); // mode for suits set, now use wcout.


				if (this->pile[top].getSuit() == 0)
				{
					wcout << L'\u2666';    //unicode for DIAMOND
				}
				else if (this->pile[top].getSuit() == 1)
				{
					wcout << L'\u2665';    //unicode for HEART
				}
				else if (this->pile[top].getSuit() == 2)
				{
					wcout << L'\u2660';     //unicode for SPADE
				}
				else if (this->pile[top].getSuit() == 3)
				{
					wcout << L'\u2663';     //unicode for CLUB
				}

				count++;   //symbol is printed

				int temp_count = count;

				int k = _setmode(_fileno(stdout), _O_TEXT);    // resetting the mode to cout
				for (int j = 0; j < 8; j++)
				{
					if (j == 7)
					{
						for (int i = 0; i < (6 - temp_count); i++)
						{
							temp_obj.writeCharOnConsole(' ');                //check if using cout is correct or we have to use the given function
						}
					}
					else
					{
						for (int i = count; i < 6; i++)
						{
							temp_obj.writeCharOnConsole(' ');
						}
						count = 0;
						temp_obj.SetCursorAt(this->startPt.x,++yCoordinate );
					}

				}


				if (this->pile[top].getRank() == 1)
				{
					temp_obj.writeCharOnConsole('A');
				}
				else if (this->pile[top].getRank() == 10)
				{
					cout << this->pile[top].getRank();
				}
				else if (this->pile[top].getRank() == 11)
				{
					temp_obj.writeCharOnConsole('J');
				}
				else if (this->pile[top].getRank() == 12)
				{
					temp_obj.writeCharOnConsole('Q');
				}
				else if (this->pile[top].getRank() == 13)
				{
					temp_obj.writeCharOnConsole('K');
				}
				else
				{
					cout << this->pile[top].getRank();
				}


				int l = _setmode(_fileno(stdout), _O_U16TEXT); // mode for suits set, now use wcout.

				if (this->pile[top].getSuit() == 0)
				{
					wcout << L'\u2666';    //unicode for DIAMOND
				}
				else if (this->pile[top].getSuit() == 1)
				{
					wcout << L'\u2665';    //unicode for HEART
				}
				else if (this->pile[top].getSuit() == 2)
				{
					wcout << L'\u2660';     //unicode for SPADE
				}
				else if (this->pile[top].getSuit() == 3)
				{
					wcout << L'\u2663';     //unicode for CLUB
				}


				int m = _setmode(_fileno(stdout), _O_TEXT);   //resetting mode to cout


				temp_obj.SetColor(15, 0); //set text colour white and background colour black 
			}
			
			
			else if(this->pile[top].isFaceUp()==false&&top!=-1)
			{
			int yCoordinate = startPt.y;
				temp_obj.SetColor(4, 4);//setting text colour and background colour both red so that even the text is written it is not displayed
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						temp_obj.writeCharOnConsole(' ');
					}
					temp_obj.SetCursorAt(startPt.x, ++yCoordinate);
				}
				temp_obj.SetColor(15, 0); //set text colour white and background colour black 
			}

			else  //empty pile  top==-1
			{
			int yCoordinate = startPt.y;
			temp_obj.SetColor(2, 2);//setting text colour and background colour both dark green so that even the text is written it is not displayed
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					temp_obj.writeCharOnConsole(' ');
				}
				temp_obj.SetCursorAt(startPt.x, ++yCoordinate);
			}
			temp_obj.SetColor(15, 0); //set text colour white and background colour black 
			}
			}

	}
	                   
	void CascadingDisplay() //gives cascading display of a pile of cards as in Figure 3, and starting point of display is startPt, if pile is empty, a 6x8 dark_green rectangle will be printed.
	{
		ConsoleFunctions temp_obj;
		if(this->top==-1)
		{
			int yCoordinate = startPt.y;  //making a temp variable so it doesn't change the value of data member
			temp_obj.SetColor(2, 2);//setting text colour and background colour both dark green so that even the text is written it is not displayed
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					temp_obj.writeCharOnConsole(' ');
				}
				temp_obj.SetCursorAt(startPt.x, ++yCoordinate);
			}
			temp_obj.SetColor(15, 0); //set text colour white and background colour black 
		}
		else
		{
			int temp_top=0;   //making a temp variable so it doesn't change the value of data member
			                  //temp_top is set to 0 so that the latest added card appears at the top
			int yCoordinate = startPt.y;
			while (temp_top <=this->top)
			{
				pile[temp_top].display(startPt.x, yCoordinate);
				yCoordinate += 2;
				temp_top++;
			}
		}
	}
	
	PlayingCard* getPile()
	{
		return pile;
	}
};



class Deck
{
private:
	PlayingCard* deck[52];
	int size;
public:
	Deck()
	{
		this->size = 52;   //size of a complete deck is always 52
		int j = 0;
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::DIAMOND);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::HEART);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::SPADE);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::CLUB);
			j++;
		}
	}

	int getSize()
	{
		return size;
	}
	bool IsEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	PlayingCard Remove(int i)
	{

		if (IsEmpty() == false)
		{
			if (deck[i] != nullptr)
			{
				PlayingCard temp(*(deck[i]));  //make a copy of the object to be removed before deleting it so that you can return the object
				delete deck[i];
				deck[i] = nullptr;
				int j;
				for (j = i; j < size - 1; j++)
				{
					deck[j] = deck[j + 1];
				}
				deck[j] = nullptr;
				size--;
				return temp;
			}

		}
			PlayingCard temp;   //returned a temporary object(with default values) because if nothing is returned it will throw an exception handling error as the return type is an object of Playing Cards
			return temp;
	}
	~Deck()
	{
		////there is no need for any destructor in case of solitaire game. This is being made just in case only an object of deck is made in main function and no other functions are called for further game display
		////all objects of deck are already being deleted in remove() function of deck class
		//for (int i = 0; i < 52; i++)
		//{
		//	if (deck[i] != nullptr)
		//	{
		//		delete deck[i];
		//		deck[i] = nullptr;
		//	}
		//}
		
	}

};



class Solitaire
{
private:
	Deck deckofCards;
	PileofCards stock;
	PileofCards waste;
	PileofCards home[4];
	PileofCards playingPile[7];
	ConsoleFunctions cf;
public:
	Solitaire() :stock(52), waste(52), home{ PileofCards(13),PileofCards(13),PileofCards(13),PileofCards(13) }, playingPile{ PileofCards(14),PileofCards(15),PileofCards(16),PileofCards(17),PileofCards(18),PileofCards(19),PileofCards(20) }
	{
		//hard codeing the values.A gap of 5 indexes is made between one pile and another
		stock.setStartPt(1, 1);
		stock.setEndPt(6, 8);
		waste.setStartPt(11, 1);
		waste.setEndPt(16, 8);
		int xCoordinateHome = 31;
		for (int i = 0; i < 4; i++)
		{
			home[i].setStartPt(xCoordinateHome, 1);
			xCoordinateHome += 5;   //adding for setting up end point
			home[i].setEndPt(xCoordinateHome, 8);
			xCoordinateHome += 5;   //adding for the next pile
		}
		int xCoordinatePlayingPile = 1;
		for (int i = 0; i < 7; i++)
		{
			playingPile[i].setStartPt(xCoordinatePlayingPile, 15);
			xCoordinatePlayingPile += 5;   //adding for setting up end point
			playingPile[i].setEndPt(xCoordinatePlayingPile,22);
			xCoordinatePlayingPile += 5;    //adding for the next pile
		}
		

	}
	void Shuffle()
	{
		int i;
		while (!deckofCards.IsEmpty())
		{
			i = rand() % deckofCards.getSize();
			PlayingCard c = deckofCards.Remove(i);
			c.setFaceUp(false);
			stock.Add(c);
		}
	}

	void dealToPlayingPiles()
	{
		for (int i = 0; i < 7; i++)
		{
			point tempEndPt = playingPile[i].getEndPt();
			for (int j = 0; j <= i; j++)
			{
				PlayingCard c= stock.Remove();
				if (j == i)
				{
					c.setFaceUp(true);
					c.setTop(true);
				}
				else
				{
					c.setFaceUp(false);
					c.setTop(false);
				}
				playingPile[i].Add(c);
				if (j == 0)
				{
					playingPile[i].setEndPt(tempEndPt.x, tempEndPt.y);   //for the first card end points will be the same
			    }
				else
				{
					tempEndPt.y += 2;    //in all other cases onlyy coordinate will increase by 2
					playingPile[i].setEndPt(tempEndPt.x, tempEndPt.y);
				}
				
				
			}
		}
	}

	void DisplayGame()
	{
		stock.SimpleDisplay();
		waste.SimpleDisplay();
		for (int i = 0; i < 4; i++)
		{
			home[i].SimpleDisplay();
		}
		for (int i = 0; i < 7; i++)
		{
			playingPile[i].CascadingDisplay();
		}
	}
	~Solitaire()  //no memory is being assigned in the constructor
	{}
};

int main()
{
	
	Solitaire S;
	S.Shuffle();
	S.dealToPlayingPiles();
	S.DisplayGame();

	return 0;
}