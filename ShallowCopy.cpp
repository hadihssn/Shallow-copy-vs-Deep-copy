// C++ program for the above approach
#include <iostream>
using namespace std;

// Box Class
class box
{
private:
	int length;
	int breadth;
	int height;
	int *pointer;

public:
	box()
	{
		cout << "Default constructor called\n";
		pointer = new int;
	}

	// This is the copy constructor we have to write ourselves in case of wanting separate memory addresses for heap memory of an object. If we comment this, compiler will use its own copy constructor and when copying the heap memory it will just point you newly created object's heap variables to the heap variables of the object being copied.
	box(box &obj)
	{
		this->length = obj.length;
		this->breadth = obj.breadth;
		this->height = obj.height;
		this->pointer = new int;
		*(this->pointer) = *(obj.pointer);
	}

	// Function that sets the dimensions
	void set_dimensions(int length1, int breadth1, int height1, int pointerValue)
	{
		length = length1;
		breadth = breadth1;
		height = height1;
		*pointer = pointerValue;
	}

	// Functions to set values
	void set_length(int length)
	{
		this->length = length;
	}

	void set_pointerValue(int pointerValue)
	{
		*(this->pointer) = pointerValue;
	}

	// Function to display the dimensions of the Box object
	void show_data()
	{
		cout << " Length = " << length << "\n Breadth = " << breadth << "\n Height = " << height << "\n Pointer = " << *pointer << endl;
	} 
};

// Driver Code
int main()
{
	// Object of class Box
	box B1, B3;

	// Set dimensions of Box B1
	B1.set_dimensions(14, 12, 16, 4);
	cout << "\nB1's data: \n";
	B1.show_data();

	// When copying the data of object at the time of initialization then copy is made through COPY CONSTRUCTOR
	box B2 = B1;
	B2.set_length(100);
	cout << "\nB2's data: \n";
	B2.show_data();

	// When copying the data of object after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
	B3 = B2;
	cout << "\nB3's data: \n";
	B3.show_data();

	// If we will write our own copy constructor, then the heap memory will be separate blocks in memory but if we let the compiler use its own copy constructor the heap memory will not be created separately for separate objects.
	box B4 = B1;
	B4.set_length(2);
	B4.set_pointerValue(30); 
	cout << "\nB4's data: \n";
	B4.show_data();
	B1.show_data(); // this shows if copy constructor is our own, changing B4 doesn't change B1 but if we comment our own copy constructor B1 also changes its pointer value since memory address would be same.

	return 0;
}
