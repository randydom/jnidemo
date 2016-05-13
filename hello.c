#include "hello.h"
#include "string.h"
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
