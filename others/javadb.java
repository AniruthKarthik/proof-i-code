import java.sql.*;
import java.util.*;

public class javadb{
    public static String url="jdbc:mysql://localhost:3306/javadb";
    public static String user="root";
    public static String pass="pass";

    public static void main(String[] args) throws SQLException {
        Scanner sc=new Scanner(System.in);

        try(Connection con=DriverManager.getConnection(url,user,pass)){
            con.setAutoCommit(false);
            System.out.println("connected successfully");

            boolean transactive=true;

            while (true) {
                System.out.println("\n=== DATABASE MENU ===");
                System.out.println("1. Create (Insert Record)");
                System.out.println("2. Read (Display Records)");
                System.out.println("3. Update Record");
                System.out.println("4. Delete Record");
                System.out.println("5. Execute Custom SQL Query");
                // eg: insert into emp values (?,?);
                System.out.println("6. Start Transaction");
                System.out.println("7. Commit Transaction");
                System.out.println("8. Rollback Transaction");
                System.out.println("9. Exit");
                System.out.print("Enter your choice: ");

                int choice=sc.nextInt();
                sc.nextLine();
                
                try{
                    switch(choice){
                        case 1-> insertRecord(con, sc);
                        case 2->readRecords(con);
                        case 3-> updateRecord(con, sc);
                        case 4-> deleteRecord(con, sc);
                        case 5-> customQuery(con, sc);
                        case 6->{
                            if(!transactive){
                                con.setAutoCommit(false);
                                transactive=true;
                                System.out.println("transaction started");
                            }else{
                                System.out.println("transaction already active");
                            }
                        }
                        case 7 -> {
                            if (transactive) {
                                con.commit();
                                con.setAutoCommit(true);
                                transactive = false;
                                System.out.println("Transaction committed successfully!");
                            } else {
                                System.out.println("No active transaction!");
                            }
                        }
                        case 8 -> {
                            if (transactive) {
                                con.rollback();
                                con.setAutoCommit(true);
                                transactive = false;
                                System.out.println("Transaction rolled back successfully!");
                            } else {
                                System.out.println("No active transaction!");
                            }
                        }
                        case 9 -> {
                            System.out.println("Exiting...");
                            if (transactive) {
                                System.out.println("Rolling back any uncommitted changes...");
                                con.rollback();
                            }
                            con.close();
                            return;
                        }
                        default-> System.out.println("invalid choice");
                    }
                }catch(SQLException e){
                    System.out.println("error:  "+e.getMessage());
                    if(transactive){
                        System.out.println("rolling back current transaction");
                        con.rollback();
                        con.setAutoCommit(true);
                        transactive=false;
                    }
                }
            }
        }
    }
    static void insertRecord(Connection con,Scanner sc)throws SQLException{
        System.out.println("enter id:  ");
        int id=sc.nextInt();
        sc.nextLine();
        System.out.println("enter name: ");
        String name=sc.nextLine();


        String sql="insert into students(id,name)values(?,?)";
        PreparedStatement ps=con.prepareStatement(sql);
        ps.setInt(1, id);
        ps.setString(2, name);
        int rows=ps.executeUpdate();
        System.out.println(rows+" + record inserted");
    }
    
    
    static void readRecords(Connection con)throws SQLException{
        String sql="select * from students";
        PreparedStatement ps=con.prepareStatement(sql);
        ResultSet rs=ps.executeQuery();
        System.out.println("==== STUDENT RECORDS ====");
        while(rs.next()){
            System.out.println("ID: "+rs.getInt("id")+" , Name: "+rs.getString("name"));
        }
    }
    
    static void updateRecord(Connection con,Scanner sc) throws SQLException{
        System.out.print("Enter ID to update: ");
        int id = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter new name: ");
        String name = sc.nextLine();

        String sql = "UPDATE students SET name = ? WHERE id = ?";
        try (PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setString(1, name);
            ps.setInt(2, id);
            int rows = ps.executeUpdate();
            System.out.println(+ rows + " record(s) updated!");
        }
    }
    
    static void deleteRecord(Connection con, Scanner sc) throws SQLException {
        System.out.print("Enter ID to delete: ");
        int id = sc.nextInt();

        String sql = "DELETE FROM students WHERE id = ?";
        try (PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setInt(1, id);
            int rows = ps.executeUpdate();
            System.out.println( rows + " record(s) deleted!");
        }
    }
    
    static void customQuery(Connection con, Scanner sc) throws SQLException {
    System.out.println("Enter your SQL query (use ? for parameters if needed): ");
    String query = sc.nextLine().trim();

    try (PreparedStatement ps = con.prepareStatement(query)) {
        int paramCount = countPlaceholders(query);

        if (paramCount > 0) {
            for (int i = 1; i <= paramCount; i++) {
                System.out.print("Enter value for parameter " + i + ": ");
                String val = sc.nextLine();
                ps.setString(i, val);
            }
        }

        boolean isResultSet = ps.execute();

        if (isResultSet) {
            try (ResultSet rs = ps.getResultSet()) {
                ResultSetMetaData md = rs.getMetaData();
                int cols = md.getColumnCount();

                System.out.println("\n--- QUERY RESULTS ---");
                for (int i = 1; i <= cols; i++) {
                    System.out.print(md.getColumnName(i) + "\t");
                }
                System.out.println("\n-----------------------------------");

                while (rs.next()) {
                    for (int i = 1; i <= cols; i++) {
                        System.out.print(rs.getString(i) + "\t");
                    }
                    System.out.println();
                }
            }
        } else {
            int rows = ps.getUpdateCount();
            System.out.println("Query executed successfully. Rows affected: " + rows);
        }

    } catch (SQLException e) {
        System.out.println("Error executing SQL: " + e.getMessage());
    }
}
    
    static int countPlaceholders(String query) {
        int count = 0;
        for (int i = 0; i < query.length(); i++) {
            if (query.charAt(i) == '?') {
                count++;
            }
        }
        return count;
    }
    
}
