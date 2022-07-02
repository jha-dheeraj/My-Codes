#include<iostream>
#include<vector>


class XClass
{
    private:
        int row;
        int col;
    public:
        void setValue(int x, int y);
        std::vector<std::vector<int> > populate(std::vector<std::vector<int> >& vec);
        bool checkXMatrix(std::vector<std::vector<int> >& grid);
};

void XClass::setValue(int x, int y)
{
    this->row=x;
    this->col=y;

}

std::vector< std::vector< int > > XClass::populate(std::vector< std::vector< int > >& vec)
{
    std::cout<<"\nEnter the elements now:"<<std::endl;
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->col;j++)
        {
            std::cin>>vec[i][j];
        }
    }

    std::cout<<"\nEntered values are:"<<std::endl;
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->col;j++)
        {
            std::cout<<vec[i][j];
        }
        std::cout<<"\n";
    }
    return vec;
}

bool XClass::checkXMatrix(std::vector<std::vector<int> >& grid)
{
    int flag=0;
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->col;j++)
        {
            if(i==j || i+j==this->row-1)
            {
                /* digonal */
                std::cout<<"pos["<<i<<"]["<<j<<"]="<<grid[i][j]<<std::endl;
                if(grid[i][j]==0)
                {
                    flag=1;
                    break;
                }
                
            } else
            {
                /*Non Digonal*/
                std::cout<<"pos["<<i<<"]["<<j<<"]="<<grid[i][j]<<std::endl;
                if(grid[i][j]!=0)
                {
                    flag=1;
                    break;
                }
            }
            
        }
    }
    if(flag==1)
        return false;
    else
        return true;

/* Method 2:

int flag=0;
    for(int i=0;i<grid[0].size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(i==j || i+j==grid[0].size()-1)
            {
                if(grid[i][j]==0)
                {
                    flag=1;
                    break;
                }
                
            } else
            {
                if(grid[i][j]!=0)
                {
                    flag=1;
                    break;
                }
            }
            
        }
    }
    if(flag==1)
        return false;
    else
        return true;
        
    }
*/
}

int main()
{
    int m,n;
    XClass obj;
    std::cout<<"\nEnter rows and colums:"<<std::endl;
    std::cin>>m>>n;
    obj.setValue(m,n);
    std::vector< std::vector< int > > vec(m, std::vector<int>(n,0));
    vec=obj.populate(vec);
    if(obj.checkXMatrix(vec))
        std::cout<<"This is a X matrix"<<std::endl;
    else
        std::cout<<"This is not a X matrix"<<std::endl;

    return 0;
}