#include "jni.h"
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT int JNICALL Java_com_example_tangyi_myapplication_HellojniCpp_add(JNIEnv *jenv, jclass jcls,jint a, jint b)
{
	jint jresult = 0;
	jresult = a+b;
	return jresult;
}
JNIEXPORT int JNICALL Java_com_example_tangyi_myapplication_HellojniCpp_sub(JNIEnv *jenv, jclass jcls,jint a, jint b)
{
	jint jresult = 0;
	jresult = a-b;
	return jresult;
}
JNIEXPORT jstring JNICALL Java_com_example_tangyi_myapplication_HellojniCpp_strcat(JNIEnv *jenv, jclass jcls,jstring a)
{
	const char* value = jenv->GetStringUTFChars(a,0);
	jstring r = jenv->NewStringUTF(value);
		return r;
	}
#ifdef __cplusplus
}
#endif
