package ISE;
import ISE.ISE_Dept;
public class MainClass {
    public static void main(String[] args) {
        ISE_Dept ise = new ISE_Dept();
        ise.readData();
        ise.number_of_reasearch_projs();
        ise.print_number_designations();
        ise.exp_greater_20();
    }
}
