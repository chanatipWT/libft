*This project has been created as part of the 42 curriculum by cwathits.*

# Libft — Your very first own library

## Description

**Libft** is the foundational C library project in the 42 curriculum (Subject Version 19.3). The primary goal of this project is to understand how standard C library functions and fundamental data structures work under the hood by reimplementing them from scratch in strict accordance with the 42 Norm.

The resulting static library (`libft.a`) provides a comprehensive suite of 43 general-purpose functions spanning character classification, string manipulation, raw memory management, integer-to-string conversions, file descriptor output utilities, and singly linked list operations. This library serves as a reusable building block for subsequent C projects throughout the curriculum.

## Detailed Library Description

The library is organized into three parts as specified in the subject:

### Part 1 — Libc Functions (23 Functions)
Reimplementations of standard C library functions (`<ctype.h>`, `<string.h>`, `<strings.h>`, `<stdlib.h>`) prefixed with `ft_`, without using the `restrict` keyword:

| Function | Prototype | Summary |
| :--- | :--- | :--- |
| `ft_isalpha` | `int ft_isalpha(int c)` | Returns `1` if `c` is an alphabetic character (`A-Z` or `a-z`), `0` otherwise. |
| `ft_isdigit` | `int ft_isdigit(int c)` | Returns `1` if `c` is a decimal digit (`0-9`), `0` otherwise. |
| `ft_isalnum` | `int ft_isalnum(int c)` | Returns `1` if `c` is an alphanumeric character, `0` otherwise. |
| `ft_isascii` | `int ft_isascii(int c)` | Returns `1` if `c` fits into the 7-bit US-ASCII character set (`0-127`), `0` otherwise. |
| `ft_isprint` | `int ft_isprint(int c)` | Returns `1` if `c` is a printable character (including space, `32-126`), `0` otherwise. |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Computes the length of string `s` excluding the terminating null byte. |
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills the first `n` bytes of memory area `s` with constant byte `c`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Erases the data in the `n` bytes of the memory starting at `s` by writing zeros. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from memory area `src` to memory area `dest` (non-overlapping). |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest`, safely handling overlapping memory blocks. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Size-bounded string copying; guarantees null-termination if `size > 0` and returns `ft_strlen(src)`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Size-bounded string concatenation; appends `src` to `dst` of total buffer size `size`. |
| `ft_toupper` | `int ft_toupper(int c)` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | `int ft_tolower(int c)` | Converts an uppercase letter to lowercase. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Locates the first occurrence of `(unsigned char)c` in string `s` (including `'\0'`). |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Locates the last occurrence of `(unsigned char)c` in string `s` (including `'\0'`). |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares at most the first `n` bytes of `s1` and `s2` using `unsigned char` values. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Scans the initial `n` bytes of memory area `s` for the first instance of `(unsigned char)c`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares the first `n` bytes (each interpreted as `unsigned char`) of memory areas `s1` and `s2`. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Locates the first occurrence of null-terminated string `little` in `big`, searching at most `len` characters. |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converts the initial portion of string `nptr` to an `int` representation. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Allocates zero-initialized memory for an array of `nmemb` elements of `size` bytes each (with overflow protection and unique freeable pointer when `nmemb` or `size` is `0`). |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Returns a pointer to a newly allocated string which is a duplicate of `s`. |

### Part 2 — Additional Functions (11 Functions)
Higher-level string utilities, functional string iterators, and file descriptor output helpers:

| Function | Prototype | Summary |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring from `s` starting at index `start` of maximum length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates and returns a new string resulting from the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates and returns a copy of `s1` with all characters in `set` trimmed from both ends. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` using delimiter `c` into a newly allocated, `NULL`-terminated array of strings, freeing all prior allocations on failure. |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns a string representing the signed integer `n`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function `f` to each character of `s` with its index to create a newly allocated string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies function `f` to each character of `s` passed by address along with its index. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs character `c` to the specified file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs string `s` to the specified file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs string `s` to the specified file descriptor `fd`, followed by a newline. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs integer `n` to the specified file descriptor `fd`. |

### Part 3 — Linked List Functions (9 Functions)
Functions for creating, traversing, transforming, and freeing singly linked lists using the `t_list` structure defined in `libft.h`:

| Function | Prototype | Summary |
| :--- | :--- | :--- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates and returns a new `t_list` node initialized with `content` and `next = NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserts node `new` at the beginning of the list `*lst`. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst)` | Counts and returns the number of nodes in `lst` as an `unsigned int`. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns a pointer to the last node of the list `lst`. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends node `new` to the end of the list `*lst`. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees a single node's content using `del` and frees the node itself without freeing `next`. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees the given node and all its successors using `del` and `free`, setting `*lst` to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Iterates through `lst` and applies function `f` to the `content` of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Iterates through `lst`, applies `f` to each node's content to create a new list, and cleans up with `del` if any allocation fails. |

## Instructions

### Compilation
Make sure all `.c` files, `libft.h`, and `Makefile` are in the root directory of your repository. Run:

```bash
make
```

This compiles all `.c` source files with `cc -Wall -Wextra -Werror` and archives the object files into `libft.a` using `ar rcs` without unnecessary relinking.

### Available Makefile Rules
- `make` or `make all`: Compiles the mandatory library `libft.a`.
- `make clean`: Removes all generated `.o` object files.
- `make fclean`: Removes all `.o` object files and `libft.a`.
- `make re`: Runs `fclean` followed by `all` to recompile the library from scratch.
- `make bonus`: Ensures compatibility with bonus evaluation rules without relinking.

### Usage in Your Programs
Include `"libft.h"` in your C source files and link against `libft.a` during compilation:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

## Resources

### Classic References
- **Linux Man Pages (`man 3`)**: Official specifications for `string.h`, `stdlib.h`, `ctype.h`, and BSD string functions (`strlcpy`, `strlcat`, `strnstr`).
- **The C Programming Language (Kernighan & Ritchie, 2nd Edition)**: Foundational reference on pointers, memory management, and linked lists.
- **42 Norm v4 Specification**: Coding style and structural rules for 42 C projects.

### AI Usage Disclosure
AI tools were used during this project for the following tasks and parts:
- Reviewing the Subject Version 19.3 requirements and verifying prototype details (such as `unsigned int ft_lstsize(t_list *lst)`, strict `1`/`0` return values for character classification functions in Part 1, and `ft_calloc` zero-size pointer behavior).
- Structuring and formatting the `Makefile`, `libft.h`, and `README.md` documentation.
- Designing automated unit tests and edge-case checks across Part 1, Part 2, and Part 3 functions.
