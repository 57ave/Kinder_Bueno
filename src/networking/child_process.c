/*
** EPITECH PROJECT, 2023
** Kinder_Bueno
** File description:
** child_process
*/

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

int child_process(void)
{
    printf("child_process call\n");
    system("telnet localhost 8080");
    return 0;
}
