#include "hello.h"
#include "jni.h"

typedef enum cla{
	ONE,
	TWO,
	THREE
}e_CLA;

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
	log("get age","123");
	strcpy(in.name, name);
	in.age = age;
	student* s = getstudent(in);

	log("name:",name);
	LOG;
	jmethodID dd = (*jenv)->GetMethodID(jenv,clazz,"<init>","()V");
	jobject out = (*jenv)->NewObject(jenv,clazz,dd);
	LOG;
	jstring outjname = (*jenv)->NewStringUTF(jenv, s->name);
	jint outjage = (int)s->age;
	log("set name");
	(*jenv)->SetObjectField(jenv,out,fidname,outjname);
	(*jenv)->SetIntField(jenv,out,fidage,outjage);
	LOG;
	free(s);
	return out;

}
JNIEXPORT jobject JNICALL Java_com_example_tangyi_myapplication_Hellojni_gettotal(JNIEnv *jenv, jclass jcls,jobject a)
{
	LOG;
	jclass clazz = (*jenv)->GetObjectClass(jenv,a);
	LOG;
	//get enum
	jmethodID getVal = (*env)->GetMethodID(jenv,clazz, "values", "()LStudentone$cla");
	jstring value = (jstring)(*env)->CallObjectMethod(jenv,clazz, getVal);
	const char * valueNative = env->GetStringUTFChars(jenv,value, 0);
	e_CLA cl;
	if(strcmp(valueNative,"ONE") == 0)
	{
		cl = ONE;
		log("enum is one");
	}else if(strcmp(valueNative,"TWO") == 0)
	{
		cl = TWO;
		log("enum is two");
	}else if(strcmp(valueNative,"THREE") == 0)
	{
		cl = THREE;
		log("enum is three");
	}



	//arrary
	jfieldID cardfied = (*jenv)->GetFieldID(jenv, clazz, "card","[I");
	jintArray card = (*jenv)->GetObjectField(jenv,clazz,cardfied);
	jsize jsize = (*jenv)->GetArrayLength(jenv,card);
	jint i = 0;
	int total = 0;
	for(i; i < jsize; i++)
	{
		jint value = (*jenv)->GetObjectArrayElement(jenv,card,i);
		total +=(int)value;
	}
	//new object
	jmethodID dd = (*jenv)->GetMethodID(jenv,clazz,"<init>","(I)");
	jobject out = (*jenv)->NewObject(jenv,clazz,dd,99);
	return out;

}
