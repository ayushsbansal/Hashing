#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 20
struct data		//data contains name and Roll number
{
	int Roll_no;
	char name[20];
};

struct student
{
	struct data d1;	//variable d1 of type struct data
	int chain;
	int flag;
};
class hash
{
	struct 	student s[SIZE];	//array of structures 
	int n;		//maintains number of records
	int hash_fun(int key)
	{
		return (key%13);	
	}
	public:
		hash()
		{
			for(int i=0;i<SIZE;i++)		//initialization
			{
				s[i].d1.Roll_no=-1;		
				s[i].chain=-1;	//stores address of next element with same hash value
				s[i].flag=0;	//flag==0,unoccupied else flag==1
				s[i].d1.name[0]='\0';
			}
		}
		int compute_pos(int key)		//chaining without replacement
		{
			int i=1;		//offset 
			int h1=hash_fun(key);	//hash function
			int h2=h1;		//moves to specific address
			int h3=h1;		//moves to previous element with same hash value
			int j=0;
			while(s[h3].flag!=0)	//until empty location is identified
			{
				if(h1==((s[h3].d1.Roll_no)%13))		//if same hash value
				{
					break;		//h3 now contains address of same hash value element
				}
				h3=(h3+1)%13;
				j++;
			}
			if(j==13)	
				cout<<"Table full"<<endl;
				
				
			while(s[h3].chain!=-1)		//access the chain to move to the end
				h3=s[h3].chain;			
			
			while(s[h2].flag!=0)	//place for insertion
				h2=(h2+i)%13;
					
			s[h3].chain=h2;		
			return h2;
		}
		
	void search(int key)
		{
			int h1= hash_fun(key);
			int h2=h1,pos,flag1=0;
			while(s[h2].flag!=0)
			{
				if(h2==(s[h2].d1.Roll_no%13))
				{
					break;
				}
				h2=(h2+1)%13;
			}
			while(h2!=-1)
			{
				if(s[h2].d1.Roll_no==key)
				{
					cout<<"Record Found at position "<<h2<<endl;
					flag1=1;
					break;
				}
				h2=s[h2].chain;
			}
			if(flag1!=1)
			{
				cout<<"Record Not Found in the hash table"<<endl;
			}
		}
		void accept()
		{
			int number,UID;
			char name1[20];
			cout<<"Enter the number of elements to be inserted:"<<endl;
			cin>>number;
			for(int i=0;i<number;i++)
			{
				cout<<"Enter the data"<<endl;
				cin>>UID;
				int pos= compute_pos(UID);
				s[pos].d1.Roll_no=UID;
				cout<<"Enter the name"<<endl;
				cin>>name1;
				strcpy(s[pos].d1.name,name1);
				s[pos].chain=-1;
				s[pos].flag=1;
			}
		}
	void display()
		{
			int i;
				cout<<"INDEX"<<"\t"<<"ROLL NO"<<"\t"<<"NAME"<<"\t"<<"CHAIN"<<endl;
			for(i=0;i<SIZE;i++)
			{
				if(s[i].flag==1)
				{
					cout<<i<<"\t"<<s[i].d1.Roll_no<<"\t"<<s[i].d1.name<<"\t"<<s[i].chain<<endl;
				}
			}
		}
};

int main()
{
	hash h;
	int choice,key;
		do
		{
		cout<<"Enter your Choice"<<endl;
		cout<<"1. Insert the data"<<endl;
		cout<<"2. Display the data"<<endl;
		cout<<"3. Search for a Record"<<endl;
		cout<<"4. QUIT"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: h.accept();
					break;
					
			case 2: h.display();
					break;
					
			case 3: cout<<"Enter the key to be searched"<<endl;\
					cin>>key;
					h.search(key);
					break;
			
			default:
					cout<<"Enter a valid choice"<<endl; 
		}
		}while(choice!=4);
	return 0;
}

/*OUTPUT
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
1
Enter the number of elements to be inserted:
13
Enter the data
18
Enter the name
ABC
Enter the data
41
Enter the name
BCD
Enter the data
22
Enter the name
CDE
Enter the data
44
Enter the name
DEF
Enter the data
45
Enter the name
EFG
Enter the data
59
Enter the name
FGH
Enter the data
32
Enter the name
GHI
Enter the data
31
Enter the name
HIJ
Enter the data
73
Enter the name
IJK
Enter the data
57
Enter the name
JKL
Enter the data
58
Enter the name
KLM
Enter the data
23
Enter the name
LMN
Enter the data
77
Enter the name
MNO
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
2
INDEX   ROLL NO NAME    CHAIN
0       57      JKL     -1
1       58      KLM     -1
2       41      BCD     -1
3       23      LMN     -1
4       77      MNO     -1
5       18      ABC     6
6       44      DEF     11
7       45      EFG     10
8       59      FGH     -1
9       22      CDE     -1
10      32      GHI     1
11      31      HIJ     0
12      73      IJK     -1
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
3
Enter the key to be searched
18
Record Found at position 5
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
3
Enter the key to be searched
31
Record Found at position 11
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
3
Enter the key to be searched
05
Record Not Found in the hash table
Enter your Choice
1. Insert the data
2. Display the data
3. Search for a Record
4. QUIT
4
*/
