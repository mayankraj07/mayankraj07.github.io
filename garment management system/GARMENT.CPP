#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
struct dress
{	
char dressname[50];
int dressid;
char gender[10];
float price;
int qty;
};
class printbill
{
dress a;
public:
void bill();
void reduce(int,int);
};
class modify
{
dress a;
public:
void choice();
void add();
void del();
void modprc();
void modqty();
void display();
};
class search
{
dress a;
public:
void choice();
void nmsearch();
void prcsearch();
void gnsearch();
};
void printbill::bill()
{
clrscr();
int id,q;
double s=0;
char c[5];
strcpy(c,"yes");
while(strcmpi(c,"yes")==0)
{
ifstream x("garment.dat",ios::binary);
cout<<"\nInput id of product :";
cin>>id;
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(a.dressid==id)
{
cout<<"Enter the quantity to buy :";
cin>>q;
if(q<=a.qty)
{
cout<<"\nDressname :"<<a.dressname;
cout<<"\nPrice of one unit :"<<a.price;
s=s+(q*(a.price));
reduce(a.dressid,q);
}
else
cout<<"\nInsufficient quantity";
}
x.read((char*)&a,sizeof(dress));
}
x.close();
cout<<"\nEnter yes if you want to add more amount to bill :";
gets(c);
}
cout<<"\nYour total bill is :"<<s;
getch();
}
void printbill::reduce(int id,int qty1)
{
int qty;
ifstream x("garment.dat",ios::binary);
ofstream y("dress.dat",ios::binary);
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(id==a.dressid)
{
a.qty=a.qty-qty1;
y.write((char*)&a,sizeof(dress));
}
else
y.write((char*)&a,sizeof(dress));
x.read((char*)&a,sizeof(dress));
}
x.close();
y.close();
remove("garment.dat");
rename("dress.dat","garment.dat");
}
void modify::add()
{
clrscr();
ofstream x("garment.dat",ios::app,ios::binary);
cout<<"Enter garment name :";
gets(a.dressname);
cout<<"Enter dressid :";
cin>>a.dressid;
cout<<"Enter gender :";
cin>>a.gender;
cout<<"Enter price of dress :";
cin>>a.price;
cout<<"Enter quantity available in store :";
cin>>a.qty;
x.write((char*)&a,sizeof(dress));
x.close();
getch();
}
void modify::del()
{
int id;
ifstream x("garment.dat",ios::binary);
ofstream y("dress.dat",ios::binary);
cout<<"\nEnter the id to delete :";
cin>>id;
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(a.dressid!=id)
y.write((char*)&a,sizeof(dress));
x.read((char*)&a,sizeof(dress));
}
x.close();
y.close();
remove("garment.dat");
rename("dress.dat","garment.dat");
cout<<"\nRecord deleted";
getch();
}
void modify::modqty()
{
int id,n;
ifstream x("garment.dat",ios::binary);
ofstream y("dress.dat",ios::binary);
cout<<"\nEnter the id to be modified :";
cin>>id;
cout<<"Enter change in quantiy :";
cin>>n;
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(a.dressid==id)
a.qty=a.qty+n;
y.write((char*)&a,sizeof(dress));
x.read((char*)&a,sizeof(dress));
}
x.close();
y.close();
remove("garment.dat");
rename("dress.dat","garment.dat");
cout<<"\nRecord modified";
getch();
}
void modify::modprc()
{
int id,n;
ifstream x("garment.dat",ios::binary);
ofstream y("dress.dat",ios::binary);
cout<<"\nEnter the id to be modified :";
cin>>id;
cout<<"Enter change in price :";
cin>>n;
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(a.dressid==id)
a.price=a.price+n;
y.write((char*)&a,sizeof(dress));
x.read((char*)&a,sizeof(dress));
}
x.close();
y.close();
remove("garment.dat");
rename("dress.dat","garment.dat");
cout<<"\nRecord modified";
getch();
}
void modify::display()
{
clrscr();
ifstream x("garment.dat",ios::binary);
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
cout<<"\nDressname :"<<a.dressname;
cout<<"\nDressid :"<<a.dressid;
cout<<"\nGender :"<<a.gender;
cout<<"\nPrice :"<<a.price;
cout<<"\nQuantity available in store :"<<a.qty;
cout<<endl;
x.read((char*)&a,sizeof(dress));
}
x.close();
getch();
}
void search::nmsearch()
{
clrscr();
char name[10];
cout<<"Input name for search :";
cin>>name;
ifstream x("garment.dat",ios::binary);
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(strcmpi(name,a.dressname)==0)
{
cout<<"\nDressname :"<<a.dressname;
cout<<"\nDressid : "<<a.dressid;
cout<<"\nGender :"<<a.gender;
cout<<"\nPrice :"<<a.price;
cout<<"\nQuantity available in store :"<<a.qty<<endl;
}
x.read((char*)&a,sizeof(dress));
}
x.close();
getch();
}
void search::prcsearch()
{
clrscr();
float prc;
cout<<"Input price for search :";
cin>>prc;
ifstream x("garment.dat",ios::binary);
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(a.price<=prc)
{
cout<<"\nDressname :"<<a.dressname;
cout<<"\nDressid : "<<a.dressid;
cout<<"\nGender :"<<a.gender;
cout<<"\nPrice :"<<a.price;
cout<<"\nQuantity available in store :"<<a.qty<<endl;
}
x.read((char*)&a,sizeof(dress));
}
x.close();
getch();
}
void search::gnsearch()
{
clrscr();
char gn[10];
cout<<"Input gender for search :";
cin>>gn;
ifstream x("garment.dat",ios::binary);
x.read((char*)&a,sizeof(dress));
while(!x.eof())
{
if(strcmpi(a.gender,gn)==0)
{
cout<<"\nDressname :"<<a.dressname;
cout<<"\nDressid : "<<a.dressid;
cout<<"\nGender :"<<a.gender;
cout<<"\nPrice :"<<a.price;
cout<<"\nQuantity available in store :"<<a.qty<<endl;
}
x.read((char*)&a,sizeof(dress));
}
x.close();
getch();
}
void modify::choice()
{
clrscr();
int i=1,opt;
while(i==1)
{
clrscr();
cout<<"\n1: Add";
cout<<"\n2: Delete";
cout<<"\n3: Modify quantity";
cout<<"\n4: Modify price";
cout<<"\n5: Display";
cout<<"\n6: Return to previous menu";
cout<<"\nEnter your option :";
cin>>opt;
if(opt==1)
add();
else if(opt==2)
del();
else if(opt==3)
modqty();
else if(opt==4)
modprc();
else if(opt==5)
display();
else if(opt==6)
return;
else exit(0);
}
}
void search::choice()
{
int i=1,opt;
while(i==1)
{
clrscr();
cout<<"\n1: Search by name";
cout<<"\n2: Search by price";
cout<<"\n3: Search by gender";
cout<<"\n4: Return to previous menu";
cout<<"\nEnter your option :";
cin>>opt;
if(opt==1)
nmsearch();
else if(opt==2)
prcsearch();
else if(opt==3)
gnsearch();
else if(opt==4)
return;
else exit(0);
}
}
void main()
{
clrscr();
printbill a;
modify b;
search c;
int i=1,opt;
while(i==1)
{
clrscr();
cout<<"\n1: Print bill";
cout<<"\n2: Modify record";
cout<<"\n3: Search record";
cout<<"\n4: Exit";
cout<<"\nEnter your option :";
cin>>opt;
if(opt==1)
a.bill();
else if(opt==2)
b.choice();
else if(opt==3)
c.choice();
else exit(0);
}
getch();
}
