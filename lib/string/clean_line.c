/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Clean from backslash n
*/

void clean_line(char *str)
{
    for (int size = 0; str[size] != '\0'; size++) {
        if (str[size] == '\n') {
            str[size] = '\0';
        }
    }
}
