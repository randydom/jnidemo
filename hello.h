#ifdef __cplusplus
extern "C" {
#endif
typedef struct student_s{
	char name[10];
	int age;

}student;
#define LOG log(__FILE__,__LINE__,__FUNCTION__);
int add(int a, int b);
int sub(int a, int b);
char* addstr(char* a);
student* getstudent(student t);
void log(const char* fmt,...);

#ifdef __cplusplus
}
#endif
