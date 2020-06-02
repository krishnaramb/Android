public class SummaryReportClass{
  static {
    System.loadLibrary("SummaryReportClass_lib"); // myjni.dll (Windows) or libmyjni.so (Unixes)
 }
  // Native method that calls back the constructor and return the constructed object.
  // Return an Integer object with the given int.
  private native Integer getIntegerObject(int number);
  private final int [] number;
  private int sz;

  public SummaryReportClass(){
    sz = 0;
    number = null;
  }

  public SummaryReportClass(int size){
    sz = size;
    number = new int[size];
  }

  public void Populate_number_array(int index, int val){
    number[index] = val;
  }


  public void PrintValue(int index){
    if (index < 0 || index >= sz) return;
    System.out.println("In java: val: " + number[index]);
  }

  public static void main(String args[]) {
     SummaryReportClass obj = new SummaryReportClass();
     System.out.println("In Java, the number is :" + obj.getIntegerObject(9999));
  }
}
