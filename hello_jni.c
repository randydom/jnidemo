#include "hello.h"
#include "jni.h"

JNIEXPORT int JNICALL Java_com_example_tangyi_myapplication_Hellojni_add(JNIEnv *jenv, jclass jcls,jint a, jint b)
{
	jint jresult = 0;
	int result;
	int ca=(jint)a;
	int cb=(jint)b;
	result = add(ca,cb);
	jresult = (jint)result;
	return jresult;
}
JNIEXPORT int JNICALL Java_com_example_tangyi_myapplication_Hellojni_sub(JNIEnv *jenv, jclass jcls,jint a, jint b)
{
	jint jresult = 0;
	int result;
	int ca=(jint)a;
	int cb=(jint)b;
	result = sub(ca,cb);
	jresult = (jint)result;
	return jresult;
}
JNIEXPORT jstring JNICALL Java_com_example_tangyi_myapplication_Hellojni_addstr(JNIEnv *jenv, jclass jcls,jstring a)
{
	const char* d = (*jenv)->GetStringUTFChars(jenv, a, 0);
	char* resualt = addstr(d);
	jstring r = (*jenv)->NewStringUTF(jenv, resualt);
	return r;
}
JNIEXPORT jobject JNICALL Java_com_example_tangyi_myapplication_Hellojni_getstudent(JNIEnv *jenv, jclass jcls,jobject a)
{
	LOG;
	student in;
	//jclass clazz = (*jenv)->FindClass(jenv,"com/example/tangyi/myapplication/Student");
	jclass clazz = (*jenv)->GetObjectClass(jenv,a);
	LOG;
	jfieldID fidname = (*jenv)->GetFieldID(jenv, clazz, "name", "Ljava/lang/String;");
	jfieldID fidage = (*jenv)->GetFieldID(jenv, clazz, "age", "I");
	LOG;
	jstring jname = (*jenv)->GetObjectField(jenv,a,fidname);
	const char* name = (*jenv)->GetStringUTFChars(jenv,jname, 0);
	LOG;
	jint  jage = (*jenv)->GetIntField(jenv,a,fidage);
	int age = (int)jage;
	log("get age");
	strcpy(in.name, name);
	in.age = age;
	student* s = getstudent(in);
	log("name:",name);	
	LOG;
	jmethodID dd = (*jenv)->GetMethodID(jenv,clazz,"<init>","()V");
	jobject out = (*jenv)->NewObject(jenv,clazz,dd);

	LOG;
	jstring outjname = (*jenv)->NewStringUTF(jenv, s->name);
	jint outjage = (int)s->name;
	log("set name");
	(*jenv)->SetObjectField(jenv,out,fidname,jname);
	(*jenv)->SetIntField(jenv,out,fidage,jage);
	LOG;
	return out;

}
