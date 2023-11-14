#include<bits/stdc++.h>
#include<time.h>
#include<graphics.h>

using namespace std;

//function to find min
int min(int a, int b)
{
	int res = a;
	if(b < a)
		res = b;
	return res;
}
//function to find longest common subsequence
//we will find a sequence of 4 or 8 zeroes
int LCS(int pattern1[], int pattern2[], int n, int m)
{
    int index=-1;
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (pattern1[i] == pattern2[j])
            {
				dp[i][j] = dp[i + 1][j + 1] + 1;
				if(dp[i][j]==m)
                   index=i;
            }
		}
	}
	return index;
}
// function to find four consecutive zeroes
void fourbitszero(int* s,int size,int* x)
{
    for(int i=0;i<10;i++)
        x[i]=-1;
    int start=0,count=0,i=0,j=0;
    while(i<size)
    {
       while(i<size&&s[i]==1)
       {
          i++;
       }
      start=i;
       while(i<size&&s[i]==0&&count<4)
       {
          count++;
           i++;
       }
      if(count==4)
       {
          count=0;
          x[j]=start;
            j++;
       }
       else
        count=0;

    }
}
// function to find 8 consecutive zeroes
void eightbitszero(int* s,int size,int* x)
{
    for(int i=0;i<3;i++)
        x[i]=-1;
    int start=0,count=0,i=0,j=0;
    while(i<size)
    {
       while(i<size&&s[i]==1)
       {
          i++;
       }
      start=i;
       while(i<size&&s[i]==0&&count<8)
       {
          count++;
           i++;
       }
      if(count==8)
       {
          count=0;
          x[j]=start;
            j++;
       }
       else
        count=0;
    }
}

//function to apply NRZ-L encoding scheme and plotting using graphics library
void NRZL(int* s,int size)
{
 int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size;i++,x=x+20,m=m+20)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);

        if(s[i])
        {
            if(i!=0&&s[i]!=s[i-1])
            line(x,y,x,y-20);

            line(x,y-20,x+20,y-20);
            if(i==size-1||(i<size-1&&s[i]!=s[i+1]))
            line(x+20,y-20,x+20,y);
                     settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
        }
        else{
                if(i!=0&&s[i]!=s[i-1])
             line(x,y,x,y+20);

            line(x,y+20,x+20,y+20);
            if(i==size-1||(i<size-1&&s[i]!=s[i+1]))
            line(x+20,y+20,x+20,y);
               settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
        }

	}
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"NRZ-L ENCODING");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE ");
	getch();
	closegraph();
}
//function to apply NRZ-I encoding scheme and plotting using graphics library
void NRZI(int* s,int* en,int size,int size1)
{
 int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+20)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);

        if(en[i])
        {
            if(i!=0&&en[i]!=en[i-1])
            line(x,y,x,y-20);

            line(x,y-20,x+20,y-20);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+20,y-20,x+20,y);

        }
        else{
                if(i!=0&&en[i]!=en[i-1])
             line(x,y,x,y+20);

            line(x,y+20,x+20,y+20);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+20,y+20,x+20,y);

        }

	}
     for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }

       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"NRZ-I ENCODING");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE");
	getch();
	closegraph();
}
//function to apply Manchester encoding scheme and plotting using graphics library
void Manchester(int* s,int size,int* en,int size1)
{
     int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+10)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);
 if(en[i]){
                if(i!=0&&en[i]!=en[i-1])
             line(x,y,x,y+10);

            line(x,y+10,x+10,y+10);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+10,y+10,x+10,y);

        }
        else
        {
            if(i!=0&&en[i]!=en[i-1])
            line(x,y,x,y-10);

            line(x,y-10,x+10,y-10);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+10,y-10,x+10,y);

        }
       
	}
     for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"MANCHESTER'S ENCODING");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE ");
	getch();
	closegraph();
}
//function to apply Differential Manchester encoding scheme and plotting using graphics library
void DManchester(int* s,int size,int* en,int size1)
{
     int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+10)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);

        if(en[i])
        {
            if(i!=0&&en[i]!=en[i-1])
            line(x,y,x,y-10);

            line(x,y-10,x+10,y-10);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+10,y-10,x+10,y);

        }
        else{
                if(i!=0&&en[i]!=en[i-1])
             line(x,y,x,y+10);

            line(x,y+10,x+10,y+10);
            if(i==size1-1||(i<size1-1&&en[i]!=en[i+1]))
            line(x+10,y+10,x+10,y);

        }

	}
     for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"DIFFERENTIAL MANCHESTER'S ENCODING");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE");
	getch();
	closegraph();
}
//function to apply AMI encoding scheme and plotting using graphics library
void AMI(int* s,int size,int* en,int size1)
{
 int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+20)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);


	    if(en[i]==-1)
            continue;
        if(en[i]==1)
        {
            line(x,y,x,y-20);

            line(x,y-20,x+20,y-20);

            line(x+20,y-20,x+20,y);

        }
        else{

             line(x,y,x,y+20);

            line(x,y+20,x+20,y+20);

            line(x+20,y+20,x+20,y);

        }
	}
for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"AMI ENCODING");
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE");
	getch();
	closegraph();
}
//function to apply B8ZS Scrambling and plotting using graphics library
void B8ZS(int* s,int size,int* en,int size1)
{
 int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+20)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);


	    if(en[i]==-1)
            continue;
        if(en[i]==1)
        {
            line(x,y,x,y-20);
            line(x,y-20,x+20,y-20);
            line(x+20,y-20,x+20,y);
        }
        else{
             line(x,y,x,y+20);
            line(x,y+20,x+20,y+20);
            line(x+20,y+20,x+20,y);
        }
	}
for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"AMI ENCODING ALONG WITH B8ZS SCRAMBLING");
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE");
	getch();
	closegraph();
}
//function to apply HDB3 Scrambling and plotting using graphics library
void HDB3(int* s,int size,int* en,int size1)
{
 int gd = DETECT, gm;
	int x=10;
	int i=0;
	int y=100;
	int m=18;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	for(i=0;i<size1;i++,x=x+20)
	{
	  line(10, 100, 610, 100);
	line(10, 50, 10, 150);
	    if(en[i]==-1)
            continue;
        if(en[i]==1)
        {
            line(x,y,x,y-20);
            line(x,y-20,x+20,y-20);
            line(x+20,y-20,x+20,y);
        }
        else{
             line(x,y,x,y+20);
            line(x,y+20,x+20,y+20);
            line(x+20,y+20,x+20,y);
        }
	}
for(int j=0;j<size;j++,m=m+20)
     {
         if(s[j])
         {
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"1");
         }
         else
         {
       settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(m,60,"0");
         }
     }
                 settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,180,"OUTPUT PLOT");
           settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-100,"AMI ENCODING WITH HDB3 SCRAMBLING");
         settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()-20,"* PRESS ANY KEY TO CONTINUE");
	getch();
	closegraph();
}

// function to generate random sequence of binary data
int* generate_comp_rand(int n)
{

    int* s=new int[n];
   srand(time(0));
   for(int i=0;i<n;i++ )
   s[i]=rand()%2;
	return s;
}

int main()
{
	srand(time(0));
	int input;
	int encoding;
	int scrambling=-1;
	int stype=-1;
	string str;
	system("Color 02");
	cout<<"------------------ WELCOME TO LINE ENCODING PROJECT ---------------------\n";
	//
    cout<<"enter your signal type"<<endl;
    cout<<"1.Digital"<<endl;
    cout<<"2.Analog"<<endl;
    int signalty;
    cin>>signalty;
    //
    if(signalty==1){
    cout<<"Enter your choice for data generation."<<endl;
	cout<<"\n";
	system("Color 02");
	cout<<"1- your sequence\n";
	cout<<"\n";
	cout<<"2-  Random sequence \n";

    int* s;
    int size;
	cin>>input;

		switch(input)
	{
		case 1:
	      {
			cout<<"Enter your pattern\n";
			cin>>str;
        	int n1=5+rand()%7;
            int n2=5+rand()%7;
       	    int * x=generate_comp_rand(n1);
       	    int * y=generate_comp_rand(n2);
       	    //size=n1+str.length()+n2;
            size=str.length();
       	    s=new int[size];
       	    for(int i=0;i<size;i++)
       	    {s[i]=str[i]-'0';
       	    	// if(i<n1)
       	        //  s[i]=x[i];
				// 	else if(i<n1+str.length())
				// 	s[i]=str[i-n1]-'0';
				// 	else
				// 	s[i]=y[i-n1-str.length()];
			}
			cout<<endl;

			break;
		}
		case 2:
            int n=20+rand()%9;
            s=generate_comp_rand(n);
            size=n;
		    break;
	}
    cout<<"FOLLOWING IS OUR INPUT:"<<endl;
			for(int i=0;i<size;i++)
			cout<<s[i];
			cout<<endl;
	cout<<"\n";
	cout<<"Enter type of encoding for the input\n";
	cout<<"\n";
	cout<<"1- NRZ-L\n";
	cout<<"\n";
	cout<<"2- NRZ-I\n";
	cout<<"\n";
	cout<<"3- Manchester\n";
	cout<<"\n";
	cout<<"4- Differential Manchester\n";
	cout<<"\n";
	cout<<"5- AMI\n";
	cout<<"\n";
	cin>>encoding;
	if(encoding==5)
	{
		cout<<"Do you want scrambling\n";
		cout<<endl;
		cout<<"1- Yes"<<endl;
		cout<<endl;
		cout<<"2- No"<<endl;
		cout<<endl;
		cin>>scrambling;
		if(scrambling==1)
        {
            cout<<"choose scrambling"<<endl;
            cout<<"1- B8ZS"<<endl;
            cout<<"2- HDB3"<<endl;
            cin>>stype;
        }
	}
	int *en;
    switch(encoding)
    {
    case 1:
        {
           NRZL(s,size);
           break;
        }
    case 2:
        {
         en=new int[size];
         en[0]=!s[0];
         for(int i=1;i<size;i++)
         {
             if(s[i]==1)
             en[i]=!en[i-1];
             else
                en[i]=en[i-1];
         }
         NRZI(s,en,size,size);
         break;
        }
    case 3:
        {
        en=new int[2*size];

        for(int i=0,j=0;i<size;i++,j=j+2)
        {
            if(s[i])
            {
                en[j]=1;
                en[j+1]=0;
            }
            else
            {
                en[j]=0;
                en[j+1]=1;
            }
        }
        Manchester(s,size,en,2*size);
        break;
        }
    case 4:
        {
         en=new int[2*size];
         if(s[0])
         {
             en[0]=1;
             en[1]=0;
         }
         else
         {
             en[0]=0;
             en[1]=1;
         }
         for(int i=1,j=2;i<size;i++,j++)
         {
           if(s[i])
           {
               en[j]=en[j-1];
               j++;
               en[j]=!en[j-1];
           }
           else
           {
               en[j]=!en[j-1];
               j++;
               en[j]=!en[j-1];
           }
         }
       //  for(int i=0;i<2*size;i++)
         //   cout<<en[i];
        DManchester(s,size,en,2*size);
        }
    case 5:
        {
            if(scrambling==2)
            {
            int flag=1;
            en=new int[size];
            for(int i=0;i<size;i++)
            {
                if(s[i])
                {
                    en[i]=flag;
                    flag=!flag;
                }
                else
                {
                    en[i]=-1;
                }
            }
            AMI(s,size,en,size);
            }
            else if(scrambling==1)
            {
                if(stype==1)
                {

                    int *x;
                    x=new int[3];

                    eightbitszero(s,size,x);
                    int flag=1;
                    en=new int[size];
                    for(int i=0;i<size;i++)
                      {
                        if(s[i])
                        {
                         en[i]=flag;
                         flag=!flag;
                       }
                      else
                      {
                       en[i]=-1;
                       }
                      }
                    for(int i=0;i<3;i++)
                    {
                      if(x[i]==-1)
                       break;
                      else
                      {
                          int v=x[i];
                          while(v>=0&&en[v]==-1)
                            v--;
                            int flag1;
                            if(v==-1)
                                flag1=1;
                            else
                          flag1=en[v];
                          v=x[i];
                          v+=3;
                          en[v]=flag1;
                          v++;
                          en[v]=!flag1;
                          flag1=!flag1;
                          v++;
                          v++;
                          en[v]=flag1;
                          v++;
                          en[v]=!flag1;
                          flag1=!flag1;
                      }
                    }
                     cout<<endl<<"SCRAMBLED DATA IS:"<<endl;
                     for(int i=0;i<size;i++)
                     {
                         if(en[i]==-1)
                            cout<<0;
                         else
                            cout<<1;
                     }
                     cout<<endl;
                        B8ZS(s,size,en,size);
                }
                else if(stype==2)
                {
                    int *x;
                    x=new int[10];
                    fourbitszero(s,size,x);

                    int flag=1;
                    en=new int[size];
                    for(int i=0;i<size;i++)
                      {
                        if(s[i])
                        {
                         en[i]=flag;
                         flag=!flag;
                       }
                      else
                      {
                       en[i]=-1;
                       }
                      }
                      cout<<endl;

                      for(int i=0;i<10;i++)
                    {
                      if(x[i]==-1)
                       break;
                      else
                      {
                          int v=-1,u=x[i];
                          int parity=0;
                          u--;
                          while(u>=0)
                            {
                               if(v==-1&&en[u]!=-1)
                               {
                                v=u;
                                parity++;
                               }
                               else if(en[u]!=-1)
                                parity++;
                               u--;
                            }
                            parity=parity%2;
                            int flag1;
                            if(v==-1)
                                flag1=1;
                            else
                            flag1=en[v];
                          v=x[i];

                          if(parity)
                          {
                              v+=3;
                              en[v]=flag1;
                          }
                          else
                          {
                              if(v==0)
                              {
                                  en[v]=1;
                                v+=3;
                                en[v]=1;
                              }
                              else
                              {
                              en[v]=!flag1;
                              flag1=!flag1;
                              v+=3;
                              en[v]=flag1;
                              flag1=!flag1;
                              }
                            for(int p=v+1;p<size;p++)
                            {
                                if(en[p]!=-1)
                                {
                                    en[p]=!en[p];
                                }
                            }
                          }
                      }
                    }
                     cout<<endl<<"SCRAMBLED DATA IS:"<<endl;
                     for(int i=0;i<size;i++)
                     {
                         if(en[i]==-1)
                            cout<<0;
                         else
                            cout<<1;
                     }
                     cout<<endl;
                   HDB3(s,size,en,size);
                }
            }
            break;
        }
    }
    cout<<endl;}
    else cout<<"your signal is analog";
        cout<<endl<<"THANK YOU"<<endl;

	cout<<"\n";

}
