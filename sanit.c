#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
DIR *dir;
struct dirent *entry;
char old_name[256];
char new_name[256];

dir = opendir(".");
if (dir == NULL) {
    perror("opendir");
    return 1;
}

// Iterate over all the files in the directory
while ((entry = readdir(dir)) != NULL) {
    // Skip the "." and ".." entries
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        continue;
    }

    // Copy the file name to the old_name buffer
    strcpy(old_name, entry->d_name);

    // Replace any whitespaces or special characters with an underscore
    for (int i = 0; i < strlen(old_name); i++) {
        char c = old_name[i];
        if (c == ' ' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '+' || c == '=' || c == '[' || c == ']' || c == '{' || c == '}' || c == '|' || c == '\\' || c == ':' || c == ';' || c == '\'' || c == '\"' || c == '<' || c == '>' || c == ',' || c == '/' || c == '?' || c == '`' || c == '~') {
            new_name[i] = '_';
        } else {
            new_name[i] = c;
        }
    }
    new_name[strlen(old_name)] = '\0';

    // Only rename the file if the new name is different from the original name
    if (strcmp(old_name, new_name) != 0) {


        // Check if there is already a file with the same name as the new name
        while (access(new_name, F_OK) == 0) {
            // If there is, add an underscore to the beginning of the new name
            char temp[256];
            temp[0] = '_';
            strcpy(temp + 1, new_name);
            strcpy(new_name, temp);
        }

        // Rename the file
        if (rename(old_name, new_name) < 0) {
            perror("rename");
            return 1;
        }
                // Print the old and new filenames
        printf("%s --> %s\n", old_name, new_name);
    }
}

closedir(dir);

return 0;
}