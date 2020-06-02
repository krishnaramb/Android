// Save as "HelloJNI.cpp"
#include <jni.h>       // JNI header provided by JDK
#include <iostream>    // C++ standard IO header
#include "SummaryReportClass.h"  // Generated
using namespace std;

// Implementation of the native method sayHello()

JNIEXPORT jint JNICALL Java_SummaryReportClass_GetSummaryReport(JNIEnv *, jobject){
		int x, y;
		jint sum;
		cout<<" C++: Enter two numbers \n";
		cin>>x;
		cin>>y;
		sum = (jint)(x + y);
		return sum;
	}

	JNIEXPORT jfloat JNICALL Java_SummaryReportClass_GetAverage (JNIEnv* jenv, jobject jobj, jint x, jint y, jint z)
	{
		jfloat average = (x + y + z)/3.0;
		return average;
	}


	JNIEXPORT jfloat JNICALL Java_SummaryReportClass_GetAverageArray (JNIEnv * jenv, jobject jobj, jintArray jarray)
	{
		jint* myarray = jenv->GetIntArrayElements(jarray, NULL);
		if (myarray == nullptr) return 0;
		jint length =  jenv->GetArrayLength(jarray);

		jint sum = 0;
		int i;
		for (i = 0; i < length; i++) {
			sum += myarray[i];
		}
		jdouble average = (jdouble)sum / length;
		jenv->ReleaseIntArrayElements(jarray, myarray, 0); // release resources
		return average;
	}


	JNIEXPORT void JNICALL Java_SummaryReportClass_modifyInstanceVariable (JNIEnv * jenv, jobject jobj)
	{
		// Get a reference to this object's class
		jclass thisClass = jenv->GetObjectClass(jobj);
		// Get the Field ID of the instance variables "number"
		jfieldID fidNumber = jenv->GetFieldID(thisClass, "number", "I");
   if (NULL == fidNumber) return;

	 // Get the int given the Field ID
   jint number = jenv->GetIntField(jobj, fidNumber);

	 cout<<"C++: Int Number val: "<<number << "\n";

	 // Change the variable
	number = 99;
	jenv->SetIntField(jobj, fidNumber, number);




	// Get the Field ID of the instance variables "message"
 jfieldID fidMessage = jenv->GetFieldID(thisClass, "message", "Ljava/lang/String;");
 if (NULL == fidMessage) return;

 // String
	// Get the object given the Field ID
	jstring subObjectJava = (jstring)(jenv->GetObjectField(jobj, fidMessage)); //loook into this one later
	// cout << "C++: " <<message<<"\n";

	}


	JNIEXPORT void JNICALL Java_SummaryReportClass_nativeMethod (JNIEnv * jenv, jobject jobj)
	{
		// Get a class reference for this object
		jclass thisClass = jenv->GetObjectClass(jobj);

		// Get the Method ID for method "callback", which takes no arg and return void
		jmethodID midCallBack = jenv->GetMethodID(thisClass, "callback", "()V");
		if (NULL == midCallBack) return;
		cout<<"In C++, call back Java's callback()\n";


	 // Call back the method (which returns void), baed on the Method ID
    jenv->CallVoidMethod(jobj, midCallBack);

		cout <<"In C++ call back Java's callback(string str) \n";

		jmethodID midCallBack2 = jenv->GetMethodID(thisClass, "callback", "(Ljava/lang/String;)V");
		if (NULL == midCallBack2) return;
		cout<<"In C++, call back Java's callback()\n";

		jstring message = jenv->NewStringUTF("Hello from C");
   	jenv->CallVoidMethod(jobj, midCallBack2, message);

	  cout <<"In C++ call back Java's callback(int n, int m) \n";

	  jmethodID midCallBackAverage = jenv->GetMethodID(thisClass, "callbackAverage", "(II)D");
		if (NULL == midCallBackAverage) return;

		jdouble average = jenv->CallDoubleMethod(jobj, midCallBackAverage, 2, 3); //2 and 3 are the arguments for the fucntion callbackAverage

		cout<<"average from C++: "<< average;




	}
