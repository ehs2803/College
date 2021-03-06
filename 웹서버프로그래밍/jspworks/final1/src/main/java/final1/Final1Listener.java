package final1;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

/**
 * Application Lifecycle Listener implementation class Final1Listener
 *
 */
@WebListener
public class Final1Listener implements ServletContextListener {

    /**
     * Default constructor. 
     */
    public Final1Listener() {
        // TODO Auto-generated constructor stub
    }

	/**
     * @see ServletContextListener#contextDestroyed(ServletContextEvent)
     */
    public void contextDestroyed(ServletContextEvent sce)  { 
         // TODO Auto-generated method stub
    }

	/**
     * @see ServletContextListener#contextInitialized(ServletContextEvent)
     */
    public void contextInitialized(ServletContextEvent sce)  { 
         // TODO Auto-generated method stub
    	ServletContext ctx = sce.getServletContext();
    	List<BookBean> books = new ArrayList<BookBean>();
    	books.add(new BookBean("미드나잇라이브러리","매크헤이그","인플루엔셜"));
    	books.add(new BookBean("자바웹프로그래밍","황희정","한빛아카데미"));
    	
    	String []strs = {"소설","역사","인문","정치","미술","종교","여행","과학","만화","건강"};
    	ctx.setAttribute("strs", strs);
    	ctx.setAttribute("books", books);
    }
	
}
