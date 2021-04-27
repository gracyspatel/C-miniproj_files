#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
class abc{
            int no;
            long long c_no;
            string name;

            int input();
            void output();

            void add();
                //void asc();
            void del();
                void delet();
                void delet2();
            void modify();
            void dis();
                void display1();
                void display2();
            int check(int);

        public:
            abc()
            {
                no=0;
                c_no=0;
                name="nil";
            }
            ~abc()
            {
                system("cls");
                cout<<endl<<endl<<"Thank you for entering details"<<endl;
            }
            void menu();  //menu
         };

int main()
{
    abc o1;
    o1.menu();
    return 0;
}
int abc :: input()
{
    int a1,ex;
        cout<<"Enter the details : "<<endl;
        cout<<"No : "<<endl;
        cin>>no;
        ex=no;
        a1=check(ex);
        if(a1==0)
        {
        no=ex;
        cout<<"Name : "<<endl;
        cin>>name;
        cout<<"Contact No:"<<endl;
        cin>>c_no;

        return 0;
        }

        return 1;
}
void abc :: output()
{
        cout<<"Details : "<<endl;
        cout<<"No : \t";
        cout<<no<<endl;
        cout<<"Name : \t";
        cout<<name<<endl;
        cout<<"Contact No: \t";
        cout<<c_no<<endl;
        cout<<endl;
        /*cout<<"Do you want to add another details(y/n)"<<endl;
        cin>>ch;*/
}
void abc :: menu()
{
    int n;

    while(n!=5)
    {
    //system("cls");
    cout<<"MAIN MENU:"<<endl;
    cout<<"1. "<<"Add"<<endl;
    cout<<"2. "<<"Delete"<<endl;
    cout<<"3. "<<"Modify"<<endl;
    cout<<"4. "<<"Display"<<endl;
    cout<<"5. "<<"Exit"<<endl;
    cin>>n;

        switch(n)
        {
        case 1: add();
               // asc();
               system("cls");
                break;
            case 2: del();
                break;
            case 3: modify();
                break;
            case 4: dis();
                break;
            case 5:
                break;
            default :
                {
                    cout<<"Wrong choice!!!"<<endl;
                    cout<<"Press any key to continue"<<endl;
                }
        }
    }
}
void abc :: del()
{
    int n1;
    cout<<"1. "<<"Delete elements by details"<<endl;
    cout<<"2. "<<"Delete all"<<endl;
    cin>>n1;

    if(n1 == 1)
        delet();
    else
        if( n1 == 2)
            delet2();
    else
        cout<<"Wrong choice"<<endl;
}
void abc :: add()
{
    system("cls");
    ofstream f1;
    int y=-1;
    f1.open("Details.txt",ios::app);
    char ch='y';

    while(f1)
    {
        if( ch == 'n' )
        {
            no=-1;
            break;
        }

        y=input();
        cout<<"Do you want to add another details(y/n)"<<endl;
        cin>>ch;

                if( y == 1 )
                    continue;

        f1<<endl<<no<<endl<<name<<endl<<c_no<<endl;

    }

    f1.close();
}
int abc :: check( int a )
{
    int flag1=0;
    ifstream f3;
  f3.open("Details.txt");
  f3.seekg(0);

  f3>>no>>name>>c_no;
  while(f3)
  {
      if( no == a )
      {
          cout<<"Number exists"<<endl;
          flag1=1;
          break;
      }
      else
        if( no == -1)
        {
            flag1=0;
            break;
        }
        f3>>no>>name>>c_no;
  }
  return flag1;
}
void abc :: dis()
{
    system("cls");
    int p=0;

    cout<<"Display"<<endl;
    cout<<"1. "<<"Details by number"<<endl;
    cout<<"2. "<<"Display all"<<endl;
    cin>>p;

    if( p==1 )
    {
        system("cls");
        display1();
    }
    else
    {
        system("cls");
        display2();
    }
}
void abc :: display1()
{
    ifstream f2;
    f2.open("Details.txt");
    f2.seekg(0);

    int np,flag4=-1;
    cout<<"Enter number get the details :"<<endl;
    cin>>np;

    while(f2)
    {
       f2>>no;
       f2>>name;
       f2>>c_no;
       // cout<<no;
       if( no == np )
       {
           cout<<endl;
           output();
           flag4=1;
           //cout<<no<<endl<<name<<endl<<c_no<<endl;
           break;
       }
       else
       {
           flag4=0;
       }

    }

    if( flag4 == 0 )
    {
        cout<<"No such no exist"<<endl;
    }

    f2.close();
}
void abc :: display2()
{
    ifstream f3;
    f3.open("Details.txt");
    f3.seekg(0);

    f3>>no;

    while(f3)
    {
       if( no == -1 )
            break;
       else
        {
            f3>>name;
            f3>>c_no;
            output();
        }

        f3>>no;
    }

    f3.close();
}
void abc :: delet()
{
    system("cls");
    int n,i;
    cout<<"Enter number to delete the details"<<endl;
    cin>>n;

    i=check(n);

 if(i==1)
 {
    ifstream f3;
    ofstream fo;

    f3.open("Details.txt");
    f3.seekg(0);
    fo.open("Det.txt",ios::out);
        f3>>no;

        while(f3)
        {
            if( no == n )
            {
                f3>>name;
                f3>>c_no;
                cout<<"So,Details deleted successfully"<<endl;
                f3>>no;
                continue;
            }

            if( no == -1 )
                break;
            else
            {
                fo<<endl<<no<<endl;
                f3>>name;
                fo<<name<<endl;
                f3>>c_no;
                fo<<c_no<<endl;
                //output();
            }
            f3>>no;
        }
    fo.close();
    f3.close();

    remove("Details.txt");
    rename("Det.txt","Details.txt");
    }
    else
    {
        cout<<endl<<"No such number"<<endl;
    }

}
void abc :: delet2()
{
    system("cls");
    ofstream of;
    ifstream iif;

    of.open("Details.txt");
    iif.open("D.txt");
    of.close();
    iif.close();

    remove("Details.txt");
    rename("D.txt","Details.txt");
}
void abc :: modify()
{

    system("cls");
    int n,i;
    cout<<"Enter number whose data is to be modified"<<endl;
    cin>>n;

    i=check(n);

 if(i==1)
 {
    ifstream f3;
    ofstream fo;

    int n1;
    f3.open("Details.txt");
    f3.seekg(0);
    fo.open("Det.txt",ios::out);
        f3>>no;

        while(f3)
        {
            if( no == n )
            {
                f3>>name;
                f3>>c_no;
                cout<<"Change"<<endl;
                cout<<1.<<" Name"<<endl;
                cout<<2.<<" Contact Number"<<endl;
                cin>>n1;
                if(n1 == 1)
                {
                    cout<<"Name : "<<endl;
                    cin>>name;
                    fo<<endl<<no<<endl;
                    fo<<name<<endl;
                    fo<<c_no<<endl;

                    cout<<"So,Data modified successfully"<<endl;
                }
                else
                    if(n1 == 2)
                {
                    cout<<"Contact No:"<<endl;
                    cin>>c_no;
                    fo<<endl<<no<<endl;
                    fo<<name<<endl;
                    fo<<c_no<<endl;

                    cout<<"So,Data modified successfully"<<endl;
                }
                else
                {
                    cout<<"Wrong choice!!!"<<endl;
                }
                f3>>no;
                continue;
            }

            if(no==-1)
                break;
            else
            {
                fo<<endl<<no<<endl;
                f3>>name;
                fo<<name<<endl;
                f3>>c_no;
                fo<<c_no<<endl;
                //output();
            }
            f3>>no;
        }
    fo.close();
    f3.close();

    remove("Details.txt");
    rename("Det.txt","Details.txt");
    }
    else
    {
        cout<<endl<<"No such number"<<endl;
    }
}

/*void abc :: asc()
{
    ifstream fy;
    fy.open("Details.txt");

    ofstream ft;
    ft.open("temp.txt",ios::app);

    int n=1;
    fy>>no;

    while(fy)
    {
        if(no==-1)
            break;

        fy>>name;
        fy>>c_no;
        //cout<<no<<name<<c_no;
        while(no!=-1)
        {
            if(n>no)
            {
                n=no;
            }
            cout<<no;
            fy>>no>>name>>c_no;
        }

        fy.seekg(0);
        if(no==n)
        {
            cout<<endl<<no<<endl<<name<<endl<<c_no<<endl;
            n=no;
        }
        fy>>no;
    }

    fy.close();
    ft.close();

    remove("Details.txt");
    rename("temp.txt","Details.txt");
}*/
