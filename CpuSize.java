import java.util. * ;
import java.io. * ;
import java.io.IOException;
import java.util.Collections;
import java.lang.management. * ;

//MyTree has Node's child and insert function
class MyTree { 
  String inputString = new String();
  Node root;
  int totalnodes = 0;
  int maxheight = 0;
  MyTree() {
    root = null;
  }
  //Insert function
  public Node insert(Node root, String s) {
    if (root == null) {
      root = new Node(s, null, null);
      return root;
    }
    else {
      if (s.compareTo((String)(root.data)) == 0) {
        return root;
      } else if (s.compareTo((String)(root.data)) < 0) root.left = insert(root.left, s);
      else root.right = insert(root.right, s);
      return root;
    }
  }
}
//Node class of BST
class Node {
  Object data;
  Node left;
  Node right;
  int xpos;
  int ypos;
  Node(String x, Node l, Node r) {
    left = l;
    right = r;
    data = (Object) x;
  }
}
public class CpuSize {
    //Function to return the memory size of the list
  public static long getBytesFromList(List list) throws IOException {
    ByteArrayOutputStream baos = new ByteArrayOutputStream();
    ObjectOutputStream out = new ObjectOutputStream(baos);
    out.writeObject(list);
    out.close();
    return baos.toByteArray().length;
  }
  public static void main(String[] args) throws IOException {
    MyTree t = new MyTree();
    ThreadMXBean tmxb = ManagementFactory.getThreadMXBean(); //ThreadMXBean will be used to give CPU time
    long cpuTime1 = tmxb.getThreadCpuTime(Thread.currentThread().getId());
    try {
      Scanner s = new Scanner(new File("customerData.txt"));
      ArrayList < String > list = new ArrayList < String > ();
      while (s.hasNextLine()) {
        list.add(s.next());
      }
      long cpuTime2 = tmxb.getThreadCpuTime(Thread.currentThread().getId());
      System.out.println("CPU time of step1 is " + (cpuTime2 - cpuTime1));
      System.out.println("The memory of ArrayList data structure is " + getBytesFromList(list));
      Scanner input = new Scanner(new File("customerData.txt"));
      while (s.hasNextLine()) {
        t.root = t.insert(t.root, input.next());
      }
      long cpuTime3 = tmxb.getThreadCpuTime(Thread.currentThread().getId());
      System.out.println("CPU time of step1 is " + (cpuTime3 - cpuTime2));
    } catch(IOException e) {}
  }
}
