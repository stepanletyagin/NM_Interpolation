#include "sets.h"
#include "grid.h"
#include "test_functions.h"
#include "output.h"
#include "lagrange_Interpolation.h"
#include "spline_Interpolation.h"
#include "matrix_operations.h"
#include "norm.h"

int main()
{
    /* UNIFORM GRID */

    /* Function y = x^2 */
    Function F1;
    F1.Limits = make_pair(-1,1);

    /* Uniform Grid for F1 */
    F1.Table = FirstFunction(UniformGrid(F1.Limits, F1.NodesNumber));
    Output(F1.Table, 'U', 1);

    /* New argument values for F1 */
    vector<VALUE_TYPE> x = CreateArgValues(F1.Limits);

    /* Lagrange Interpolation */
    vector<pair<VALUE_TYPE,VALUE_TYPE>> LagrangeInterpolationTable = LagrangeInterpolation(F1.Table, x, F1.NodesNumber);
    Output(LagrangeInterpolationTable, 'U', 5);

    cout << '\t' << MAGENTA << "Norm error of TEST_1 Lagrange Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(FirstFunction(x), LagrangeInterpolationTable) << endl;

    /* Lagrange Interpolation */
    vector<pair<VALUE_TYPE,VALUE_TYPE>> SplineInterpolationTable = spline_interpolation(F1.Table, x, F1.NodesNumber);
    Output(SplineInterpolationTable, 'U', 9);

    cout << '\t' << MAGENTA << "Norm error of TEST_1 Spline Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(FirstFunction(x), SplineInterpolationTable) << endl;


    /* Function y = 1/(1+25x^2) */
    Function F2;
    F2.Limits = make_pair(-1,1);

    /* Uniform Grid for F2 */
    F2.Table = SecondFunction(UniformGrid(F2.Limits, F2.NodesNumber));

    Output(F2.Table, 'U', 2);

    x = CreateArgValues(F2.Limits);

    LagrangeInterpolationTable = LagrangeInterpolation(F2.Table, x, F2.NodesNumber);
    Output(LagrangeInterpolationTable, 'U', 6);

    cout << '\t' << GREEN << "Norm error of TEST_2 Lagrange Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(SecondFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F2.Table, x, F2.NodesNumber);
    Output(SplineInterpolationTable, 'U', 10);

    cout << '\t' << GREEN << "Norm error of TEST_2 Spline Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(SecondFunction(x), SplineInterpolationTable) << endl;


    /* Function y = 1/(arctg(1 + 10x^2)) */
    Function F3;
    F3.Limits = make_pair(-3,3);

    /* Uniform Grid for F3 */
    F3.Table = ThirdFunction(UniformGrid(F3.Limits, F3.NodesNumber));

    Output(F3.Table, 'U', 3);

    x = CreateArgValues(F3.Limits);

    LagrangeInterpolationTable = LagrangeInterpolation(F3.Table, x, F3.NodesNumber);
    Output(LagrangeInterpolationTable, 'U', 7);

    cout << '\t' << CYAN << "Norm error of TEST_3 Lagrange Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(ThirdFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F3.Table, x, F3.NodesNumber);
    Output(SplineInterpolationTable, 'U', 11);

    cout << '\t' << CYAN << "Norm error of TEST_3 Spline Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(ThirdFunction(x), SplineInterpolationTable) << endl;



    /* Function y = (4x^3 + 2x^2 - 4x + 2)^(sqrt(2)) + arcsin(1/(5 + x - x^2)) - 5 */
    Function F4;
    F4.Limits = make_pair(-1,1);

    /* Uniform Grid for F4 */
    F4.Table = FourthFunction(UniformGrid(F4.Limits, F4.NodesNumber));

    Output(F4.Table, 'U', 4);

    x = CreateArgValues(F4.Limits);
    //sort (x.begin(), x.end());

    LagrangeInterpolationTable = LagrangeInterpolation(F4.Table, x, F4.NodesNumber);
    Output(LagrangeInterpolationTable, 'U', 8);

    cout << '\t' << YELLOW << "Norm error of TEST_4 Lagrange Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(FourthFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F4.Table, x, F4.NodesNumber);
    Output(SplineInterpolationTable, 'U', 12);

    cout << '\t' << YELLOW << "Norm error of TEST_4 Spline Interpolation with Uniform grid:" << RESET << endl;
    cout << '\t' << norm_error(FourthFunction(x), SplineInterpolationTable) << endl;
    cout << endl;



    /* CHEBYSHEV GRID*/

    /* Function y = x^2 */
    F1.Limits = make_pair(-1,1);

    /* Chebyshev Grid for F1 */
    F1.Table = FirstFunction(ChebyshevGrid(F1.Limits, F1.NodesNumber));
    Output(F1.Table, 'C', 1);

    /* New argument values for F1 */
    x = CreateArgValues(F1.Limits);

    /* Lagrange Interpolation */
    LagrangeInterpolationTable = LagrangeInterpolation(F1.Table, x, F1.NodesNumber);
    Output(LagrangeInterpolationTable, 'C', 5);

    cout << '\t' << MAGENTA << "Norm error of TEST_1 Lagrange Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(FirstFunction(x), LagrangeInterpolationTable) << endl;

    /* Lagrange Interpolation */
    SplineInterpolationTable = spline_interpolation(F1.Table, x, F1.NodesNumber);
    Output(SplineInterpolationTable, 'C', 9);

    cout << '\t' << MAGENTA << "Norm error of TEST_1 Spline Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(FirstFunction(x), SplineInterpolationTable) << endl;


    /* Function y = 1/(1+25x^2) */
    F2.Limits = make_pair(-1,1);

    /* Uniform Grid for F2 */
    F2.Table = SecondFunction(ChebyshevGrid(F2.Limits, F2.NodesNumber));

    Output(F2.Table, 'C', 2);

    x = CreateArgValues(F2.Limits);

    LagrangeInterpolationTable = LagrangeInterpolation(F2.Table, x, F2.NodesNumber);
    Output(LagrangeInterpolationTable, 'C', 6);

    cout << '\t' << GREEN << "Norm error of TEST_2 Lagrange Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(SecondFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F2.Table, x, F2.NodesNumber);
    Output(SplineInterpolationTable, 'C', 10);

    cout << '\t' << GREEN << "Norm error of TEST_2 Spline Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(SecondFunction(x), SplineInterpolationTable) << endl;



    /* Function y = 1/(arctg(1 + 10x^2)) */
    F3.Limits = make_pair(-3,3);

    /* Uniform Grid for F3 */
    F3.Table = ThirdFunction(ChebyshevGrid(F3.Limits, F3.NodesNumber));

    Output(F3.Table, 'C', 3);

    x = CreateArgValues(F3.Limits);

    LagrangeInterpolationTable = LagrangeInterpolation(F3.Table, x, F3.NodesNumber);
    Output(LagrangeInterpolationTable, 'C', 7);

    cout << '\t' << CYAN << "Norm error of TEST_3 Lagrange Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(ThirdFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F3.Table, x, F3.NodesNumber);
    Output(SplineInterpolationTable, 'C', 11);

    cout << '\t' << CYAN << "Norm error of TEST_3 Spline Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(ThirdFunction(x), SplineInterpolationTable) << endl;


    /* Function y = (4x^3 + 2x^2 - 4x + 2)^(sqrt(2)) + arcsin(1/(5 + x - x^2)) - 5 */
    F4.Limits = make_pair(-1,1);

    /* Uniform Grid for F4 */
    F4.Table = FourthFunction(ChebyshevGrid(F4.Limits, F4.NodesNumber));

    Output(F4.Table, 'C', 4);

    x = CreateArgValues(F4.Limits);

    LagrangeInterpolationTable = LagrangeInterpolation(F4.Table, x, F4.NodesNumber);
    Output(LagrangeInterpolationTable, 'C', 8);

    cout << '\t' << YELLOW << "Norm error of TEST_4 Lagrange Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(FourthFunction(x), LagrangeInterpolationTable) << endl;

    SplineInterpolationTable = spline_interpolation(F4.Table, x, F4.NodesNumber);
    Output(SplineInterpolationTable, 'C', 12);

    cout << '\t' << YELLOW << "Norm error of TEST_4 Spline Interpolation with Chebyshev grid:" << RESET << endl;
    cout << '\t' << norm_error(FourthFunction(x), SplineInterpolationTable) << endl;


    Function EXP;
    EXP.Limits = make_pair(0, 2);
    EXP.Table = EXP_func(UniformGrid(EXP.Limits, EXP.NodesNumber));
    vector<VALUE_TYPE> extra;

    VALUE_TYPE LagrangeInterpolationEXP = Lagranzh_single(EXP.Table, 2.2);
    cout << "Point value in 2.2 = " << LagrangeInterpolationEXP << endl;
    cout << "Error (|exp(x) - L(x)|) = " << fabs(LagrangeInterpolationEXP - exp(2.2)) << endl;
    VALUE_TYPE error = pow(0.2, 11) * 12 * exp(2.2);
    cout << "Estimation of the error of extrapolation = " << error << endl;

    double a = 2.349;
    double b = a*1000;
    cout.precision(5);
    cout<<b<<endl;

    return 0;
}
