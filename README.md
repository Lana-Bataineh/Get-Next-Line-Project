*This activity has been created as part of the 42 curriculum by lalbatai*

--------------------------------------------------------------------------

## Description


**get_next_line** is a fundamental project in the 42 School curriculum designed to challenge your understanding of file I/O operations and memory allocation in C. The primary goal of this project is to code a reliable function that reads a single line from a file descriptor, returning the text line by line with each successive call until the End-Of-File (EOF) is reached.

This activity serves as an essential introduction to the highly practical concept of static variables, deepening your grasp of how data persists across multiple function calls.

The core learning objectives of this project include:
  **Static Variables:** Master the usage of static memory to preserve the reading state and buffer leftovers between consecutive function invocations.
  **Dynamic Memory Management:** Ensure precise allocation and deallocation of heap memory (using `malloc` and `free`) to guarantee zero memory leaks.
  **Buffer Size Flexibility:** Adapt dynamically to different reading efficiencies by modifying the buffer size at compilation time using the `-D BUFFER_SIZE=n` flag.

---------------------------------------------------------------------------

## Instructions


### Prerequisites ------

To use this function, you need a Unix-like environment (Linux or macOS) with the following tools installed:
*   **`cc` compiler** (or any other standard C compiler like `gcc` or `clang`)

### Compilation ------

All source files are compiled strictly using the standard 42 flags: `-Wall -Wextra -Werror`. 

Since this project does not use a Makefile, you must compile the source files directly alongside your main testing program. You also need to define the `BUFFER_SIZE` macro using the `-D` flag during compilation.

Navigate to your project directory and run the following command:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test
```
*Note: You can change `42` to any buffer size you want to test (e.g., `1`, `9999`, or `10000000`).*


### Execution & Usage ------

To use `get_next_line` in your code, follow these steps:

1. Include the header file in your C files:
   ```
   #include "get_next_line.h"
   ```
2. Open a file descriptor and call the function inside a loop to read the file line by line:
   ```
   int   fd;
   char  *line;

   fd = open("test.txt", O_RDONLY);
   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line); // Always free the returned line to avoid memory leaks
   }
   close(fd);
   ```
3. Run the compiled executable:
   ```bash
   ./gnl_test
   ```
------------------------------------------------------------------------------

## Resources

### References

*   [Linux Manual Page - read(2)](https://man7.org) – Official documentation on the behavior of the `read` system call, return values, and error codes.
*   [Static Variables in C - GeeksforGeeks](https://geeksforgeeks.org) – Comprehensive guide detailing lifetime, scope, and behavior of static memory within local functions.
*   [File Descriptors Guide - cppreference](https://cppreference.com) – Technical reference explaining input/output streams and Unix file descriptor tables.

### AI Usage Statement

Artificial Intelligence (AI) was utilized in the following capacity to complete this documentation and learning activity:

*   **Tasks performed:**
    *   Curating, validating, and formatting the technical references in the **Resources** section.
    *   Structuring and organizing the modular architectural overview within this `README.md` file.
    *   Explaining the foundation of using the `-D` flag for `BUFFER_SIZE`.
    *   Providing debugging assistance for tricky memory management cases (e.g., preventing memory leaks).
    *   Providing educational explanations regarding static variable states and the behavioral logic behind tracking newlines (`\n`) within buffers.

*   **Parts affected:**
    Documentation layout assistance, educational descriptions, and technical references only, providing critical edge cases for testing.

------------------------------------------------------------------------------              

## Functions Reference

### Core Function

#### `get_next_line`
```c
Prototype    : char *get_next_line(int fd);
Description  : The main function that orchestrates the reading process. It retrieves a single line from the given file descriptor, manages the static variable storage, and ensures memory is correctly allocated and freed.
Parameters   : fd ---> The file descriptor to read from.
Return Value : The read line (including '\n' if present), or NULL if the end of file is reached or an error occurs.
```

### Auxiliary Functions

#### `read_and_fill`
```c
Prototype    : char *read_and_fill(int fd, char *storage_line);
Description  : Reads data from the file descriptor into a temporary buffer in a loop until a newline character ('\n') is found or the end of the file is reached. It appends the new text to the existing storage string.
Parameters   : #1 ---> fd: The file descriptor to read from.
               #2 ---> storage_line: The current static string holding the read data.
Return Value : An updated string containing the newly read data appended to the old storage.
```

#### `extract_line`
```c
Prototype    : char *extract_line(char *storage_line);
Description  : Extracts the ready-to-return line from the compiled storage string. It stops allocating right after the first newline character ('\n') or at the string terminator ('\0').
Parameters   : storage_line ---> The accumulated string from the file.
Return Value : A newly allocated string containing exactly one line of text, or NULL if allocation fails.
```

#### `update_storage`
```c
Prototype    : char *update_storage(char *storage);
Description  : Cleans up the static storage string after a line has been extracted. It cuts off the returned line part and keeps only the leftover data after the newline character for the next function call.
Parameters   : storage ---> The current accumulated string.
Return Value : A newly allocated string containing only the remaining text, or NULL if there are no leftovers.
```

### Utility Functions

#### `ft_join`
```c
Prototype    : char *ft_join(char *storage_line, char *temp_buffer);
Description  : A custom memory allocation wrapper that joins the current storage text with the newly read buffer data, handling NULL protection efficiently.
Parameters   : #1 ---> storage_line: The existing accumulated string.
               #2 ---> temp_buffer: The new data read during the current cycle.
Return Value : A newly allocated concatenated string.
```

#### `ft_str_concat`
```c
Prototype    : void ft_str_concat(char *dst, const char *src1, const char *src2);
Description  : A low-level utility function that safely copies and concatenates two source strings into a pre-allocated destination buffer.
Parameters   : #1 ---> dst: The pre-allocated memory zone where the result will be stored.
               #2 ---> src1: The first source string.
               #3 ---> src2: The second source string.
Return Value : None.
```

#### `ft_strchr`
```c
Prototype    : char *ft_strchr(const char *str, char ch);
Description  : Searches for the first occurrence of a specific character (specifically '\n') within a string.
Parameters   : #1 ---> str: The string to scan.
               #2 ---> ch: The character to look for.
Return Value : A pointer to the first occurrence of the character, or NULL if the character is not found.
```

#### `ft_strlen`
```c
Prototype    : int ft_strlen(char *str);
Description  : Calculates the exact length of a null-terminated string.
Parameters   : str ---> The string whose length needs to be measured.
Return Value : The total number of characters in the string (excluding the null-terminator).
```

