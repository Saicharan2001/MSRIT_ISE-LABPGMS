public class Book
{
	String title, author, publisher;
	Double price;
	
	Book(String t, String a, String p, Double x)
	{
		title = t;
		author = a;
		publisher = p;
		price = x;
	}
	 
	public String display()
	{
		return "Book Title " + title + "Author " + author + "publisher " + publisher + "price " + price;
	}
}