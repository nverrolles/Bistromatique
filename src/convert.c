/*
** EPITECH PROJECT, 2020
** convert.c
** File description:
** encrypt and decrypt expression
*/

#include "../include/functions.h"

char *encrypt_str(char *str, char *base, char *ope)
{
    char *r_char = "()+-*/%0123456789";
    char *c_char = my_strcat(ope, base);
    char *encrypted_str = malloc((my_strlen(str) + 1) * sizeof(char));

    if (check_params(str, ope, base) == 0)
        exit(84);
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; c_char[j] != '\0'; j++) {
            if (str[i] == c_char[j]) {
                encrypted_str[i] = r_char[j];
                break;
            }
        }
    }
    encrypted_str[my_strlen(str)] = '\0';
    return encrypted_str;
}

char *decrypt_str(char *str, char *base, char *ope)
{
    char *r_char = "()+-*/%0123456789";
    char *c_char = my_strcat(ope, base);
    char *decrypted_str = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; r_char[j] != '\0'; j++) {
            if (str[i] == r_char[j]) {
                decrypted_str[i] = c_char[j];
                break;
            }
        }
    }
    decrypted_str[my_strlen(str)] = '\0';

    return decrypted_str;
}

int check_params(char *str, char *ope, char *base)
{
    int return_val = 1;
    ope = my_strcat(ope, base);

    for (int i = 0; str[i] != '\0'; i++) {
        return_val = 0;
        for (int j = 0; ope[j] != '\0'; j++) {
            if (str[i] == ope[j]) {
                return_val = 1;
            }
        }
        if (return_val == 0) {
            return 0;
        }
    }

    return return_val;
}