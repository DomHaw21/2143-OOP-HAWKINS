/*********************************************************************************
 * 
 * Author:      Dominique Hawkins
 * Email:       domhaw1242@gmail.com
 * Label:       A03
 * Title:       Basic Project Organization 
 * Course:      CMPS 2143
 * Semester:    Spring 2023 
 * 
 * Description: 
 *      This program is used to practice the the approipraite format for Commenting 
 *      in any of our programming assignments.
 * 
 * Usage: 
 *      - N/A
 * 
 * Files
 *      main.cpp
 * *******************************************************************************/
#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description: 
 *      This class implements a circular Array Based Queue. This class allows to store 
 *      data in a dynamic array that can store and remove data through the rules of 
 *      Queue by adding data at rear of the list and removing data from the front of the 
 *      list. This list is also circular that means when the all the space of in the list
 *      it will go back to inserting and removing from the front of list ensuring it will
 *      run out of space.
 * 
 * Public Methods:
 *                                      CircularArrayQue()
 *                                      CircularArrayQue(int size)
 *      void                            Push(int item)
 *      int                             Pop()
 *      friend                          ostream &operator<<(ostream &os, const CircularArrayQue &other)   
 *      
 * Private Methods:
 * 
 *      int                             Container
 *      int                             Front
 *      int                             Rear
 *      int                             QueSize
 *      int                             CurrentSize
 *      void                            init(int size=0)
 *      bool                            Full()                            
 *  
 * Usage: 
 *      
 *      CircularArrayQue   C1()         // Creates list with the size of 10
 * 
 *                                      // or
 * 
 *      CirculatArrayQue   C1(size)     // allows the user to create the list of whatever
 *                                      // they want
 *      Push(9)                         // adds the number 9 to the list
 *      Pop()                           // removes the front item
 *      cout << C1                      // allows you to display the entire list in one command
 *           
 */
class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
     /**
     * Private: Full
     * 
     * Description: 
     *      Checks to see if array is full
     * 
     * Params: 
     *      N/A
     * 
     * Returns:
     *      Returns true of false 
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

    public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    /**
    * Public: Push 
    * 
    * Description:
    *      Adds an item to the back of the queue
    * 
    * Param
    * 
    *      int     : the data that will be added to the program
    * 
    * Returns: 
    * 
    *      N/A
    */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    /**
    * Public: Pop
    * 
    * Description:
    *      Removes items from the front of the list
    * 
    * Param
    *      N/A
    * 
    * Returns:
    *      returns the piece of data that was popped off the list 
    */
    int Pop() 
    {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
    };
    /**
     * Public: &operator<<
     * 
     * Description:
     *      This Function overloads the cout function allowing you to use cout to display an
     *      entire array without having to cout each individual item in the array 
     * 
     * Params:
     *      ostream                 : access to the cout function     
     *      CircularArrayQue        : circular array class 
     * 
     * Returns:
     *      ostream &os             : allows for the dispaly of the class array 
    */

    ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
    }

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);             // adds one to the array
    C1.Push(2);             // adds two to the array
    C1.Push(3);             // adds three to the array
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;     // prints out and displays list

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
