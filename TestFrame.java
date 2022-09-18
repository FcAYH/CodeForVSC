import java.awt.*; 

public class TestFrame
 {
  public static void main( String args[])   //创建标题My Frame Test的窗口容器对象实例  
   { 
       Frame f = new Frame("My Frame Test");
        f.setSize( 170,100);  //设臵Frame组件窗口大小（宽﹑高）  
        f.setBackground( Color.blue);  //设臵Frame组件背景色为蓝色       
        f.setVisible( true);  //设臵Frame组件为可视  
     }
}
