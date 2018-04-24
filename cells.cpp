#include<iostream>
using namespace std;
bool check(int x,int y,int size)//schaut, ob über grenze hinaus
{
	if (x==-1)
		return false;
	if (y==-1)
		return false;
	if (x>=size)
		return false;
	if (y>=size)
		return false;
}
void output(int **field,int size)
{
	for (int i=0;i-2<size;i++)
		cout <<".";
	cout<<endl;
	for(int x=0;x<size;x++)
	{
		cout<<".";
			for(int y=0;y<size;y++)
			{
				if (field[x][y]==1)
					cout << "#";
				else
					cout << " ";
			}
			cout <<"."<< endl;
	}
	for (int i=0;i-2<size;i++)
		cout <<".";
	cout <<endl<< "----------------------------------------------"<<endl;
	return;
}

void life(int **&field,int size)
{
	int count=0;
	int XS=0;
	int YS=0;
	//cursor positionieren--------------------------------------------
	for (int x=0;x<size;x++)
	{
		for (int y=0;y<size;y++)
		{		
			for (int offsetx=0;offsetx<=2;offsetx++)
			{
					for (int offsety=0;offsety<=2;offsety++)
					{
						XS=x+(offsetx-1);
						YS=y+(offsety-1);
						if (check(XS,YS,size)==false||(XS==0&&YS==0))
						{count+=0;}
						else
						{if (field[XS][YS]==1) count++;}
					}
			}
			// bestimmen, was mit x/y passiert------------------------------
			if (count <2 || count >3)
				field[x][y]=0; //und tot
			else 
				if (count ==3)
					field[x][y]=1; //neues leben
			//mutation
			int mutate=0;
			mutate = rand()%6;
			if (mutate==0)
				field[x][y]=0;//kaputtmutiert
			if (mutate==5)
				field[x][y]=1;//stärkere mutation, überlebt!
			count =0;//sonst einfach nix tun
		}
	}
}	
int main()
{
	int size=0;
	char weiter=0;
	cout	<< "Zellulärer Automat:"<<endl
			<< "-------------------"<<endl
			<< "Bitte Groesse der Petrischale einstellen:";
	cin >> size;
	int **field=new int*[size];
	int zufall;
	for (int i=0;i<size;i++)
		field[i]=new int[size];
	for (int x=0;x<size;x++)
		for (int y=0;y<size;y++)
		{
			zufall=rand()%2;
			field[x][y]=zufall;
		}
		output (field,size);
	do
	{
		life(field,size);
		output(field,size);
		cout <<endl<<"one more iteration ?[y/n]";
		cin >>weiter;
	}while(weiter!='n');
	system("PAUSE");
	return 0;
}
