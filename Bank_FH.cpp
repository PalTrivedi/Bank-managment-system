#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
ofstream fout;
ifstream fin;
fstream f;
class Bank
{
	private:
		char name[50],pass[10],cpass[10],mob[20],tv[20],dt[20];
		int type,bal,dep=0,wit=0,lbal=0,i1=0,i2=0;
		float interest;
	public:
		void cdi(char smob[])
		{
			cout<<"Enter your name:";fflush(stdin);gets(name);
			//check1:
			strcpy(mob,smob);
			cout<<"Mobile:"<<mob<<endl;
			check2:
			//strcpy(pass,"");
			//strcpy(cpass,"");
			i1=0;
			i2=0;
			cout<<"Enter password:";
			while(1)
			{
				char c=getch();
				if(c=='\r')
				{
					pass[i1]='\0';
					break;
				}
				else
				{
					pass[i1]=c;
					cout<<"*";
					i1++;
				}
				if(c=='\b' && i1>=1)
				{
					cout<<"\b \b";
					i1--;
				}
			}
			cout<<endl;
			cout<<"Please re-enter your password for confirmation:";
			while(1)
			{
				char c=getch();
				if(c=='\r')
				{
					cpass[i2]='\0';
					break;
				}
				else
				{
					cpass[i2]=c;
					cout<<"*";
					i2++;
				}
				if(c=='\b' && i2>=1)
				{
					cout<<"\b \b";
					i2--;
				}
			}
			if(strcmp(pass,cpass)==0 )
			{
				cout<<endl;
				cout<<"Password matched!"<<endl;
				cout<<"Which type of account do you want to open?(Enter 1 for savings and 2 for current):";cin>>type;
				bal=2000;
				if(type==1)
				{
					strcpy(dt,"Savings");
				}
				else
				{
					strcpy(dt,"Current");
				}
			}
			else
		    {
				cout<<endl;
				cout<<"Password doesn't match!"<<endl;
				goto check2;
		    }
		}
		int rmob(char smob[])
		{
			if(strcmp(smob,mob)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int rpass(char spass[])
		{
			if(strcmp(spass,pass)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int rtype()
		{
			return type;
		}
		void cdisplay()
		{
			cout<<"************************************************************************\n";
			cout<<"Account holder :"<<name<<endl;
			cout<<"Mobile number  :"<<mob<<endl;
			cout<<"Password       :"<<pass<<endl;
			cout<<"Type           :"<<dt<<endl;
			cout<<"Balance        :"<<bal<<endl;
			cout<<"************************************************************************\n";
		}
		void adisplay()
		{
			cout<<"***************************************************************\n";
			cout<<"Account holder :"<<name<<endl;
			cout<<"Mobile number  :"<<mob<<endl;
			cout<<"Password       :"<<pass<<endl;
			cout<<"Type           :"<<dt<<endl;
			cout<<"Balance        :"<<bal<<endl;
			cout<<"Interest       :"<<interest<<endl;
			cout<<"***************************************************************\n";
		}
		int rbal()
		{
			return bal;
		}
		float rinterest()
		{
			float r;
			cout<<"Enter rate of interest:";cin>>r;
			interest=(bal*pow(1+r/100,1))-bal;
			cout<<"Interest "<<interest<<" at "<<r<<"% rate!!"<<endl;
		}
		void deposit(int wd)
		{
			wit=0;
			dep=wd;
			strcpy(tv,"Deposit: +");
			bal=bal+wd;
			cout<<"Amount deposited successfully!!\n";
		}
		void withdraw(int wd)
		{
			dep=0;
			wit=wd;
			strcpy(tv,"Withdraw: -");
			bal=bal-wd;
			cout<<"Amount withdrawed successfully!!\n";
		}
		void th()
		{
			
			if(dep==0)
			{
				cout<<"-->"<<tv<<wit<<endl<<"Balance : "<<bal<<endl;
			}
			else
			{
				cout<<"-->"<<tv<<dep<<endl<<"Balance : "<<bal<<endl;
			}
			
		}
		void ami()
		{
			cout<<"***************************************************************\n";
			cout<<"Account holder :"<<name<<endl;
			cout<<"Mobile number  :"<<mob<<endl;
			cout<<"Type           :"<<dt<<endl;
			cout<<"Balance        :"<<bal<<endl;
			cout<<"Interest       :"<<interest<<endl;
			cout<<"***************************************************************\n";
		}
		void pbalacc()
		{
			if(lbal==0)
			{
				cout<<"***************************************************************\n";
				cout<<"Account holder :"<<name<<endl;
				cout<<"Mobile number  :"<<mob<<endl;
				cout<<"Type           :"<<dt<<endl;
				cout<<"Balance        :"<<bal<<endl;
				cout<<"***************************************************************\n";
			}
		}
		void lbalacc()
		{
			if(lbal==2)
			{
				cout<<"***************************************************************\n";
				cout<<"Account holder :"<<name<<endl;
				cout<<"Mobile number  :"<<mob<<endl;
				cout<<"Type           :"<<dt<<endl;
				cout<<"Balance        :"<<bal<<endl;
				cout<<"***************************************************************\n";
			}
		}
		int rlbal()
		{
			return lbal;
		}
		void lbali()
		{
			lbal=lbal+1;
		}
};
Bank b;
void Signup()
{
	check3:
	int flag=0;
	char smob[20];
	cout<<"Please enter your mobile number for verification:";fflush(stdin);gets(smob);
	if(strlen(smob)==10 && (smob[0]=='9'|| smob[0]=='8' || smob[0]=='7' || smob[0]=='6'))
	{
		fin.open("125_Bank_FH.dat",ios::binary|ios::in);
		while(fin.read((char*)&b,sizeof(b)))
		{
			if(b.rmob(smob)==1)
			{
				cout<<"Invalid mobile number!!"<<endl;
				flag++;
				fin.close();
				goto check3;
			}
		}
		fin.close();
		if(flag==0)
		{
			f.open("125_Bank_FH.dat",ios::binary|ios::app);
			b.cdi(smob);
			f.write((char*)&b,sizeof(b));
			f.close();
			system("CLS");
			cout<<"YOU SIGNED UP SUCCESSFULLY!!"<<endl;
			cout<<"NOW YOU CAN SIGN IN WHENEVER YOU WANT AND AVAIL OUR SERVICES!!"<<endl;
			cout<<endl;
			cout<<"SINCE YOU JUST SIGNED UP YOUR OPENING BALANCE IS HERE AT THE MINIMUM OF $2000."<<endl;
			cout<<"SIGNUP USING MOBILE NUMBER AND PASSWORD AND DEPOSIT AMOUNT AS PER YOUR WISH BUT DO MAINTAIN A MINIMUM BALANCE OF $2000"<<endl;
		}
	}
	else
	{
		cout<<"Enter proper mobile number!!\n";
		goto check3;
	}
}
void admin();
void Signin();

int main()
{
	l1:	
	while(1)
	{
		int c1;
		d1:
		cout<<"**********MENU**********"<<endl;
		cout<<"1.Admin Signin"<<endl;
		cout<<"2.Customer Signup"<<endl;
		cout<<"3.Customer Signin"<<endl;
		cout<<"4.EXIT"<<endl;
		cout<<"Enter your choice:";cin>>c1;
		cout<<"************************"<<endl;
		switch(c1)
		{
			case 1: admin();break;
			case 2: Signup();break;
			case 3: Signin();break;
			case 4: exit(0);break;
			default:cout<<"Enter valid choice!";goto l1;break;
		}
	}
}

void admin()
{
	int choice;
	int fl=0,i=0;
	char spass[8],lg[5];
	check5:
	i=0;
	cout<<"Enter admin password:";
	while(1)
	{
		char c=getch();
		if(c=='\r')
		{
			spass[i]='\0';
			break;
		}
		else
		{
			spass[i]=c;
			cout<<"*";
			i++;
		}
		if(c=='\b' && i>=1)
		{
			cout<<"\b \b";
			i--;
		}
	}
	cout<<endl;
	if(strcmp(spass,"admin123")==0)
	{
		cout<<"ACCESS GRANTED!!"<<endl;
		loop1:
		while(1)
		{
			cout<<"***************MENU***************"<<endl;
			cout<<"1.Customer Monthly Interest\n";
			cout<<"2.Check account with proper balance\n";
			cout<<"3.Check account with low balance\n";
			cout<<"4.Dormat low balance accounts\n";
			cout<<"5.Customer data\n";
			cout<<"6.Logout\n";
			cout<<"Enter your choice:";cin>>choice;
			cout<<"**********************************"<<endl;
			switch(choice)
			{
				case 1: f.open("125_Bank_FH.dat",ios::binary|ios::in);
					    while(f.read((char*)&b,sizeof(b)))
					    {
							b.ami();
					    }
				   	    f.close();
				   	    break;
				case 2: cout<<"ACCOUNTS WITH ALL TIME PROPER BALANCE!!\n";
						f.open("125_Bank_FH.dat",ios::binary|ios::in);
					    while(f.read((char*)&b,sizeof(b)))
					    {
							b.pbalacc();
					    }
				   	    f.close();
				   	    break;
				case 3: cout<<"ACCOUNTS WITH OCCASSIONAL LOW BALANCE!!\n";
						f.open("125_Bank_FH.dat",ios::binary|ios::in);
					    while(f.read((char*)&b,sizeof(b)))
					    {
							b.lbalacc();
					    }
				   	    f.close();
				   	    break;
				case 4: cout<<"DORMATTING ACCOUNTS WITH REPEATED LOW BALANCE!!\n";
						f.open("125_Bank_FH.dat",ios::binary|ios::in);
						fout.open("125_Bank_FH_Dormat.dat",ios::binary|ios::app);
					    while(f.read((char*)&b,sizeof(b)))
					    {
					    	if(b.rlbal()==3)
					    	{
					    		fl++;
							}
							else
							{
								fout.write((char*)&b,sizeof(b));
							}
						}
						f.close();
						fout.close();
						if(fl==0)
						{
							cout<<"No accounts deleted!\n";
						}
						else
						{
							cout<<fl<<" accounts deleted!\n";
						}
						remove("125_Bank_FH.dat");
						rename("125_Bank_FH_Dormat.dat","125_Bank_FH.dat");
						break;
				case 5: cout<<"*****Customer Databank*****\n";
						fin.open("125_Bank_FH.dat",ios::binary|ios::in);
						fin.read((char*)&b,sizeof(b));
						while(!fin.eof())
						{
							b.adisplay();
							fin.read((char*)&b,sizeof(b));
						}
						fin.close();
						break;
				case 6: cout<<"Are you sure you want to logout?(yes/no):";fflush(stdin);gets(lg);
						if(strcmpi(lg,"Yes")==0)
						{
							system("CLS");
							main();
						}
						else
						{
							goto loop1;
						}
				default: cout<<"Enter valid choice\n";goto loop1;break;
			}
		}
	}
	else
	{
		goto check5;
	}
}
void Signin()
{
	check4:
	int flag=0,wd,i2=0;
	char smob[20],spass[8],lg[5];
	cout<<"Enter mobile number:";fflush(stdin);gets(smob);
	cout<<"Enter password:";
	while(1)
	{
		char c=getch();
		if(c=='\r')
		{
			spass[i2]='\0';
			break;
		}
		else
		{
			spass[i2]=c;
			cout<<"*";
			i2++;
		}
		if(c=='\b' && i2>=1)
		{
			cout<<"\b \b";
			i2--;
		}
	}
	cout<<endl;
	f.open("125_Bank_FH.dat",ios::binary|ios::in|ios::out);
	while(f.read((char*)&b,sizeof(b)))
	{
		int tell=f.tellp();
		if(b.rmob(smob)==1 && b.rpass(spass)==1)
		{
			int choice;
			cout<<"SIGNED IN SUCCESSFULLY!!"<<endl;
			b.cdisplay();
			flag++;
			if(b.rtype()==1)
			{
				exl1:
				while(1)
				{
					cout<<"************************************************************************\n";
					cout<<"1.Interest\n";
					cout<<"2.Check Balance\n";
					cout<<"3.Deposit\n";
					cout<<"4.Withdraw\n";
					cout<<"5.Account history\n";
					cout<<"6.Logout\n";
					cout<<"Choose your option:";cin>>choice;
					cout<<"************************************************************************\n";
					switch(choice)
					{
						case 1: b.rinterest();break;
						case 2: cout<<"Balance:"<<b.rbal();
								cout<<endl;break;
						case 3: fout.open("125_Bank_FH_TH.dat",ios::binary|ios::app);
								cout<<"Enter amount to be deposited:";cin>>wd;
								b.deposit(wd);
								cout<<"New balance:"<<b.rbal();
								if(b.rbal()<3000)
								{
									b.lbali();
								}
								cout<<endl;
								fout.write((char*)&b,sizeof(b));
								f.seekp(tell-sizeof(b));
								f.write((char*)&b,sizeof(b));
								fout.close();
								break;
						case 4: fout.open("125_Bank_FH_TH.dat",ios::binary|ios::app);
								cout<<"Enter amount to be withdrawed:";cin>>wd;
								if(wd<=b.rbal())
								{
									b.withdraw(wd);
									cout<<"New balance:"<<b.rbal();
									cout<<endl;
									fout.write((char*)&b,sizeof(b));
									f.seekp(tell-sizeof(b));
									f.write((char*)&b,sizeof(b));
									if(b.rbal()<3000)
									{
										b.lbali();
										cout<<endl<<"Alert...!!! Low Balance Please Deposit\n";
									}
								}
								else
								{
									cout<<"Insufficient funds!!"<<endl;
									cout<<"Balance:"<<b.rbal()<<endl;
								}
								fout.close();
								break;
						case 5: fin.open("125_Bank_FH_TH.dat",ios::binary|ios::in);
								while(fin.read((char*)&b,sizeof(b)))
								{
									b.th();
								}
								fin.close();
								break;
						case 6: cout<<"Are you sure you want to logout?(yes/no):";fflush(stdin);gets(lg);
								if(strcmpi(lg,"Yes")==0)
								{
									system("CLS");
									f.close();
									main();
								}
								else
								{
									goto exl1;
								}
						default:cout<<"Enter valid choice\n";goto exl1;break;
					}
				}
			}
			else
			{
				exl2:
				while(1)
				{
					cout<<"************************************************************************\n";
					cout<<"1.Check Balance\n";
					cout<<"2.Deposit\n";
					cout<<"3.Withdraw\n";
					cout<<"4.Account history\n";
					cout<<"5.Exit\n";
					cout<<"Choose your option:";cin>>choice;
					cout<<"************************************************************************\n";
					switch(choice)
					{
						case 1: cout<<"Balance:"<<b.rbal();
								cout<<endl;break;
						case 2: fout.open("125_Bank_FH_TH.dat",ios::binary|ios::app);
								cout<<"Enter amount to be deposited:";cin>>wd;
								b.deposit(wd);
								cout<<"New balance:"<<b.rbal();
								if(b.rbal()<3000)
								{
									b.lbali();
								}
								cout<<endl;
								fout.write((char*)&b,sizeof(b));
								f.seekp(tell-sizeof(b));
								f.write((char*)&b,sizeof(b));
								fout.close();
								break;
						case 3: fout.open("125_Bank_FH_TH.dat",ios::binary|ios::app);
								cout<<"Enter amount to be withdrawed:";cin>>wd;
								if(wd<=b.rbal())
								{
									b.withdraw(wd);
									cout<<"New balance:"<<b.rbal();
									cout<<endl;
									fout.write((char*)&b,sizeof(b));
									f.seekp(tell-sizeof(b));
									f.write((char*)&b,sizeof(b));
									if(b.rbal()<3000)
									{
										b.lbali();
										cout<<endl<<"Alert...!!! Low Balance Please Deposit\n";
									}
								}
								else
								{
									cout<<"Insufficient funds!!"<<endl;
									cout<<"Balance:"<<b.rbal()<<endl;
								}
								fout.close();
								break;
						case 4: fin.open("125_Bank_FH_TH.dat",ios::binary|ios::in);
								while(fin.read((char*)&b,sizeof(b)))
								{
									b.th();
								}
								fin.close();
								break;
						case 5: cout<<"Are you sure you want to logout?(yes/no):";fflush(stdin);gets(lg);
								if(strcmpi(lg,"Yes")==0)
								{
									system("CLS");
									f.close();
									main();
								}
								else
								{
									goto exl2;
								}
						default:cout<<"Enter valid choice\n";goto exl2;break;
					}
				}
			}
		}
		else
		{
			f.close();
			goto check4;
		}
	}
	f.close();
	if(flag==0)
	{
		goto check4;
	}
}
