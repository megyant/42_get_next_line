# 42_getnextline

This project has been created as part of the 42 curriculum.

## Description
Get_next_line project aims to develop a program that reads a file descriptor until either a '\n' (new line) or EOF is found.  
  
This project included the use of static variables and the read() function. Static variables, unlike shorter-lived variables where we find an automatic allocation, are variables in which their lifetime lasts for the entire run of the program, this occurs because they are allocated satically, that is they are allocated at the compile time before the program is executed. Simplifying, static variables work as a bookmarker, they keep track of what they have been allocated until the end of the program.  
  
The read() function uses static variables as an attempt to count bytes from file descriptor into the buffer. The function will keep reading the file until it finds the end of file (EOF), keeping track of the progress while the program lasts. If successful, read() returns the number of bytes read, else it returns -1, or, when it reaches the EOF, it returns 0.

The get_next_line.c file in this repository contains the char	*get_next_line(int fd) function and an example of main that can be used to run the program. The get_next_line_utils.c contains the auxiliary functions: fill_buffer aims to fill the static variable with the read() function and verifies whether the content inside the buffer has already been "filtered" or not. ft_isnewline scans buffer to find a '\n' character and cleans the buffer in case it is found. ft_strjoin concatenates the everchanging buffer to the final line that is going to be delivered. Finally ft_strlen calculates the length of a string and it's used as an utilitary function for ft_strjoin.  The get_next_line.h has all the libraries calls, it defines BUFFER_SIZE (length of chars that read() will read each call) and the prototypes of all functions.  

The bonus part, consisted of creating a get_next_line capable of handling multiple file descriptors, the overall structure remained the same with the added [FOPEN_MAX] to the static buffer to make it possible.  

## Instructions
To run this program use the following commands

### Mandatory:
```
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
```

### Bonus:
```
cc -Wall -Werror -Wextra get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Change BUFFER_SIZE

```
-D BUFFER_SIZE=1
```
### Using valgrind

```
cc -Wall -Werror -Wextra -d get_next_line.c get_next_line_utils.c
```
```
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

## Resources
- [Get_next_line explained](https://www.youtube.com/watch?v=-Mt2FdJjVno)
- [Roadmap.c](https://github.com/ricardoferreirax/GET_NEXT_LINE/blob/main/roadmap.c)
- [Guide](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)
- [Static variable wikipedia](https://en.wikipedia.org/wiki/Static_variable)
- [Static variables geekforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Educative read()](https://www.educative.io/answers/read-data-from-a-file-using-read-in-c)
