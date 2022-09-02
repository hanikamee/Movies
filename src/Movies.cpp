// This program will ask the user to enter the number of users surveyed,
// dynamically create an array to contain number of movies watched for each
// student, ask the user how many movies they watched, and calculate the average
// of the array. Pointers were used in many sections of the program.

#include <iostream>
#include <algorithm> // Sorting the array
#include <iomanip>

// Getting the data, movies and number of students, from the user
void getData(int *array, int number){
    for (int i = 0; i < number; i++){
        std:: cout << "student "<< (i+1) << ": ";
        std:: cin >> *(array +i);
    }
}

// Sorting the array in an ascending order
void sortData(int *array, int size){
    std::sort(array, array + size);

}

// Displaying the number of movies watched
void displayList(int *array, int size){

    std::cout<<"Number of movies watched:"<< std::endl;
    std::cout<<"-------------------------"<<std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i) << std::endl;
    }
    std::cout<<"-------------------------"<<std::endl;

}

// Getting the average by adding up the number of movies watched and dividing it
// by the number of students
double average(int *array, int number){
    double total = 0;
    for (int i = 0; i < number; i++){
        total += *(array+i);

    }
    return total/number;

}
int main()
{
    // Declaraing a varaible, users, and a pointer, movies.
    int users, *movies;
    std::cout << "How many students were surveyed? " << std::endl;
    std::cin >> users;

    // Input validation
    while (users < 0){
        std::cout << "How many students were surveyed? " << std::endl;
        std::cin >> users;
    }

    // Creating an array dynamically
    movies = new int[users];

    // Calling the functions
    getData(movies, users);
    sortData(movies, users);
    displayList(movies, users);
    double avg = average(movies, users);

    // Displaying the average
    std::cout << std::fixed<< std::setprecision(2);
    std::cout << "Average: " << avg <<std::endl;

    delete [] movies; // deleting movies from memory

    return 0;
}
