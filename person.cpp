//implememtation file for struct PersonType
#include "person.h"

//function to read from file and populate list
void populatePersons(PersonType list[], int& count, const char fileName[])
{
    ifstream        inFile;
    char            name[MAX_CHAR];
    char            citizen[MAX_CHAR];
    int age = 0;

    inFile.open(fileName);
    if(!inFile)
    {
        cerr << "Fail to open " << fileName << " to populate inventory!" << endl;
        exit(1);
    }
    inFile >> name;
    while(!inFile.eof())
    {
        inFile >> citizen;
        inFile >> age;
        strcpy(list[count].name, name);
        strcpy(list[count].citizenship, citizen);
        list[count].age = age;
        count++;

        inFile >> name;
    }
    inFile.close();
}

//function to print list
void printPersons(const PersonType list[], int count)
{
    cout << "List of citizen database!" << endl;
    for(int index = 0; index < count; index++)
    {
        cout << list[index].name << ";" << list[index].citizenship;
        cout << ";" << list[index].age << endl;
    }
}

//add your function here
// Name:    addPerson()
// Desc:    Creates a person from input and adds it to the list
// input:   name (cstring), citizenship (cstring), age (int), pos (int)
// output:  Prompt
// return:  bool (false if invalid input, true if successfully inserted)
bool addPerson(PersonType list[], int &count) {
    PersonType person;
    int pos = 0;

    cout << "Enter name: ";
    cin.getline(person.name, MAX_CHAR);
    cout << "Enter citizenship: ";
    cin.getline(person.citizenship, MAX_CHAR);

    cout << "Enter age: ";
    cin >> person.age;
    cin.ignore(100, '\n');
    if (person.age < 0 || person.age > 100) {
        return false;
    }

    cout << "Enter position: ";
    cin >> pos;
    cin.ignore(100, '\n');
    if (pos < 0 || pos > count) {
        return false;
    }

    if (pos == count) {
        list[count] = person;
    }
    else {
        for (int i = count; i > pos; i--) {
            list[i] = list[i - 1];
        }
        list[pos] = person;
    }
    ++count;
    return true;
}