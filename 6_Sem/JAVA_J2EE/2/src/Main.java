import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main 
{
	public static void main(String[] args)
	{	
		ArrayList<Book> books=new ArrayList<Book>();
		books.add(new Book("Dbms basics", "auth1", "pub1", 10.00));
		books.add(new Book("Dbms", "auth2", "pub2", 222.00));
		books.add(new Book("Java J2EE", "auth3", "pub3", 123.566));
		books.add(new Book("Machine Learning","auth4","pub4",567.56));
		System.out.println();
		for (Book b:books)
		{
			System.out.println(b.title + " " + b.author + " "+b.publisher+ " "+ b.price);
		}
		ArrayList<Book> sorted_books=new ArrayList<Book>(books);
		System.out.println();
		System.out.println("Sorting the books");
		Collections.sort(sorted_books,new BookCompare());
		for (Book b:sorted_books)
		{
			System.out.println(b.title + " " + b.author + " "+b.publisher+ " "+ b.price);
		}
		
		System.out.println();
		System.out.println("Adding unique id to the book");
		HashMap<Integer, Book> book_list_with_ids = new HashMap<Integer,Book>();
		int i=0;
		for (Book b:sorted_books)
		{
			book_list_with_ids.put(i, b);
			i++;
		}
		
		for(Map.Entry<Integer, Book> entry: book_list_with_ids.entrySet())
		{
			System.out.println("ID is"+entry.getKey());
			Book temp=entry.getValue();
			System.out.println(temp.title + " " + temp.author + " "+temp.publisher+ " "+ temp.price);
		}
	
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the author name to search");
		String search_text=sc.nextLine();
		System.out.println();
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			if(s.getValue().author.equals(search_text))
				System.out.println(s.getValue().title+""+s.getValue().publisher+""+s.getValue().price);
	
		}
		System.out.println();
		
		System.out.println("Enter price");
		double t=sc.nextDouble();
		System.out.println();
		ArrayList<Book> new_book_list_price = new ArrayList<Book>();
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			if(s.getValue().price > t)
				new_book_list_price.add(s.getValue());
		}
//		System.out.println();
		for (Book b:new_book_list_price)
		{
			System.out.println(b.title + " " + b.author + " "+b.publisher+ " "+ b.price);
		}
		System.out.println();
		
		System.out.println("Enter the book title to search");
		String te=sc.next();
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			if(s.getValue().title.contains(te))
				System.out.println(s.getValue().author+""+s.getValue().title+""+s.getValue().publisher+""+s.getValue().price);
	
		}
		System.out.println();
		
		System.out.println("Enter the name of the publisher");
		String tem=sc.next();
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			if(s.getValue().publisher.contains(tem))
				System.out.println(s.getValue().author+""+s.getValue().title+""+s.getValue().publisher);
	
		}
		System.out.println();
		
		System.out.println("Enter the book title whose publisher needs to be updated");
		String teme=sc.next();
		System.out.println("Enter the new publisher details");
		String new_pub=sc.next();
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			if(s.getValue().title.equals(teme))
			{
				s.getValue().publisher=new_pub;
				System.out.println(s.getValue().author+""+s.getValue().title+""+s.getValue().publisher);
			}
		}
		System.out.println();
		System.out.println("After updating with new publisher details");
		for(Map.Entry<Integer, Book> s:book_list_with_ids.entrySet())
		{
			System.out.println(s.getValue().author+""+s.getValue().title+""+s.getValue().publisher);
		}
	}
}



// public class FirstProg {

//     static HashMap<Integer, Book> hmbook = new HashMap<Integer, Book>();
//     static Scanner sc = new Scanner(System.in);
//     static void BookHashMap(ArrayList<Book> barr)
//     {
//         int i = 1;
//         for(Book b1:barr)
//         {
//             hmbook.put(i, b1);
//             i++;
//         }
//     }
//     static void printHashMap()
//     {
//         Set<Map.Entry<Integer, Book>> set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             System.out.println(s.getKey());
//             System.out.println(s.getValue());
//         }
//     }
//     static void printBookData(Book b)
//     {
//         String str= "Book has "+b.title+" title whose author is "+b.author;
//         str+="\n Book is published by "+b.publisher;
//         str+="\n Price is= "+b.price;
//         System.out.println(str);
//     }
//     static void Read_data(ArrayList<Book> barr)
//     {
//     while(true)
//         {
//         System.out.println("Do u want to enter book details? Mention yes/no");
//         String val = sc.nextLine();
//         if(val.toUpperCase().equals("YES"))
//         {
//             System.out.println("Enter Book Details");
//             System.out.println("Enter Title");
//             String title =sc.nextLine();
//             System.out.println("Enter Author");
//             String author = sc.nextLine();
//             System.out.println("Enter Publisher");
//             String pub = sc.nextLine();
//             System.out.println("Enter Price");
//             double price = Double.parseDouble(sc.nextLine());
//             Book b1 = new Book(title,author,pub,price);
//             barr.add(b1);
//         }
//         else
//         {
//             break;
//         }
//     }
//     }
//     static boolean isSubString(String s1, String s2)
//     {
//         int M = s1.length();
//         int N = s2.length();
//         for(int i = 0; i<= N-M; i++)
//         {
//             int j;
//             for(j=0; j<M; j++)
//             if (s2.charAt(i+j)!=s1.charAt(j))
//             break;
//             if (j==M)
//             return false;
//         }
//         return true;
//     }
//     public static void main(String[] args)
//     {
//     // TODO Auto-generated method stub
//         ArrayList<Book> arbook = new ArrayList<Book>();
//         Read_data(arbook);
//         ArrayList<Book> clone = (ArrayList<Book>) arbook.clone();
//         ArrayList<Book> booklist = clone;
//         booklist.sort(new BookCompare());
//         System.out.println("Before sorting");
//         System.out.println(arbook);
//         System.out.println("After sorting");
//         System.out.println(booklist);
//         System.out.println("Enter author name");
//         String aut_name = sc.nextLine();
//         BookHashMap(booklist);
//         Set<Map.Entry<Integer,Book>> set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             Book b1=s.getValue();
//             String s1 =b1.author;
//             if(s1.equals(aut_name))
//             {
//                 printBookData(s.getValue());
//             }
//         }
//         LinkedList<Book> lbook = new LinkedList<Book>();
//         System.out.println("To list all books with price greater than a value, enter a price");
//         double pri = Double.parseDouble(sc.nextLine());
//         set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             Book b1=s.getValue();
//             if(b1.price>pri)
//             {
//                 lbook.add(b1);
//             }
//         }
//         System.out.println("Books with price > than "+pri);
//         for(Book b:lbook)
//         {
//             System.out.println(b);
//         }
//         System.out.println("enter a part of a publishers name");
//         String p = sc.nextLine();
//         set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             Book b1=s.getValue();
//             if(isSubString(b1.title,p))
//             {
//                 printBookData(b1);
//             }
//         }
//         System.out.println("enter a publishers name to print book details");
//         String p1 = sc.nextLine();
//         set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             Book b1=s.getValue();
//             if(b1.publisher.equals(p1))
//             {
//                 printBookData(b1);
//             }
//         }
//         System.out.println("enter a title whose publisher is to be updated");
//         String t = sc.nextLine();
//         System.out.println("enter the updated publishers name");
//         String p2 = sc.nextLine();
//         set = hmbook.entrySet();
//         for(Map.Entry<Integer, Book> s:set)
//         {
//             Book b1=s.getValue();
//             if(b1.title.equals(t))
//             {
//                 b1.publisher=p2;
//                 hmbook.put(s.getKey(), b1);
//                 printBookData(b1);
//             }
//         }
//         printHashMap();
//     }
// }