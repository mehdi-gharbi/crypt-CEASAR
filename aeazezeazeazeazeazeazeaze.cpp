#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

// Fonction pour chiffrer le message
void encrypt(char message[], int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        
        // Vérifie si le caractère est une lettre majuscule
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + key) % 26;
        }
        // Vérifie si le caractère est une lettre minuscule
        else if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + key) % 26;
        }
        
        printf("%c", c);
        i++;
    }
}

// Fonction pour déchiffrer le message
void decrypt(char message[], int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        
        // Vérifie si le caractère est une lettre majuscule
        if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - key + 26) % 26;
        }
        // Vérifie si le caractère est une lettre minuscule
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
    printf("2. Déchiffrer un message\n");
    printf("Choisissez une option : ");
    scanf("%d", &choice);
    
    // Vider le tampon d'entrée
    while ((c = getchar()) != '\n' && c != EOF);
    
    if (choice == 1) {
        printf("Entrez le message à chiffrer : ");
        while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
            message[i++] = c;
        }
        message[i] = '\0';
        
        printf("Entrez le décalage : ");
        scanf("%d", &key);
        
        printf("Message chiffré : ");
        encrypt(message, key);
    } else if (choice == 2) {
        printf("Entrez le message chiffré : ");
        while ((c = getchar()) != '\n' && c != EOF && i < MAX_LENGTH - 1) {
            message[i++] = c;
        }
        message[i] = '\0';
        
        printf("Entrez le décalage : ");
        scanf("%d", &key);
        
        printf("Message déchiffré : ");
        decrypt(message, key);
    } else {
        printf("Option invalide.\n");
        return 0;
    }
    
    printf("\n");
    return 0;
}
