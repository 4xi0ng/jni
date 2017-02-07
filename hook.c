#include <stdio.h>
#include <dlfcn.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

int native_hook_pid(pid_t pid, char * method_name, char * so_name, char * my_method_name)
{
	ptrace_attach(pid);
	inject_so(pid, so_name);
	modify_got(pid, )
}

int ptrace_attach (pid_t pid)
{
	if (ptrace(PTRACE_ATTACH, pid, 0, 0) < 0) {
        perror("ptrace_attach");
        return -1;
    }

    int status = 0;
    waitpid(pid, &status , WUNTRACED);

    return 0;
}
