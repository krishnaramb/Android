public class SummaryReportClass {  // Save as HelloJNI.java
   static {
      System.loadLibrary("cplusplus_lib"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
                                   //  at runtime
                                   // This library contains a native method called sayHello()
   }


   // Instance variables
   private int number = 88;
   private String message = "Hello from Java";

    // Declare a native method that calls back the Java methods below
    private native void nativeMethod();


    // To be called back by the native code
    private void callback() {
    System.out.println("In Java");
    }

    private void callback(String message) {
       System.out.println("In Java with " + message);
    }

    private double callbackAverage(int n1, int n2) {
      System.out.println("JAVA: callbackAverage called\n");
      return ((double)n1 + n2) / 2.0;
    }
   // Declare a native method that modifies the instance variables
   private native void modifyInstanceVariable();

   private native int GetSummaryReport();

   private native float GetAverage(int x, int y, int z);

   private native float GetAverageArray(int[] array);

   // Test Driver
   public static void main(String[] args) {
     SummaryReportClass obj = new SummaryReportClass();
      int[] array = new int[]{1, 2, 3, 4,5, 6};
      System.out.println("JAVA: Report is: " + obj.GetSummaryReport());  // Create an instance and invoke the native method
      System.out.println("JAVA: Average is: " + obj.GetAverage(5, 4, 4));
      System.out.println("JAVA: avgArray is: " + obj.GetAverageArray(array));
      obj.modifyInstanceVariable();
      System.out.println("JAVA: member varaialbe number: " + obj.number);
      obj.nativeMethod();
   }
}
