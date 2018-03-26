#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

#ifdef __GNUC__ 	//如果是使用的gcc编译器，则使用下面的__attribute__特性
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

//打印出与当前errno值相对应的错误文本
void ErrorMsg(const char *format, ...);

//与ErrorMsg相似，只是会终止程序：调用exit()退出，或者将环境变量EF_DUMPCORE定义为非空字符串，
//调用abort()退出，同时生成core文件
void ErrorExit(const char *format, ...) NORETURN ;

//打印错误消息之前，不会刷新标准输出
//终止进程使用的是_exit()，而不是exit()。这种退出方式，略去了对stdio缓冲区的刷新以及对退出处理程序（exit_handler）的调用
void ErrorExitNoRefresh(const char *format, ...) NORETURN ;

//只会打印与errnum参数中给定的错误号相对应的文本
void ErrorExitNum(int errnum, const char *format, ...) NORETURN ;

//诊断一般性错误
void Fatal(const char *format, ...) NORETURN ;

//诊断命令行参数使用方面的错误
void UsageError(const char *format, ...) NORETURN ;

//针对特定程序的命令行参数错误
void CmdLineError(const char *format, ...) NORETURN ;

#endif //ERROR_FUNCTIONS_H
