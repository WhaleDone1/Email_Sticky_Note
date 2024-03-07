#include "../ESN/lib_esn.h"
#include "../Ft_printf/lib_ftprintf.h"

/*
            Set the file name and path, Also filename const is
    already declared in the header file as: extern const char *filename;
                    so only need to assign it once.
                                                                            */

const char *filename = "ESN/database.txt";

/*
    Function to display the wanted address (Get)
                                                 */

void getAddress(const char *name)
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
            ft_printf("%s", line);
        }
    }
    fclose(file);
}

/*
    Function to add a new address
                                   */

void addAddress(const char *name, const char *email, const char *note)
{
    if (checkDuplicateName(name))
    {
        ft_printf("Duplicate name found. Please provide a unique name.\n");
        return;
    }

    FILE *file = fopen(filename, "a"); // Opens the file in "append" mode.
    if (file == NULL)
    {
        ft_printf("Unable to open the file.\n");
        exit(1);
    }

    if (note != NULL)
    {
        fprintf(file, "name: %s | email: %s | note: %s\n", name, email, note);
    }
    else
    {
        fprintf(file, "name: %s | email: %s\n", name, email);
    }
    fclose(file);
    ft_printf("Address added successfully.\n");
}

/*
    Function to remove an address
                                   */

void removeAddress(const char *name)
{
    FILE *tempFile = fopen("temp.txt", "w"); // Opens a temporary file in "write" mode.
    FILE *file = fopen(filename, "r");

    if (file == NULL || tempFile == NULL)
    {
        ft_printf("Unable to open the file.\n");
        exit(1);
    }
    char line[256];
    int removed = 0;
    while (fgets(line, sizeof(line), file))
    {
        char *start = ft_strstr(line, name);
        if (start && (start == line || *(start - 1) == ' ') && (*(start + ft_strlen(name)) == ' ' || *(start + ft_strlen(name)) == '\n'))
        {
            removed = 1;
        }
        else
        {
            fprintf(tempFile, "%s", line);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
    if (removed)
    {
        ft_printf("Address removed successfully.\n");
    }
    else
    {
        ft_printf("Address not found.\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1 || (argc == 2 && (ft_strcmp(argv[1], "--help") == 0 || ft_strcmp(argv[1], "-h") == 0)))
    {
        displayHelp();
        return 0;
    }
    if (argc < 3 || argc > 5)
    {
        ft_printf("Invalid number of arguments.\n");
        ft_printf("For help, use -h or --help.\n");
        return 1;
    }
    if (ft_strcmp(argv[1], "--get") == 0 || ft_strcmp(argv[1], "-g") == 0)
    {
        // Get address
        if (argc == 3)
        {
            const char *name = argv[2];
            getAddress(name);
        }
        else
        {
            ft_printf("Usage: %s --get name\n", argv[0]);
            return 1;
        }
    }
    else if (ft_strcmp(argv[1], "--add") == 0 || ft_strcmp(argv[1], "-a") == 0)
    {
        // Add address
        if (argc == 4 || argc == 5)
        {
            const char *name = argv[2];
            const char *email = argv[3];
            const char *note = (argc == 5) ? argv[4] : NULL;

            addAddress(name, email, note);
        }
        else
        {
            ft_printf("Usage: %s --add name email [note]\n", argv[0]);
            return 1;
        }
    }
    else if (ft_strcmp(argv[1], "--remove") == 0 || ft_strcmp(argv[1], "-r") == 0)
    {
        // Remove address
        if (argc == 3)
        {
            const char *name = argv[2];
            removeAddress(name);
        }
        else
        {
            ft_printf("Usage: %s --remove name\n", argv[0]);
            return 1;
        }
    }
    else
    {
        ft_printf("Invalid command.\n");
        return 1;
    }
    return 0;
}
