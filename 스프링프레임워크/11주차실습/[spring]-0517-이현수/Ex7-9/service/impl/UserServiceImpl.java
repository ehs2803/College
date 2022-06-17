package myapp.service.impl;
import java.util.List;  
import myapp.dao.UserDao;  
import myapp.domain.User;  
import myapp.service.UserService;  

public class UserServiceImpl implements UserService {   
    private UserDao userDao;    
    public void setUserDao(UserDao userDao) {   this.userDao = userDao;  }  

    public void save(User user) {  
        userDao.save(user);  
    }  
    public void update(User user) {  
        userDao.update(user);  
    }  
    public void delete(int id) {  
        userDao.delete(id);  
    }  
    public User getById(int id) {  
        return userDao.findById(id);  
    }  
    public List<User> getAll() {  
        return userDao.findAll();  
    }  
} 
