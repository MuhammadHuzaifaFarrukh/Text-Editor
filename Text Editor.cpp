#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void menu(int msg);

int main()
{
    menu(0);
    return 0;
}

void menu(int msg)
{
    system("CLS");
    if(msg==0)
    {
        cout<<"Welcome to Text Editor"<<endl<<endl;
    }
    if(msg==1)
    {
        cout<<"File Created Successfully"<<endl<<endl;
    }
    if(msg==2)
    {
        cout<<"File Updated Successfully"<<endl<<endl;
    }
    if(msg==4)
    {
        cout<<"File Emptied Successfully"<<endl<<endl;
    }
    if(msg==5)
    {
        cout<<"File Deleted Successfully"<<endl<<endl;
    }
    if(msg==55)
    {
        cout<<"File Not Found / Exist "<<endl<<endl;
    }
    if(msg==6)
    {
        cout<<"File Copied Successfully"<<endl<<endl;
    }
    if(msg==7)
    {
        cout<<"Deletion is Successful"<<endl<<endl;
    }
    if(msg == 8)
    {
        cout<<"Your Word was not Found"<<endl<<endl;
    }


    cout<<"Main Menu"<<endl;
    cout<<"-------------"<<endl;
    cout<<"1. Create File"<<endl;
    cout<<"2. Add to File"<<endl;
    cout<<"3. Read from File"<<endl;
    cout<<"4. Empty File"<<endl;
    cout<<"5. Delete File"<<endl;
    cout<<"6. Copy File"<<endl;
    cout<<"7. Delete Some Contents"<<endl<<endl;
    cout<<"8. Exit"<<endl<<endl;
    cout<<"Enter Choice: ";

    int choice = 0;
    string filename;
    string text;

    cin>>choice;
    if(choice==1)
    {
        cout<<endl<<"Enter name of file: ";
        cin.ignore();
        getline(cin, filename);
        ofstream myfile( (filename+".txt"));


        myfile.close();
        menu(1);
        //cin>>choice;
    }
    if(choice==2)
    {
        text="";
        cout<<endl<<"Enter name of file: ";
        cin>>filename;
        cout<<endl<<"Enter text to write to file: (Enter END to complete)"<<endl;
        ofstream myfile;
        myfile.open((filename+".txt"),ios::app);

        string line;
        cin.ignore();	 // (Ignore the Buffer(Temperory contents)
        while (getline(cin, line))
        {
            if(line.size()>=3)
            {
                if (line.substr(line.size() - 3) == "END") //Specifying that whenever END is typed stop reading data eof//
                {
                    text += line.substr(0, line.size()-3);// 0 is position of 1st chracter ,line.size is the total length, 3 is size of END//
                    break;
                }
                else
                {
                    text += line+"\n";
                }
            }
            else
            {
                text += line+"\n";
            }
        }
        myfile<<text;
        myfile.close();
        menu(2);
        //cin>>choice;
    }
    if(choice==3)
    {
        text="";
        cout<<endl<<"Enter name of file: ";
        cin>>filename;
        fstream myfile;
        myfile.open((filename+".txt"));
        if(!myfile)
        {
            menu(55);
        }

        while(getline(myfile, text))
        {
            cout << text << "\n";
        }
        myfile.close();
        char now;
        cout<<endl<<"End of File. Press any key for main menu: ";
        cin>>now;
        menu(2);
        //cin>>choice;
    }
    if(choice==4)
    {
        cout<<endl<<"Enter name of file: ";
        cin>>filename;
        ofstream myfile;
        myfile.open((filename+".txt"));
        myfile<<"";
        myfile.close();
        menu(4);
        cin>>choice;
        //cin>>choice;
    }
    if(choice==5)
    {
        cout<<endl<<"Enter name of file: ";
        cin>>filename;
        if (remove((filename+".txt").c_str())==0) // Here .c_str() is necessary as .remove() takes a const char * whereas for opening file , string can also work //
        {
            menu(5);
        }
        else
        {
            menu(55);
        }
    }
    if(choice==6)
    {
        text="";
        cout<<endl<<"Enter name of file to copy from: ";
        cin.ignore();
        getline(cin, filename);
        fstream myfile( (filename+".txt") );
        if(!myfile)
        {
            menu(55);
        }
        string line;
        while(getline(myfile, line))
        {
            text += line+"\n";
        }
        myfile.close();
        cout<<endl<<"Enter name of file to copy to: ";
        string second;
        getline(cin, second);
        ofstream myfile2;
        myfile2.open((second+".txt"),ios::app);
        myfile2<<text;
        myfile2.close();
        menu(6);
        //cin>>choice;
    }
    if(choice==7)
    {

        cout<<endl<<"Enter name of file to delete something from: ";

        cin.ignore();
        getline(cin, filename);
        ifstream myfile( (filename+".txt") );

        if(!myfile)
        {
            menu(55);
        }

        // Step 1: Read the file's content into memory
        string fileContent;
        string line;

        while (getline(myfile, line))
        {
            fileContent += line + "\n";
        }
        myfile.close();

        // Step 2: Modify the content in memory
        cout<<endl<<"Write text what you want to remove from your file: ";
        string toRemove ;
        cin>>toRemove;
        size_t pos = fileContent.find(toRemove);
        if (pos != string::npos)
        {
            fileContent.erase(pos, toRemove.length());
        }
        else
        {
            menu(8);
        }

        // Step 3 & 4: Overwrite the file with the modified content
        ofstream outFile((filename+".txt"), ios::trunc);

        outFile << fileContent;
        outFile.close();
        menu(7);
        //cin>>choice;
    }
    if(choice==8)
    {
        exit(EXIT_SUCCESS);
    }
}
