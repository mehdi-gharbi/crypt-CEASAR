#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Fonction pour chiffrer le message
void encrypt(char message[], int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        
        // V�rifie si le caract�re est une lettre majuscule
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + key) % 26;
        }
        // V�rifie si le caract�re est une lettre minuscule
        else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + key) % 26;
        }
        
        printf("%c", c);
        i++;
    }
}

// Fonction pour d�chiffrer le message
void decrypt(char message[], int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        
        // V�rifie si le caract�re est une lettre majuscule
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - key + 26) % 26;
        }
        // V�rifie si le caract�re est une lettre minuscule
        else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' - key + 26) % 26;
        }
        
        printf("%c", c);
        i++;
    }
}

int main() {
    int choice;
    char message[MAX_LENGTH];
    int key;
    int c;
    int i = 0;
    
    printf("Menu:\n");
    printf("1. Chiffrer un message\n");
    printf("2. D�chiffrer un message\n");
    printf("Choisissez une option : ");
    scanf("%d", &choice);
    
    // Vider le tampon d'entr�e
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (choice == 1) {
        printf("Entrez le message � chiffrer : ");
        while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
            message[i++] = c;
        }
        message[i] = '\0';
        
        printf("Entrez le d�calage : ");
        scanf("%d", &key);
        
        printf("Message chiffr� : ");
        encrypt(message, key);
    } else if (choice == 2) {
        printf("Entrez le message chiffr� : ");
        while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
            message[i++] = c;
        }
        message[i] = '\0';
        
        printf("Entrez le d�calage : ");
        scanf("%d", &key);
        
        printf("Message d�chiffr� : ");
        decrypt(message, key);
    } else {
        printf("Option invalide.\n");
        return 0;
    }
    
    printf("\n");
    return 0;
}
