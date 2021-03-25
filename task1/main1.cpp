#include <iostream>
#include <random>

int in_circle(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    int points_in_circle = 0;
    for (auto i = 0; i < n; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        if (x * x + y * y <= 1.0) {
            ++points_in_circle;
        }
    }
    return points_in_circle;
}

double m_pi(int p) {
    double all_points_inside = in_circle(p);
    double pi = ((double)all_points_inside / (double)p) * 4.0;
    return pi;
}
