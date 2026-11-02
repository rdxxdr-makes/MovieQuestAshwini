/* Movie Recommendation Quest
   A simple genre-based movie recommendation program in C. */

#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[20];
    char language[20];
    float rating;
};

void displayMenu(void) {
    printf("\n===== MOVIE RECOMMENDATION QUEST =====\n");
    printf("1. Action\n");
    printf("2. Comedy\n");
    printf("3. Drama\n");
    printf("4. Animation\n");
    printf("5. Science Fiction\n");
    printf("6. Exit\n");
}

void showRecommendations(struct Movie movies[], int count,
                         const char selectedGenre[]) {
    int i, found = 0;

    printf("\n--- Recommended Movies ---\n");

    for (i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, selectedGenre) == 0) {
            printf("\nMovie: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Language: %s\n", movies[i].language);
            printf("Rating: %.1f/10\n", movies[i].rating);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No movies found in this genre.\n");
    }
}

int main(void) {
    struct Movie movies[] = {
        {"Warrior's Path", "Action", "Hindi", 8.1},
        {"Sky Mission", "Action", "English", 7.8},
        {"Laugh Out Loud", "Comedy", "Hindi", 8.0},
        {"Funny Days", "Comedy", "English", 7.5},
        {"The Last Letter", "Drama", "Hindi", 8.4},
        {"Life's Journey", "Drama", "English", 8.2},
        {"Magic Planet", "Animation", "English", 8.6},
        {"Little Heroes", "Animation", "Hindi", 7.9},
        {"Future World", "Science Fiction", "English", 8.7},
        {"Beyond Earth", "Science Fiction", "Hindi", 8.0}
    };

    int count = sizeof(movies) / sizeof(movies[0]);
    int choice;
    char selectedGenre[20];

    do {
        displayMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                strcpy(selectedGenre, "Action");
                break;
            case 2:
                strcpy(selectedGenre, "Comedy");
                break;
            case 3:
                strcpy(selectedGenre, "Drama");
                break;
            case 4:
                strcpy(selectedGenre, "Animation");
                break;
            case 5:
                strcpy(selectedGenre, "Science Fiction");
                break;
            case 6:
                printf("Thank you for using Movie Recommendation Quest!\n");
                break;
            default:
                printf("Invalid choice. Please select 1 to 6.\n");
        }

        if (choice >= 1 && choice <= 5) {
            showRecommendations(movies, count, selectedGenre);
        }

    } while (choice != 6);

    return 0;
}
