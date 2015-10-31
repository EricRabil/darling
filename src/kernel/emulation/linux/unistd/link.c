#include "link.h"
#include "../base.h"
#include "../errno.h"
#include <asm/unistd.h>

long sys_link(const char* path, const char* link)
{
	int ret;

	// TODO: case translation

	ret = LINUX_SYSCALL(__NR_link, path, link);
	if (ret < 0)
		ret = errno_linux_to_bsd(ret);

	return ret;
}

