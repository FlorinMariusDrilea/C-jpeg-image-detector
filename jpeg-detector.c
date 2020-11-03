// Detects if a file/image is a JPEG file format
#include <stdio.h>


int main(int argc, char *argv[])
{
    // Check if the argument is there
    if (argc != 2)
    {
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    // Read the first 3 bytes
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    // Check first three bytes
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("It is a JPEG file format.\n");
    }
    else
    {
        printf("It is not a JPEG file format.\n");
    }
    fclose(file);
}
