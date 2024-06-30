import java.util.*;
import java.io.*;

class packer
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("_____________________Marvellous Packer Unpacker____________");
        System.out.println("Packing Activity of Application is started....");
        System.out.println("Enter the name of folder which contains the file that you want to pack : ");

        String FolderName = sobj.nextLine();

        File fobj = new File(FolderName);
        String Header = null;

        System.out.println("Enter the name of packed file that you want to create : ");
        String PackFile = sobj.nextLine();

        byte Buffer[] = new byte[1024];
        int iRet = 0;
        int PackCount = 0;
        try
        {
            File Packobj = new File(PackFile);
            boolean bRet = Packobj.createNewFile();
            if(bRet == false)
            {
                System.out.println("Unable to create packed file");
                return;
            }
            System.out.println("Packed file gets successfully created in your current Directory");

            FileOutputStream outobj = new FileOutputStream(Packobj);

            bRet = fobj.isDirectory();
            if(bRet == true)
            {
                File list[] = fobj.listFiles();
                System.out.println("Total number of files found in the directory are :"+list.length);
                for(int i = 0; i< list.length; i++)
                {
                    if((list[i].getName()).endsWith(".txt"))
                    {
                        Header = list[i].getName() + " " + list[i].length();
                        for(int j = Header.length(); j < 100; j++)
                        {
                            Header = Header + " ";
                        }

                        byte bHeader[] = Header.getBytes();
                        outobj.write(bHeader,0,bHeader.length);

                        FileInputStream inobj = new FileInputStream(list[i]);

                        // Loop to write the data
                        while((iRet = inobj.read(Buffer)) != -1)
                        {
                            outobj.write(Buffer,0,iRet);
                        }
                        System.out.println("File Successfully packed with name :"+list[i].getName());

                        inobj.close();
                        PackCount++;
                    }
                }
                System.out.println("___________Packing Summary_____________");
                System.out.println("Total numbers of Files Scanned : "+list.length);
                System.out.println("Total number of Files packes : "+PackCount );

                System.out.println("Thank you for Using Marvellous Packer Unpacker...");

            }            
        }
        catch(Exception iobj)
        {
            System.out.println("Exception occured : "+iobj);
        }
    }
}