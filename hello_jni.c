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
	//jfieldID fidname = (*jenv)->GetFieldID(jenv, clazz, "name", "Ljava/lang/String");
	//jfieldID fidage = (*jenv)->GetFieldID(jenv, clazz, "age", "I");
	jmethodID gtnm = (*jenv)->GetMethodID(jenv,clazz, "getName","(V)Ljava/lang/String;");
	log("getstudent");
	jmethodID gtage = (*jenv)->GetMethodID(jenv,clazz, "getAge","(V)I");
	LOG;
	jmethodID stage = (*jenv)->GetMethodID(jenv,clazz, "setAge","(I)V");
	LOG;
	jmethodID stnm = (*jenv)->GetMethodID(jenv,clazz, "setName","(Ljava/lang/String;)V");
	LOG;
	jstring jname = (*jenv)->CallObjectMethod(jenv,clazz,gtnm);
	LOG;
	const char* name = (*jenv)->GetStringUTFChars(jenv,jname, 0);
	LOG;
	jint jage = (*jenv)->CallIntMethod(jenv,clazz,gtage);
	LOG;
	int  age = (int)jage;
	strcpy(in.name, name);
	in.age = age;
	student* s = getstudent(in);
	log("name:",name,",age:",age);	
	jobject out = (*jenv)->NewObject(clazz,gtnm,stnm,gtage,stage);

	LOG;
	jstring outjname = (*jenv)->NewStringUTF(jenv, s->name);
	jint outjage = (int)s->name;
	(*jenv)->CallVoidMethod(jenv,out, stnm, outjname);
	LOG;
	(*jenv)->CallVoidMethod(jenv,out, stage, outjage);
	LOG;
	return out;

}
