# **[Program 1](link/to/program1.c)**  :
**Develop a C program to implement Process system calls:**  
`fork()`, `exec()`, `wait()`, `create process`, `terminate process`.

---

<details>
  <summary><strong>Full Code</strong></summary>

```c
#include <stdio.h>    // For printf()
#include <stdlib.h>   // For exit()
#include <sys/types.h> // For pid_t
#include <sys/wait.h>  // For wait()
#include <unistd.h>    // For fork()

int main() {
    pid_t pid; 
    pid = fork();  // Create a new process

    if (pid == 0) { // Child process
        printf("It is the child process and pid is %d\n", getpid());
        for (int i = 0; i < 8; i++) {
            printf("%d\n", i);
        }
        exit(0); // Exit the child process
    } 
    else if (pid > 0) { // Parent process
        printf("It is the parent process and pid is %d\n", getpid());
        int status;
        wait(&status);  // Wait for child process to finish
        printf("Child is reaped\n");
    } 
    else {  // Fork failed
        printf("Error in forking..\n"); 
        exit(EXIT_FAILURE);
    }

    return 0;
}
```
</details>



---

## **Explanation**

### **1. Including Necessary Headers**
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
```
- **`stdio.h`**: For input/output functions like `printf`.  
- **`stdlib.h`**: Provides functions like `exit()`.  
- **`sys/types.h`**: Defines `pid_t` for process IDs.  
- **`sys/wait.h`**: Functions for process termination, like `wait()`.  
- **`unistd.h`**: For `fork()` and other system calls.

---

### **2. Process Creation and Execution**
#### **Child Process**
```c
if (pid == 0) {
    printf("It is the child process and pid is %d\n", getpid());
    for (int i = 0; i < 8; i++) {
        printf("%d\n", i);
    }
    exit(0);
}
```
- The **child process** prints its process ID (`getpid()`) and a loop from `0-7`.
- Terminates using `exit(0)`.

#### **Parent Process**
```c
else if (pid > 0) {
    printf("It is the parent process and pid is %d\n", getpid());
    int status;
    wait(&status);
    printf("Child is reaped\n");
}
```
- The **parent process** prints its process ID.  
- Uses `wait()` to pause and reap the child process, preventing a **zombie process**.

#### **Forking Error**
```c
else {
    printf("Error in forking..\n");
    exit(EXIT_FAILURE);
}
```
- Prints an error message if `fork()` fails.

---

## **Key Concepts**
1. **`fork()`**:  
   - Creates a new process.
   - Returns `0` to the child process and the child's PID to the parent.
2. **`wait()`**:  
   - Makes the parent process wait for the child to finish.
   - Prevents **zombie processes** by reaping the child.
3. **Zombie Process**:  
   - A terminated process that has not been reaped by the parent.

---

## **Sample Output**
```plaintext
It is the parent process and pid is 12345
It is the child process and pid is 12346
0
1
2
3
4
5
6
7
Child is reaped
```
