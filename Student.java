import java.util.Scanner;
public class Student
{
    private String name;
    private String id;
    private String group;
    private String email;

    public String getName()
    {
        return name;
    }
    public void setName(String name)
    {
        this.name=name;
    }
    public String getId()
    {
        return id;
    }
    public void setId(String id)
    {
        this.id=id;
    }
    public String getGroup()
    {
        return group;
    }
    public void setGroup(String group)
    {
        this.group=group;
    }
    public String getEmail()
    {
        return email;
    }
    public void setEmail(String email)
    {
        this.email=email;
    }
    public String getInfo()
    {
        return name+"\t"+id+"\t"+group+"\t"+email;
    }
    public Student()
    {
        name="Student";
        id="000";
        group="INT22041";
        email="uet@vnu.edu.vn";
    }
    public Student(String n, String sid, String em)
    {
        name=n;
        id=sid;
        group="INT22041";
        email=em;
    }
    public Student(Student s)
    {
        this.name=s.name;
        this.id=s.id;
        this.group=s.group;
        this.email=s.email;
    }
    public void Nhapdulieu()
    {
        Scanner input=new Scanner(System.in);
        System.out.println("Nhập tên Sinh Viên: ");
        name=input.nextLine();
        System.out.println("Nhập MSSV: ");
        id=input.nextLine();
        System.out.println("Nhập nhóm lớp : ");
        group=input.nextLine();
        System.out.println("Nhập email: ");
        email=input.nextLine();
    }
}

