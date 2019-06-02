    /*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
				RESTAURANT AHAR
      WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
	      PROJECT BY: NIRBHAY VASHISHT
	      CLASS     : XII-C
	      ROLL NO.  : 14
     */
//+++++++++++++++++++++++++++++
//********HEADER FILES*********
//+++++++++++++++++++++++++++++
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
//+++++++++++++++++++++++++
//*****GLOBALVARIABLES*****
//+++++++++++++++++++++++++
int choiceF1; //for first options ie. to choose entering or viewing or ordering
int choiceF;  //for choosing snacks etc
int  cno=0;                     // a variable for no. of customers
int  add;
int  lag=0;
char   cons_id[21];            // a variable for consumer id which is to be searched
char   met_id[21];             // a variable for meter id which is to be searched
char   del_id[21];             // a variable for consumer id which is to be deleted
char   bill_id[21];            // a variable for consumer id for which bill is to be generated
char ch0;
char pass_o[30];
char pass[]="abc12";

//+++++++++++++++++++++++++
//********FUNCTIONS********
//+++++++++++++++++++++++++
void ahar();
void startdesign();
void catag();
void loading();
void border();
void password();
//+++++++++++++++++++++++++
//********CLASSES**********
//+++++++++++++++++++++++++
class subcat
	{
	public:
	int itm;         //item code
	int qnty;        //quantity bought
	char nam[50];
	int rate;
	}cart[50];
class c : public subcat                 //categories;
	{
	public:
	char name[20];
	subcat var[20]; //var for varitey
	int num;         //stores d no. of itm's in a category
	}cat[10];   //main catagories

class addr
 {
   public:
     unsigned long house_no;
     char locality[21];
     char city[21];
     char state[21];
     unsigned long pin;
 };
class consumer     // addr should be inherited or not || ans:no
 {
   private:

     char name[21];
     char consumer_id[21];
     char meter_id[21];
     addr address;
     unsigned long int phone_no;

   public:

     void input(int);
     void output(int);


     char*    get_consumer_id()   { return consumer_id; }
     char*    get_meter_id()      { return meter_id; }

 }obj;
      ofstream fout;
       ifstream fin;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//************************STARTING WITH MAIN**********************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void main()
{

int choi,choic;
int cal=0,choice3=0,total=0;
	clrscr();
ahar();
	clrscr();
password();
	clrscr();
border();        //*********FUNCTION FOR BORDER**********

	gotoxy(3,3);
	cout<<"CHOOSE ONE OF THE FOLLOWING OPTION TO CONTINUE :-\n";
	gotoxy(3,4);
	cout<<"1. Place Order\n";
	gotoxy(3,5);
	cout<<"2. Enter details of the customer\n";
	gotoxy(3,6);
	cout<<"3. View details of a customer\n";
	gotoxy(25,16);
	cout<<"|-----------------------|\n";
	gotoxy(25,17);
	cout<<"| Enter your choice :   |\n";
	gotoxy(25,18);
	cout<<"|-----------------------|";
	gotoxy(47,17);

	cin>>choiceF1;

switch(choiceF1)
{   case 1:
	   do{  int choice2=-1;    //for choosing sub snacks or home or exit or procceed billing

		clrscr();
		catag();	 //*********FUNCTION FOR CATEGORIES**********
		clrscr();
		border();        //*********FUNCTION FOR BORDER**********


		gotoxy(3,3);
		cout<<"Choose any one of the categories \n";
		for(int i=1;i<=8;i++)       //printing categories
		{
			for(int k=4;k<=i+3;k++)
			{
			gotoxy(1,k);
			cout<<"|  ";
			}
			cout<<i<<". ";
			cout<<cat[i].name;
			cout<<"\n";
		}

			cout<<"|     ";
			gotoxy(25,16);
			cout<<"|-----------------------|\n";
			gotoxy(25,17);
			cout<<"| Enter your choice :   |\n";
			gotoxy(25,18);
			cout<<"|-----------------------|";
			gotoxy(47,17);

			cin>>choiceF; //For choosing snacks etc
			clrscr();
			gotoxy(18,23);
			cout<<"Home=0       End=100       Proceed Billing=99";
			gotoxy(1,5);
			cout<<"_______________________________________________________________________________";
			cout<<"\n   SNo.  |         Price         |                Descripition               ";
			cout<<"\n---------|-----------------------|---------------------------------------------\n";


			for(i=1;i<=cat[choiceF].num;i++)  //displaying subdivisions
			{       gotoxy(5,i+7);
				cout<<i<<".   |          ";
				cout<<cat[choiceF].var[i].rate;
				cout<<"          |             ";
				puts(cat[choiceF].var[i].nam ) ;
			}

			cout<<"_________|_______________________|_____________________________________________";
			gotoxy(1,4);
			cout<<"Choose the products you want to buy:-\n";
			for(int j=1;j<80;j++)
			{
				delay(5);
				gotoxy(j,1);         //]
				cout<<"X";           //]  Design for top border
					gotoxy(j,2); //]
					cout<<"X";   //]

				gotoxy(j,25);              //]
				cout<<"X";                 //] Design for bottom border
					gotoxy(j,24);      //]
					cout<<"X";         //]
			}

			while(choice2!=0&&choice2!=100&&choice2!=99)
			{
				static i=1;
				gotoxy(25,20);
				cout<<"Enter your choice : "    ;
				cin>>choice2;
					if(choice2!=0&&choice2!=100&&choice2!=99)
					{
						cart[i]=cat[choiceF].var[choice2];
						gotoxy(25,21);
						cout<<"Enter the Quantity: ";
						cin>>cart[i].qnty;
						total=cart[i].rate*cart[i].qnty+total;
						cal++;
						i++;
					}
			}
			if(choice2==99)        //choice is bill=99
			{
				clrscr();
				loading();
				gotoxy(35,1);
				cout<<"BILL\n";
				cout<<"_______________________________________________________________________________";
				cout<<"\nSNo.     |    Price    |   Quantity   |           Item descripition"          ;
				cout<<"\n---------|-------------|--------------|----------------------------------------\n";
				for(int j=1;j<=cal;j++)
				{
					cout<<j<<".       |    ";
					cout<<cart[j].rate<<"      |      "<<cart[j].qnty<<"       |         ";
					puts(cart[j].nam);
				}
				cout<<"_________|_____________|______________|________________________________________\n";
				cout<<"\n";

				gotoxy(20,23);
				cout<<"TOTAL PRODUCTS BOUGHT : "<<cal<<"\n";
				gotoxy(20,24);
				cout<<"TOTAL BILL AMOUNT     : "<<total;
				getch();
				clrscr();
				gotoxy(30,13);
				cout<<"PLEASE VISIT AGAIN";
				cout<<".";
				delay(500);
				cout<<".";
				delay(500);
				cout<<".";
				delay(500);
				cout<<".";
				delay(500);
				cout<<".";
				gotoxy(30,24);
				cout<<"Press any key to exit";
				getch();
				exit(0);
			}


			else if(choice2==100)     //choice is end=100
			{
			clrscr();
			gotoxy(30,13);
			cout<<"HAVE A NICE DAY";
			cout<<".";
			delay(500);
			cout<<".";
			delay(500);
			cout<<".";
			gotoxy(30,24);
			cout<<"Press Any Key to Exit" ;
			getch();
			exit(0);
			}
			choice3=choice2;

	     }while(choice3==0);

			break;//for case 1

    case 2:     // To Enter details of the customer

		clrscr();
		gotoxy(33,5);
		  cout<<"AHAR RESTO";
		  gotoxy(25,6);
		  cout<<"Welcome to CUSTOMER ADDITION SECTOR";

		  gotoxy(10,8);
		  cout<<"Enter the no. of customers you want to add: ";
		  cin>>cno;

		  fout.open("ahar.txt",ios::app);
		  for(add=0;add<cno;add++)         //add is used in place of i since border print also uses i&j ,output not coming to be right
		     {
		      clrscr();


		      gotoxy(33,5);
		      cout<<"AHAR RESTO";

		      gotoxy(25,6);
		      cout<<"Welcome to CUSTOMER ADDITION SECTOR";
		      gotoxy(10,8);
		      cout<<"Enter the no. of customers you want to add: "<<cno;

		      gotoxy(10,9);
		      cout<<"Enter the details of customer "<<add+1<<":";

		      obj.input(10);
		      fout.write((char*)&obj,sizeof(obj));

		      if(add<cno-1)
			{
			 gotoxy(20,21);
			 cout<<"Press any key to add more customers";
			 getch();
			}

		     }
		  fout.close();

		  gotoxy(20,24);
		  cout<<"Press any key to exit....";
		  getch();

		break;
    case 3:   //To View details of a customer
		     clrscr();


		  gotoxy(33,5);
		  cout<<"AHAR RESTO";

		  gotoxy(25,6);
		  cout<<"Welcome to the Customer veiwing portal";
		  gotoxy(10,8);
		  cout<<"Select the parameter on the basis of which ,you want to search";
		  gotoxy(10,9);
		  cout<<"for the consumer: ";
		  gotoxy(35,9);
		  cout<<"1.consumer id";
		  gotoxy(35,10);
		  cout<<"2.meter id";
		  gotoxy(10,11);
		  cout<<"Choice(1/2) : ";
		  cin>>choic;
		  switch(choic)       //if there are 2 consumer with same meter id/cons_id then??
		  {
		   case 1:   gotoxy(10,12);
			       cout<<"Enter the consumer id of the consumer to be searched: ";
			       gets(cons_id);

			       fin.open("ahar.txt");
			       while(!fin.eof())
				  {
				   fin.read((char*)&obj,sizeof(obj));
				   if(strcmp(obj.get_consumer_id(),cons_id)==0)
				     {
				       obj.output(13);
				       lag=1;
				       break;
				     }
				  }
			       fin.close();
			       if(lag!=1)
				 {
				   gotoxy(10,15);
				   cout<<"The above consumer ID does not exists";
				 }
			       break;

		   case 2:   gotoxy(10,12);
			       cout<<"Enter the meter id of the consumer to be searched: ";
			       gets(met_id);

			       fin.open("ahar.txt");
			       while(!fin.eof())
				  {
				   fin.read((char*)&obj,sizeof(obj));
				   if(strcmp(obj.get_meter_id(),met_id)==0)
				     {
				       obj.output(13);
				       lag=1;
				       break;
				     }
				  }
			       fin.close();
			       if(lag!=1)
				 {
				   gotoxy(10,15);
				   cout<<"The above meter ID does not exists";
				 }
			       break;

		   default:    gotoxy(10,15);
			       cout<<"Wrong choice!!";
		  }

		  gotoxy(20,24);
		  cout<<"Press any key to exit....";
		  getch();



		  break;

    default:
		cout<<"INVALID OPTION";

}//for switch
getch();      //PROG. ENDS HERE
}
		   //+++++++++++++++++++++++++++++++++
		   //***********FUNCTIONS*************
		   //+++++++++++++++++++++++++++++++++

//**********FUNCTION FOR STARTING DESIGN***********
void password()
{       int i;
	for(int j=0;j<80;j++)
	{
	  delay(5);
		gotoxy(j,1);         //]
		cout<<"X";           //]  Design for top border
			gotoxy(j,2); //]
			cout<<"X";   //]

		gotoxy(j,25);              //]
		cout<<"X";                 //] Design for bottom border
			gotoxy(j,24);      //]
			cout<<"X";         //]
	}
	for(j=3;j<=23;j++)
	{     delay(10);
	      gotoxy(1,j);    //] Design for left '|' border
	      cout<<"|";      //]
			gotoxy(80,j);  //] Design for right '|'border
			cout<<"|";     //]


	}

	for(j=9;j<=17;j++)
	{
	      gotoxy(22,j); //] Design for left '\' border of box
	      cout<<"/";    //]
			gotoxy(57,j); //] Design for right '/'border of box
			cout<<"\\";   //]
	      gotoxy(21,j);
	      cout<<"\\";
			 gotoxy(58,j);
			 cout<<"/";
	}
	for(j=22;j<=57;j++)
	{
		gotoxy(j,7);          //]
		cout<<"M";            //] Design 'M'for top border of box
			gotoxy(j,8);  //]        'W'
			cout<<"W";    //]
		gotoxy(j,18);         //] Design 'M'for bottom border of box
		cout<<"M";            //]        'W'
			gotoxy(j,19); //]
			cout<<"W";    //]
	}

	gotoxy(30,10);   			  //]
	cout<<"******WELCOME******"; 		  //]
	gotoxy(30,11);                            //]
	cout<<"~~~~~~~~~~~~~~~~~~~";              //]
	gotoxy(38,12);                            //]
	cout<<"to";                               //]
	gotoxy(30,13);                            //]
	cout<<"\t AHAAR RESTO  ";                 //] Text of the box
	gotoxy(27,14);                            //]
	cout<<"ENTER PASSWORD TO CONTINUE";	  //]
	gotoxy(36,15);                  	  //]
	for(i=0; ;i++)
      {
       ch0=getch();

       if(ch0!='\r')
	 {
	  pass_o[i]=ch0;
	  cout<<"*";
	 }
       else
	 break;
      }
	if(strcmp(pass_o,pass)==0)
       {   gotoxy(28,16);
       cout<<"Press ENTER to continue\n";
       }
       else
       {   gotoxy(31,16);
       cout<<"INCORRECT PASSWORD";
	   gotoxy(33,17);
       cout<<"EXITING in ";
       for(int f=10;f>=0;f--)
		{
		gotoxy(46,17);
		delay(500);
		cout<<f<<" ";
		}

	delay(1000);
	exit(0);
       }


	getch();
}

void border()
{
    for(int j=0;j<80;j++)
	{
	  delay(5);
		gotoxy(j,1);         //]
		cout<<"X";           //]  Design for top border
			gotoxy(j,2); //]
			cout<<"X";   //]

		gotoxy(j,25);              //]
		cout<<"X";                 //] Design for bottom border
			gotoxy(j,24);      //]
			cout<<"X";         //]
	}
	for(j=3;j<=23;j++)
	{     delay(10);
	      gotoxy(1,j);    //] Design for left '|' border
	      cout<<"|";      //]
			gotoxy(80,j);  //] Design for right '|'border
			cout<<"|";     //]


	}
}
void catag()
{

	strcpy(cat[1].name, "Snacks");
	strcpy(cat[2].name, "Chinese: Veg");
	strcpy(cat[3].name, "Soups");
	strcpy(cat[4].name, "Rice");
	strcpy(cat[5].name, "Pizza");
	strcpy(cat[6].name, "Noodles");
	strcpy(cat[7].name, "Veg-e-delight");
	strcpy(cat[8].name, "Roti");
//|||||||||| NAMING SUB CATAGORIES ||||||||||

//********SUB CATAGORIES FOR SNACKS**********
	strcpy(cat[1].var[1].nam,"Veg. Spring Rolls");
	cat[1].var[1].rate=130;
	strcpy(cat[1].var[2].nam,"Paneer Pakore");
	cat[1].var[2].rate=170;
	strcpy(cat[1].var[3].nam,"French Fries");
	cat[1].var[3].rate=120;
	strcpy(cat[1].var[4].nam,"Veg. Cutlets");
	cat[1].var[4].rate=140;
	cat[1].num=4;
//********SUB CATAGORIES FOR CHINESE; VEG********
	strcpy(cat[2].var[1].nam,"Chilly Crispy Potato");
	cat[2].var[1].rate=160;
	strcpy(cat[2].var[2].nam,"Honey Crispy Potato");
	cat[2].var[2].rate=180;
	strcpy(cat[2].var[3].nam,"Veg. Fried Rice");
	cat[2].var[3].rate=140;
	strcpy(cat[2].var[4].nam,"Paneer Momos");
	cat[2].var[4].rate=120;
	strcpy(cat[2].var[5].nam,"Veg.Momos");
	cat[2].var[5].rate=100;
	strcpy(cat[2].var[6].nam,"Manchurian");
	cat[2].var[6].rate=180;
	cat[2].num=6;
//********SUB CATAGORIES FOR SOUP********
	strcpy(cat[3].var[1].nam,"Veg. Clear Soup ");
	cat[3].var[1].rate=100;
	strcpy(cat[3].var[2].nam,"Tomato Soup ");
	cat[3].var[2].rate=100;
	strcpy(cat[3].var[3].nam,"Veg. Talumein Soup ");
	cat[3].var[3].rate=100;
	strcpy(cat[3].var[4].nam,"Veg. Manchow Soup ");
	cat[3].var[4].rate=100;
	strcpy(cat[3].var[5].nam,"Veg. Hot n Sour Soup ");
	cat[3].var[5].rate=100;
	strcpy(cat[3].var[6].nam,"Veg. Sweet Corn Soup ");
	cat[3].var[6].rate=100;
	strcpy(cat[3].var[7].nam,"Veg. Noodle Soup ");
	cat[3].var[7].rate=120;
	cat[3].num=7;
//********SUB CATAGORIES FOR RICE********
	strcpy(cat[4].var[1].nam,"Our Special Veg. Biryani");
	cat[4].var[1].rate=170;
	strcpy(cat[4].var[2].nam,"Veg. Pulao");
	cat[4].var[2].rate=140;
	strcpy(cat[4].var[3].nam,"Veg. Biryani");
	cat[4].var[3].rate=160;
	strcpy(cat[4].var[4].nam,"Jeera Pulao");
	cat[4].var[4].rate=130;
	strcpy(cat[4].var[5].nam,"Peas Pulao");
	cat[4].var[5].rate=140;
	strcpy(cat[4].var[6].nam,"Plain Rice");
	cat[4].var[6].rate=120;
	cat[4].num=6;
//********SUB CATAGORIES FOR PIZZA**********
	strcpy(cat[5].var[1].nam,"Cheese Pizza");
	cat[5].var[1].rate=120;
	strcpy(cat[5].var[2].nam,"Onion, Tomato Pizza");
	cat[5].var[2].rate=140;
	strcpy(cat[5].var[3].nam,"Capsicum, Onion Pizza");
	cat[5].var[3].rate=150;
	strcpy(cat[5].var[4].nam,"Onion, Capsicum & Tomato Pizza");
	cat[5].var[4].rate=160;
	strcpy(cat[5].var[5].nam,"Onion, Tomato & Mashroom Pizza");
	cat[5].var[5].rate=170;
	cat[5].num=5;
//********SUB CATAGORIES FOR NOODLES********
	strcpy(cat[6].var[1].nam,"Veg. Noodles");
	cat[6].var[1].rate=120;
	strcpy(cat[6].var[2].nam,"Chilly Garlic Veg. Noodles");
	cat[6].var[2].rate=140;
	strcpy(cat[6].var[3].nam,"Veg. Singapore Noodles");
	cat[6].var[3].rate=160;
	strcpy(cat[6].var[4].nam,"Butter Noodles");
	cat[6].var[4].rate=130;
	strcpy(cat[6].var[5].nam,"Our Special Noodles");
	cat[6].var[5].rate=180;
	cat[6].num=5;
//********SUB CATAGORIES FOR VEG-E-DElIGHT********
	strcpy(cat[7].var[1].nam,"Dal Makhani");
	cat[7].var[1].rate=130;
	strcpy(cat[7].var[2].nam,"Chana Pindi");
	cat[7].var[2].rate=160;
	strcpy(cat[7].var[3].nam,"Shahi Paneer");
	cat[7].var[3].rate=180;
	strcpy(cat[7].var[4].nam,"Dum Aloo");
	cat[7].var[4].rate=190;
	strcpy(cat[7].var[5].nam,"Malai Kofta");
	cat[7].var[5].rate=200;
	strcpy(cat[7].var[6].nam,"Matar Mashroom");
	cat[7].var[6].rate=180;
	strcpy(cat[7].var[7].nam,"Soya Chaap");
	cat[7].var[7].rate=170;
	strcpy(cat[7].var[8].nam,"Palak Paneer ");
	cat[7].var[8].rate=190;
	cat[7].num=8;
//********SUB CATAGORIES FOR ROTI************
	strcpy(cat[8].var[1].nam,"Butter Naan");
	cat[8].var[1].rate=30;
	strcpy(cat[8].var[2].nam,"Roti");
	cat[8].var[2].rate=10;
	strcpy(cat[8].var[3].nam,"Butter Roti");
	cat[8].var[3].rate=13;
	strcpy(cat[8].var[4].nam,"Plain Naan");
	cat[8].var[4].rate=25;
	strcpy(cat[8].var[5].nam,"Lachha Parantha");
	cat[8].var[5].rate=32;
	strcpy(cat[8].var[6].nam,"Missi Masala Roti");
	cat[8].var[6].rate=35;
	strcpy(cat[8].var[7].nam,"Aloo Stuffed Parantha");
	cat[8].var[7].rate=50;
	strcpy(cat[8].var[8].nam,"Paneer Stuffed Parantha");
	cat[8].var[8].rate=40;
	cat[8].num=8;
}
void loading()
{
  gotoxy(31,10);
  cout<<"Loading";
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		cout<<".";
		delay(500);
		clrscr();
}
void ahar()
{
clrscr();
int q,w;
//A
for(q=10;q<20;q++)          //   A                      ]
{       gotoxy(15,q);       //   A                      ]
	cout<<"A"<<"\n";    //   A                      ]
	delay(50);          //   A                      ]       AAAAA
}                           //   A                      ]       A   A
for(q=16;q<22;q++)               	//      AAAAA   ]       A   A
{	gotoxy(q,10);            	//              ]       AAAAA
	cout<<"A";              	//      AAAAA   ]       A   A
	gotoxy(q,15);            	//              ]       A   A
	cout<<"A";              	//              ]
	delay(50);         //                           ]
}                          //                           ]
for(q=10;q<20;q++)         //    A                      ]
{       gotoxy(22,q);      //    A                      ]
	cout<<"A"<<"\n";   //    A                      ]
	delay(50);         //    A                      ]
}                          //    A                      ]
//H
for(q=10;q<20;q++)         //   H                       ]
{       gotoxy(25,q);      //   H                       ]
	cout<<"H"<<"\n";   //   H                       ]
	delay(50);         //   H                       ]      H    H
}                                        //             ]      H    H
for(q=26;q<35;q++)                       //             ]      H    H
{       gotoxy(q,15);                    //             ]      HHHHHH
	cout<<"H";                       //  HHHHH      ]      H    H
	delay(50);                       //             ]      H    H
}                                        //             ]      H    H
for(q=10;q<20;q++)          //  H                       ]
{       gotoxy(35,q);       //  H                       ]
	cout<<"H"<<"\n";    //  H                       ]
	delay(50);          //  H                       ]
}                           //                          ]


//A
for(q=10;q<20;q++)          //   A                      ]
{       gotoxy(38,q);       //   A                      ]
	cout<<"A"<<"\n";    //   A                      ]
	delay(50);          //   A                      ]       AAAAA
}                           //   A                      ]       A   A
for(q=39;q<45;q++)               	//      AAAAA   ]       A   A
{	gotoxy(q,10);            	//              ]       AAAAA
	cout<<"A";              	//      AAAAA   ]       A   A
	gotoxy(q,15);            	//              ]       A   A
	cout<<"A";              	//              ]
	delay(50);         //                           ]
}                          //                           ]
for(q=10;q<20;q++)         //    A                      ]
{       gotoxy(45,q);      //    A                      ]
	cout<<"A"<<"\n";   //    A                      ]
	delay(50);         //    A                      ]
}
//R
for(q=10;q<20;q++)          //                          ]
{       gotoxy(48,q);       //   R                      ]
	cout<<"R"<<"\n";    //   R                      ]
	delay(50);          //   R                      ]       RRRRR
}                           //   R                      ]       R   R
for(q=49;q<55;q++)               	//      RRRRR   ]       R   R
{	gotoxy(q,10);            	//              ]       RRRRR
	cout<<"R";              	//      RRRRR   ]       RR
	gotoxy(q,15);            	//              ]       R R
	cout<<"R";              	//              ]       R  R
	delay(50);         		//              ]       R   R
}                          //                           ]
for(q=10;q<=15;q++)        //    R                      ]
{       gotoxy(55,q);      //    R                      ]
	cout<<"R"<<"\n";   //    R                      ]
	delay(50);         //    R                      ]
}                          //    R                      ]
q=52;
w=16;
for(int t=0;t<4;t++)
{
delay(50);
gotoxy(q,w);
cout<<"R";
q++;
w++;
}
getch();

}
//MEMBER FUNCTION DECLARATIONS

void consumer::input(int i)
   {
       gotoxy(10,i);
       cout<<"CONSUMER-ID: ";
       gets(consumer_id);

       gotoxy(10,i+1);
       cout<<"METER-ID: ";
       gets(meter_id);

       gotoxy(10,i+2);
       cout<<"NAME: ";
       gets(name);

       gotoxy(10,i+3);
       cout<<"ADDRESS:  ";
       gotoxy(20,i+3);
       cout<<"House number: ";
       cin>>address.house_no;
       gotoxy(20,i+4);
       cout<<"Locality: ";
       gets(address.locality);
       gotoxy(20,i+5);
       cout<<"City: ";
       gets(address.city);
       gotoxy(20,i+6);
       cout<<"State: ";
       gets(address.state);
       gotoxy(20,i+7);
       cout<<"Pin: ";
       cin>>address.pin;


       gotoxy(10,i+8);
       cout<<"PHONE NUMBER: ";
       cin>>phone_no;

   }
void consumer::output(int i)
   {
       gotoxy(10,i);
       cout<<"CONSUMER-ID: ";
       puts(consumer_id);

       gotoxy(10,i+1);
       cout<<"METER-ID: ";
       puts(meter_id);

       gotoxy(10,i+2);
       cout<<"NAME: ";
       puts(name);

       gotoxy(10,i+3);
       cout<<"ADDRESS:  ";
       gotoxy(20,i+3);
       cout<<"House number: ";
       cout<<address.house_no;
       gotoxy(20,i+4);
       cout<<"Locality: ";
       puts(address.locality);
       gotoxy(20,i+5);
       cout<<"City: ";
       puts(address.city);
       gotoxy(20,i+6);
       cout<<"State: ";
       puts(address.state);
       gotoxy(20,i+7);
       cout<<"Pin: ";
       cout<<address.pin;


       gotoxy(10,i+8);
       cout<<"PHONE NUMBER: ";
       cout<<phone_no;

   }
