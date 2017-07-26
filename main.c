#include <stdio.h>                          
#include <stdlib.h>

// A Brute-force approach


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

int if_apt(int p[][9],int i,int j,int value)
{
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
int sd_put_column(int p[][9],int i,int j,int value)                         // DEKH LO YAAR....
{
    int u,count=0,m=-1;
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
    else {return 0;}
}
int sd_put_row(int p[][9],int i,int j,int value)
{
    int u,count=0,m=-1;
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
    else {return 0;}
}

int sd_put_sqr(int p[][9], int n,int h, int a,int b)
{
    int y,z,k,l,count=0,v=-1,c=-1;
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
   else{return 0;}
}
void do_column(int p[][9], int j)
{
    int h=1,u;
    while (h<10)
    {
        for (u=0;u<9;u=u+1)
        {
            if (sd_put_column(p,u,j,h))
           {
               p[u][j] =h;
           }
        }
        h=h+1;
    }
}
void do_row(int p[][9],int i)
{
    int h=1,u;
    while (h<10)
    {
        for (u=0;u<9;u=u+1)
        {
            if (sd_put_row(p,i,u,h))
           {p[i][u] =h;}
        }
        h=h+1;
    }
}
void do_square(int p[][9],int n)
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
            if (sd_put_sqr(p,n,h,y,z))
            {
                p[k+y][l+z]=h;
            }
        }
    }
    h=h+1;
}
}
void solve_sudoku2(int p[][9])
{
    int i;
    for(i=0;i<9;i=i+1)
    {
        do_square(p,i+1);
        do_row(p,i);
        do_column(p,i);
    }
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
    printf("Welcome tO Vineet's Sudoku solver.\n");
    printf("INSTRUCTIONS:\n");
    printf("1: Enter the 9X9 Sudoku puzzle.(Use '0' in the place of blank and give space between each entry)\n");
    printf("2: The solver might take some time, please be patient after entering the puzzle.\n");
    printf("3: Please check each row before hitting 'Enter'.\n");
    printf("4: A typical row will look like: 0 9 0 0 0 0 0 0 5\n");
    printf("_________________________________________________________________________________________\n\n\n\n");
    int p[9][9];
    int count=1;

    int i=0,j=0;

   for (i=0;i<=8;i=i+1)
    {
        for(j=0;j<=8;j=j+1)
        {
            scanf("%d",&p[i][j]);
        }
    }

    // This is for testing 
    /*p[0]=//('0','0','0','0','0','1','0','4','0');
    p[][1]={0,9,0,0,0,0,0,0,5};
    p[][2]={3,0,4,0,2,6,0,7,0};
    p[][3]={8,0,0,0,0,0,1,0,9};
    p[][4]={0,0,0,0,4,0,0,0,0};
    p[][5]={6,0,2,0,0,0,0,0,3};
    p[][6]={0,1,0,7,5,0,2,0,8};
    p[][7]={0,1,0,7,5,0,2,0,8};
    p[][8]={9,0,0,0,0,0,0,6,0};
    p[][9]={0,7,0,9,0,0,0,0,0};*/


    while (!check_completion(p)&&(count<1000))
    {
        solve_sudoku1(p);
        solve_sudoku2(p);
        count=count+1;
    }
    if (count<999)
    {
     printf("\n\nThank you for using Vineet's Sudoku solver\n"); 
    printf("Solved puzzle: \n");
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
    else{
        printf("\nSorry, the algorithm could not solve the input puzzle.\n");
	printf("Either the input was wrong or the puzzle requires a trail and error step, which the algorithm is incapable of.\n");
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
