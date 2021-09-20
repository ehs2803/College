public class josh {
    boolean[] Persons;
    int Total, Remain, KillOrder;
    
    josh(int total, int remain, int kill) {
        Total = total;
        Remain = remain;
        KillOrder = kill;
        
        Persons = new boolean[Total];
    }

    int next(int cur) {
        cur = (++cur) % Total;
        while(Persons[cur] == false)
            cur = (++cur) % Total;
        return cur;
    }
    
    void run() {
        int i, j;
        int pos = -1;
        for (i = 0; i < Total; i++)
            Persons[i] = true;
        
        for (i = 0; i < Total - Remain; i++) {
            for (j = 1; j <= KillOrder; j++) 
                pos = next(pos);
            
            System.out.print("   === Man deleted is ");
            System.out.println(pos + 1);    // Pos is array index
            Persons[pos] = false;
        }

        for (i = 0; i < Total; i++) 
            if (Persons[i] == true) {
                System.out.print("   *** Man survived is ");
                System.out.println(i + 1);  // i is array index
            }
    }
    
    public static void main(String[] args) {
        new josh(30, 15, 9).run();  /* total number of men, 
                                           			remaining men,
                                           			D-th man killing */
    }
}//25 28 29 1 2 3 4 10 11 13 14 15 17 20 21 