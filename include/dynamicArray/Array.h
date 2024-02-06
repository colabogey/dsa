
using namespace std;

// A class to represent an integer array
class Array {
private:
	int* ptr;
	int size;

public:
	Array(int*, int);

	// Overloading [] operator to access elements in array style
	int& operator[](int);

	// Utility function to print contents
	void print() const;
};
