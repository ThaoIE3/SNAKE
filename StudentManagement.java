public class StudentManagement
{
    public Student[] std=new Student[100];
    public void removeStudent(String id)
    {
        int count=0;
        int i;
        for ( i = 0; i < std.length; i++)
        {
            if (!std[i].getId().equals(id))
            {
                std[count]=std[i];
                count++;
            }
        }
        for(i=0;i<count;i++)
        {
            System.out.println( std[i].getInfo());
        }
    }

    public void studentByGroup()
    {
        int[] check= new int[std.length];
        int i;
        for(i=0;i<std.length;i++)
        {
            check[i]=0;
        }
        for(i=0;i<std.length;i++)
        {
            if(check[i]==0)
            {
                System.out.println("Thông tin Sinh Viên theo nhóm lớp: " +
                        std[i].getGroup());
                for(int j=i;j<std.length;j++)
                {
                    if(std[i].getGroup().equals(std[j].getGroup()))
                    {
                        System.out.println(std[j].getInfo());
                        check[j]=1;
                    }
                }
            }
        }
    }
    public boolean sameGroup(Student s1, Student s2)
    {
        return s1.getGroup().equals(s2.getGroup());
    }

    public static void main(String[] args)
    {
        Student st1 = new Student();
        st1.setName("Trịnh Thị Thảo");
        st1.setId("17021025");
        st1.setGroup("INT22041");
        st1.setEmail("trinhthithao1999@gmail.com");
        System.out.println("Name: " + st1.getName());
        System.out.println("Thong tin: " + st1.getInfo());

        Student st2 = new Student();
        System.out.println(st2.getInfo());
        Student st3 = new Student("Thảo Ngọc", "1700000", "thao.amc@gmail.com");
        System.out.println(st3.getInfo());
        Student st4 = new Student(st3);
        System.out.println(st4.getInfo());
        StudentManagement sm = new StudentManagement();
        System.out.println(sm.sameGroup(st1, st2));
        int i;
        for(i=0;i<sm.std.length;i++)
        {
            sm.std[i]=new Student();
        }
        System.out.println("Danh sách Sinh Viên: ");
        for(i=0;i<sm.std.length;i++)
        {
            System.out.println("Sinh Viên thứ "+ (i+1));
            Student st = sm.std[i];
            st.Nhapdulieu();
        }
        sm.studentByGroup();
        System.out.println("Thảo cute");
        sm.removeStudent("17021025");
    }
}
