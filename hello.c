#include "hello.h"
#include "string.h"
#include "android/log.h"
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
char* addstr(char* a)
{
	return a;

}
student* getstudent(student t)
{
	student* s = malloc(sizeof(t));
	memset(s,0,sizeof(t));
	strcpy(s->name,t.name);
	s->age = t.age;
	return s;
}
void log(const char* fmt,...)
{
  va_list va_android;
  va_start(va_android,fmt);
  __android_log_vprint(ANDROID_LOG_DEBUG, "Hello", fmt, va_android);
  va_end(va_android);
}
