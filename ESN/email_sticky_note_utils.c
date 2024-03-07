#include "../ESN/lib_esn.h"
#include "../Ft_printf/lib_ftprintf.h"

/*
    Function to display the help menu
                                       */

void displayHelp(void)
{
    ft_printf("\033[1;34mAdd\033[0m, \033[1;34mUpdate\033[0m, \033[1;37mRemove\033[0m \033[1;34mand\033[0m \033[1;37mRetrieve Addresses\033[0m\n\n");
    ft_printf("\033[1;37m-a\033[0m, \033[1;30m--add       Add a new address to the database.\n\033[0m ");
    ft_printf("               \033[1;37mUsage:\033[0m -a name email [note]\n");
    ft_printf("                \033[1;37mNotes:\033[0m\n");
    ft_printf("                - \033[1;37mEnclose\033[0m arguments containing special characters \033[1;34min\033[0m quotes.\n");
    ft_printf("                - \033[1;37mExample:\033[0m -a \"John Doe\" john\033[1;36m@example\033[0m.com \"Work\"\n\n");
    ft_printf("\033[1;37m-g\033[0m, \033[1;30m--get       Display the address containing the specified query.\n\033[0m ");
    ft_printf("               \033[1;37mUsage:\033[0m -g query\n\n");
    ft_printf("\033[1;37m-h\033[0m, \033[1;30m--help      Display this menu.\n\n\033[0m");
    ft_printf("\033[1;37m-r\033[0m, \033[1;30m--remove    Remove the address with the specified name.\n\033[0m");
    ft_printf("                \033[1;37mUsage:\033[0m -r name\n\n");
    ft_printf("\033[1;37mComing Soon:\033[0m\n");
    ft_printf("\033[1;37m-u\033[0m, \033[1;30m--update=name   Update the address with the specified name.\n\033[0m");
    ft_printf("\033[1;37m-U\033[0m, \033[1;30m--update=note   Update the note of the specified address.\n\033[0m");
}

/*
    Function to check for duplicate entries
                                             */

int checkDuplicateName(const char *name)
{
    FILE *file = fopen(filename, "r"); // Opens the file in "read" mode.

    if (file == NULL)
    {
        ft_printf("Impossible d'ouvrir le fichier.\n");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (ft_strstr(line, name))
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}