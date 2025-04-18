# get_next_line

![42 Badge](https://img.shields.io/badge/42-get__next__line-00babc)
![C Badge](https://img.shields.io/badge/Language-C-blue)

## 📚 Overview

get_next_line (GNL) is a programming project at 42 School that involves creating a function which reads a line from a file descriptor. This function is designed to be called in a loop, allowing for the reading of a text file one line at a time.

## 🔍 Description

The function `get_next_line` reads from a file descriptor and returns a line (a string ending with a newline character `\n` or the end of the file). When called in a loop, it should read the text file pointed to by the file descriptor, one line at a time.

## 📋 Function Prototype

```c
char *get_next_line(int fd);
```

### Return Value
- A line read from the file descriptor
- NULL if there's nothing else to read or if an error occurred

## 🛠️ Implementation

This implementation handles:
- Reading from any file descriptor (files, standard input, etc.)
- Managing multiple file descriptors simultaneously with the bonus part
- Proper memory management to avoid leaks
- Reading files with a specified buffer size (defined through compilation)

## 🚀 How to Use

### Compilation

To compile the function with your program:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_program.c
```

You can change the buffer size by modifying the `BUFFER_SIZE` value during compilation.

### Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // Read file line by line
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);  // Don't forget to free the allocated memory
    }

    // Close file
    close(fd);
    return (0);
}
```

### Handling Multiple File Descriptors (Bonus)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);

    // Read alternately from both files
    line = get_next_line(fd1);
    printf("File 1: %s", line);
    free(line);

    line = get_next_line(fd2);
    printf("File 2: %s", line);
    free(line);

    line = get_next_line(fd1);
    printf("File 1: %s", line);
    free(line);

    // Close files
    close(fd1);
    close(fd2);
    return (0);
}
```

## 🧩 Project Structure

```
.
├── get_next_line.c       # Main function implementation
├── get_next_line.h       # Header file
├── get_next_line_utils.c # Helper functions
├── get_next_line_bonus.c       # Bonus implementation for multiple FDs
├── get_next_line_bonus.h       # Bonus header file
└── get_next_line_utils_bonus.c # Bonus helper functions
```

## 🔬 Key Learning Objectives

- Static variables
- File descriptor management
- Memory allocation and management
- Buffer manipulation
- Reading files with a set chunk size
- Understanding EOF (End of File)

## 📝 Technical Constraints

- Only allowed functions: `read`, `malloc`, and `free`
- Function must work with any buffer size defined during compilation
- All memory allocated with `malloc` must be properly freed
- No memory leaks
- No global variables
- Code must comply with the 42 Norm

## 👤 Author

- Oussama Zahdi (@oussamazahdi)

## 💬 Acknowledgements

- 42 School for providing this challenging project
- All fellow students who provided feedback and testing