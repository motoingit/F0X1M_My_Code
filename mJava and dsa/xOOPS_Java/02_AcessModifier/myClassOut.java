
class Employee{
    int id;
    String name;
    private int hidden; //! only by class fuction

    //* Setter */
    public void setId(int id) {
        this.id = id;
    }
    public void setHidden(int hidden) {
        this.hidden = hidden;
    }
    public void setName(String name) {
        this.name = name;
    }

    //* Getter */
    public int getHidden() {
        return hidden;
    }
    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
}


public class myClassOut {
    public static void main(String[] args) {
        Employee mohit = new Employee();
        mohit.id = 324;
        mohit.name = "324";
        mohit.setHidden(000);
    }
}
