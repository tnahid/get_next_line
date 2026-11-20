*This project has been created as part of the 42 curriculum by tnahid.*

# Description

**get_next_line** is a C project that implements a function capable of reading a file or input stream one line at a time.

The goal is to understand file descriptors, static variables, memory allocation, and buffered reading.

The project also includes the bonus part, which allows reading from multiple file descriptors simultaneously.

# Instructions

### Compilation

Compile the mandatory part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Compile the bonus part:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

Replace `42` with your desired buffer size.

### Usage

Include the appropriate header:

```c
#include "get_next_line.h"
```

Call the function to read one line at a time:

```c
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
```

# Resources

- [Linux Manual Pages](https://man7.org/linux/man-pages/) — Documentation for `read()`, `open()`, and `close()`.
- [C Programming Language](https://en.cppreference.com/w/c) — C language reference.
- 42 subject and project documentation.
- stackoverflow website.
- my peers.

### Algorithm

The algorithm uses a static buffer to preserve unread data between function calls.

1. Read data from the file descriptor using `read()` and store it in a temporary buffer.
2. Append the newly read data to the previously saved content.
3. Continue reading until a newline character is found or EOF is reached.
4. Extract the next line and return it.
5. Preserve the remaining content for the next function call.

The static storage allows the function to remember its state between calls without losing unread data.

**Bonus:** The bonus implementation supports multiple file descriptors simultaneously by maintaining separate saved content for each file descriptor. This allows switching between files without losing their reading positions.

### AI Usage

AI was used to help understand concepts related to the project, clarify technical questions.
