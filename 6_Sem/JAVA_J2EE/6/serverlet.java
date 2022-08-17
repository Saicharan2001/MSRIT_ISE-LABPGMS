//import javax.servlet.*;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
/**
 * Servlet implementation class serverlet
 */
public class serverlet extends HttpServlet {
private static final long serialVersionUID = 1L;
public serverlet() {
super();
}
    /**
     * @see HttpServlet#HttpServlet()
     */
//    public serverlet() {
//        super();
//        // TODO Auto-generated constructor stub
//    }

/**
* @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
*/
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
// TODO Auto-generated method stub
String name=request.getParameter("name");
String gender=request.getParameter("gender");
String salary=request.getParameter("salary");
String tax=request.getParameter("tax");
response.getWriter().append("\nName: " + name).append("\nGender: " + gender).append("\nSalary: " + salary)
        .append("\nDeduction: ").append("\nIncomeTax: " + tax);

        String newFile = new File("data.txt").getAbsolutePath();
        System.out.println("File:" + newFile);

        PrintWriter pw = new PrintWriter("data.txt");
        pw.println("Name: " + name);
        pw.println("Gender: " + gender);
        pw.println("Salary: " + salary);
        pw.println("IncomeTax: " + tax);

        pw.close();
// PrintWriter out=response.getWriter();
// File file = new File("/home/mahen/1.txt");
// file.createNewFile();
// FileOutputStream fout = new FileOutputStream(file);
// out.println(""+name+gender+salary+tax);
// fout.write(("hello"+name+gender+salary+tax).getBytes());
// fout.close();
// response.getWriter().append("Served at: ").append(request.getContextPath());
}

/**
* @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
*/
protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
// TODO Auto-generated method stub
doGet(request, response);
}

}
