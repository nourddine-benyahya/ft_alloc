<div align="center">
  <h1>NO LEAKS NO REEKS</h1>
<div align="center">
  <img src="https://miro.medium.com/v2/resize:fit:653/0*h-NV13DA2cvjcNMN.jpeg" alt="Image">
</div>
</div>

# Memory Management Library

This library provides a simple mechanism to manage dynamic memory allocations in C and to ensure that all allocated memory is freed at the end of the program, preventing memory leaks. It includes functions for allocating and freeing memory, and maintains a list of all allocated addresses.

## Functions

### `void *ft_alloc(size_t size, void *ptr, char mode)`

Allocates, reallocates, or frees memory based on the specified operation.

- **Parameters:**
  - `size`: The size of the memory to allocate.
  - `ptr`: The pointer to the memory to reallocate or free. Set to `NULL` for new allocations.
  - `mode`: The operation to perform. This can be:
    - `MALLOC` for `malloc`
    - `CALLOC` for `calloc`
    - `FREE_PTR` to free a specific pointer
    - `FREE_ALL` to free all allocated memory

- **Returns:** A pointer to the allocated memory, or `NULL` if an error occurs.

## instalation
- clone the repo inside your main project:
  ```
  git clone git@github.com:nourddine-benyahya/ft_alloc.git
  ```

- append this inside your makefile in building target rule
  ```
  make -C ft_alloc all
  ```
- append this inside your makefile in librarys includes  
  ```
  alloc/ft_alloc.a
  ```
- include `#include "ft_alloc.h"` in your header file
  ```
  #include "ft_alloc.h"
  ```

#### example :
  before : 
  ```
      LIBS = libft/libft.a
      $(NAME) : $(OBJ)
            $(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
  ```
  after :
  ```
      LIBS = libft/libft.a alloc/ft_alloc.a
      $(NAME) : $(OBJ)
            make -C ft_alloc all
            $(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
  ```
 
  

make the libarary
`cd ft_alloc`


## Usage

### testing Code Example

```c
#include "ft_alloc.h"

void leaks(void)
{
    system("leaks a.out");
}

int ft_testing(void)
{
    //check memory leaks at the exit of the programm
    atexit(leaks);

    // Allocate memory using malloc
    void *ptr1 = ft_alloc(sizeof(char *), NULL, MALLOC);

    // Allocate memory using calloc
    void *ptr2 = ft_alloc(sizeof(int *), NULL, CALLOC);

    // Free a specific pointer
    ft_alloc(0, ptr1, FREE_PTR);

    // Free all allocated memory
    ft_alloc(0, NULL, FREE_ALL);

    return (0);
}
int main()
{
    ft_testing();
}
```

