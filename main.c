#include <stdio.h>                          
#include <stdlib.h>
#include <time.h>

// A Brute-force approach

void solve_sudoku2(int[][9] , int ); //Declaring
void solve_sudoku1(int p[][9]);

void copy_arr(int p[][9] , int p_dummy[][9] )
{

	for(int i=0; i<9; i=i+1)
	{
		for(int j=0; j<9; j=j+1)
		{
			p_dummy[i][j]=p[i][j];
				}

			}
}


int which_sqr(int row,int column )          // INPUT IS THE LOCATION OF SUDOKU, IT TELLS IN WHICH 3x3 BOX DOES THE LOCATION LIES.
{
    if ((row>=0)&&(row<=2))
    {
        if ((column>=0)&&(column<=2))
        {
            return 1;
        }
         if ((column>=3)&&(column<=5))
        {
            return 2;
        }
         if ((column>=6)&&(column<=8))
        {
            return 3;
        }
    }
          if ((row>=3)&&(row<=5))
    {
        if ((column>=0)&&(column<=2))
        {
            return 4;
        }
         if ((column>=3)&&(column<=5))
        {
            return 5;
        }
         if ((column>=6)&&(column<=8))
        {
            return 6;
        }
    }
          if ((row>=6)&&(row<=8))
    {
        if ((column>=0)&&(column<=2))
        {
            return 7;
        }
         if ((column>=3)&&(column<=5))
        {
            return 8;
        }
         if ((column>=6)&&(column<=8))
        {
            return 9;
        }

    }
     else {return 0; }
}


int check_sqr(int p[][9],int i,int j,int value)                     /* CHECKS THAT A GIVEN VALUE IS FIT FOR THAT PLACE BY ONLY
                                                                                        CHECKING THE CORRESPONDING 3x3 BOX. */
{
    int n=which_sqr(i,j),k,l,yes=1,y,z;
    if (n==1)
    {
        k=0;
        l=0;
    }
      if (n==2)
    {
        k=0;
        l=3;
    }
 if (n==3)
    {
        k=0;
        l=6;
    }
     if (n==4)
    {
        k=3;
        l=0;
    }
      if (n==5)
    {
        k=3;
        l=3;
    }
     if (n==6)
    {
        k=3;
        l=6;
    }
    if (n==7)
    {
        k=6;
        l=0;
    }
    if (n==8)
    {
        k=6;
        l=3;
    }
    if (n==9)
    {
        k=6;
        l=6;
    }
    for(y=0;y<3;y=y+1)
    {
        for (z=0;z<3;z=z+1)
        {
            if (p[k+y][l+z]==value)
            {
                yes=0;
            }
        }
    }
    return yes;
}

int check_column(int p[][9],int i,int j,int value)                       /* CHECKS THAT A GIVEN VALUE IS FIT FOR THAT PLACE BY ONLY
                                                                                        CHECKING THE CORRESPONDING COLUMN. */
{
    int yes=1,k;
    for (k=0;k<9;k=k+1)
    {
        if (p[k][j]==value)
        {
            yes=0;
        }
    }
    return yes;
}
int check_row(int p[][9],int i,int j,int value)                      /* CHECKS THAT A GIVEN VALUE IS FIT FOR THAT PLACE BY ONLY
                                                                                        CHECKING THE CORRESPONDING ROW. */
{
    int yes=1,k;
    for(k=0;k<9;k=k+1)
    {
        if (p[i][k]==value)
        {
            yes=0;
        }
    }
    return yes;
}

int check_completion(int p[][9])
{
    int a,b;
    for (a=0;a<9;a=a+1)
    {
        for(b=0;b<9;b=b+1)
        {
            if (p[a][b]==0)
            {
		
                return 0;
            }
        }
    }
	
    return 1;
}

int if_apt(int p[][9],int i,int j,int value)			            // Check if the current entry ie. value, is appropriate for 
{									    // position i,j
   int a,b,c;
   a= check_sqr(p,i,j,value);
   b=check_column(p,i,j,value);
   c=check_row(p,i,j,value);
   if(a+b+c==3)
   {
       return 1;
   }
   else {return 0;}
}
int sd_put_column(int p[][9],int i,int j,int value, int tae)             // Checks if a number ie. value can only be placed at one row(i) 
									 //position for a particular column (j)
{
    if (p[i][j]!=0){return 0;}
    int u,count=0,m=-1,cunt=0;
    for (u=0;u<9;u=u+1)
    {
        if ((if_apt(p,u,j,value))&&p[u][j]==0)
        {		
            count =count+1;
            m=u;
        }
    }
    if ((count == 1)&&(m==i))
    {
        return 1;
    }
    if ((count>0)&&tae==1){
	p[i][j] =value;
	int p_dummy[9][9];
	copy_arr(p,p_dummy);
	while (!check_completion(p_dummy)&&(cunt<10))
    	{
        	solve_sudoku2(p_dummy,0);     //New and improved method
        	cunt=cunt+1;
    		}
	if (check_completion(p_dummy))
		{
		copy_arr(p_dummy,p);
		return 2;}
	else {p[i][j] =0;
	      return 0;		}
	}
    return 0;
}
int sd_put_row(int p[][9],int i,int j,int value, int tae)    // Checks if a number ie. value can only be placed at one column(i) 
									 //position for a particular column (j)
{
    if (p[i][j]!=0){return 0;}
    int u,count=0,m=-1,cunt=0;
    for (u=0;u<9;u=u+1)
    {
        if ((if_apt(p,i,u,value))&&p[i][u]==0)
        {
            count =count+1;
            m=u;
        }
    }
    if ((count == 1)&&(m==j))
    {
        return 1;
    }
    if ((count>0)&&tae==1){
	p[i][j] =value;
	int p_dummy[9][9];
	copy_arr(p,p_dummy);
	while (!check_completion(p_dummy)&&(cunt<10))
    	{      
        	solve_sudoku2(p_dummy,0);     //New and improved method
        	cunt=cunt+1;
    		}
	if (check_completion(p_dummy))
		{
		copy_arr(p_dummy,p);
		return 2;}
	else {p[i][j] =0;
	      return 0;		}
	}
    return 0;
}

int sd_put_sqr(int p[][9], int n,int h, int a,int b, int tae)
{
    int y,z,k,l,count=0,v=-1,c=-1,cunt=0;
        if (n==1)
    {
        k=0;
        l=0;
    }
      if (n==2)
    {
        k=0;
        l=3;
    }
 if (n==3)
    {
        k=0;
        l=6;
    }
     if (n==4)
    {
        k=3;
        l=0;
    }
      if (n==5)
    {
        k=3;
        l=3;
    }
     if (n==6)
    {
        k=3;
        l=6;
    }
    if (n==7)
    {
        k=6;
        l=0;
    }
    if (n==8)
    {
        k=6;
        l=3;
    }
    if (n==9)
    {
        k=6;
        l=6;
    }

    if (p[k+a][l+b]!=0){return 0;}

      for(y=0;y<3;y=y+1)
    {
        for (z=0;z<3;z=z+1)
        {
            if ((if_apt(p,k+y,l+z,h))&&p[k+y][l+z]==0)
            {
                count=count+1;
                v=y;
                c=z;
            }
        }
    }
   if ((count==1)&&(a==v)&&(b==c))
   {
       return 1;
   }

   if ((count>0)&&tae==1){
	p[k+a][l+b] =h;
	int p_dummy[9][9];
	copy_arr(p,p_dummy);
	while (!check_completion(p_dummy)&&(cunt<10))
    	{
        	solve_sudoku2(p_dummy,0);     //New and improved method
        	cunt=cunt+1;
    		}
	if (check_completion(p_dummy))
		{
		    copy_arr(p_dummy,p);
		    return 2;}
	else {p[k+a][l+b] =0;
	      return 0;		}
	}
    return 0;
}
void do_column(int p[][9], int j, int tae)
{
    int h=1,u;
    while (h<10)
    {
        for (u=0;u<9;u=u+1)
        {
	    int temp_col=sd_put_column(p,u,j,h,tae);
            if (temp_col==1)
           {
               p[u][j] =h;
           }
 	   if (temp_col==2)
           {
               break; 
           }
        }
        h=h+1;
    }
}
void do_row(int p[][9],int i, int tae)
{
    int h=1,u;
    while (h<10)
    {
        for (u=0;u<9;u=u+1)
        {    int temp_row=sd_put_row(p,i,u,h,tae);
            if (temp_row==1)
              {p[i][u] =h;}

	    if (temp_row==2)
              {break;}
        }

      h=h+1;
    }
}
void do_square(int p[][9],int n,int tae)
{
    int k,l,h=1,y,z;
    if (n==1)
    {
        k=0;
        l=0;
    }
      if (n==2)
    {
        k=0;
        l=3;
    }
 if (n==3)
    {
        k=0;
        l=6;
    }
     if (n==4)
    {
        k=3;
        l=0;
    }
      if (n==5)
    {
        k=3;
        l=3;
    }
     if (n==6)
    {
        k=3;
        l=6;
    }
    if (n==7)
    {
        k=6;
        l=0;
    }
    if (n==8)
    {
        k=6;
        l=3;
    }
    if (n==9)
    {
        k=6;
        l=6;
    }
    while (h<10)
    {
      for(y=0;y<3;y=y+1)
    {
        for (z=0;z<3;z=z+1)
        {   
            int temp_sqr=sd_put_sqr(p,n,h,y,z,tae); 
            if (temp_sqr==1)
            {
                p[k+y][l+z]=h;
            }
	   if (temp_sqr==2)
            {
                break;
            }
        }
    }
    h=h+1;
}
}
void solve_sudoku2(int p[][9], int tae)       
{
    int i;
    for(i=0;i<9;i=i+1)
    {
	if (!check_completion(p)){
	solve_sudoku1(p);    //Old method
        do_square(p,i+1,tae);
        do_row(p,i,tae);
        do_column(p,i,tae);
	}
    }
}


int can_put(int p[][9],int i, int j)
{
     int h=1,t=0,n;
    while(h<10)
    {
        if (if_apt(p,i,j,h))
        {
            t=t+1;
            n=h;
        }
        h=h+1;
   }
   if (t==1)
   {
    return n;
   }
  if (t !=1)
   {
       return 0;}
}
void put_correct(int p[][9],int i,int j)
{
   p[i][j]=can_put(p,i,j);
}
void solve_sudoku1(int p[][9])
{
    int a,b;
    for (a=0;a<9;a=a+1)
    {
        for(b=0;b<9;b=b+1)
        {
            if (p[a][b]==0)
            {
                put_correct(p,a,b);
            }
        }
    }
}
int main()
{
    printf("Welcome to Vineet's Sudoku solver.\n");
    printf("INSTRUCTIONS:\n");
    printf("1: Enter the 9X9 Sudoku puzzle.(Use '0' in the place of blank and give space between each entry)\n");
    printf("2: The solver might take some time, please be patient after entering the puzzle.\n");
    printf("3: Please check each row before hitting 'Enter'.\n");
    printf("4: A typical row will look like: 0 9 0 0 0 0 0 0 5\n");
    printf("_________________________________________________________________________________________\n\n\n\n");
    int p[9][9];
    int count=1;
    int iter=3;

    int i=0,j=0;

   for (i=0;i<=8;i=i+1)
    {
        for(j=0;j<=8;j=j+1)
        {
            scanf("%d",&p[i][j]);
        }
    }

    clock_t start,end;
    double time_used;
    start=clock();

    while (!check_completion(p)&&(count<iter))
    {
        solve_sudoku2(p,1);     //New and improved method
        count=count+1;
    }

    if (check_completion(p))
    {
     end=clock();
     time_used=((double)(end-start))/CLOCKS_PER_SEC;
     printf("\nTime required to solve the puzzle: %f seconds\n", time_used);
     printf("Solved puzzle: \n");
     
     for (int a=0;a<9;a=a+1)
     {
         for(int b=0;b<9;b=b+1)
         {
             printf("%d ",p[a][b]);
         }
         printf("\n");
     }
      printf("\nThank you for using Vineet's Sudoku solver!!\n\n");
    
    }
    else{
	printf("Wrong input!! Please check your input and try again\n");
        printf("If you think your input is correct and the algorithm is incapable of solving the puzzle,\nplease e-mail at: anand.vineet19@gmail.com\n");
        printf("Partially Solved puzzle: \n");
    int a,b;
    for (a=0;a<9;a=a+1)
    {
        for(b=0;b<9;b=b+1)
        {
            printf("%d ",p[a][b]);
        }
        printf("\n");
    } 
	}

    return 1;
}
