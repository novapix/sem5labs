// Random Password Generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length)
{
    char regex[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789"
                   "!@#$%^&*()-_=+[]{};:,.<>?";
    int regex_size = sizeof(regex) - 1;
    char password[length + 1];
    for (int i = 0; i < length; i++)
    {
        int randomIndex = rand() % regex_size;
        password[i] = regex[randomIndex];
    }
    password[length] = '\0'; // null-terminate string
    printf("Generated Password: %s\n", password);
}
int main()
{
    int length;
    srand(time(NULL));
    printf("Enter the desired password length: ");
    scanf("%d", &length);
    generatePassword(length);
    return 0;
}