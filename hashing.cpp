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
				display();
			}
		}
		void display()
		{
			int i;
			for(i=0;i<SIZE;i++)
			{
				if(s[i].flag==1)
				{
					cout<<i<<"\t"<<s[i].d1.name<<"\t"<<s[i].d1.Roll_no<<"\t"<<s[i].chain<<endl;
				}
			}
		}
};

int main()
{
	hash h;
		h.accept();
	
	return 0;
}
