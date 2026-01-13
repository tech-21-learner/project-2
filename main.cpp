// Name: Siddh Patel
// ID: 200543710
// Date: 24/07/2025
// Purpose: This cpp file contains all the three question given in assignment-2 
//          In Que-1, we are checking if user given number is multiple of 7,11,13; Sum of each digit is odd or even
//          and lastly if number is prime or not. 
//          In Que-2, we are generating a user defined array having positive numbers 
//          we sort those numbers in the ascending order by calling function selectionSort 
//          Then we search for index of a number by calling binarySearch function
//          In Que-3, we are generating a user defined array having positive numbers
//          then we search for specific number's index in the array by using function linearSearch

#include <iostream>
#include <cmath> // included the library to do square root 
using namespace std;

// set array size to be constant
const unsigned int size = 100;

// function prototypes
void selectionSort(int arr[], int size);
int binarySearch(int arr[], int low, int high, int target);
int linearSearch(int arr[], int size, int target);

class myInt // declaring the class 
{
    private: 
        int value; // declaring member 

    public:
    // member functions to perform specific tasks
        myInt(int a = 0);    // constructor having one parameter
        void multiple() const; // check if number is divisible of 7
        bool sumOfDigitEven() const;// check if sum of digits is even or odd
        bool primeNum() const;// cehck if number is prime

};// class defination ends

int main()
{
    int que;

    while(true) // infinite loop 
    {
        //statements to get informatation about which question user is interested to try
        cout << "Press 1 to see the output of the code for question 1" << endl;
        cout << "Press 2 to see the output of the code for question 2" << endl;
        cout << "Press 3 to see the output of the code for question 3" << endl;
        cout << "Enter the question number : ";
        cin >> que; // the number

        switch(que)// switch loop is used to iterate specific question number
        {
            case 1:// it's for question-1
            {
            int number;
            cout << "Enter an integer: ";// prompt user to give number
            cin >> number;
            cout << endl;

            myInt num(number);// declaring the instance of the date class and passing it to constructor.

            // call member function of the class myInt inorder to print the result
            num.multiple();

            if(num.sumOfDigitEven())
            {
                cout << "The sum of digits of the integer is an Even number." << endl;
            }
            else
            {
                cout << "The sum of digits of the integer is an Odd number." << endl;
            }

            if(num.primeNum())
            {
                cout << "The integer is a prime number." << endl;
            }
            else 
            {
                cout << "The integer is not a prime number." << endl;
            }
            
            cout << "Thank You!";
            break; // que-1 ends
            }
            
            case 2: // it's for question-2
            {
            int n;
            cout << "Enter the number of elements that you want in the array: ";// get the size of array from the user
            cin >> n;

            int arr[n];
            cout << "Enter the elements: ";// get the positive numbers from the user and save them to array
            for (int i = 0; i < n; i++)
            {
              cin >> arr[i];
            }

            selectionSort(arr, n); // call function to sort the array in ascending order

            cout << "The sorted array is ";// prints the sorted array
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            int target;
            cout << "Enter the element that you are searching for: "; // get number from user to be searched in the array
            cin >> target;

            int index = binarySearch(arr, 0, n-1, target); // call function to search the index of value

            if (index != -1)// value found in array
                cout << "The index of " << target << " is " << index << "." << endl;

            else// value not found 
                cout << target << " not found in the array." << endl;

            cout << "Thank you!";

            break;  // que-2 ends
            }

            case 3: // it's for question-3
            {
            int n;
            cout << "Enter the number of elements that you want in the array: "; // prompt to defined the size of array
            cin >> n;

            int arr[n];
            cout << "Enter the elements: "; // takes the elements from user
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            int target; // value to be search in array
            cout << "Enter the element that you are searching for: ";
            cin >> target;

            int index = linearSearch(arr, n, target); // calls the function and saves the result in the index variable

            if (index != -1) // value found
                cout << "The index of " << target << " is " << index << "." << endl;
            else // value not found
                cout << target << " not found in the array." << endl;

            cout << "Thank you!";

            break; // que-3 ends
            }
        }
        if (que != 1 && que != 2 && que != 3)// if user input other number, then program exit
        {
        cout << "Program Exit!!!";
        break;// exit code
        }

    }

    return 0;
}

// implementing the class myInt and sub-functions
myInt :: myInt(int a) 
{ 
    value = a;
}

void myInt :: multiple() const
{ 
    int check[3] = {7,11,13};// creates array for three intger values
    
    for(int i = 0; i < 3; i++)
    {
        if(value % check[i] == 0)
        cout << "The integer is a multiple of " << check[i] << endl;// print the result according to the if statement
        else 
        cout << "The integer is not a multiple of " << check[i] << endl;
    }
    
}

bool myInt :: sumOfDigitEven() const
{
    int n;
    int sum = 0; // set sum to zero initially

    if(value < 0) // check if number is negative
    {
       n = -value;
    }
    else
    {
        n = value;
    }

    while( n > 0)
    {
        sum += (n % 10);// get the last digit of number and add it to sum
        n /= 10;// remove the last digit
    }
    return (sum % 2 == 0); // check if number is even or not

}

bool myInt :: primeNum() const
{
    if( value < 2)// number less than 2 are not prime numbers
    return false;
    
    for(int i = 2; i <= sqrt(value); i++)
    {
        if(value % i == 0)// number has factor i.e. it's divisible  
        return false; 
    }
    return true;
}

void selectionSort(int arr[], int n) // sub-function having two parameters, array and size 
{
    for (int i = 0; i < n - 1; i++)
     {
        int minIndex = i; // initializing the first index has minimum value
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) // check if first index is a minimum value or not
            {
                minIndex = j; // updating minimum value
            }
        }
       
        int temp = arr[i];    //swaping the values to arrange in ascending order
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
// function used to search an element in a array
int binarySearch(int arr[], int low, int high, int target) // sub-function takes 4 parameter array,value to be searched,fist and last element 
 {
    int difference, mid;

    while (low <= high) 
    {
        int mid = (low + high) / 2; // search for mid value.
        difference = arr[mid] - target; 

        if (difference == 0)
            return mid;     // value is in middle of array
        else if (difference < 0)
            low = mid + 1;  // search in right half of array
        else
            high = mid - 1; // search in left half of array
    }
    return -1; // value not found
}

int linearSearch(int arr[], int size, int target) // sub-function that takes three parameters an array, size, and value to find
 {
    for (int i = 0; i < size; i++) // loop to check each element in an array.
    {
        if (arr[i] == target) 
        return i; // returns index i, when above condition is true
    }
    return -1; // value do not exist in the array 
}      
    
