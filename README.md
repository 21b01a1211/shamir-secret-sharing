#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long convert_base_to_decimal(int base, const char *encoded_value) {
    return strtoll(encoded_value, NULL, base);
}

double calculate_lagrange_interpolation(int data_points[], long long function_values[], int num_points) {
    double interpolation_result = 0.0;
    for (int i = 0; i < num_points; i++) {
        double term = function_values[i];
        for (int j = 0; j < num_points; j++) {
            if (i != j) {
                term *= (0.0 - data_points[j]) / (data_points[i] - data_points[j]);
            }
        }
        interpolation_result += term;
    }
    return round(interpolation_result);
}

int main() {
    int data_x1[] = {1, 2, 3};
    long long data_y1[] = {
        convert_base_to_decimal(10, "4"),
        convert_base_to_decimal(2, "111"),
        convert_base_to_decimal(10, "12")
    };
    int num_points1 = 3;
    double secret1 = calculate_lagrange_interpolation(data_x1, data_y1, num_points1);

    int data_x2[] = {1, 2, 3, 4, 5, 6, 7};
    long long data_y2[] = {
        convert_base_to_decimal(6, "13444211440455345511"),
        convert_base_to_decimal(15, "aed7015a346d63"),
        convert_base_to_decimal(15, "6aeeb69631c227c"),
        convert_base_to_decimal(16, "e1b5e05623d881f"),
        convert_base_to_decimal(8, "316034514573652620673"),
        convert_base_to_decimal(3, "2122212201122002221120200210011020220200"),
        convert_base_to_decimal(3, "20120221122211000100210021102001201112121")
    };
    int num_points2 = 7;
    double secret2 = calculate_lagrange_interpolation(data_x2, data_y2, num_points2);

    printf("Secret for Test Case 1: c = %.0f\n", secret1);
    printf("Secret for Test Case 2: c = %.0f\n", secret2);

    return 0;
}



// output:
// Secret for Test Case 1: c = 3
// Secret for Test Case 2: c = -6529208073738502144

