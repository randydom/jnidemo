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
