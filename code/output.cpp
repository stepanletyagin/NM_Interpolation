#include "output.h"

void Output(vector<pair<VALUE_TYPE,VALUE_TYPE>> &Table, char grid, int name)
{
    ofstream fout;

    switch(grid)
    {
        case 'U':
        {
            switch(name)
            {
                case 1:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_1/F1_UniformGrid.txt", ios_base::trunc);
                    break;
                }
                case 2:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_2/F2_UniformGrid.txt", ios_base::trunc);
                    break;
                }
                case 3:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_3/F3_UniformGrid.txt", ios_base::trunc);
                    break;
                }
                case 4:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_4/F4_UniformGrid.txt", ios_base::trunc);
                    break;
                }
                case 5:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_1/Lagrange_Interpolation/F1_UniformGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 6:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_2/Lagrange_Interpolation/F2_UniformGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 7:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_3/Lagrange_Interpolation/F3_UniformGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 8:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_4/Lagrange_Interpolation/F4_UniformGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 9:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_1/Spline_Interpolation/F1_UniformGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 10:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_2/Spline_Interpolation/F2_UniformGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 11:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_3/Spline_Interpolation/F3_UniformGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 12:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Uniform_Grid/Test_4/Spline_Interpolation/F4_UniformGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                default: break;
            }
            break;
        }

        case 'C':
        {
            switch(name)
            {
                case 1:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_1/F1_ChebyshevGrid.txt", ios_base::trunc);
                    break;
                }
                case 2:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_2/F2_ChebyshevGrid.txt", ios_base::trunc);
                    break;
                }
                case 3:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_3/F3_ChebyshevGrid.txt", ios_base::trunc);
                    break;
                }
                case 4:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_4/F4_ChebyshevGrid.txt", ios_base::trunc);
                    break;
                }
                case 5:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_1/Lagrange_Interpolation/F1_ChebyshevGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 6:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_2/Lagrange_Interpolation/F2_ChebyshevGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 7:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_3/Lagrange_Interpolation/F3_ChebyshevGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 8:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_4/Lagrange_Interpolation/F4_ChebyshevGrid_Lagrange.txt", ios_base::trunc);
                    break;
                }
                case 9:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_1/Spline_Interpolation/F1_ChebyshevGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 10:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_2/Spline_Interpolation/F2_ChebyshevGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 11:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_3/Spline_Interpolation/F3_ChebyshevGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                case 12:
                {
                    fout.open("/Users/stepanletyagin/Desktop/Code/Cpp/Projects/Interpolation/Output/Chebyshev_Grid/Test_4/Spline_Interpolation/F4_ChebyshevGrid_Spline.txt", ios_base::trunc);
                    break;
                }

                default: break;
            }
            break;
        }

        default: break;
    }


    cout.precision(5);
//    for (int i = 0; i < Table.size(); i++)
//    {
//        fout << i + 1  << "\t" <<  Table[i].first << "\t \t" << Table[i].second << endl;
//    }

    for (int i = 0; i < Table.size(); i++)
    {
        fout <<  Table[i].first << "  ";
    }
    fout << endl;
    for (int i = 0; i < Table.size(); i++)
    {
        fout <<  Table[i].second << "  ";
    }

//    for (int i = 0; i < Table.size(); i++)
//    {
//        fout << "{" <<  Table[i].first << ", " <<Table[i].second << "}" << ", ";
//    }


    fout.close();
}

