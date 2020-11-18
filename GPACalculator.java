import java.util. * ;
public class GPACalculator {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System. in );
    int input = 0;
    int mark[] = new int[3];
    int hour[] = new int[3];
    int id = 0;
    String name = "";
    int age = 0;
    float gpa = 0;
    char grade = 'x';
    while (true) {

      System.out.println("************** GPA Calculator **************");
      System.out.println("1. Enter Student's Information");
      System.out.println("2. Enter Marks and Hour for 3 courses");
      System.out.println("3. Prints student's information and GPA and Grade");
      System.out.println("4. Exit");
      System.out.println("Enter your choice :");
      input = sc.nextInt();

      if (input == 1) {
        System.out.println("****Student's Information****");
        System.out.println("Enter Student ID ");
        id = sc.nextInt();
        System.out.println("Enter Student's Name ");
        name = sc.next();
        System.out.println("Enter Student's Age");
        age = sc.nextInt();
      }
      if (input == 2) {
        for (int j = 0; j < 3; j++) {
          System.out.println("Enter student's marks in course " + (j + 1));
          mark[j] = sc.nextInt();
          System.out.println("Enter hours of course " + (j + 1));
          hour[j] = sc.nextInt();
        }
      }
      if (input == 3) {
        float summary = 0;
        int sumhour = 0;

        for (int j = 0; j < 3; j++) {
          float sum;
          if (mark[j] >= 95 && mark[j] <= 100) sum = (float) 4.00;
          else if (mark[j] >= 90 && mark[j] <= 94) sum = (float) 3.75;
          else if (mark[j] >= 85 && mark[j] <= 89) sum = (float) 3.50;
          else if (mark[j] >= 80 && mark[j] <= 85) sum = (float) 3.00;
          else if (mark[j] >= 75 && mark[j] <= 79) sum = (float) 2.50;
          else if (mark[j] >= 70 && mark[j] <= 74) sum = (float) 2.00;
          else if (mark[j] >= 65 && mark[j] <= 69) sum = (float) 1.50;
          else if (mark[j] >= 60 && mark[j] <= 64) sum = (float) 1.00;
          else sum = (float) 0.00;

          sumhour = sumhour + hour[j];
          summary = summary + (sum * hour[j]);
        }
        summary = (float) summary / sumhour;
        gpa = summary;
        if (gpa >= (float) 3.50 && gpa <= (float) 4.00) grade = 'A';
        else if (gpa >= (float) 2.75 && gpa < (float) 3.50) grade = 'B';
        else if (gpa >= (float) 1.75 && gpa < (float) 2.75) grade = 'C';
        else if (gpa >= (float) 1.00 && gpa < (float) 1.75) grade = 'D';

        System.out.println("Student ID: " + id);
        System.out.println("Student's Name: " + name);
        System.out.println("Student's Age: " + age);
        System.out.println("Student's GPA: " + gpa);
        System.out.println("Student's Grade: " + grade);
        if (id == 0) {
          System.out.println("Empty student's information ! Please enter the student's information first.");
          System.out.println("Empty Marks and hours ! Please enter the student's mark and hours first.");
        }
      }
      if (input == 4) {
        System.exit(0);
      }
    }
  }
}
