/* #include<iostream>
#include<string>
using namespace std;

class matrix
{
    public:
    int edge,cost;
    
    friend class graph;
};
class graph
{
    matrix m;
    string a[10];
    int n,i;
    public:
    void set_edge(int edge_set)
    {
        m.edge=edge_set;
    }
    void set_cost(int cost_set)
    {
        m.cost = cost_set;
    }
    bool get_src(string city,int i)
    {
        if(a[i] == city)
        return true;
        else
        {
            return false;
        }
        
    }
    bool get_dest(string dest,int i)
    {
        if(a[i] == dest)
        return true;
        else
        {
            return false;
        }
    }
    void set_city(){
        cout<<"\nenter number of cities:";
        cin>>n;
        for(i=0;i<n;i++)
    {
        cin>>a[i];
    }}
    

    
};
int main()
{
    graph m[10][10];
    int n,i,j,k,choice,flag=0;;
    m[0][0].set_city();
    int mat[10][10];
    string source,dest;
    do{
    cout<<"\n1.create matrix\n2.display matrix";
    cin>>choice;
    switch(choice)
    {
        case 1:
                cout<<"\nenter source:";
                cin>>source;
                cout<<"\nenter destination:";
                cin>>dest;
                for(i=0;i<n;i++)
                {
                    if(m[i][i].get_src(source,i) == true)
                    j=i;
                    else
                    {
                        cout<<"\nsource not found";
                        flag=1;
                    }
                    
                    if(m[i][i].get_dest(dest,i) == true)
                    k=i;
                    {
                        cout<<"\ndest not found";

                    }
                    //break;
                }
                if(flag==0)
                {
                m[j][k].set_edge(1);
                m[j][k].set_cost(50);
                mat[j][k]=1;
                }
                else
                {
                    m[j][k].set_edge(0);
                    m[j][k].set_cost(0);
                    mat[j][k]=0;
                }
                
                //break;
        case 2: cout<<"\ndisplaying adjacency matrix";
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        cout<<mat[i][j]<<"\t";
                    }
                    cout<<"\n";
                }
                break;

    }
    }while(choice!=3);
    
    return 0;
} */


#include<iostream>
#include<string>
using namespace std;
class graph
{
    string city[10];
    int i,j,m[10][10],distance[10][10],flags=0,flagd=0;
    public:
    void set_city(int n)
    {
        for(i=0;i<n;i++)
        {
            cin>>city[i];
        }
        
    }
    void set_param(string source,string dest,int n)
    {
        for(i=0;i<n;i++)
        {
            if(source == city[i])
            {
                //cout<<"\nmehak";
            flags=1;
            break;
            }
            
        }
        for(j=0;j<n;j++)
        {
            if(dest == city[j])
            {
                //cout<<"\nmehak";
            flagd=1;
            break;
            }
            
        }
        if(flags==1&&flagd==1)
        {
            //cout<<"\nmehak";
            m[i][j] = 1;
            cout<<"\nenter distance:";
            cin>>distance[i][j];
        }
        else
        {
            m[i][j]=0;
            distance[i][j]=0;
        }
        
    }
    void display(int n)
    {
        //cout<<"\nmatrix is in the form:\n";
        /* for(i=0;i<n;i++)
        {
            cout<<city[i]<<"\t";
        }
        cout<<"\n";
        for(i=0;i<n;i++)
        {
            cout<<city[i]<<"\n";
        } */
        cout<<"\nadjacency matrix is:\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(m[i][j]!=1)
                {
                    m[i][j]=0;
                    distance[i][j]=0;
                }
                cout<<city[i]<<city[j]<<"\t";
                cout<<m[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\ncost/distance matrix is:\n";
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                
                cout<<city[i]<<city[j]<<"\t";
                cout<<distance[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
};

int main()
{
    int n;
    string source,dest;
    graph obj;
    char choice;
    cout<<"\nenter maximum number of cities:";
    cin>>n;
    //naming cities
    obj.set_city(n);
    do
    {
    cout<<"\nenter source:";
    cin>>source;
    cout<<"\nenter destination:";
    cin>>dest;
    //setting edge and distance
    obj.set_param(source,dest,n); 
    cout<<"\ndo you want to continue (y/n):";
    cin>>choice;
    }while(choice!='n');
    //display adjancecy matrix
    cout<<"\nadjacency matrix:\n";
    obj.display(n);    

}