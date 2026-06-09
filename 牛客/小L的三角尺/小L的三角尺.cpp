/*
https://ac.nowcoder.com/acm/contest/120566/A
Solution for the triangle ruler problem using Lagrange multiplier method with binary search
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long n;
	double w;
	cin >> n >> w;
	
	vector<double> x(n), y(n);
	double sum_y = 0;
	
	for(long i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		sum_y += y[i];
	}
	
	double S = sum_y - w;
	
	// If S <= 0, we can grind all edges to 0, answer is sum of x_i
	if(S <= 0)
	{
		double ans = 0;
		for(long i = 0; i < n; ++i)
		{
			ans += x[i];
		}
		cout << fixed << setprecision(9) << ans;
		return 0;
	}
	
	// Define function to compute z_i values and their sum given lambda
	// Returns {sum_z, sum_hypotenuse}
	auto compute_z = [&](double lambda) -> pair<double, double>
	{
		double sum_z = 0, sum_hypo = 0;
		double m = lambda / sqrt(1 - lambda * lambda);
		for(long i = 0; i < n; ++i)
		{
			double z = min(y[i], x[i] * m);
			sum_z += z;
			sum_hypo += sqrt(x[i] * x[i] + z * z);
		}
		return {sum_z, sum_hypo};
	};
	
	// Binary search for lambda such that g(lambda) = S
	// where g(lambda) = sum of z_i(lambda)
	double left = 0, right = 1 - 1e-12;
	double eps = 1e-10;
	
	for(int iter = 0; iter < 200; ++iter)
	{
		double mid = (left + right) / 2;
		auto [sum_z, _] = compute_z(mid);
		
		if(sum_z < S)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	
	// Compute final answer with the found lambda
	double lambda = (left + right) / 2;
	auto [sum_z_final, ans] = compute_z(lambda);
	
	cout << fixed << setprecision(9) << ans;
	
	return 0;
}

