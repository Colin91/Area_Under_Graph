#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

double Y_Value(double);
double Square(double,double);
double get_Y_Highest_Value(double*,int);
double get_Y_Lowest_Value(double*,int);
double get_Y_MidPoint_Value(double,double);
double Adjust_Height(double,double);

int main()
{
    //First example x = y
    double Period = 0.05; //precision
    double Height = 0;
    double SquareArea = 0;
    double AreaUnderGraph=0;
    double Right_Range = 0;
    double Left_Range = 0;
    double Range = 0;
    double LowestValue;
    double HighestValue;
    cout<<"Set Range : "<<endl;
    cout<<"Set Left Value : "<<endl;
    cin>>Left_Range;
    cout<<"Set Right Value : "<<endl;
    cin>>Right_Range;


    double Counter = Left_Range;
    Range = (Right_Range - Left_Range);
    int Set = (Range/Period)+2;

    double* X_Values = new double[Set];
    double* Y_Values = new double[Set];

    for(int x=0;x<Set;x++)
    {
        X_Values[x] = Counter;
        Counter=Counter+Period;
        cout<<x<<"| "<<setprecision(5)<<X_Values[x]<<endl;
    }
    Counter=0;

    for(int x=0;x<Set;x++) //x=y
    {
        Y_Values[x] = Y_Value(X_Values[x]);
        Counter++;
    }

    LowestValue = get_Y_Lowest_Value(Y_Values,Set);
    HighestValue= get_Y_Highest_Value(Y_Values,Set);

    cout<<""<<LowestValue<<endl;
    cout<<""<<HighestValue<<endl;


    int PeriodicSet;
    for(int x=0;x<Set;x++)
    {
        PeriodicSet = Range/10;
        Height = Adjust_Height(Y_Values[x],Height);
        SquareArea = Square(Height,Period);
        cout<<setprecision(5)<<AreaUnderGraph<<endl;
        AreaUnderGraph = AreaUnderGraph + SquareArea;
    }

    cout<<setprecision(5)<<"      "<<AreaUnderGraph;
    return 0;
}

double Work_Equation(string EQ_In)
{

}

double Adjust_Height(double Y_Value_In,double Height_In)
{
    double New_Height = Height_In-(Height_In - Y_Value_In);
    return New_Height;
}

double get_Y_MidPoint_Value(double Y_Value_In,double Prev_Y_Value_In) //get the Midpoint of the width
{
    double Difference = Y_Value_In-Prev_Y_Value_In;
    Difference = Difference/2;
    Prev_Y_Value_In = Prev_Y_Value_In + Difference;
    return Difference;
}

double get_Y_Highest_Value(double* Y_Values_In,int Set_In) //get Highest Value of Y from equation to determine Height of Square
{
    double MAX;
    MAX = Y_Values_In[0];
    for(int x=0;x<Set_In;x++)
    {
        if(Y_Values_In[x]>MAX)
        {
            MAX = Y_Values_In[x];
        }
    }
    return MAX;
}

double get_Y_Lowest_Value(double* Y_Values_In,int Set_In)
{
    double MIN;
    double *Pointer;
    MIN = Y_Values_In[0];
    for(int x=0;x<Set_In;x++)
    {
        if(Y_Values_In[x]<MIN)
        {
            MIN = Y_Values_In[x];
        }
    }
    return MIN;

}

double Y_Value(double Equation_In) //input x in first example (y=x)
{
    return Equation_In;
}

double Square(double Length_In,double Width_In)
{
    double Area = Length_In*Width_In;
    return Area;
}
