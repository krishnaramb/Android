#include <jni.h>
#include <iostream>
#include "SummaryReportClass.h"

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
  std::cout<<" JNI ONload is being called \n";
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR; // JNI version not supported.
    }
    return JNI_VERSION_1_6; // returns the JNI vesion needed by the native library
}

JNIEXPORT jobject JNICALL Java_SummaryReportClass_getIntegerObject (JNIEnv * jenv, jobject jobj, jint number)
{
  // Get a class reference for java.lang.Integer
  jclass cls = jenv->FindClass("java/lang/Integer");

  // Get the Method ID of the constructor which takes an int
  jmethodID midInit = jenv->GetMethodID(cls, "<init>", "(I)V");
  if (NULL == midInit) return NULL;

  // Call back constructor to allocate a new instance, with an int argument
  jobject newObj = jenv->NewObject(cls, midInit, number);


  // Try running the toString() on this newly create object
  jmethodID midToString = jenv->GetMethodID(cls, "toString", "()Ljava/lang/String;");
  if (NULL == midToString) return NULL;


  jstring resultStr = (jstring)(jenv->CallObjectMethod(newObj, midToString));
  const char *resultCStr = jenv->GetStringUTFChars(resultStr, NULL);
  std::cout<<"In C++: the number"<<resultCStr <<"\n";

  jclass myclass = jenv->GetObjectClass(jobj);
  jmethodID my_contr = jenv->GetMethodID(myclass, "<init>", "(I)V");
  if (NULL == my_contr) return NULL;

  jobject myobj = jenv->NewObject(myclass, my_contr, (jint)5);

  jmethodID mypopmethod = jenv->GetMethodID(myclass, "Populate_number_array", "(II)V");
  if (NULL == mypopmethod) return NULL;


  jmethodID mygetnum_methodid= jenv->GetMethodID(myclass, "PrintValue", "(I)V");
  if (NULL == mygetnum_methodid) return NULL;

  jenv->CallVoidMethod(myobj, mygetnum_methodid, 4);

  jenv->CallVoidMethod(myobj, mypopmethod, 0, 100);
  jenv->CallVoidMethod(myobj, mypopmethod, 1, 200);
  jenv->CallVoidMethod(myobj, mypopmethod, 2, 300);
  jenv->CallVoidMethod(myobj, mypopmethod, 3, 400);
  jenv->CallVoidMethod(myobj, mypopmethod, 4, 500);


  jenv->CallVoidMethod(myobj, mygetnum_methodid, 4);

  //May need to call releaseStringUTFChars() before return
  return newObj;
}
