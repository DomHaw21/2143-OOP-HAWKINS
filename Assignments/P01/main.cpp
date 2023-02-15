/*****************************************************************************
*                    
*  Author:           Dominique Hawkins
*  Email:            domhaw1242@gmail.com
*  Label:            P01
*  Title:            Linked List Vector Class
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*     This program is used to create a Linked List based vector class and 
*			demonstrate my ability to create a beginner level class. This is done
*			by creating a linked list class that allow for pushing data (ints) to 
* 		to both ends of the list, at any position and also sort the list and 
* 		place the approipriate position, and push another vector onto another. 
* 		It will also allows you to pop items off the front and rear and at a 
*			position and find the position of an item. This List will also allow you 
* 		create the list using a array, items from an input file, and another vector.
* 
*  Usage:
*     N/A
* 
*  Files:            
*			main.cpp				:driver program
*			input.dat				:file to get data to make the list
*			output.dat			:displays list
*
*****************************************************************************/
#include <iostream>				
#include <fstream>
#include <string>

using namespace std; 
/**
 * Node
 * Description:
 *    makes a struct to create a node to store data and hold pointers 
 * 		for next and previous node.
 * 
 * Member variables:
 * 				int -	data
 * 				Node* -	next
 * 				Node* -	prev
 * 
 * Public Method:
 * 				
 * 				Node(int d)
 *  
 * Usage: 
 * 
 *      Node(d)	// creates an instance of a node
 *      
 */
struct Node {
	int data;			  	// data that will be stored in the list 
	Node* next;				// node pointing to the new node
	Node* Prev;				// node pointing to previous node 
	Node(int d)
  {			// constructor to create new node
		data = d;
		next = NULL;
		Prev = NULL;
	}
};
/**
 * Vector
 * 
 * Description:
 *    This class implements a linked list based class that lets you
 * 		add items to the rear and front of the list, at 
 * 		any position, in order, and push another vector class
 * 		to the front or rear of the current list. It also 
 * 		allows you to pop items off the rear or front and at any position 
 * 		and also find any item in the list. It will allow you to 
 * 		create a list using an array, items from a file, and another vector.
 * 
 * Public Methods:
 *      					Vector()
 * 								Vector(int* a, int size)
 * 								Vector(string filename)
 * 								Vector(const Vector &V)
 * 		bool				isSorted()
 * 		void				Sort()
 * 		void				print()
 * 		int size		size()
 * 		void 				pushFront(int d)
 * 		void				Pushfront(Vector V)
 * 		void 				pushRear(int d)
 * 		void 				Pushrear(Vector V)
 * 		void 				pushAt(int loc,int d)
 * 		void				Pushinorder(int d)
 * 		int					popFront()
 * 		int 				popRear()
 * 		int 				popAt(int loc)
 * 		int 				Find(int d)
 * 		friend ofstream&		<<operator(ofstream&, const Vector&)
 * 				
 * Private Methods:
 *     	Node*					head
 *      Node*         tail
 * 
 * Usage: 
 *
 * 		V1.Pushinorder(2)		//sorts list then puts 2 in order
 * 		V1.Popfront			  	//pops off the front of the list
 * 		V1.Poprear			  	//pops the rear of the list 
 * 		V1.Popat(3)				  //pops the item at position 3 of the list 
 * 		V1.Find(4)				  //locates the position of value 4 in the list 
 * 		cout << V1				  //print list
 */
class Vector {
private:
	Node* head;
	Node* tail;
public: 
	Vector() 
  {					//default constructor 
		head = NULL;			//setting head and tail to NULL
		tail = NULL;
	}
	Vector(int* a, int size) 	//constructor to accept an array and its size to create a new vector
	{
		head = NULL;			
		tail = NULL;	
		for (int i = 0; i < size; i++) 
    { 	// for loop to push the elements of the array to the rear of the list
			Pushrear(a[i]);
		}
	}
	Vector(string filename)
  {	// Constructor that accepts data from a file
		head = NULL;
		tail = NULL;
		int data = 0;			// variable to accept data from file
		ifstream infile;
		infile.open(filename);	//opening file
		
		while (!infile.eof()) 
    {	//while loop that repeats until the file is empty and pushes the data to end of list
			infile >> data;		
			Pushrear(data);		
		}
		infile.close();
	}
	Vector(const Vector &V) {	//Constructor to create another vector using a vector 
		head = tail = NULL;
		Node* traverse = V.head;
		while (traverse) 
    {	//while loop that traverses list and pushes data from V2 to V1
			Pushrear(traverse->data);
			traverse = traverse->next;
		}
	}
 /**
     * Public : isSorted
     * 
     * Description:
     *      checks to see if the list is sorted
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      Bool  - a true or false if the list is sorted or not
     */
	bool isSorted() {	
		int cnt = 0;
		
		Node* traverse = head;
		while (traverse->next != NULL) { 	//loop to traverse the list until end 
			if (traverse->data >= traverse->next->data) {	//Checks if current list element is greater than the next one 
				cnt++;	// increments count

			}


			traverse = traverse->next;
		}
		return cnt == 0;	//returns true if the count is 0 
	}
   /**
     * Public: Sort
     * 
     * Description:
     *      Sorts the Vector list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      Vector 	-	returns the sorted list
     */
	void Sort() {
		bool notSorted = true;	//assumes the list is notsorted 
		int i = 0;
		while (notSorted)
    {			//loop that runs while the list is still sorted
			notSorted = false;		//if false, leave loop
			Node* traverse = head;
			while (traverse->next != NULL) 
      {//loop that runs while not at the end of the loop
				if (traverse->data > traverse->next->data) 
        {//checks if current is greater than next data
					int temp = traverse->data;	//makes a swap
					traverse->data = traverse->next->data;
					traverse->next->data = temp;
					temp = 0;
					notSorted = true;	//sets notsorted to true
					
				}
				traverse = traverse->next;
				
				
			}
		}
	}
   /**
     * Public: print
     * 
     * Description:
     *      prints the vector list
     * 
     * Params:
     *      none
	   * 
     * Returns:
     *      nothing
     */
	void print() {	
		Node* traverse = head;
		while (traverse) 
    {				// traverse list and print data as it goes
			cout << traverse->data << " ";
			traverse = traverse->next;
		}
	}
   /**
     * Public: size
     * 
     * Description:
     *      checks size of list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      int (value size of list)
     */
	int size() {
		int cnt = 0;
		Node* traverse = head;
		while (traverse != NULL) 
    {
			cnt++;						   // increments count as it moves
			traverse = traverse->next;
		}
		return cnt;						//returns size of list
	}
	 /**
     * Public: pushfront
     * 
     * Description:
     *      Adds items to the front of list 
     * 
     * Params:
     *    
     *      int: data to add
     * 
     * Returns:
     *      nothing
     */
	void pushFront(int d){
		Node* temp = new Node(d); 	//creates new node
		if (head == NULL) 
    {	//checks if list is empty 
			head = temp;
			tail = temp;
		}
		else 
    {
			temp->next = head;		//adds node to the front of list and moves pointer
			head->Prev = temp;
			head = temp;
		}
	}
	 /**
     * Public: Pushfront
     * 
     * Description:
     *      adds another vector class to the front of the current list
     * 
     * Params:
     *      VectorV - the vector to be pushed
     * 
     * Returns:
     *      nothing
     */
	void Pushfront(Vector V){ 	
		V.tail->next = head;		// moves the tail of the new vector to the head of the current vector 
		head->Prev = V.tail;	  // makes the previous head point to the tail of the new vector 
		head = V.head;			 	  // makes the new head pointer
	}
	 /**
     * Public: pushrear
     * 
     * Description:
     *      Adds items to list at the back
     * 
     * Params:
     *     
     *      int data: the data to be added 
     * 
     * Returns:
     *      nothing
     */
	void pushRear(int d){
		Node* temp = new Node(d);	//creates new node
		if (head == NULL)
    {	// checks if list is empty 
			head = temp;
			tail = temp;
		}
		else 
    {					
			temp->Prev = tail; // moves new node to the back of list and move pointers 
			tail->next = temp;
			tail = temp;
		}
	}
	 /**
     * Public: Pushrear
     * 
     * Description:
     *      Pushes another vector to the back of the current
     * 
     * Params:
     *      VectorV : the vector being pushed 
     * 
     * Returns:
     *      nothing
     */
	void Pushrear(Vector V)
  {
		tail->next = V.head;		//assigns tail of current vector to head of new 
		V.head->Prev = tail;		//assigns head of new vector to tail of current
		tail = V.tail;			  	//reassgns tail 
	}
	 /**
     * Public: pushAt
     * 
     * Description:
     *      add items to the list at a certain location
     * 
     * Params:
     *      int	d: data to be added 
     * 		  int	loc: location to add data
     * Returns:
     *      nothin
     */
	void pushAt(int loc, int d){
		Node* temp = new Node(d);	//creates new node
		if (loc == 1) 
    {	//checks if the location is the first position and moves node to the front 
			pushFront(d);			
		}
		else if (loc >= size()) 
    {  //checks if the location is the last in the list and moves to the rear
			pushRear(d);
		}
		else 
    {	// if spot is somewhere in the middle 
			Node* traverse = head;
			for (int a = 0; a < loc - 1; a++) {	//traverses to get to the correct position 
				traverse = traverse->next;
			}
			temp->next = traverse;	//adds a node to middle of list 
			temp->Prev = traverse->Prev;
			traverse->Prev->next = temp;
			traverse->Prev = temp;
		}
	}
	 /**
     * Public: Pushinorder
     * 
     * Description:
     *      sorts list then adds items in correct position 
     * 
     * Params:
     *      int d: data to be added 
     * 
     * Returns:
     *      nothing
     */
	void Pushinorder(int d){
		if (!isSorted()) 
    {// checks if list is sorted; if not, sort 
			Sort();
		}
		if (head == NULL) 
    {//checks if list is empty 
			cout << "list is empty";
		}
		else 
    {					
			Node* traverse = head;
			if (d < head->data) 
      {// checks if nodes data is less than head, then moves to front 
				pushFront(d);
			}
			else if (d > tail->data)
      {
				pushRear(d);//checks if nodes data is greater than tail, then moves to rear 
			}
			else 
      {
				int cnt = 0;
				while (traverse->data <= d && traverse != NULL) 
        {	//finds where the approipriate position of the node data should be 
					cnt++;
					traverse = traverse->next;
				}
				pushAt(cnt, d);// pushes data at correct location
			}
		}
	}
 /**
     * Public: popFront
     * 
     * Description:
     *      removes item from front of list and gives back the item
     * 
     * Params:
     *      nothin
     * 
     * Returns:
     *      int	(item that was popped off)
     */
	int popFront(){			
		int num = head->data; // gets data from node 
		Node* temp = head;
		if (head == NULL) 
    {	//checks if list is empty
			cout << "list is empty";
			return -1;
		}
		else 
    {							
			head = head->next;	//moves the head pointer 
			delete temp;				//deletes old head
			head->Prev = NULL;	//makess head Prev NULL
			return num;					//returns data that was stored in node 
		}
	}
	 /**
     * Public: popRear
     * 
     * Description:
     *      Removes item off back of list and gives back item
     * 
     * Params:
     *      nothin
	   * 
     * Returns:
     *      int (item that was popped off)
     */
	int popRear(){
		int num = tail->data;//gets data from node
		Node* temp = tail;			
		if (head == NULL)
    {	//checks if list is empty 
			cout << "list is empty";
			return -1;
		}
		else 
    {
			tail = tail->Prev;			//reassigns new tail
			delete temp;				//delete old node 
			tail->next = NULL;			//reassigns tail next to null
			return num;					//returns the data that was removed from list 
		}
	}
	 /**
     * Public: popAt
     * 
     * Description:
     *      removes item at certain location, then gives back item
     * 
     * Params:
     *      int loc - the location of the item to remove
     * 
     * Returns:
     *      int (item that was removed)
     */
	int popAt(int loc){
		int num;
		if (head == NULL) 
    {	//checks if list is empty 
			cout << "list is empty";
			return -1;
		}
		else if (loc == 1)
    {// checks if location is at front, then pops front 
			return popFront();
		}
		else if (loc >= size()) 
    {// checks if location is the rear, then pops rear 
			return popRear();
		}
		else {
			Node* traverse = head;
			for (int i = 0; i < loc-1; i++)
      {//goes to location of node to be deleted 
				traverse = traverse->next;
			}
			num = traverse->data;	// gets data from node 
			traverse->Prev->next = traverse->next;	//reassigns nodes
			traverse->next->Prev = traverse->Prev;
			delete traverse;	// deletes removed node 
			return num;				// returns data
		}
	}
	 /**
     * Public: Find 
     * 
     * Description:
     *  	locates position of the item you want and gives that position 	
     * 
     * Params:
     *      int d (the item you want)
     * 
     * Returns:
     *      int (position of item your looking for in list)
     */
	int Find(int d){
		Node* traverse = head;
		int cnt = 0;
		if (d == head->data) 
    {			// checks if data is at the front of list 
			return 1;
		}
		else if (d == tail->data) 
    {// checks if data is at the back of list 
			return size();
		}
		else 
    {
			while (traverse != NULL && traverse->data != d) 
      {  	// finds location of data in the list 
				cnt++;
				traverse = traverse->next;
			}
			if (traverse == NULL) 
      {	// if data is not in the list 
				cout << "Not found";
				return -1;
			}
			else 
      {
				
				return cnt+1;	// returns postion of data 
			}
		}
	}
	friend ofstream& operator<<(ofstream&, const Vector&); // lets the class to use this function
};
 /**
     * Public: operator<<
     * 
     * Description:
     *      overloads << operator to display the entire list at once 
     * 
     * Params:
     *      ofstream&	out: << outfile variable that displays data 
	   * 		  const Vector&	V1: vector being displayed 
     * 
     * Returns:
     *      ofstream&	(allows for displaying of data)
     */
ofstream& operator<<(ofstream& outfile, const Vector& V) {
	Node* traverse = V.head;
	while (traverse != NULL)
  {	//goes through list and dispalays
		outfile << traverse->data << " ";
		traverse = traverse->next;
	}
	return outfile;
}
//main driver
int main(){

	int a[] = { 2,6,8 };								//creates array 
	ofstream outfile;										//creates outfile

	outfile.open("output.dat");					//opens output file

	Vector V1("input.dat"); 

	outfile << "Dominique Hawkins 2143 OOP" << endl;
	outfile << "P1" << endl;
	outfile << endl;
  outfile << endl;

	outfile << "V1";
	outfile << V1;
	outfile << endl;

	V1.pushFront(12);										//pushes 12 to front
	V1.PushFront(6);
	
	outfile << "V1 after pushFront: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.pushRear(14);										//pushes 14 to rear
	V1.PushRear(3);
	
	outfile << "V1 after pushRear: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	V1.pushAt(2, 17);										//pushes 17 to pos 2
	outfile << "V1 after pushing 17 to position 2: "; 
	outfile << V1;
	outfile << endl;
	outfile << endl;

	Vector V2(a,5);											//creates another vector with size 5
	outfile << "V2: ";
	outfile << V2;
	outfile << endl;
	outfile << endl;

	V1.Pushfront(V2);										

	outfile << "V1 after pushing V2: ";
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int b[] = {0,16,5,7};								//new array

	Vector V3(b, 4);										// creates another vector using array sized 4
	outfile << "V3: "; 			
	outfile << V3;
	outfile << endl;
	outfile << endl;  
	Vector V4(V3);											//create fourth vector using third vector 
	outfile << "V4 created using V3: "; 				
	outfile << V4;
	outfile << endl;

	V1.Pushrear(V4);							 

	outfile << "V1 after Pushing V4: "; //displays first vector
	outfile << V1;
	outfile << endl;

	V1.Pushinorder(5);

	outfile << "V1 after sorting: "; //displays sorted vector
	outfile << V1;
	outfile << endl;
	outfile << endl;

	int num = 21;

	num =V1.popFront();
	
	outfile << "V1 after popping off front :"; 			// displays vector after popping front 
	outfile << V1;
	outfile << endl;
	outfile << "Popped: " << num;							// displays data that was popped 
	outfile << endl;

	num = V1.popRear();									

	outfile << "V1 afteer popping rear :";
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;
	outfile << endl;
	outfile << endl;

	num=V1.popAt(3);									 

	outfile << "V1 after popping data at pos 3: ";	
	outfile << V1;
	outfile << endl;
	outfile << "popped: " << num;
	outfile << endl;
	outfile << endl;

	num = V1.Find(5);										//finds num 5 in list

	outfile << "5 was at pos: " << num; 
	outfile << endl;

	outfile.close();
}
