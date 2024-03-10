#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100 // Define a constant for the maximum number of movies that can be stored

// Structure to hold movie information
struct Movie {
    int movieId;
    char movieName[50];
    char releaseDate[20];
    float rating;
};

// Global array to store movie records
struct Movie movies[MAX_MOVIES]; // Declare an array to hold movie records
int count = 0; // Initialize a variable to keep track of the number of movies stored

// Function prototypes
void insert();
void display();
void edit();
void delete();
void search();
int checkMovieId(int id);

int main() {
    int choice;
    
    do {
        // Display menu options
        printf("\nMovie Management System\n");
        printf("1. Add New Movie Record\n");
        printf("2. Display All Movie Records\n");
        printf("3. Edit Movie Record by movie Id\n");
        printf("4. Delete Movie from a list by\n");
        printf("5. Search Movie by name or release date\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice

        switch (choice) {
            case 1:
                insert(); // Call function to add a new movie record
                break;
            case 2:
                display(); // Call function to display all movie records
                break;
            case 3:
                edit(); // Call function to edit a movie record
                break;
            case 4:
                delete(); // Call function to delete a movie record
                break;
            case 5:
                search(); // Call function to search for a movie
                break;
            case 6:
                printf("Exiting...\n"); // Display exit message
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n"); // Display message for invalid choice
        }
    } while (choice != 6); // Continue until user chooses to exit

    return 0;
}

// Function to insert a new movie record
void insert() {
    if (count < MAX_MOVIES) { // Check if maximum limit of movies has been reached
        struct Movie newMovie; // Declare a new movie structure
        printf("Enter Movie ID: ");
        scanf("%d", &newMovie.movieId); // Read movie ID

        // Check if the entered movie ID already exists
        if (checkMovieId(newMovie.movieId)) {
            printf("Movie with the same ID already exists.\n");
            return;
        }

        printf("Enter Movie Name: ");
        scanf("%s", newMovie.movieName); // Read movie name
        printf("Enter Release Date: ");
        scanf("%s", newMovie.releaseDate); // Read release date
        printf("Enter Rating: ");
        scanf("%f", &newMovie.rating); // Read movie rating

        movies[count++] = newMovie; // Add the new movie to the array of movies
        printf("Movie record added successfully.\n");
    } else {
        printf("Maximum limit reached. Cannot add more movies.\n");
    }
}

// Function to display all movie records
void display() {
    if (count == 0) { // Check if there are no movies stored
        printf("No movies to display.\n");
        return;
    }
    // Display table header
    printf("Movie ID\tMovie Name\tRelease Date\tRating\n");
    for (int i = 0; i < count; i++) { // Loop through all stored movies
        // Display movie information
        printf("%d\t\t%s\t\t%s\t\t%.2f\n", movies[i].movieId, movies[i].movieName, movies[i].releaseDate, movies[i].rating);
    }
}

// Function to edit a movie record
void edit() {
    int id, found = 0;
    printf("Enter Movie ID to edit: ");
    scanf("%d", &id); // Read movie ID to be edited

    for (int i = 0; i < count; i++) { // Loop through all stored movies
        if (movies[i].movieId == id) { // Check if the entered movie ID matches with any stored movie
            // Prompt user to enter new information for the movie
            printf("Enter new Movie Name: ");
            scanf("%s", movies[i].movieName);
            printf("Enter new Release Date: ");
            scanf("%s", movies[i].releaseDate);
            printf("Enter new Rating: ");
            scanf("%f", &movies[i].rating);
            printf("Movie record updated successfully.\n");
            found = 1; // Set found flag to true
            break; // Exit the loop
        }
    }

    if (!found) { // If the movie ID is not found in the records
        printf("Movie with given ID not found.\n");
    }
}

// Function to delete a movie record
void delete() {
    int id, found = 0;
    printf("Enter Movie ID to delete: ");
    scanf("%d", &id); // Read movie ID to be deleted

    for (int i = 0; i < count; i++) { // Loop through all stored movies
        if (movies[i].movieId == id) { // Check if the entered movie ID matches with any stored movie
            // Shift elements to remove the movie record
            for (int j = i; j < count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            count--; // Decrement the count of movies
            printf("Movie record deleted successfully.\n");
            found = 1; // Set found flag to true
            break; // Exit the loop
        }
    }

    if (!found) { // If the movie ID is not found in the records
        printf("Movie with given ID not found.\n");
    }
}

// Function to search for a movie by name or release date
void search() {
    char query[50];
    int found = 0;
    printf("Enter Movie Name or Release Date to search: ");
    scanf("%s", query); // Read the search query

    printf("Movie ID\tMovie Name\tRelease Date\tRating\n");
    for (int i = 0; i < count; i++) { // Loop through all stored movies
        // Check if the search query matches with any movie name or release date
        if (strstr(movies[i].movieName, query) || strstr(movies[i].releaseDate, query)) {
            // Display information of the matching movie
            printf("%d\t\t%s\t\t%s\t\t%.2f\n", movies[i].movieId, movies[i].movieName, movies[i].releaseDate, movies[i].rating);
            found = 1; // Set found flag to true
        }
    }

    if (!found) { // If no matching movie is found
        printf("No movie found with the given query.\n");
    }
}

// Function to check if a movie ID already exists
int checkMovieId(int id) {
    for (int i = 0; i < count; i++) { // Loop through all stored movies
        if (movies[i].movieId == id) { // Check if the entered movie ID matches with any stored movie ID
            return 1; // Return true if movie ID exists
        }
    }
    return 0; // Return false if movie ID does not exist
}
