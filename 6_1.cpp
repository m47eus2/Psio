#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matrix{
    bool isempty = false;
    vector<vector<int>> v;

  public:
  Matrix(int a, int b)
  {
    for(int i=0; i<a; i++)
    {
        v.emplace_back(vector<int>(b,0));
    }
  }

  Matrix(vector<vector<int>> a)
  {
    v=a;
  }

  Matrix()
  {
    isempty=true;
  }

  pair<int,int> size()
  {
    pair<int,int> ret;
    if(isempty == true)
    {
        ret.first = 0;
        ret.second = 0;
    }
    else
    {
        ret.first = v.size();
        ret.second = v[0].size();
    }
    return ret;
  }

  friend ostream& operator<<(ostream& os, Matrix m)
  {
    if(m.v.size() == 0) os<<"0 0";
    else
    {
        for(int i=0; i<m.v.size(); i++)
        {
            for(int j=0; j<m.v[i].size(); j++)
            {
                os<<m.v[i][j]<<" ";
            }
            os<<endl;
        }
    }
    return os;
  }

  friend istream& operator>>(istream& is, Matrix &m)
  {
    m.v.clear();
    string dimensions;
    is>>dimensions;

    string a = dimensions.substr(0, dimensions.find('x'));
    string b = dimensions.substr(dimensions.find('x')+1);

    for(int i=0; i<stoi(a); i++)
    {
        vector<int> e;
        for(int j=0; j<stoi(b); j++)
        {
            int x;
            is>>x;
            e.emplace_back(x);
        }
        m.v.emplace_back(e);
        e.clear();
    }
    m.isempty=false;
    return is;
  }

  Matrix operator+ (Matrix m)
  {
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            v[i][j] += m.v[i][j];
        }
    }
    return *this;
  }

  Matrix operator+ (int a)
  {
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[0].size(); j++)
        {
            v[i][j] += a;
        }
    }
    return *this;
  }

  Matrix operator* (Matrix m)
  {
    if(v.size()==2 && v[0].size()==2 && m.v.size()==2 && m.v[0].size()==2)
    {
        int a = v[0][0]*m.v[0][0] + v[0][1]*m.v[1][0];
        int b = v[1][0]*m.v[0][0] + v[1][1]*m.v[1][0];

        int c = v[0][0]*m.v[0][1] + v[0][1]*m.v[1][1];
        int d = v[1][0]*m.v[0][1] + v[1][1]*m.v[1][1];

        v[0][0] = a;
        v[1][0] = b;
        v[0][1] = c;
        v[1][1] = d;

    }
    return *this;
  }

    Matrix operator* (int a)
    {
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {
                v[i][j] *= a;
            }
        }
        return *this;
    }
};


Matrix create_by_size()
{
    int a,b;
    cin>>a;
    cin>>b;
    return Matrix(a, b);
}

Matrix create_by_value()
{
    vector<vector<int>> v;
    int a,b,c;
    cin>>a;
    cin>>b;
    for(int i=0; i<a; i++)
    {
        v.emplace_back(vector<int>(b));
        for(int j=0; j<b; j++)
        {
            cin>>c;
            v[i][j] = c;
        }
    }
    return Matrix(v);
}

Matrix create_empty()
{
    return Matrix();
}

int main()
{
    int t;
    Matrix a,b;
    cin>>t;
    switch(t){
        case 1:
            a = create_by_size();
            break;
        case 2:
            a = create_by_value();
            break;
        case 3:
            a = create_empty();
            break;
        case 4:
            a = create_by_size();
            std::cout << a.size().first<< " " <<a.size().second << endl;
            break;
        case 5:
            a = create_by_value();
            std::cout << a.size().first<< " " << a.size().second << endl;
            break;
        case 6: 
            a = create_empty();
            std::cout << a.size().first<< " " << a.size().second << endl;
            break;
        case 7:
            a = create_by_size();
            std::cout << a << endl;
            break;
        case 8:
            a = create_by_value();
            std::cout << a << endl;
            break;
        case 9: 
            a = create_empty();
            std::cout << a << endl;
            break;
        case 10:
            a;
            std::cin>>a;
            std::cout << a << endl;
            break;
        case 11:
            a;
            std::cin>>a;
            std::cout << a.size().first<< " " << a.size().second << endl;
            break;
        case 12:
            a = create_by_value();
            b = create_by_value();
            std::cout << a + b << endl;
            break;
        case 13:
            a = create_by_value();
            b = create_by_value();
            std::cout << a * b << endl;
            break;
        case 14:
            a = create_by_value();
            std::cout << a + 5 << endl;
            break;
        case 15:
            a = create_by_value();
            std::cout << a * 5 << endl;
            break;
        case 16:
            a = create_by_value();
            b = create_by_value();
            std::cout << a + b * 2 + 5 << endl;
            break;
        
        
    }
}