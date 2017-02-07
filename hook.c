#include <stdio.h>
#include <dlfcn.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <android/log.h>

const char *libc_path = "/system/lib/libc.so";
const char *linker_path = "/system/bin/linker";

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

void* get_module_base(pid_t pid, const char* module_name)
{
    FILE *fp;
    long addr = 0;
    char *pch;
    char filename[32];
    char line[1024];

    if (pid < 0) {
        /* self process */
        snprintf(filename, sizeof(filename), "/proc/self/maps", pid);
    } else {
        snprintf(filename, sizeof(filename), "/proc/%d/maps", pid);
    }

    fp = fopen(filename, "r");

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, module_name)) {
                pch = strtok( line, "-" );
                addr = strtoul( pch, NULL, 16 );

                if (addr == 0x8000)
                    addr = 0;

                break;
            }
        }

        fclose(fp) ;
    }

    return (void *)addr;
}

void* get_remote_address(pid_t pid, const char* module_name, void* local_method_addr)
{
	void* local_module_addr = get_module_base(-1, module_name);
	void* remote_module_addr = get_module_base(pid, module_name);
	return local_method_addr - local_module_addr + remote_module_addr;
}

int inject_so(pid_t pid, char* so_name)
{
	
}