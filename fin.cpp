//main driver file
//add header comments here.
#include "person.h"
const int CAPACITY = 20;

//function protoypes

//main and then functions.
int main()
{
	PersonType list[CAPACITY];
	int 	   count  = 0;
	char	   fileName[] = "persons.txt";

	populatePersons(list, count, fileName);
	printPersons(list, count);

	cout << "Welcome to the Citizen Database!\n" << endl;
	//call your functions here to do what is required.
	if ( addPerson(list, count) ) {
		cout << endl;
		printPersons(list, count);
	}
	else {
		cout << endl << "Invalid entry!\n";
	}
	cout << endl << "Thank you for accessing the Citizen Database.\n";
	return 0;
}


