#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};
void registerUser() {
    FILE *file;
    struct User user;
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter password: ");
    scanf("%s", user.password);
    file = fopen("users.txt", "a");
    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);
    printf("Registration successful.\n");
}
int checkCredentials(char* username, char* password) {
    FILE *file;
    struct User user;
    int found = 0;
    file = fopen("users.txt", "r");
    while(fscanf(file, "%s %s\n", user.username, user.password) != EOF) {
        if(strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);
    return found;
}
void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    if(checkCredentials(username, password)) {
        printf("Login successful.\n");
    } else {
        printf("Invalid username or password.\n");
    }
}
int main() {
    int choice;
    while(1) {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}