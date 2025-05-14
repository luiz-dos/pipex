# 🔌 pipex

**Description**  
Emulates the shell pipe operator (`|`), chaining two commands by redirecting standard input/output through a pipe.

**🛠️ Technologies**  
- C language  
- Unix syscalls: `fork()`, `pipe()`, `dup2()`, `execve()`  

**🎯 Key Learning Outcomes**  
- Process control and forking logic  
- File descriptor redirection  
- Robust error handling in inter-process communication
