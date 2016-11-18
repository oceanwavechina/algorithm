/*
 * fork.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: liuyanan
 */


#include <unistd.h>
#include <iostream>


/*
 这样理解:
	(1) 对于现代的操作系统来讲, 每个进程都有自己的独立虚拟地址空间, 进程中的地址并不是实际的物理内存的地址,
		内核会完成从虚拟地址到物理地址的映射.所以两个不同进程中的同一虚拟地址, 不一定(这块我只能用不一定)映射到同一物理内存地址.

	(2) 对于父子进程而言, 子进程是父进程调用fork()后创建出来的拷贝, 理论上二者在虚拟内存空间这个角度上看是一样的,
		所以在父进程在fork()前创建的变量, 与fork()后子进程中的同一变量虚拟地址是一样的.

	(3) 对于内核而言, 每次fork()时都创建父进程的完整拷贝, 效率是比较低下的, 所以操作系统会使用copy-on-write(写时拷贝)机制,
		所以在父子进程中一方对某一地址空间写入之前, 二者实际上是映射到同一物理内存地址,
		父子一方对某一地址空间进行写入操作时, 操作系统才实际创建这一部分的拷贝
 */


int main()
{
	pid_t fpid;
	int count = 0;

	fpid = fork();
	if (fpid < 0)
		std::cout << "error in fork";
	else if (fpid == 0) {
		count++;
		std::cout << "child process with pid: " << getpid() << "; with count: " << count  << "; and counter address: " << (int*)&count << std::endl;
	} else {
		std::cout << "parent process with pid: " << getpid() << "; with count: " << count  << "; and counter address: " << (int*)&count << std::endl;
	}

	return 0;
}
