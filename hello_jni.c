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
	jclass clazzin = (*jenv)->GetObjectClass(jenv, a);
	student in;
	//jclass clazz = (*jenv)->FindClass(jenv,"com/example/tangyi/myapplication/Student");
	jfieldID fidname = (*jenv)->GetFieldID(jenv, clazzin, "name", "Ljava/lang/String");
	jfieldID fidage = (*jenv)->GetFieldID(jenv, clazzin, "age", "I");
	jmethodID gtnm = (*jenv)->GetMethodID(jenv,clazzin, "getName","()Ljava/lang/String");
	jmethodID stnm = (*jenv)->GetMethodID(jenv,clazzin, "setName","(Ljava/lang/String)");
	jmethodID gtage = (*jenv)->GetMethodID(jenv,clazzin, "getAge","()I");
	jmethodID stage = (*jenv)->GetMethodID(jenv,clazzin, "setAge","(I)");
	jstring jname = (*jenv)->CallObjectMethod(jenv,clazzin,gtnm);
	const char* name = (*jenv)->GetStringUTFChars(jenv,jname, 0);
	jint jage = (*jenv)->CallIntMethod(jenv,clazzin,gtage);
	int  age = (int)jage;
	strcpy(in.name, name);
	in.age = age;
	student* s = getstudent(in);
	
	jobject out = (*jenv)->NewObject(clazzin,gtnm,stnm,gtage,stage);

	jstring outjname = (*jenv)->NewStringUTF(jenv, s->name);
	jint outjage = (int)s->name;
	(*jenv)->CallVoidMethod(jenv,out, stnm, outjname);
	(*jenv)->CallVoidMethod(jenv,out, stage, outjage);
	return out;

}
