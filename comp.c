 //program to return the no of components of disconnected graph
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int component();
 int label;
 main()
 {
   int i,v,k; 
   
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   int result =component();
   printf("the number of components = %d\n",result);
   printf ("\nthe vertices and their component numbers");
   for(i=1;i<=n;i++)
     printf("%d---> %d\n",i,visit[i]);

  }
  
  int component()
  {
    int i;
    label=0;
    for(i=1;i<=n;i++)
      visit[i]=0;

    for(i=1;i<=n;i++)
    {
      if(visit[i]==0)
      {
        ++label;
         dfs(i);
     }
   }
   return label;
  }
   

  void dfs(int v)
  {
    int w;
    visit[v]=label;
    for(w=1;w<=n;w++)
    {
      if((a[v][w]==1)&&(visit[w]==0))
        dfs(w);
    }
  }
   

  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=a[j][i]=1;
     }
  }


   

      

     



